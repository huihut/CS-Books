# executable files for this directory
OBJECTS = erasemap.exe map1.exe \
		  multimap.exe pair.exe \
		  restricted_count.exe setOps.exe \
		  unorderedWordCount.exe \
		  wcEx.exe word_count.exe word_transform.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

# directory 7 has Sales_data code, 6 has make_plural function
LOCFLAGS = /I..\7 -I..\6

map1.exe: map1.obj ..\7\Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) map1.obj ..\7\Sales_data.obj 

