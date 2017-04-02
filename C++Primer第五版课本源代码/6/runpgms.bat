echo on
mainmath < data/mainmath
refparms < data/refparms

for %%i in ( arrRet.exe count-calls.exe 
		   errMsg_initList.exe fact.exe fcnptrRet.exe 
		   good_printmain.exe inline_shorter.exe 
		   mainret.exe mk_plural.exe 
		   ref-fcn.exe refret-ex.exe  reset.exe 
		   stl-arr-fcns.exe usefcnptr.exe wdebug.exe ) do %%i
