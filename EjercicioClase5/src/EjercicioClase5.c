/*
 ============================================================================
 Name        : EjercicioClase5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Hacer un programa que le pida 10 numeros al usuario y los guarde en un array
1) analizar el array e imprimir:
Promedio
Maximo
Minimo
2) Pedirle al usuario que ingrese un numero e indicar si el mismo está o no en el array.
3) Imprimir el array ordenado de mayor a menor
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "numeros.h"
#define QTY 5



int main ()
{
	int arrayNumeros[QTY];

	int bufferInt;
	int Aux;
	int i;
	int option;
	int ingresarNumero;
	int min;
	int max;
	int prom;
	int cantnumerosIguales = 0;

	setbuf(stdout,NULL);

	for(i=0;i<QTY;i++)
	{
		Aux = utn_getInt(&bufferInt,"Ingrese un numero: ","\n Error. ingrese un numero valido. entre 0 a 1.000.000",0, 1000000,3);

		if(Aux==0)
		{
			arrayNumeros[i]=bufferInt;

		}
	}

	while(option != 4)
	{
		utn_getInt(&option,"\n\n1-Mostrar: promedio max y min\n2-Ingresar un num\n3-Ordenar\n4-Salir\nIngrese la opcion: ","\n Error. ingrese un numero valido. entre 1 a 4",1,4,3);

		switch(option)
		{
		case 1: // Maximo|minimo|promedio
			minimo(arrayNumeros,QTY,&min);
			maximo(arrayNumeros,QTY,&max);
			promedio(arrayNumeros,QTY,&prom);
			printf("\nel minimo es: %d\nel maximo es: %d\nel promedio es: %d\n",min,max,prom);


			break;
		case 2:// Ingresar un numero y compararlo con uno del array
			utn_getInt(&ingresarNumero,"\nIngrese un numero: ","\n Error. ingrese un numero valido. entre 0 a 1.000.000",0,1000000,3);
			comparacion (arrayNumeros,QTY,ingresarNumero,&cantnumerosIguales);
			printf("la cantidad de numeros ingresados son: %d \nnumero ingresado : %d",cantnumerosIguales,ingresarNumero);


			break;

		case 3://Imprimir el array ordenado de mayor a menor
			ordenarArrayInt(arrayNumeros,QTY);
			printf("\nSe ordeno de mayor a menor\n");
			imprimirArrayInt(arrayNumeros,QTY);

		break;
		case 4:
			printf("\nGracias vuelva pronto\n");
			break;
		}
	}


}

/*

int main(void)
{
	int arrayEdades[QTY]; // Inicializo array Edades
	int arraySalarios[QTY];// Inicializo array Salarios
	int i;//indice
	int bufferEdad;//variable donde ingreso la edad
	int bufferSalario;//variable donde ingreso el salario
	int respuestaE;
	int respuestaS;
	int respuesta;
	int opcion; // opcion

	setbuf(stdout,NULL);

	for(i = 0; i < QTY; i++) //
	{
		respuestaE = utn_getInt(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2); //pido la edad por consola
		respuestaS = utn_getInt(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);// pido Salario por la consola
		if(respuestaE == 0 && respuestaS == 0)//valido. Si sale todo Ok, le paso lo ingresado por consola a las posiciones
		{
			arrayEdades[i] = bufferEdad;
			arraySalarios[i] = bufferSalario;
		}
	}
	imprimirArrayInt(arrayEdades,QTY); //imprimo las edades
	imprimirArrayInt(arraySalarios,QTY); // imprimo los salarios

	do
	{
		respuesta = utn_getInt(&opcion, "\n1-Modificar Edad\n2-Modificar Salario\n3-Mostrar\n4-Ordenar\n5-Salir\n","\nError tiene que ser de 1 a 6\n",1,6,2); //Menu
		if(respuesta == 0)
		{
			switch(opcion)
			{
				case 1: //Modificar la edad
					respuesta = utn_getInt(&i, "Indice de la Edad?\n","Error indice fuera de rango\n",0,QTY,2);
					respuestaE = utn_getInt(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2);
					if(respuestaE == 0 && respuesta == 0)
					{
						arrayEdades[i] = bufferEdad;
					}
					break;
				case 2: // Modificar salario
					respuesta = utn_getInt(&i, "Indice del salario?\n","Error indice fuera de rango\n",0,QTY,2);
					respuestaS = utn_getInt(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);
					if(respuestaS == 0 && respuesta == 0)
					{
						arraySalarios[i] = bufferSalario;
					}
					break;
				case 3: // Mostrar
					imprimirArrayInt(arrayEdades,QTY);
					imprimirArrayInt(arraySalarios,QTY);
					break;
				case 4: //Ordenar
					if(ordenar(arrayEdades,QTY) == 0)
					{
						printf("\nSIIIIIII ordeno\n");
					}
					break;

			}
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
*/


