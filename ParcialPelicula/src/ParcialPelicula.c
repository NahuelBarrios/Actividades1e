/*
 ============================================================================
 Name        : ParcialPelicula.c
 Author      : Nahu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "controller.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option = 0;
	char path[51];

	LinkedList* listaPelicula = ll_newLinkedList();

	while(option != 5)
	{
		printf("\n1-Cargar archivo\n2-Imprimir Ventas\n3-Generar archivo de montos\n4-Informes\n5-Salir");
		utn_getInt(&option,"\nElija una opcion: " ,"\nError\n",1,10,3);
		switch(option)
		{
		case 1:
			fflush(stdin);
			if(utn_getTexto("\nIngrese el nombre del archivo: ","\nError\n",3,51,3,path)==0)
			{
				if(controller_loadData(path,listaPelicula)==0)
				{
					printf("\nSe cargo los datos correctamente\n");
				}
				else
				{
					printf("\nNO se cargo los datos\n");
				}
			}
			else
			{
				printf("\nAgregó un nombre inexistente.\n");
			}
			break;
		case 2:
			controller_ListPelicula(listaPelicula);
			break;
		case 3:
			if(controller_GenerateAmountFile("data_new_Pelis.csv",listaPelicula)==0)
				printf("\nSe cargo con exito los datos\n");
			else
				printf("\nNO se cargo con exito los datos\n");
			break;
		case 4:
			controller_informes(listaPelicula);
			break;
		case 5:
			printf("\nSalió.\n");
			break;

		default: printf("\n Ingrese una opcion valida\n");

		}

	}



	return 0;
}












