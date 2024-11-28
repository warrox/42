NAME = INTERN
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRC_DIR = src
INCLUDE_DIR = includes

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Bureaucrat.cpp $(SRC_DIR)/AForm.cpp  $(SRC_DIR)/RobotomyRequestForm.cpp  $(SRC_DIR)/PresidentialPardonForm.cpp $(SRC_DIR)/ShrubberyCreationFrom.cpp $(SRC_DIR)/Intern.cpp

INCLUDES = $(INCLUDE_DIR)/Bureaucrat.hpp $(INCLUDE_DIR)/Colors.hpp $(INCLUDE_DIR)/RobotomyRequestForm.hpp $(INCLUDE_DIR)/PresidentialPardonForm.hpp $(INCLUDE_DIR)/ShrubberyCreationFrom.hpp $(INCLUDE_DIR)/Intern.hpp
 

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
