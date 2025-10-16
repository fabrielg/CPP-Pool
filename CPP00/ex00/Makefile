NAME	= megaphone

CC		= c++
FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

SRCS	= megaphone.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(STD) -o $@ $^

all: $(NAME)

clean:

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re