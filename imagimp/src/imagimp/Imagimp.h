#include <stdio.h>
#include <stdlib.h>

#include "Image.h"
#include "Layout.h"
#include "Histogram.h"
#include "LUT.h"
#include "glimagimp/interface.h"


typedef enum {
	NONE_KEYBOARD,
	A_LOWERCASE = 'a',
	B_LOWERCASE = 'b',
	C_LOWERCASE = 'c',
	D_LOWERCASE = 'd', 
	E_LOWERCASE = 'e',
	F_LOWERCASE = 'f', 
	G_LOWERCASE = 'g',
	H_LOWERCASE = 'h',
	I_LOWERCASE = 'i',
	J_LOWERCASE = 'j', 
	K_LOWERCASE = 'k',
	L_LOWERCASE = 'l', 
	M_LOWERCASE = 'm',
	N_LOWERCASE = 'n',
	O_LOWERCASE = 'o',
	P_LOWERCASE = 'p',
	Q_LOWERCASE = 'q',
	R_LOWERCASE = 'r',
	S_LOWERCASE = 's',
	T_LOWERCASE = 't',
	U_LOWERCASE = 'u',
	V_LOWERCASE = 'v',
	W_LOWERCASE = 'w',
	X_LOWERCASE = 'x',
	Y_LOWERCASE = 'y',
	Z_LOWERCASE= 'z', 
	A_UPPERCASE = 'A',
	B_UPPERCASE = 'B',
	C_UPPERCASE = 'C',
	D_UPPERCASE = 'D',
	E_UPPERCASE = 'E',
	F_UPPERCASE = 'F',
	G_UPPERCASE = 'G',
	H_UPPERCASE = 'H',
	I_UPPERCASE = 'I',
	J_UPPERCASE = 'J',
	K_UPPERCASE = 'K',
	L_UPPERCASE = 'L',
	M_UPPERCASE = 'M',
	N_UPPERCASE = 'N',
	O_UPPERCASE = 'O',
	P_UPPERCASE = 'P',
	Q_UPPERCASE = 'Q',
	R_UPPERCASE = 'R',
	S_UPPERCASE = 'S',
	T_UPPERCASE = 'T',
	U_UPPERCASE = 'U',
	V_UPPERCASE = 'V',
	W_UPPERCASE = 'W',
	X_UPPERCASE = 'X',
	Y_UPPERCASE = 'Y',
	Z_UPPERCASE = 'Z', 
	ZERO = '0',
	ONE = '1', 
	TWO = '2', 
	THREE = '3', 
	FOUR = '4', 
	FIVE = '5', 
	SIX = '6', 
	SEVEN = '7', 
	EIGHT = '8', 
	NINE = '9', 
	POINT = '.', 
	SLASH = '/', 
	COMMA = ',', 
	DELETE
} keyboard;

typedef enum {
	ENABLED_KEYBOARD,
	DISABLED_KEYBOARD, 
} Keyboard_status;

typedef enum {
	ACTIVE_KEYBOARD,
	DISACTIVE_KEYBOARD, 
} Keyboard_activation;

/*Definir les affichages sur l'ihm en fonction des evenements claviers*/
typedef enum {
	NONE,
	INFO_LAYOUT,
	INFO_IMG,
	LOAD_IMG,
	CHGMT_OPACITY,
	OPACITY_ADDED,
	HIST_R,
	HIST_G,
	HIST_B,
	HIST_RGB, 
	SAVE_IMG, 
	ADD_CON, 
	ADD_LUM,
	DIM_CON, 
	DIM_LUM, 
	EFFECT_SEPIA,
	EFFECT_GRAYSCALE,
	EFFECT_INVERT, 
	PREV_LAYOUT_EMPTY, 
	NEXT_LAYOUT_EMPTY, 
	MODE_ADD, 
	MODE_MULTIPLY, 
	IMG_ADDED, 
	IMG_SAVED, 
	LUM_CHANGED,
	CON_CHANGED, 
	OPACITY_FAIL,
	LUM_ADD_FAIL, 
	CON_ADD_FAIL,
	LUM_DIM_FAIL,
	CON_DIM_FAIL
} Display;

/* Définir le mode de vue de l'application */
typedef enum {
	LAYOUT_IMG,
	LAYOUT_SRC,
	FINAL_IMG
} Display_Mode;

/* Gerer les évenements clavier */
void keyEvent(unsigned char c, int x, int y);

/*Gerer les evenements souris*/
void mouseControl(int button, int state, int x, int y);

/* Lancer l'application */
int launchImagimp(int argv, char *argc[]);