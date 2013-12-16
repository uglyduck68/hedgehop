#pragma	once

namespace X1
{

	const int	INVALID_HANDLE	= -1;
	typedef unsigned long	EVENT_MASK;
	
#ifdef	defined(_LINUX_)

typedef	int		HANDLE;

#elif	defined(_VXWORKS_)

typedef	int		HANDLE;

#elif	defined(_WINDOWS_)

typedef	int		HANDLE;

#endif
}