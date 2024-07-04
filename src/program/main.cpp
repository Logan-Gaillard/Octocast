#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <iostream>

#include "program/main.h"

using namespace std;

SDL_Window* window = NULL;

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;

//Cette fonction charge une image depuis un fichier
SDL_Surface *load_image_png(const string& filename) {
  // L'image chargée
  SDL_Surface *loadedImage = NULL;

  // L'image optimisée qui sera utilisée
  SDL_Surface* optimizedImage = NULL;

  // Load the image using SDL_image
  loadedImage = IMG_Load(filename.c_str());

  // If the image is loaded correctly
  if (loadedImage != nullptr) {
    
    // Create the optimized image
    optimizedImage = SDL_ConvertSurfaceFormat(loadedImage, SDL_PIXELFORMAT_ARGB8888, 0);

    // Free the old image
    SDL_FreeSurface(loadedImage);
  }

  return optimizedImage;
}

//Afficher l'image une image sur l'écran
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  //On "colle" l'image à la surface 
  SDL_BlitSurface(source, clip, destination, &offset);
}

bool init(){
  //Initioalisation de SDL et de ces sous-système
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    return false;
  }

  //On met la fenetre en place
  window = SDL_CreateWindow("Octoray", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  //Si il y a une erreur avec la fenetre
  if(window == NULL){
    return false;
  }

  //On met le titre de la fenetre
  SDL_SetWindowTitle(window, "Octoray");

  //On crée la surface de l'écran
  screen = SDL_GetWindowSurface(window);

  return true;
}

bool load_files(){
  //On charge l'image de fond
  background = load_image_png("./background.png");

  //Si il y a une erreur avec l'image de fond
  if(background == NULL){
    return false;
  }

  message = load_image_png("./message.png");

  //Si il y a une erreur avec le message
  if(message == NULL){
    return false;
  }

  return true;
}

void clean_up(){
  //On libère la surface de l'écran
  SDL_FreeSurface(background);
  SDL_FreeSurface(message);

  //On détruit la fenetre
  SDL_DestroyWindow(window);

  //On quitte SDL
  SDL_Quit();
}

#ifdef _WIN32
int WinMain(int argc, char* argv[])
#else
int main(int argc, char* argv[])
#endif
{
  std::cout << "Hello, World!" << std::endl;
  if(init() == false){
    std::cout << "Erreur d'écran" << std::endl;
    return 1;
  }

  //chargement des fichiers
  if(load_files() == false){
    std::cout << "Erreur de chargement des fichiers" << std::endl;
    return 1;
  }

  //On applique l'image de fond
  apply_surface(0, 0, background, screen);
  apply_surface(220, 200, message, screen);

  //Mise à jour de l'écran
  SDL_UpdateWindowSurface(window);

  while(true){
    SDL_Event event;

    //On attend un évènement
    SDL_WaitEvent(&event);

    //Si l'évènement est de type QUIT
    if(event.type == SDL_QUIT){
      break;
    }
  }

  clean_up();

  return 0;
}