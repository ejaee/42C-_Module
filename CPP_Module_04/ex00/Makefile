NAME		= ex00

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	Animal.cpp		\
				Cat.cpp			\
				Dog.cpp			\
				WrongAnimal.cpp	\
				WrongCat.cpp	\
				main.cpp		\

OBJS		= $(SRCS:.cpp=.o)

all			: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean