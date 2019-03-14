# executable files for this directory
OBJECTS = arrRet.exe count-calls.exe errMsg_initList.exe \
		  fact.exe fcnptrRet.exe good_printmain.exe \
		  inline_shorter.exe mainmath.exe mainret.exe \
		  mk_plural.exe ref-fcn.exe refparms.exe refret-ex.exe  \
		  reset.exe stl-arr-fcns.exe usefcnptr.exe wdebug.exe

# tells make to use the file "..\MS_makefile_template", which
# defines general rules for making .obj and .exe files
include ..\MS_makefile_template

LOCFLAGS = 

fact.obj mainmath.obj LocalMath.obj: LocalMath.h

fact.exe: fact.obj LocalMath.obj
	$(CPP) $(CPPFLAGS) fact.obj LocalMath.obj 

mainmath.exe: mainmath.obj LocalMath.obj 
	$(CPP) $(CPPFLAGS) mainmath.obj LocalMath.obj 

