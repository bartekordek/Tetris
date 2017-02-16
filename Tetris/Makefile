CC = g++
CC_LINK = g++
COMPILER_FLAGS = -pedantic -Wall -std=c++11 -D MogeLib_EXPORT="1" -Wno-ignored-attributes
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
PROJECT_NAME = Tetris
BINARY_NAME = $(PROJECT_NAME).exe 
OUTPUT_DIR_DEBUG = ../Build/$(OS)_DEBUG
OUTPUT_DIR_RELEASE = ../Build/$(OS)_RELEASE
HEADER_INC = -I ../MogeLib/inc/ -I inc/ -I ../MogeMath/inc/ -I $(HOME_SDL2_CYGWIN)/include/SDL2/
IMPORT_LIBS_DEBUG = $(OUTPUT_DIR_DEBUG)/MogeLib.a $(HOME_SDL2_CYGWIN)/lib/libSDL2.dll.a 
IMPORT_LIBS_RELEASE = $(OUTPUT_DIR_RELEASE)/MogeLib.a $(HOME_SDL2_CYGWIN)/lib/libSDL2.dll.a 
OUTPUT_DEBUG = $(OUTPUT_DIR_DEBUG)/$(BINARY_NAME)
OUTPUT_RELEASE = $(OUTPUT_DIR_RELEASE)/$(BINARY_NAME)

CPP_FILES := $(wildcard */*.cpp)
CPP_FILES += main.cpp

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: run_debug_deps $(OUTPUT_DEBUG)
release: run_release_deps $(OUTPUT_RELEASE)

run_debug:
	make debug
	cd $(OUTPUT_DIR_DEBUG);./$(BINARY_NAME)

run_release:
	make release
	cd $(OUTPUT_DIR_RELEASE);./$(BINARY_NAME)

$(OUTPUT_DEBUG): $(OBJ_DEBUG_FILES)
	$(CC_LINK) -o $(OUTPUT_DEBUG) $(OBJ_DEBUG_FILES) $(IMPORT_LIBS_DEBUG)
	cp $(HOME_SDL2_CYGWIN)/bin/*.dll $(dir $(OUTPUT_DEBUG))

$(OUTPUT_RELEASE): $(OBJ_RELEASE_FILES)
	$(CC_LINK) -o $(OUTPUT_RELEASE) $(OBJ_RELEASE_FILES) $(IMPORT_LIBS_RELEASE) 
	cp $(HOME_SDL2_CYGWIN)/bin/*.dll $(dir $(OUTPUT_RELEASE))

$(OBJ_DEBUG_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(DEBUG_FLAGS) -c -o $@ $<

$(OBJ_RELEASE_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(RELEASE_FLAGS) -c -o $@ $<

run_debug_deps:
	make -C ../MogeLib debug

run_release_deps:
	make -C ../MogeLib release

first_run:
	mkdir -p $(dir $(OBJ_DEBUG_FILES)) 
	mkdir -p $(dir $(OUTPUT_DEBUG))
	mkdir -p $(dir $(OBJ_RELEASE_FILES)) 
	mkdir -p $(dir $(OUTPUT_RELEASE))

clear:
	rm -f $(OBJ_DEBUG_FILES)
	rm -f $(OBJ_RELEASE_FILES)
	rm -f $(OUTPUT_DEBUG)
	rm -f $(OUTPUT_RELEASE)

clear_all:
	make clear
	find . -name '*.o' | xargs rm

test:
	@echo "All .o files: $(OBJ_DEBUG_FILES)"
	@echo "All .cpp files: $(CPP_FILES)" 
	@echo "SDL2: $(HOME_SDL2_CYGWIN)/"

help:
	echo "If run first time, please run \"make first_run\" it will create necessary dirs."
