#include "Imagimp.h"
#include "Ihm.h"

// Variables globales du programme
Layout *firstLayout = NULL; // Correspond au premier calque du canevas
Layout *currentLayout = NULL; // Correspond au calque courant
Image *finalImage = NULL; // Correspond à l'image finale
Display_Mode currentMode = LAYOUT_IMG; // Correspond au mode de vue actuel (image source du calque, image transformée du calque ou image finale)
Display display = NONE;
keyboard Keyboard = NONE_KEYBOARD;
Keyboard_status keyboard_status = DISABLED_KEYBOARD;
Keyboard_activation keyboard_activation = DISACTIVE_KEYBOARD;
unsigned int amount = 0;

extern Keyboard_activation keyboard_activation;
extern Keyboard_status keyboard_status;
extern keyboard Keyboard;
extern Display display;
extern Display_Mode currentMode;
extern Layout *firstLayout;
extern Layout *currentLayout;
extern unsigned int amount;
extern char letter_entry[255];


void keyEvent(unsigned char c, int x, int y) {
	int returnValue;
	if (keyboard_activation == ACTIVE_KEYBOARD){
		switch(c) {
		case 'a':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = A_LOWERCASE;
			break;
		case 'b':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = B_LOWERCASE;
			break;
		case 'c':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = C_LOWERCASE;
			break;
		case 'd':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = D_LOWERCASE;
			break;
		case 'e':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = E_LOWERCASE;
			break;
		case 'f':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = F_LOWERCASE;
			break;
		case 'g':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = G_LOWERCASE;
			break;
		case 'h':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = H_LOWERCASE;
			break;
		case 'i':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = I_LOWERCASE;
			break;
		case 'j':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = J_LOWERCASE;
			break;
		case 'k':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = K_LOWERCASE;
			break;
		case 'l':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = L_LOWERCASE;
			break;
		case 'm':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = M_LOWERCASE;
			break;
		case 'n':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = N_LOWERCASE;
			break;
		case 'o':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = O_LOWERCASE;
			break;
		case 'p':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = P_LOWERCASE;
			break;
		case 'q':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Q_LOWERCASE;
			break;
		case 'r':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = R_LOWERCASE;
			break;
		case 's':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = S_LOWERCASE;
			break;
		case 't':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = T_LOWERCASE;
			break;
		case 'u':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = U_LOWERCASE;
			break;
		case 'v':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = V_LOWERCASE;
			break;
		case 'w':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = W_LOWERCASE;
			break;
		case 'x':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = X_LOWERCASE;
			break;
		case 'y':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Y_LOWERCASE;
			break;
		case 'z':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Z_LOWERCASE;
			break;
		case 'A':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = A_UPPERCASE;
			break;
		case 'B':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = B_UPPERCASE;
			break;
		case 'C':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = C_UPPERCASE;
			break;
		case 'D':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = D_UPPERCASE;
			break;
		case 'E':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = E_UPPERCASE;
			break;
		case 'F':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = F_UPPERCASE;
			break;
		case 'G':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = G_UPPERCASE;
			break;
		case 'H':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = H_UPPERCASE;
			break;
		case 'I':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = I_UPPERCASE;
			break;
		case 'J':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = J_UPPERCASE;
			break;
		case 'K':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = K_UPPERCASE;
			break;
		case 'L':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = L_UPPERCASE;
			break;
		case 'M':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = M_UPPERCASE;
			break;
		case 'N':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = N_UPPERCASE;
			break;
		case 'O':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = O_UPPERCASE;
			break;
		case 'P':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = P_UPPERCASE;
			break;
		case 'Q':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Q_UPPERCASE;
			break;
		case 'R':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = R_UPPERCASE;
			break;
		case 'S':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = S_UPPERCASE;
			break;
		case 'T':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = T_UPPERCASE;
			break;
		case 'U':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = U_UPPERCASE;
			break;
		case 'V':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = V_UPPERCASE;
			break;
		case 'W':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = W_UPPERCASE;
			break;
		case 'X':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = X_UPPERCASE;
			break;
		case 'Y':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Y_UPPERCASE;
			break;
		case 'Z':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = Z_UPPERCASE;
			break;
		case '0':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = ZERO;
			break;
		case '1':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = ONE;
			break;
		case '2':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = TWO;
			break;
		case '3':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = THREE;
			break;
		case '4':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = FOUR;
			break;
		case '5':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = FIVE;
			break;
		case '6':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = SIX;
			break;
		case '7':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = SEVEN;
			break;
		case '8':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = EIGHT;
			break;
		case '9':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = NINE;
			break;
		case '.':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = POINT;
			break;
		case '/':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = SLASH;
			break;
		case ',':
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = COMMA;
			break;
		case 8:
			keyboard_status = ENABLED_KEYBOARD;
			Keyboard = DELETE;
			break;
		
		}
	}
	
		switch(c){
		case 13 :
			Keyboard = NONE;
			switch(display){
				float newVal;
				case CHGMT_OPACITY:
					if (sscanf(letter_entry, "%f", &newVal) == 1) {
						if (newVal >= 0 && newVal <= 1) {
							changeOpacity(currentLayout, newVal);
							keyboard_activation = DISACTIVE_KEYBOARD;
							display = OPACITY_ADDED;
						} else {
							display = OPACITY_FAIL;
						}
					} else {
						display = OPACITY_FAIL;
					}
					actualiseImage(currentLayout->img->pixels);
					memset(letter_entry, 0, sizeof(letter_entry));
					
				break;
				case OPACITY_FAIL: 
					if (sscanf(letter_entry, "%f", &newVal) == 1) {
						if (newVal >= 0 && newVal <= 1) {
							changeOpacity(currentLayout, newVal);
							keyboard_activation = DISACTIVE_KEYBOARD;
							display = OPACITY_ADDED;
						} else {
							display = OPACITY_FAIL;
						}
					} else {
						display = OPACITY_FAIL;
					}
					actualiseImage(currentLayout->img->pixels);
					memset(letter_entry, 0, sizeof(letter_entry));
					
				break;
				case LOAD_IMG:
					keyboard_activation = DISACTIVE_KEYBOARD;
					returnValue = addImageOnLayout(currentLayout, letter_entry);
					if (returnValue == 0)
						printf("Erreur ajout image. L'image n'a pas pu être ouverte.\n");
					else if (returnValue == -1) {
						printf("Erreur ajout image. L'image ne possède pas les bonnes dimensions.\n"); //TODO Préciser les dimensions
					} else {
						display = IMG_ADDED;
					}
					memset(letter_entry, 0, sizeof(letter_entry));

				break;
				case ADD_CON:
						
						if (sscanf(letter_entry, "%d", &amount)!= 1){
							break;
						}	
						if (amount > 100){
							display = CON_ADD_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = CON_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, ADDCON);
						memset(letter_entry, 0, sizeof(letter_entry));
							
				break;
				case DIM_CON:
						
						if (sscanf(letter_entry, "%d", &amount)!= 1){
							break;
						}	
						if (amount > 100){
							display = CON_DIM_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = CON_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, DIMCON);
						memset(letter_entry, 0, sizeof(letter_entry));
							
				break;
				case ADD_LUM:
						
						if (sscanf(letter_entry, "%d", &amount) != 1){
							break;
						}	
						if (amount > 100){
							display = LUM_ADD_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = LUM_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, ADDLUM);		
						memset(letter_entry, 0, sizeof(letter_entry));
					
				break;
				case DIM_LUM:
						
						if (sscanf(letter_entry, "%d", &amount) != 1){
							break;
						}	
						if (amount > 100){
							display = LUM_DIM_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = LUM_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, DIMLUM);	
						memset(letter_entry, 0, sizeof(letter_entry));						
				break;
				case CON_ADD_FAIL:
						
						if (sscanf(letter_entry, "%d", &amount)!= 1){
							break;
						}	
						if (amount > 100){
							display = CON_ADD_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = CON_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, ADDCON);
						memset(letter_entry, 0, sizeof(letter_entry));
							
				break;
				case CON_DIM_FAIL:
						
						if (sscanf(letter_entry, "%d", &amount)!= 1){
							break;
						}	
						if (amount > 100){
							display = CON_DIM_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						addLUTOnLayout(currentLayout, DIMCON);
						display = CON_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						memset(letter_entry, 0, sizeof(letter_entry));
							
				break;
				case LUM_ADD_FAIL:
						
						if (sscanf(letter_entry, "%d", &amount) != 1){
							break;
						}	
						if (amount > 100){
							display = LUM_ADD_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = LUM_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, ADDLUM);		
						memset(letter_entry, 0, sizeof(letter_entry));
					
				break;
				case LUM_DIM_FAIL:
						
						if (sscanf(letter_entry, "%d", &amount) != 1){
							break;
						}	
						if (amount > 100){
							display = LUM_DIM_FAIL;
							memset(letter_entry, 0, sizeof(letter_entry));
							break;
						}
						display = LUM_CHANGED;
						keyboard_activation = DISACTIVE_KEYBOARD;
						addLUTOnLayout(currentLayout, DIMLUM);	
						memset(letter_entry, 0, sizeof(letter_entry));						
				break;
				case SAVE_IMG:
						keyboard_activation = DISACTIVE_KEYBOARD;
						finalImage = calculateFinalImage(firstLayout);
						savePPM(finalImage, letter_entry);
						display = IMG_SAVED;
						memset(letter_entry, 0, sizeof(letter_entry));
				default: 
				break;
				}
			break;

		default :
		break;
	}
	switch(currentMode){
		case LAYOUT_IMG:
			actualiseImage(currentLayout->img->pixels);
		break;
		case LAYOUT_SRC:
			actualiseImage(currentLayout->src->pixels);
		break;
		case FINAL_IMG:
			actualiseImage(calculateFinalImage(firstLayout)->pixels);
		break;
		default: 
		break;
	}
	
}

void mouseControl(int button, int state, int x, int y){
	float positionX = x/(float)width_ecran;
	float positionY = -y/(float)(height_ecran) + 1; 
	if (state == GLUT_DOWN){
		if ((display != HIST_R) && (display != HIST_RGB) && (display != HIST_B) && (display != HIST_G))
			display = NONE;
		
		if ((positionY > 0.008) && (positionY < 0.045)){
			
			if ((positionX > 0.9) && (positionX < 0.99)){
				/*Quitter*/
				freeCanvas(currentLayout);
				freeImage(finalImage);
				exit(0);
			} else if ((positionX > 0.85) && (positionX < 0.89)){
					switch(currentMode){
						case LAYOUT_IMG:
							currentMode = LAYOUT_SRC;
							actualiseImage(currentLayout->src->pixels);
						break;
						case LAYOUT_SRC :
							currentMode = FINAL_IMG;
							actualiseImage(calculateFinalImage(firstLayout)->pixels);
						break;
						case FINAL_IMG:
							currentMode = LAYOUT_IMG;
							actualiseImage(currentLayout->img->pixels);
						break;
						default: 
						break;
					}
			} 
		}

		if ((positionY > 0.01) && (positionY < 0.06)){

			if ((positionX > 0.60) && (positionX < 0.64)){
				/*Histogramme Rouge*/
				if ((display == HIST_R) || (display == HIST_RGB) || (display == HIST_B) || (display == HIST_G))
					display = HIST_R;
			} else if ((positionX > 0.65) && (positionX < 0.70)){
				/*Histogramme Bleu*/
				if ((display == HIST_R) || (display == HIST_RGB) || (display == HIST_B) || (display == HIST_G))
					display = HIST_B;
			} else if ((positionX > 0.71) && (positionX < 0.77)){
				/*Histogramme Vert*/
				if ((display == HIST_R) || (display == HIST_RGB) || (display == HIST_B) || (display == HIST_G))
				 	display = HIST_G;
			} else if ((positionX > 0.78) && (positionX < 0.82)){
				/*Histogramme RVB*/
				if ((display == HIST_R) || (display == HIST_RGB) || (display == HIST_B) || (display == HIST_G))
					display = HIST_RGB;
			} 

		 } else 

		if ((positionY > 0.93) && (positionY < 0.98)){
			
			if ((positionX > 0.015) && (positionX < 0.18)){
				/*Sauvegarde*/
				display = SAVE_IMG;
				keyboard_activation = ACTIVE_KEYBOARD;
			} else if ((positionX > 0.20) && (positionX < 0.32)){
				/*Histogrammes*/
				display = HIST_RGB;
			}  else if ((positionX > 0.34) && (positionX < 0.44)){
				/*Info img*/
				display = INFO_IMG;
			}  else if ((positionX > 0.46) && (positionX < 0.58)){
				/*Info calque*/
				display = INFO_LAYOUT;
			}

		} else if ((positionX > 0.61) && (positionX < 0.78)){
			/*Actions sur les calques*/ 

			if ((positionY > 0.88) && (positionY < 0.93)){
				/*Ajout Calque*/
				currentLayout = addLayout(firstLayout);

			} else if ((positionY > 0.82) && (positionY < 0.87)){
				/*Suppression du calque courant*/
				currentLayout = deleteLayout(&firstLayout, currentLayout);

			} else if ((positionY > 0.74) && (positionY < 0.81)){
				/*Ajout image sur calque courant*/
				display = LOAD_IMG;
				keyboard_activation = ACTIVE_KEYBOARD;
				
			} else if ((positionY > 0.68) && (positionY < 0.73)){
				/*Opacite*/
				display = CHGMT_OPACITY;
				keyboard_activation = ACTIVE_KEYBOARD;

			} else if ((positionY > 0.62) && (positionY < 0.67)){
				/*Mode de fusion*/
				changeMode(currentLayout);
				if (currentLayout->mode == MULTIPLICATION){
					display = MODE_MULTIPLY;
				} else {
					display = MODE_ADD;
				}
				if (currentMode == FINAL_IMG){
					actualiseImage(calculateFinalImage(firstLayout)->pixels);
				}
					
			} else if ((positionY > 0.52) && (positionY < 0.57)){
				/*Calque suivant*/
				if (changeToNextLayout(&currentLayout) == 0) {
					display = NEXT_LAYOUT_EMPTY;
					return;
				}		
				
			} else if ((positionY > 0.46) && (positionY < 0.51)){
				/*Calque precendent*/  
				if (changeToPrevLayout(&currentLayout) == 0) {
					display = PREV_LAYOUT_EMPTY;
					return;
				}				
			} 

		} else if ((positionX > 0.82) && (positionX < 0.99)){
			/* Actions sur les LUT*/

			if ((positionY > 0.88) && (positionY < 0.93)){
				/*Augmenter le contraste*/
				display = ADD_CON;
				keyboard_activation = ACTIVE_KEYBOARD;
			} else if ((positionY > 0.82) && (positionY < 0.87)){
				/*Diminuer le contraste*/
				display = DIM_CON;
				keyboard_activation = ACTIVE_KEYBOARD;
			} else if ((positionY > 0.76) && (positionY < 0.81)){
				/*Augmenter la luminosite*/
				display = ADD_LUM;
				keyboard_activation = ACTIVE_KEYBOARD;
			} else if ((positionY > 0.70) && (positionY < 0.75)){
				/*Diminuer la luminosite*/
				display = DIM_LUM;
				keyboard_activation = ACTIVE_KEYBOARD;
			} else if ((positionY > 0.64) && (positionY < 0.69)){
				/*Sepia*/
				display = EFFECT_SEPIA;
				addLUTOnLayout(currentLayout, SEPIA);
				
			} else if ((positionY > 0.58) && (positionY < 0.63)){
				/*Noir et blanc*/
				display = EFFECT_GRAYSCALE;
				addLUTOnLayout(currentLayout, GRAYSCALE);
				
			} else if ((positionY > 0.52) && (positionY < 0.57)){
				/*Negatif*/
				display = EFFECT_INVERT;
				addLUTOnLayout(currentLayout, INVERT); //TODO rester afficher :(
				
			} else if ((positionY > 0.46) && (positionY < 0.51)){
				/*Supprimer la LUT active*/
				deleteLUT(currentLayout);
				
			} 
		}

		if (((positionX < 0.60) || (positionX > 0.99)) && ((positionY < 0.08) ||(positionY > 0.44))){
			memset(letter_entry, 0, sizeof(letter_entry));
		}
	}

	switch(currentMode){
		case LAYOUT_IMG:
			actualiseImage(currentLayout->img->pixels);
		break;
		case LAYOUT_SRC:
			actualiseImage(currentLayout->src->pixels);
		break;
		case FINAL_IMG:
			actualiseImage(calculateFinalImage(firstLayout)->pixels);
		break;
		default: 
		break;
	}

	if ((display != SAVE_IMG) && (display != CHGMT_OPACITY) && (display != LOAD_IMG) && (display != DIM_LUM) && 
		(display != ADD_LUM) && (display != ADD_CON) && (display != DIM_CON) && (display != OPACITY_FAIL) && (display != LUM_ADD_FAIL) 
		&& (display != LUM_DIM_FAIL) && (display != CON_DIM_FAIL) && (display != CON_ADD_FAIL)){
		keyboard_activation = DISACTIVE_KEYBOARD;
	}



}


int launchImagimp(int argv, char *argc[]) {
    firstLayout = createCanvas(argc[1]);
	if (firstLayout == NULL) {
		fprintf(stderr, "Erreur lors de la création de l'image");
		exit(1);
	}
	currentLayout = firstLayout;

   	fixeFonctionClicSouris(mouseControl);
	fixeFonctionClavier(keyEvent);
	fixeFonctionDessin(drawInterface);

	float added_width = 870.4 - firstLayout->src->w;
	float added_height = 563.4 - firstLayout->src->w;
	if (added_height < 0)
		added_height = 0.1*firstLayout->src->h;
	if (added_width < 0)
		added_width = 0.7*firstLayout->src->w;
    //initGLIMAGIMP(firstLayout->src->w, firstLayout->src->h, firstLayout->src->pixels);
    initGLIMAGIMP_IHM(firstLayout->src->w, firstLayout->src->h, firstLayout->src->pixels, firstLayout->src->w + added_width, firstLayout->src->h + added_height);
    
    
    return 1;
}
