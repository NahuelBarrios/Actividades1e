/*
 ============================================================================
 Name        : Clase11.c
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
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "flag.h"
#define QTY_ORQUESTA 50
#define QTY_MUSICO 1000
#define QTY_INSTRUMENTO 20

int main(void) {
	setbuf(stdout,NULL);

	eOrquesta arrayOrquesta [QTY_ORQUESTA];
	inicializarOrquesta(arrayOrquesta,QTY_ORQUESTA);

	eMusico arrayMusico[QTY_MUSICO];
	inicializarMusico(arrayMusico,QTY_MUSICO);

	eInstrumento arrayInstrumento[QTY_INSTRUMENTO];
	inicializarInstrumento(arrayInstrumento,QTY_INSTRUMENTO);

	int idOrquesta = 0;
	int idMusico = 0;
	int idInstrumento = 0;
	int option = 0;

	while(option != 10)
	{
		utn_getUnsignedInt("\nMenu\n\n1-Agregar Orquesta\n2-Eliminar Orquesta\n3-Imprimir Orquestas\n4-Agregar Musico\n5-Modificar Musicom\n6-Eliminar Musico\n7-Imprimir Musicos\n8-Agregar Instrumento\n9-Imprimir instrumentos\n10-Salir\n\nIngrese una opcion: ",
				"\nError\n",1,sizeof(int),1,10,3,&option);

		switch(option)
		{
		case 1:
			altaOrquesta(arrayOrquesta,QTY_ORQUESTA,&idOrquesta);
			printf("\nSe cargo la orquesta.\n");
			break;

		case 2:
			bajaOrquesta(arrayOrquesta,QTY_ORQUESTA);
			printf("\nSe realizo la baja\n");
			break;

		case 3:
			listarOrquesta(arrayOrquesta,QTY_ORQUESTA);
			break;
		case 4:
			altaMusico(arrayMusico,QTY_MUSICO,&idMusico,arrayOrquesta,QTY_ORQUESTA,arrayInstrumento,QTY_INSTRUMENTO);
			printf("\nSe cargo el musico\n");
			break;
		case 5:
			listarMusico(arrayMusico,QTY_MUSICO);
			modificarMusico(arrayMusico,QTY_MUSICO,arrayOrquesta,QTY_ORQUESTA);
			break;
		case 6:
			listarMusico(arrayMusico,QTY_MUSICO);
			bajaMusico(arrayMusico,QTY_MUSICO);
			break;
		case 7:
			imprimirMusicoConInstrumento(arrayMusico,QTY_MUSICO,arrayInstrumento,QTY_INSTRUMENTO);
			break;
		case 8:
			altaInstrumento(arrayInstrumento,QTY_INSTRUMENTO,&idInstrumento);
			printf("\nSe cargo el instrumento\n");
			break;
		case 9:
			imprimirInstrumento(arrayInstrumento,QTY_INSTRUMENTO);
			break;
		case 10:
			printf("\nVUELVA PRONTO\n");
			break;

		}

	}


	return 0;
}
