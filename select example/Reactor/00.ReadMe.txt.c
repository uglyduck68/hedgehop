[TO DO]
- config.h에 build macros가 정의됨에 따라 관련 헤더 파일 및 라이브러리의 인클루드 패스가
	설정이 되어야 하는데 VisualStudio IDE에서는 이걸 미리 알아서할 수가 없다.

[20140508]
1. replace Thread class with OpenThread library
2. macro constants like _X1_WINDOWS_, PTHREAD_H, etc will be refactored.
3. This should be build as library type. and only example applications are build as execution type.
4. Make more examples.
5. Refactor Types.h file.
6. sem_t같은 넘 때문에 데이터 타입 명칭을 변경해야할 듯 함. 예를 들면 X1_Sem_t or Sem_t 뭐 이런식으로.
7. _X1_WINDOWS_에서 _X1_USE_PTHREAD_ 할 때와 _X1_LINUX_(또는 _X1_VXWORKS_)  에서 _X1_USE_PTHREAD_ 할 때를 구분하는
   빌드 매크로가 필요하다. 그래야 인클루드 할 때 플랫폼 별로 적당한 클래스가 빌드된다.

//6. Make thread_mutex_t, thread_cond_t type as class.

[20140516]
- complete to replace Thread class by using TestThread project.

[20140519]
- start to replace Threadpool class and test it by using TestThreadpool2 project.

