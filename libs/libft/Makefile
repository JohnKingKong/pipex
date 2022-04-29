# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/04/15 14:34:00 by jvigneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
define NL


endef





SRCS	= 	ft_atoi.c ft_bzero.c  ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c	ft_memmove.c ft_memset.c  \
			ft_putchar_fd.c ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			ft_strrchr.c get_next_line.c get_next_line_utils.c ft_free_list.c 
BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstdelone.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c

OBJS	=	${SRCS:.c=.o}

BONOBJS	=	${BONUS:.c=.o}

CC		=	@gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror 
	
NAME	=	libft.a

$(NAME)	:	${OBJS} 
			ar rcs ${NAME} ${OBJS}
			
all		:	$(NAME)

clean	:	
			${RM} ${OBJS} ${BONOBJS}

fclean	:
			$(RM) $(NAME)

re		:	fclean all 

bonus	:	${OBJS} ${BONOBJS}		
			ar rcs ${NAME} ${OBJS} ${BONOBJS}

.PHONY	:	all clean fclean re bonus

.SILENT	:	clean fclean