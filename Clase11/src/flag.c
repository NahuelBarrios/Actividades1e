/*
 * flag.c
 *
 *  Created on: 3 may. 2020
 *      Author: Nahu_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        		printf("\nNo existe ese id de orquesta");


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

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int modificarMusico(eMusico array[], int size,eOrquesta arrayOrquesta[],int sizeOrquesta)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    int bufferIdOrquesta;
    if(array!=NULL && size>0)
    {
        utn_getUnsignedInt("\nID de Musico a modificar: ","\nError",1,sizeof(int),1,size,1,&id);
        if(buscarIdMusico(array,size,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\nQue desea modificar?:\nA-Edad\nB-Id de orquesta\nS-Salir","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	 utn_getUnsignedInt("\nIngrese la edad del musico a modificar: ","\nError",1,sizeof(int),1,60,1,&array[posicion].edadMusico);
                        break;
                    case 'B':
                    	utn_getUnsignedInt("\nIngrese el id del musico a modificar: ","\nError",1,sizeof(int),1,60,1,&bufferIdOrquesta);
                    	if(buscarIdOrquestaParaMusico(array,arrayOrquesta,sizeOrquesta,bufferIdOrquesta,&posicion)==-1)
                    	{
                    		printf("\nNo existe ese id de musico");
                    	}
                    	else
                    	{
                    		printf("\n Se cargo el nuevo Id.");
                    	}
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

int imprimirMusicoConInstrumento(eMusico array[],int size,eInstrumento arrayInstrumento[],int sizeInstrumento)
{
	int retorno=-1;
	    int i;
	    int bufferInstrumento;
	    if(array!=NULL && size>=0)
	    {
	        for(i=0;i<size;i++)
	        {
	            if(array[i].isEmptyMusico==1)
	            {
	                continue;
	            }
	            else
	            {
	            		bufferInstrumento = array[i].idInstrumento;
	            		if(buscarInstrumento(arrayInstrumento,sizeInstrumento,bufferInstrumento,&i)==-1)
	            		{
	            			printf("\nNo existe este ID");
	            		}
	            		else
	            		{
	            			printf("\n**************************************\nID: %d\nNombre de Musico: %s\nApellido de musico: %s\nId de instrumento: %d\nNombre de instrumento: %s\nTipo de instrumento: %s",
	            			array[i].idMusico,array[i].nombreMusico,array[i].apellidoMusico,array[i].idInstrumento,arrayInstrumento[i].nombreInstrumento,arrayInstrumento[i].tipoInstrumento);
	            		}
	            }

	        }
	        retorno=0;
	    }
	    return retorno;

}
