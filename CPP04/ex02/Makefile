NAME	= animal

CC		= c++
FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

SRCS	= AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp

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