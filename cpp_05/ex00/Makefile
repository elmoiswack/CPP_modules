NAME	:=	Bureaucrat

SRC	:=	main.cpp \
		Bureaucrat.cpp \

OBJ := $(SRC:.cpp=.o)

CC	:=	c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re