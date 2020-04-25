/*
 * numeros.h
 *
 *  Created on: 10 abr. 2020
 *      Author: Nahu_
 */

#ifndef NUMEROS_H_
#define NUMEROS_H_

int imprimirArrayInt(int pArray[],int size);

int ordenarArrayInt(int* pArray, int limite);

int minimo (int* pArray,int size,int *min);

int maximo (int* pArray,int size,int *min);

int promedio(int* pArray,int size,int* promedio);

int comparacion (int* pArray,int size,int num,int *cantIguales);

#endif /* NUMEROS_H_ */

