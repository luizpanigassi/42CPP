NAME =	materia
SRC =	AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		ICharacter.cpp \
		IMateriaSource.cpp \
		main.cpp \
		MateriaSource.cpp
HPP =	AMateria.hpp \
		Character.hpp \
		Cure.hpp \
		Ice.hpp \
		ICharacter.hpp \
		IMateriaSource.hpp \
		MateriaSource.hpp

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
