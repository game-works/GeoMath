PROJECT_NAME := GeoMath
VERSION := 0.1.3
TYPE := Dynamic
PLATFORM := Linux#Windows
ARCHITECTURE := x86# x86_64
CONFIG := Debug#Release
CXXFLAGS := ${CXXFLAGS} -std=c++11 -Wall -W -pedantic
CXXFLAGS += -D_$(shell echo ${CONFIG} | tr a-z A-Z) -DVERSION=${VERSION}
SRC_DIR := src
INCLUDE_DIR := include

OBJ_DIR := bin
NAME := ${OBJ_DIR}/${PLATFORM}-${TYPE}
BUILD_DIR := build/${PLATFORM}-${TYPE}

LIB_IMGUI := ${INCLUDE_DIR}/imgui
LIB_IMGUI_SFML := ${INCLUDE_DIR}/imgui-sfml

SOURCES := $(wildcard ${SRC_DIR}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI}/*.cpp)
SOURCES += $(wildcard ${LIB_IMGUI_SFML}/*.cpp)
SOURCES := $(filter-out ${LIB_IMGUI}/imgui_demo.cpp, ${SOURCES})

OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
INCLUDES := -I${LIB_IMGUI} -I${LIB_IMGUI_SFML}

ifeq ($(TYPE), Static)
  CXXFLAGS += -DSFML_STATIC
  LDDFLAGS := -Linclude/SFML/lib-clang
  LDDFLAGS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
  LDDFLAGS += -lX11 -lXrandr -lpthread -lopenal -ludev -lfreetype -lGL -lvorbisenc -lvorbisfile -lvorbis -logg -lFLAC
else
  LDDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
  LDDFLAGS += -lGL
endif

ifeq ($(PLATFORM), Windows)
  ifeq ($(ARCHITECTURE), x86_64)
    CC = x86_64-w64-mingw32-gcc
    CXX = x86_64-w64-mingw32-g++
  else
    CC = i686-w64-mingw32-gcc
    CXX = i686-w64-mingw32-g++
  endif
  INCLUDES += -Iinclude/SFML/include
  LINKS := -Linclude/SFML/lib
  LDDFLAGS += -lopengl32
  LINKS += ${LDDFLAGS}
else
  CC ?= clang
  CXX ?= clang++
  LINKS := ${LDDFLAGS}
endif

EXECUTABLE := ${PROJECT_NAME}-${CONFIG}-${TYPE}-${ARCHITECTURE}

${EXECUTABLE}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -o ${BUILD_DIR}/$@ $^ ${INCLUDES} ${LINKS}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $< ${INCLUDES}

test:
	./${BUILD_DIR}/${EXECUTABLE}

compile:
	${CXX} ${CXXFLAGS} -o ${BUILD_DIR}/${EXECUTABLE} ${SOURCES} ${INCLUDES} ${LINKS}

package-windows:
	make CONFIG=Release PLATFORM=Windows
	cd ${BUILD_DIR}/ && zip -9r GeoMath-${PLATFORM}-${TYPE}-${CONFIG}.zip .
