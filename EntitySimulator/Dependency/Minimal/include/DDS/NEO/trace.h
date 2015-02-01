/*
	TRACE 관련 헤더
	작성자 : 
	이력
	2010-08-8 : 시작

*/

#if !defined(__TRACE_H)
#define __TRACE_H
#endif

struct trace_t
{
    MODULE_COMMON_FIELD

	moduleload_t	*p_moduleload;
	void ( *pf_trace ) (trace_t *p_trace, int mode, char *p_str);

	trace_sys_t		*p_sys;
};

#if !defined(_DEBUG)
#define trace_msg(arg1, arg2, arg3, ...) ;
#define launchTraceModule(arg1) ;
#else
#ifdef __cplusplus
extern "C" {
#endif
#ifdef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : Trace모듈을 domainID에 따라 런칭할 수 있도록 수정
	int	launchTraceModule(module_object_t *p_this);
#else
	int	launchTraceModule(module_object_t *p_this, int32_t domainID);
#endif	//DDS_147_JWKIM_141204_MULTI_DOMAIN
	//void  trace_msg(module_object_t *p_this, int mode, const char *psz_format, ...);

#ifdef __cplusplus
}
#endif


#endif