# the compiler to use
CC = gcc

# compiler flags:
# -g flags for debugging
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the name to use for both the target source file, and the output file:
TARGET = main

all: $(TARGET)

# .PRECIOUS: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	./${TARGET} input.txt
