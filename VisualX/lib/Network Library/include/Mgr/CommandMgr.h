#pragma once
#include "Common/template.hpp"
class ICommandInterface;
/// DDS Vector
typedef std::unordered_map<size_t,weak_shared_ptr<ICommandInterface>> ProcMap;

class CommandMgr
{
public:
	static CommandMgr& GetCommandMgr();
	static void ReleaseCommandMgr();

	CommandMgr(){}
	virtual ~CommandMgr();
public:

	virtual bool AddCommand(const size_t& Hash, ICommandInterface* Class);
	virtual bool RemoveCommand(const size_t& Hash);
	/// 모든 DDS 메시지를 삭제합니다.
	virtual void Release();

	/// 등록된 DDS 메시지를 가져옵니다.
	virtual weak_shared_ptr<ICommandInterface>& GetCommand(const size_t& Hash);
	virtual ProcMap& GetCommandList();
private:

	CommandMgr(const CommandMgr&);
	CommandMgr& operator=(const CommandMgr&);

	/// DDSList
	ProcMap m_ProcMap;
};