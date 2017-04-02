echo on
add_item < data/add_item
add_itemV2 < data/add_item
fileIO data/add_item data/sstream
sstream < data/sstream

for %%i in (  buf.exe clearIO.exe ) do %%i
