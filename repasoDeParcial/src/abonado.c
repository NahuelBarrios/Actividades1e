/*
 * abonado.c
 *
 *  Created on: 6 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "abonado.h"

int inicializarAbonado(eAbonado array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int altaAbonado(eAbonado array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscarEmptyAbonado(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].id=*contadorID;
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nNumero: ","\nError",1,1000000,1,100000,3,&array[posicion].numero);
            utn_getTexto("\nNombre: ","\nError",1,51,3,array[posicion].nombre);
            utn_getTexto("\nApellido: ","\nError",1,51,3,array[posicion].apellido);
            printf("\n\nID: %d\nNumero: %d\nNombre: %s\nApellido: %s",
                   array[posicion].id,array[posicion].numero,array[posicion].nombre,array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

int buscarEmptyAbonado(eAbonado array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int modificarAbonado(eAbonado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(buscarIdAbonado(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {

                utn_getChar("\n\nModificar:\nA-Nombre\nB-Apellido\nS-Salir","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	utn_getTexto("\n: ","\nError",1,51,1,array[posicion].nombre);
                        break;
                    case 'B':
                    	utn_getTexto("\n: ","\nError",1,51,1,array[posicion].apellido);
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

int buscarIdAbonado(eAbonado array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int bajaAbonado(eAbonado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(buscarIdAbonado(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].id=0;
            array[posicion].numero=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}

int listarAbonado(eAbonado array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n\nID: %d\nNumero: %d\nNombre: %s\nApellido: %s",
                       array[i].id,array[i].numero,array[i].nombre,array[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}
