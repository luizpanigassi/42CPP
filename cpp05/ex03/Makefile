NAME = bureaucrat
SRC = main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp \
	  Intern.cpp
HPP = Bureaucrat.hpp \
	  AForm.hpp \
	  PresidentialPardonForm.hpp \
	  RobotomyRequestForm.hpp \
	  ShrubberyCreationForm.hpp \
	  Intern.hpp

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
