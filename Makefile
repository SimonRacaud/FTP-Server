##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES	=	main.c					\
				usage.c					\
				commands/commands.c		\
				app/arg_parser.c		\
				app/app_destroy.c		\
				app/app_init.c			\
				app/app_loop.c			\
				app/account.c			\
				app/signal_init.c		\
				socket/socket_send.c			\
				socket/socket_client_connect.c	\
				socket/socket_close.c			\
				socket/socket_receive.c			\
				socket/socket_server_connect.c	\
				socket/socket_server_create.c	\
				socket/socket_server_select.c	\
				server/client/connection_create.c		\
				server/client/connection_destroy.c		\
				server/client/connection_list_push.c	\
				server/client/connection_list_destroy.c	\
				server/client/connection_list_remove.c	\
				server/dchannel/dchannel_create.c			\
				server/dchannel/dchannel_destroy.c			\
				server/dchannel/dchannel_list_add.c			\
				server/dchannel/dchannel_list_destroy.c		\
				server/dchannel/dchannel_list_remove.c		\
				server/dchannel/dchannel_list_clean.c		\
				server/dchannel/dchannel_get_free_channel.c	\
				server/dchannel/dchannel_prepare.c			\
				server/dchannel/server_dchannel_requests_process.c	\
               	server/server_create.c						\
               	server/server_destroy.c						\
               	server/server_client_manager.c				\
               	server/server_client_requests_process.c		\
               	server/server_connect_client.c				\
               	server/server_execute_cmd.c					\
               	server/request/cmd_create.c					\
               	server/request/cmd_destroy.c				\
               	server/request/get_request.c				\
               	server/response/send_response.c				\
               	server/response/send_raw_message.c			\
				server/response/response.c					\
				utility/edit_dirpath.c						\
				utility/str_to_upper.c						\
				utility/is_empty.c							\
				utility/find_newline.c						\
				utility/strconcat.c						\
				commands/command_help.c						\
				commands/command_noop.c						\
				commands/command_pass.c						\
				commands/command_quit.c						\
				commands/command_user.c						\
				commands/command_cdup.c						\
				commands/command_cwd.c						\
				commands/command_pwd.c						\
				commands/command_dele.c						\
				commands/command_port.c						\
				commands/command_pasv.c						\

SRC	=	$(addprefix $(DSRC), $(SRC_FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	+= -Wall -Wextra -W $(INCLUDE) #-Werror

INCLUDE = -I./include

debug: CFLAGS += -g
debug: all

all:  $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	rm -f  $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#	gcc -o $(NAME) $(SRC_UT) -I./include -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LINE_RETURN	=	$(ECHO) ""
