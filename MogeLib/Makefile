CC = g++
CC_LINK = g++ -shared 
COMPILER_FLAGS = -pedantic -Wall -std=c++11 -D MogeLib_EXPORT="" -Wno-ignored-attributes
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -Ofast
PROJECT_NAME = MogeLib
DLL_NAME = $(PROJECT_NAME).dll 
IMP_LIB_NAME = $(PROJECT_NAME).a
OUTPUT_DIR_DEBUG = ../Build/$(OS)_DEBUG
OUTPUT_DIR_RELEASE = /Build/$(OS)_RELEASE
HEADER_INC = -I inc/ -I ../String/inc/ -I ../MogeMath/inc/ -I $(HOME_SDL2_CYGWIN)/include/SDL2/ -I $(HOME_BOOST_CYGWIN)
IMPORT_LIBS_DEBUG = $(OUTPUT_DIR_DEBUG)/String.a $(HOME_SDL2_CYGWIN)/lib/libSDL2.dll.a $(HOME_BOOST_CYGWIN)/stage/lib/libboost_filesystem.a $(HOME_BOOST_CYGWIN)/stage/lib/libboost_system.a
OUTPUT_DEBUG = $(OUTPUT_DIR_DEBUG)/$(DLL_NAME)
OUTPUT_RELEASE = $(OUTPUT_DIR_RELEASE)/$(DLL_NAME)
IMP_LIB_DEBUG = $(OUTPUT_DIR_DEBUG)/$(IMP_LIB_NAME)
IMP_LIB_RELEASE = $(OUTPUT_DIR_RELEASE)/$(IMP_LIB_NAME)

CPP_FILES := $(wildcard */*.cpp)

OBJ_DEBUG_DIR := obj/debug/
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR),$(CPP_FILES:.cpp=.o))

OBJ_RELEASE_DIR := obj/release/
OBJ_RELEASE_FILES := $(addprefix $(OBJ_RELEASE_DIR),$(CPP_FILES:.cpp=.o))

debug: $(OUTPUT_DEBUG)
release: $(OUTPUT_RELEASE)

$(OUTPUT_DEBUG): $(OBJ_DEBUG_FILES)
	$(CC_LINK) -shared -o $(OUTPUT_DEBUG) $(OBJ_DEBUG_FILES) $(IMPORT_LIBS_DEBUG) -Wl,--out-implib,$(OUTPUT_DIR_DEBUG)/$(IMP_LIB_NAME)

$(OUTPUT_RELEASE): $(OBJ_RELEASE_FILES) 
	$(CC_LINK) 

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
