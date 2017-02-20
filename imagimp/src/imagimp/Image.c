#include "Image.h"

Image * initImage(unsigned int w, unsigned int h, Image_Type type) {
	Image *img = malloc(1*sizeof(Image));
	if (img == NULL)
		exit(0);
	img->w = w;
	img->h = h;
	img->type = type;

	img->pixels = malloc(3*w*h*sizeof(uint8_t)); // On multiplie par 3 car chaque pixel possède trois composantes
	if (img->pixels == NULL)
		exit(0);
	
	// Tous les pixels sont blancs
	int i;
	for (i = 0; i < 3*w*h; i++)
		img->pixels[i] = 255;

	return img;
}

Image * imageCopy(Image *img) {
	Image *imgCopy = malloc(1*sizeof(Image));
	imgCopy->w = img->w;
	imgCopy->h = img->h;
	imgCopy->type = img->type;
	imgCopy->pixels = malloc(3*imgCopy->w*imgCopy->h*sizeof(uint8_t));
	memcpy(imgCopy->pixels, img->pixels, 3*imgCopy->w*imgCopy->h*sizeof(uint8_t));

	return imgCopy;
}

void freeImage(Image *img) {
	if (img == NULL)
		return;

	free(img->pixels);
	img->pixels = NULL;
	free(img);
}

Image * readPPM(char *fileName) {
	FILE *f = fopen(fileName, "r");

	if (f == NULL) {
		fprintf(stderr, "Impossible d'ouvrir l'image.");
		return NULL;
	}

	char buffer[MAX_SIZE] = "";
	unsigned int line = 0;
	int returnValue;

	unsigned int w, h;
	Image_Type type;

	// On lit d'abord les "paramètres" de l'image
    while (line < 3) {
    	fgets(buffer, MAX_SIZE, f);
    	if (buffer[0] != '#') {
			line++;
    		switch (line) {
    			case 1: // RGB or N&B ?
    				if (strcmp(buffer, "P5\n") == 0) 
    					type = BLACK_WHITE;
    				else
    					type = COLOR;
    				break;
    			case 2 : // Hauteur & largeur ?
    				returnValue = sscanf(buffer, "%u %u", &w, &h);
    				if (returnValue != 2) return NULL;
    				break;
    			case 3 : // Maximum valeur ?
    				// Dans le cahier des charges, il est écrit que le maximum est 255. On ignore cette étape.
    				break;
    			default :
    				break;
    		}
    	}
    }

    Image *img = initImage(w, h, type);

    size_t nbPixels;
    fseek(f, 0, SEEK_CUR);

    /* Lecture des pixels */
    if (type == COLOR) {
    	nbPixels = fread(img->pixels, sizeof(uint8_t), 3*w*h, f);
    	if (nbPixels !=  3*w*h) {
    		freeImage(img);
    		img = NULL;
    		fclose(f);
    		return NULL;
    	}
    } else {
    	nbPixels = fread(img->pixels, sizeof(uint8_t), w*h, f);
    	if (nbPixels != w*h) {
    		freeImage(img);
    		img = NULL;
    		fclose(f);
    		return NULL;
    	}
    }

    fclose(f);

    returnImage(img);
    return img;
}

void returnImage(Image *img) {
	int i, j, k = 0;
	
	uint8_t *pixelsCopy = malloc(3*img->w*img->h*sizeof(uint8_t));
	if (pixelsCopy == NULL)
		exit(1);
	memcpy(pixelsCopy, img->pixels, 3*img->h*img->w);

	if (img->type == COLOR) {
		for (i = img->h-1; i >= 0; i--) { /* Lignes */
			for (j = 0; j < img->w; j++) { /* Colonnes */
				img->pixels[k++] = pixelsCopy[i*img->w*3 + j*3];
				img->pixels[k++] = pixelsCopy[i*img->w*3 + j*3 + 1];
				img->pixels[k++] = pixelsCopy[i*img->w*3 + j*3 + 2];
			}
		}	
	} else {
		for (i = img->h-1; i >= 0; i--) {
			for (j = 0; j < img->w; j++) { 
				/* Pour une image en noir et blanc, chaque composante (RVB) possède la même valeur */
				img->pixels[k++] = pixelsCopy[i*img->w + j];
				img->pixels[k++] = pixelsCopy[i*img->w + j];
				img->pixels[k++] = pixelsCopy[i*img->w + j];
			}
		}
	}
}

void savePPM(Image *img, char *fileName) {
	FILE *f = fopen(fileName, "w");

	if (f == NULL) {
		fprintf(stderr, "Impossible d'ouvrir l'image.");
		exit(1);
	}

	returnImage(img);

	// On écrit les informations de l'image
	fprintf(f, "P6\n");

	fprintf(f, "%u %u\n", img->w, img->h);
	fprintf(f, "255\n");

	// On écrit les pixels
	fwrite(img->pixels, 3*img->w*img->h*sizeof(uint8_t), 1, f);
	fclose(f);
}
