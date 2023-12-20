NAME	:=	REPLACE

SRC	:=	main.cpp \

OBJ := $(SRC:.cpp=.o)

CC	:=	c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re