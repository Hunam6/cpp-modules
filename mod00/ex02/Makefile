NAME := logger
FLAGS := -std=c++98 -Wall -Wextra -Werror -I includes

SRCS := $(addprefix srcs/,\
	tests.cpp \
	Account.cpp \
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
