echo on 
compareDef.exe < data/book_sales
multiset.exe < data/book_trans
Vecmain.exe < data/Vecmain

for %%i in ( Array.exe array-parms4.exe 
		   compare.exe compareSpec.exe 
		   debug.exe flip.exe
		   overloaded.exe overSpec.exe qm.exe 
		   SP.exe special.exe specialized.exe 
		   trail-ret.exe useBlob.exe useChcking.exe ) do %%i

