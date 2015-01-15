   ___                   _              __    __ _                  _ 
  /___\__ _ _ __ ___    /_\  _ __  _ __/ / /\ \ (_)______ _ _ __ __| |
 //  // _` | '__/ _ \  //_\\| '_ \| '_ \ \/  \/ / |_  / _` | '__/ _` |
/ \_// (_| | | |  __/ /  _  \ |_) | |_) \  /\  /| |/ / (_| | | | (_| |
\___/ \__, |_|  \___| \_/ \_/ .__/| .__/ \/  \/ |_/___\__,_|_|  \__,_|
      |___/                 |_|   |_|                                 
      Ogre 1.8.x Application Wizard for VC10 (May 2012)
      https://bitbucket.org/jacmoe/ogreappwizards
========================================================================
    About the "BattlefiedlVisualization" Project
========================================================================

The OGRE Application Wizard has created this OGRE "BattlefiedlVisualization" project for you.
It serves as a starting point, whether you want to do some quick OGRE-testing,
or just want to create an OGRE compliant project real fast.

IMPORTANT!
This wizard relies on the OGRE_HOME environment variable being set to the root directory of your Ogre SDK, like this:
D:\OgreSDK\OgreSDK_vc10_v1-8-0

You can do that in Windows Vista and later by opening a command prompt and do this:
setx OGRE_HOME D:\OgreSDK\OgreSDK_vc10_v1-8-0

Alternatively, navigate to the Ogre SDK directory and enter this:
setx OGRE_HOME %CD%

You can check if OGRE_HOME is set correctly by typing this in a command shell (cmd.exe):
set OGRE_HOME

For users of Windows XP, see this:
http://vlaurie.com/computers2/Articles/environment.htm
Open Control Panel-Performance and Maintenance-System - click Advanced tab and the Environment Variables button; then create a new environment variable OGRE_HOME.

Enjoy! ;-))

/////////////////////////////////////////////////////////////////////////////
About the wizard:

Remember that you can customize and tweak the wizard to your liking.
Look in the "templates" directory where you placed the OGRE Application Wizard.
(Might be a good idea to make a backup copy, just in case...)

The Ogre AppWizard is hosted at https://bitbucket.org/jacmoe/ogreappwizards
Feature requests, bug reports, etc - use the project issue tracker.

Alternatively, leave a note in the Ogre Forum: http://www.ogre3d.org/forums/index.php

/////////////////////////////////////////////////////////////////////////////
// Things To Do
/////////////////////////////////////////////////////////////////////////////
- Terrain ���� �浹 ȸ�ǰ� ���������� ����.
	Ogre::TerrainGroip ���� terrain ��� ����� ����ġ ����. LoD ����� �������� ���� ����.
	Terrain�� �� ���� .mesh �� ���� �����̹Ƿ� Ogre::Terrain�� ����� �� ����.
	�� (�� ����) .mesh ������ ��ġ ���� ��� �׽�Ʈ�� �ʿ���.
- Big Terrain ������ ����. ��Ȯ�ϰ� col ������ �÷� �� ���� ����.
- DDS ���� �� �޽����� ������ ���õ�(animation, message queue, etc) ����.
- Camera Control System�� ���� �н� �� ����
- SkyX�� ���� �н� �� ����
	��, ��, �帲, ������ ���� ���� ���� �Ϸ�.
- �������� architecture ����
- ��Ʈ�� ��� ����. createScene() ���� ��� ������Ʈ ���� �� ��Ʈ�� ��� ������ �����ʿ�.
- Ocean�� collision

/////////////////////////////////////////////////////////////////////////////
// History
/////////////////////////////////////////////////////////////////////////////
[20141225]
	- VisualX.dll & VisualX.exe �׽�Ʈ ���� �Ϸ��Ͽ� ����. EOTS�� ����ϱ⿡ 
		�������� ����.
[20141226]
	- OgreWizard�� �����ϴ� �����ִ� BaseApplicaiton.cpp & .h �� 1.9 ������ �°�
		�����ǵ��� OgreWizard ����
	- Sound ���� ����� �������� �׽�Ʈ. ������ �������� ���� �ڵ��� �����
		���� ����� ������. SoundTuturial.cpp keyPressed �Լ� ����.
[20141228]
	- Plane.d �� ����. + �� ���� �Ʒ���, -�� ���� ����.
	- 1,000,000 * 1,000,000 ũ���� plane ������ �ĵ� Ư�� ȿ���� ���� ������ Ȯ����.
	- bullet trajectory �׽�Ʈ ��. ������ ���� �����ϴ� ������ ������ �Ǿ�� �ϴ� ��
		DynamicLines Ŭ������ ������ ���� ������. http://code.google.com/p/ovise/source/browse/TrajectoryPlugin/Trajectory.h?name=v0-5 �� 
		�����Ͽ� �߰� Ȯ���� �ʿ���. ovise ���ٴ� DynamicLines�� �ϵ���� ���۸� ���� ����ϹǷ� ���� ����.
[20150103]
	- DynamicLines class�� Ȱ���Ͽ� ������ ��ȹ��� drawing ���� Ȯ����.
		���Ŀ��� ���� ����� ���ϰ� �����ϴ� �۾��� �䱸��. ���� �۾� �Ϸ�.
	- ȸ��� ��Ʈ�� ������ resource mismatching ���� ����.
		sound, font, axes.mesh � ���� ���ҽ��� ���Ϸ� ���� ��.