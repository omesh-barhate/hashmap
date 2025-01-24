# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ggdb

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SRC_FILES = $(SRCDIR)/main.c $(SRCDIR)/test.c

# Object files
OBJ_FILES = $(SRC_FILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Output executable
TARGET = $(BINDIR)/test_program

# Create necessary directories
$(OBJDIR) $(BINDIR):
	mkdir -p $(OBJDIR) $(BINDIR)

# Rule to compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the tests
run: $(TARGET)
	$(TARGET)

# Default target to build and run the program
all: $(TARGET) run
