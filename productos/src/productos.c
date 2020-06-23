/*
 ============================================================================
 Name        : productos.c
 Author      : Nahu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "linkedlist.h"
#include "controller.h"

int main(void)
{
	setbuf(stdout,NULL);
	LinkedList* listaVentas = ll_newLinkedList();
	int option=0;

	while(option != 3)
	{
		printf("\n1-Cargar los datos\n2-Informe\n3-Salir");
		utn_getInt(&option,"\nElija una opcion: " ,"\nError\n",1,10,3);
		switch(option)
		{
		case 1:
			if(controller_loadData("data_prod.csv",listaVentas)==0)
				printf("\nSe cargo todo con exito\n");
			else
				printf("\nNO Se cargo con exito\n");
			break;
		case 2:
			if(informe("informes.txt",listaVentas)==0)
				printf("\nSe guardo el informe correctamente\n");
			break;
		case 3:
			printf("\nSalió.\n");
			break;

		default: printf("\nIngrese una opcion correcta\n");
		}
	}
	return 0;
}
