NAME = bsp
SRC = bsp.cpp \
	  Fixed.cpp \
	  main.cpp \
	  Point.cpp
HPP = Fixed.hpp \
	  Point.hpp


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
