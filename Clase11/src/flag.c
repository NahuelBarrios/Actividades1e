/*
 * flag.c
 *
 *  Created on: 3 may. 2020
 *      Author: Nahu_
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "flag.h"


int altaOrquesta(eOrquesta array[], int size, int* contadorID,eMusico array2[],int size2)
{
    int retorno=-1;
    int posicion;
    int posicion2;
    int bufferIdMusico;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyOrquesta(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            utn_getUnsignedInt("\nIngrese el id de musico: ","\nError",1,sizeof(int),1,1000,3,&bufferIdMusico);
            if(buscarIdMusico(array,size,array2,size2,bufferIdMusico,&posicion,&posicion2)==-1)
             {
            	printf("\nNo existe ese id");
             }
            else
            {
            	(*contadorID)++;
            	array[posicion].idOrquesta=*contadorID;
            	array[posicion].isEmptyOrquesta=0;
            	utn_getTexto("\nIngrese el nombre: ","\nError",1,51,1,array[posicion].nombreOrquesta);
            	utn_getTexto("\nIngrese el lugar: ","\nError",1,51,1,array[posicion].lugarOrquesta);
            	utn_getUnsignedInt("\nIngrese el tipo 1-Sinfonica 2-Filarmonica 3-Camara: ","\nError",1,sizeof(int),1,3,3,&array[posicion].tipoOrquesta);

            printf("\n\nID: %d\nNombre de orquesta: %s\nLugar : %s\nTipo de orquesta: %d\nId Musico: %d\n**************************************",
                    array[posicion].idOrquesta,array[posicion].nombreOrquesta,array[posicion].lugarOrquesta,array[posicion].tipoOrquesta,array[posicion].idMusico);
            retorno=0;
            }
        }
    }
    return retorno;
}


int buscarIdMusico(eOrquesta array[],int size,eMusico array2[], int size2, int valorBuscado, int* posicion,int* posicion2)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && valorBuscado>=0 && posicion!= NULL && array2 != NULL && size2 >0 && posicion2 != NULL)
    {
    	        for(i=0;i<size;i++)
    	        {
    	            if(array2[i].isEmptyMusico==1)
    	                continue;
    	            else if(array2[i].idMusico==valorBuscado)
    	            {
    	                retorno=0;
    	                *posicion=i;
    	                array[i].idMusico = valorBuscado;
    	                break;
    	            }
    	        }
    	    }
    	    return retorno;
}
