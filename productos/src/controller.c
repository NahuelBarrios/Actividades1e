
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "linkedlist.h"
#include "controller.h"
#include "parser.h"
#include "ventas.h"

int controller_loadData(char* path,LinkedList* pArrayVentas)
{
	int retorno = -1;
		FILE* pArchivo;

		if(path != NULL && pArrayVentas != NULL)
		{
			pArchivo= fopen(path,"r");
			if(pArchivo != NULL)
			{
				if(parser_loadData(pArchivo,pArrayVentas) == 0)
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

int informe(char* path,LinkedList* pArrayVentas)
{
	int retorno = -1;
	FILE* pArchivo;
	int cantVentas;
	int cantMayorDiezMil;
	int cantMayorVeinteMil;
	int cantLCD;

	if(pArrayVentas != NULL)
	{
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL)
		{
			cantVentas =ll_count(pArrayVentas,cantVendida);

			cantMayorDiezMil = ll_count(pArrayVentas,cantDiezMil);

			cantMayorVeinteMil = ll_count(pArrayVentas,cantMayorVeinte);

			cantLCD = ll_count(pArrayVentas,cantLCDFunc);

			fprintf(pArchivo,"********************\nInforme de ventas\n********************\nCantidad de unidades vendidas totales: %d\nCantidad de ventas por un monto mayor a $10000: %d\nCantidad de ventas por un monto mayor a $20000: %d\nCantidad de TVs LCD vendidas: %d\n********************",
					cantVentas,cantMayorDiezMil,cantMayorVeinteMil,cantLCD);
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}

int cantVendida(void* p)
{
	int retorno=-1;
	eVentas* pVentas;
	int cant;

	if(p != NULL)
	{
		pVentas = (eVentas*) p;

		cant=pVentas->cantidad;
		retorno = cant;

	}
	return retorno;
}

int cantDiezMil(void* p)
{
	int retorno = 0;
	eVentas* pVentas;

	if(p != NULL)
	{
		pVentas = (eVentas*)p;
		if((pVentas->precio) > 10000)
			retorno =  1;
	}
return retorno;
}

int cantMayorVeinte(void* p)
{
	int retorno = 0;
	eVentas* pVentas;

	if(p != NULL)
	{
		pVentas = (eVentas*)p;
		if((pVentas->precio) > 20000)
			retorno =  1;
	}

	return retorno;
}

int cantLCDFunc(void* p)
{
	int retorno = 0;
	eVentas* pVentas;

	if(p != NULL)
	{
		pVentas = (eVentas*)p;
		if(strcmp(pVentas->codigoProducto,"LCD_TV")==0)
			retorno = 1;
	}
	return retorno;
}
