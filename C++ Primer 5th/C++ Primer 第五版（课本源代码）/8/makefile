# executable files for this directory
OBJECTS = buf.exe clearIO.exe fileIO.exe add_item.exe \
		  add_itemV2.exe sstream.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\7

add_itemV2.exe: add_itemV2.obj ..\7\Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) add_itemV2.obj ..\7\Sales_data.obj 

add_item.exe: add_item.obj ..\7\Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) add_item.obj ..\7\Sales_data.obj 
 
