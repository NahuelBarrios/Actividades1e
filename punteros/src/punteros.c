/*
 ============================================================================
 Name        : punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	// Guarda la direccion de memoria de otra variable en un puntero. Operador de direccion(&).
	int* punteroInt = NULL;
	char* punteroChar = NULL;
	float* punteroFloat = NULL;

	int auxInt= 10;
	char auxChar = 'c';
	float auxFloat = 3.14;

	punteroInt = &auxInt;
	punteroChar = &auxChar;
	punteroFloat = &auxFloat;

	printf("Int:%p\nchar:%p\nfloat:%p",punteroInt,punteroChar,punteroFloat);
	printf("\nint %i",*punteroInt);//Operador de indireccion(*). Muestra el contenido que tiene auxInt. Desde el puntero.con el aterisco(*).
									// *punteroInt = ACCESO AL VALOR DE AUXINT OSEA AL 10

	auxInt = (int)&auxChar;
	printf("\nDireccion de auxChar %d",auxInt);
	return 0;
}
