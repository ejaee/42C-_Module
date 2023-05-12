NAME		= Unnecessary_violence

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

SRCS		= HumanA.cpp		\
				HumanB.cpp		\
				Weapon.cpp		\
				main.cpp

OBJS		= $(SRCS:.cpp=.o)

all 		: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
