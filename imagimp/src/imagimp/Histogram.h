#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdio.h>
#include <stdlib.h>

#include "Image.h"

/* Définir le type d'histogramme */
typedef enum {
	RED,
	BLUE,
	GREEN,
	AVERAGE
} Histogram_Type;

/* Définir un histogramme */
typedef struct {
	Histogram_Type type;
	unsigned int nbPixels[256];
} Histogram;

/* Créer un histogramme vide */
Histogram * initHisto(Histogram_Type type);

/* Créer l'histogramme rouge */
Histogram * createRedHisto(Image *img);

/* Créer l'histogramme vert */
Histogram * createGreenHisto(Image *img);

/* Créer l'histogramme bleu */
Histogram * createBlueHisto(Image *img);

/* Créer l'histogramme RGB (luminance) */
Histogram *createRGBHisto(Image *img);


#endif