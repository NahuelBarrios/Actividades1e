/*
 * pelicula.h
 *
 *  Created on: 18 jun. 2020
 *      Author: Nahu_
 */

#ifndef PELICULA_H_
#define PELICULA_H_

typedef struct
{
	int idVenta;
	char nombrePelicula[51];
	int dia;
	char horario[51];
	int sala;
	int cantEntradas;
	int monto;

}Cine;

Cine* pelicula_new();
Cine* pelicula_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr,char* cantEntradasStr);
int pelicula_delete(Cine* this);

int pelicula_setId(Cine* this,int id);
int pelicula_getId(Cine* this,int* id);

int pelicula_setNombre(Cine* this,char* nombre);
int pelicula_getNombre(Cine* this,char* nombre);

int pelicula_setDia(Cine* this,int dia);
int pelicula_getDia(Cine* this,int* dia);

int pelicula_setHorario(Cine* this,char* nombre);
int pelicula_getHorario(Cine* this,char* nombre);

int pelicula_setSala(Cine* this,int id);
int pelicula_getSala(Cine* this,int* id);

int pelicula_setCantEntradas(Cine* this,int id);
int pelicula_getCantEntradas(Cine* this,int* id);

int pelicula_setMonto(Cine* this,int id);
int pelicula_getMonto(Cine* this,int* id);

#endif /* PELICULA_H_ */
