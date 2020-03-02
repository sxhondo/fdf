# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 16:26:49 by sxhondo           #+#    #+#              #
#    Updated: 2020/03/02 16:26:59 by sxhondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CMAKE_DIR = ./cmake-build/

all: $(NAME)

$(NAME): cmake

cmake: $(CMAKE_DIR) $(CMAKE_DIR)Makefile
		$(MAKE) -C $(CMAKE_DIR)

$(CMAKE_DIR):
	mkdir -p $(CMAKE_DIR)

$(CMAKE_DIR)Makefile:
	cd $(CMAKE_DIR) && cmake ../

clean:
	$(MAKE) clean -C minilibx 
	rm -rf $(CMAKE_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
