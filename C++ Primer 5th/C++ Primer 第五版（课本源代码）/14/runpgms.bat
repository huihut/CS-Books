echo on
absInt.exe < data/absInt
add.exe < data/add_item
fcnobj.exe < data/count-size
directcall.exe < data/add_item
newcount-size.exe < data/count-size
readStr.exe < data/word_echo

for %%i in ( calc.exe ) do %%i

