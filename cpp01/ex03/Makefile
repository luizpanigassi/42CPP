NAME = violence
SRC = HumanA.cpp \
	  HumanB.cpp \
	  main.cpp \
	  Weapon.cpp

HPP = HumanA.hpp \
	  HumanB.hpp \
	  Weapon.hpp

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
