/** @file HandlerHolder.h
 ** @brief 핸들 클래스
 ** @date 2014-11-10
 ** @author 박현(hyunpark@endcs.net)
 **/

#pragma once
/*!	@class	HandlerHolder
 *	@brief	핸들 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class HandleHolder {
private:
	typedef void* HANDLE;
	HANDLE _handle;
	/// 핸들을 닫는다.
	void close();
	HandleHolder(const HandleHolder& rhs);
	HandleHolder& operator=(const HandleHolder& rhs);

public:
	/// 생성자
	HandleHolder();
	/** 생성자
		@param h : 저장할 핸들 */
	explicit HandleHolder(HANDLE h);
	/// 소멸자
	~HandleHolder();
	/// 저장된 핸들의 레퍼런스를 얻는다.
	const HANDLE& get() const;
	/** 핸들을 저장한다.
		@param h : 저장할 핸들 */
	void set(HANDLE h);
	operator bool ();
};