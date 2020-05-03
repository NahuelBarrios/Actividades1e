/*
 * flag.h
 *
 *  Created on: 3 may. 2020
 *      Author: Nahu_
 */

#ifndef FLAG_H_
#define FLAG_H_

int altaOrquesta(eOrquesta array[], int size, int* contadorID,eMusico array2[],int size2);

int buscarIdMusico(eOrquesta array[],int size,eMusico array2[], int size2, int valorBuscado, int* posicion);

int altaMusico(eMusico array[], int size, int* contadorID,eOrquesta array2[],int size2,eInstrumento array3[],int size3);

int buscarIdOrquesta(eMusico array[],int size,eOrquesta array2[], int size2, int valorBuscado, int* posicion);

int buscarIdInstrumento(eMusico array[],int size,eInstrumento array2[], int size2, int valorBuscado, int* posicion);

#endif /* FLAG_H_ */
