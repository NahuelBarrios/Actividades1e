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
	int idInstrumento;
	int isEmptyMusico;

}eMusico;


int inicializarMusico(eMusico array[], int size);

int buscarEmptyMusico(eMusico array[], int size, int* posicion);

int listarMusico(eMusico array[], int size);

int buscarIdMusico(eMusico array[], int size, int valorBuscado, int* posicion);

int bajaMusico(eMusico array[], int size);


#endif /* MUSICO_H_ */
