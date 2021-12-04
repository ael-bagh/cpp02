SRC = main.cpp Fixed.cpp
NAME = Fixed

all: $(NAME)

$(NAME): 
	clang++ -Wall -Werror -Wextra -std="c++98" -o $(NAME) $(SRC)
clean:
	rm -f $(NAME)
fclean: clean
	rm -f $(NAME)
re: fclean all
