NAME	= account

CC		= c++
FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

SRCS	= Account.cpp

MAIN	= tests.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(STD) -o $@ $^ $(MAIN)

$(SRCS): SRCS += $(MAIN)

all: $(NAME)

clean:

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re