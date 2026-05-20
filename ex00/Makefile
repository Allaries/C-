CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
NAME = megaphone

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
all : $(NAME)
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