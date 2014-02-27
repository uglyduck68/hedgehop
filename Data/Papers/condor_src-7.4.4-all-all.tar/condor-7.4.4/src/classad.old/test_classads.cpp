/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/


#include "condor_common.h"
#include "condor_classad.h"
#include "condor_xml_classads.h"
#include "stringSpace.h"
#include "condor_scanner.h" 
#include "iso_dates.h"
#define HAVE_DLOPEN 1
#ifdef HAVE_DLOPEN // Used to be CLASSAD_FUNCTIONS
#include "condor_config.h"
#endif

/*----------------------------------------------------------
 *
 *                        Global Variables
 *
 *----------------------------------------------------------*/

#define LARGE_NUMBER_OF_CLASSADS 10000

extern StringSpace classad_string_space; // for debugging only!

#define NUMBER_OF_CLASSAD_STRINGS (sizeof(classad_strings)/sizeof(char *))
char *classad_strings[] = 
{
#ifdef HAVE_DLOPEN
	"A = 1, B=2, C = 3, D='2001-04-05T12:14:15', G=GetTime(1), H=foo(1)",
#else
	"A = 1, B=2, C = 3, D='2001-04-05T12:14:15', E=TRUE",
#endif
	"A = 0.7, B=2, C = 3, D = \"alain\", MyType=\"foo\", TargetType=\"blah\"",

	"Rank = (Memory >= 50)",

    "Env = \"CPUTYPE=i86pc;GROUP=unknown;LM_LICENSE_FILE=/p/multifacet/"
            "projects/simics/dist10/v9-sol7-gcc/sys/flexlm/license.dat;"
            "SIMICS_HOME=.;SIMICS_EXTRA_LIB=./modules;PYTHONPATH=./modules;"
            "MACHTYPE=i386;SHELL=/bin/tcsh;PATH=/s/std/bin:/usr/afsws/bin:"
        	"/usr/ccs/bin:/usr/ucb:/bin:/usr/bin:/usr/X11R6/bin:/unsup/condor/bin:.\"",

    "MyType=\"Job\", TargetType=\"Machine\", Owner = \"alain\", Requirements = (TARGET.Memory > 50)",
    "MyType=\"Machine\", TargetType=\"Job\", Memory = 100,  Requirements = (TARGET.owner == \"alain\")",
    "MyType=\"Machine\", TargetType=\"Job\", Memory = 40, Requirements = (TARGET.owner == \"alain\")",
    "MyType=\"Machine\", TargetType=\"Job\", Memory = 100, Requirements = (TARGET.owner != \"alain\")",

	// A classad to test PrintToNewStr()--we need to ensure everything
	// we can print is properly accounted for. 
	"Requirements = (a > 3) && (b >= 1.3) && (c < MY.rank) && ((d <= TARGET.RANK) "
    "|| (g == \"alain\") || (g != \"roy\") || (h =?= 5) || (i =!= 6)) "
    "&& ((a + b) < (c-d)) && ((e * f) > (g / h)) && x == false && y == true "
    "&& z == f && j == t",

	/* Some classads to test GetReferences() 
	 * The first one is simple, but we can also check that things aren't listed twice. */
	"Memory = 60, Disk = 40, OS = Linux, X = 4, Requirements = ((ImageSize > Memory) "
	"&& (AvailableDisk > Disk) && (AvailableDisk > Memory) && (ImageSize > Disk)) "
    "&& foo(X; XX)",
	/* The second one is to test MY and TARGET. */
	"Memory = 60, Disk = 40, OS = Linux, Requirements = ((TARGET.ImageSize > MY.Memory) "
	"&& (AvailableDisk > Disk) && (TARGET.AvailableDisk > MY.Memory) && (TARGET.ImageSize > MY.Disk)) "
    "&& foo(TARGET.X; TARGET.XX)",

	/* Test case sensitivity */
	"DoesMatch = \"Bone Machine\" == \"bone machine\" && \"a\" =?= \"a\" && \"a\" =!= \"A\","
	"DoesntMatch = \"a\" =?= \"A\"",

    /* Test XML preservation of spaces */
    "A = \"\", B=\" \""
};

/*----------------------------------------------------------
 *
 *                     Private Datatypes
 *
 *----------------------------------------------------------*/
struct parameters
{
	bool verbose;
	bool test_scanner;
	bool test_copy_constructor;
	bool test_assignment;
	bool test_classads;
	bool test_references;
	bool test_xml;
	bool test_dirty;
	bool test_functions;
    bool test_random;
};

class TestResults
{
public:
	TestResults()
	{
		number_of_tests        = 0;
		number_of_tests_passed = 0;
		number_of_tests_failed = 0;
		return;
	};

	~TestResults()
	{
		return;
	}

	void AddResult(bool passed)
	{
		number_of_tests++;
		if (passed) {
			number_of_tests_passed++;
		} else {
			number_of_tests_failed++;
		}
		return;
	}

	int GetNumberFailed(void)
	{
		return(number_of_tests_failed);
	}

	void PrintResults(void)
	{
		printf("%d of %d tests passed.\n", number_of_tests_passed, number_of_tests);
		return;
	}

private:
	int number_of_tests;
	int number_of_tests_passed;
	int number_of_tests_failed;
};

/*----------------------------------------------------------
 *
 *                     Private Functions
 *
 *----------------------------------------------------------*/
static void parse_command_line(int argc, char **argv, 
    struct parameters *parameters);
void test_scanner(TestResults *results);
void test_token_text(const Token *token, char *text, int line_number, 
    TestResults *test_results);
void test_token_type(const Token *token, int token_type, int line_number,
    TestResults *test_results);
void test_token_integer(const Token *token, int integer, 
    int line_number, TestResults *test_results);
void test_integer_value(ClassAd *classad, const char *attribute_name, 
    int expected_value,int line_number, TestResults *results);
void test_eval_bool(ClassAd *classad, const char  *attribute_name,
	int expected_value, int line_number, TestResults *results);
void test_eval_error(ClassAd *classad, const char  *attribute_name,
	int line_number, TestResults *results);
void test_token_float(const Token *token, float number,
    int line_number, TestResults *test_results);
void test_string_value(ClassAd *classad, const char *attribute_name,
    const char *expected_value, int line_number,
    TestResults *results);
void test_time_string_value(ClassAd *classad, const char *attribute_name,
    const char *expected_value, int line_number,
    TestResults *results);
void test_time_value(ClassAd *classad, const char *attribute_name,
    const struct tm  &expected_time, int line_number,
    TestResults *results);
void test_mytype(ClassAd *classad, const char *expected_value, 
	int line_number, TestResults *results);
void test_targettype(ClassAd *classad, const char *expected_value, 
    int line_number, TestResults *results);
void test_ads_match(ClassAd *classad_1, ClassAd *classad_2,
    int line_number, TestResults  *results);
void test_ads_dont_match(ClassAd *classad_1, ClassAd *classad_2,
    int line_number, TestResults *results);
void test_printed_version(ClassAd *classad, const char *attribute_name, 
    char *expected_string, int line_number, TestResults *results);
void test_in_references(char *name,	StringList &references,
    int line_number, TestResults *results);
void test_not_in_references(char *name,	StringList &references,
    int line_number, TestResults *results);
void test_dirty_attribute(
    TestResults *results);
#ifdef HAVE_DLOPEN
static void test_functions( TestResults  *results);
static void test_function_int( TestResults  *results);
static void test_function_real( TestResults  *results);
static void test_function_ifthenelse( TestResults  *results);
static void test_function_stringlists( TestResults  *results);
static void test_function_stringlists_regexpmember( TestResults  *results);
static void test_function_string( TestResults  *results);
static void test_function_strcat( TestResults  *results);
static void test_function_floor( TestResults  *results);
static void test_function_ceiling( TestResults  *results);
static void test_function_round( TestResults  *results);
static void test_function_random( TestResults  *results);
static void test_function_isstring( TestResults  *results);
static void test_function_isundefined( TestResults  *results);
static void test_function_iserror( TestResults  *results);
static void test_function_isinteger( TestResults  *results);
static void test_function_isreal( TestResults  *results);
static void test_function_isboolean( TestResults  *results);
static void test_function_substr( TestResults  *results);
static void test_function_formattime( TestResults  *results);
static void test_function_strcmp( TestResults  *results);
static void test_function_attrnm( TestResults  *results);
static void test_function_regexp( TestResults  *results);
static void test_function_XXX( TestResults  *results);/*sample*/
static bool test_floats_close( float one, float two, float diff = .0001);
#endif
void print_truncated_string(const char *s, int max_characters);
static void make_big_string(int length, char **string,
    char **quoted_string);
void test_random(TestResults *results);
void test_equality(TestResults *results);
void test_operators(TestResults *results);
void test_scoping(TestResults *results);
void test_debug_function_run(bool expect_run, int line_number, TestResults *results);

