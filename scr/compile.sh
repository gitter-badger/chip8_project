
CC=g++ -std=c++14

FLAGS=-Wall -Wextra -Winline

INCLUDEPATH=-I./include


OBJECTFILES=./object\ files/*.o

FILES=main.cc


LINK=-lSDL2






all:$
	$(CC)	$(FLAGS) 	$(INCLUDEPATH) 	$(OBJECTFILES) 	$(FILES) 	$(LINK)
