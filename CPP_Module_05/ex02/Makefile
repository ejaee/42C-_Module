NAME		= ex02

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	Bureaucrat.cpp	\
				AForm.cpp		\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp	\
				main.cpp		\

OBJS		= $(SRCS:.cpp=.o)

all			: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) *_shrubbery

re: fclean all

.PHONY: all clean fclean