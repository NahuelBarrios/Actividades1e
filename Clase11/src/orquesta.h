/*
 * orquesta.h
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */

#ifndef ORQUESTA_H_
#define ORQUESTA_H_

typedef struct
{
	int idOrquesta;
	char nombreOrquesta[51];
	char lugarOrquesta[51];
	int tipoOrquesta;
	int idMusico;
	int isEmptyOrquesta;


}eOrquesta;

int inicializarOrquesta(eOrquesta array[], int size);

int altaOrquesta(eOrquesta array[], int size, int* contadorID);

int buscarEmptyOrquesta(eOrquesta array[], int size, int* posicion);

int bajaOrquesta(eOrquesta array[], int sizeArray);

int buscarIdOrquesta(eOrquesta array[], int size, int valorBuscado, int* posicion);

int listarOrquesta(eOrquesta array[], int size);

#endif /* ORQUESTA_H_ */
