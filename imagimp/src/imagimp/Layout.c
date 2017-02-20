#include "Layout.h"

Layout * createCanvas(char *fileName) {
	Image *img = readPPM(fileName);
	if (img == NULL) return NULL;

	Layout *l = malloc(1*sizeof(Layout));
	l->position = 0;
	l->next = l->prev = NULL;
	l->src = img;
	l->img = imageCopy(img); // On utilise une copie de l'image source pour ne pas modifier l'image source lorsqu'on modifie l'image transformée
	l->mode = ADDITION;
	l->opacity = 1;
	l->luts = NULL;

	return l;
}

Layout * initLayout(unsigned int w, unsigned int h) {
	Layout *l = malloc(1*sizeof(Layout));
	l->position = -1;
	l->next = NULL;
	l->prev = NULL;
	l->src = initImage(w, h, COLOR);
	l->img = initImage(w, h, COLOR);
	l->mode = MULTIPLICATION;
	l->opacity = 0;
	l->luts = NULL;

	return l;
}

void freeLayout(Layout *layout) {
	if (layout == NULL)
		return;

	freeImage(layout->src);
	freeImage(layout->img);
	layout->src = layout->img = NULL;
	layout->next = layout->prev = NULL;
	free(layout);
}

void freeCanvas(Layout *firstLayout) {
	if (firstLayout == NULL)
		return;

    Layout *next = firstLayout;
    while (next != NULL) {
    	Layout *toFree = next;
    	next = toFree->next;
    	freeLayout(toFree);
    }
    firstLayout = NULL;
}

// TODO : Fonctionne uniquement pour les images de la même taille que les autres...
// Soit, on controle que c'est la meme taille et on renvoie une erreur sinon == Ca pour le moment
// Soit on crée une fonction pour étirer l'image, ou la compresser
int addImageOnLayout(Layout *layout, char* fileName) {
	Image *img = readPPM(fileName);
	if (img == NULL) return 0;

	// On regarde si l'image est de la bonne taille
	if (img->w != layout->src->w || img->h != layout->src->h)
		return -1;
	layout->src = img;
	layout->img = imageCopy(img);

	// On supprime les LUT existantes
	LUT *next = layout->luts;
    while (next != NULL) {
    	LUT *toFree = next;
    	next = toFree->next;
    	free(toFree);
    }
    layout->luts = NULL;

	return 1;
}

void changeOpacity(Layout *layout, float opacity) {
	layout->opacity = opacity;
}

void changeMode(Layout *layout) {
	if (layout->mode == ADDITION)
		layout->mode = MULTIPLICATION;
	else
		layout->mode = ADDITION;
}

Layout * addLayout(Layout *firstLayout) {
	Layout *l = initLayout(firstLayout->src->w, firstLayout->src->h);

	// On se déplace jusqu'au dernier calque
	while (firstLayout->next != NULL)
		firstLayout = firstLayout->next;

	// Ajout du calque à la fin de la liste
	l->position = (firstLayout->position)+1;
	l->prev = firstLayout;
	firstLayout->next = l;

	return l;
}

Layout * changeCurrentLayout(Layout *firstLayout, unsigned int layoutPosition) {
	while (firstLayout->position != layoutPosition) {
		if (firstLayout->next == NULL)
			return NULL;
		firstLayout = firstLayout->next;
	}

	return firstLayout;
}

int changeToPrevLayout(Layout **currentLayout) {
	if ((*currentLayout)->prev == NULL) {
		return 0;
	}
	(*currentLayout) = (*currentLayout)->prev;
	return 1;
}

int changeToNextLayout(Layout **currentLayout) {
	if ((*currentLayout)->next == NULL) {
		return 0;
	}
	(*currentLayout) = (*currentLayout)->next;
	return 1;
}


Layout * deleteLayout(Layout **firstLayout, Layout *currentLayout) {
	Layout *returnLayout = currentLayout;

	if (currentLayout->prev == NULL && currentLayout->next == NULL) {
		return returnLayout;
	}
	else if (currentLayout->position == 0) {
		/* Cas où le calque courant est le premier
		Le suivant devient le premier et prend donc la position 0 */
		Layout *tmp = currentLayout;
		while (tmp->next != NULL) {
			tmp->next->position -= 1;
			tmp = tmp->next;
		}
		returnLayout = currentLayout->next;
		returnLayout->prev = NULL;
		*firstLayout = returnLayout; // Le premier élement de la liste de calque change...
	} else if (currentLayout->next == NULL) {
		/* Cas où le calque courant est le dernier
		Son précédent devient le dernier */
		currentLayout->prev->next = NULL;
		returnLayout = currentLayout->prev;
	} else {
		/* Cas où le calque courant est au milieu
		Il faut alors ensuite décaler d'1 la position de tous les calques suivants... */
		currentLayout->prev->next = currentLayout->next;
		currentLayout->next->prev = currentLayout->prev;
		returnLayout = currentLayout->next;
		while (currentLayout->next != NULL) {
			currentLayout->next->position -= 1;
			currentLayout = currentLayout->next;
		}
	}

	return returnLayout;
}

void printCurrentImageInfo(Layout *currentLayout) {
	printf("* Informations sur l'image *\n");
	printf("L'image appartient au calque %d.\n", currentLayout->position);
	printf("L'image est en ");
	if (currentLayout->img->type == COLOR) {
		printf("couleurs.\n");
	} else {
		printf("niveaux de gris.\n");
	}
	printf("Hauteur : %d - Largeur : %d\n\n", currentLayout->img->h, currentLayout->img->w);
}

