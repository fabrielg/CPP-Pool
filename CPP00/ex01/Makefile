NAME	= phonebook

CC		= c++
FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

SRCS	= Contact.cpp PhoneBook.cpp

MAIN	= main.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(STD) -o $@ $^ $(MAIN)

$(SRCS): SRCS += $(MAIN)

all: $(NAME)

clean:

fclean: clean
	rm -fr $(NAME)

re: fclean all

test: MAIN = main_test.cpp
test: re

.PHONY: all clean fclean re test