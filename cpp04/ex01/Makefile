CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp src/animal.cpp src/dog.cpp src/cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp
NAME = Polymorphism

OBJDIR = AAA
all : $(NAME)
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "All done !"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "All clean !"

fclean: clean
	@rm -rf $(NAME)
	@echo "All clean ++!"

re: fclean all

.PHONY: all clean fclean re