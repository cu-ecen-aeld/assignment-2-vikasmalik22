# Makefile for building the "writer" application

# Variables
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = writer
SRC = writer.c
OBJ = writer.o

# Default target: build the writer application
all: $(TARGET)

# Compile the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove binary and object files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean
