# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/02 16:27:31 by sxhondo           #+#    #+#              #
#    Updated: 2020/03/02 16:27:33 by sxhondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 2.8)

project (fdf)
# "-Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c"

set(DST ${PROJECT_NAME})
set(BUILD_FLAGS "-Wall -Wextra -Werror")


set(SRC_DIR ${PROJECT_SOURCE_DIR}/srcs/)
set(INC_DIR ${PROJECT_SOURCE_DIR}/incs/)

set(MLX_DIR ${PROJECT_SOURCE_DIR}/minilibx/)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/libft/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/)

add_executable(${DST}
	${SRC_DIR}main.c
)
target_include_directories(${DST} PUBLIC ${INC_DIR})

add_custom_target(
	libmlx
	COMMAND make
	WORKING_DIRECTORY ${MLX_DIR}
)
target_include_directories(${DST} PUBLIC ${MLX_DIR})

add_subdirectory(${LIB_DIR})
target_include_directories(${DST} PUBLIC ${LIB_DIR}incs/)
target_link_directories(${DST} PUBLIC ${LIB_DIR})

target_link_libraries(${DST}
	"mlx"
	"libft"
	"-framework OpenGL" 
	"-framework AppKit"
    )

add_dependencies(${DST} 
	mlx
	libft)
