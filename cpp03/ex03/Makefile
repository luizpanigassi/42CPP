NAME = diamondtrap
SRC = main.cpp \
	  Claptrap.cpp \
	  ScavTrap.cpp \
	  FragTrap.cpp \
	  DiamondTrap.cpp
HPP = Claptrap.hpp \
	  ScavTrap.hpp \
	  FragTrap.hpp \
	  DiamondTrap.hpp

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
