/*
 * abonado.h
 *
 *  Created on: 6 may. 2020
 *      Author: Nahu_
 */

#ifndef ABONADO_H_
#define ABONADO_H_

typedef struct{

int id;
int numero;
char nombre[51];
char apellido[51];
int isEmpty;
}eAbonado;

int inicializarAbonado(eAbonado array[], int size);

int altaAbonado(eAbonado array[], int size, int* contadorID);

int buscarEmptyAbonado(eAbonado array[], int size, int* posicion);

int modificarAbonado(eAbonado array[], int sizeArray);

int buscarIdAbonado(eAbonado array[], int size, int valorBuscado, int* posicion);

int bajaAbonado(eAbonado array[], int sizeArray);

int listarAbonado(eAbonado array[], int size);


#endif /* ABONADO_H_ */
