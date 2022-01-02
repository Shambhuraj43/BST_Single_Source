run: output	
	./output

output: bst1source.o
	g++ -g bst1source.o -o output
bst1source.o: bst1source.cpp
	g++ -c bst1source.cpp

clean: 
	rm *.o
	rm output
	rm *.txt
