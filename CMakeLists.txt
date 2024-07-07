cmake_minimum_required(VERSION 3.10)
project(octoray)

# Définir les répertoires des sources et des en-têtes
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Définir les sources
set(SOURCES ${SRC_DIR}/main.cpp)  # Ajoutez ici toutes vos sources

# Ajouter l'exécutable
add_executable(octoray ${SOURCES})

# Lier les bibliothèques pour libnx
if(TARGET_SWITCH)
    message(STATUS "Configuring for Nintendo Switch with libnx")

    # Définir le chemin vers devkitPro
    set(DEVKITPRO $ENV{DEVKITPRO})
    set(DEVKITA64 ${DEVKITPRO}/devkitA64)
    set(LIBNX ${DEVKITPRO}/libnx)

    # Ajouter le compilateur et les outils de devkitA64 au chemin
    set(CMAKE_C_COMPILER ${DEVKITA64}/bin/aarch64-none-elf-gcc)
    set(CMAKE_CXX_COMPILER ${DEVKITA64}/bin/aarch64-none-elf-g++)
    set(CMAKE_ASM_COMPILER ${DEVKITA64}/bin/aarch64-none-elf-as)

    # Définir les drapeaux de compilation
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall -std=gnu++11")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -specs=${LIBNX}/switch.specs -lnx")

    # Définir les répertoires d'inclusion et de lien
    include_directories(${LIBNX}/include)
    link_directories(${LIBNX}/lib)

    # Lier les bibliothèques
    target_link_libraries(octoray nx GL GLU glut)

else()
    # Lier les bibliothèques pour Linux ou Windows
    if (WIN32)
        set(CMAKE_SYSTEM_NAME Windows)
        set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
        set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
        set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

        # Ajoutez l'option -mwindows pour indiquer que l'application est une GUI Windows
        add_link_options(-mwindows)
        
        target_link_libraries(octoray glu32 opengl32 freeglut)
    else()
        # Préciser l'utilisation de GLVND
        set(OpenGL_GL_PREFERENCE GLVND)

        find_package(OpenGL REQUIRED)
        find_package(GLUT REQUIRED)

        include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
        target_link_libraries(octoray ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
    endif()
endif()
