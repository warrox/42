NAME = Animal
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Cat.cpp $(SRC_DIR)/Animal.cpp $(SRC_DIR)/WrongAnimal.cpp  $(SRC_DIR)/WrongCat.cpp


INCLUDES = $(INCLUDE_DIR)/Animal.hpp $(INCLUDE_DIR)/Cat.hpp $(INCLUDE_DIR)/Dog.hpp $(INCLUDE_DIR)/WrongAnimal.hpp $(INCLUDE_DIR)/WrongCat.hpp






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
