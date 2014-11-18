/*!	@file rmBufferedData.h
 *	@brief �����Ϳ� ����� �Լ��� ������ �ִ� �����̳�
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#ifndef RM_INCLUDE_RMBUFFEREDDATA_H_
#define RM_INCLUDE_RMBUFFEREDDATA_H_

#include <vector>
#include <functional>
#include "common/RefPtr.hpp"

class ISocket;
class Mutex;
/*!	@class	rmBufferedData
 *	@brief	�����Ϳ� ����� �Լ��� ������ �ִ� �����̳�
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class rmBufferedData
{
public:
	rmBufferedData(unsigned char* data, unsigned int size,std::function<void(void*)> Work);
	rmBufferedData(unsigned char* data, unsigned int size,std::function<void(void*,RefPtr<ISocket>)> Work);
	rmBufferedData(rmBufferedData&&);
	rmBufferedData();
	virtual ~rmBufferedData();
	/// ������ ����� ��ȯ�Ѵ�.
	const size_t GetSize();
	/// �����͸� ���´�.
	unsigned char* GetData();
	/// ����� �Լ��� �����Ѵ�
	void RunWorker();
	/// ����� �Լ��� �����Ѵ�.
	void RunWorker(RefPtr<ISocket> socket);
	void operator()();
	void operator()(RefPtr<ISocket> socket);

protected:
	std::vector<unsigned char> m_Data;
	std::function<void(void*)> Func;
	RefPtr<Mutex> m_mutex;
	std::function<void(void*,RefPtr<ISocket>)> SocketFunc;
};
#endif // RM_INCLUDE_RMBUFFEREDDATA_H_