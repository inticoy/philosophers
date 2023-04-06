# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/04/06 14:56:33 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
PHILO	= Dining Philosophers Problem

# **************************************************************************** #
#                                                                              #
#    Options                                                                   #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# **************************************************************************** #
#                                                                              #
#    Source Files                                                              #
#                                                                              #
# **************************************************************************** #

error		= $(addprefix error/,		raise_error.c)
fork		= $(addprefix fork/,		set_forks.c)
philo		= $(addprefix philo/,		act_philo.c			\
										set_philos.c)
table		= $(addprefix table/,		set_table_manners.c)
thread		= $(addprefix thread/,		await_threads.c		\
										create_threads.c	\
										detach_threads.c)
utils		= $(addprefix utils/,		ft_atoi.c			\
										ft_putstr_fd.c		\
										ft_strlen.c)
main		= main.c

SRCS		= $(addprefix src/,			$(error)		\
										$(fork)			\
										$(philo)		\
										$(table)		\
										$(thread)		\
										$(utils)		\
										$(main))
OBJS 		= ${SRCS:.c=.o}
INCLUDE		= ./include

# **************************************************************************** #
#                                                                              #
#    Progress                                                                  #
#                                                                              #
# **************************************************************************** #


num_file	= $(shell echo $(SRCS) | tr ' ' '\n' | wc -w)
cnt			:= 0
bar_done	= '🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩'
bar_ready	= '⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️'

#			COLOR
red			= \e[1;31m
grn			= \e[1;32m
yel			= \e[1;33m
blu			= \e[1;34m
mag			= \e[1;35m
cyn			= \e[1;36m
bold		= \e[1;37m
end			= \e[0m

version = "mandatory version"

# **************************************************************************** #
#                                                                              #
#    Executable Section                                                        #
#                                                                              #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $@
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "🍽️  Now you simulate ${bold}$(PHILO).${end}"
	@printf " (%s)\n" $(version)

$(LIBFT) :
	@printf "Build ${bold}[LIBFT]${end}\n"
	@make -C libft -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

$(MLX) :
	@printf "Build ${bold}[MINILIBX]${end}\n"
	@make -C minilibx -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

%.o : %.c
	@$(eval cnt=$(shell printf $$(($(cnt)+1))))
	@$(eval rate_hex=$(shell echo "scale=2; ($(cnt) / $(num_file)) * 16" | bc))
	@$(eval len=$(shell printf "%.0f\n" $(rate_hex)))
	@$(eval len_done=$(shell echo "scale=0; $(len) * 4" | bc))
	@$(eval len_ready=$(shell echo "scale=0; 96 - ($(len_done) / 4) * 6" | bc))
	@$(eval percent=$(shell echo "scale=4; ($(cnt) / $(num_file)) * 100" | bc))
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" $(len_done))s" $(bar_done)
	@printf "%.$(shell printf "%d" $(len_ready))s" $(bar_ready)
	@printf "%7.2f%%" $(percent)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@printf "make clean ${bold}$(PHILO).${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@printf "make fclean ${bold}$(PHILO).${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re