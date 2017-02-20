#ifndef IHM_H
#define IHM_H

#include "Histogram.h"

char *letter(keyboard Key, char letter_entry[255] );

/*transforme un chiffre int en char*/
char *digit(int digit);

/*transforme un nombre int en char*/
char *number(int number, char number_string[5]);

/*affiche les informations sur l'image*/
void drawInfoImg();

/*affiche les informations sur le calque*/
void drawInfoLayout();

/*dessine un histogramme*/
void drawHistogram(Histogram *histogram);

/*dessine les boutons de choix du type d'histogramme*/
void drawButtonHisto();

/*dessine l'interface*/
void drawInterface();


#endif
