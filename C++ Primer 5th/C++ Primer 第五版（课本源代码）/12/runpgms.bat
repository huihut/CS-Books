echo on
querymain.exe data/storyDataFile < data/Alice
allocPtr.exe < data/alloc
allocSP.exe < data/alloc
usealloc.exe < data/storyDataFile

for %%i in ( oknew.exe 
		   unique.exe UP.exe usealloc2.exe useBlob.exe weak.exe ) do %%i

REM c++ 11 files:
REM release.exe 
