/*!	@file	rmRunable.h
 *	@brief	스레드 클래스에서 실행시킬 함수를 담는 클래스 선언
 *	@author	이현우 (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMRUNABLE_H_
#define RM_INCLUDE_RMRUNABLE_H_
//--------------------------------------------------------------------------
class rmRunable
{
private:
	rmRunable(const rmRunable&);
	rmRunable& operator=(const rmRunable&);
public:
	rmRunable(){}
	virtual ~rmRunable(){}
	virtual void SetState(bool State) = 0;
	virtual void Run() = 0;
};
#endif // RM_INCLUDE_RMRUNABLE_H_