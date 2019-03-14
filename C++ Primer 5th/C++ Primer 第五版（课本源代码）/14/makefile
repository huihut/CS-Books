# executable files for this directory
OBJECTS = absInt.exe add.exe calc.exe directcall.exe \
		  fcnobj.exe newcount-size.exe readStr.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\1 -I..\6

add.obj directcall.obj Sales_data.obj: Sales_data.h

add.exe: add.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) add.obj Sales_data.obj 

directcall.exe: directcall.obj Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) directcall.obj Sales_data.obj 
