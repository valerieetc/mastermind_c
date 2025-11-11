#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "mastermind.h"

int main(int argc, char **argv) {

    srand(time(NULL));

    int attempts = 0;    
    int code[4];
    int userguess[4];

    int cparam = 0;
    int tparam = 0;

//Checks if "-c" and/or "-t" parameters were used, if yes assigns code and attempts
    if (argc % 2 == 0 || argc > 5) {
        printf("Wrong input!\n");
        return 0;
    }
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 >= argc) {
                printf("Wrong input!\n");
                return 0;
            } 
            if (isvalid(argv[i + 1]) == 0) {
                return 0;
            }
            numtoarray(atoi(&argv[i + 1][0]), code);
            cparam++; 
            
        } else if (strcmp(argv[i], "-t") == 0) {
            if (i + 1 >= argc) {
                printf("Wrong input!\n");
                return 0;
            }
            if (isnumvalid(argv[i + 1]) == 0) {
                return 0;
            }
            attempts = atoi(&argv[i + 1][0]);
            if (attempts == 0) {
                printf("Wrong input!\n");
                return 0;
            }
            tparam++; 
            
        }
    }

    if ((cparam == 1 && argc == 4) || (tparam == 1 && argc == 4) || cparam > 1 || tparam > 1) {
        printf("Wrong input!\n");
        return 0;
    }

//If "-c" wasn't used, generates random secret code
    if (cparam == 0) {
        generatecode(code);
    }

//If "-t" wasn't used, default attempts are 10
    if (tparam == 0) {
        attempts = 10;
    }

//Starts the game
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    int round = 0;
    
//First round starts. if attempt isn't successful, loops to next round    
    while (round < attempts) {
        printf("---\n");
        printf("Round %d\n", round);

        char input[20] = "";
        int i = 0;
        char c = 0;

//Reads user input. if input isn't valid, asks for input again        
        do {
            input[0] = '\0';
            i = 0;
            c = 0;
            while (c != '\n') {
                //Checks for Ctrl + D
                if (read(0, &c, 1) == 0) {
                    return 0;
                }
                input[i] = c;
                i++;
            }
            input[i] = '\0';
        } while (isvalid(input) == 0); 
        
//Once input is valid, turns input into int array
        numtoarray(atoi(&input[0]), userguess);

//Counts results, exits loop if code fully matches
        if (countresult(code, userguess) == 1) {
            break;
        } else {
            round++;
        }
    }

//Prints that you've lost if you run out of attempts
    if (round == attempts) {
        printf("You lost! Better luck next time!\n");
    }
}
