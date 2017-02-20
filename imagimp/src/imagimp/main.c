#include <stdio.h>
#include <stdlib.h>

#include "Imagimp.h"

int main(int argv, char *argc[]) {
    if (argv < 2) {
    	fprintf(stderr, "Usage : bin/imagimp fileName");
       	exit(1);
    }

	launchImagimp(argv, argc);
    return 1;
}