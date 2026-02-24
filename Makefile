NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext -lmlx

SRC = fractol.c utils/math.c init/init.c init/render.c events/keys.c utils/ft_atodb.c init/setlogic.c
OBJ = $(SRC:.c=.o) 


LIBFT_DIR = libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR) 
all: $(NAME)
$(OBJ): fractol.h

$(NAME): $(LIBFT_LIB)  $(OBJ)
	@echo "=====\n Creating fractol you will regret it \n====="
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME) 
	@echo "=====\n Never gonna give u up, never gonna let u down. Never gonna run around and create fractols!\n====="


$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) --no-print-directory

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory clean
	@echo "=====\n 🧹 The directory got cleaned, no more object files 🧹 \n ====="

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) --no-print-directory fclean
	@echo "====\n 🕯️ The directory was Purged🕯️ \n====="

re: fclean all

libs: $(LIBFT_LIB)

.PHONY: all clean fclean re libs
