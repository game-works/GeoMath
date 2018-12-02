PROJECT_NAME := MathProject
BIN_DIR := bin
SRC_DIR := src

CONFIG := Debug

LIB_IMGUI := include/imgui
LIB_IMGUI_SFML := include/imgui-sfml

SOURCES := $(wildcard ${SRC_DIR}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI_SFML}/*.cpp)
SOURCES := $(filter-out ${LIB_IMGUI}/imgui_demo.cpp, ${SOURCES})

INCLUDES := -I${LIB_IMGUI} -I${LIB_IMGUI_SFML}
LINKS := -lGL -lsfml-graphics -lsfml-window -lsfml-system

CC ?= clang
CXX ?= clang++
CXXFLAGS := ${CXXFLAGS} -pedantic -D _$(shell echo ${CONFIG} | tr a-z A-Z)

test:
	./${BIN_DIR}/${PROJECT_NAME}-${CONFIG}

compile:
	${CXX} ${CXXFLAGS} -o ${BIN_DIR}/${PROJECT_NAME}-${CONFIG} ${SOURCES} ${INCLUDES} ${LINKS}

clean:
	rm -rf ${BIN_DIR}
	rm -rf ${OBJ_DIR}
	mkdir ${BIN_DIR}
	mkdir ${OBJ_DIR}
