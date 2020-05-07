/*
 * llamada.h
 *
 *  Created on: 6 may. 2020
 *      Author: Nahu_
 */

#ifndef LLAMADA_H_
#define LLAMADA_H_

typedef struct
{
	int idLlamada;
	int idAbonado;
	char motivo[51];// "Falla 3G" - "FALLA LTE" - "FALLA EQUIPO"
	char estado[51];// "En curso" - "Solucionado" - "No Solucionado"
	float tiempoInsumido;
	int isEmptyLlamada;
}eLlamada;

int inicializarLlamada(eLlamada array[], int size);

int buscarEmptyLlamada(eLlamada array[], int size, int* posicion);
#endif /* LLAMADA_H_ */