int 
main(
	 int  argc,
	 char **argv)
{
	ClassAd              **classads;
	struct parameters    parameters;
	TestResults          test_results;
	int                  classad_index = 0; 
	parse_command_line(argc, argv, &parameters);

	if (parameters.verbose) {
		printf("sizeof(ClassAd) = %d\n", sizeof(ClassAd));
		printf("sizeof(AttrListElem) = %d\n", sizeof(AttrListElem));
		printf("sizeof(ExprTree) = %d\n", sizeof(ExprTree));
		printf("We have %d classads.\n", NUMBER_OF_CLASSAD_STRINGS);
	}

	if (parameters.test_scanner) {
		printf("Testing classad scanner...\n");
		test_scanner(&test_results);
	}

	classads = new ClassAd *[NUMBER_OF_CLASSAD_STRINGS];

	printf("\nCreating ClassAds...\n");
	if (parameters.test_copy_constructor) {
		printf("(Will test copy constructor at the same time.)\n");
	}
	else if (parameters.test_assignment) {
		printf("(Will test assignment at the same time.)\n");
	}
	for (  classad_index = 0; 
		   classad_index < (int) NUMBER_OF_CLASSAD_STRINGS;
		   classad_index++) {
		ClassAd *original, *duplicate;

		printf("%s\n", classad_strings[classad_index]);

		original = new ClassAd(classad_strings[classad_index], ',');
		classads[classad_index] = original;

		if (parameters.test_copy_constructor) {
			duplicate = new ClassAd(*original);
			delete original;
			classads[classad_index] = duplicate;
		}
		else if (parameters.test_assignment) {
			duplicate = new ClassAd("A = 1, MyType=\"x\", TargetType=\"y\"",
									',');
			*duplicate = *original;
			delete original;
			classads[classad_index] = duplicate;
		}

		if (parameters.verbose) {
			printf("ClassAd %d:\n", classad_index);
			classads[classad_index]->fPrint(stdout);
			printf("\n");
		}
	}

	if (parameters.test_xml) {
		printf("Testing XML...\n");
		for (  int classad_index = 0; 
			   classad_index < (int) NUMBER_OF_CLASSAD_STRINGS;
			   classad_index++) {
			ClassAdXMLUnparser unparser;
			ClassAdXMLParser   parser;
			ClassAd            *after_classad;
			MyString xml, before_classad_string, after_classad_string;
			
			// 1) Print each ClassAd to a string.
			// 2) Convert it to XML and back and 
			// 3) see if the string is the same. 
			classads[classad_index]->sPrint(before_classad_string);

			unparser.SetUseCompactSpacing(false);
			unparser.Unparse(classads[classad_index], xml);
			if (parameters.verbose) {
				printf("Classad %d in XML:\n%s", classad_index, xml.Value());
			}
			after_classad = parser.ParseClassAd(xml.Value());

			after_classad->sPrint(after_classad_string);
			if (strcmp(before_classad_string.Value(), after_classad_string.Value()) != 0) {
				printf("Failed: XML Parse and UnParse for classad %d\n", classad_index);
				printf("---- Original ClassAd:\n%s\n", before_classad_string.Value());
				printf("---- After ClassAd:\n%s\n", after_classad_string.Value());
				printf("---- Intermediate XML:\n%s\n", xml.Value());
				test_results.AddResult(false);
			} else {
				printf("Passed: XML Parse and Unparse for classad %d\n\n", classad_index);
				test_results.AddResult(true);
			}
			delete after_classad;
		}
	}

	if (parameters.test_classads) {

		printf("\nTesting ClassAds...\n");
		
		test_integer_value(classads[0], "A", 1, __LINE__, &test_results);
		test_integer_value(classads[0], "B", 2, __LINE__, &test_results);
		test_integer_value(classads[0], "C", 3, __LINE__, &test_results);
		test_mytype(classads[0], "", __LINE__, &test_results);
		test_targettype(classads[0], "", __LINE__, &test_results);
		test_time_string_value(classads[0], "D", "2001-04-05T12:14:15",
							   __LINE__, &test_results);
		{
			struct tm  time;
			time.tm_year = 101; // year 2001
			time.tm_mon  = 03;  // that's april, not march. 
			time.tm_mday = 05;
			time.tm_hour = 12;
			time.tm_min  = 14;
			time.tm_sec  = 15;
			test_time_value(classads[0], "D", time, __LINE__, &test_results);
		}

		test_string_value(classads[1], "D", "alain", __LINE__, &test_results);
		test_mytype(classads[1], "foo", __LINE__, &test_results);
		test_targettype(classads[1], "blah", __LINE__, &test_results);
		
		test_ads_match(classads[4], classads[5], __LINE__, &test_results);
		test_ads_match(classads[5], classads[4], __LINE__, &test_results);
		test_ads_dont_match(classads[4], classads[6], __LINE__, &test_results);
		test_ads_dont_match(classads[6], classads[4], __LINE__, &test_results);
		test_ads_dont_match(classads[4], classads[7], __LINE__, &test_results);
		test_ads_dont_match(classads[7], classads[4], __LINE__, &test_results);
		
		// Here we test that we can scan large inputs and everything works.
		char *variable, *string, *expression;
		
		make_big_string(15000, &variable, NULL);
		make_big_string(25000, &string, NULL);
		expression = (char *) malloc(50000);
		sprintf(expression, "%s = \"%s\"", variable, string);
		
		classads[0]->Insert(expression);
		
		test_string_value(classads[0], variable, string, __LINE__, &test_results);

		test_printed_version(classads[2], "Rank",         classad_strings[2], 
							 __LINE__, &test_results);
		test_printed_version(classads[3], "Env",          classad_strings[3],
							 __LINE__, &test_results);
		test_printed_version(classads[8], "Requirements", 
			"Requirements = (a > 3) && (b >= 1.300000) && (c < MY.rank) && ((d <= TARGET.RANK) "
		    "|| (g == \"alain\") || (g != \"roy\") || (h =?= 5) || (i =!= 6)) "
            "&& ((a + b) < (c - d)) && ((e * FALSE) > (g / h)) && x == FALSE && y == TRUE "
            "&& z == FALSE && j == TRUE",
			 __LINE__, &test_results);

		ClassAd *big_classad = new ClassAd(expression, ',');
		test_printed_version(big_classad, variable, expression, __LINE__, &test_results);
		delete big_classad;
		free(variable);
		free(expression);
		free(string);

		/* Test case insensitivity */
		test_eval_bool(classads[11], "DoesMatch",   1, __LINE__, &test_results);
		test_eval_bool(classads[11], "DoesntMatch", 0, __LINE__, &test_results);

        /* Test that reading from a FILE works */
        FILE *classad_file;
        ClassAd *classad_from_file;
        classad_file = safe_fopen_wrapper("classad_file", "w");
        classads[1]->fPrint(classad_file);
        fprintf(classad_file, "***\n");
        fclose(classad_file);

        int iseof, error, empty;
        classad_file = safe_fopen_wrapper("classad_file", "r");
        classad_from_file = new ClassAd(classad_file, "***", iseof, error, empty);
        fclose(classad_file);
		test_integer_value(classad_from_file, "B", 2, __LINE__, &test_results);
		test_integer_value(classad_from_file, "C", 3, __LINE__, &test_results);
		test_string_value(classad_from_file, "D", "alain", __LINE__, &test_results);
        delete classad_from_file;
	}

	if (parameters.test_references) {
		printf("\nTesting References...\n");
		StringList  *internal_references; 
		StringList  *external_references; 

		internal_references = new StringList;
		external_references = new StringList;

		classads[9]->GetReferences("Requirements", *internal_references,
								   *external_references);
		test_in_references("Memory", *internal_references, __LINE__, &test_results);
		test_in_references("Disk", *internal_references, __LINE__, &test_results);
		test_in_references("ImageSize", *external_references, __LINE__, &test_results);
		test_in_references("AvailableDisk", *external_references, __LINE__, &test_results);
        test_in_references("XX", *external_references, __LINE__, &test_results);
		
		test_not_in_references("Memory", *external_references, __LINE__, &test_results);
		test_not_in_references("Disk", *external_references, __LINE__, &test_results);
		test_not_in_references("ImageSize", *internal_references, __LINE__, &test_results);
		test_not_in_references("AvailableDisk", *internal_references, __LINE__, &test_results);
		test_not_in_references("Linux", *internal_references, __LINE__, &test_results);
		test_not_in_references("Linux", *external_references, __LINE__, &test_results);
        test_not_in_references("X", *external_references, __LINE__, &test_results);
		delete internal_references;
		delete external_references;

		internal_references = new StringList;
		external_references = new StringList;

		classads[10]->GetReferences("Requirements", *internal_references,
								   *external_references);
		test_in_references("Memory", *internal_references, __LINE__, &test_results);
		test_in_references("Disk", *internal_references, __LINE__, &test_results);
		test_in_references("ImageSize", *external_references, __LINE__, &test_results);
		test_in_references("AvailableDisk", *external_references, __LINE__, &test_results);
		test_in_references("X", *external_references, __LINE__, &test_results);
		test_in_references("XX", *external_references, __LINE__, &test_results);
		
		test_not_in_references("Memory", *external_references, __LINE__, &test_results);
		test_not_in_references("Disk", *external_references, __LINE__, &test_results);
		test_not_in_references("ImageSize", *internal_references, __LINE__, &test_results);
		test_not_in_references("AvailableDisk", *internal_references, __LINE__, &test_results);
		test_not_in_references("Linux", *internal_references, __LINE__, &test_results);
		test_not_in_references("Linux", *external_references, __LINE__, &test_results);

		delete internal_references;
		delete external_references;
	}

	if (parameters.test_dirty) {
		test_dirty_attribute(&test_results);
	}

#ifdef HAVE_DLOPEN
	if (parameters.test_functions) {
		test_functions(&test_results);
	}
//#else

    if (parameters.test_random) {
        test_random(&test_results);
    }

    test_operators(&test_results);
    test_scoping(&test_results);
    test_equality(&test_results);

	//ClassAd *many_ads[LARGE_NUMBER_OF_CLASSADS];
	/*
	for (int i = 0; i < LARGE_NUMBER_OF_CLASSADS; i++) {
		many_ads[i] = new ClassAd(classad_strings[2], ',');
		//print_memory_usage();
	}
	system("ps -v");
	*/

	test_results.PrintResults();
	//classad_string_space.dump();

#endif
	// Clean up when we're done.
	for (  classad_index = 0; 
		   classad_index < (int) NUMBER_OF_CLASSAD_STRINGS;
		   classad_index++) {
		delete classads[classad_index];
	}
	delete [] classads;

	return(test_results.GetNumberFailed());
}

/***************************************************************
 *
 * Function: parse_command_line
 * Purpose:  Read the command line arguments and fill in 
 *           the parameters structure to reflect them. 
 *
 ***************************************************************/
static void
parse_command_line(
	 int                argc,
	 char               **argv,
	 struct parameters  *parameters)
{
	int   argument_index;
	bool  dump_usage;

	dump_usage = false;

	parameters->verbose               = false;
	parameters->test_scanner          = false;
	parameters->test_copy_constructor = false;
	parameters->test_assignment       = false;
	parameters->test_classads         = false;
	parameters->test_references       = false;
	parameters->test_xml              = false;
	parameters->test_dirty            = false;
	parameters->test_functions        = false;
    parameters->test_random           = false;
	argument_index = 1;

	while (argument_index < argc) {
		if (!strcmp(argv[argument_index], "-v")
			|| !strcmp(argv[argument_index], "-verbose")) {
			parameters->verbose = !parameters->verbose;
		} else if (!strcmp(argv[argument_index], "-h")
			|| !strcmp(argv[argument_index], "-help")
			|| !strcmp(argv[argument_index], "-?")) {
			dump_usage = true;
		} else if (!strcmp(argv[argument_index], "-a")
		    || !strcmp(argv[argument_index], "-all")) {
			parameters->test_scanner          = true;
			if (!parameters->test_assignment) {
				parameters->test_copy_constructor = true;
			}
			parameters->test_classads         = true;
			parameters->test_references       = true;
			parameters->test_xml              = true;
			parameters->test_dirty            = true;
			parameters->test_functions        = true;
            parameters->test_random           = true;
		} else if (!strcmp(argv[argument_index], "-s")
		    || !strcmp(argv[argument_index], "-scanner")) {
			parameters->test_scanner          = true;
		} else if (!strcmp(argv[argument_index], "-c")
		    || !strcmp(argv[argument_index], "-classads")) {
			parameters->test_classads          = true;
		} else if (!strcmp(argv[argument_index], "-r")
		    || !strcmp(argv[argument_index], "-references")) {
			parameters->test_references        = true;
		} else if (!strcmp(argv[argument_index], "-C")
		    || !strcmp(argv[argument_index], "-copy")) {
			parameters->test_copy_constructor  = true;
			parameters->test_assignment        = false;
		} else if (!strcmp(argv[argument_index], "-A")
		    || !strcmp(argv[argument_index], "-assignment")) {
			parameters->test_assignment       = true;
			parameters->test_copy_constructor = false;
		} else if (!strcmp(argv[argument_index], "-x")
		    || !strcmp(argv[argument_index], "-xml")) {
			parameters->test_xml              = true;
		} else if (!strcmp(argv[argument_index], "-d")
		    || !strcmp(argv[argument_index], "-dirty")) {
			parameters->test_dirty            = true;
		} else if (!strcmp(argv[argument_index], "-f")
		    || !strcmp(argv[argument_index], "-functions")) {
			parameters->test_functions        = true;
		} else if (!strcmp(argv[argument_index], "-random")) {
			parameters->test_random           = true;
		} else {
			fprintf(stderr, "Unknown argument: %s\n", 
					argv[argument_index]);
			dump_usage = true;

		}
		argument_index++;
	}

	parameters->test_functions        = true;

	if (dump_usage) {
		fprintf(stderr, "Usage: test_classads [-v | -verbose] "
				        "[-h | -help| -?]\n");
		fprintf(stderr, "       [-v | -verbose]   Print oodles of info.\n");
		fprintf(stderr, "       [-h | -help | -?] Print this message.\n");
		exit(1);
	}

