#pragma once

#include <stdio.h>
#include <malloc.h>
#include <math.h>

char* unification(char* a, char* b);
int ConvertToInt(char* s);
char* ConvertToString(int n);
void GetDlinaOtr();
float GetDlina(int x1, int y1, int x2, int y2);
void GetPerPlosh();
int GetProverka(float a, float b, float c);

int Summ(int a, int b)
{
	return a + b;
}

int Rasn(int a, int b)
{
	return a - b;
}

int Prois(int a, int b)
{
	return a * b;
}

float Chast(int a, int b)
{
	return (float)a / (float)b;
}