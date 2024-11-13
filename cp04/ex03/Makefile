NAME = WorldOf42
CC = c++

CFLAGS = -std=c++98 -g3

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/AMateria.cpp $(SRC_DIR)/Cure.cpp $(SRC_DIR)/Ice.cpp $(SRC_DIR)/ICharacter.cpp $(SRC_DIR)/Character.cpp $(SRC_DIR)/MateriaSource.cpp

INCLUDES = $(INCLUDE_DIR)/AMateria.hpp $(INCLUDE_DIR)/Cure.hpp $(INCLUDE_DIR)/Ice.hpp $(INCLUDE_DIR)/ICharacter.hpp $(INCLUDE_DIR)/Character.hpp $(INCLUDE_DIR)/MateriaSource.hpp



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
