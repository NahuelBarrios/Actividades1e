/*
 * controller.c
 *
 *  Created on: 18 jun. 2020
 *      Author: Nahu_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "pelicula.h"
#include "parser.h"
#include "utn.h"

int controller_loadData(char* path,LinkedList* pArrayListPelicula)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListPelicula != NULL)
	{
		pArchivo= fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_loadData(pArchivo,pArrayListPelicula) == 0)
			{
				fclose(pArchivo);
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo cargar el archivo\n");
			}
		}
	}
	return retorno;
}


int controller_ListPelicula(LinkedList* pArrayListPelicula)
{
	 int retorno=-1;
	    int len;
	    int i;
	    int bufferIdVenta;
	    char bufferNombre[50];
	    int bufferDia;
	    char bufferDiaStr[50];
	    char bufferHorario[50];
	    int bufferSala;
	    int bufferCantEntradas;
	    Cine* pelicula;
	    if(pArrayListPelicula != NULL)
	    {
	        len=ll_len(pArrayListPelicula);
	        printf("\nid_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas\n\n");
	        for(i=0;i<len;i++)
	        {
	        	pelicula=(Cine*)ll_get(pArrayListPelicula,i);
	            if(pelicula!=NULL)
	            {
	            	pelicula_getId(pelicula,&bufferIdVenta);
	            	pelicula_getNombre(pelicula,bufferNombre);
	            	pelicula_getDia(pelicula,&bufferDia);
	            	switch(bufferDia)
	            	{
	            	case 0:
	            		strcpy(bufferDiaStr,"Domingo");
	            		break;
	            	case 1:
	            		strcpy(bufferDiaStr,"Lunes");
	            		break;
	            	case 2:
	            		strcpy(bufferDiaStr,"Martes");
	            		break;
	            	case 3:
	            		strcpy(bufferDiaStr,"Miercoles");
	            		break;
	            	case 4:
	            		strcpy(bufferDiaStr,"Jueves");
	            		break;
	            	case 5:
	            		strcpy(bufferDiaStr,"Viernes");
	            		break;
	            	case 6:
	            		strcpy(bufferDiaStr,"Sabado");
	            		break;
	            	}
	            	pelicula_getHorario(pelicula,bufferHorario);
	            	pelicula_getSala(pelicula,&bufferSala);
	            	pelicula_getCantEntradas(pelicula,&bufferCantEntradas);
	            	printf("%d,%s,%s,%s,%d,%d\n",bufferIdVenta,bufferNombre,bufferDiaStr,bufferHorario,bufferSala,bufferCantEntradas);
	            }
	        }
	        retorno=0;
	    }
	    return retorno;
}

int controller_utiliceMap(void* pPuntero)
{
	int retorno = -1;
	int bufferDia;
	int buffercantEntradas;
	int precioEntrada=0;
	int descuento;
	int total;

	if(pPuntero != NULL)
	{
		pPuntero = (Cine*)pPuntero;
		pelicula_getDia(pPuntero,&bufferDia);
		pelicula_getCantEntradas(pPuntero,&buffercantEntradas);

		if(bufferDia == 1 || bufferDia == 2 || bufferDia == 3)
		{
			precioEntrada = 240;
		}
		else
		{
			precioEntrada = 350;
		}

		if(buffercantEntradas >=3)
		{
			descuento = 10;

			total = precioEntrada*buffercantEntradas;
			descuento = (total*descuento)/100;
			total = total-descuento;
			pelicula_setMonto(pPuntero,total);
			retorno = 0;
		}
		else
		{
			total = precioEntrada*buffercantEntradas;
			pelicula_setMonto(pPuntero,total);
			retorno = 0;
		}
	}


	return retorno;
}

int controller_GenerateAmountFile(char* path,LinkedList* pArrayListPelicula)
{
	int retorno = -1;
	FILE* pArchivo;
	Cine* pelicula;
	 int bufferIdVenta;
	 char bufferNombre[50];
	 int bufferDia;
	 char bufferHorario[50];
	 int bufferSala;
	 int bufferCantEntradas;
	 int bufferMonto;
	int longitud;
	int i;

	if(path != NULL && pArrayListPelicula != NULL)
	{
		longitud = ll_len(pArrayListPelicula);
		ll_map(pArrayListPelicula,controller_utiliceMap);
		pArchivo = fopen(path,"w");
		if(pArchivo != NULL)
		{
			//fprintf(pArchivo,"id,nombre,dia,horario,sala,cantE,monto\n",bufferIdVenta,bufferNombre,bufferDia,bufferHorario,bufferSala,bufferCantEntradas,bufferMonto);
			for(i=0;i<longitud;i++)
			{
				pelicula = ll_get(pArrayListPelicula,i);
				if(pelicula_getId(pelicula,&bufferIdVenta)==0 &&
				pelicula_getNombre(pelicula,bufferNombre)==0&&
				pelicula_getDia(pelicula,&bufferDia)==0&&
				pelicula_getHorario(pelicula,bufferHorario)==0&&
				pelicula_getSala(pelicula,&bufferSala)==0&&
				pelicula_getCantEntradas(pelicula,&bufferCantEntradas)==0
				&& pelicula_getMonto(pelicula,&bufferMonto)==0)
				{
					fprintf(pArchivo,"%d,%s,%d,%s,%d,%d,%d\n",bufferIdVenta,bufferNombre,bufferDia,bufferHorario,bufferSala,bufferCantEntradas,bufferMonto);
					printf("%d,%s,%d,%s,%d,%d,%d\n",bufferIdVenta,bufferNombre,bufferDia,bufferHorario,bufferSala,bufferCantEntradas,bufferMonto);
				}
			}
			printf("\nArchivo Guardado con exito.\n");
		}
		fclose(pArchivo);
		retorno = 0;
	}
	return retorno;
}

int controller_informes(LinkedList* pArrayListPelicula)
{
	int retorno = -1;
	int auxSala;
	int longitud;
	int i;
	int bufferSala;
	int acumCantEntradas = 0;
	int bufferCantEntradas;
	int bufferMonto;
	int acumMonto = 0;
	char bufferNombre[51];
	int flag = 0;
	Cine* pelicula;

	if(pArrayListPelicula != NULL)
	{
		utn_getInt(&auxSala,"\nIngrese una sala: " ,"\nError\n",1,10,3);
		longitud = ll_len(pArrayListPelicula);

		for(i=0;i<longitud;i++)
		{
			pelicula = (Cine*)ll_get(pArrayListPelicula,i);
			pelicula_getSala(pelicula,&bufferSala);

			if(auxSala != bufferSala)
				continue;
			else
			{
				pelicula_getCantEntradas(pelicula,&bufferCantEntradas);
				acumCantEntradas = acumCantEntradas + bufferCantEntradas;

				pelicula_getMonto(pelicula,&bufferMonto);
				acumMonto = acumMonto + bufferMonto;

				pelicula_getNombre(pelicula,bufferNombre);
				if(flag == 0)
				{
					printf("Listado de películas que se proyectaron en dicha sala");
					flag =1;
				}

				printf("\n%s",bufferNombre);

			}
		}
		printf("\n******************************\nCantidad de entradas vendidas: %d",acumCantEntradas);
		printf("\nMonto total recaudado de sala: %d\n******************************",acumMonto);
	}

	return retorno;
}

