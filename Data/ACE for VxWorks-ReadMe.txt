************************************
****** ACE Static 빌드 하기 ********
************************************
1. static 으로 빌드하기
http://groups.google.com/group/comp.soft-sys.ace/browse_thread/thread/1eb2a24108d2b1c1# 참조한다.

간단하게 요약하면 아래와 같이 perl script를 돌려 준다.

$ACE_ROOT\ace> ..\bin\mwc.pl -type vc10 -static


2. static 으로 빌드 하면서 ssl을 추가 하려면

- $(ACE_ROOT)\bin\MakeProjectCreator\config\vc9.features(VC 9.0의 경우에) 파일에 SSL 항목을 1 로 설정한다.
- 1 항목의 mwc.pl을 돌려 준다.
- SSL project를 빌드 하면되는데 ssl.h 가 0 바이트인 경우가 있다.

이 문제는 ssl.h가 2군데 존재해서 그렇다. $(SSL_ROOT)\inc32\openssl\ssl.h가 맞는 파일이다.

===> ACE_SSLs.lib ACE_SSLsd.lib 파일이 static 으로 빌드된 SSL 라이브러리 임.


ACE를 static 으로 컴파일하는 방법

ace.sIn project 파일을 이용한다. 이 파일은 mwm 인가를 통해서 재생성된 파일이다.

1. ACE_ROOT 환경 변수 정의되어 있고,
2. perl 설치되어 있으면
3 $(ACE_ROOT)/ace 디렉터리에서 ..\bin\mwc.pl -type vc9 -static 을 실행하면
4. $(ACE_ROOT)/ace 디렉터리에 ace.sIn, ACE.vcproj 파일이 생긴다. 이 프로젝트 파일을 이용하여 빌드하면 될 듯 하다.


ACE를 dll로 컴파일하는 방법
- 원래 따라 나오는 ace_vc9.sIn 프로젝트 파일을 이용한다.


*** ace를 vc9로 빌드하고, 메인 프로그램을 vc10을 이용하는 경우 실행 시 오류가 나는 현상이 있다.
컴파일러 버전을 잘 맞춰야 한다.

build ACE for vxworks
----------------------------------------------------------------
내 컴퓨터에서는 이미 빌드를했고, 그 내용은 "ACE-INSTALL.html" 에 나와있다.

1. PATH 설정
PATH에 C:\WindRiver\utilities-1.0\x86-win32\bin 가 맨앞에 설정되어 있어야 한다. 이유는 make 등의 빌드 도구가 여기에 정의되어 있기 때문에.

2. 환경변수 설정
예전에는 그렇지 않았는데 이번에 컴파일을 하는데 아래의 환경 변수를 정의하라고 한다. 이 변수들이
platform_macros.GNU에 정의가 되어 있는데도 말이다.
WIND_HOME
WIND_USR
WIND_LIC_PROXY <-- 요건 안되있어도 컴파일이 되는듯. 설정한다면 c:\WindRiver\setup\x86-win32\bin

"D:\Lib\ACE-6.1.0\ACE_wrappers\include\makeinclude\platform_macros.GNU" 에 대부분의 필요한 것을 정의해 놓았다.

3. cmd.exe 에서 make 실행

여기까지 진행하면 static library로 빌드가 진행된다. vxworks kernel에 포함시키기 위해서는 shared library로 빌드를 해야하는 걸로 보인다. 이 부분은 "ACE-INSTALL.html" 를 참조하자.
