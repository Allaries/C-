CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = main.cpp src/Bureaucrat.cpp src/Form.cpp
NAME = Formup

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