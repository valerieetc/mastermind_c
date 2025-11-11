#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "mastermind.h"

//Turns code from number into an array
void numtoarray(int num, int *arr) {
    int j = 3;
    while (j >= 0) {
        arr[j] = num % 10;
        num = num / 10;
        j--;
    }
}

//Generates random code
void generatecode(int *arr) {
    int max = 8;
    int min = 0;
    
    for (int i = 0; i < 4; i++) {
        int tempnum = rand() % (max - min + 1) + min;
        for (int j = 0; j < i; j++) {
            if (tempnum == arr[j]) {
                tempnum = rand() % (max - min + 1) + min;
                j = -1;
            }
        }
        arr[i] = tempnum;
    }
}

//Counts the wellplaced and misplaced numbers
int countresult(int *code, int *guess) {
    int wellplaced = 0;
    int misplaced = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (guess[i] == code[j] && i == j) {
                wellplaced++;
            } else if (guess[i] == code[j] && i != j) {
                misplaced++;
            }
        }
    }
        
    if (wellplaced != 4) {
        printf("Well placed pieces: %d\n", wellplaced);
        printf("Misplaced pieces: %d\n", misplaced);
        return 0;
    } else if (wellplaced == 4) {
        printf("Congratz! You did it!\n");
        return 1;
    }

    return 0;
}

//Checks if user input is valid
int isvalid(char *str) {
    
    int len = length(str);
    if (len != 4) {
        printf("Wrong input!\n");
        return 0;
    } 
        
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '8') {
            printf("Wrong input!\n"); 
            return 0;
        }
        }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                printf("Wrong input!\n");
                return 0;
            }
        }
    }

    return 1;
}

//Counts the length of a string
int length(char *str) {
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }

    return i;
}

int isnumvalid(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            printf("Wrong input!\n");
            return 0;
        }
        i++;
    }

    return 1;
}
