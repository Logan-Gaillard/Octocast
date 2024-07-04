#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>

#include "program/main.h"

using namespace std;

SDL_Window* window = NULL;

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *message2 = NULL;

SDL_Surface *kUp = NULL, *kDown = NULL, *kLeft = NULL, *kRight = NULL;

//Police d'écriture
TTF_Font *font;

SDL_Event event;

//Couleur de la police
SDL_Color textColor = {255, 255, 255};

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

  if(TTF_Init() == -1){
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

  //On charge la police d'écriture
  font = TTF_OpenFont("./Roboto.ttf", 40);

  //Si il y a une erreur avec la police
  if(font == NULL){
    return false;
  }

  return true;
}

void clean_up(){
  //On libère la surface de l'écran
  SDL_FreeSurface(background);
  SDL_FreeSurface(message);
  SDL_FreeSurface(message2);

  SDL_FreeSurface( kUp );
  SDL_FreeSurface( kDown );
  SDL_FreeSurface(kLeft);
  SDL_FreeSurface(kRight);
  
  TTF_CloseFont(font);

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
  std::cout << "Lancement..." << std::endl;
  bool exit = false;

  if(init() == false){
    std::cout << "Erreur lors que l'initialisation de SDL" << std::endl;
    return 1;
  }

  //chargement des fichiers
  if(load_files() == false){
    std::cout << "Erreurs lors du chargement des fichiers" << std::endl;
    return 1;
  }

  message = TTF_RenderText_Solid( font, "OctoRay.", textColor );
  kUp = TTF_RenderText_Solid( font, "Haut a ete pressee.", textColor );
  kDown = TTF_RenderText_Solid( font, "Bas a ete pressee.", textColor );
  kLeft = TTF_RenderText_Solid( font, "Gauche a ete pressee.", textColor );
  kRight = TTF_RenderText_Solid( font, "Droite a ete pressee.", textColor );

  if(message==NULL || kUp==NULL || kDown==NULL || kLeft==NULL || kRight==NULL){
    std::cout << "Erreurs lors de l'écriture" << std::endl;
    return 1;
  }
  

  while(true){   
    //On attend un évènement
    SDL_WaitEvent(&event);

    //Si l'évènement est de type QUIT
    if(event.type == SDL_QUIT){
      break;
    }else if(event.type == SDL_KEYDOWN){
      std::cout << "Touche pressée" << event.key.keysym.sym << std::endl;
      switch(event.key.keysym.sym){
        case SDLK_UP:
          message2 = kUp;
          break;
        case SDLK_DOWN:
          message2 = kDown;
          break;
        case SDLK_LEFT:
          message2 = kLeft;
          break;
        case SDLK_RIGHT:
          message2 = kRight;
          break;
      }
    }

    apply_surface(0, 0, background, screen);
    apply_surface(( SCREEN_WIDTH - message->w ) /2, ( SCREEN_HEIGHT - message->h ) /2, message, screen);

    if(message2 != NULL){
      apply_surface(( SCREEN_WIDTH - message2->w ) /2, 250, message2, screen);
      message2 = NULL;
    }

    //Mise à jour de l'écran
    SDL_UpdateWindowSurface(window);
  }

  clean_up();

  return 0;
}