#ifndef UTILITAIRE_H
#define UTILITAIRE_H
#include <stdio.h>   
#include <string.h>  


void ClearScreen();


void DisplayMenu(char *title, char *options, int n);


int GetIntInput(int min, int max);


void GetStringInput(char *buf, int size);

