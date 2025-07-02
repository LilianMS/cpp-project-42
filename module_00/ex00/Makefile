NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Colors
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)
	@echo "Program created: $(GREEN)📣 ./$(NAME) $(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking...$(RESET)"
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

test:
	@echo -e "$(YELLOW)🔧 Running tests...$(RESET)"
	./test.sh

.PHONY: all clean fclean re test
