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

set(DST ${PROJECT_NAME})
set(DEBUG_FLAGS "-g -Wall -Wextra")
set(BUILD_FLAGS "-Wall -Wextra -Werror")

set(SRC_DIR ${PROJECT_SOURCE_DIR}/srcs/)
set(INC_DIR ${PROJECT_SOURCE_DIR}/incs/)

set(MLX_DIR ${PROJECT_SOURCE_DIR}/minilibx/)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/libft/)

set(COMMON_SOURCES
	${SRC_DIR}fdf.c
	${SRC_DIR}utilities.c
	${SRC_DIR}init.c
	${SRC_DIR}read_file.c
	${SRC_DIR}drawing.c
	${SRC_DIR}draw_line.c
	${SRC_DIR}rotation_matrix.c
	${SRC_DIR}color.c
	${SRC_DIR}draw_window.c
	${SRC_DIR}projection.c)

if (${CMAKE_SYSTEM} MATCHES "Linux")
	set(SOURCES
		${COMMON_SOURCES}
		${SRC_DIR}key_handler_linux.c)
	set(LIBS
		"mlx"
		"libft"
		"Xext"
		"X11"
		"m")
elseif (${CMAKE_SYSTEM} MATCHES "Darwin")
	set(SOURCES
		${COMMON_SOURCES}
		${SRC_DIR}key_handler_mac_os.c)
	set(LIBS
		"mlx"
		"libft"
		"-framework OpenGL"
		"-framework AppKit")
endif ()

add_subdirectory(${LIB_DIR})
add_custom_target(
	libmlx
	COMMAND make
	WORKING_DIRECTORY ${MLX_DIR})

add_executable(${DST} ${SOURCES})
target_include_directories(${DST} PUBLIC 
		${INC_DIR}
		${LIB_DIR}incs/ 
		${MLX_DIR})
target_link_directories(${DST} PUBLIC ${MLX_DIR} ${LIB_DIR})
target_link_libraries(${DST} ${LIBS})
add_dependencies(${DST} libmlx libft)
set_target_properties(${DST} PROPERTIES
		COMPILE_FLAGS ${BUILD_FLAGS}
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(debug ${SOURCES})
target_include_directories(debug PUBLIC ${INC_DIR} ${LIB_DIR}incs/)
target_link_directories(debug PUBLIC ${LIB_DIR})
target_link_libraries(debug ${LIBS})
set_target_properties(debug PROPERTIES
		COMPILE_FLAGS ${DEBUG_FLAGS}
		COMPILE_DEFINITIONS DEBUG
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
