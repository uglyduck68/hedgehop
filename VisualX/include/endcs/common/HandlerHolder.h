/** @file HandlerHolder.h
 ** @brief �ڵ� Ŭ����
 ** @date 2014-11-10
 ** @author ����(hyunpark@endcs.net)
 **/

#pragma once
/*!	@class	HandlerHolder
 *	@brief	�ڵ� Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class HandleHolder {
private:
	typedef void* HANDLE;
	HANDLE _handle;
	/// �ڵ��� �ݴ´�.
	void close();
	HandleHolder(const HandleHolder& rhs);
	HandleHolder& operator=(const HandleHolder& rhs);

public:
	/// ������
	HandleHolder();
	/** ������
		@param h : ������ �ڵ� */
	explicit HandleHolder(HANDLE h);
	/// �Ҹ���
	~HandleHolder();
	/// ����� �ڵ��� ���۷����� ��´�.
	const HANDLE& get() const;
	/** �ڵ��� �����Ѵ�.
		@param h : ������ �ڵ� */
	void set(HANDLE h);
	operator bool ();
};