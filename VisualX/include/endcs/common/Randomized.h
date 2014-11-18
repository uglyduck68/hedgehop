/*!	@file Randomized.h
 *	@brief Custom Random Ŭ����
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
/*!	@class	CRandomized
 *	@brief	mt19937 Random Class
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class CRandomized
{
public:
	CRandomized();
	int operator()(const int& start,const int& end);
	double operator()(const double& min,const double& max);
	~CRandomized(void);
	int get(const int& start,const int& end);
	double get(const double& min,const double& max);
};