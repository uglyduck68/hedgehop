/*
	UTIL ���� �������

	�ۼ��� : 
	�̷�
	2010-08-5: ����
*/

#if !defined(__UTIL_H)
#define __UTIL_H


#ifdef __cplusplus
extern "C" {
#endif
	
	FILE* open_file(const char* psz_file_path, const char* psz_mode);
	int close_file(FILE* p_file);

	size_t strlcpy (char *tgt, const char *src, size_t bufsize);
	int vasprintf(char **strp, const char *fmt, va_list ap);
	int asprintf( char **strp, const char *fmt, ... );

	char* get_default_local_address();
	void set_string(dds_string* p_string, char* p_value);
	char* get__string(dds_string* p_string);

	/***
	 * static ip_addr string ���� �Լ� �߰�
	 *
	 * by seojune(20140715)
	 ***/
	void free_ip_string();

#ifdef __cplusplus
}
#endif


#endif