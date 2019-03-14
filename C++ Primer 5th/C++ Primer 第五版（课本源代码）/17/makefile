# executable files for this directory
OBJECTS =  badgetc.exe bits.exe findbook.exe \
		  game.exe getc.exe getput.exe manips.exe \
		  normalInts.exe no-skipws.exe point.exe \
		  prec.exe rand1.exe rand2.exe rand4.exe \
		  rand6.exe seed.exe seek.exe setw.exe \
		  skipws.exe tuple.exe  phones.exe \
		  ccpgms.exe validatePhones.exe \
		  phonesFinal.exe subexpr.exe \
		  regex1.exe zips.exe REerrs.exe 

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = /I..\14

findbook.obj: ..\14\Sales_data.h

findbook.exe: findbook.obj ..\14\Sales_data.obj
	$(CPP) $(CPPFLAGS) findbook.obj ..\14\Sales_data.obj


