#include "tokenizer.h"







US_ECILA

Tokenizer::Tokenizer()
{
	Reset();
}








Tokenizer::~Tokenizer()
{
}








uint32_t Tokenizer::STokenize(char_t *str, const char_t *delim)
{
	Reset();

	return StringTokenize(str, delim);
}








uint32_t Tokenizer::CTokenize(char_t *str, const char_t *delim)
{
	Reset();

	return CharacterTokenize(str, delim);
}








uint32_t Tokenizer::STokenize(const char_t *str, const char_t *delim)
{
	Reset();

	ecila_strncpy(source_, str, sizeof(source_));

	return StringTokenize(source_, delim);
}








uint32_t Tokenizer::CTokenize(const char_t *str, const char_t *delim)
{
	Reset();

	ecila_strncpy(source_, str, sizeof(source_));

	return CharacterTokenize(source_, delim);
}








uint32_t Tokenizer::Count()
{
	return count_;
}








char_t* Tokenizer::Token(uint32_t idx)
{
	if(idx >= count_) { ECILA_TRACE(); return 0; }

	return token_[idx];
}








void Tokenizer::Reset()
{
	count_	= 0;
	memset(token_,	0, sizeof(token_));
	memset(source_, 0, sizeof(source_));
}








bool_t Tokenizer::PushToken(char *token)
{
	if(count_ >= MAX_TOKENS) { ECILA_TRACE(); return FALSE; }

	token_[count_] = token;
	count_++;

	return TRUE;
}








uint32_t Tokenizer::StringTokenize(char_t *str, const char_t *delim)
{
	uint32_t delim_len = ecila_strlen(delim);
	if(delim_len == 0) { ECILA_TRACE(); return 0; }
	if(delim_len == 1) { return CTokenize(str, delim); }

	bool_t ret		= FALSE;
	char_t *next	= str;
	char_t *token	= 0;

	token = strstr(next, delim);
	if(!token) { return count_; }

	while(token != 0)
	{
		if(next == token)
		{
			next = token + delim_len;
			token = strstr(next, delim);
			continue;
		}

		*token = '\0';

		ret = PushToken(next);
		if(!ret) { ECILA_TRACE(); return 0; }

		next = token + delim_len;
		token = strstr(next, delim);
	}

	ret = PushToken(next);
	if(!ret) { ECILA_TRACE(); return 0; }

	return count_;
}








uint32_t Tokenizer::CharacterTokenize(char_t *str, const char_t *delim)
{
	bool_t ret		= FALSE;
	char_t *next	= 0;
	char_t *token	= 0;

	token = ecila_strtok(str, delim, &next);
	while(token != 0)
	{
		ret = PushToken(token);
		if(!ret) { ECILA_TRACE(); return 0; }

		token = ecila_strtok(0, delim, &next);
	}

	return count_;
}

