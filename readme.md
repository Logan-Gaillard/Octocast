# Octoray
## Introduction

Octoray est une appli encore en développement et non fonctionnel pour le moment !!!

Octoray est un moteur de jeu libre avec la méthode du ray-casting tournant sur SDL2 compatible avec Linux et Windows.

## Compiler

Les prérequis :
**MinGW**, **Freeglut**, **cmake**, **pkg-config** et **Les applications essentielles**
> sudo apt install build-essential cmake mingw-w64 pkg-config freeglut3-dev 

(Pour Windows, cloner le git https://github.com/freeglut/freeglut et lisez README.mingw_cross pour suivre les étapes d'installation)

Pour accéder au moteur de jeu, il faudra tout d'abords clone cette repo.
Ensuite vous avez simplement à vous rendre sur le dossier du repo et entrer cette commande :

**Linux**
> make linux

**Windows**
> make windows

Si vous voulez immédiatement le lancer, vous pouvez faire cette commande :
> sh run.sh

## Crédits
Applications :  
- [Freeglut](https://github.com/freeglut/freeglut)  

Développeur :  
- Gaillard Logan
