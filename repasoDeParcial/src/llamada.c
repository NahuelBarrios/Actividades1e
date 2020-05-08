/*
 * llamada.c
 *
 *  Created on: 6 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "llamada.h"

int inicializarLlamada(eLlamada array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmptyLlamada=1;
        }
        retorno=0;
    }
    return retorno;
}


int buscarEmptyLlamada(eLlamada array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyLlamada==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int finLlamada(eLlamada array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;
    int option;
    if(array!=NULL && size>0)
    {
    	utn_getUnsignedInt("\nIngrese el id Abonado: ","\nError.",1,sizeof(int),1,size,3,&id);
    	        	if(buscarIdLlamada(array,size,id,&posicion)==-1)
    	        	{
    	        		printf("\nNo Existe ese Id\n");
    	        	}

    	        	else
    	        	{

    	        		utn_getFloat("\nTiempo insumido (EN SEGUNDOS): ","\nError",1,sizeof(float),1,1000,3,&array[posicion].tiempoInsumido);
    	        		utn_getUnsignedInt("\nSu estado esta: \n1-Solucionado\n2-No solucionado: ","\nError.",1,sizeof(int),1,size,3,&option);
    	        		switch(option)
    	        		{
    	        		case 1:
    	        			strcpy(array[id].estado,"SOLUCIONADO");
    	        			break;
    	        		case 2:
    	        			strcpy(array[id].estado,"NO SOLUCIONADO");
    	        			break;
    	        		default: printf("\nIngrese la opcion entre 1 o 2\n");


    	        		}

    	        		printf("\nMotivo: %s",array[id].estado);

    	            retorno=0;
    	        	}
    }
    return retorno;
}

int buscarIdLlamada(eLlamada array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmptyLlamada==1)
                continue;
            else if(array[i].idLlamada==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

