NAME := interfaces
FLAGS := -std=c++98 -Wall -Wextra -Werror -I includes -g #TODO: rm -g

SRCS := $(addprefix srcs/,\
	main.cpp \
	AMateria.cpp \
	Character.cpp \
	Cure.cpp \
	Ice.cpp \
	MateriaSource.cpp \
)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME):
	@echo "Compiling $(NAME)..."
	@g++ $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all
