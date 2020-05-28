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


	char arrayChar[]="Hola Mundo";
	*(arrayChar+4)='#';
	printf("\n%s",arrayChar);

	/*	 //Variable puntero que apunta al primer elemento de un arreglo.
	 * int vec[10];
int* p;  //Puntero al primer elemento de un vector
int i;
printf("Direccion de p, %p", &p);
for(i=0;i<10;i++){
    vec[i]= i;
}
//EL puntero p apunta a la dirección del primer elemento del vector
p=vec;
for (i=0;i<10;i++)
{
   printf("\nNomenclatura vectorial: %d", vec[i]);
   printf("\nAritmetica de Punteros: %d", *(p+i));
   printf("\nDireccion de p: %p", (&p+i));
}

 *
 * //Vector de Punteros
//Cargar un vector con las direcciones de memoria de variables
int main()
{
int i;
int var1=100, var2=200, var3=300,var4=400, var5=500;
//Vector de Punteros
int* vec[5];
vec[0]=&var1;
vec[1]=&var2;
vec[2]=&var3;
vec[3]=&var4;
vec[4]=&var5;
printf("\nDir de memoria de var1: %p ", &var1);
printf("\nDir de memoria de var2: %p ", &var2);
printf("\nDir de memoria de var3: %p ", &var3);
printf("\nDir de memoria de var4: %p ", &var4);
printf("\nDir de memoria de var5: %p ", &var5);
for (i=0;i<5;i++){
   printf("\nValores del vector: %p ", vec[i]);
}
printf("\nValor de var1: %d ", var1);
printf("\nValor de var2: %d ", var2);
printf("\nValor de var3: %d ", var3);
printf("\nValor de var4: %d ", var4);
printf("\nValor de var5: %d ", var5);
for (i=0;i<5;i++){
   printf("\nValores de lo apuntado por cada elemento del vector: %d ", *vec[i]);
}
 *

	 */


	return 0;
}
