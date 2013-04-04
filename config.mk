CPPC=g++
DIST=dist

CPP2DGAMEENGINE_LIBNAME:=cpp2dgameengine
CPP_FLAGS:=-std=c++0x -Werror -Wall

ifdef DEBUG
    CPP_FLAGS+= -g
    CPP2DGAMEENGINE_LIBNAME:=$(CPP2DGAMEENGINE_LIBNAME)_debug
endif
ifeq ($(32BIT), 1)
CPP_FLAGS+= -m32
else
    32BIT=0
endif

ALLEGRO_LIBS=allegro-5.0 allegro_primitives-5.0
INC_DIRS:=.
LIB_DIRS:=Cpp2DGameEngine/dist
LIB_NAMES:=$(CPP2DGAMEENGINE_LIBNAME)

MAIN=Application/src/main.cpp
SRCS:=$(MAIN)
BIN=seekingmissile
MODULES=
