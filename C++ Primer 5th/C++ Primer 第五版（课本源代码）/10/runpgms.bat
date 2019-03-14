echo on
absInt.exe < data/absInt
accum.exe < data/accum
accum4.exe < data/iostream_iter
avg_price.exe < data/book_sales
bind2.exe < data/count-size
elimDups < data/count-size
equiv-istream-iter.exe < data/iostream_iter
iostream_iter.exe < data/iostream_iter
newcount-size.exe < data/count-size
ostreamIter2.exe < data/iostream_iter
rcomma.exe < data/rcomma
reverse-iter.exe < data/reverse-iter
sortSI.exe < data/book_sales
use_find.exe < data/use_find
use-istream-iter.exe < data/iostream_iter

for %%i in ( equal.exe inserters.exe reverse.exe 
		   rev-iters.exe ) do %%i 

REM C++ 11 file:
REM lambda.exe
