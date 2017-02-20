#include "Histogram.h"


Histogram * initHisto(Histogram_Type type) {
	Histogram *histo = malloc(1*sizeof(Histogram));
	histo->type = type;

	int i;
	for (i = 0; i < 256; i++)
		histo->nbPixels[i] = 0;

	return histo;
}

Histogram * createRedHisto(Image *img) {
	Histogram *histo = initHisto(RED);

	int i;
	for (i = 0; i < 3*img->w*img->h; i++) {
		histo->nbPixels[img->pixels[i]] += 1;
	}

	return histo;
}

Histogram * createGreenHisto(Image *img) {
	Histogram *histo = initHisto(GREEN);

	int i;
	for (i = 1; i < 3*img->w*img->h; i += 3) {
		histo->nbPixels[img->pixels[i]] += 1;
	}

	return histo;
}

Histogram * createBlueHisto(Image *img) {
	Histogram *histo = initHisto(BLUE);

	int i;
	for (i = 2; i < 3*img->w*img->h; i += 3) {
		histo->nbPixels[img->pixels[i]] += 1;
	}

	return histo;
}

Histogram *createRGBHisto(Image *img) {
	Histogram *histo = initHisto(AVERAGE);

	int i;
	unsigned int lum;
	for (i = 0; i < 3*img->w*img->h; i += 3) {
		lum =  0.299*img->pixels[i] + 0.587*img->pixels[i+1] + 0.114*img->pixels[i+2];
		histo->nbPixels[lum] += 1;
	}

	return histo;
}

