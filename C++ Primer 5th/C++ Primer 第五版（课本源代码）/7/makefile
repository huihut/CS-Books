# executable files for this directory
OBJECTS = add_item.exe avg_price.exe \
		  useAccount.exe useScreen.exe 

# the corresponding source file uses c++ 11 features
C11_OBJECTS = useDebug.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\1

useScreen.exe: Screen.h

Account.obj useAccount.obj: Account.h
Debug.obj useDebug.obj: Debug.h

useAccount.exe: Account.obj useAccount.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) useAccount.obj Account.obj 

useDebug.exe: Debug.obj useDebug.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) useDebug.obj Debug.obj 

add_item.exe: add_item.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) add_item.obj Sales_data.obj \

avg_price.exe: avg_price.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) avg_price.obj Sales_data.obj \
 
