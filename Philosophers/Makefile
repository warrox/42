# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
# CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fstack-protector-strong -fno-optimize-sibling-calls
# Source files
SRC = main.c parser.c parser_util.c philo_util.c philo_util_2.c simulation.c simulation_util.c philo_util_3.c 

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = philo

# Default target
all: $(EXEC)

all:
	@echo "______ _     _ _                       _                   "
	@echo "| ___ \ |   (_) |                     | |                  "
	@echo "| |_/ / |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ "
	@echo "|  __/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|"
	@echo "| |   | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \\"
	@echo "\_|   |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/"
	@echo "                                | |                        "
	@echo "                                |_|                        "
	@echo " ____________________________________________________"
	@echo " |____________________________________________________|"
	@echo " | __     __   ____   ___ ||  ____    ____     _  __  |"
	@echo " ||  |__ |--|_| || |_|   |||_|**|*|__|+|+||___| ||  | |"
	@echo " ||==|^^||--| |=||=| |=*=||| |~~|~|  |=|=|| | |~||==| |"
	@echo " ||  |##||  | | || | |WHA|||-|  | |==|+|+||-|-|~||__| |"
	@echo " ||__|__||__|_|_||_|_|___|||_|__|_|__|_|_||_|_|_||__|_|"
	@echo " ||_______________________||__________________________|"
	@echo " | _____________________  ||      __   __  _  __    _ |"
	@echo " ||=|=|=|=|=|=|=|=|=|=|=|=| __..\/ |  |_|  ||#||==|  / /|"
	@echo " || | | | | | | | | | | | |/\ \  \\|++|=|  || ||==| / / |"
	@echo " ||_|_|_|_|_|_|_|_|_|_|_/_/\_.___\__|_|__||_||__|/_/__|"
	@echo " |____________________ /\~()/()~//\ __________________|"
	@echo " | __   __    _  _     \_  (_ .  _/ _    ___     _____|"
	@echo " ||~~|_|..|__| || |_ _   \ //\\ /  |=|__|~|~|___| | | |"
	@echo " ||--|+|^^|==|1||2| | |__/\ __ /\__| |==|x|x|+|+|=|=|=|"
	@echo " ||__|_|__|__|_||_|_| /  \ \  / /  \_|__|_|_|_|_|_|_|_|"
	@echo " |_________________ _/    \/\/\/    \_ _______________|"
	@echo " | _____   _   __  |/      \../      \|  __   __   ___|"
	@echo " ||_____|_| |_|##|_||   |   \/ __|   ||_|==|_|++|_|-|||"
	@echo " ||______||=|#|--| |\   \   o    /   /| |  |~|  | | |||"
	@echo " ||______||_|_|__|_|_\   \  o   /   /_|_|__|_|__|_|_|||"
	@echo " |_________ __________\___\____/___/___________ ______|"
	@echo " |__    _  /    ________     ______           /| _ _ _|"
	@echo " |\ \  |=|/   //    /| //   /  /  / |        / ||%|%|%|"
	@echo " | \/\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|"
	@echo "__|  \/\|/   /(____|/ //                    /  /||~|~|~|__"
	@echo " |___\_/   /________//   ________         /  / ||_|_|_|"
	@echo " |___ /   (|________/   |\_______\       /  /| |______|"
	@echo "      /                  \|________)     /  / | |"

# Rule to link the object files into the final executable
all: $(EXEC)
$(EXEC): $(OBJ)
	@echo "\033[1;34mLinking object files into the final executable...\033[0m"
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)
	@echo "\033[1;32mBuild successful!\033[0m"

# Rule to compile .c files into .o files
%.o: %.c philo_lib.h
	@echo "\033[1;33mCompiling $<...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32mCompiled $< successfully!\033[0m"

# Rule to run valgrind to check for memory leaks and data races
val: $(EXEC)
	@echo "\033[1;36mRunning valgrind to check for memory leaks...\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXEC)
	@echo "\033[1;36mRunning valgrind to check for data races with Helgrind...\033[0m"
	valgrind --tool=helgrind ./$(EXEC)
	@echo "\033[1;32mValgrind check complete!\033[0m"

# Clean up object files and the executable
clean:
	@echo "\033[1;31mCleaning up object files and the executable...\033[0m"
	rm -f $(OBJ) $(EXEC)
	@echo "\033[1;32mClean complete!\033[0m"

fclean: clean

re: fclean all

# Phony targets
.PHONY: all clean fclean re val
