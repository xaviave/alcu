# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/17 15:42:24 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2017/12/17 18:54:10 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY = all, clean, fclean, re


#COMIPLATION

CC = gcc
NAME = alum1
CFLAGS = -Wall -Wextra -Werror


#PATH

INCLUDE = alum1.h
LIBFT = libft/libft.a

SRCS = main.c\
	   input.c\
	   check.c\
	
OBJS = $(SRCS:.c=.o)


#RULES

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INCLUDE) -o $(NAME)
	@make loading && make loading && make loading
	@clear && echo "\033[32m --------------\n ALUM1 COMPILED\n --------------\n\033[0m"
	@./alum1

./%.o:./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

loading:
	@clear
	@echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▽"
	@echo "			 ▽         ▽"
	@echo "			 ▽         ▽"
	@echo "			  ▽       ▽"
	@echo "			     ▽ ▽"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▽"
	@echo "			 ▽         ▽"
	@echo "			  ▽       ▽"
	@echo "			     ▽ ▽"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▽"
	@echo "			  ▽       ▽"
	@echo "			     ▽ ▽"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▼"
	@echo "			  ▽       ▽"
	@echo "			     ▽ ▽"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▼"
	@echo "			  ▽       ▼"
	@echo "			     ▽ ▽"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▼"
	@echo "			  ▽       ▼"
	@echo "			     ▽ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▼"
	@echo "			  ▽       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▽         ▼"
	@echo "			  ▼       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▽         ▼"
	@echo "			 ▼         ▼"
	@echo "			  ▼       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▽       ▼"
	@echo "			 ▼         ▼"
	@echo "			 ▼         ▼"
	@echo "			  ▼       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▽ ▼"
	@echo "			  ▼       ▼"
	@echo "			 ▼         ▼"
	@echo "			 ▼         ▼"
	@echo "			  ▼       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.3 && clear && echo "			  LOADING\n"
	@echo "			     ▼ ▼"
	@echo "			  ▼       ▼"
	@echo "			 ▼         ▼"
	@echo "			 ▼         ▼"
	@echo "			  ▼       ▼"
	@echo "			     ▼ ▼"
	@sleep 0.5

%.o: $(DIR_SRCS)/%.c libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
