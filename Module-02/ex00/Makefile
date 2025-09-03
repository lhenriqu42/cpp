# ===========================================================================
#  =============================== CONTROL =================================
# ===========================================================================

UP = \033[A
CUT = \033[K
RESET = \033[0m
RED = \033[31;3m
GREEN = \033[32;3m
YELLOW = \033[33;3m
WHITE = \033[37;1;4m
CYAN = \033[36;1;3;208m

# ===========================================================================
#  =============================== COMPILER ================================
# ===========================================================================

CFLAGS := -Wall -Wextra -Werror -std=c++98 -g3
VALGRIND_LOG := valgrind.log
CC := c++

# ===========================================================================
#  =============================== C++ =====================================
# ===========================================================================

NAME = fix
EX_PATH = ex00/
HEADERS_PATH = ./includes/
BUILD_PATH = ./build/
FILES_PATH = ./src/

FILES = \
	main.cpp \
	Zombie.cpp \
	zombieHorde.cpp \

OBJS = $(addprefix $(BUILD_PATH), $(FILES:%.cpp=%.o))

# ===========================================================================
#  ================================= RULES =================================
# ===========================================================================

all: $(BUILD_PATH) print $(NAME)

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)

print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(RESET)"
	@printf "$(GREEN)| Compiling Main Project |$(RESET)"
	@printf "$(GREEN)------------------------$(RESET)"
	@echo " "
endif

$(NAME): $(OBJS) $(HEADERS_PATH)
	@printf "$(YELLOW)[Building]$(RESET) $(NAME)...\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADERS_PATH)
	@printf "$(UP)$(CUT)"
	@printf "$(GREEN)[Builded]$(RESET) $(NAME)...\n"
	@printf "$(CYAN)------ ------------------------------- ------$(RESET)\n"
	@printf "$(CYAN)------| $(EX_PATH) compiled successfully!! |------$(RESET)\n"
	@printf "$(CYAN)------ ------------------------------- ------$(RESET)\n"
	@echo " "

$(BUILD_PATH)%.o:$(FILES_PATH)%.cpp
	@printf "$(YELLOW)[Compiling]$(RESET) $(notdir $<)...\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADERS_PATH)
	@printf "$(UP)$(CUT)"
	@printf "$(GREEN)[Compiled]$(RESET) $(notdir $<)...\n"

clean:
	@printf "$(RED)[Removing Objects...]$(RESET)\n"
	@rm -rf $(BUILD_PATH)
	@rm -rf $(VALGRIND_LOG)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(RESET)\n"
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME)
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re valgrind
