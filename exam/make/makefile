CC = gcc
CFLAGS = -c -g -Wall
BIN = ../bin/
SRC = ../src/
OBJ = ../obj/
INC = ../include/
IFLAGS = -I$(INC)
GFLAGS = `pkg-config --cflags --libs glib-2.0`

all :$(BIN)output
$(BIN)output : $(OBJ)main.o $(OBJ)util.o
	$(CC) -o $(BIN)output $(OBJ)main.o $(OBJ)util.o $(CFLAGS) $(GFLAGS) $(IFLAGS) 
	mv output $(BIN)
$(OBJ)main.o : $(SRC)main.c
	$(CC) $(CFLAGS) $(GFLAGS) $(IFLAGS) $(SRC)main.c
	mv main.o $(OBJ)

$(OBJ)util.o : $(SRC)util.c
	$(CC) $(CFLAGS) $(GFLAGS) $(IFLAGS) $(SRC)util.c
	mv util.o $(OBJ)
clean:
	rm -f $(OBJ)*.o
	rm -f $(BIN)output
