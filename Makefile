# WEBSERV Makefile by dhorvath
# property of David inc.

NAME=webserv

########    UTILS    ########

NAMECOLOR	=	\033[38;46m
PIPECOLOR	=	\033[38;45m
FILECOLOR	=	\033[38;42m
OUTCOLOR	=	\033[38;44m
RESET		=	\033[0m
MESSAGE		=	\033[38;41m
INDENT		=	| sed 's/^/  /'

########    FILES    ########

SRCDIR		=	src/
OBJDIR		=	obj/
INCLUDEDIR	=	include/

FLAGS	=	-Wall -Wextra -Werror -std=c++20 \
			-I$(INCLUDEDIR)

SRC	=	$(wildcard $(SRCDIR)*.cpp)
OBJ	=	$(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))
INC	=	$(wildcard $(INCLUDEDIR)*.hpp)

########    RULES    ########

all: $(NAME)


$(NAME): $(OBJDIR) $(OBJ) $(INC)
	@echo "$(NAMECOLOR)$(NAME) $(PIPECOLOR)| $(FILECOLOR)compiling executable: $(OUTCOLOR)$(NAME)$(RESET)"
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@echo "$(NAMECOLOR)$(NAME) $(PIPECOLOR)| $(FILECOLOR)$< => $(OUTCOLOR)$@ $(RESET)"
	@c++ $(FLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

clean:
	@echo "$(MESSAGE)removing files:$(RESET)"
	@ls $(OBJDIR)* $(INDENT)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(MESSAGE)removing executable:$(RESET)"
	@echo "$(OUTCOLOR)$(NAME)$(RESET)" $(INDENT)
	@rm -rf $(NAME)

re: fclean all

########    TESTS    ########


########    MISC.    ########
.PHONY: all clean fclean re