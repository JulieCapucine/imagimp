#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "glimagimp/interface.h"
#include "glimagimp/outils.h"
#include "Image.h"
#include "Layout.h"
#include "Imagimp.h"
#include "Histogram.h"

float letter_positionX = 0.65;
float letter_positionY = 0.30;
char letter_entry[255] = {'\0'};

extern keyboard Keyboard;
extern Layout *currentLayout;
extern Layout *firstLayout;
extern Display display;
extern Display_Mode currentMode;
extern Keyboard_status keyboard_status;
extern Keyboard_activation keyboard_activation;
extern char letter_entry[255];




char *letter(keyboard Key, char letter_entry[255] ){
	int size = 0;
	switch (Key){
		case A_LOWERCASE:
			return strcat(letter_entry,"a");
			break;
		case B_LOWERCASE:
			return strcat(letter_entry,"b");
			break;
		case C_LOWERCASE:
			return strcat(letter_entry,"c");
			break;
		case D_LOWERCASE:
			return strcat(letter_entry,"d");
			break;
		case E_LOWERCASE:
			return strcat(letter_entry,"e");
			break;
		case F_LOWERCASE:
			return strcat(letter_entry,"f");
			break;
		case G_LOWERCASE:
			return strcat(letter_entry, "g");
			break;
		case H_LOWERCASE:
			return strcat(letter_entry, "h");
			break;
		case I_LOWERCASE:
			return strcat(letter_entry, "i");
			break;
		case J_LOWERCASE:
			return strcat(letter_entry, "j");
			break;
		case K_LOWERCASE:
			return strcat(letter_entry,"k");
			break;
		case L_LOWERCASE:
			return strcat(letter_entry, "l");
			break;
		case M_LOWERCASE:
			return strcat(letter_entry,"m");
			break;
		case N_LOWERCASE:
			return strcat(letter_entry, "n");
			break;
		case O_LOWERCASE:
			return strcat(letter_entry, "o");
			break;
		case P_LOWERCASE:
			return strcat(letter_entry, "p");
			break;
		case Q_LOWERCASE:
			return strcat(letter_entry, "q");
			break;
		case R_LOWERCASE:
			return strcat(letter_entry, "r");
			break;
		case S_LOWERCASE:
			return strcat(letter_entry,"s");
			break;
		case T_LOWERCASE:
			return strcat(letter_entry,"t");
			break;
		case U_LOWERCASE:
			return strcat(letter_entry,"u");
			break;
		case V_LOWERCASE:
			return strcat(letter_entry, "v");
			break;
		case W_LOWERCASE:
			return strcat(letter_entry,"w");
			break;
		case X_LOWERCASE:
			return strcat(letter_entry, "x");
			break;
		case Y_LOWERCASE:
			return strcat(letter_entry, "y");
			break;
		case Z_LOWERCASE:
			return strcat(letter_entry, "z");
			break;
		case A_UPPERCASE:
			return strcat(letter_entry,"A");
			break;
		case B_UPPERCASE:
			return strcat(letter_entry,"B");
			break;
		case C_UPPERCASE:
			return strcat(letter_entry,"C");
			break;
		case D_UPPERCASE:
			return strcat(letter_entry,"D");
			break;
		case E_UPPERCASE:
			return strcat(letter_entry,"E");
			break;
		case F_UPPERCASE:
			return strcat(letter_entry,"F");
			break;
		case G_UPPERCASE:
			return strcat(letter_entry, "G");
			break;
		case H_UPPERCASE:
			return strcat(letter_entry, "H");
			break;
		case I_UPPERCASE:
			return strcat(letter_entry, "I");
			break;
		case J_UPPERCASE:
			return strcat(letter_entry, "J");
			break;
		case K_UPPERCASE:
			return strcat(letter_entry,"K");
			break;
		case L_UPPERCASE:
			return strcat(letter_entry, "L");
			break;
		case M_UPPERCASE:
			return strcat(letter_entry,"M");
			break;
		case N_UPPERCASE:
			return strcat(letter_entry, "N");
			break;
		case O_UPPERCASE:
			return strcat(letter_entry, "O");
			break;
		case P_UPPERCASE:
			return strcat(letter_entry, "P");
			break;
		case Q_UPPERCASE:
			return strcat(letter_entry, "Q");
			break;
		case R_UPPERCASE:
			return strcat(letter_entry, "R");
			break;
		case S_UPPERCASE:
			return strcat(letter_entry,"S");
			break;
		case T_UPPERCASE:
			return strcat(letter_entry,"T");
			break;
		case U_UPPERCASE:
			return strcat(letter_entry,"U");
			break;
		case V_UPPERCASE:
			return strcat(letter_entry, "V");
			break;
		case W_UPPERCASE:
			return strcat(letter_entry,"W");
			break;
		case X_UPPERCASE:
			return strcat(letter_entry, "X");
			break;
		case Y_UPPERCASE:
			return strcat(letter_entry, "Y");
			break;
		case Z_UPPERCASE:
			return strcat(letter_entry, "Z");
			break;
		case ZERO:
			return strcat(letter_entry,"0");
			break;
		case ONE:
			return strcat(letter_entry, "1");
			break;
		case TWO:
			return strcat(letter_entry,"2");
			break;
		case THREE:
			return strcat(letter_entry, "3");
			break;
		case FOUR:
			return strcat(letter_entry, "4");
			break;
		case FIVE:
			return strcat(letter_entry, "5");
			break;
		case SIX:
			return strcat(letter_entry,"6");
			break;
		case SEVEN:
			return strcat(letter_entry, "7");
			break;
		case EIGHT:
			return strcat(letter_entry,"8");
			break;
		case NINE:
			return strcat(letter_entry, "9");
			break;
		case POINT:
			return strcat(letter_entry, ".");
			break;
		case SLASH:
			return strcat(letter_entry,"/");
			break;
		case COMMA:
			/*virgule devient point pour gérer les nombres décimaux*/
			return strcat(letter_entry, ".");
			break;
		case DELETE:
			size = strlen(letter_entry);
			letter_entry[size - 1] = '\0';
			return letter_entry;
			break;
		default:
			return "/";

	}
}

