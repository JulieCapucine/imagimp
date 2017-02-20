#ifndef LAYOUT_H
#define LAYOUT_H

#include <stdio.h>
#include <stdlib.h>

#include "LUT.h" 
#include "Image.h"

/* Définir le mode de fusion d'un calque */
typedef enum {
	ADDITION,
	MULTIPLICATION
} Layout_Mode;

/* Définir un calque */
typedef struct Layout {
	int position;
	struct Layout *next;
	struct Layout *prev;
	Image *img; // Image finale du calque, une fois les LUT appliquées à l'image source
	Image *src; // Image source
	Layout_Mode mode;
	float opacity;
	LUT *luts;
} Layout;

/* Initialiser un calque avec une image source blanche */
Layout * initLayout();

/* Créer le premier calque de l'application */
Layout * createCanvas(char *fileName);

/* Ajouter un calque au canevas
Retourne le calque ajouté */
Layout * addLayout(Layout *firstLayout);

void freeLayout(Layout *layout);

/* Libérer la mémoire allouée à un calque */
void freeCanvas(Layout *firstLayout);

/* Ajouter une image à un calque
Ecrase l'image actuelle du calque (s'il y en a)
Retourne 0 si l'image n'a pas pu être ajoutée, retourne -1 si l'image n'est pas aux bonnes dimensions */
int addImageOnLayout(Layout *layout, char* fileName);

/* Changer l'opacité d'un calque */
void changeOpacity(Layout *layout, float opacity);

/* Changer le mode de fusion d'un calque */
void changeMode(Layout *layout);

/* Afficher les informations sur les calques du canevas */
void printCanvas(Layout *firstLayout, Layout *currentLayout);

/* Afficher les informations sur l'image actuelle */
void printCurrentImageInfo(Layout *currentLayout);

/* Changer de calque courant
layoutPosition correspond au calque souhaité */
Layout * changeCurrentLayout(Layout *firstLayout, unsigned int layoutPosition);

/* Passer au calque précédent */
int changeToPrevLayout(Layout **currentLayout);

/* Passer au calque suivant */
int changeToNextLayout(Layout **currentLayout);

/* Supprimer le calque courant
Retourne le calque précédent ou le premier calque, si le calque supprimé était le premier */
Layout * deleteLayout(Layout **firstLayout, Layout *currentLayout);

/* Appliquer une LUT à une image */
void applyLUTOnImage(Image *img, LUT *lut);

/* Appliquer toutes les LUT d'un calque à son image source
Utilise la combinaison de LUT */
void applyAllLUTOnImage(Layout *currentLayout);

/* Ajouter une LUT à un calque */
void addLUTOnLayout(Layout *currentLayout, LUT_Type type);

/* Supprimer la dernière LUT ajoutée au calque courant */
void deleteLUT(Layout *currentLayout);

/* Calculer l'image finale */
Image * calculateFinalImage(Layout *firstLayout);

#endif