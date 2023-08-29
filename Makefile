MY_PROG=demo
CC=cc
CFLAGS = -Wall -g -std=c17

CXX=c++
CPPFLAGS = -Wall -g -std=c++17

OBJ_DIR = obj
BIN_DIR = bin
OUT_DIRS = $(OBJ_DIR) $(BIN_DIR)

ECHO = @echo
MD = mkdir -p


# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space
#VPATH = obj src include
# Search for .c files in "src" directory; .h files in "include" directory
# The pattern matching character '%' matches filename without the extension
vpath %.cpp src
vpath %.c src
vpath %.h include
vpath %.o $(OBJ_DIR)
#vpath %.d $(DEPDIR)

default: $(MY_PROG)

all: clean $(MY_PROG)

$(MY_PROG): demo.o GrokkingAlgorithm.o UtilsGrokkingAlgo.o
	@$(MD) $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$@ $(OBJ_DIR)/*.o



#%.o: %.c %.h ${OUT_DIRS}
#	$(CC) $(CFLAGS) -c $< -o $@ 

%.o: %.cpp %.h 
	@$(MD) $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $(OBJ_DIR)/$@ 

.PHONY: clean run acho dirs
clean:
	$(ECHO) "Cleaning..."
	$(RM) $(MY_PROG) *.o
	$(RM) -r ${OUT_DIRS}

run: $(MY_PROG)
	$(ECHO) "Running $(MY_PROG)"
	@$(BIN_DIR)/$(MY_PROG)

echo:
	$(ECHO) $(MKDIR)

dirs: ${OUT_DIRS}

${OUT_DIRS}:
	$(ECHO) "Creating directories..."
	$(MD) ${OUT_DIRS}

