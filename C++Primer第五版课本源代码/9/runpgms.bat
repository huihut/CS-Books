echo on
erase1 <data\erase

for %%i in (  capacity.exe erase2.exe find_ops.exe
			  find-str.exe refreshIter.exe stack.exe 
			  str_assignOps.exe substr.exe useConvs.exe ) do %%i
