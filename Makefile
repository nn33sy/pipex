NAME = pipex.a
CC=gcc
CFLAGS=  -Wall -Wextra -Werror
OBJ = ${SRCS:.c=.o}

SRCS =		ft_parsing.c\
			ft_utils.c\
			ft_exec.c
		
OBJS	=	$(SRCS:.c=.o)
# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

%.o: %.c
		@$(CC) -Iincludes $(CFLAGS)  -c $< -o $@
		@echo "Linking" [ $< ] $(OK)
	
$(NAME): $(OBJ)
	@make re -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $^
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)
	@$(CC) -Iincludes  $(OBJ) $(CFLAGS)  main.c  $(NAME) libft/libft.a  -o  pipex

leak:
	@$(CC) -Iincludes  $(OBJ) $(CFLAGS)  main.c  $(NAME) libft/libft.a -fsanitize=address -fno-omit-frame-pointer -o  leak

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "[ft_printf] Removed object files!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f pipex
	@make fclean -C libft/
	@echo "Cleaning" [ $(NAME) ] $(OK)

re: fclean all 

.PHONY: all clean fclean re 