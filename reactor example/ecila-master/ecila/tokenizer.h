#pragma once

#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL Tokenizer
{
public:
	enum ENUM_MAX { MAX_TOKENS = 256, MAX_SOURCE_LEN = 4096, };

	 Tokenizer();
	~Tokenizer();

	uint32_t STokenize(char_t *str, const char_t *delim);		//string tokenizer
	uint32_t CTokenize(char_t *str, const char_t *delim);		//character tokenizer

	uint32_t STokenize(const char_t *str, const char_t *delim); //string tokenizer
	uint32_t CTokenize(const char_t *str, const char_t *delim); //character tokenizer


	uint32_t Count();
	char_t*  Token(uint32_t idx);



private:

	uint32_t	count_;						//token count
	char_t		*token_[MAX_TOKENS];		//token pointers
	char_t		source_[MAX_SOURCE_LEN+1];	//source string


	void		Reset();
	bool_t		PushToken(char *token);

	uint32_t	StringTokenize		(char_t *str, const char_t *delim);
	uint32_t	CharacterTokenize	(char_t *str, const char_t *delim);

};

NS_ECILA_END

