************************************
****** ACE Static ���� �ϱ� ********
************************************
1. static ���� �����ϱ�
http://groups.google.com/group/comp.soft-sys.ace/browse_thread/thread/1eb2a24108d2b1c1# �����Ѵ�.

�����ϰ� ����ϸ� �Ʒ��� ���� perl script�� ���� �ش�.

$ACE_ROOT\ace> ..\bin\mwc.pl -type vc10 -static


2. static ���� ���� �ϸ鼭 ssl�� �߰� �Ϸ���

- $(ACE_ROOT)\bin\MakeProjectCreator\config\vc9.features(VC 9.0�� ��쿡) ���Ͽ� SSL �׸��� 1 �� �����Ѵ�.
- 1 �׸��� mwc.pl�� ���� �ش�.
- SSL project�� ���� �ϸ�Ǵµ� ssl.h �� 0 ����Ʈ�� ��찡 �ִ�.

�� ������ ssl.h�� 2���� �����ؼ� �׷���. $(SSL_ROOT)\inc32\openssl\ssl.h�� �´� �����̴�.

===> ACE_SSLs.lib ACE_SSLsd.lib ������ static ���� ����� SSL ���̺귯�� ��.


ACE�� static ���� �������ϴ� ���

ace.sIn project ������ �̿��Ѵ�. �� ������ mwm �ΰ��� ���ؼ� ������� �����̴�.

1. ACE_ROOT ȯ�� ���� ���ǵǾ� �ְ�,
2. perl ��ġ�Ǿ� ������
3 $(ACE_ROOT)/ace ���͸����� ..\bin\mwc.pl -type vc9 -static �� �����ϸ�
4. $(ACE_ROOT)/ace ���͸��� ace.sIn, ACE.vcproj ������ �����. �� ������Ʈ ������ �̿��Ͽ� �����ϸ� �� �� �ϴ�.


ACE�� dll�� �������ϴ� ���
- ���� ���� ������ ace_vc9.sIn ������Ʈ ������ �̿��Ѵ�.


*** ace�� vc9�� �����ϰ�, ���� ���α׷��� vc10�� �̿��ϴ� ��� ���� �� ������ ���� ������ �ִ�.
�����Ϸ� ������ �� ����� �Ѵ�.

build ACE for vxworks
----------------------------------------------------------------
�� ��ǻ�Ϳ����� �̹� ���带�߰�, �� ������ "ACE-INSTALL.html" �� �����ִ�.

1. PATH ����
PATH�� C:\WindRiver\utilities-1.0\x86-win32\bin �� �Ǿտ� �����Ǿ� �־�� �Ѵ�. ������ make ���� ���� ������ ���⿡ ���ǵǾ� �ֱ� ������.

2. ȯ�溯�� ����
�������� �׷��� �ʾҴµ� �̹��� �������� �ϴµ� �Ʒ��� ȯ�� ������ �����϶�� �Ѵ�. �� ��������
platform_macros.GNU�� ���ǰ� �Ǿ� �ִµ��� ���̴�.
WIND_HOME
WIND_USR
WIND_LIC_PROXY <-- ��� �ȵ��־ �������� �Ǵµ�. �����Ѵٸ� c:\WindRiver\setup\x86-win32\bin

"D:\Lib\ACE-6.1.0\ACE_wrappers\include\makeinclude\platform_macros.GNU" �� ��κ��� �ʿ��� ���� ������ ���Ҵ�.

3. cmd.exe ���� make ����

������� �����ϸ� static library�� ���尡 ����ȴ�. vxworks kernel�� ���Խ�Ű�� ���ؼ��� shared library�� ���带 �ؾ��ϴ� �ɷ� ���δ�. �� �κ��� "ACE-INSTALL.html" �� ��������.
