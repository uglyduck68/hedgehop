[TO DO]
- config.h�� build macros�� ���ǵʿ� ���� ���� ��� ���� �� ���̺귯���� ��Ŭ��� �н���
	������ �Ǿ�� �ϴµ� VisualStudio IDE������ �̰� �̸� �˾Ƽ��� ���� ����.

[20140508]
1. replace Thread class with OpenThread library
2. macro constants like _X1_WINDOWS_, PTHREAD_H, etc will be refactored.
3. This should be build as library type. and only example applications are build as execution type.
4. Make more examples.
5. Refactor Types.h file.
6. sem_t���� �� ������ ������ Ÿ�� ��Ī�� �����ؾ��� �� ��. ���� ��� X1_Sem_t or Sem_t �� �̷�������.
7. _X1_WINDOWS_���� _X1_USE_PTHREAD_ �� ���� _X1_LINUX_(�Ǵ� _X1_VXWORKS_)  ���� _X1_USE_PTHREAD_ �� ���� �����ϴ�
   ���� ��ũ�ΰ� �ʿ��ϴ�. �׷��� ��Ŭ��� �� �� �÷��� ���� ������ Ŭ������ ����ȴ�.

//6. Make thread_mutex_t, thread_cond_t type as class.

[20140516]
- complete to replace Thread class by using TestThread project.

[20140519]
- start to replace Threadpool class and test it by using TestThreadpool2 project.

