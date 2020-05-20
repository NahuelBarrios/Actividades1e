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

int inicioLlamada(eLlamada array[], int size, int* contadorID,eAbonado array2[],int size2,int* motivo1,int* motivo2,int* motivo3)
{
    int retorno=-1;
    int posicion;
    int contReclamo= 0;
    int bufferIdAbonado;
    int posicion2;

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
            utn_getUnsignedInt("\nIngrese motivo: 1-FALLA 3G / 2-FALLA LTE / 3-FALLA EQUIPO: ","\nError",1,sizeof(int),1,4,3,&array[posicion].motivo);
            if(array[posicion].motivo==1)
           	{
            	(*motivo1)++;
      		}
            if(array[posicion].motivo == 2)
            {
            	(*motivo2)++;
            }
            if(array[posicion].motivo == 3)
            {
            	(*motivo3)++;
            }

            strcpy(array[posicion].estado,"EN CURSO");
            printf("\nSu estado se encuentra EN CURSO\n");

            printf("\n\nId Llamada: %d\nid Abonado: %d\nMotivo 1-FALLA 3G / 2-FALLA LTE / 3-FALLA EQUIPO: %d\nEstado: %s",
                   array[posicion].idLlamada,array[posicion].idAbonado,array[posicion].motivo,array[posicion].estado);
            retorno=0;
        	}
        }
    }
    return retorno;
}

// DE ACA PARA ABAJO, INFORMES
int informes (eAbonado arrayAbonado[],int sizeAbonado,int motivo1,int motivo2,int motivo3)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int maximo;
	int id;
	int motivoMaximo;

	if(arrayAbonado!=NULL && sizeAbonado>0 && motivo1>=0 && motivo2>=0 && motivo3>=0)
	{
		// primer informe
		for (i=0;i < sizeAbonado ;i++) // Recorro el array
		{
			if(arrayAbonado[i].isEmpty ==1) // si esta vacio q lo salte
				continue;
			if(flag ==0)
			{
			maximo = arrayAbonado[i].contReclamos; // le asigno el 1er valor a maximo
			id = arrayAbonado[i].id;// le asigno el 1er id del abonado a id.
			flag =1; // flag =1. No entra mas a este if
			}
			else
			{
				if(arrayAbonado[i].contReclamos > maximo) // Saco maximo
				{
					maximo = arrayAbonado[i].contReclamos; // si el nuevo contReclamos es mas grande que el anterior se le asigna a maximo
					id = arrayAbonado[i].id; // le asigno el id del nuevo maximo
				}

			}

		}

		printf("\n\nAbonado con mas reclamos:\nid: %d\nNombre: %s\nApellido: %s\nCant de reclamos: %d\n",id,arrayAbonado[id].nombre,arrayAbonado[id].apellido,maximo); // Lo imprimo


		//2do informe
		if (motivo1 > motivo2 && motivo1>motivo3)
		{
			motivoMaximo = motivo1;
			printf("\nEl reclamo mas realizado fue: FALLA 3G. con %d de reclamos.\n",motivoMaximo);
		}
		else if (motivo2 > motivo1 && motivo2>motivo3)
		{
			motivoMaximo = motivo2;
			printf("\nEl reclamo mas realizado fue: FALLA LTE. con %d de reclamos.\n",motivoMaximo);
		}
		else
		{
			motivoMaximo = motivo3;
			printf("\nEl reclamo mas realizado fue: FALLA EQUIPO. con %d de reclamos.\n",motivoMaximo);
		}

		retorno = 0;
		}
	return retorno;
}

int reclamoMasDemora(eLlamada arrayLlamada[],int sizeLlamada) // 3er informe
{
	int retorno = -1;
	int j;
	float acumulador1erMotivo = 0;
	int cont1erMotivo = 0;
	float acumulador2doMotivo = 0;
	int cont2doMotivo = 0;
	float acumulador3erMotivo = 0;
	int cont3erMotivo = 0;
	float promedio1erMotivo;
	float promedio2doMotivo;
	float promedio3erMotivo;

	if(arrayLlamada != NULL && sizeLlamada>0)
	{
	for(j=0;j<sizeLlamada;j++)
		{
			if (arrayLlamada[j].isEmptyLlamada == 1)
			{
				continue;
			}
				if(arrayLlamada[j].motivo == 1 && arrayLlamada[j].tiempoInsumido>0)
				{
					acumulador1erMotivo = acumulador1erMotivo+ arrayLlamada[j].tiempoInsumido;
					cont1erMotivo++;
				}
				if(arrayLlamada[j].motivo == 2 && arrayLlamada[j].tiempoInsumido>0)
				{
					acumulador2doMotivo = acumulador2doMotivo + arrayLlamada[j].tiempoInsumido;
					cont2doMotivo++;
				}
				if(arrayLlamada[j].motivo == 3 && arrayLlamada[j].tiempoInsumido>0)
				{
					acumulador3erMotivo = acumulador3erMotivo + arrayLlamada[j].tiempoInsumido;
					cont3erMotivo++;
				}

		}


		promedio1erMotivo = acumulador1erMotivo/cont1erMotivo;
		promedio2doMotivo = acumulador2doMotivo/cont2doMotivo;
		promedio3erMotivo = acumulador3erMotivo/cont3erMotivo;

		if (promedio1erMotivo > promedio2doMotivo && promedio1erMotivo>promedio3erMotivo)
		{
			printf("\nEl reclamo que con el promedio %.2f mas demora en ser resuelto es FALLA 3G\n",promedio1erMotivo);
		}
		if (promedio2doMotivo > promedio1erMotivo && promedio2doMotivo>promedio3erMotivo)
		{
			printf("\nEl reclamo que con el promedio %.2f mas demora en ser resuelto es FALLA LTE.\n",promedio2doMotivo);
		}
		if(promedio3erMotivo>promedio1erMotivo && promedio3erMotivo>promedio2doMotivo)
		{
			printf("\nEl reclamo que con el promedio %.2f mas demora en ser resuelto es FALLA EQUIPO.\n",promedio3erMotivo);
		}

		retorno = 0;
	}

	return retorno;
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
