cmake_minimum_required(VERSION 3.30)
# src list collision

set(MY_COLLISION_NAME collision_src)

set(MY_COLLISION_INCLUDE 
    headers/camera.h
	headers/shader.h
	headers/collision_cube.h
	headers/collision_plane.h
	)
	
set(MY_COLLISION_SRC 
    sources/camera.cpp
	sources/shader.cpp
	sources/collision_cube.cpp
	sources/collision_plane.cpp
	)

set(MY_COLLISION_TXT
    txt/shader_vs.txt
	txt/shader_fs.txt
	)	
	
	
set(ALL_MY_COLLISION_SRC 
    ${MY_COLLISION_INCLUDE} 
    ${MY_COLLISION_SRC} 
    ${MY_COLLISION_TXT}
    )	

add_library(${MY_COLLISION_NAME} STATIC ${ALL_MY_COLLISION_SRC})

target_include_directories(${MY_COLLISION_NAME} PUBLIC headers)
target_include_directories(${MY_COLLISION_NAME} PUBLIC sources)
target_include_directories(${MY_COLLISION_NAME} PUBLIC txt)

add_subdirectory(../libs/GLAD ${CMAKE_CURRENT_BINARY_DIR}/GLAD)
target_link_libraries(${MY_COLLISION_NAME} PUBLIC GLAD)

add_subdirectory(../libs/GLFW ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${MY_COLLISION_NAME} PUBLIC glfw)

add_subdirectory(../libs/GLM ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${MY_COLLISION_NAME} PUBLIC glm)