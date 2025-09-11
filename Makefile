SRC_DIR = srcs
HDR_DIR = includes

FLAGS = -Wall -Wextra -Werror
CC = cc

MY_SRCS = main.c\
		write_nbr.c\
		num_paddings.c\
		write_str.c\
		write_adds.c\
		utils1.c\
		utils2.c\
		parser.c

SRCS = $(addprefix $(SRC_DIR)/, $(MY_SRCS))
OBJS = $(SRCS:.c=.o)
# NAME = libftprintf.a
NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)
	$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

output: all
	$(addprefix ./, $(NAME))

leak: all
	valgrind --leak-check=full $(addprefix ./, $(NAME))

norm:
	norminette -R CheckDefine

.PHONY: all clean fclean out norm leak