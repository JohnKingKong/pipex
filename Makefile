# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/04/20 11:15:43 by jvigneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
define JR

	BIG LEAK!!!! A PICTURE OF ME WORKING

                        .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .-------.        \'---'/    //
     _|~~ ~~  |_       /`"""`\\  ((
   =(_|_______|_)=    / /_,_\ \\  \\
     |:::::::::|      \_\\_'__/ \  ))
     |:::::::[]|       /`  /`~\  |//
     |o=======.|      /   /    \ //
     `"""""""""`  ,--`,--'\/\   //
                  '-- "--'  '--'
endef
export JR

define TEA

		TEABAG THAT MOTHERF***ER

            .------.____
         .-'       \ ___)
      .-'         \\\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\\
        \ /    /__v__\\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|

endef
export TEA

SRCS	= 	./srcs/pipex.c ./srcs/pipex_utils.c ./srcs/printerr.c

HEADERS	=	pipex.h

vpath %.h include/

OB		= @mkdir -p objs && mv ./srcs/*.o ./objs/ 

OBJS	=	${SRCS:.c=.o}

CC		=	@gcc

RM		=	@rm -rf

CFLAGS	=	-Wall -Wextra -Werror -o pipex

LIBS	=	./libs/libft/libft.a

NAME	=	pipex

FTMAKE	=	@cd ./libs/libft && make -s 

RUN		=	./pipex

CLS		= 	clear

all		:	$(NAME)

$(NAME)	:	$(SRCS) $(OBJS) $(HEADERS)
			@if [ ! -d "./objs" ]; then \
				clear && \
				echo "__________________________________" && \
				echo "\n       Compiling.....\n" && \
				echo "__________________________________" && \
				touch a ;\
			fi 
			$(FTMAKE) 
			@ if [ ! -d "./objs" ]; then \
				echo "__________________________________" && \
				echo "\n      Libft compiled \n" && \
				echo "__________________________________"; \
			fi
			$(CC) $(SRCS) $(LIBS) $(CFLAGS)
			@if [ -p "./objs" ]; then \
				rm -rf ./objs; \
			fi
			$(OB)
			@if [ -f "./a" ]; then \
				sleep 1 && \
				echo "__________________________________" && \
				echo "\n Project succesfully compiled!\n" && \
				echo "__________________________________" && \
				rm -f ./a; else \
				clear && \
				echo "__________________________________" && \
				echo "\n             Done\n" && \
				echo "__________________________________"; \
			fi
clean	:	
			@clear
			@echo "__________________________________"
			@echo "\n     Clearing object files... \n"
			@echo "__________________________________"
			${RM} ./objs
			$(FTMAKE) $@
			@sleep 1
			@echo "__________________________________"
			@echo "\n     Cleaning Successful! \n"
			@echo "__________________________________"
			@sleep 1

fclean	:	clean
			@echo "__________________________________"
			@echo "\n     Clearing other files... \n"
			@echo "__________________________________"
			$(RM) $(NAME)
			$(FTMAKE) $@
			@sleep 1
			@echo "__________________________________"
			@echo "\n         Cleaning done!\n"
			@echo "__________________________________"
			@sleep 1
			
re		:	fclean all

run :		fclean all 
			@echo "Enter the files and commands (Usage [FILE IN] [1ST CMD] [2ND CMD] [FILE OUT])"; \
			read ARGS; \
			$(RUN) $$ARGS
			
jr		: 
			clear
			@echo "$$JR"

tea	:
			clear
			@echo "$$TEA"

.PHONY	:	all clean fclean re bonus jr

.SILENT :   clean fclean

