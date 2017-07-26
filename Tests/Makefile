CC = g++
CC_LINK = g++
COMPILER_FLAGS = -pedantic -Wall -std=gnu++11 -D MogeLib_EXPORT="1" -Wno-ignored-attributes
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
PROJECT_NAME = Tests
LINUX_BUILD_PREF=$(HOME_GTEST_LINUX)/Build-Linux/googlemock/gtest
BINARY_NAME = $(PROJECT_NAME).exe 
OUTPUT_DIR_DEBUG = ../Build/Debug
OUTPUT_DIR_RELEASE = ../Build/Release
HEADER_INC = -I ../MogeLib/inc/ -I inc/ -I $(HOME_GTEST_LINUX)/googletest/include/
IMPORT_LIBS_DEBUG = -L$(OUTPUT_DIR_DEBUG) -L$(LINUX_BUILD_PREF)
IMPORT_LIBS_RELEASE = -L$(OUTPUT_DIR_RELEASE) -L$(LINUX_BUILD_PREF)
IMPORT_LIBS_FILES=-lmoge -lgtest -lgtest_main
OUTPUT_DEBUG = $(OUTPUT_DIR_DEBUG)/$(BINARY_NAME)
OUTPUT_RELEASE = $(OUTPUT_DIR_RELEASE)/$(BINARY_NAME)
LINUX_BIN_SUBPATH=build/.libs

CPP_FILES := $(wildcard */*.cpp)
CPP_FILES += main.cpp

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: run_debug_deps $(OUTPUT_DEBUG)

release: run_release_deps $(OUTPUT_RELEASE)

run_debug: debug
	cd $(OUTPUT_DIR_DEBUG);./$(BINARY_NAME)

run_release: release
	cd $(OUTPUT_DIR_RELEASE);./$(BINARY_NAME)

$(OUTPUT_DEBUG): $(OBJ_DEBUG_FILES)
	$(CC_LINK) -o $(OUTPUT_DEBUG) $(OBJ_DEBUG_FILES) $(IMPORT_LIBS_DEBUG) $(IMPORT_LIBS_FILES)

$(OUTPUT_RELEASE): $(OBJ_RELEASE_FILES)
	$(CC_LINK) -o $(OUTPUT_RELEASE) $(OBJ_RELEASE_FILES) $(IMPORT_LIBS_RELEASE) $(IMPORT_LIBS_FILES)

$(OBJ_DEBUG_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(DEBUG_FLAGS) -c -o $@ $<

$(OBJ_RELEASE_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(RELEASE_FLAGS) -c -o $@ $<

first_run:
	mkdir -p $(dir $(OBJ_DEBUG_FILES)) 
	mkdir -p $(dir $(OUTPUT_DEBUG))
	mkdir -p $(dir $(OBJ_RELEASE_FILES)) 
	mkdir -p $(dir $(OUTPUT_RELEASE))
ifeq ($(OS),Windows_NT)
	find /usr -name 'SDL2.dll' | xargs -i cp {} -fv $(OUTPUT_DIR_DEBUG)
	find /usr -name 'SDL2.dll' | xargs -i cp {} -fv $(OUTPUT_DIR_RELEASE)
endif

clean:
	rm -f $(OBJ_DEBUG_FILES)
	rm -f $(OBJ_RELEASE_FILES)
	rm -f $(OUTPUT_DEBUG)
	rm -f $(OUTPUT_RELEASE)

run_debug_deps:
	make -C ../MogeLib debug

run_release_deps:
	make -C ../MogeLib release

clear_all:
	find . -name '*.o' | xargs rm

test:
	@echo "All .o files: $(OBJ_DEBUG_FILES)"
	@echo "All .cpp files: $(CPP_FILES)" 
	@echo "SDL2: $(HOME_SDL2_LINUX)/"

help:
	echo "If run first time, please run \"make first_run\" it will create necessary dirs."
