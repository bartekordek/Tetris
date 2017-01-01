CC = g++
OBJ_DIR_NAME = obj
LIB_STATIC_CC = ar rcs
COMPILER_FLAGS = -pedantic -Wall -std=c++11 -D MogeLib_EXPORT=""
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
BINARY_NAME = String.a
HEADER_INC = -I inc/
OUTPUT_DEBUG = ../Build/$(OS)_DEBUG/$(BINARY_NAME)
OUTPUT_RELEASE = ../Build/$(OS)_RELEASE/$(BINARY_NAME)

CPP_FILES := $(wildcard */*.cpp)

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: $(OUTPUT_DEBUG)
release: $(OUTPUT_RELEASE)

$(OUTPUT_DEBUG): $(OBJ_DEBUG_FILES)
	$(LIB_STATIC_CC) $(OUTPUT_DEBUG) -o $(OBJ_DEBUG_FILES)

$(OUTPUT_RELEASE): $(OBJ_RELEASE_FILES) 
	$(LIB_STATIC_CC) $(OUTPUT_RELEASE) -o $(OBJ_RELEASE_FILES) 

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

test:
	@echo "All .o files: $(OBJ_DEBUG_FILES)"
	@echo "All .cpp files: $(CPP_FILES)" 

help:
	echo "If run first time, please run \"make first_run\" it will create necessary dirs."
