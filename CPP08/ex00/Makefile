NAME	= easyfind
CC		= c++
SRC		= main.cpp

FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98
DEP_FLAGS = -MMD -MP

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(STD) $(DEP_FLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

-include $(DEPS)

clean :
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re