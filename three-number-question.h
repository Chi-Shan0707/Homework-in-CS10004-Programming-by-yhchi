#ifndef THREE_NUMBER_QUESTION_H
#define THREE_NUMBER_QUESTION_H

int readFromString(const char* str, int* index);
int MAX(int x, int y);
int MIN(int x, int y);
void calculateStats(int a, int b, int c, int* sum, float* average, int* max, int* min);

#endif