NAME	= materia
CC		= c++
SRC		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

FLAGS	= -Wall -Wextra -Werror
STD		= -std=c++98

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp
	$(CC) $(FLAGS) $(STD) -o $@ -c $< $(INCLUDES)

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -fr $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re