NAME	= harl

CC		= c++
FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

SRCS	= Harl.cpp

MAIN	= main.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(STD) -o $@ $^ $(MAIN)

$(SRCS): SRCS += $(MAIN)

all: $(NAME)

clean:

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re