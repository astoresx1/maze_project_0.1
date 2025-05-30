CC = gcc

CFLAGS = -Wall

LIBS = -lncurses

SRCS = maze.c

TARGET = maze

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LIBS)
	
clean:
	rm -f $(TARGET)