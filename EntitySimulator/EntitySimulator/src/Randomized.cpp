/*!	@file Randomized.cpp
 *	@brief Custom Random Ŭ����
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#include "Randomized.h"
#include <random>
#include <time.h>

typedef std::mt19937 Engine;
typedef std::uniform_int_distribution<int> Distribution;
typedef std::uniform_real_distribution<double> RealDistribution;

CRandomized::CRandomized()
{
}


CRandomized::~CRandomized(void)
{
}

/*!	@fn	CRandomized::get
 *	@brief	������ : �ش���� \n
			����  : ������ ������ ������ ���� ��ȯ�Ѵ�.
 *	@param	start : ���۰� 
 *	@param	end : �ִ밪
 *	@return	int
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
int CRandomized::get(const int& start,const int& end)
{
	static Engine* generator = nullptr;
	if(!generator) generator = new Engine(clock());
	Distribution distribution(start,end);
	return distribution(*generator);
}

int CRandomized::operator()(const int& min,const int& max)
{
	return get(min,max);
}
/*!	@fn	CRandomized::get
 *	@brief	������ : �ش���� \n
			����  : ������ ������ ������ ���� ��ȯ�Ѵ�.
 *	@param	min : �ּҰ�
 *	@param	max : �ִ밪
 *	@return	double
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-11
 */
double CRandomized::get(const double& min,const double& max)
{
	static Engine* generator = nullptr;
	if(!generator) generator = new Engine(clock());
	RealDistribution distribution(min,max);
	return distribution(*generator);
}

double CRandomized::operator()(const double& min,const double& max)
{
	return get(min,max);
}