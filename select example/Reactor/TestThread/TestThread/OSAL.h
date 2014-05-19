#ifndef	_OSAL_H_
#define _OSAL_H_

#pragma once

class OSAL
{
public:
	OSAL(void);
	~OSAL(void);


	static void	sleep(int nsec);
};

#endif