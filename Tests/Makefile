CC = g++
CC_LINK = g++
COMPILER_FLAGS = -pedantic -Wall -std=gnu++11 -D MogeLib_EXPORT="1" -Wno-ignored-attributes
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
PROJECT_NAME = Tests
BINARY_NAME = $(PROJECT_NAME).exe 
OUTPUT_DIR_DEBUG = ../Build/$(OS)_DEBUG
OUTPUT_DIR_RELEASE = ../Build/$(OS)_RELEASE
HEADER_INC = -I ../MogeLib/inc/ -I inc/ -I ../String/inc/ -I ../MogeMath/inc/ -I $(HOME_GTEST_CYGWIN)/googletest/include/
IMPORT_LIBS_DEBUG = $(OUTPUT_DIR_DEBUG)/MogeLib.a $(OUTPUT_DIR_DEBUG)/String.a $(HOME_SDL2_CYGWIN)/lib/libSDL2.dll.a $(HOME_GTEST_CYGWIN)/googletest/make/gtest_main.a 
IMPORT_LIBS_RELEASE = $(OUTPUT_DIR_RELEASE)/MogeLib.a $(OUTPUT_DIR_RELEASE)/String.a $(HOME_SDL2_CYGWIN)/lib/libSDL2.dll.a $(HOME_GTEST_CYGWIN/)googletest/make/gtest_main.a
OUTPUT_DEBUG = $(OUTPUT_DIR_DEBUG)/$(BINARY_NAME)
OUTPUT_RELEASE = $(OUTPUT_DIR_RELEASE)/$(BINARY_NAME)

CPP_FILES := $(wildcard */*.cpp)
CPP_FILES += main.cpp

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: $(OUTPUT_DEBUG)
release: $(OUTPUT_RELEASE)

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
	find . -name '*.o' | xargs rm

test:
	@echo "All .o files: $(OBJ_DEBUG_FILES)"
	@echo "All .cpp files: $(CPP_FILES)" 
	@echo "SDL2: $(HOME_SDL2_CYGWIN)/"

help:
	echo "If run first time, please run \"make first_run\" it will create necessary dirs."
