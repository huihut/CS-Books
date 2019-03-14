echo on 
cond < data/vecSubs

for %%i in (arith-ex.exe arraysizeof.exe 
		   incr.exe int-div.exe oofe.exe overflow.exe 
		   prec.exe shift-prec.exe sizeof_pgm.exe 
		   unaryOps.exe vec_init.exe warn_dbltoint.exe ) do %%i
