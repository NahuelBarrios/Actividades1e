/*
 * orquesta.c
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"


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

int bajaOrquesta(eOrquesta array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int i;
    if(array!=NULL && sizeArray>0)
    {
    	for(i=0;i<sizeArray;i++)
    	{
    		if(array[i].isEmptyOrquesta==1)
    		{
    			continue;
    		}
    		else
    		{
    			printf("\n**************************************\nID: %d\nNombre de orquesta: %s\nLugar : %s\nTipo de orquesta: %d\nId Musico: %d\n",
    			                    array[i].idOrquesta,array[i].nombreOrquesta,array[i].lugarOrquesta,array[i].tipoOrquesta,array[i].idMusico);
    		}
    	}


        utn_getUnsignedInt("\nId de Orquesta a  cancelar: ","\nError",1,sizeof(int),1,sizeArray,3,&id);
        if(buscarIdOrquesta(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	array[posicion].isEmptyOrquesta=1;
            array[posicion].idOrquesta=0;
            strcpy(array[posicion].nombreOrquesta,"");
            strcpy(array[posicion].lugarOrquesta,"");
            array[posicion].tipoOrquesta=0;
            array[posicion].idMusico=0;
            retorno=0;
        }
    }
    return retorno;
}

int buscarIdOrquesta(eOrquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyOrquesta==1)
                continue;
            else if(array[i].idOrquesta==valorBuscado)
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

int listarOrquesta(eOrquesta array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyOrquesta==1)
                continue;
            else
            	printf("\n**************************************\nID: %d\nNombre de orquesta: %s\nLugar : %s\nTipo de orquesta: %d\nId Musico: %d\n",
            	    			                    array[i].idOrquesta,array[i].nombreOrquesta,array[i].lugarOrquesta,array[i].tipoOrquesta,array[i].idMusico);
        }
        retorno=0;
    }
    return retorno;
}