char *digit(int digit){
	switch(digit){
 			case 0:
 				return "0";
 				break;
 			case 1: 
 				return "1";
 				break;
 			case 2:
 				return "2";
 				break;
 			case 3: 
 				return "3";
 				break;
 			case 4:
 				return "4";
 				break;
 			case 5: 
 				return "5";
 				break;
 			case 6:
 				return "6";
 				break;
 			case 7: 
 				return "7";
 				break;
 			case 8:
 				return "8";
 				break;
 			case 9: 
 				return "9";
 				break;
 			default:
 				return "0";
 				break;

 		}
}

char *number(int number, char number_string[5]){
	int first_digit = 0, i = 0, j = 0;
	char temp[1]= "";
	if (number == 0){
		return "0";
	} else {
		while (number/10 != 0){
			first_digit = number%10;
			number = number/10;
			number_string[i] = *digit(first_digit);
			i++;
		}
	}
	first_digit = number%10;
	number_string[i] = *digit(first_digit);
	for (; j < i/2; j++){
		temp[0] = number_string[j];
		number_string[j] = number_string [i-j];
		number_string[i] = temp[0];
	}
	return number_string;
 }


 void drawInfoImg(){
 		char number_string[5] = "";
 	    writeString(0.63, 0.40, " ***  Informations sur l'image  *** ");
		writeString(0.63, 0.34, "L'image appartient au calque :");
		writeString(0.91, 0.34, digit(currentLayout->position));
		writeString(0.63, 0.30, "L'image est en");
		if (currentLayout->img->type == COLOR) {
			writeString(0.77, 0.30, "couleurs.");
		} else {
		    writeString(0.77, 0.30,"niveaux de gris.");
		}
		writeString(0.63, 0.26, "Hauteur :       - Largeur :   ");
		writeString(0.73, 0.26, number(currentLayout->img->h, number_string));
		writeString(0.89, 0.26, number(currentLayout->img->w, number_string));
 }

