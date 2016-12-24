CC = clang++
LIB_STATIC_CC = ar rcs
COMPILER_FLAGS = -pedantic -Wall -std=c++11
DEBUG_FLAGS = -ggdb
DEBUG_INTERMEDIATE_DIR = Intermediate/Debug
RELEASE_FLAGS = -Ofast
RELEASE_INTERMEDIATE_DIR = Intermediate/Release
BINARY_NAME = String.a 
CPPFILES = src/*.cpp
HEADER_SRCH_PATH = inc/
HEADER_INC = -I $(HEADER_SRCH_PATH)
OBJECTS = *.o
OUTPUT_DEBUG = ../Build/$(OS)_DEBUG/$(BINARY_NAME)
OUTPUT_RELEASE = ../Build/$(OS)_RELEASE/$(BINARY_NAME)

debug: CompileDebug 
	mkdir -p $(dir $(OUTPUT_DEBUG))
	$(LIB_STATIC_CC) $(OUTPUT_DEBUG) -o $(DEBUG_INTERMEDIATE_DIR)/*.o

release: CompileRelease
	mkdir -p $(dir $(OUTPUT_RELEASE))
	$(LIB_STATIC_CC) $(OUTPUT_RELEASE) -o $(RELEASE_INTERMEDIATE_DIR)/*.o

CompileDebug: $(CPPFILES)
	mkdir -p $(DEBUG_INTERMEDIATE_DIR)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(DEBUG_FLAGS) -c $? -o $(DEBUG_INTERMEDIATE_DIR)/$(basename $(notdir $?)).o

CompileRelease: $(CPPFILES)
	mkdir -p $(RELEASE_INTERMEDIATE_DIR)
	$(CC) $(HEADER_INC) $(COMPILER_FLAGS) $(RELEASE_FLAGS) -c $? -o $(RELEASE_INTERMEDIATE_DIR)/$(basename $(notdir $?)).o

clear:
	rm -f *.o
	rm -f *.exe
	rm -f $(DEBUG_INTERMEDIATE_DIR)/*.o
	rm -f $(RELEASE_INTERMEDIATE_DIR)/.*o
	rm -f $(OUTPUT_DEBUG)
	rm -f $(OUTPUT_RELEASE)
