CC = gcc
CFLAGS = -g -c -Wall
IFLAGS = -I$(INC)
OBJ = ../obj/
SRC = ../src/
INC = ../include/
BIN = ../bin/
GFLAGS = `pkg-config --cflags --libs glib-2.0`

all : $(BIN)output

$(BIN)output : $(OBJ)main.o $(OBJ)utility.o
	$(CC) -o $(BIN)output $(OBJ)main.o $(OBJ)utility.o $(GFLAGS)
	mv output $(BIN)
$(OBJ)main.o : $(SRC)main.c
	$(CC) $(CFLAGS) $(IFLAGS) $(GFLAGS) $(SRC)main.c
	mv main.o $(OBJ)
$(OBJ)utility.o : $(SRC)utility.c
	$(CC) $(CFLAGS) $(IFLAGS) $(GFLAGS) $(SRC)utility.c
	mv utility.o $(OBJ)
clean:
	rm -f $(OBJ)*.o
	rm -f $(BIN)output 
