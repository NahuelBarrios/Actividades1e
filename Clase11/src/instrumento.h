/*
 * instrumento.h
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */

#ifndef INSTRUMENTO_H_
#define INSTRUMENTO_H_

typedef struct
{
	int idInstrumento;
	char nombreInstrumento[51];
	char tipoInstrumento[51];// 1-Cuerdas- 2-(Viento-Madera) 3-(Viento-Metal) 4-Percusión
	int isEmptyInstrumento;

}eInstrumento;

int inicializarInstrumento(eInstrumento array[], int size);

int altaInstrumento(eInstrumento array[], int size, int* contadorID);

int buscarEmptyInstrumento(eInstrumento array[], int size, int* posicion);

int buscarInstrumento(eInstrumento array[], int size, int valorBuscado, int* posicion);

int imprimirInstrumento(eInstrumento array[],int size);

#endif /* INSTRUMENTO_H_ */
