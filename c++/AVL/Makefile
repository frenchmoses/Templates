#Austin Frenchmoses
#CS302 Progam 3 Makefile

CC=g++ -std=c++2a -g -Wall -o
EXE=program
FILES=Main.cpp
HEADERS=AVL.h bstNode.h
TPP=AVL.tpp bstNode.tpp

PROG:
	$ clear
	$(CC) $(EXE) $(FILES)

clean:
	$ clear
	$ rm -f $(EXE) *.o ~*
	
run:
	$ ./$(EXE)

memCheck:
	$ clear
	$ valgrind --track-origins=yes --tool=memcheck --leak-check=full ./$(EXE)

edit:
	vim -p $(HEADERS) $(TPP) $(FILES)

gdb:
	$ clear
	$ gdb $(EXE)


