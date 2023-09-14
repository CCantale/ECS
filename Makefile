################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################

NAME		=		test

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror

SRCS		=		test.cpp \
				EntityManager.cpp

OBJDIR		=		obj
OBJS		=		$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))



all: $(NAME)


$(NAME): $(OBJS)
	@$(CC) -g $^ -o $(NAME)
	@echo test successfully compiled!

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(INCLS) $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm $(NAME)
	@echo test deleted.

kill:
	@make -s clean
	@make fclean

re:
	@make -s kill
	@make -s

r:
	@make -s
	@./$(NAME)

.PHONY: all clean fclean kill re

