/*
 ============================================================================
 Name        : repasoDeParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "abonado.h"
#include "llamada.h"
#include "flag.h"
#define QTY_ABONADO 5
#define QTY_LLAMADAS 10

int main(void)
{
	setbuf(stdout,NULL);
	eAbonado arrayAbonado [QTY_ABONADO];
	inicializarAbonado(arrayAbonado,QTY_ABONADO);

	eLlamada arrayLlamada [QTY_LLAMADAS];
	inicializarLlamada(arrayLlamada,QTY_LLAMADAS);

	int option;
	int idAbonado = 0;
	int idLlamada = 0;

	while (option!=7)
	{
		utn_getUnsignedInt("\nMENU\n1-Alta abonado\n2-modificar\n3-bajar\n4-alta llamada\nSeleccione opcion:","\nError\n",1,sizeof(int),1,7,3,&option);

		switch(option)
		{
		case 1:
			altaAbonado(arrayAbonado,QTY_ABONADO,&idAbonado);
			break;
		case 2:
			listarAbonado(arrayAbonado,QTY_ABONADO);
			modificarAbonado(arrayAbonado,QTY_ABONADO);
			break;
		case 3:
			listarAbonado(arrayAbonado,QTY_ABONADO);
			bajaAbonado(arrayAbonado,QTY_ABONADO);
			break;
		case 4:
			inicioLlamada(arrayLlamada,QTY_LLAMADAS,&idLlamada,arrayAbonado,QTY_ABONADO);
			break;
		case 5:
			finLlamada(arrayLlamada,QTY_LLAMADAS);
			break;
		case 6:

			break;
		case 7:
			printf("\nGracias vuelva pronto\n");
			break;

		default: printf("\nIngrese una opcion del 1 a 7.\n");
		}
	}

	return 0;
}
