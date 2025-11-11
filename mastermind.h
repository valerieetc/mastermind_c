#ifndef MASTERMIND_H
#define MASTERMIND_H

void numtoarray(int num, int *arr);
void generatecode(int *arr);
int countresult(int *code, int *guess);
int length(char *input);
int isvalid(char *input);
int isnumvalid(char* str);

#endif