void printCanvas(Layout *firstLayout, Layout *currentLayout) {
	Layout *tmpLayout = firstLayout;
	while (tmpLayout != NULL) {
		printf("Calque %d", tmpLayout->position);
		if (currentLayout->position == tmpLayout->position)
			printf(" - Calque courant\n");
		else printf("\n");
		printf("\tOpacité : %.2f\n", tmpLayout->opacity);
		(tmpLayout->mode == ADDITION) ? printf("\tMode : Addition\n"):printf("\tMode : Multiplication\n");
		printf("Luts : ");
		LUT *tmp = tmpLayout->luts;
		while (tmp != NULL) {
			switch(tmp->type) {
				case ADDLUM:
					printf("--> ADDLUM ");
					break;
				case DIMLUM :
					printf("--> DIMLUM ");
					break;
				case ADDCON :
					printf("--> ADDCON ");
					break;
				case DIMCON :
					printf("--> DIMCON ");
					break;
				case INVERT :
					printf("--> INVERT ");
					break;
				case SEPIA :
					printf("--> SEPIA ");
					break;
				default:
					break;
			}
			tmp = tmp->next;
		}
		printf("\n");

		tmpLayout = tmpLayout->next;
	}
	printf("\n");
}

void applyLUTOnImage(Image *img, LUT *lut) {
	int i;	
	unsigned int luminance;

	switch (lut->type) {
		case ADDLUM : case DIMLUM :
		case ADDCON : case DIMCON :
		case INVERT :
		case FINAL_LUT :
			for (i = 0; i < img->h*img->w*3; i++) {
				img->pixels[i] = lut->redValue[img->pixels[i]];
				i++;
				img->pixels[i] = lut->greenValue[img->pixels[i]];
				i++;
				img->pixels[i] = lut->blueValue[img->pixels[i]];
			}
			break;
		case SEPIA : // On applique la LUT grâce à la luminance
		case GRAYSCALE :
		case FINAL_LUT_LUM :
			for (i = 0; i < img->h*img->w*3; i += 3) {
				luminance = 0.2126*img->pixels[i] + 0.7152*img->pixels[i+1] + 0.0722*img->pixels[i+2];
				img->pixels[i] = lut->redValue[luminance];
				img->pixels[i+1] = lut->greenValue[luminance];
				img->pixels[i+2] = lut->blueValue[luminance];
			}
	}
	
}

void addLUTOnLayout(Layout *currentLayout, LUT_Type type) {
	LUT *lut = createLUT(type);
	if (lut == NULL) {
		printf("Erreur lors de la création de la LUT.\n");
		return;
	}


	if (currentLayout->luts == NULL) {
		currentLayout->luts = lut;
	} else {
		LUT *tmp = currentLayout->luts;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		lut->prev = tmp;
		tmp->next = lut;
	}

	// Application de la LUT à l'image
	applyLUTOnImage(currentLayout->img, lut);
}

void applyAllLUTOnImage(Layout *currentLayout) {
	LUT * finalLut = createLUT(FINAL_LUT); //TODO Créer un type 

	int luminance;

	LUT *tmp = currentLayout->luts;
	int i;
	while (tmp != NULL) {
		for (i = 0; i < 256; i++) {
			if (tmp->type == GRAYSCALE || tmp->type == SEPIA) {
				finalLut->type = FINAL_LUT_LUM; // Permet d'indiquer que la lut finale s'appliquera grâce à la luminance

				luminance = 0.2126*finalLut->redValue[i] + 0.7152*finalLut->greenValue[i] + 0.0722*finalLut->blueValue[i];
				finalLut->redValue[i] = tmp->redValue[luminance];
				finalLut->greenValue[i] = tmp->greenValue[luminance];
				finalLut->blueValue[i] = tmp->blueValue[luminance];
			} else {
				finalLut->redValue[i] = tmp->redValue[finalLut->redValue[i]];
				finalLut->greenValue[i] = tmp->greenValue[finalLut->greenValue[i]];
				finalLut->blueValue[i] = tmp->blueValue[finalLut->blueValue[i]];
			}
		}
		tmp = tmp->next;
	}

	applyLUTOnImage(currentLayout->img, finalLut);
}

void deleteLUT(Layout *currentLayout) {
	currentLayout->img = imageCopy(currentLayout->src); // On réinitialise l'image du calque

	if (currentLayout->luts == NULL)
		return;

	LUT *tmp = currentLayout->luts;
	if (tmp->next == NULL) {
		currentLayout->luts = NULL;
		return;
	}

	while (tmp->next != NULL) {
		tmp = tmp->next;
		
	}
	tmp->prev->next = NULL;
	free(tmp);

	// On applique toutes les LUT restantes
	applyAllLUTOnImage(currentLayout);
}

Image * calculateFinalImage(Layout *firstLayout) {
	unsigned int width = firstLayout->img->w;
	unsigned int height = firstLayout->img->h;

	Image *finalImg = initImage(width, height, COLOR); // On ne crée que des images couleurs


	int i;
	for (i = 0; i < width*height*3; i++)
		finalImg->pixels[i] = 0;


	Layout *tmp = firstLayout;
	while (tmp != NULL) {
		for (i = 0; i < 3*width*height; i++) {
			if (tmp->mode == ADDITION)
				finalImg->pixels[i] = finalImg->pixels[i] + tmp->opacity * tmp->img->pixels[i];
			else
				finalImg->pixels[i] = (1 - tmp->opacity) * finalImg->pixels[i] + tmp->opacity * tmp->img->pixels[i];
		}
		tmp = tmp->next;
	}

	return finalImg;
}