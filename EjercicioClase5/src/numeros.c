/*
 * numeros.c
 *
 *  Created on: 10 abr. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "numeros.h"



int imprimirArrayInt(int pArray[],int size)
{
	int i;
	int retorno=-1;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %d\n", i, pArray[i]);
		}
		retorno=0;
	}
	return retorno;
}


//***************************************************************
/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayInt(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<limite - 1 ; i++)
			{
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

//*****************************************************************

int minimo (int* pArray,int size,int *min)
{
	int i;
	int retorno=-1;
	int auxMin;

	if(pArray != NULL && size > 0 && min != NULL)
	{
		for(i = 0; i < size; i++)
		{
			if(i==0)
			{
				auxMin = pArray[i];
			}

			else
			{
				if(auxMin>pArray[i])
				{
					auxMin = pArray[i];
				}
			}

		}
		*min = auxMin;
		retorno=0;
	}
	return retorno;
}

//******************************************************************************

int maximo (int* pArray,int size,int *max)
{
	int i;
	int retorno=-1;
	int auxMin;

	if(pArray != NULL && size > 0 && max != NULL)
	{
		for(i = 0; i < size; i++)
		{
			if(i==0)
			{
				auxMin = pArray[i];
			}

			else
			{
				if(auxMin<pArray[i])
				{
					auxMin = pArray[i];
				}
			}

		}
		*max = auxMin;
		retorno=0;
	}
	return retorno;
}

//**********************************************************************

int promedio(int* pArray,int size,int* promedio)
{
	int i;
	int retorno=-1;
	int acumulador = 0;

	if(pArray != NULL && size > 0 && promedio != NULL)
	{
		for(i = 0; i < size; i++)
		{
			acumulador+= pArray[i];
		}
		*promedio=acumulador/size;
		retorno=0;
	}
	return retorno;

}

//************************************************************************

int comparacion (int* pArray,int size,int num,int *cantIguales)
{
	int i;
	int retorno=-1;
	int contador=0;

	if(pArray != NULL && size > 0 && num >=0 && cantIguales != NULL)
	{
		for(i = 0; i < size; i++)
		{
			if(pArray[i] == num)
			{
				contador++;
			}

		}
		*cantIguales = contador;
		retorno=0;
	}
	return retorno;

}


