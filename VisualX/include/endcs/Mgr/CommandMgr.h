/*!	@file CommandMgr.h
 *	@brief Ŀ�ǵ� �Ŵ���
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "Interface/ICommandInterface.h"
#include "common/refptr.hpp"
#include <unordered_map>

/// ������ �Լ��� �����ϰ� �ִ� �������̽� Ŭ����
class ICommandInterface;
/// �������̽� ��� ����
typedef std::unordered_map<size_t,RefPtr<ICommandInterface>> ProcMap;

/*!	@class	CommandMgr
 *	@brief	Ŀ�ǵ� �Ŵ���
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class CommandMgr
{
public:
	/** Ŀ�ǵ� �Ŵ����� ��ȯ�Ѵ�.
		\ �̱��� �������̽�	*/
	static CommandMgr& GetCommandMgr();
	/** Ŀ�ǵ� �Ŵ����� �޸𸮿��� �����Ѵ�.
		\ �̱��� ����	*/
	static void ReleaseCommandMgr();
	/** Ŀ�ǵ� �Ŵ����� �����Ǿ����� Ȯ���Ѵ�.
		\ �̱��� üũ	*/
	static bool isCreated();
	/// ������
	CommandMgr();
	/// �Ҹ���
	~CommandMgr();

public:
	/** Ŀ�ǵ带 �߰��Ѵ�.
		@param Hash : �߰��� Ŀ�ǵ��� Type Hash ID
		@param Class : �߰��� Ŀ�ǵ� */
	bool AddCommand(const size_t& Hash, ICommandInterface* Class);
	/** Ŀ�ǵ带 �����Ѵ�.
		@param Hash : ������ Ŀ�ǵ��� Type Hash ID	*/
	bool RemoveCommand(const size_t& Hash);
	/// ��� Ŀ�ǵ带 �����Ѵ�.
	void Release();

	/** ��ϵ� Ŀ�ǵ带 �����´�.
		@param Hash : ������ Ŀ�ǵ��� Type Hash ID	*/
	RefPtr<ICommandInterface>& GetCommand(const size_t& Hash);
	/// ��ϵ� ��� Ŀ�ǵ��� ����� �����ɴϴ�.
	ProcMap& GetCommandList();
private:

	CommandMgr(const CommandMgr&);
	CommandMgr& operator=(const CommandMgr&);

	/// DDSList
	ProcMap m_ProcMap;
};