# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Source files
SRC = main.c parser.c parser_util.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = philo

# Default target
all: $(EXEC)

# Rule to link the object files into the final executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Rule to compile .c files into .o files
%.o: %.c philo_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean

