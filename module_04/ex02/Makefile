NAME = animals

CXX = c++
INCLUDES = -Iincludes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow $(INCLUDES)
DEPFLAGS = -MMD -MP

BUILD_DIR = build/

SRCS = src/main.cpp \
		src/AAnimal.cpp \
		src/Cat.cpp \
		src/Dog.cpp \
		src/Brain.cpp \

OBJS = $(patsubst src/%.cpp, $(BUILD_DIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# Colors for terminal output
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
RESET = \033[0m

all: $(NAME)
	@echo "\nProgram created:  $(GREEN)🐾 ./$(NAME) $(RESET)\n"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)🗑️  Removing executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

test: clear re
	@echo "$(YELLOW)\n🧪 Running tests with Valgrind...$(RESET)"
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

clear:
	clear
	@echo "$(MAGENTA)🧽 Clearing terminal...$(RESET)"

-include $(DEPS)

.PHONY: all clean fclean re test clear
