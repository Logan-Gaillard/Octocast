set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)

set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Ajoutez ici les chemins spécifiques pour les bibliothèques MinGW
list(APPEND CMAKE_LIBRARY_PATH "/usr/x86_64-w64-mingw32/lib")

# Définissez les options de compilation spécifiques à MinGW si nécessaire
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")