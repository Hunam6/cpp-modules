NAME := serialize
SRCS_DIR := srcs
BUILD_DIR := build

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -Iincludes

SRCS := $(wildcard $(SRCS_DIR)/*.cpp)
OBJS := $(patsubst $(SRCS_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(patsubst $(SRCS_DIR)/%.cpp,$(BUILD_DIR)/%.d,$(SRCS))

.PHONY: all clean

all: $(BUILD_DIR) $(NAME)

clean:
	@rm -rf $(BUILD_DIR) $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "\033[2K[$(NAME)]: compiled"

-include $(DEPS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp Makefile
	@echo "\033[2K[$(NAME)]: compiling $<\033[A"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
