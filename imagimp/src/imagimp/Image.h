#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#define MAX_SIZE 255 // Taille maximale du buffer utilisé pour lire dans un fichier

/* Définir le type d'une image */
typedef enum {
	COLOR,
	BLACK_WHITE
} Image_Type;

/* Définir une image */
typedef struct {
	unsigned int w;
	unsigned int h;
	Image_Type type;
	uint8_t *pixels;
} Image;

/* Allouer une image et mettre les composants de tous les pixels à 255 (image blanche) */
Image * initImage(unsigned int w, unsigned int h, Image_Type type);

/* Libérer la mémoire allouée à une image */
void freeImage(Image *img);

/* Lire une image PPM */
Image * readPPM(char *fileName);

/* Réaliser une copie de l'image img */
Image * imageCopy(Image *img);

/* Retourner une image pour qu'elle soit dans le bon sens
Remplir les 3 composants d'une image BLACK_WHITE */
void returnImage(Image *img);

void savePPM(Image *img, char *fileName);

#endif
