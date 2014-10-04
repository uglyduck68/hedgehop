@echo off
rmdir /s /q 3ds2mesh
if not exist 3ds2mesh mkdir 3ds2mesh

devenv /build Release 3ds2mesh.sln

copy README.txt 3ds2mesh
copy bin\release\3ds2mesh.exe 3ds2mesh

copy %OGRE_SRC%\samples\common\bin\release\OgreMain.dll 3ds2mesh
copy %OGRE_SRC%\samples\common\bin\release\zlib1.dll 3ds2mesh
copy %OGRE_SRC%\samples\common\bin\release\DevIL.dll 3ds2mesh
copy %OGRE_SRC%\samples\common\bin\release\ILU.dll 3ds2mesh


copy %SYSTEMROOT%\system32\msvcp71.dll 3ds2mesh
copy %SYSTEMROOT%\system32\msvcr71.dll 3ds2mesh