	if (   parameters->test_scanner == false
		&& parameters->test_copy_constructor == false
		&& parameters->test_assignment       == false
		&& parameters->test_classads         == false
		&& parameters->test_references       == false
		&& parameters->test_dirty            == false) {
		parameters->test_scanner          = true;
		parameters->test_copy_constructor = true;
		parameters->test_classads         = true;
		parameters->test_references       = true;
		parameters->test_dirty            = true;
	}
	return;
}

/***************************************************************
 *
 * Function: test_scanner
 * Purpose:  Test the classad scanner: that's the bit that
 *           walks through the input character by character and
 *           tokenizes it: it's a lexer.
 *
 ***************************************************************/
void 
test_scanner(
    TestResults *results) // OUT: Modified to reflect result of test
{
	Token token;
	char  *input = "Rank = ((Owner == \"Alain\") || (Memory < 500)) 5.4 '2001-10-10'";
	const char  *current;

	current = input;

	Scanner(current, token);

	// Rank
	test_token_type(&token, LX_VARIABLE, __LINE__, results);
	test_token_text(&token, "Rank", __LINE__, results);
	Scanner(current, token);

	// =
	test_token_type(&token, LX_ASSIGN, __LINE__, results);
	Scanner(current, token);

	// ((
	test_token_type(&token, LX_LPAREN, __LINE__, results);
	Scanner(current, token);
	test_token_type(&token, LX_LPAREN, __LINE__, results);
	Scanner(current, token);

	// Owner
	test_token_type(&token, LX_VARIABLE, __LINE__, results);
	test_token_text(&token, "Owner", __LINE__, results);
	Scanner(current, token);

	// ==
	test_token_type(&token, LX_EQ, __LINE__, results);
	Scanner(current, token);

	// "Alain"
	test_token_type(&token, LX_STRING, __LINE__, results);
	test_token_text(&token, "Alain", __LINE__, results);
	Scanner(current, token);

	// )
	test_token_type(&token, LX_RPAREN, __LINE__, results);
	Scanner(current, token);

	// ||
	test_token_type(&token, LX_OR, __LINE__, results);
	Scanner(current, token);

	// (
	test_token_type(&token, LX_LPAREN, __LINE__, results);
	Scanner(current, token);

	// Memory
	test_token_type(&token, LX_VARIABLE, __LINE__, results);
	test_token_text(&token, "Memory", __LINE__, results);
	Scanner(current, token);

	// LT
	test_token_type(&token, LX_LT, __LINE__, results);
	Scanner(current, token);

	// 500 
	test_token_type(&token, LX_INTEGER, __LINE__, results);
	test_token_integer(&token, 500, __LINE__, results);
	Scanner(current, token);

	// ))
	test_token_type(&token, LX_RPAREN, __LINE__, results);
	Scanner(current, token);
	test_token_type(&token, LX_RPAREN, __LINE__, results);
	Scanner(current, token);

	test_token_type(&token, LX_FLOAT, __LINE__, results);
	test_token_float(&token, 5.4, __LINE__, results);
	Scanner(current, token);

	test_token_type(&token, LX_TIME, __LINE__, results);
	test_token_text(&token, "2001-10-10", __LINE__, results);
	Scanner(current, token);

	// end
	test_token_type(&token, LX_EOF, __LINE__, results);

	// Test some big strings.
	char *big_string, *quoted_big_string; 
	const char *scanner_text;
	
	make_big_string(30000, &big_string, &quoted_big_string);
	scanner_text = quoted_big_string;
	Scanner(scanner_text, token);
	test_token_type(&token, LX_STRING, __LINE__, results);
	test_token_text(&token, big_string, __LINE__, results);

	scanner_text = big_string;
	Scanner(scanner_text, token);
	test_token_type(&token, LX_VARIABLE, __LINE__, results);
	test_token_text(&token, big_string, __LINE__, results);

	free(big_string);
	free(quoted_big_string);

	return;
}

/***************************************************************
 *
 * Function: test_token_type
 * Purpose:  Used by test_scanner(). Given a token, make sure
 *           it's the type we expect.
 *
 ***************************************************************/
void
test_token_type(
	const Token *token,        // IN: The token we're examining
    int         token_type,    // IN: The token type we expect
    int         line_number,   // IN: The line number to print
	TestResults *test_results) // OUT: Modified to reflect result of test
{
	if (token->type == token_type) {
		printf("Passed: token_type == %d in line %d\n",
			   token_type, line_number);
		test_results->AddResult(true);
	} else {
		printf("Failed: token_type == %d, not %d in line %d\n", 
			   token->type, token_type, line_number);
		test_results->AddResult(false);
	}
	return; 
}

/***************************************************************
 *
 * Function: test_token_text
 * Purpose:  Used by test_scanner(). Given a token, make sure it
 *           has the text we expect. 
 *
 ***************************************************************/
void
test_token_text(
	const Token *token,        // IN: The token we're examining
	char        *text,         // IN: The text we expect
    int         line_number,   // IN: The line number to print
	TestResults *test_results) // OUT: Modified to reflect result of test
{
	if (!strcmp(token->strVal, text)) {
		printf("Passed: token_text == \"");
		print_truncated_string(text, 40);
		printf("\" in line %d\n", line_number);
		test_results->AddResult(true);
	} else {
		printf("Failed: token_text == \"");
		print_truncated_string(token->strVal, 30);
		printf("\" not \"");
		print_truncated_string(text, 30);
		printf("\" in line %d\n", line_number);
		test_results->AddResult(false);
	}
	return; 
}

/***************************************************************
 *
 * Function: test_token_integer
 * Purpose:  Given a token, make sure its integer value is as
 *           we expect. Used by test_scanner().
 *
 ***************************************************************/
void
test_token_integer(
    const Token *token,        // IN: The token we're examining
    int         integer,       // IN: The integer we're expecting.
    int         line_number,   // IN: The line number to print
	TestResults *test_results) // OUT: Modified to reflect result of test
{
	if (token->intVal == integer) {
		printf("Passed: token value == %d in line %d\n",
			   integer, line_number);
		test_results->AddResult(true);
	} else {
		printf("Failed: token value == %d, not %d in line %d\n", 
			   token->intVal, integer, line_number);
		test_results->AddResult(false);
	}
	return; 
}

/***************************************************************
 *
 * Function: test_token_float
 * Purpose:  Given a token, make sure its floating-point value
 *           is as we expect. Used by test_scanner().
 *
 ***************************************************************/
