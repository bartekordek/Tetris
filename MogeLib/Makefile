CC = clang++
CC_LINK = clang++ -shared 
COMPILER_FLAGS = -pedantic -Wall -std=c++11 -D MogeLib_EXPORT=""
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
PROJECT_NAME = MogeLib
DLL_NAME = $(PROJECT_NAME).dll 
IMP_LIB_NAME = $(PROJECT_NAME).a
HEADER_INC = -I inc/ -I ../String/inc/ -I ../MogeMath/inc/ -I $(HOME_SDL2_CYGWIN)/include/SDL2/ -I $(HOME_BOOST_CYGWIN) 
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
	#$(CC_LINK) $(OUTPUT_DEBUG) -o $(OBJ_DEBUG_FILES)

$(OUTPUT_RELEASE): $(OBJ_RELEASE_FILES) 
	#$(CC_LINK) $(OUTPUT_RELEASE) -o $(OBJ_RELEASE_FILES) 

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
	@echo "SDL2: $(HOME_SDL2_CYGWIN)/"

help:
	echo "If run first time, please run \"make first_run\" it will create necessary dirs."