void drawInfoLayout(){
	char number_string[5] = "";
	writeString(0.63, 0.40, " ***  Informations sur le calque *** ");
				writeString(0.63, 0.34, "Calque:");
				writeString(0.72, 0.34, number(currentLayout->position, number_string));
				writeString(0.77, 0.34, "- Calque courant");
				if (currentLayout->opacity == 0){
					writeString(0.63, 0.30, "Opacite:  0");
				} else if (currentLayout->opacity == 1){
					writeString(0.63, 0.30, "Opacite:  1");
				} else {
					writeString(0.63, 0.30, "Opacite:  0.");
					writeString(0.74, 0.30, number(currentLayout->opacity*10,number_string));
				}
				(currentLayout->mode == ADDITION) ? writeString(0.63, 0.26, "Mode : Addition"):writeString(0.63, 0.26, "Mode : Multiplication");
				writeString(0.63, 0.22, "Luts :");
				LUT *tmp = currentLayout->luts;
				float position = 0.22;
				while (tmp != NULL) {
					switch(tmp->type) {
						case ADDLUM:
							writeString(0.70, position, "ADDLUM");
							position -= 0.04;
							break;
						case DIMLUM :
							writeString(0.70,position, "DIMLUM");
							position -= 0.04;
							break;
						case ADDCON :
							writeString(0.70, position, "ADDCON");
							position -= 0.04;
							break;
						case DIMCON :
							writeString(0.70, position, "DIMCON");
							position -= 0.04;
							break;
						case INVERT :
							writeString(0.70, position, "INVERT");
							position -= 0.04;
							break;
						case SEPIA :
							writeString(0.70, position, "SEPIA");
							position -= 0.04;
							break;
						case GRAYSCALE :
							writeString(0.70, position, "GRAYSCALE");
							position -= 0.04;
							break;
						default:
							break;
					}
					tmp = tmp->next;
				}
}

void drawHistogram(Histogram *histogram){
 	int i = 1, max = histogram->nbPixels[0];
 	for (; i < 256; i++){
 		if (histogram->nbPixels[i] > max){
 			max = histogram->nbPixels[i];
 		}
 	}
 	for (i = 0; i< 256; i++){
 		drawLigne(0.60 + i*0.0015, 0.08, 0.60 + i*0.0015, 0.08 + 0.36*histogram->nbPixels[i]/max);
 	}
 }

void drawButtonHisto(){
	
		writeString(0.605, 0.03, "Red");
		drawCarreVide(0.60, 0.01, 0.64, 0.06);

		writeString(0.657, 0.03, "Blue");
		drawCarreVide(0.65, 0.01, 0.70, 0.06);

		writeString(0.715, 0.03, "Green");
		drawCarreVide(0.71, 0.01, 0.77, 0.06);

		writeString(0.787, 0.03, "RGB");
		drawCarreVide(0.78, 0.01, 0.82, 0.06);
		
}


