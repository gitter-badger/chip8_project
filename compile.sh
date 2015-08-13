# OPTIONS may be = DEBUG or RELEASE


#RELEASE must set optmizations for fast code and  link the RELEASE object-files.

#DEBUG must set debug information and disable optimizations, also link the DEBUG object-files.

# All .cc/.c/.cxx/.cpp... files in src folder must be passed for compiler and linked together, except for the subfolder that must be already in object-files directory 


OPTION=DEBUG

CC=g++ -std=c++14

FLAGS=-Wall -Wextra -Winline

INCLUDEPATH=-I./include-object-files/headers

ifeq ($(OPTION),RELEASE)

OBJECTFILES=./include-object-files/object-files-release/*.o

else ifeq($(OPTION),DEBUG)
	
OBJECTFILES=./include-object-files/object-files-debug/*.o

endif


FILES=./src/*.cc

OUT=-o./OUT/Chip8-interpreter

LINKS=-lSDL2






all:$
	$(CC)	$(FLAGS) 	$(INCLUDEPATH) 	$(OBJECTFILES) 	$(FILES)  $(LINKS) $(OUT)
