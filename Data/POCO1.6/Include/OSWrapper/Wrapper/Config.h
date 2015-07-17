#if defined(_I7_VXWORKS_32)
// macro definition for vxworks-6.9

#define	POCO_VXWORKS
#define	VXWORKS_VERSION_MAJOR	6
#define	VXWORKS_VERSION_MINOR	9
#define	i386

#elif defined(_WIN32)
// macro definition for win32

#elif defined(_WIN32) && defined(_WIN64)
// macro definition for win64

#endif
