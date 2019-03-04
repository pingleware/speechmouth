# Microsoft Developer Studio Project File - Name="SpeakMouth" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SpeakMouth - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SpeakMouth.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SpeakMouth.mak" CFG="SpeakMouth - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SpeakMouth - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SpeakMouth - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SpeakMouth - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "SpeakMouth - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "D:\Program Files\Microsoft Speech SDK 5.1\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ   /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 sapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"D:\Program Files\Microsoft Speech SDK 5.1\Lib\i386"

!ENDIF 

# Begin Target

# Name "SpeakMouth - Win32 Release"
# Name "SpeakMouth - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\SpeakMouth.cpp
# End Source File
# Begin Source File

SOURCE=.\SpeakMouth.rc
# End Source File
# Begin Source File

SOURCE=.\SpeakMouthDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SpeakMouth.h
# End Source File
# Begin Source File

SOURCE=.\SpeakMouthDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\mic eyes closed.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\mic.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_eyes_narrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_11.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_13.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mic_mouth_9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\SpeakMouth.ico
# End Source File
# Begin Source File

SOURCE=.\res\SpeakMouth.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
