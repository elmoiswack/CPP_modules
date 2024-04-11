NAME	:=	btc

SRC	:=	main.cpp \
		BitcoinExchange.cpp \

OBJ := $(SRC:.cpp=.o)

CC	:=	c++ -g -fsanitize=address

CFLAGS	:= -Wall -Wextra -std=c++11

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