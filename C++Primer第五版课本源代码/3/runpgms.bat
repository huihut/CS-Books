echo on
add_using < data/add
arrayScores < data/grades
hexify < data/hexify
ptr_traversal2 < data/ptr_traversal2
string_io < data/string_io
string_io2 < data/string_io
vecStrings2 < data/vecStrings2
vecScores < data/grades
getline < data/word_echo
string_size2 < data/word_echo
string_size3 < data/word_echo
word_echo < data/word_echo

for %%i in (cctype.exe char_repl.exe cstring_hdr.exe 
		   multidim.exe square.exe strcompare.exe 
		   string_add.exe string_size.exe vec_decls.exe 
		   vecSubs.exe) do %%i
