NAME		= replace

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

SRCS		= FileDto.cpp		\
				main.cpp

OBJS		= $(SRCS:.cpp=.o)

all 		: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) ./ex04_testFiles/*.replace

re: fclean all

.PHONY: all clean fclean
