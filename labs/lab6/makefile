
CC = g++
CFLAGS = -g -Wall
BIN = BST1 BST2 BST3

all: $(BIN)

BST1: BST1.h BST1_usage.cpp
	$(CC) $(CFLAGS) -o BST1 BST1_usage.cpp

BST2: BST2.h BST2_usage.cpp
	$(CC) $(CFLAGS) -o BST2 BST2_usage.cpp

BST3: BST3.h BST3_usage.cpp
	$(CC) $(CFLAGS) -o BST3 BST3_usage.cpp

.cpp: 
	$(CC) $(CFLAGS) -o $* $<

clean:
	rm -f $(BIN) *.o
