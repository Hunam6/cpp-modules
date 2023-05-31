NAME := phonebook
FLAGS := -std=c++98 -Wall -Wextra -Werror -I includes

SRCS := $(addprefix srcs/,\
	main.cpp \
	Contact.cpp \
	PhoneBook.cpp \
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
