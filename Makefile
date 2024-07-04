# Définir la cible par défaut
.DEFAULT_GOAL := linux

# Dossiers
BUILD_DIR = builds

# Options de compilation
CFLAGS = -I includes -I includes/program -I includes/images

# Source
SRCS = src/program/main.cpp

# Règle pour créer le dossier builds si nécessaire
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Règle par défaut pour Linux
linux: $(BUILD_DIR)
	g++ $(CFLAGS) -o $(BUILD_DIR)/main $(SRCS) `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -static-libgcc -static-libstdc++

# Règle pour Windows
windows: $(BUILD_DIR)
	x86_64-w64-mingw32-g++ $(CFLAGS) -o $(BUILD_DIR)/main.exe $(SRCS) -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -static-libgcc -static-libstdc++ -mwindows

# Règle pour tout nettoyer
clean:
	rm -rf $(BUILD_DIR)
