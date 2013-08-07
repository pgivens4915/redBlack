redBlack : redBlack.o tree.o
	gcc redBlack.o tree.o -o redBlack
redBlack.o : redBlack.c
	gcc -c redBlack.c -o redBlack.o
tree.o : tree.c tree.h
	gcc -c tree.c -o tree.o
clean :
	rm redBlack
