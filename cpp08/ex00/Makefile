CXX = c++
CXXFLAGS = 

SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)

NAME = run

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
