/*
 * parser.c
 *
 *  Created on: 18 jun. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "pelicula.h"
#include "controller.h"
#include "parser.h"

int parser_loadData(FILE* pFile , LinkedList* pArrayListPelicula)
{
	int retorno = -1;
	Cine* pPelicula;
	char id[51];
	char nombre[51];
	char dia[51];
	char horario[51];
	char sala[51];
	char cantEntradas[51];
	int cant;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dia,horario,sala,cantEntradas);

	while(!feof(pFile))
	{
		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dia,horario,sala,cantEntradas);

		if(cant == 6)
		{
			pPelicula = pelicula_newParametros(id,nombre,dia,horario,sala,cantEntradas);
			if(pPelicula != NULL)
			{
				ll_add(pArrayListPelicula,pPelicula);
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo cargar los datos\n");
				break;
			}
		}
		else
		{
			printf("\nNo se pudo leer los datos correctamente\n");
			break;
		}
	}

	return retorno;
}

