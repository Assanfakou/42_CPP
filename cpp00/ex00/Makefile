CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = maegaphone

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all NAME clean fclean re

