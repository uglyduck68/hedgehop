#pragma once


#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL File
{
public:
	enum ENUM_MAX { MAX_FILE_PATH = 255, };

	 File();
	~File();

	bool_t Open		(const char_t* path, const char_t *mode);
	bool_t ReadLine (char_t *buffer, int32_t buff_size, int32_t &read_size);
	bool_t Write	(const char_t* msg);
	bool_t Write	(const void *buffer, uint32_t elem_size, uint32_t elem_count);
	bool_t Close	();


private:

	FILE *fp_;
	char path_[MAX_FILE_PATH + 1];

	void Initialize();
	void Finalize();
};

NS_ECILA_END

