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

/*
	This code tests the sin_to_string() function implementation.
 */

#include "condor_common.h"
#include "condor_debug.h"
#include "condor_config.h"
#include "internet.h"
#include "function_test_driver.h"
#include "emit.h"
#include "unit_test_utils.h"

static bool test_normal_case(void);
static bool test_general_domain(void);
static bool test_two_hostname(void);
static bool test_different_subdomain(void);

bool FTEST_host_in_domain(void) {
		// beginning junk for getPortFromAddr()
	e.emit_function("host_in_domain(char* host, char* domain)");
	e.emit_comment("Converts a sockaddr_in to a sinful string.");
	e.emit_problem("None");
	
		// driver to run the tests and all required setup
	FunctionDriver driver;
	driver.register_function(test_normal_case);
	driver.register_function(test_general_domain);
	driver.register_function(test_two_hostname);
	driver.register_function(test_different_subdomain);
	
		// run the tests
	bool test_result = driver.do_all_functions();
	e.emit_function_break();
	return test_result;
}

static bool test_normal_case() {
	e.emit_test("Is a positive case identified correctly?");
	char* input_host = strdup( "balthazar.cs.wisc.edu" );
	char* input_domain = strdup( "cs.wisc.edu" );
	e.emit_input_header();
	e.emit_param("HOST", input_host);
	e.emit_param("DOMAIN", input_domain);
	int result = host_in_domain(input_host, input_domain);
	free(input_host);
	free(input_domain);
	e.emit_output_expected_header();
	e.emit_retval("%s", tfstr(TRUE));
	e.emit_output_actual_header();
	e.emit_retval("%s", tfstr(result));
	if(result != TRUE) {
		e.emit_result_failure(__LINE__);
		return false;
	}
	e.emit_result_success(__LINE__);
	return true;
}

static bool test_general_domain() {
	e.emit_test("Is a more generic domain identified correctly?");
	char* input_host = strdup( "balthazar.cs.wisc.edu" );
	char* input_domain = strdup( "wisc.edu" );
	e.emit_input_header();
	e.emit_param("HOST", input_host);
	e.emit_param("DOMAIN", input_domain);
	int result = host_in_domain(input_host, input_domain);
	free(input_host);
	free(input_domain);
	e.emit_output_expected_header();
	e.emit_retval("%s", tfstr(TRUE));
	e.emit_output_actual_header();
	e.emit_retval("%s", tfstr(result));
	if(result != TRUE) {
		e.emit_result_failure(__LINE__);
		return false;
	}
	e.emit_result_success(__LINE__);
	return true;
}

static bool test_two_hostname() {
	e.emit_test("Is a test with two hostnames in the same domain identified as failure?");
	char* input_host = strdup( "balthazar.cs.wisc.edu" );
	char* input_domain = strdup( "jerez.cs.wisc.edu" );
	e.emit_input_header();
	e.emit_param("HOST", input_host);
	e.emit_param("DOMAIN", input_domain);
	int result = host_in_domain(input_host, input_domain);
	free(input_host);
	free(input_domain);
	e.emit_output_expected_header();
	e.emit_retval("%s", tfstr(FALSE));
	e.emit_output_actual_header();
	e.emit_retval("%s", tfstr(result));
	if(result != FALSE) {
		e.emit_result_failure(__LINE__);
		return false;
	}
	e.emit_result_success(__LINE__);
	return true;
}

static bool test_different_subdomain() {
	e.emit_test("Is failure identified in different subdomains of the same domain?");
	char* input_host = strdup( "balthazar.cs.wisc.edu" );
	char* input_domain = strdup( "www.wisc.edu" );
	e.emit_input_header();
	e.emit_param("HOST", input_host);
	e.emit_param("DOMAIN", input_domain);
	int result = host_in_domain(input_host, input_domain);
	free(input_host);
	free(input_domain);
	e.emit_output_expected_header();
	e.emit_retval("%s", tfstr(FALSE));
	e.emit_output_actual_header();
	e.emit_retval("%s", tfstr(result));
	if(result != FALSE) {
		e.emit_result_failure(__LINE__);
		return false;
	}
	e.emit_result_success(__LINE__);
	return true;
}
