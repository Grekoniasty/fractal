NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = ft_putchar_fd.c ft_bzero.c ft_memmove.c ft_tolower.c ft_calloc.c ft_memset.c ft_toupper.c ft_substr.c \
      ft_isalnum.c ft_strchr.c ft_itoa.c ft_strlen.c ft_isalpha.c ft_strdup.c ft_memchr.c ft_striteri.c \
      ft_strjoin.c ft_isascii.c ft_strlcat.c ft_memcmp.c ft_strmapi.c ft_isdigit.c ft_strlcpy.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_isprint.c ft_strncmp.c ft_putstr_fd.c ft_atoi.c ft_memcpy.c \
      ft_strnstr.c ft_split.c ft_strtrim.c ft_strrchr.c
OBJ = $(SRC:.c=.o)

SRCB = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(OBJB)

re: fclean all

bonus: $(OBJ) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
