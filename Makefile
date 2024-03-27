NAME = push_swap

SRCS = utils.c \
		stack_utils.c \
		stack_init.c \
		main.c \
		ft_split.c \
		errors.c \
		b_to_a.c \
		a_to_b.c \
		commands/push.c \
		commands/rev_rotate.c \
		commands/rotate.c \
		commands/sort_stacks.c \
		commands/sort_three.c \
		commands/swap.c \
		commands/command_utils.c


SRCS_OBJ = $(SRCS:.c=.o)

FT_PRINTF = ft_printf/libftprintf.a

FT_PRINTF_DIR = ft_printf

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

all: $(NAME)

$(FT_PRINTF):
	make -C ft_printf

$(NAME): $(SRCS_OBJ)
	cc -Wall -Wextra -Werror $(SRCS_OBJ) $(FT_PRINTF) -o $(NAME)

$(NAME): $(FT_PRINTF)

test100a:	${NAME}
			$(eval ARG = ${shell seq -1000000 1000000 | shuf -n 100})
			./push_swap ${ARG} | ./checker_linux ${ARG}
			@echo -n "Command: "
			./push_swap ${ARG} | wc -l

test500a:	${NAME}
			$(eval ARG = ${shell seq -1000000 1000000| shuf -n 500})
			./push_swap ${ARG} | ./checker_linux ${ARG}
			@echo -n "Command: "
			./push_swap ${ARG} | wc -l

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -rf  $(SRCS_OBJ)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -rf $(NAME) $(SRCS_OBJ)

re: fclean all