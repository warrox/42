NAME = zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Zombie.cpp $(SRC_DIR)/zombieHorde.cpp
INCLUDES = $(INCLUDE_DIR)/Zombie.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
