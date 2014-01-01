ecila
=======================================


소개
----------
* POSA2를 바탕으로 하는 서버 엔진(네트워크 라이브러리)입니다.
* c++ 으로 작성되었으며 cross platform 을 지향합니다.


특징
----------
* Proactor : iocp (for windows)
* Reactor  : select(Windows/Linux/FreeBSD), epoll(Linux 2.6 higher), kqueue(FreeBSD 7.2 higher)


예제
----------
* test case
* web server

빌드
----------
* Windows 7 : Microsoft Visual Studio 2010
* FreeBSD 7.2 32bit : gcc 4.6.2
* Linux (CentOS 6 64bit) : gcc 4.4.6
* [UTF-8 BOM 소스 컴파일](http://code.google.com/p/ecila/wiki/CompileCppWithUTF8BOM)

주의
----------
* 개인 프로젝트임으로 버그가 발생할수 있으며, 업데이트가 늦을수 있습니다.