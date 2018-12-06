PROJECT_NAME := MathProject
BIN_DIR := bin
SRC_DIR := src
INCLUDE_DIR := include

PLATFORM := Linux
ARCHITECTURE := x86 #32-bit, 64-bit = x86_64
CONFIG := Debug

LIB_IMGUI := ${INCLUDE_DIR}/imgui
LIB_IMGUI_SFML := ${INCLUDE_DIR}/imgui-sfml

SOURCES := $(wildcard ${SRC_DIR}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI_SFML}/*.cpp)

SOURCES := $(filter-out ${LIB_IMGUI}/imgui_demo.cpp, ${SOURCES})

OBJECTS :=

INCLUDES := -I${LIB_IMGUI} -I${LIB_IMGUI_SFML} -I${LIB_TINYEXPR}
LINKS := -lGL -lsfml-graphics -lsfml-window -lsfml-system

CC ?= clang
CXX ?= clang++
CXXFLAGS := ${CXXFLAGS} -pedantic -D _$(shell echo ${CONFIG} | tr a-z A-Z)

ifeq ($(PLATFORM), Windows)
INCLUDES += -Iinclude/SFML/include
LINKS := -Linclude/SFML/lib
LINKS += -lopengl32 -lsfml-graphics -lsfml-window -lsfml-system

ifeq ($(ARCHITECTURE), x86_64)
CC = x86_64-w64-mingw32-gcc
CXX = x86_64-w64-mingw32-g++
else
CC = i686-w64-mingw32-gcc
CXX = i686-w64-mingw32-g++
endif

CXXFLAGS := ${CXXFLAGS} -Wall
endif

test:
	./${BIN_DIR}/${PLATFORM}/${PROJECT_NAME}-${CONFIG}-${ARCHITECTURE}

compile:
	${CXX} ${CXXFLAGS} -o ${BIN_DIR}/${PLATFORM}/${PROJECT_NAME}-${CONFIG}-${ARCHITECTURE} ${SOURCES} ${OBJECTS} ${INCLUDES} ${LINKS}

clean:
	rm -rf ${BIN_DIR}
	mkdir ${BIN_DIR}
	mkdir ${BIN_DIR}/Linux
	mkdir ${BIN_DIR}/Windows
