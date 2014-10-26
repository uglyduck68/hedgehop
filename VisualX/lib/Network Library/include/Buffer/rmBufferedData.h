#include <vector>
#include <memory>
#include <functional>
/*!	@file	rmBufferedData.h
 *	@brief	버퍼에 저장되는 데이터 클래스 선언
 *	@author	이현우 (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMBUFFEREDDATA_H_
#define RM_INCLUDE_RMBUFFEREDDATA_H_
class ICommandInterface;
class ISocket;
class rmBufferedData
{
public:
	rmBufferedData(unsigned char* data, unsigned int size,std::shared_ptr<ICommandInterface> Work);
	rmBufferedData(std::vector<unsigned char>&& data,std::shared_ptr<ICommandInterface> Work);
	rmBufferedData(unsigned char* data, unsigned int size,std::function<void(void*)> Work);
	rmBufferedData(std::vector<unsigned char>&& data,std::function<void(void*)> Work);
	rmBufferedData(unsigned char* data, unsigned int size,std::function<void(void*,std::shared_ptr<ISocket>)> Work);
	rmBufferedData(std::vector<unsigned char>&& data,std::function<void(void*,std::shared_ptr<ISocket>)> Work);
	rmBufferedData(const rmBufferedData&);
	rmBufferedData(rmBufferedData/*&&*/* data);
	rmBufferedData();
	virtual ~rmBufferedData();

	const size_t GetSize() const;

	unsigned char* GetData();
	void RunWorker();
	void RunWorker(std::shared_ptr<ISocket> socket);
	void Clear();
	void operator()();
	std::shared_ptr<ICommandInterface> GetWorker() { return Worker; }

protected:
	std::vector<unsigned char> m_Data;
	std::function<void(void*)> Func;
	std::function<void(void*,std::shared_ptr<ISocket>)> SocketFunc;
	std::shared_ptr<ICommandInterface> Worker;
};
#endif // RM_INCLUDE_RMBUFFEREDDATA_H_