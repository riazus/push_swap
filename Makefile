NAME		=	push_swap

SRCS_F		=	main.c			\
				list.c			\
				list_sort.c		\
				list_u1.c		\
				list_u2.c		\
				check.c			\
				init.c			\
				case.c			\
				algo_short.c	\
				algo_bigger.c	\
				norm.c			\
				get.c			\
				op_p.c			\
				op_r.c			\
				op_s.c

SRCS_D		=	srcs/

SRCS		=	$(addprefix $(SRCS_D), $(SRCS_F))

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include/	-I libft

HEADER		=	include/push_swap.h

RM			=	 rm -rf



$(NAME)		:	$(OBJS) $(HEADER)
				@$(MAKE) -C $(dir $(LIBFT))
				@$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)
#				@$(RM) *.o

all			:	$(NAME)

%.o			:	%.c $(HEADER)
				@$(CC) $(CFLAGS) -c $< -o $@ 

clean		:	
				@$(MAKE) clean -C $(dir $(LIBFT))
				@$(RM) $(OBJS)

fclean		:	clean
				@$(MAKE) fclean -C $(dir $(LIBFT))
				@$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re