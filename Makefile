CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -lreadline
RM = rm -f

NAME = cub_3d

#Libft
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

#MLX
LIBMLXDIR = ./minilibx-linux
LIBMLX = $(LIBMLXDIR)/libmlx.a

SRCDIR = srcs
OBJDIR = objs
SRCS = main.c \


OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

LDFLAGS = -L$(LIBMLXDIR) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm


$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@echo "\033[0;32m✅---COMPILING IS DONE---✅\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFTDIR)

$(LIBMLX):
	@make -sC $(LIBMLXDIR)

clean:
	@$(RM) $(OBJS)
	@make -sC $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -sC $(LIBFTDIR) fclean

re: fclean all

v:
	make re && valgrind --leak-check=full --show-leak-kinds=all  --suppressions="supp.supp" ./minishell
	