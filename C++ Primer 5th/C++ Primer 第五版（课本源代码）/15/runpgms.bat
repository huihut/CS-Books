echo on
andQueryTest.exe data/storyDataFile < data/two
and_orQueryTest.exe data/storyDataFile < data/three
wordQueryTest.exe data/storyDataFile < data/querymain

for %%i in ( Basket_main.exe sample.exe 
		   scope.exe  useQuote.exe vecBasket.exe 
		   virtualsNscope.exe ) do %%i
