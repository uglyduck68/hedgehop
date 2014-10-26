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
	/// ��� DDS �޽����� �����մϴ�.
	virtual void Release();

	/// ��ϵ� DDS �޽����� �����ɴϴ�.
	virtual weak_shared_ptr<ICommandInterface>& GetCommand(const size_t& Hash);
	virtual ProcMap& GetCommandList();
private:

	CommandMgr(const CommandMgr&);
	CommandMgr& operator=(const CommandMgr&);

	/// DDSList
	ProcMap m_ProcMap;
};