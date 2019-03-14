echo on 
wcEx.exe < data/storyDataFile
erasemap.exe < data/storyDataFile
restricted_count.exe < data/word_count
unorderedWordCount.exe < data/word_count
word_count.exe < data/storyDataFile
pair.exe < data/storyDataFile
word_transform.exe data/rules data/text

for %%i in ( map1.exe multimap.exe setOps.exe ) do %%i
