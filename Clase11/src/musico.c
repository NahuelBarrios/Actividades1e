/*
 * musico.c
 *
 *  Created on: 2 may. 2020
 *      Author: Nahu_
 */


#include <stdio.h>
#include <stdlib.h>
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

int altaMusico(eMusico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyMusico(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusico=*contadorID;
            array[posicion].isEmptyMusico=0;
            utn_getName("\nIngrese Nombre del musico: : ","\nError",1,51,1,array[posicion].nombreMusico);
            utn_getName("\nIngrese Apellido del musico: : ","\nError",1,51,1,array[posicion].apellidoMusico);
            utn_getUnsignedInt("\nIngrese la edad del musico: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edadMusico);
            printf("\nID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   array[posicion].idMusico,array[posicion].nombreMusico,array[posicion].apellidoMusico,array[posicion].edadMusico);
            retorno=0;
        }
    }
    return retorno;
}


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

