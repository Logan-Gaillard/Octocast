cmake_minimum_required(VERSION 3.10)
project(octoray)

# Définir les répertoires des sources et des en-têtes
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Définir les sources
set(SOURCES ${SRC_DIR}/main.cpp)  # Ajoutez ici toutes vos sources

# Ajouter l'exécutable
add_executable(octoray ${SOURCES})

# Lier les bibliothèques
if (WIN32)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

    # Ajoutez l'option -mwindows pour indiquer que l'application est une GUI Windows
    add_link_options(-mwindows)
    
    target_link_libraries(octoray glu32 opengl32 freeglut)
else ()
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
    target_link_libraries(octoray ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif ()