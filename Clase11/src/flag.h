/*
 * flag.h
 *
 *  Created on: 3 may. 2020
 *      Author: Nahu_
 */

#ifndef FLAG_H_
#define FLAG_H_


int altaMusico(eMusico arrayMusico[], int sizeMusico, int* contadorIDMusico,eOrquesta arrayOrquesta[],int sizeOrquesta,eInstrumento arrayInstrumento[],int sizeInstrumento);

int buscarIdOrquestaParaMusico(eMusico array[],eOrquesta array2[],int size, int valorBuscado, int* posicion);

int buscarIdInstrumentoParaMusico(eMusico array[],eInstrumento array2[],int size, int valorBuscado, int* posicion);

int modificarMusico(eMusico array[], int size,eOrquesta arrayOrquesta[],int sizeOrquesta);

int imprimirMusicoConInstrumento(eMusico array[],int size,eInstrumento arrayInstrumento[],int sizeInstrumento);
#endif /* FLAG_H_ */
