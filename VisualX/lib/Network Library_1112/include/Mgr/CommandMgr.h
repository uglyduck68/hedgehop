/*!	@file CommandMgr.h
 *	@brief 커맨드 매니저
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "Interface/ICommandInterface.h"
#include "common/refptr.hpp"
#include <unordered_map>

/// 실행할 함수를 보유하고 있는 인터페이스 클래스
class ICommandInterface;
/// 인터페이스 목록 정의
typedef std::unordered_map<size_t,RefPtr<ICommandInterface>> ProcMap;

/*!	@class	CommandMgr
 *	@brief	커맨드 매니저
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class CommandMgr
{
public:
	/** 커맨드 매니저를 반환한다.
		\ 싱글턴 인터페이스	*/
	static CommandMgr& GetCommandMgr();
	/** 커맨드 매니저를 메모리에서 제거한다.
		\ 싱글턴 해제	*/
	static void ReleaseCommandMgr();
	/** 커맨드 매니저가 생성되었는지 확인한다.
		\ 싱글턴 체크	*/
	static bool isCreated();
	/// 생성자
	CommandMgr();
	/// 소멸자
	~CommandMgr();

public:
	/** 커맨드를 추가한다.
		@param Hash : 추가된 커맨드의 Type Hash ID
		@param Class : 추가할 커맨드 */
	bool AddCommand(const size_t& Hash, ICommandInterface* Class);
	/** 커맨드를 제거한다.
		@param Hash : 제거할 커맨드의 Type Hash ID	*/
	bool RemoveCommand(const size_t& Hash);
	/// 모든 커맨드를 삭제한다.
	void Release();

	/** 등록된 커맨드를 가져온다.
		@param Hash : 가져올 커맨드의 Type Hash ID	*/
	RefPtr<ICommandInterface>& GetCommand(const size_t& Hash);
	/// 등록된 모든 커맨드의 목록을 가져옵니다.
	ProcMap& GetCommandList();
private:

	CommandMgr(const CommandMgr&);
	CommandMgr& operator=(const CommandMgr&);

	/// DDSList
	ProcMap m_ProcMap;
};