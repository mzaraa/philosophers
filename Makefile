# SOURCES
SRCS	= 	main.c \
			check_valid_args.c \
			quit_error.c \
			simulation.c \
			init_mutex.c \
			utils.c \

OBJS	= $(addprefix bin/, $(SRCS:.c=.o))

# COMPILATION
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -Ofast -ffast-math

INCS	= 

LIBS	= # LIBRARIES (ex: libft)

C_OPTS	= $(FLAGS) $(INCS) -g
BIN_OPT	= $(LIBS)

# OTHER
NAME = philo

RED = \033[91;1m
GRE = \033[32;1m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

bin/%.o: %.c
	@mkdir -p bin
	@$(CC) $(C_OPTS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(BIN_OPT) $^ -o $@
	@echo "$(GRE)$@ compiled 🤢$(EOC)"

run: all
	@./$(NAME)

debug:
	@rm -rf bin
	@rm -f $(NAME)
	@make C_OPTS="$(C_OPTS) -g" BIN_OPT="$(BIN_OPT) -fsanitize=address"

clean:
	@rm -rf bin
	@echo "$(RED)objects deleted 😡$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)executables deleted 😡$(EOC)"

re: fclean all

.PHONY: all clean fclean re