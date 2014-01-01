#include "file.h"








US_ECILA

File::File()
{
	Initialize();
}





File::~File()
{
	Finalize();
}








bool_t File::Open(const char_t *path, const char_t *mode)
{
	if(fp_ != NULL)		{ ECILA_TRACE(); return FALSE; } 
	if(!path || !mode)	{ ECILA_TRACE(); return FALSE; }

	ecila_strncpy(path_, path, sizeof(path_));

#ifdef OS_WINDOWS
	int32_t ret = fopen_s(&fp_, path, mode);
	if(ret != 0 || !fp_) { ECILA_TRACE(); return FALSE; }
#else
	fp_ = fopen(path, mode);
	if(!fp_) { ECILA_TRACE(); return FALSE; }
#endif

	return TRUE;
}








bool_t File::ReadLine(char_t *buffer, int32_t buff_size, int32_t &read_size)
{
	char_t *line = fgets(buffer, buff_size, fp_);
	if(line == NULL) { read_size = 0; return FALSE; }
	else			 { read_size = ecila_strlen(buffer); return TRUE; }
}








bool_t File::Write(const char_t *msg)
{
	int32_t ret = 0;

	if(!fp_ || !msg) { ECILA_TRACE(); return FALSE; } 

	ret = fprintf(fp_, msg);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t File::Write(const void *buffer, uint32_t elem_size, uint32_t elem_count)
{
	int32_t ret = 0;

	if(!fp_ || !buffer || elem_size <= 0 || elem_count <= 0)
	{
		ECILA_TRACE(); return FALSE;
	}

	ret = fwrite(buffer, elem_size, elem_count, fp_);
	if(ret == 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t File::Close()
{
	Finalize();

	return TRUE;
}








void File::Initialize()
{
	fp_ = 0;
	memset(path_, 0, sizeof(path_));
}








void File::Finalize()
{
	if(fp_) { fclose(fp_); fp_ = 0; }
	path_[0] = '\0';
}

