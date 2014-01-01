#include "testtokenizer.h"

#include <ecila/tokenizer.h>









void TestTokenizer::Do()
{
	char_t str[] = " Hello,  World";

	Tokenizer t;
	int32_t	count	= t.STokenize(" Hello,  World", ", ");
	int32_t	count2	= t.STokenize(str, "  ");

	assertEquals(2, count);
	assertEquals(2, count2);
}
