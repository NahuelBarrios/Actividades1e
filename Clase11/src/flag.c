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


//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int altaMusico(eMusico arrayMusico[], int sizeMusico, int* contadorIDMusico,eOrquesta arrayOrquesta[],int sizeOrquesta,eInstrumento arrayInstrumento[],int sizeInstrumento)
{
    int retorno=-1;
    int posicion;
    int bufferIdOrquesta;
    int bufferIdInstrumento;
    if(arrayMusico!=NULL && arrayMusico>0 && contadorIDMusico!=NULL && arrayOrquesta != NULL && sizeOrquesta >0 && arrayInstrumento != NULL && sizeInstrumento >0)
    {
        if(buscarEmptyMusico(arrayMusico,sizeMusico,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	utn_getUnsignedInt("\nIngrese el id de la orquesta: ","\nError",1,sizeof(int),1,sizeOrquesta,3,&bufferIdOrquesta);
        	if(buscarIdOrquestaParaMusico(arrayMusico,arrayOrquesta,sizeOrquesta,bufferIdOrquesta,&posicion)==-1)
        	{
        		printf("\nNo existe ese id de musico");


        	}

        	utn_getUnsignedInt("\nIngrese el id del instrumento: ","\nError",1,sizeof(int),1,sizeInstrumento,3,&bufferIdInstrumento);
        	if(buscarIdInstrumentoParaMusico(arrayMusico,arrayInstrumento,sizeInstrumento,bufferIdInstrumento,&posicion) == -1)
        	{

        		printf("\n no existe ese id de instrumento\n");


        	}

        	else
        	{
            (*contadorIDMusico)++;
            arrayMusico[posicion].idMusico=*contadorIDMusico;
            arrayMusico[posicion].isEmptyMusico=0;
            utn_getName("\nIngrese Nombre del musico: : ","\nError",1,51,1,arrayMusico[posicion].nombreMusico);
            utn_getName("\nIngrese Apellido del musico: : ","\nError",1,51,1,arrayMusico[posicion].apellidoMusico);
            utn_getUnsignedInt("\nIngrese la edad del musico: ","\nError",1,sizeof(int),1,60,1,&arrayMusico[posicion].edadMusico);
            printf("\nID: %d\nnombre de musico: %s\napellido: %s\nedad: %d\n",
                   arrayMusico[posicion].idMusico,arrayMusico[posicion].nombreMusico,arrayMusico[posicion].apellidoMusico,arrayMusico[posicion].edadMusico);
            retorno=0;
        	}
        }
    }
    return retorno;
}

int buscarIdOrquestaParaMusico(eMusico array[],eOrquesta array2[],int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && valorBuscado>=0 && posicion!= NULL && array2 != NULL )
    {
    	        for(i=0;i<size;i++)
    	        {
    	            if(array2[i].isEmptyOrquesta==1)
    	                continue;
    	            else if(array2[i].idOrquesta==valorBuscado)
    	            {
    	                retorno=0;
    	                *posicion=i;
    	                array[i].idOrquesta = valorBuscado;
    	                break;
    	            }
    	        }
    	    }
    	    return retorno;
}

int buscarIdInstrumentoParaMusico(eMusico array[],eInstrumento array2[],int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && valorBuscado>=0 && posicion!= NULL && array2 != NULL)
    {
    	        for(i=0;i<size;i++)
    	        {
    	            if(array2[i].isEmptyInstrumento==1)
    	                continue;
    	            else if(array2[i].idInstrumento==valorBuscado)
    	            {
    	                retorno=0;
    	                *posicion=i;
    	                array[i].idInstrumento = valorBuscado;
    	                break;
    	            }
    	        }
    	    }
    	    return retorno;
}
