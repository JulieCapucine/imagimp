#include "LUT.h"

extern uint8_t amount;

LUT * createLUT(LUT_Type type) {
	LUT *lut = malloc(1*sizeof(LUT));
	lut->next = NULL;
	lut->prev = NULL;
	lut->type = type;
	int i;
	
	switch (type) {
		case ADDLUM :
			for (i = 0; i < 256; i++) {
				if (i + amount > 255) {
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 255;
				} else {
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i+amount;
				}
			}
			break;
		case DIMLUM :
			for (i = 0; i < 256; i++) {
				if (i - amount < 0) 
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 0;
				else
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i-amount;
			}
			break;
		case ADDCON :
			for (i = 0; i < 128; i++) {
				if (i - amount < 0)
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 0;
				else
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i-amount;
			}

			for (; i < 256; i++) {
				if (i + amount > 255)
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 255;
				else
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i+amount;
			}

			break;
		case DIMCON : //TODO AREVOIR
			for (i = 0; i < 128; i++) {
				if (i + amount > 127)
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 127;
				else
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i+amount;
			}

			for (; i < 256; i++) {
				if (i - amount < 128)
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 128;
				else
					lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i-amount;
			}
			break;
		case INVERT :
			for (i = 0; i < 256; i++) {
				lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = 255-i;
			}
			break;
		case SEPIA :
			for (i=0; i<256; i++) {
				if (i * 1.351 > 255)
					lut->redValue[i] = 255;
				else
					lut->redValue[i] = i * 1.351;

				if (i * 1.203 > 255)
					lut->greenValue[i] = 255;
				else
					lut->greenValue[i] = i * 1.203;

				if (i * 0.937 > 255)
					lut->blueValue[i] = 255;
				else
					lut->blueValue[i] = i * 0.937;
			}
			break;
		case FINAL_LUT :
		case FINAL_LUT_LUM :
		case GRAYSCALE :
			for (i = 0; i < 256; i++) {
				lut->redValue[i] = lut->greenValue[i] = lut->blueValue[i] = i;
			}
			break;
	}

	return lut;
}