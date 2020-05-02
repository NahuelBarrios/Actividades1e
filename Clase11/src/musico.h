/*
 * musico.h
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */

#ifndef MUSICO_H_
#define MUSICO_H_

typedef struct
{
	int idMusico;
	char nombreMusico[51];
	char apellidoMusico[51];
	int edadMusico;
	int idOrquesta;
	int idIntrumento;
	int isEmptyMusico;

}eMusico;


int inicializarMusico(eMusico array[], int size);

int altaMusico(eMusico array[], int size, int* contadorID);

int buscarEmptyMusico(eMusico array[], int size, int* posicion);

#endif /* MUSICO_H_ */
