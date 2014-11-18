/*!	@file rmBufferedData.h
 *	@brief 데이터와 실행될 함수를 가지고 있는 컨테이너
 *	@author 박현(hyunpark@endcs.net)
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
 *	@brief	데이터와 실행될 함수를 가지고 있는 컨테이너
 *	@author	박현(hyunpark@endcs.net)
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
	/// 데이터 사이즈를 반환한다.
	const size_t GetSize();
	/// 데이터를 얻어온다.
	unsigned char* GetData();
	/// 저장된 함수를 실행한다
	void RunWorker();
	/// 저장된 함수를 실행한다.
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