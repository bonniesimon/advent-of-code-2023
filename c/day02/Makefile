# the compiler to use
CC = gcc

# compiler flags:
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

# additional flags for debugging
DEBUG_FLAGS = -g

# the name to use for both the target source file, and the output file:
TARGET = main

all: $(TARGET)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

.PRECIOUS: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	./${TARGET} input.txt
