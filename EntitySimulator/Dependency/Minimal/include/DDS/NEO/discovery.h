/*
	��Ŀ���� ���� ���
	�ۼ��� : 
	�̷�
	2010-09-27 : ����

*/

#if !defined(__DISCOVERY_H)
#define __DISCOVERY_H

typedef struct discovery_sys_t discovery_sys_t;

struct discovery_t
{
    MODULE_COMMON_FIELD

	moduleload_t*	p_moduleload;

	discovery_sys_t*	p_sys;
};


#ifdef __cplusplus
extern "C" {
#endif
#ifdef DDS_147_JWKIM_141204_MULTI_DOMAIN	//jwkim : domainID�� ���� ��Ī�ϵ��� ����
	int launch_discovery_module(module_object_t* p_this);
#else
	int launch_discovery_module(module_object_t* p_this, int32_t domain_id);
#endif //DDS_147_JWKIM_141204_MULTI_DOMAIN

#ifdef __cplusplus
}
#endif

#endif