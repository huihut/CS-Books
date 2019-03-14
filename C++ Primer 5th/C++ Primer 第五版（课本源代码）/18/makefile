# executable files for this directory
OBJECTS = Animal.exe book.exe class.exe \
		  ex-over.exe inherit.exe mi-scope.exe\
		  over.exe over2.exe \
		  usingDirective.exe virt-inherit.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\14

Animal.obj: Animal.h
book.obj: ..\14\Sales_data.h bookexcept.h
virt-inherit.obj: Animal_virtual_baseVers.h

book.exe: book.obj bookexcept.h ..\14\Sales_data.obj
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) book.obj ..\14\Sales_data.obj 
