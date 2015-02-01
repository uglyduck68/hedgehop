#include <core.h>
#include <cpsdcps.h>
#include <dcps_func.h>
#if defined(_MSC_VER)
#define STRUCT_ALIGNED_(x) struct __declspec(align(x))
#elif defined(__GNUC__)
#define STRUCT_ALIGNED_(x) struct __attribute__ ((aligned(x)))
#else
#define STRUCT_ALIGNED_(x) struct
#endif

typedef STRUCT_ALIGNED_(1) ShapeType {
	dds_string color;
	int32_t x;
	int32_t y;
	int32_t shapesize;
} ShapeType;

class ShapeTypeTypeSupport
{
public:
	FooTypeSupport	*fooTS;
public:
	void register_topic_type(DomainParticipant *p_Participant)
	{
		if(p_Participant == NULL) return;
		{
			fooTS = get_new_foo_type_support();
			insert_topic_parameters(fooTS);
			fooTS->i_size = sizeof(struct ShapeType);
			fooTS->register_type(fooTS, p_Participant, "ShapeType");
		}
	}
	void insert_topic_parameters(FooTypeSupport *fooTS)
	{
		{dds_parameter_t *p_para = get_new_parameter("color", DDS_String, sizeof(dds_string));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("x", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("y", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
		{dds_parameter_t *p_para = get_new_parameter("shapesize", DDS_Int32, sizeof(int32_t));
		INSERT_PARAM(fooTS->pp_parameters, fooTS->i_parameters, fooTS->i_parameters, p_para, dds_parameter_t**);}
	}
};

