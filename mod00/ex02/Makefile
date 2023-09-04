OBJS_DIR = objs
SRCS_DIR = srcs
SRCS = $(wildcard $(SRCS_DIR)/*.cpp)
OBJS = $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))

NAME = logger
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS += -Iincludes

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	@echo "\033[2K[$(NAME)]: compiling $<\033[A"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) -o $@ $^ $(CXXFLAGS)
	@echo "\033[2K[$(NAME)]: compiled"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR) $(NAME)
	@echo "\033[2K[$(NAME)]: cleaned"
