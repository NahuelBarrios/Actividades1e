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
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "flag.h"
#include "instrumento.h"
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
		utn_getUnsignedInt("\nMenu\n\n1-Alta Orquesta\n2-Baja Orquesta\n3-Imprimir Orquesta\n4-Alta Musico",
				"\nError\n",1,sizeof(int),1,10,3,&option);

		switch(option)
		{
		case 1:// Alta
			altaOrquesta(arrayOrquesta,QTY_ORQUESTA,&idOrquesta,arrayMusico,QTY_MUSICO);
			printf("\nSe cargo la orquesta.\n");
			break;

		case 2: // Baja
			bajaOrquesta(arrayOrquesta,QTY_ORQUESTA);
			printf("\nSe realizo la baja\n");
			break;

		case 3:// Se imprime la lista de orquestas
			listarOrquesta(arrayOrquesta,QTY_ORQUESTA);
			break;
		case 4:
			altaMusico(arrayMusico,QTY_MUSICO,&idMusico);
			printf("\nSe cargo el musico\n");
			break;
		case 8:
			altaInstrumento(arrayInstrumento,QTY_INSTRUMENTO,&idInstrumento);
			printf("\nSe cargo el instrumento\n");
			break;
		case 10:
			printf("\nVUELVA PRONTO\n");
			break;

		}





	}


	return 0;
}
