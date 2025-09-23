cc = c++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = phonebook.cpp

OBJ = $(SRC:%.c=%.o)

NAME = phonebook

all : $(NAME)

$(NAME): $(OBJ)

%.o : %.c
	@$(cc) $(CCFLAGS) -c $< -o $@
clean :
	rm -f %.o

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all NAME clean fclean re
