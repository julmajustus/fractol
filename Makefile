# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 16:11:30 by jmakkone          #+#    #+#              #
#    Updated: 2024/07/23 22:39:49 by jmakkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME            = fractol
LIBFT_DIR       = ./libft
MLX42_DIR       = ./MLX42
SRC_DIR         = src
SRC_BONUS_DIR   = src_bonus
INC_DIR         = includes

SRC             = $(SRC_DIR)/main.c \
                  $(SRC_DIR)/window_init.c \
                  $(SRC_DIR)/validate_input.c \
                  $(SRC_DIR)/fractol_init.c \
                  $(SRC_DIR)/fractol_render.c \
                  $(SRC_DIR)/calculate_view_changes.c \
                  $(SRC_DIR)/set_colors.c \
                  $(SRC_DIR)/randomize_colors.c \
                  $(SRC_DIR)/controls_keyboard.c \
                  $(SRC_DIR)/controls_mouse.c \
                  $(SRC_DIR)/error_handler.c \
                  $(SRC_DIR)/exit_handler.c

SRC_BONUS       = $(SRC_BONUS_DIR)/main_bonus.c \
                  $(SRC_BONUS_DIR)/window_init_bonus.c \
                  $(SRC_BONUS_DIR)/validate_input_bonus.c \
                  $(SRC_BONUS_DIR)/fractol_init_bonus.c \
                  $(SRC_BONUS_DIR)/fractol_render_bonus.c \
                  $(SRC_BONUS_DIR)/calculate_view_changes_bonus.c \
                  $(SRC_BONUS_DIR)/set_colors_bonus.c \
                  $(SRC_BONUS_DIR)/randomize_colors_bonus.c \
                  $(SRC_BONUS_DIR)/controls_keyboard_bonus.c \
                  $(SRC_BONUS_DIR)/controls_mouse_bonus.c \
                  $(SRC_BONUS_DIR)/error_handler_bonus.c \
                  $(SRC_BONUS_DIR)/exit_handler_bonus.c \
                  $(SRC_BONUS_DIR)/draw_multibrot.c

OBJ_DIR         = obj
OBJ             = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS       = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT           = $(LIBFT_DIR)/libft.a
LIBMLX42        = $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

RM              = rm -f
CC              = cc
CFLAGS          = -Wunreachable-code -Ofast -Wall -Wextra -Werror \
				  -I$(INC_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(MLX42_DIR)/include/$(MLX42_DIR)


all:  $(LIBFT) $(LIBMLX42) $(NAME)
bonus: $(LIBFT) $(LIBMLX42) .bonus

# Build library targets
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX42):
	@if [ ! -d $(MLX42_DIR) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git \
		$(MLX42_DIR); \
	fi
	@if [ ! -f $(MLX42_DIR)/build/libmlx42.a ]; then \
		cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && \
		cmake --build $(MLX42_DIR)/build -j$(shell nproc); \
	fi

# Object file compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(INC_DIR)/*.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Targets

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBMLX42) $(LIBFT) -o $(NAME)

.bonus: $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBMLX42) $(LIBFT) -o $(NAME)
	@touch .bonus


# Clean targets
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)
	$(RM) .bonus

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(MLX42_DIR)/build

re: fclean all

.PHONY: all clean fclean re bonus
