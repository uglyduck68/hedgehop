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
- Terrain 에서 충돌 회의가 정상적이지 않음.
	Ogre::TerrainGroip 등의 terrain 기능 사용이 용이치 않음. LoD 기능이 생각보다 좋지 않음.
	Terrain을 몇 개의 .mesh 로 받을 예정이므로 Ogre::Terrain을 사용할 수 없음.
	이 (몇 개의) .mesh 파일의 위치 설정 기능 테스트가 필요함.
- Big Terrain 렌더링 문제. 정확하게 col 지역을 올려 본 적이 없음.
- DDS 수신 후 메시지와 렌더링 관련된(animation, message queue, etc) 구현.
- Camera Control System에 대한 학습 및 적용
- SkyX에 대한 학습 및 적용
	낮, 밤, 흐림, 맑음에 대한 설정 대충 완료.
- 전반적인 architecture 수립
- 인트로 기능 변경. createScene() 에서 모든 오브젝트 만든 후 인트로 들어 가도록 수정필요.
- Ocean의 collision

/////////////////////////////////////////////////////////////////////////////
// History
/////////////////////////////////////////////////////////////////////////////
[20141225]
	- VisualX.dll & VisualX.exe 테스트 버전 완료하여 보냄. EOTS에 사용하기에 
		적당하지 않음.
[20141226]
	- OgreWizard가 생성하는 오류있던 BaseApplicaiton.cpp & .h 를 1.9 버전에 맞게
		생성되도록 OgreWizard 수정
	- Sound 연속 재생이 가능한지 테스트. 동일한 음원으로 사운드 핸들을 만들면
		연속 재생이 가능함. SoundTuturial.cpp keyPressed 함수 참조.
[20141228]
	- Plane.d 값 정의. + 는 원점 아래로, -는 원점 위로.
	- 1,000,000 * 1,000,000 크기의 plane 에서는 파도 특수 효과가 먹지 않음을 확인함.
	- bullet trajectory 테스트 중. 궤적이 점차 증가하는 순으로 구동이 되어야 하는 데
		DynamicLines 클래스는 기존과 거의 동일함. http://code.google.com/p/ovise/source/browse/TrajectoryPlugin/Trajectory.h?name=v0-5 를 
		참조하여 추가 확인이 필요함. ovise 보다는 DynamicLines가 하드웨어 버퍼를 직접 사용하므로 좋아 보임.
[20150103]
	- DynamicLines class를 활용하여 궤적이 계획대로 drawing 됨을 확인함.
		추후에는 좀더 사용이 편리하게 개선하는 작업이 요구됨. 개선 작업 완료.
	- 회사와 노트북 사이의 resource mismatching 현상 제거.
		sound, font, axes.mesh 등에 대한 리소스를 메일로 전달 함.