NAME = Brain
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Cat.cpp $(SRC_DIR)/AAnimal.cpp $(SRC_DIR)/WrongAnimal.cpp  $(SRC_DIR)/WrongCat.cpp $(SRC_DIR)/Brain.cpp


INCLUDES = $(INCLUDE_DIR)/AAnimal.hpp $(INCLUDE_DIR)/Cat.hpp $(INCLUDE_DIR)/Dog.hpp $(INCLUDE_DIR)/WrongAnimal.hpp $(INCLUDE_DIR)/WrongCat.hpp $(INCLUDE_DIR)/Brain.hpp $(INCLUDE_DIR)/colors.hpp








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