void drawInterface(){
	

	fixeCouleur(1, 1, 1);
	writeString(0.91, 0.02, "Quitter");
	drawCarreVide(0.9, 0.008, 0.99, 0.045);

	// fixeCouleur(1, 0, 1);
	writeString(0.857, 0.02, "Vue");
	drawCarreVide(0.84, 0.008, 0.89, 0.045);

	fixeCouleur(1, 1, 1);
	/*partie supérieure*/

	writeString(0.03, 0.95, "Sauvegarder img");
	drawCarreVide(0.015, 0.93, 0.18, 0.98);

	writeString(0.205, 0.95, "Histogrammes");
	drawCarreVide(0.20, 0.93, 0.32, 0.98);

	writeString(0.35, 0.95, "Info img");
	drawCarreVide(0.34, 0.93, 0.44, 0.98);

	writeString(0.47, 0.95, "Info calque");
	drawCarreVide(0.46, 0.93, 0.58, 0.98);

	/*Action sur les calques*/ 
	writeString(0.605, 0.96, "Actions sur calques");

	writeString(0.64, 0.90, "Ajout calque");
	drawCarreVide(0.61, 0.88, 0.78, 0.93);

	writeString(0.63, 0.84, "Suppr. calque");
	drawCarreVide(0.61, 0.82, 0.78, 0.87);

	writeString(0.63, 0.785, "Ajout img sur");
	writeString(0.63, 0.76, "calque courant"); 
	drawCarreVide(0.61, 0.74, 0.78, 0.81);

	writeString(0.65, 0.70, "Opacite");
	drawCarreVide(0.61, 0.68, 0.78, 0.73);

	writeString(0.63, 0.64, "Mode de fusion");
	drawCarreVide(0.61, 0.62, 0.78, 0.67);

	writeString(0.63, 0.54, "Calque suivant");
	drawCarreVide(0.61, 0.52, 0.78, 0.57);

	writeString(0.62, 0.48, "Calque precedent");
	drawCarreVide(0.61, 0.46, 0.78, 0.51);

	/*Action sur les LUT*/ 
	writeString(0.83, 0.96, "Actions sur LUT");

	writeString(0.84, 0.90, "Augm. contraste");
	drawCarreVide(0.82, 0.88, 0.99, 0.93);

	writeString(0.84, 0.84, "Dim. contraste");
	drawCarreVide(0.82, 0.82, 0.99, 0.87);

	writeString(0.83, 0.78, "Augm. luminosite");
	drawCarreVide(0.82, 0.76, 0.99, 0.81);

	writeString(0.84, 0.72, "Dim. luminosite");
	drawCarreVide(0.82, 0.70, 0.99, 0.75);

	writeString(0.89, 0.66, "Sepia");
	drawCarreVide(0.82, 0.64, 0.99, 0.69);

	writeString(0.85, 0.60, "Noir et blanc");
	drawCarreVide(0.82, 0.58, 0.99, 0.63);

	writeString(0.88, 0.54, "Negatif");
	drawCarreVide(0.82, 0.52, 0.99, 0.57);

	writeString(0.86, 0.48, "Suppr. LUT");
	drawCarreVide(0.82, 0.46, 0.99, 0.51);

	/*section affichage*/
	drawCarreVide(0.60, 0.44, 0.99, 0.08);

	if (keyboard_activation == ACTIVE_KEYBOARD){
		if ((Keyboard != NONE_KEYBOARD) && (keyboard_status == ENABLED_KEYBOARD)){
			letter(Keyboard, letter_entry);
			writeString(letter_positionX, letter_positionY, letter_entry);
			keyboard_status = DISABLED_KEYBOARD;
		} else if (keyboard_status == DISABLED_KEYBOARD){
				writeString(letter_positionX, letter_positionY, letter_entry);	
		}

	}
	
	if (display == INFO_IMG){
		drawInfoImg();

	} else if (display == INFO_LAYOUT){
		drawInfoLayout();

	} else if (display == HIST_RGB){
		Histogram * histo;
		histo = initHisto(AVERAGE);
		if (currentMode == FINAL_IMG){
			histo = createRGBHisto(calculateFinalImage(firstLayout));
		} else  if (currentMode == LAYOUT_SRC){
			histo = createRGBHisto(currentLayout->src);
		} else {
			histo = createRGBHisto(currentLayout->img);
		}
		writeString(0.62, 0.41, "RVB");
		drawHistogram(histo);
		drawButtonHisto();
	} else if (display == HIST_R){
		Histogram * histo;
		histo = initHisto(RED);
		if (currentMode == FINAL_IMG){
			histo = createRedHisto(calculateFinalImage(firstLayout));
		} else if (currentMode == LAYOUT_SRC){
			histo = createRedHisto(currentLayout->src);
		} else {
			histo = createRedHisto(currentLayout->img);
		}
		writeString(0.62, 0.41, "Red");
		drawHistogram(histo);
		drawButtonHisto();

	} else if (display == HIST_G){
		Histogram * histo;
		histo = initHisto(GREEN);
		if (currentMode == FINAL_IMG){
			
			histo = createGreenHisto(calculateFinalImage(firstLayout));
		} else  if (currentMode == LAYOUT_SRC){
			histo = createGreenHisto(currentLayout->src);
		} else {
			histo = createGreenHisto(currentLayout->img);
		}
		writeString(0.62, 0.41, "Green");
		drawHistogram(histo);
		drawButtonHisto();

	} else if (display == HIST_B){
		Histogram * histo;
		histo = initHisto(BLUE);
		if (currentMode == FINAL_IMG){
			histo = createBlueHisto(calculateFinalImage(firstLayout));
		} else  if (currentMode == LAYOUT_SRC){
			histo = createBlueHisto(currentLayout->src);
		} else {
			histo = createBlueHisto(currentLayout->img);
		}
		writeString(0.62, 0.41, "Blue");
		drawHistogram(histo);
		drawButtonHisto();

	} else if (display == CHGMT_OPACITY){
		writeString(0.64, 0.40, "Veuillez saisir la valeur de       l'opacite et appuyer sur ENTREE");
		writeString(0.70, 0.10, "(Valeur entre 0 et 1)");
	} else if (display == OPACITY_ADDED){
		writeString(0.65, 0.30, "Ajout opacite!");
	} else if (display == OPACITY_FAIL){
		writeString(0.64, 0.40, "Veuillez saisir la valeur de       l'opacite et appuyer sur ENTREE");
		writeString(0.65, 0.18, "(Erreur: l'opacite doit etre       comprise entre 0 et 1)");
	} else if (display == IMG_ADDED){
		writeString(0.65, 0.30, "Ajout image!");
	} else if (display == IMG_SAVED){
		writeString(0.65, 0.30, "Image sauvegardee!");
	} else if (display == CON_CHANGED){
		writeString(0.65, 0.30, "Contraste modifie!"); 
	} else if (display == LUM_CHANGED){
		writeString(0.65, 0.30, "Luminosite modifie!");
	} else if (display == LOAD_IMG){
		writeString(0.63, 0.40, "Veuillez saisir saisir le chemin et appuyez sur ENTREE ");
	} else if (display == SAVE_IMG){
		writeString(0.63, 0.40, "Veuillez saisir saisir le chemin   de la sauvegarde et appuyer        sur ENTREE");
	} else if ((display == ADD_LUM) || (display == ADD_CON) || (display == DIM_LUM) || (display == DIM_CON)){
		writeString(0.63, 0.40, "Veuillez saisir la valeur de       l'effet et appuyer sur ENTREE");
		writeString(0.68, 0.10, "(Valeur entre 0 et 100)");
	} else if ((display == LUM_ADD_FAIL ) || (display == LUM_DIM_FAIL) || (display == CON_DIM_FAIL) || (display == CON_ADD_FAIL)){
		writeString(0.63, 0.40, "Veuillez saisir la valeur de       l'effet et appuyer sur ENTREE");
		writeString(0.65, 0.18, "(Erreur: la valeur saisie doit     etre comprise entre 0 et 100)");
	}else if ((display == EFFECT_SEPIA)){
		writeString(0.66, 0.26, "Effet sepia ajoute!");
	} else if ((display == EFFECT_INVERT)){
		writeString(0.66, 0.26, "Effet negatif ajoute!");
	} else if ((display == EFFECT_GRAYSCALE)){
		writeString(0.66, 0.26, "Effet noir et blanc ajoute!");
	} else if ((display == NEXT_LAYOUT_EMPTY)){
		writeString(0.66, 0.26, "Pas de calque suivant!");
	} else if ((display == PREV_LAYOUT_EMPTY)){
		writeString(0.66, 0.26, "Pas de calque precedent!");
	} else if ((display == MODE_MULTIPLY)){
		writeString(0.63, 0.26, "Mode de fusion: multiplication");
	} else if ((display == MODE_ADD)){
		writeString(0.63, 0.26, "Mode de fusion: addition");	
	}

	if (currentMode == LAYOUT_IMG){
		writeString(0.83, 0.055, "Calque avec effets");
	} else if (currentMode == LAYOUT_SRC){
		writeString(0.83, 0.055, "Calque sans effet");	
	} else if (currentMode == FINAL_IMG){
		writeString(0.88, 0.055, "Image finale");	
	
}
}





