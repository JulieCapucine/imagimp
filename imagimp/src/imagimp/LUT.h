#ifndef LUT_H
#define LUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
	ADDLUM,
	DIMLUM,
	ADDCON,
	DIMCON,
	INVERT,
	SEPIA,
	GRAYSCALE,
	FINAL_LUT,
	FINAL_LUT_LUM
} LUT_Type;

typedef struct LUT {
	struct LUT *next;
	struct LUT *prev;
	LUT_Type type;
	uint8_t redValue[256];
	uint8_t greenValue[256];
	uint8_t blueValue[256];
} LUT;

LUT * createLUT(LUT_Type type);

#endif