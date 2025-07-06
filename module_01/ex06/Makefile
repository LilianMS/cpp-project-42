NAME = harlFilter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Harl.cpp

OBJS = $(SRCS:.cpp=.o)

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
RESET = \033[0m

all: $(NAME)
	@echo "Program created:  $(GREEN) ./$(NAME) $(RESET)"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

test: re
	@echo "$(YELLOW)Running tests with Valgrind...$(RESET)"
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) DEBUG

.PHONY: all clean fclean re test
