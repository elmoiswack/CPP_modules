NAME	:=	Zombie

SRC	:=	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

OBJ := $(SRC:.cpp=.o)

CC	:=	g++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re