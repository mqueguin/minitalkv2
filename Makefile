# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 12:30:22 by mqueguin          #+#    #+#              #
#    Updated: 2021/09/27 13:11:11 by mqueguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \x1b[32m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m
CYAN = \x1b[36m

SRCS_CLIENT			=	srcs/client.c\
					srcs/check_pid.c

SRCS_SERVER			=	srcs/server.c

SRCS_CLIENT_BONUS	=	srcs/client_bonus.c\
				srcs/check_pid.c

SRCS_SERVER_BONUS	=	srcs/server_bonus.c

DIR_HEAD			=	includes/

DIR_LIBFT			=	libft/

INCLUDES			=	${DIR_LIBFT}libft.h ${DIR_HEAD}minitalk.h

OBJS_CLIENT			=	${SRCS_CLIENT:.c=.o}
OBJS_SERVER			=	${SRCS_SERVER:.c=.o}
OBJS_CLIENT_BONUS	=	${SRCS_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS	=	${SRCS_SERVER_BONUS:.c=.o}

NAME_CLIENT			=	client
NAME_SERVER			=	server
NAME_CLIENT_BONUS	=	client_Bonus
NAME_SERVER_BONUS	=	server_Bonus

LIBFT				=	libft/libft.a
CC					=	gcc
RM					=	rm -rf
FLAGS				=	-Wall -Werror -Wextra -g

.c.o:
				@${CC} ${FLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}
				@echo "${GREEN}${BOLD}[ OK ]${END} ${CYAN}${<:.s=.o}${END}"

all:		${NAME_CLIENT}

bonus:		${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

${NAME_CLIENT_BONUS}:	${OBJS_CLIENT_BONUS}
			@make -C ${DIR_LIBFT}
			@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_CLIENT_BONUS} ${OBJS_CLIENT_BONUS} ${LIBFT}
			@echo "\n\t\t${BOLD}${GREEN}Client_Bonus	has been created !${END}${END}\n"

${NAME_SERVER_BONUS}:	${OBJS_SERVER_BONUS}
			@make -C ${DIR_LIBFT}
			@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_SERVER_BONUS} ${OBJS_SERVER_BONUS} ${LIBFT}
			@echo "\n\t\t${BOLD}${GREEN}Server_Bonus	has been created !${END}${END}\n"

${NAME_CLIENT}:	${NAME_SERVER} ${OBJS_CLIENT}
			@make -C ${DIR_LIBFT}
			@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_CLIENT} ${OBJS_CLIENT} ${LIBFT}
			@echo "\n\t\t${BOLD}${GREEN}Client	has been created !${END}${END}\n"


${NAME_SERVER}:	${OBJS_SERVER}
			@make -C ${DIR_LIBFT}
			@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_SERVER} ${OBJS_SERVER} ${LIBFT}
			@echo "\n\t\t${BOLD}${GREEN}Server	has been created !${END}${END}\n"

clean:
			@make -C ${DIR_LIBFT} clean
			@${RM} ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS_CLIENT_BONUS} ${OBJS_SERVER_BONUS}

fclean:		clean
			@make -C ${DIR_LIBFT} fclean
			@${RM} ${NAME_CLIENT} ${NAME_CLIENT_BONUS} ${NAME_SERVER} ${NAME_SERVER_BONUS} ${LIBFT}
			@echo "${GREEN}[ OK ]${END} ${RED} Client and Server has been deleted${END}"

re:			fclean all

.PHONY:		all clean fclean re
