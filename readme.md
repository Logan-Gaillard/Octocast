# IMPORTANT
Actuellement je suis dubitatif en rapport de l'utilisation avec SDL.  
Car j'aurais bien pu choisir OpenGL qui est beaucoup plus utilisé et plus facile à gérer  
Je pense déjà en premier lieu à l'intégration des fonctionnalités et OpenGL intègre lui-même SDL  
Je pense que je vais plutôt important dans mon projet OpenGL, ce qui va me permettre également gagner du temps et d'optimisations.    
Et j'utiliserai le SDL intégré pour gérer les contrôleurs (Manettes, Claviers/souris, etc...)  

D'ailleurs, j'ai remarqué que SDL supporte très bien les contrôleurs Nintendo Switch, ça sera l'occasion de tester.  
Aller, c'est parti pour tout changer re se relire des docs 🤡  


# Octoray
## Introduction

Octoray est une appli encore en développement et non fonctionnelle pour le moment !!!

Octoray est un moteur de jeu libre avec la méthode du ray-casting tournant sur SDL2 compatible avec Linux et Windows.

## Compiler

Les prérequis :
**MinGW** (Pour une compilation vers Windows) optionnel pour Linux
> sudo apt install gcc-mingw-w64

Pour accéder au moteur de jeu, il faudra tout d'abord cloner cette repo.
Ensuite, vous avez simplement à vous rendre dans le dossier du repo et entrer cette commande :

**Linux**
> make linux

**Windows**
> make windows

Si vous voulez le lancer immédiatement, vous pouvez exécuter cette commande :
> sh run.sh

## Crédits
Applications :  
- [SDL](https://github.com/libsdl-org/SDL)  
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)  
- [SDL_image](https://github.com/libsdl-org/SDL_image)  

Développeur :  
- Gaillard Logan
