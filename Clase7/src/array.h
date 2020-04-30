/*
 * array.h
 *
 *  Created on: 16 abr. 2020
 *      Author: Nahu_
 */

#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct
{
	int idFecha;
	int dia;
	int mes;
	int anio;
	int isEmpty;
}fechaE;

typedef struct
{
	int legajo; // (id)
	char sexo[51];
	int edad;
	int nota1P;
	int nota2P;
	char apellidos[51];
	float promedio;
	fechaE fechaDeIngreso;
	int idCarrera;
	int isEmpty;
}colegioE;

int initColegio(colegioE pArray[],int limite);

int initFecha(fechaE pArray[],int limite);

int cargarPersona(colegioE array[], int size,int* contadorLegajo);

int cargarFecha(fechaE array[],int size,int* contadorFecha);

int buscarEmpty(colegioE array[], int size, int* posicion);

int buscarEmptyfecha(fechaE array[], int size, int* posicion);

int mostrarUnEstudiante(colegioE array[], int size,int idBuscado,fechaE array2[],int size2);

int mostrarEstudiantes(colegioE array[], int size);

int estructuraOrdenada(colegioE array[], int size);

int buscarLegajo(colegioE array[], int size, int valorBuscado);

int buscarID(colegioE array[], int size, int valorBuscado, int* posicion);
#endif /* ARRAY_H_ */
