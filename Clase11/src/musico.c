/*
 * musico.c
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "musico.h"

int inicializarMusico(eMusico array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyMusico=1;
        }
        retorno=0;
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int buscarEmptyMusico(eMusico array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyMusico==1)
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

int listarMusico(eMusico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyMusico==1)
                continue;
            else
            	printf("\n**************************************\nID: %d\nNombre de Musico: %s\nApellido : %s",
            	    			                    array[i].idMusico,array[i].nombreMusico,array[i].apellidoMusico);
        }
        retorno=0;
    }
    return retorno;
}

int buscarIdMusico(eMusico array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyMusico==1)
                continue;
            else if(array[i].idMusico==valorBuscado)
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

int bajaMusico(eMusico array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && size>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,size,1,&id);
        if(buscarIdMusico(array,size,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmptyMusico=1;
            array[posicion].idMusico=0;
            array[posicion].edadMusico=0;
            array[posicion].idOrquesta=0;
            array[posicion].idInstrumento=0;
            strcpy(array[posicion].nombreMusico,"");
            strcpy(array[posicion].apellidoMusico,"");
            retorno=0;
        }
    }
    return retorno;
}
