/*
 * orquesta.c
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"


int inicializarOrquesta(eOrquesta array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyOrquesta=1;
        }
        retorno=0;
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int altaOrquesta(eOrquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyOrquesta(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idOrquesta=*contadorID;
            array[posicion].isEmptyOrquesta=0;
            utn_getTexto("\nIngrese el nombre: ","\nError",1,51,1,array[posicion].nombreOrquesta);
            utn_getTexto("\nIngrese el lugar: ","\nError",1,51,1,array[posicion].lugarOrquesta);
            utn_getUnsignedInt("\nIngrese el tipo 1-Sinfonica 2-Filarmonica 3-Camara: ","\nError",1,sizeof(int),1,3,3,&array[posicion].tipoOrquesta);
            printf("\n\nID: %d\nNombre de orquesta: %s\nLugar : %s\nTipo de orquesta: %d",
                    array[posicion].idOrquesta,array[posicion].nombreOrquesta,array[posicion].lugarOrquesta,array[posicion].tipoOrquesta);
            retorno=0;
        }
    }
    return retorno;
}

int buscarEmptyOrquesta(eOrquesta array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyOrquesta==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
