#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <glib.h> //I tried to include a library with a builtin
//hashmap, but it looks like a pain to install it on windows.
//I'm using gcc 11.2.0 installed on C:\cygwin64\bin\gcc.exe
#define BIG_NUMBER 150

//LOL C doesn't have classes nor hashmaps
// typedef struct {
//     int x, y;
// } Point;

int has_neighbour_symbol(char **lines, int i, int j, int numLines, int lineLength) {
    for (int k = i-1; k <= i+1; k++) {
        for (int l = j-1; l <= j+1; l++) {
            if (k >= 0 && k < numLines && l >= 0 && l < lineLength ) {
                if (lines[k][l] != '.' && !(lines[k][l] >= '0' && lines[k][l] <= '9')) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int numLines = 0;
    char **lines = malloc(sizeof(char*) * BIG_NUMBER);
    size_t size;
    int lineLength = getline(&lines[0], &size, stdin) - 2, newLineLength;
    while (1) {
        numLines += 1;
        newLineLength = getline(&lines[numLines], &size, stdin) - 2; //Good job C was giving me a false line length...
        if (newLineLength >= 0) {
            assert(newLineLength == lineLength);
        }
        else {
            break;
        }
    }
    printf("Number of lines: %d\n", numLines);
    printf("Line length: %d\n", lineLength);

    //Vull algo que guardi estrella -> números adjacents
    //una estrella és (i, j) -> [números adjacents]
    //I miss vectors so much
    
    int ***starNumbers = malloc(sizeof(int**) * BIG_NUMBER);
    for (int i = 0; i < numLines; i++) {
        starNumbers[i] = malloc(sizeof(int*) * lineLength);
        for (int j = 0; j < lineLength; j++) {
            starNumbers[i][j] = malloc(sizeof(int) * BIG_NUMBER);
            starNumbers[i][j][0] = 0;
        }
    }
    int suma = 0;

    for (int i = 0; i < numLines; i++) {
        for (int j = 0; j < lineLength; j++) {
            if (lines[i][j] >= '0' && lines[i][j] <= '9') {
                //I found a number
                int jInicial = j;
                int number = lines[i][j] - '0';
                int valid = has_neighbour_symbol(lines, i, j, numLines, lineLength);
                while (j+1 < lineLength && lines[i][j+1] >= '0' && lines[i][j+1] <= '9') {
                    j += 1;
                    valid = valid || has_neighbour_symbol(lines, i, j, numLines, lineLength);
                    number = number*10 + (lines[i][j] - '0');
                }
                int jFinal = j;
                if (valid) {
                    suma += number;
                    for (int k = i-1; k <= i+1; k++) {
                        for (int l = jInicial-1; l <= jFinal+1; l++) {
                            if (k >= 0 && k < numLines && l >= 0 && l < lineLength && lines[k][l]=='*') {
                                starNumbers[k][l][0] += 1;
                                starNumbers[k][l][starNumbers[k][l][0]] = number;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Suma: %d\n", suma); //548370 too high

    int suma2 = 0;
    for (int i = 0; i < numLines; i++) {
        for (int j = 0; j < lineLength; j++) {
            if (starNumbers[i][j][0] == 2) {
                suma2 += starNumbers[i][j][1] * starNumbers[i][j][2];
            }
        }
    }
    printf("Suma2: %d\n", suma2);

    for (int i = 0; i < numLines; i++) {
        free(lines[i]);
    }
    free(lines);
    return 0;
}

/*
If I wanted to install glib on windows, I would have to:

Open cygwin terminal and type: "setup-x86_64.exe"
Search for "libglib2.0-devel", select it and install it

Then, to compile, I would have to type:
gcc your_program.c `pkg-config --cflags --libs glib-2.0`
*/
