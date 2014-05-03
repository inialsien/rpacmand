CC=gcc
CFLAGS=
LIB_DIR=./lib/
LDFLAGS=$(xmlrpc-c-config client --ldflags)
SRC_DIR=./src/
SRC=$(wildcard $(SRC_DIR)*.c)
OBJ_DIR=./bin/
OBJ=$(SRC:.c=.o)
EXEC=rpacmand

all: $(OBJ)
	$(CC) $(CFLAGS) -L$(LDFLAGS)$(LIB_DIR) -o $(EXEC) main.c $^ $(LIB_DIR)libobdii.a
%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $^


clean :
	rm -rf $(SRC_DIR)*.o

mrproper : clean 
	rm -rf $(EXEC)
