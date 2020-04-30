/*
 ============================================================================
 Name        : Clase7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * int legajo[CANT_EL];
char sexo[CANT_EL];
int edad[CANT_EL];
int nota1P[CANT_EL];
int nota2P[CANT_EL];
float promedio[CANT_EL];
char arrayApellidos[CANT_EL][50];
Funciones con Arrays
*********************
Inicializar
cargar
Mostrar1Estudiante
mostrarEstudiantes
Ordenar por legajo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#include "carreras.h"
#define QTY 200
#define QTY2 200

int main(void)
{
	setbuf(stdout,NULL);

	colegioE arrayColegio[QTY];
	fechaE arrayFecha[QTY];
	carreraE arrayCarrera[] = {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

	initColegio(arrayColegio,QTY);
	initFecha(arrayFecha,QTY2);

	int option;
	int idUnEstudiante;
	int contId = 0;
	int contIdFecha = 0;

	while(option !=7)
	{
		utn_getUnsignedInt("\n\nBienvenidos\n\n1-Cargar Estudiante\n2-Baja\n3-Modificacion\n4-Mostrar Estudiante especifico\n5-Mostrar todo\n6-Ordenar por legajo\n7-Salir\nElija una opcion: ","\n\nError Ingrese opcion valida\n\n"
				,1,sizeof(int),1,5,3,&option);

		switch(option)
		{
		case 1: // Cargar osea alta :v
			cargarPersona(arrayColegio,QTY,&contId);
			cargarFecha(arrayFecha,QTY2,&contIdFecha);
		break;
		case 2://BAJA
			baja(arrayColegio,QTY,arrayFecha,QTY2);
			printf("\nSe realizo la baja\n");
			break;
		case 3://MODIFICACION
			break;
		case 4: // mostrar un solo estudiante
			utn_getUnsignedInt("\nIngrese el legajo a mostrar: \n","\nError,Opcion no valida\n",1,sizeof(int),0,QTY,3,&idUnEstudiante);
			mostrarUnEstudiante(arrayColegio,QTY,idUnEstudiante,arrayFecha,QTY2);
		break;
		case 5: //mostrar todos los estudiantes
			mostrarEstudiantes(arrayColegio,QTY,arrayFecha,QTY2);
			break;
		case 6://ordenar por apellido
			estructuraOrdenada(arrayColegio,QTY);
			printf("\nSe ha ordenado por apellido de forma ascendente\n");
			break;
		case 7:
			printf("\n vuelva pronto \n");
			break;

		}

	}

	return 0;
}
