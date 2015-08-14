--------------------------------------
MySQL example 빌드하기
--------------------------------------

1. makefile.mysql 수정
	- cmd 에서 컴파일 가능하도록 VC관련 환경 변수 설정(vavarall.bat 수행)
	- makefile 수정 후
	- nmake /f makefile.mysql 로 컴파일
	
2. MySQL 관련 dll(mysqlcppconn.dll, libmysql.dll) 복사