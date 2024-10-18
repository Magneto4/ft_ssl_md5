# Folders and Names
NAME		= ft_ssl
SRCDIR		= src/
OBJDIR		= obj/
INCLUDES	= includes/
SRC			= main.c utils.c md5.c print_output.c algorithm_runner.c sha_256.c
DEP			= $(OBJS:.o=.d)

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

OBJ			= $(patsubst %.c, %.o, $(SRC))
OBJS		= $(addprefix ${OBJDIR}, ${OBJ})


all: $(NAME)

$(NAME): $(OBJS)
	@make print_name --no-print-directory
	@tput bold
	@tput setaf 2
	@printf "%-16s" "Linking "
	@tput sgr0
	@tput setaf 6
	@echo "${@}"

	@$(CC) -o $@ $(OBJS) -L./ft_printf -lftprintf

-include $(DEP)


$(OBJDIR)%.o: $(SRCDIR)%.c
	@make create_dir_objs --no-print-directory
	@make print_name --no-print-directory
	@tput bold
	@tput setaf 2
	@printf "%-16s" "Compiling "
	@tput sgr0
	@tput setaf 6
	@echo "${@}"

	@make -C ft_printf all

	@$(CC) $(LFLAGS) $(CFLAGS) -MMD -MP -c -I./ft_printf/libft -I./ft_printf -I $(INCLUDES) -o $@ $<

create_dir_objs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/commands
	@mkdir -p $(OBJDIR)/utils

clean:
	@make -C ft_printf clean
	@rm -fr $(OBJDIR)
	@rm	-f ${DEP}
	@make print_name --no-print-directory
	@tput bold
	@tput setaf 2
	@echo "clean done"

fclean: clean
	@make -C ft_printf fclean
	@rm -rf $(NAME)
	@make print_name --no-print-directory
	@tput bold
	@tput setaf 2
	@echo "fclean done"

re: fclean all

test: all
	./$(NAME)

print_name:
	@tput bold
	@tput setaf 208
	@printf "%-10s " $(NAME)

.PHONY: all clean fclean re test print_name create_dir_objs