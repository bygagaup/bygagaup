NAME = fillit

SRC = fillit.c\
		ft_creatarr.c\
		ft_valtet.c\
		ft_creatlsttet.c\
		ft_trash.c\
		ft_alg.c\
		ft_foralg.c \

INCLUDES = libft/libft.a
.PHONY: 
	all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C libft	
	gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)

clean: 
	$(MAKE) -C libft clean	

fclean: clean
	$(MAKE) -C libft fclean	
	rm -f fillit

re: fclean all

