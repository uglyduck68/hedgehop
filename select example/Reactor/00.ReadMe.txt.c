[TO DO]
- config.h에 build macros가 정의됨에 따라 관련 헤더 파일 및 라이브러리의 인클루드 패스가
	설정이 되어야 하는데 VisualStudio IDE에서는 이걸 미리 알아서할 수가 없다.

[20140508]
1. replace Thread class with OpenThread library
2. macro constants like _X1_WINDOWS_, PTHREAD_H, etc will be refactored.
3. This should be build as library type. and only example applications are build as execution type.
4. Make more examples.
5. Refactor Types.h file.
//6. Make thread_mutex_t, thread_cond_t type as class.