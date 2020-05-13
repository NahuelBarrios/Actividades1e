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
    int contReclamo= 0;
    int bufferIdAbonado;
    int posicion2;
    int motivo1 = 0;
    int motivo2 = 0;
    int motivo3 = 0;
    if(array!=NULL && size>0 && contadorID!=NULL && array2!=NULL && size2>0) // Valido
    {
        if(buscarEmptyLlamada(array,size,&posicion)==-1) // Recorro el isEmpty para averiguar si hay espacio
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	utn_getUnsignedInt("\nIngrese el id Abonado: ","\nError.",1,sizeof(int),1,size,3,&bufferIdAbonado); // Pido un ud
        	if(buscarIdAbonado(array2,size2,bufferIdAbonado,&posicion2)==-1) // Valido si existe o no
        	{
        		printf("\nNo Existe ese Id\n");
        	}

        	else
        	{
        		// Si existe Cargo lo siguiente
            (*contadorID)++;
            array[posicion].idLlamada=*contadorID;
            array[posicion].isEmptyLlamada=0;
            array[posicion].idAbonado=bufferIdAbonado;
            contReclamo=array2[bufferIdAbonado].contReclamos + 1;
            array2[bufferIdAbonado].contReclamos = contReclamo;
            printf("ContReclamos: %d",array2[bufferIdAbonado].contReclamos);
            utn_getTexto("\nIngrese motivo: FALLA 3G - FALLA LTE - FALLA EQUIPO ","\nError",1,51,3,array[posicion].motivo);
            if(strcmp(array[posicion].motivo,"FALLA 3G"))
           	{
            	motivo1++;

      		}
            if(strcmp(array[posicion].motivo,"FALLA LTE"))
            {
            	motivo2++;
            }
            if(strcmp(array[posicion].motivo,"FALLA EQUIPO"))
            {
            	motivo3++;
            }
            informe2(motivo1,motivo2,motivo3);
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

int informes (eAbonado array2[],int size2)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int maximo;
	int id;

	if(array2!=NULL && size2>0)
	{
		for (i=0;i < size2 ;i++) // Recorro el array
		{
			if(array2[i].isEmpty ==1) // si esta vacio q lo salte
				continue;
			if(flag ==0)
			{
			maximo = array2[i].contReclamos; // le asigno el 1er valor a maximo
			id = array2[i].id;// le asigno el 1er id del abonado a id.
			flag =1; // flag =1. No entra mas a este if
			}
			else
			{
				if(array2[i].contReclamos > maximo) // Saco maximo
				{
					maximo = array2[i].contReclamos; // si el nuevo contReclamos es mas grande que el anterior se le asigna a maximo
					id = array2[i].id; // le asigno el id del nuevo maximo
				}

			}

		}

		printf("\n\nAbonado con mas reclamos:\nid: %d\nNombre: %s\nApellido: %s\nCant de reclamos: %d\n",id,array2[id].nombre,array2[id].apellido,maximo); // Lo imprimo

		if (auxMotivo1 > auxMotivo2 && auxMotivo1>auxMotivo3)
					{
						MotivoMaximo = auxMotivo1;
						printf("\nEl reclamo mas realizado fue: FALLA 3G. con %d de reclamos.\n",MotivoMaximo);
				 	 }
					else if (auxMotivo2 > auxMotivo1 && auxMotivo2>auxMotivo3)
					{
						MotivoMaximo = auxMotivo2;
						printf("\nEl reclamo mas realizado fue: FALLA LTE. con %d de reclamos.\n",MotivoMaximo);
					}
				else
					{
						MotivoMaximo = auxMotivo3;
						printf("\nEl reclamo mas realizado fue: FALLA EQUIPO. con %d de reclamos.\n",MotivoMaximo);
					}


		retorno = 0;
		}
	return retorno;
}

int informe2 (int motivo1,int motivo2, int motivo3)
{
	int auxMotivo1 = 0;
	int auxMotivo2 = 0;
	int auxMotivo3 = 0;
	int MotivoMaximo;

	auxMotivo1 = auxMotivo1 + motivo1;
	auxMotivo2 = auxMotivo2+ motivo2;
	auxMotivo3 = auxMotivo3 + motivo3;


	return 0;
}


/*
int imprimirLlamada(eLlamada array[], int size,eAbonado array2[],int size2)
{
    int retorno=-1;
        int i;
        if(array!=NULL && size>0 && array2!=NULL && size2>0)
            {
            for(i=0;i<size;i++)
            {
                if(array[i].isEmptyLlamada==1 &&array2[i].isEmpty==1 )
                    continue;
                else
                    if(array[i].idLlamada>0){
                    printf("\n**\nID LLAMADA:[ %d ]\nMotivo del Reclamo:[ %d ]\n (1-FALLA 3G / 2-FALLA LTE  /  3-FALLA EQUIPO) \n\n**\n\nApellido del Abonado :[ %s ]\Nombre del Abonado :[ %s ]",
                                                array[i].idLlamada,array[i].motivo,array2[i].apellido,array2[i].nombre);
            }}

            retorno=0;
        }
        return retorno;


}
*/
