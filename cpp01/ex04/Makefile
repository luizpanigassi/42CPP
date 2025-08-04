NAME = sed_is_for_losers
SRC = main.cpp \
	  Sed.cpp
HPP = Sed.hpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

all: $(NAME)

$(NAME): $(SRC) $(HPP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
