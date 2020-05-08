/*
 * flag.c
 *
 *  Created on: 7 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "llamada.h"
#include "abonado.h"
#include "flag.h"


int inicioLlamada(eLlamada array[], int size, int* contadorID,eAbonado array2[],int size2)
{
    int retorno=-1;
    int posicion;
    int bufferIdAbonado;
    int posicion2;
    if(array!=NULL && size>0 && contadorID!=NULL && array2!=NULL && size2>0)
    {
        if(buscarEmptyLlamada(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	utn_getUnsignedInt("\nIngrese el id Abonado: ","\nError.",1,sizeof(int),1,size,3,&bufferIdAbonado);
        	if(buscarIdAbonado(array2,size2,bufferIdAbonado,&posicion2)==-1)
        	{
        		printf("\nNo Existe ese Id\n");
        	}

        	else
        	{

            (*contadorID)++;
            array[posicion].idLlamada=*contadorID;
            array[posicion].isEmptyLlamada=0;
            array[posicion].idAbonado=bufferIdAbonado;
            utn_getTexto("\nIngrese motivo: FALLA 3G - FALLA LTE - FALLA EQUIPO ","\nError",1,51,3,array[posicion].motivo);
            strcpy(array[posicion].estado,"EN CURSO");
            printf("\nSu estado se encuentra EN CURSO\n");

            printf("\n\nId Llamada: %d\nid Abonado: %d\nMotivo: %s\nEstado: %s",
                   array[posicion].idLlamada,array[posicion].idAbonado,array[posicion].motivo,array[posicion].estado);
            retorno=0;
        	}
        }
    }
    return retorno;
}


