NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		ClapTrap.cpp \

OBJS = $(SRCS:.cpp=.o)

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
RESET = \033[0m

COLORS = colors.hpp

all: $(COLORS) $(NAME)
	@echo "Program created:  $(GREEN)🤖 ./$(NAME) $(RESET)"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	rm -f $(NAME)
	rm -f $(COLORS)

re: fclean all

test: re
	@echo "$(YELLOW)Running tests with Valgrind...$(RESET)"
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

COLORS = colors.hpp

$(COLORS):
	@echo "🔧 Gerando colors.hpp..."
	@echo "#ifndef COLORS_HPP" > $(COLORS)
	@echo "# define COLORS_HPP" >> $(COLORS)
	@echo "" >> $(COLORS)
	@echo '# define RESET   "\033[0m"' >> $(COLORS)
	@echo '# define BLACK   "\033[30m"' >> $(COLORS)
	@echo '# define RED     "\033[31m"' >> $(COLORS)
	@echo '# define GREEN   "\033[32m"' >> $(COLORS)
	@echo '# define YELLOW  "\033[33m"' >> $(COLORS)
	@echo '# define BLUE    "\033[34m"' >> $(COLORS)
	@echo '# define MAGENTA "\033[35m"' >> $(COLORS)
	@echo '# define CYAN    "\033[36m"' >> $(COLORS)
	@echo '# define WHITE   "\033[37m"' >> $(COLORS)
	@echo "" >> $(COLORS)
	@echo '# define BOLD    "\033[1m"' >> $(COLORS)
	@echo '# define UNDER   "\033[4m"' >> $(COLORS)
	@echo "" >> $(COLORS)
	@echo "#endif" >> $(COLORS)
	@echo "✅ colors.hpp criado."

.PHONY: all clean fclean re test
