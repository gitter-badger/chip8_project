# OPTIONS may be = DEBUG, RELEASE, or TEST


#DEBUG and RELEASE must output object files for link with the final application's executable

#TEST must output an executable for debuggin n testing, optimizations must be set if needed


#RELEASE must set optmizations for fast code.

#DEBUG must set debug information and no optimizations at all.



OPTION=DEBUG


CC= g++ -std=c++14 -Wall -Wextra -Winline 

INCLUDE= -I./SysDisplay

#LINK and OUT are used if OPTION == TEST
LINK=
OUT=

ifeq ($(OPTION),RELEASE)

FLAGS= -Ofast -c

FILES= chip8display.cc




else ifeq ($(OPTION),DEBUG)
FLAGS=-g -O0 -c

FILES=chip8display.cc




else ifeq ($(OPTION),TEST)

FLAGS=-g -O0

FILES=TEST_chip8display.cc

LINK=-lSDL2

OUT=-oTEST_display


endif


FILES_2=./SysDisplay/sysdisplay.cc



all:
	$(CC) $(FLAGS) $(FILES) $(FILES_2) $(INCLUDE) $(LINK) $(OUT)
