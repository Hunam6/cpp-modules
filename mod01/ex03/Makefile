NAME := violence
FLAGS := -std=c++98 -Wall -Wextra -Werror -I includes -g -fsanitize=address,undefined

SRCS := $(addprefix srcs/,\
	main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \
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
