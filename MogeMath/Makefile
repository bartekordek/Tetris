CC = clang++
OBJ_DIR_NAME = obj
LIB_STATIC_CC = ar rcs
COMPILER_FLAGS = -pedantic -Wall -std=c++11
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
BINARY_NAME = Math.a 
HEADER_INC = -I inc/ -I Point/
OUTPUT_DEBUG = ../Build/$(OS)_DEBUG/$(BINARY_NAME)
OUTPUT_RELEASE = ../Build/$(OS)_RELEASE/$(BINARY_NAME)

CPP_FILES := $(wildcard */*.cpp)

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: CHECK_DIRS CD_OBJ $(OBJ_DEBUG_FILES) $(OUTPUT_DEBUG)
	$(LIB_STATIC_CC) $(OUTPUT_DEBUG) -o $(OBJ_DEBUG_FILES)

release: CHECK_DIRS CD_OBJ $(OBJ_RELEASE_FILES) $(OUTPUT_RELEASE)
	$(LIB_STATIC_CC) $(OUTPUT_RELEASE) -o $(OBJ_RELEASE_FILES) 

$(OBJ_DEBUG_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(DEBUG_FLAGS) -c -o $@ $<

$(OBJ_RELEASE_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(RELEASE_FLAGS) -c -o $@ $<

CHECK_DIRS:
	mkdir -p $(OBJ_DEBUG_DIR)
	mkdir -p $(dir $(OUTPUT_DEBUG))
	mkdir -p $(OBJ_RELEASE_DIR)
	mkdir -p $(dir $(OUTPUT_RELEASE))

CD_OBJ:
	cd $(OBJ_DIR_NAME) 

clear:
	rm -f $(OBJ_DEBUG_DIR)*.o
	rm -f $(OBJ_RELEASE_DIR)*.o
	rm -f $(OUTPUT_DEBUG)
	rm -f $(OUTPUT_RELEASE)

test:
	@echo "All .o files: $(OBJ_DEBUG_FILES)"
	@echo "All .cpp files: $(CPP_FILES)" 
