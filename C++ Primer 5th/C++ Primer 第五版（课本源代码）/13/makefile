# executable files for this directory
OBJECTS = FolderMain.exe HasPtrUseCount.exe \
		  HasPtrValueLike.exe \
		  moveHP.exe serial.exe StrFolderMain.exe \
		  useStrVec.exe substr.exe 

# the corresponding source file uses c++ 11 features
C11_OBJECTS = copyNoMove.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\1 -I..\7

Folder.obj FolderMain.obj: Folder.h
StrFolder.obj StrFolderMain.obj: StrFolder.h String.h
String.obj: String.h
useStrVec.obj StrVec.obj: String.h StrVec.h

useStrVec.exe: StrVec.obj useStrVec.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) useStrVec.obj StrVec.obj

FolderMain.exe: Folder.obj FolderMain.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) FolderMain.obj Folder.obj

StrFolderMain.exe: StrFolder.obj StrFolderMain.obj String.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) StrFolderMain.obj StrFolder.obj String.obj 

