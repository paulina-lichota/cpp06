NAME = base

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

SRC = main.cpp \
	  Base.cpp \
	  A.cpp \
	  B.cpp \
	  C.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "---- Building of $(NAME) ----$(RESET)";
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re