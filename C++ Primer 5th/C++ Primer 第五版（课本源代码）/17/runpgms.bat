echo on
badgetc.exe < data/skipws
bits.exe < data/bits
ccpgms.exe < data/files
findbook.exe data/store*
game.exe < data/game
getc.exe < data/skipws
getput.exe < data/skipws
no-skipws.exe < data/no-skipws
phones.exe < data/phones
phonesFinal.exe < data/phonesFinal
skipws.exe < data/skipws
subexpr.exe < data/files
validatePhones.exe < data/validatePhones

for %%i in ( manips.exe normalInts.exe point.exe 
		   prec.exe rand1.exe rand2.exe rand4.exe 
		   rand6.exe regex1.exe REerrs.exe 
		   seed.exe seek.exe setw.exe tuple.exe zips.exe ) do %%i
