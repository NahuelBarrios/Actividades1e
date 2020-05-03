#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"

int inicializarInstrumento(eInstrumento array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyInstrumento=1;
        }
        retorno=0;
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int altaInstrumento(eInstrumento array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyInstrumento(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idInstrumento=*contadorID;
            array[posicion].isEmptyInstrumento=0;
            utn_getTexto("\nIngrese el nombre del instrumento : ","\nError",1,51,1,array[posicion].nombreInstrumento);
            utn_getTexto("\nIngrese tipo de intrumento: Cuerdas - (Viento-Madera) - (Viento-Metal) - Percusión: ","\nError",1,51,1,array[posicion].tipoInstrumento);
            printf("\n******************\n ID: %d\nNombre instrumento: %s\nTipo instrumento: %s",
                   array[posicion].idInstrumento,array[posicion].nombreInstrumento,array[posicion].tipoInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

int buscarEmptyInstrumento(eInstrumento array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyInstrumento==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