void
test_token_float(
	const Token *token,         // IN: The token we're examining
	float       number,         // IN: The float we're expecting
    int         line_number,    // IN: The line number to print
	TestResults *test_results)  // OUT: Modified to reflect result of test
{
	if (token->floatVal == number) {
		printf("Passed: token value == %g in line %d\n",
			   number, line_number);
		test_results->AddResult(true);
	} else {
		printf("Failed: token value == %g, not %g in line %d\n", 
			   token->floatVal, number, line_number);
		test_results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_integer_value
 * Purpose:  Given a classad and an attribute within the classad,
 *           test that the attribute has the integer value we
 *           expect.
 *
 ***************************************************************/
void 
test_integer_value(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *attribute_name, // IN: The attribute we're examining
	int         expected_value,  // IN: The integer we're expecting
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	int actual_value;
 	int found_integer;

	found_integer = classad->LookupInteger(attribute_name, actual_value);
	if (expected_value == actual_value) {
		printf("Passed: %s is %d in line %d\n",
			   attribute_name, expected_value, line_number);
		results->AddResult(true);
	} else if (!found_integer) {
		printf("Failed: Attribute \"%s\" is not found.\n", attribute_name);
		results->AddResult(false);
	} else {
		printf("Failed: %s is %d not %d in line %d\n",
			   attribute_name, actual_value, expected_value, line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_eval_bool
 * Purpose:  Given a classad and an attribute within the classad,
 *           test that the attribute evaluates to the boolean we
 *           expect
 *
 ***************************************************************/
void 
test_eval_bool(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *attribute_name, // IN: The attribute we're examining
	int         expected_value,  // IN: The integer we're expecting
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	int actual_value;
 	int found_bool;

	found_bool = classad->EvalBool(attribute_name, NULL, actual_value);
	if (expected_value == actual_value) {
		printf("Passed: %s is %d in line %d\n",
			   attribute_name, expected_value, line_number);
		results->AddResult(true);
	} else if (!found_bool) {
		printf("Failed: Attribute \"%s\" is not found.\n", attribute_name);
		results->AddResult(false);
	} else {
		printf("Failed: %s is %d not %d in line %d\n",
			   attribute_name, actual_value, expected_value, line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_eval_error
 * Purpose:  Given a classad and an attribute within the classad,
 *           test that the attribute evaluates an error
 *
 ***************************************************************/
void 
test_eval_error(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *attribute_name, // IN: The attribute we're examining
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
 	int is_error;
	ExprTree *tree;
	EvalResult val;

	tree = classad->Lookup(attribute_name);
	if(!tree) {
        is_error = false;
    } else if (tree->EvalTree(classad, NULL, &val) && val.type == LX_ERROR) {
        is_error = true;
    } else {
        is_error = false;
    }
	if (is_error) {
		printf("Passed: Found expected error in line %d\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: Did not find error in line %d\n", line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_string_value
 * Purpose:  Given a classad, test that an attribute within the
 *           classad has the string value we expect.
 *
 ***************************************************************/
void 
test_string_value(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *attribute_name, // IN: The attribute we're examining
	const char  *expected_value, // IN: The string we're expecting
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	int         found_string;
	char        *actual_value=NULL;

	found_string = classad->LookupString(attribute_name, &actual_value);
	if (found_string && !strcmp(expected_value, actual_value)) {
		printf("Passed: ");
		print_truncated_string(attribute_name, 40);
		printf(" is \"");
		print_truncated_string(expected_value, 40);
		printf(" \" in line %d\n", line_number);
		results->AddResult(true);
	} else if (!found_string) {
		printf("Failed: Attribute \"%s\" is not found.\n", attribute_name);
		results->AddResult(false);
	} else {
		printf("Failed: ");
		print_truncated_string(attribute_name, 40);
		printf(" is: ");
		print_truncated_string(actual_value, 30);
		printf("\" not \"");
		print_truncated_string(expected_value, 30);
		printf("\" in line %d\n", line_number);
		results->AddResult(false);
	}
    if (actual_value != NULL){
        free(actual_value);
    }
	return;
}

/***************************************************************
 *
 * Function: test_time_string_value
 * Purpose:  Given a classad, test that an attribute within the
 *           classad has the time string we expect.
 *
 ***************************************************************/
void 
test_time_string_value(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *attribute_name, // IN: The attribute we're examining
	const char  *expected_value, // IN: The string we're expecting
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	int         found_string;
	char        *actual_value;

	found_string = classad->LookupTime(attribute_name, &actual_value);
	if (found_string && !strcmp(expected_value, actual_value)) {
		printf("Passed: ");
		print_truncated_string(attribute_name, 40);
		printf(" is \"");
		print_truncated_string(expected_value, 40);
		printf("\" in line %d\n", line_number);
		results->AddResult(true);
	} else if (!found_string) {
		printf("Failed: Attribute \"%s\" is not found.\n", attribute_name);
		results->AddResult(false);
	} else {
		printf("Failed: ");
		print_truncated_string(attribute_name, 40);
		printf(" is: ");
		print_truncated_string(actual_value, 30);
		printf("\" not \"");
		print_truncated_string(expected_value, 30);
		printf("\" in line %d\n", line_number);
		results->AddResult(false);
	}
	free(actual_value);
	return;
}

/***************************************************************
 *
 * Function: test_time_value
 * Purpose:  Given a classad, test that an attribute within the
 *           classad has the time we expect.
 *
 ***************************************************************/
void 
test_time_value(
    ClassAd          *classad,        // IN: The ClassAd we're examining
	const char       *attribute_name, // IN: The attribute we're examining
	const struct tm  &expected_time,  // IN: The string we're expecting
	int              line_number,     // IN: The line number to print
    TestResults      *results)        // OUT: Modified to reflect result of test
{
	int         found_time;
	struct tm   actual_time;
	bool        is_utc;

	found_time = classad->LookupTime(attribute_name, &actual_time, &is_utc);
	if (found_time 
		&& actual_time.tm_year == expected_time.tm_year
		&& actual_time.tm_mon  == expected_time.tm_mon
		&& actual_time.tm_mday == expected_time.tm_mday
		&& actual_time.tm_hour == expected_time.tm_hour
		&& actual_time.tm_min  == expected_time.tm_min
		&& actual_time.tm_sec  == expected_time.tm_sec) {
		printf("Passed: ");
		print_truncated_string(attribute_name, 40);
		printf(" has correct time in line %d\n", line_number);
		results->AddResult(true);
	} else if (!found_time) {
		printf("Failed: Attribute \"%s\" is not found.\n", attribute_name);
		results->AddResult(false);
	} else {
		char *t1, *t2;
		bool is_utc;
		t1 = time_to_iso8601(actual_time, ISO8601_ExtendedFormat, 
						ISO8601_DateAndTime, &is_utc);
		t2 = time_to_iso8601(expected_time, ISO8601_ExtendedFormat, 
						ISO8601_DateAndTime, &is_utc);
		printf("Failed: ");
		print_truncated_string(attribute_name, 40);
		printf(" is: ");
		print_truncated_string(t1, 30);
		printf("\" not \"");
		print_truncated_string(t2, 30);
		printf("\" in line %d\n", line_number);
		results->AddResult(false);
		free(t1);
		free(t2);
	}
	return;
}

/***************************************************************
 *
 * Function: test_mytype
 * Purpose:  Given a classad, make sure that the type (mytype)
 *           is what we expect it to be. 
 *
 ***************************************************************/
void 
test_mytype(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *expected_value, // IN: The type we're expecting.
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	static const char *actual_value;

	actual_value = classad->GetMyTypeName();
	if (!strcmp(expected_value, actual_value)) {
		printf("Passed: MyType is \"");
		print_truncated_string(expected_value, 40);
		printf("\" in line %d\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: MyType is \"");
		print_truncated_string(actual_value, 30);
		printf("\" not \"");
		print_truncated_string(expected_value, 30);
		printf("\" in line %d\n", line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_targettype
 * Purpose:  Given a classad, test that the target type is what
 *           we expect it to be.
 *
 ***************************************************************/
void 
test_targettype(
    ClassAd     *classad,        // IN: The ClassAd we're examining
	const char  *expected_value, // IN: The targettype we're expecting
	int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
	static const char *actual_value;

	actual_value = classad->GetTargetTypeName();
	if (!strcmp(expected_value, actual_value)) {
		printf("Passed: TargetType is \"");
		print_truncated_string(expected_value, 40);
		printf("\" in line %d\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: TargetType is \"");
		print_truncated_string(actual_value, 30);
		printf("\" not \"");
		print_truncated_string(expected_value, 30);
		printf("\" in line %d\n", line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_ads_match
 * Purpose:  Verify that two class ads match, as we expect.
 *
 ***************************************************************/
void
test_ads_match(
	ClassAd      *classad_1,   // IN: One of the class ads
	ClassAd      *classad_2,   // IN: The other the class ads
    int          line_number,  // IN: The line number to print
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	if (classad_1->IsAMatch(classad_2)) {
		printf("Passed: classads match in line %d.\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: classads don't match in line %d.\n", line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_ads_dont_match
 * Purpose:  Given two class ads, ensure that they don't match.
 *
 ***************************************************************/
void
test_ads_dont_match(
	ClassAd      *classad_1,   // IN: One of the class ads
	ClassAd      *classad_2,   // IN: The other the class ads
    int          line_number,  // IN: The line number to print
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	if (!classad_1->IsAMatch(classad_2)) {
		printf("Passed: classads don't match in line %d.\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: classads match in line %d.\n", line_number);
		results->AddResult(false);
	}
	return;
}

void 
test_printed_version(
    ClassAd     *classad,         // IN: The ClassAd we're examining
	const char  *attribute_name,  // IN: The attribute we're examining
	char        *expected_string, // IN: The string we're expecting
	int         line_number,      // IN: The line number to print
    TestResults *results)         // OUT: Modified to reflect result of test
{
	char      *printed_version;
	ExprTree  *tree;

	tree = classad->Lookup(attribute_name);
	tree->PrintToNewStr(&printed_version);

	if (!strcmp(expected_string, printed_version)) {
		printf("Passed: ");
		print_truncated_string(attribute_name, 40);
		printf(" prints correctly in line %d.\n", line_number);
		results->AddResult(true);
	} else {
		printf("Failed: ");
		print_truncated_string(attribute_name, 40);
		printf(" does not print correctly in line %d.\n", line_number);
		printf("Printed as: %s\n", printed_version);
		printf("Expected  : %s\n", expected_string);
		results->AddResult(false);
	}
	free(printed_version);
	return;
}

/***************************************************************
 *
 * Function: test_not_references
 * Purpose:  Test if the name (reference) is found in the
 *           list of refrences.
 *
 ***************************************************************/
void
test_in_references(
	char         *name,        // IN: What to look for 
	StringList   &references,   // IN: References to examine
    int          line_number,  // IN: The line number to print
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char *reference;
	bool is_in_references = false;

	references.rewind(); 
	while ((reference = references.next()) != NULL) {
		if (!strcmp(reference, name)) {
			is_in_references = true;
			break;
		}
	}
	if (is_in_references) {
		printf("Passed: %s is in references in line %d.\n", 
			   name, line_number);
		results->AddResult(true);
	}
	else {
		printf("Failed: %s is not in references in line %d.\n", 
			   name, line_number);
		results->AddResult(false);
	}
	return;
}
    
/***************************************************************
 *
 * Function: test_not_in_references
 * Purpose:  Test if the name (reference) is not found in the
 *           list of refrences.
 *
 ***************************************************************/
void
test_not_in_references(
	char         *name,        // IN: What to look for 
	StringList   &references,   // IN: References to examine
    int          line_number,  // IN: The line number to print
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char *reference;
	bool is_in_references = false;

	references.rewind(); 
	while ((reference = references.next()) != NULL) {
		if (!strcmp(reference, name)) {
			is_in_references = true;
			break;
		}
	}
	if (!is_in_references) {
		printf("Passed: %s is not in references in line %d.\n", 
			   name, line_number);
		results->AddResult(true);
	}
	else {
		printf("Failed: %s is in references in line %d.\n", 
			   name, line_number);
		results->AddResult(false);
	}
	return;
}

/***************************************************************
 *
 * Function: test_dirty_attribute
 * Purpose:  Test if dirty attributes (attributes modified after
 *           the creation of the ClassAd) are properly maintained.
 *
 ***************************************************************/
void 
test_dirty_attribute(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	ClassAd  *classad;
	char     *name;

	classad = new ClassAd("A = 1, B = 2", ',');

	// First of all, we should have zero dirty attributes. 
	classad->ResetName(); 
	name = classad->NextDirtyName();
	if (name) {
		delete [] name;
		printf("Failed: new ClassAd has dirty attributes in line %d\n",
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Passed: new ClassAd is clean in line %d\n", __LINE__);
		results->AddResult(true);
	}

	// Add an attribute
	classad->Insert("C = 3");

	// Now we should have exactly one dirty attribute, C.
	classad->ResetName();
	name = classad->NextDirtyName();
	if (!name) {
		printf("Failed: C isn't dirty in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (strcmp(name, "C")) {
		printf("Failed: %s is dirty, not C in line %d\n", name, __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: C is dirty in line %d\n", __LINE__);
		results->AddResult(true);
		delete [] name;
	}
	name = classad->NextDirtyName();
	if (name) {
		printf("Failed: more than one dirty attribute in line %d\n", __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: not more than one dirty attribute in line %d\n", __LINE__);
		results->AddResult(true);
	}

	// Add an attribute
	classad->Insert("D = 4");

	// Now we should have two dirty attributes, C & D
	classad->ResetName();
	name = classad->NextDirtyName();
	if (!name) {
		printf("Failed: C isn't dirty in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (strcmp(name, "C")) {
		printf("Failed: %s is dirty, not C in line %d\n", name, __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: C is dirty in line %d\n", __LINE__);
		results->AddResult(true);
		delete [] name;
	}
	name = classad->NextDirtyName();
	if (!name) {
		printf("Failed: D isn't dirty in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (strcmp(name, "D")) {
		printf("Failed: %s is dirty, not D in line %d\n", name, __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: D is dirty in line %d\n", __LINE__);
		results->AddResult(true);
		delete [] name;
	}
	name = classad->NextDirtyName();
	if (name) {
		printf("Failed: more than two dirty attributes in line %d\n", __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: not more than two dirty attributes in line %d\n", __LINE__);
		results->AddResult(true);
	}

	// Clear the dirty flags, and there should be no dirty attributes
	classad->ClearAllDirtyFlags();
	classad->ResetName(); 
	name = classad->NextDirtyName();
	if (name) {
		delete [] name;
		printf("Failed: ClassAd has dirty attributes in line %d\n",
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Passed: new ClassAd is clean in line %d\n", __LINE__);
		results->AddResult(true);
	}

	// Now make A dirty, and B dirty then clean, and we should have 
	// just A dirty. 
	classad->SetDirtyFlag("A", true);
	classad->SetDirtyFlag("B", true);
	classad->SetDirtyFlag("B", false);

	classad->ResetName();
	name = classad->NextDirtyName();
	if (!name) {
		printf("Failed: A isn't dirty in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (strcmp(name, "A")) {
		printf("Failed: %s is dirty, not A in line %d\n", name, __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: A is dirty in line %d\n", __LINE__);
		results->AddResult(true);
		delete [] name;
	}
	name = classad->NextDirtyName();
	if (name) {
		printf("Failed: more than one dirty attribute in line %d\n", __LINE__);
		results->AddResult(false);
		delete [] name;
	} else {
		printf("Passed: not more than one dirty attribute in line %d\n", __LINE__);
		results->AddResult(true);
	}

	// We should also be able to test it with GetDirtyFlag()
	bool exists, dirty;
	classad->GetDirtyFlag("A", &exists, &dirty);
	if (!exists) {
		printf("Failed: A doesn't exist in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (!dirty) {
		printf("Failed: A isn't dirty  in line %d\n", __LINE__);
		results->AddResult(false);
	} else {
		printf("Passed: A is dirty in line %d\n", __LINE__);
		results->AddResult(true);
	}

	classad->GetDirtyFlag("B", &exists, &dirty);
	if (!exists) {
		printf("Failed: B doesn't exist in line %d\n", __LINE__);
		results->AddResult(false);
	} else if (dirty) {
		printf("Failed: B is dirty  in line %d\n", __LINE__);
		results->AddResult(false);
	} else {
		printf("Passed: B is not dirty in line %d\n", __LINE__);
		results->AddResult(true);
	}

	classad->GetDirtyFlag("Unknown", &exists, NULL);
	if (exists) {
		printf("Failed: 'Unknown' should not exist in line %d\n", __LINE__);
		results->AddResult(false);
	} else {
		printf("Passed: 'Unknown' doesn't exist in line %d\n", __LINE__);
	}


	delete classad;

	return;
}

#ifdef HAVE_DLOPEN
static void test_functions(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;
    float	real;

	char classad_string[] = 
							/* batch 1 testing of functions */
							"D0=GetTime():"
							"D1=Time():"

							"D2=Interval(60):"
							"D3=Interval(3600):"
							"D4=Interval(86400):"

		                    "E=sharedstring():"
                            "G=sharedinteger(2):"
	                        "H=sharedfloat(3.14):"

							"L=toupper(\"AbCdEfg\"):"
							"M=toLower(\"ABCdeFg\"):"

							"N0=size(\"ABC\"):"
							"N1=size(\"\"):"
							"N2=size(foo):"
							"E0=isError(N2):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for functions in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for functions in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("D0", NULL, integer)) {
			printf("Passed: Evaluating gettime function gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating gettime function in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("D1", NULL, integer)) {
			printf("Passed: Evaluating time function gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating time function in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("D2", NULL, big_string)&&
			(strcmp("  0+00:01:00",big_string) == 0)) {
			printf("Passed: Evaluating interval(60) function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating interval(60) wanted  0+00:01:00 got <<%s>>in line %d\n",
				   big_string,__LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("D3", NULL, big_string)&&
			(strcmp("  0+01:00:00",big_string) == 0)) {
			printf("Passed: Evaluating interval(3600) function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating interval(3600) in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("D4", NULL, big_string)&&
			(strcmp("  1+00:00:00",big_string) == 0)) {
			printf("Passed: Evaluating interval(86400) function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating interval(86400) in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		/*
		** turn off shared values till testing concerns are met
		**
		if (classad->EvalString("E", NULL, big_string)) {
			printf("Passed: Evaluating sharedstring function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating foo sharedstring in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("G", NULL, integer)) {
			printf("Passed: Evaluating sharedinteger gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating sharedinteger in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("H", NULL, real)) {
			printf("Passed: Evaluating sharedfloat gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating sharedfloat in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}
		*/

		if (classad->EvalString("L", NULL, big_string) && 
				(strcmp(big_string, "ABCDEFG") == 0)) {
			printf("Passed: Evaluating toupper gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating toupper gave %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("M", NULL, big_string) && 
				(strcmp(big_string, "abcdefg") == 0)) {
			printf("Passed: Evaluating tolower gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating tolower gave %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("N0", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating size gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating size gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("N1", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating size gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating size gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}
		
		if (classad->EvalBool("E0", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating size(foo) ): %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating size(foo) ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		test_function_isstring(results);
		test_function_isundefined(results);
		test_function_iserror(results);
		test_function_isinteger(results);
		test_function_isreal(results);
		test_function_isboolean(results);

		test_function_int(results);
		test_function_real(results);
		test_function_string(results);
		test_function_stringlists(results);

		test_function_floor(results);
		test_function_ceiling(results);
		test_function_round(results);
		test_function_random(results);

		test_function_ifthenelse(results);

		test_function_strcat(results);
		test_function_substr(results);
		test_function_formattime(results);
		test_function_strcmp(results);
		test_function_attrnm(results);
		test_function_regexp(results);
		test_function_stringlists_regexpmember(results);
        delete classad;
	}
	return;
}

static void test_function_int(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC0=int(-3):"
							"BC1=int(3.4):"
							"BC2=int(-3.4):"
							"BC3=int(\"-3.4\"):"
							"BC4=int(true):"
							"BC5=int(t):"
							"BC6=int(false):"
							"BC7=int(f):"
							"BC8=int(\"this is not a number\"):"
							"BC9=isError(BC8):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function int() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function int()>> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC9", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(BC9) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(BC9) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC8", NULL, integer) && (integer == 0)) {
			printf("Failed: Evaluating int(weirdstring)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		} else {
			printf("Passed: Evaluating int(weirdstring) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(true);
		}

		if (classad->EvalInteger("BC7", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating int(f)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(f) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC6", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating int(false)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(false) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating int(t)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(t) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating int(true)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(true) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC3", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating int('-3.4')  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int('-3.4') gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC2", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating int(-3.4)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(-3.4) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC1", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating int(3.4)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(3.4) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC0", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating int(-3)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating int(-3) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_ifthenelse(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;

	char classad_string[] = 
							"BB=2:"
							"BC=10:"
							//BD is undefined.....
							"BB2=ifThenElse(BB > 5, \"big\",\"small\"):"
							"BB3=ifThenElse(BC > 5, \"big\",\"small\"):"
							"BB4=ifThenElse(BD > 5, \"big\",\"small\"):"
							"BB5=isUndefined(BB4):"
							"BB6=ifThenElse(4 / \"hello\", \"big\",\"small\"):"
							"BB7=ifThenElse(\"big\",\"small\"):"
							"E0=isError(BB6):"
							"E1=isError(BB7):"
							"BB8=ifThenElse(BB > 5, 4 / 0,\"small\"):"
							"BB9=ifThenElse(BC > 5, \"big\", 4 / 0):"
							"BB10=ifThenElse(0.0, \"then\", \"else\"):"
							"BB11=ifThenElse(1.0, \"then\", \"else\"):"
							"BB12=ifThenElse(3.7, \"then\", \"else\"):"
							"BB13=ifThenElse(\"\", \"then\", \"else\"):"
							"E2=isError(BB13):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function ifthenelse() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function ifthenelse() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalString("BB2", NULL, big_string) &&
				(strcmp(big_string, "small") == 0)) {
			printf("Passed: Evaluating ifThenElse <if false>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <if false> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB3", NULL, big_string) &&
				(strcmp(big_string, "big") == 0)) {
			printf("Passed: Evaluating ifThenElse <if true>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <if true> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BB5", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating ifThenElse isUndefined(BB5) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse isUndefined(BB5) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E0", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating ifThenElse conditional error (BB6) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse conditional error (BB6) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E1", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating ifThenElse missing arg(BB7) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse missing arg(BB7) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB8", NULL, big_string) &&
				(strcmp(big_string, "small") == 0)) {
			printf("Passed: Evaluating ifThenElse <if false do not evaluate true arg>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <if false do not evaluate true arg> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB9", NULL, big_string) &&
				(strcmp(big_string, "big") == 0)) {
			printf("Passed: Evaluating ifThenElse <if true do not evaluate false arg>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <if true do not evaluate false arg> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB10", NULL, big_string) &&
				(strcmp(big_string, "else") == 0)) {
			printf("Passed: Evaluating ifThenElse <0.0 evaluates to false yielding else result>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <0.0 evaluates to false yielding else result> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB11", NULL, big_string) &&
				(strcmp(big_string, "then") == 0)) {
			printf("Passed: Evaluating ifThenElse <1.0 evaluates to true yielding then result>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <1.0 evaluates to true yielding then result> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BB12", NULL, big_string) &&
				(strcmp(big_string, "then") == 0)) {
			printf("Passed: Evaluating ifThenElse <3.7 evaluates to true yielding then result>: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse <3.7 evaluates to true yielding then result> %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E2", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating ifThenElse expression a string : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ifThenElse expression a string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_stringlists(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;
    float	real;

	char classad_string[] = 
							"O0=stringlistsize(\"A ,0 ,C\"):"
							"O1=stringlistsize(\"\"):"
							"O2=stringlistsize(\"A;B;C;D;E\",\";\"):"
							"O3=isError(stringlistsize(\"A;B;C;D;E\",true)):"
							"O4=isError(stringlistsize(true,\"A;B;C;D;E\")):"
							"O5=stringlistsize(\"A B C,D\"):"
							"O6=stringlistsize(\"A B C,,,,,D\"):"
							"O7=stringlistsize(\"A B C ; D\",\";\"):"
							"O8=stringlistsize(\"A B C;D\",\" ; \"):"
							"O9=stringlistsize(\"A  +B;C$D\",\"$;+\"):"

							"P0=stringlistsum(\"1,2,3\"):"
							"P1=stringlistsum(\"\"):"
							"P2=stringlistsum(\"1;2;3\",\";\"):"
							"P3=isError(stringlistsum(\"1;2;3\",true)):"
							"P4=isError(stringlistsum(true,\"1;2;3\")):"
							"P5=isError(stringlistsum(\"this, list, bad\")):"
							"P6=stringlistsum(\"1,2.0,3\"):"

							"Q0=stringlistmin(\"-1,2,-3\"):"
							"Q1=isUndefined(stringlistmin(\"\")):"
							"Q2=stringlistmin(\"1;2;3\",\";\"):"
							"Q3=isError(stringlistmin(\"1;2;3\",true)):"
							"Q4=isError(stringlistmin(true,\"1;2;3\")):"
							"Q5=isError(stringlistmin(\"this, list, bad\")):"
							"Q6=isError(stringlistmin(\"1;A;3\",\";\")):"
							"Q7=stringlistmin(\"1,-2.0,3\"):"

							"R0=stringlistmax(\"1 , 4.5, -5\"):"
							"R1=isUndefined(stringlistmax(\"\")):"
							"R2=stringlistmax(\"1;2;3\",\";\"):"
							"R3=isError(stringlistmax(\"1;2;3\",true)):"
							"R4=isError(stringlistmax(true,\"1;2;3\")):"
							"R5=isError(stringlistmax(\"this, list, bad\")):"
							"R6=isError(stringlistmax(\"1;A;3\",\";\")):"
							"R7=stringlistmax(\"1,-2.0,3.0\"):"

							"S0=stringlistavg(\"10, 20, 30, 40\"):"
							"S1=stringlistavg(\"\"):"
							"S2=stringlistavg(\"1;2;3\",\";\"):"
							"S3=isError(stringlistavg(\"1;2;3\",true)):"
							"S4=isError(stringlistavg(true,\"1;2;3\")):"
							"S5=isError(stringlistavg(\"this, list, bad\")):"
							"S6=isError(stringlistavg(\"1;A;3\",\";\")):"
							"S7=stringlistavg(\"1,-2.0,3.0\"):"

							"U0=stringlistmember(\"green\", \"red, blue, green\"):"
							"U1=stringlistmember(\"green\",\"\"):"
							"U2=stringlistmember(\"green\", \"red; blue; green\",\";\"):"
							"U3=isError(stringlistmember(\"green\",\"1;2;3\",true)):"
							"U4=isError(stringlistmember(\"green\",true,\";\")):"
							"U5=isError(stringlistmember(true,\"green\",\";\")):"
							"U6=isError(stringlistmember(\"this, list, bad\")):"
							"U7=isError(stringlistmember(\"1;A;3\",\";\")):"
							"U8=stringlistmember(\"-2.9\",\"1,-2.0,3.0\"):"

							"U=stringlistmember(\"green\", \"red, blue, green\"):"
							"V=stringlistimember(\"ReD\", \"RED, BLUE, GREEN\"):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function stringlists() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function stringlists() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("O0", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O1", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O2", NULL, integer) && (integer == 5)) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("O3", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistsize expected error arg 2 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 2 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("O4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistsize expected error arg 1 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O5", NULL, integer) ) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O6", NULL, integer) ) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O7", NULL, integer) ) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O8", NULL, integer) ) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("O9", NULL, integer) ) {
			printf("Passed: Evaluating stringlistsize gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsize Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}
		if (classad->EvalInteger("P0", NULL, integer) && (integer == 6)) {
			printf("Passed: Evaluating stringlistsum gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("P1", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating stringlistsum gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("P2", NULL, integer) && (integer == 6)) {
			printf("Passed: Evaluating stringlistsum gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("P3", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistsum expected error arg 2 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum Got error arg 2 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("P4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistsum expected error arg 1 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("P5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistsum expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("P6", NULL, real) && (real == 6.0)) {
			printf("Passed: Evaluating stringlistsum gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistsum gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("Q0", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating stringlistmin gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("Q1", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin expected UNDEFINED for empty list: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin expected UNDEFINED for empty list %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("Q2", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("Q3", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin expected error arg 2 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin Got error arg 2 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("Q4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin expected error arg 1 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("Q5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("Q6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmin expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmin Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("Q7", NULL, real) && (real == -2.0)) {
			printf("Passed: Evaluating stringlistmin gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("R0", NULL, real) && (real == 4.5)) {
			printf("Passed: Evaluating stringlistmax gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("R1", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmax expected UNDEFINED for empty list: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax expected UNDEFINED for empty list %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("R2", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating stringlistmax gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("R3", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmax expected error arg 2 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax Got error arg 2 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("R4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmax expected error arg 1 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("R5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmax expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("R6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmax expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("R7", NULL, real) && (real == 3.0)) {
			printf("Passed: Evaluating stringlistmax gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmax gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("S0", NULL, real) && (real == 25.0)) {
			printf("Passed: Evaluating stringlistavg gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("S1", NULL, real) && (real == 0.0)) {
			printf("Passed: Evaluating stringlistavg gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("S2", NULL, real) && (real == 2.0)) {
			printf("Passed: Evaluating stringlistavg gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("S3", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistavg expected error arg 2 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg Got error arg 2 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("S4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistavg expected error arg 1 not string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg Got error arg 1 not string %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("S5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistavg expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("S6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistavg expected error list not all numbers: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg Got error list not all numbers %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("S7", NULL, real) && (real > 0.6)) {
			printf("Passed: Evaluating stringlistavg gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistavg gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("U", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistmember gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistmember gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("V", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlistimember gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlistimember gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_real(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;
    float	real;

	char classad_string[] = 
							"BC0=real(-3):"
							"BC1=real(3.4):"
							"BC2=real(-3.4):"
							"BC3=real(\"-3.4\"):"
							"BC4=real(true):"
							"BC5=real(t):"
							"BC6=real(false):"
							"BC7=real(f):"
							"BC8=real(\"this is not a number\"):"
							"BC9=isError(BC8):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function real() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function real() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC9", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(BC9) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(BC9) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC8", NULL, real) && 
			test_floats_close(real, 0.0)) {
			printf("Failed: Evaluating real(weirdstring)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(false);
		} else {
			printf("Passed: Evaluating real(weirdstring) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(true);
		}

		if (classad->EvalFloat("BC7", NULL, real) && 
			test_floats_close(real, 0.0)) {
			printf("Passed: Evaluating real(f)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(f) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC6", NULL, real) && 
			test_floats_close(real, 0.0)) {
			printf("Passed: Evaluating real(false)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(false) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC5", NULL, real) && 
			test_floats_close(real, 1.0)) {
			printf("Passed: Evaluating real(t)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(t) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC4", NULL, real) && 
			test_floats_close(real, 1.0)) {
			printf("Passed: Evaluating real(true)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(true) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC3", NULL, real) && 
			test_floats_close(real, -3.4 )) {
			printf("Passed: Evaluating real('-3.4')  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real('-3.4') gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC2", NULL, real) && 
			test_floats_close(real, -3.4)) {
			printf("Passed: Evaluating real(-3.4)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(-3.4) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC1", NULL, real) && 
			test_floats_close(real, 3.400000)) {
			printf("Passed: Evaluating real(3.4)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(3.4) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC0", NULL, real) && 
			test_floats_close(real, -3.0)) {
			printf("Passed: Evaluating real(-3)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating real(-3) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_string(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;

	char classad_string[] = 
							"BC0=string(\"-3\"):"
							"BC1=string(123):"
							"E0=isError(BC1):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function string() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function string() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalString("BC0", NULL, big_string)) {
			printf("Passed: Evaluating string function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating for string in line %d\n",
				   __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BC1", NULL, big_string)) {
			printf("Passed: Evaluating integer passed in to string: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: missed bad string passed in : %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(false);
		}
        delete classad;
	}
	return;
}

static void test_function_strcat(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];

	char classad_string[] = 
							"BC0=strcat(\"-3\",\"3\"):"
							"BC1=strcat(\"a\",\"b\",\"c\",\"d\",\"e\",\"f\",\"g\"):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function strcat() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function strcat() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalString("BC0", NULL, big_string) && (strcmp("-33",big_string) == 0)) {
			printf("Passed: Evaluating string function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating for strcat<<%s>> in line %d\n",
				   big_string,__LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("BC1", NULL, big_string) && (strcmp("abcdefg",big_string) == 0)) {
			printf("Passed: Evaluating string function gives: '%s' in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating for strcat<<%s>> in line %d\n",
				   big_string,__LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_floor(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC0=floor(\"-3\"):"
							"BC1=floor(\"-3.4\"):"
							"BC2=floor(\"3\"):"
							"BC3=floor(5):"
							"BC4=floor(5.2):"
							// error test ??????
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function floor() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function floor() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("BC0", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating floor gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating floor gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC1", NULL, integer) && (integer == -4)) {
			printf("Passed: Evaluating floor gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating floor gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC2", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating floor gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating floor gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC3", NULL, integer) && (integer == 5)) {
			printf("Passed: Evaluating floor gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating floor gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC4", NULL, integer) && (integer == 5)) {
			printf("Passed: Evaluating floor gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating floor gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_ceiling(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC0=ceiling(\"-3\"):"
							"BC1=ceiling(\"-3.4\"):"
							"BC2=ceiling(\"3\"):"
							"BC3=ceiling(5):"
							"BC4=ceiling(5.2):"
							// error test ??????
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function ceiling() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function ceiling() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("BC0", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating ceiling gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ceiling gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC1", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating ceiling gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ceiling gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC2", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating ceiling gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ceiling gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC3", NULL, integer) && (integer == 5)) {
			printf("Passed: Evaluating ceiling gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ceiling gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC4", NULL, integer) && (integer == 6)) {
			printf("Passed: Evaluating ceiling gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating ceiling gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_round(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC0=round(\"-3\"):"
							"BC1=round(\"-3.5\"):"
							"BC2=round(\"3\"):"
							"BC3=round(5.5):"
							"BC4=round(5.2):"
							// error test ??????
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function round() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function round() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("BC4", NULL, integer) && (integer == 5)) {
			printf("Passed: Evaluating round gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating round gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC3", NULL, integer) && (integer == 6)) {
			printf("Passed: Evaluating round gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating round gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC2", NULL, integer) && (integer == 3)) {
			printf("Passed: Evaluating round gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating round gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC1", NULL, integer) && (integer == -4)) {
			printf("Passed: Evaluating round gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating round gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC0", NULL, integer) && (integer == -3)) {
			printf("Passed: Evaluating round gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating round gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_random(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;
    float	real;

	char classad_string[] = 
							"BC1=random(5):"
							"BC2=random():"
							"BC3=random(3.5):"
							"BC4=random(\"-3.5\"):"
							"BC5=random(\"-3.5\"):"
							"BC6=random(\"-3.5\"):"
							"BC7=random(\"3\"):"
							"BC8=random(5.5):"
							"BC9=random(5.2):"
							// error testn test_function_iserror 
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function random() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function random() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalFloat("BC3", NULL, real) 
			&& (real > 0) && (real < 3.5)) {
			printf("Passed: Evaluating random(3.5)  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating random(3.5) gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalFloat("BC2", NULL, real) 
			&& (real > 0) && (real < 1)) {
			printf("Passed: Evaluating random()  gives: %f in line %d\n", 
				   real, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating random() gave %f in line %d\n",
				   real, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("BC1", NULL, integer) 
			&& (integer >= 0) && (integer < 5)) {
			printf("Passed: Evaluating random(5)  gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating random(5) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_isstring(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC3=isString(\"abc\"):"
							"BC0=isString(strcat(\"-3\",\"3\")):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function isString() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function isString() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC3", NULL, integer)) {
			printf("Passed: Evaluating isString \"abc\": %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isString \"abc\" : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC0", NULL, integer)) {
			printf("Passed: Evaluating isString strcat(\"-3\",\"3\"): %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isString strcat(\"-3\",\"3\"): %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_isundefined(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BB=2:"
							"BC=10:"
							//"BD=undefined:"
							"BB0=isUndefined(BD):"
							"BB1=isUndefined(BC):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function isundefined() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function isundefined() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BB0", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isUndefined(BB0) returned true(1) when it should : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isUndefined(BB0) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BB1", NULL, integer) &&
				(integer == 0)) {
			printf("Passed: Evaluating isUndefined(BB1) return false(0) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isUndefined(BB1) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_iserror(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC0=isError(random(\"-3\")):"
							"BC1=isError(int(\"this is not an int\")):"
							"BC2=isError(real(\"this is not a float\")):"
							"BC3=isError(floor(\"this is not a float\")):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function iserror() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function iserror() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC0", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(random(BC0)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(random(BC0)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC1", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(int(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(int(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC2", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(real(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(real(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC3", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating isError(floor(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isError(floor(non nummeric string)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_isinteger(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC1=isInteger(-3.4 ):"
							"BC2=isInteger(-3):"
							"BC3=isInteger(\"-3\"):"
							"BC4=isInteger( 3.4 ):"
							"BC5=isInteger( int(3.4) ):"
							"BC6=isInteger(int(\"-3\")):"
							"BC7=isInteger(3):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function isinteger() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function isinteger() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC1", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isInteger( -3.4 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger( -3.4 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC2", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isInteger( -3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger( -3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC3", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isInteger(\"-3\" ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger(\"-3\") : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC4", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isInteger(3.4) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger(3.4) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isInteger( int(3.4) ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger( int(3.4) ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isInteger( int(\"-3\") ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger(int(\"-3\")) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC7", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isInteger( 3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isInteger( 3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_isreal(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC1=isReal(-3.4 ):"
							"BC2=isReal(-3):"
							"BC3=isReal(\"-3\"):"
							"BC4=isReal( 3.4 ):"
							"BC5=isReal( real(3) ):"
							"BC6=isReal(real(\"-3\")):"
							"BC7=isReal(3):"
							"BC8=isReal(3,1):"
							"BC9=isError(BC8):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function isreal() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function isreal() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC1", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isReal( -3.4 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal( -3.4 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC2", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isReal( -3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal( -3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC3", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isReal(\"-3\" ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal(\"-3\") : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC4", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isReal(3.4) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal(3.4) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC5", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isReal( real(3) ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal( real(3) ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isReal( real(\"-3\") ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal(real(\"-3\")) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC7", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating isReal( 3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal( 3 ) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("BC9", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isReal( x,y) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isReal( x,y) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_isboolean(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"BC1=isBoolean(isReal(-3.4 )):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function isboolean() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function isboolean() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("BC1", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating isBoolean(isReal( 3.4)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating isBolean(isReal( 3.4)) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}


static void test_function_formattime(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	char	i0[1024];
	int 	integer;

	char classad_string[] = 
							"I0=formattime():"
							"I1=formattime(CurrentTime):"
							"I2=formattime(CurrentTime,\"%c\"):"
							"I3=formattime(1174737600,\"%m/%d/%y\"):"
							"I4=formattime(-231):"
							"I5=formattime(1174694400,1174694400):"
							"E0=isError(I4):"
							"E1=isError(I5):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function formattime() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function formattime() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalString("I0", NULL, i0)) {
			printf("Passed: Evaluating formattime() gives: %s in line %d\n", 
				   i0, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating formattime() gives: %s in line %d\n",
				   i0, __LINE__);
			results->AddResult(false);
		}

		int retry_count = 0;
		first_retry:
		if (classad->EvalString("I1", NULL, big_string) && 
				(strcmp(big_string, i0) == 0)) {
			printf("Passed: Evaluating formattime(CurrentTime) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			retry_count++;
			if (retry_count < 10) {	
					classad->EvalString("I0", NULL, i0);
					goto first_retry;
			}
			printf("Failed: Evaluating formattime(CurrentTime) gives: %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		retry_count = 0;
		second_retry:
		if (classad->EvalString("I2", NULL, big_string) && 
				(strcmp(big_string, i0) == 0)) {
			printf("Passed: Evaluating formattime(CurrentTime,\"%%c\") gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			retry_count++;
			if (retry_count < 10) {	
					classad->EvalString("I0", NULL, i0);
					goto second_retry;
			}
			printf("Failed: Evaluating formattime(CurrentTime,\"%%c\") gives: %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("I3", NULL, big_string) && 
				(strcmp(big_string, "03/24/07") == 0)) {
			printf("Passed: Evaluating formattime(1174737600,\"%%m/%%d/%%y\") gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating formattime(1174737600,\"%%m/%%d/%%y\") gives: %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}



		if (classad->EvalBool("E0", NULL, integer) && (integer == 1)) {
			printf("Passed: Caught error from a negative time : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: did not catch error from a negative time : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E1", NULL, integer) && (integer == 1)) {
			printf("Passed: Bad string caught : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Bad string missed : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}


static void test_function_substr(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int 	integer;

	char classad_string[] = 
							"I0=substr(\"abcdefg\", 3):"
							"I1=substr(\"abcdefg\", 3, 2):"
							"I2=substr(\"abcdefg\", -2, 1):"
							"I3=substr(\"abcdefg\", 3, -1):"
							"I4=substr(\"abcdefg\", 3, -9):"
							"I5=substr(\"abcdefg\", 3.3, -9):"
							"I6=substr(foo, 3, -9):"
							"E0=isError(I5):"
							"E1=isError(I6):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function substr() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function substr() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalString("I0", NULL, big_string) && 
				(strcmp(big_string, "defg") == 0)) {
			printf("Passed: Evaluating substr(\"abcdefg\", 3) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating substr substr(\"abcdefg\", 3) %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("I1", NULL, big_string) && 
				(strcmp(big_string, "de") == 0)) {
			printf("Passed: Evaluating substr(\"abcdefg\", 3, 2) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating substr substr(\"abcdefg\", 3, 2) %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("I2", NULL, big_string) && 
				(strcmp(big_string, "f") == 0)) {
			printf("Passed: Evaluating substr(\"abcdefg\", -2, 1) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating substr substr(\"abcdefg\", -2, 1) %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("I3", NULL, big_string) && 
				(strcmp(big_string, "def") == 0)) {
			printf("Passed: Evaluating substr(\"abcdefg\", 3, -1) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating substr substr(\"abcdefg\", 3, -1) %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("I4", NULL, big_string) && 
				(strcmp(big_string, "") == 0)) {
			printf("Passed: Evaluating substr(\"abcdefg\", 3, -9) gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating substr substr(\"abcdefg\", 3, -9) %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E0", NULL, integer) && (integer == 1)) {
			printf("Passed: Caught error from a float for the offset) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: did not catch error from a float for the offset) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E1", NULL, integer) && (integer == 1)) {
			printf("Passed: Bad string caught) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Bad string missed) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_strcmp(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	int		integer;

	char classad_string[] = 
							"J0=strcmp(\"ABCDEFgxx\"; \"ABCDEFg\"):"
							"J1=strcmp(\"BBBBBBBxx\"; \"CCCCCCC\"):"
							"J2=strcmp(\"AbAbAbAb\"; \"AbAbAbAb\"):"
							"J3=strcmp(1+1; \"2\"):"
							"J4=strcmp(\"2\"; 1+1):"
							"K0=stricmp(\"ABCDEFg\"; \"abcdefg\"):"
							"K1=stricmp(\"ffgghh\"; \"aabbcc\"):"
							"K2=stricmp(\"aBabcd\"; \"ffgghh\"):"
							"K3=stricmp(1+1; \"2\"):"
							"K4=stricmp(\"2\"; 1+1):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function strcmp() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function strcmp() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalInteger("J0", NULL, integer) && (integer > 0)) {
			printf("Passed: Evaluating strcmp(\"ABCDEFgxx\"; \"ABCDEFg\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating strcmp(\"ABCDEFgxx\"; \"ABCDEFg\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("J1", NULL, integer) && (integer < 0)) {
			printf("Passed: Evaluating strcmp(\"BBBBBBBxx\"; \"CCCCCCC\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating strcmp(\"BBBBBBBxx\"; \"CCCCCCC\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("J2", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating strcmp(\"AbAbAbAb\"; \"AbAbAbAb\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating strcmp(\"AbAbAbAb\"; \"AbAbAbAb\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("K0", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating stricmp(\"ABCDEFg\"; \"abcdefg\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stricmp(\"ABCDEFg\"; \"abcdefg\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("K1", NULL, integer) && (integer > 0)) {
			printf("Passed: Evaluating stricmp(\"ffgghh\"; \"aabbcc\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stricmp(\"ffgghh\"; \"aabbcc\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("K2", NULL, integer) && (integer < 0)) {
			printf("Passed: Evaluating stricmp(\"aBabcd\"; \"ffgghh\") gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stricmp(\"aBabcd\"; \"ffgghh\") gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("K3", NULL, integer) && (integer == 0)) {
			printf("Passed: stricmp Converted int first arg to string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: stricmp did not convert int first arg to expected string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("K4", NULL, integer) && (integer == 0)) {
			printf("Passed: stricmp Converted int second arg to string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: stricmp did not convert int second arg to expected string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("J3", NULL, integer) && (integer == 0)) {
			printf("Passed: strcmp Converted int first arg to string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: strcmp did not convert int first arg to expected string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalInteger("J4", NULL, integer) && (integer == 0)) {
			printf("Passed: strcmp Converted int second arg to string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: strcmp did not convert int second arg to expected string) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_attrnm(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;
    float	real;
	bool	found_bool;

	char classad_string[] = 
							"T012=t:"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function attrnm() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function attrnm() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);
        delete classad;
	}
	return;
}

static void test_function_regexp(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;
    float	real;
	bool	found_bool;

	char classad_string[] = 
							"W0=regexp(\"[Mm]atcH.i\", \"thisisamatchlist\", \"i\"):"
							"W1=regexp(20, \"thisisamatchlist\", \"i\"):"
							"E1=isError(W1):" 
							"W2=regexp(\"[Mm]atcH.i\", 20, \"i\"):"
							"E2=isError(W2):" 
							"W3=regexp(\"[Mm]atcH.i\", \"thisisamatchlist\", 20):"
							"E3=isError(W3):" 
							"W4=regexp(\"[Mm]atcH.i\", \"thisisalist\", \"i\"):"
							"W5=regexp(\"[Mm]atcH.i\", \"thisisamatchlist\"):"
							"W6=regexp(\"([Mm]+[Nn]+)\", \"aaaaaaaaaabbbmmmmmNNNNNN\", \"i\"):"

							"X0=regexps(\"([Mm]at)c(h).i\", \"thisisamatchlist\", \"one is \\1 two is \\2\"):"
							"X1=regexps(\"([Mm]at)c(h).i\", \"thisisamatchlist\", \"one is \\1 two is \\2\",\"i\"):"
							"X2=regexps(20 , \"thisisamatchlist\", \"one is \\1 two is \\2\",\"i\"):"
							"E4=isError(X2):" 
							"X3=regexps(\"([Mm]at)c(h).i\", 20 , \"one is \\1 two is \\2\",\"i\"):"
							"E5=isError(X3):" 
							"X4=regexps(\"([Mm]at)c(h).i\", \"thisisamatchlist\", 20 ,\"i\"):"
							"E6=isError(X4):" 
							"X5=regexps(\"([Mm]at)c(h).i\", \"thisisamatchlist\", \"one is \\1 two is \\2\",20):"
							"E7=isError(X5):" 
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function regexp() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function regexp() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("W0", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating regexp match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E1", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexp pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E2", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexp target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E3", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexp optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W4", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating regexp not a match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp not a match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W5", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating regexp not a match(case sensitive) gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp not a match(case sensitive) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating regexp match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexp match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("X0", NULL, big_string) ||
				strcmp(big_string, "one is mat two is h")) {
			printf("Passed: Evaluating regexps gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps gave %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalString("X1", NULL, big_string) ||
				strcmp(big_string, "one is mat two is h")) {
			printf("Passed: Evaluating regexps gives: %s in line %d\n", 
				   big_string, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps gave %s in line %d\n",
				   big_string, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E4", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexps pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E5", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexps target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E6", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexps return arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps return arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E7", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating regexps optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating regexps optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_stringlists_regexpmember(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;
    float	real;
	bool	found_bool;

	char classad_string[] = 
							"U0=stringlist_regexpMember(\"green\", \"red, blue, green\"):"
							"U1=stringlist_regexpMember(\"green\", \"red; blue; green\",\"; \"):"
							"U2=stringlist_regexpMember(\"([e]+)\", \"red, blue, green\"):"
							"U3=stringlist_regexpMember(\"([p]+)\", \"red, blue, green\"):"
							"W0=stringlist_regexpMember(\"[Mm]atcH.i\", \"thisisamatchlist\", \" ,\", \"i\"):"
							"W1=stringlist_regexpMember(20, \"thisisamatchlist\", \"i\"):"
							"E1=isError(W1):" 
							"W2=stringlist_regexpMember(\"[Mm]atcH.i\", 20, \"i\"):"
							"E2=isError(W2):" 
							"W3=stringlist_regexpMember(\"[Mm]atcH.i\", \"thisisamatchlist\", 20):"
							"E3=isError(W3):" 
							"W7=stringlist_regexpMember(\"[Mm]atcH.i\", \"thisisamatchlist\", \" ,\", 20):"
							"E4=isError(W7):" 
							"W4=stringlist_regexpMember(\"[Mm]atcH.i\", \"thisisalist\", \" ,\", \"i\"):"
							"W5=stringlist_regexpMember(\"[Mm]atcH.i\", \"thisisamatchlist\"):"
							"W6=stringlist_regexpMember(\"([Mm]+[Nn]+)\", \"aaaaaaaaaabbbmmmmmNNNNNN\", \" ,\", \"i\"):"
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function stringlists_regexpmember() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function stringlists_regexpmember() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);

		if (classad->EvalBool("U0", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember matching green : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember failed matching green: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("U1", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember matching green(delimiter change) : %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember failed matching green(delimiter change): %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("U2", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember matching multiple hits in stringlist: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember failed matching multiple hits in stringlist: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("U3", NULL, integer) &&
				(integer == 0)) {
			printf("Passed: Evaluating stringlist_regexpMember multiple stringlist misses: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember multiple stringlist misses: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W0", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E1", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember pattern arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E2", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember target arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E3", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember optional delimiter not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember optional delimiter not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("E4", NULL, integer) &&
				(integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember optional option arg not a string: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W4", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating stringlist_regexpMember not a match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember not a match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W5", NULL, integer) && (integer == 0)) {
			printf("Passed: Evaluating stringlist_regexpMember not a match(case sensitive) gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember not a match(case sensitive) gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

		if (classad->EvalBool("W6", NULL, integer) && (integer == 1)) {
			printf("Passed: Evaluating stringlist_regexpMember match gives: %d in line %d\n", 
				   integer, __LINE__);
			results->AddResult(true);
		} else {
			printf("Failed: Evaluating stringlist_regexpMember match gave %d in line %d\n",
				   integer, __LINE__);
			results->AddResult(false);
		}

        delete classad;
	}
	return;
}

static void test_function_XXX(
	TestResults  *results)     // OUT: Modified to reflect result of test
{
	char	big_string[1024];
	int		integer;
    float	real;
	bool	found_bool;

	char classad_string[] = 
							"";

	ClassAd  *classad;

	config(0);

	classad = new ClassAd(classad_string, ':');
	if (classad == NULL) {
		printf("Can't parse ClassAd for function XXX() in line %d\n", 
			   __LINE__);
		results->AddResult(false);
	} else {
		printf("Parsed ClassAd for << function XXX() >> in line %d\n", 
			   __LINE__);
		results->AddResult(true);
        delete classad;
	}
	return;
}

static bool test_floats_close( float one, float two, float diff)
{
	float ftmp = abs(one) - abs(two);
	if(abs(ftmp) <= diff) {
		return(true);
	} else {
		return(true);
	}
}
#endif

/***************************************************************
 *
 * Function: print_truncated_string
 * Purpose:  Make sure that a string prints out with no more than
 *           the given number of characters. If the string is 
 *           too long, we put an ellipsis at the end. 
 *
 ***************************************************************/
void 
print_truncated_string(
    const char *s,        // IN: The string to print
	int max_characters)   // IN: The maximum number of characters to print
{
	int length;

	if (max_characters < 1) {
		max_characters = 1;
	}

	length = strlen(s);
	if (length > max_characters) {
		if (max_characters > 3) {
			printf("%.*s...", max_characters - 3, s);
		}
		else {
			printf("%.*s", max_characters, s); 
		}
	}
	else {
		printf("%s", s);
	}
	return;
}

/***************************************************************
 *
 * Function: make_big_string
 * Purpose:  create a string of a given length, and fill it with 
 *           random stuff. If quoted_string is not NULL, we make it
 *           a copy of the big string, except with quotes around it.
 *
 ***************************************************************/
static void 
make_big_string(
    int length,           // IN: The desired length
	char **string,        // OUT: the big random string
	char **quoted_string) // OUT: the string in quotes
{
	*string = (char *) malloc(length + 1);

	for (int i = 0; i < length; i++) {
		(*string)[i] = (rand() % 26) + 97; 
	}
	(*string)[length] = 0;

	if (quoted_string != NULL) {
		*quoted_string = (char *) malloc(length + 3);
		sprintf(*quoted_string, "\"%s\"", *string);
	}
	return;
}

/***************************************************************
 *
 * Function: test_random
 * Purpose:  Test the random() function in ClassAds. Our testing
 *           is a bit wonky: since we are getting random numbers,
 *           we can't be sure our tests will work, but chances
 *           are good. :)
 *
 ***************************************************************/
void test_random(
    TestResults *results)
{
    char *classad_string = "R1 = random(), R2 = random(10)";
    int  base_r1, r1;
    int  r2;
    bool have_different_numbers;
    bool numbers_in_range;
	int	i;

    ClassAd *classad;

    classad = new ClassAd(classad_string, ',');

    // First we check that random gives us different numbers
    have_different_numbers = false;
    classad->EvalInteger("R1", NULL, base_r1);
    for ( i = 0; i < 10; i++) {
        classad->EvalInteger("R1", NULL, r1);
        if (r1 != base_r1) {
            have_different_numbers = true;
            break;
        }
    }

    // Then we check that random gives numbers in the correct range
    numbers_in_range = true;
    for ( i = 0; i < 10; i++) {
        classad->EvalInteger("R2", NULL, r2);
        if (r2 < 0 || r2 >= 10) {
            numbers_in_range = false;
            break;
        }
    }

    if (have_different_numbers) {
        printf("Passed: Random generates a variety of numbers in line %d\n", 
               __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: Random does not generate a variety of numbers in line %d\n", 
               __LINE__);
        results->AddResult(false);
    }

    if (numbers_in_range) {
        printf("Passed: Random generates numbers in correct range in %d\n", 
               __LINE__);
        results->AddResult(true);
    } else {
        printf("Passed: Random does not generate numbers in correct range in %d\n", 
               __LINE__);
        results->AddResult(false);
    }
    delete classad;
    return;
}

void test_equality(TestResults *results)
{
    ExprTree *e1, *e2, *e3;
    const char *s1 = "Foo = 3";
    const char *s3 = "Bar = 5";

    Parse(s1, e1);
    Parse(s1, e2);
    Parse(s3, e3);

    if ((*e1) == (*e2)) {
        printf("Passed: operator== detects equality in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: operator== does not detect equality in line %d\n", __LINE__);
        results->AddResult(false);
    }

    if ((*e1) == (*e3)) {
        printf("Failed: operator== does not detect inequality in line %d\n", __LINE__);
        results->AddResult(false);
    } else {
        printf("Passed: operator== detects inequality in line %d\n", __LINE__);
        results->AddResult(true);
    }
    return;
}

// I wrote this function to ensure that short-circuiting
// in ClassAds works correctly, and to ensure that when
// I added short-circuiting, I didn't break normal evaluation
void test_operators(TestResults *results)
{
    extern bool classad_debug_function_run;
    char *classad_string = 
        // Test short-circuiting with logical OR
        "A = TRUE || _debug_function_(), "
        "B = 1 || _debug_function_(), "
        "C = 1.2 || _debug_function_(), "
        // Test no short-circuiting with logical OR
        "D = \"foo\" || _debug_function_(), "
        "E = FALSE || _debug_function_(), "
        "G = 0 || _debug_function_(), "
        "H = 0.0 || _debug_function_(), "
        // Test short-circuiting with logical AND
        "I = FALSE && _debug_function_(), "
        "J = 0 && _debug_function_(), "
        "K = 0.0 && _debug_function_(), "
        "L = \"foo\" && _debug_function_(), "
        // Test no short-circuiting with logical AND
        "M = TRUE && _debug_function_(), "
        "N = 1 && _debug_function_(), "
        "O = 1.2 && _debug_function_() ";
    ClassAd *c = new ClassAd(classad_string, ',');

    // Test short-circuiting with logical OR
    classad_debug_function_run = false;
    test_eval_bool(c, "A", 1, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "B", 1, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "C", 1, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    // Test no short-circuiting with logical OR
    classad_debug_function_run = false;
    test_eval_bool(c, "D", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "E", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "G", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "H", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    // Test short-circuiting with logical AND
    classad_debug_function_run = false;
    test_eval_bool(c, "I", 0, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "J", 0, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "K", 0, __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_error(c, "L", __LINE__, results);
    test_debug_function_run(false, __LINE__, results);

    // Test no short-circuiting with logical AND
    classad_debug_function_run = false;
    test_eval_bool(c, "M", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "N", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

    classad_debug_function_run = false;
    test_eval_bool(c, "O", 1, __LINE__, results);
    test_debug_function_run(true, __LINE__, results);

}

/***************************************************************
 *
 * Function: test_scoping 
 * Purpose:  Make sure that when someone specified MY. or TARGET.,
 *           it only looks there. From 6.3.something through 
 *           6.7.17, MY and TARGET provided a search order, not
 *           a scope. 
 *
 ***************************************************************/
void 
test_scoping(TestResults *results)
{
    char *ad1_string = "A = MY.X, B = TARGET.X, C=MY.Y, D = TARGET.Y, E = Y, G=MY.Z, H=TARGET.Z, J=TARGET.K, L=5, X = 1, Z=4";
    char *ad2_string = "X = 2, Y = 3, K=TARGET.L";
    int value;
    ClassAd *ad1  =  new ClassAd(ad1_string, ',');
    ClassAd *ad2  =  new ClassAd(ad2_string, ',');

    if (ad1->EvalInteger("A", ad2, value) && value == 1) {
         printf("Passed: eval of A is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of A is bad in line %d\n", __LINE__);
    }

    if (ad1->EvalInteger("B", ad2, value) && value == 2) {
         printf("Passed: eval of B is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of B is bad in line %d\n", __LINE__);
    }

    if (!ad1->EvalInteger("C", ad2, value)) {
         printf("Passed: eval of C is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of C is bad in line %d\n", __LINE__);
    }

    if (ad1->EvalInteger("D", ad2, value) && value == 3) {
         printf("Passed: eval of D is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of D is bad in line %d\n", __LINE__);
    }

    if (ad1->EvalInteger("E", ad2, value) && value == 3) {
         printf("Passed: eval of E is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of E is bad in line %d\n", __LINE__);
    }

    if (ad1->EvalInteger("G", ad2, value) && value == 4) {
         printf("Passed: eval of G is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of G is bad in line %d\n", __LINE__);
    }

    if (!ad1->EvalInteger("H", ad2, value)) {
         printf("Passed: eval of H is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of H is bad in line %d\n", __LINE__);
    }
    
    if (ad1->EvalInteger("J", ad2, value) && value == 5) {
         printf("Passed: eval of J is good in line %d\n", __LINE__);
        results->AddResult(true);
    } else {
        printf("Failed: eval of J is bad in line %d\n", __LINE__);
    }
}

/***************************************************************
 *
 * Function: test_eval_error
 * Purpose:  Given a classad and an attribute within the classad,
 *           test that the attribute evaluates an error
 *
 ***************************************************************/
void 
test_debug_function_run(
    bool        expect_run,      // IN: Do we expect that it ran?
    int         line_number,     // IN: The line number to print
    TestResults *results)        // OUT: Modified to reflect result of test
{
    extern bool classad_debug_function_run;
    if (expect_run) {
        if (classad_debug_function_run) {
            printf("Passed: ClassAd debug function ran as expected in line %d\n", 
                   line_number);
            results->AddResult(true);
        } else {
            printf("Failed: ClassAd debug function did not run, but was expected to in line %d\n", 
                   line_number);
            results->AddResult(false);
        }
    } else {
        if (!classad_debug_function_run) {
            printf("Passed: ClassAd debug function did not run, and was not expected to in line %d.\n", 
                   line_number);
            results->AddResult(true);
        } else {
            printf("Failed: ClassAd debug function run when it was not expected to in line %d.\n", 
                   line_number);
            results->AddResult(false);
        }
    }

	return;
}
