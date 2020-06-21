/*
 * pelicula.c
 *
 *  Created on: 18 jun. 2020
 *      Author: Nahu_
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

Cine* pelicula_new()
{
	Cine* pelicula = (Cine*)malloc( sizeof(Cine)); // pido el espacio de memoria

		if(pelicula != NULL) // valido que no sea NULL
		{
			pelicula->idVenta = 0; // CARGO TODOS LOS VALORES EN 0, asi no tienen basura dentro
			strcpy(pelicula->nombrePelicula, "");
			pelicula->dia = 0;
			strcpy(pelicula->horario, "");
			pelicula->sala = 0;
			pelicula->cantEntradas = 0;
		}

	return pelicula;
}

Cine* pelicula_newParametros(char* idStr,char* nombreStr,char* diaStr,char* horarioStr,char* salaStr,char* cantEntradasStr)
{
	Cine* pelicula = pelicula_new(); // Le asigno puntero del array el nuevo espacio
	int bufferMonto = 0;
	if(pelicula != NULL)
	{
		pelicula_setId(pelicula,atoi(idStr)); // cargo los datos llamando la funcion set. transformandolos de char a enteros a traves del atoi
		pelicula_setNombre(pelicula,nombreStr);
		pelicula_setDia(pelicula,atoi(diaStr));
		pelicula_setHorario(pelicula,horarioStr);
		pelicula_setSala(pelicula,atoi(salaStr));
		pelicula_setCantEntradas(pelicula,atoi(cantEntradasStr));
		pelicula_setMonto(pelicula,bufferMonto);
	}
return pelicula; // Retorno el empleado
}
//*******************************************************************************************************
int pelicula_delete(Cine* this)
{
	int retorno = -1;
	if(this!=NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************
int pelicula_setId(Cine* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->idVenta = id;
		retorno = 0;
	}
	return retorno;
}

int pelicula_getId(Cine* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->idVenta;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int pelicula_setNombre(Cine* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(this->nombrePelicula,nombre);
		retorno = 0;
	}

	return retorno;
}

int pelicula_getNombre(Cine* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(nombre,this->nombrePelicula);
		retorno = 0;
	}
	return retorno;
}
//*******************************************************************************************************
int pelicula_setDia(Cine* this,int dia)
{
	int retorno = -1;

	if(this!=NULL && dia>=0)
	{
		this->dia = dia;
		retorno = 0;
	}
	return retorno;
}

int pelicula_getDia(Cine* this,int* dia)
{
	int retorno = -1;

		if(this!=NULL && dia!= NULL)
		{
			*dia = this->dia;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int pelicula_setHorario(Cine* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(this->horario,nombre);
		retorno = 0;
	}

	return retorno;
}

int pelicula_getHorario(Cine* this,char* nombre)
{
	int retorno = -1;

	if(this!=NULL && nombre!= NULL)
	{
		strcpy(nombre,this->horario);
		retorno = 0;
	}
	return retorno;
}

//*******************************************************************************************************
int pelicula_setSala(Cine* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->sala = id;
		retorno = 0;
	}
	return retorno;
}

int pelicula_getSala(Cine* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->sala;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int pelicula_setCantEntradas(Cine* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->cantEntradas = id;
		retorno = 0;
	}
	return retorno;
}

int pelicula_getCantEntradas(Cine* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->cantEntradas;
			retorno = 0;
		}
		return retorno;
}
//*******************************************************************************************************
int pelicula_setMonto(Cine* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->monto = id;
		retorno = 0;
	}
	return retorno;
}

int pelicula_getMonto(Cine* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->monto;
			retorno = 0;
		}
		return retorno;
}
