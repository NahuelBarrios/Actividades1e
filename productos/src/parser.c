
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "linkedlist.h"
#include "controller.h"
#include "ventas.h"

int parser_loadData(FILE* pFile,LinkedList* pArrayListVentas)
{
	int retorno = -1;
		eVentas* pVentas;
		char idVenta[51];
		char fechaVenta[51];
		char codigoProducto[51];
		char cantidad[51];
		char precio[51];
		char cuitCliente[51];
		int cant;

		fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",idVenta,fechaVenta,codigoProducto,cantidad,precio,cuitCliente);

		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",idVenta,fechaVenta,codigoProducto,cantidad,precio,cuitCliente);

			if(cant == 6)
			{
				pVentas = ventas_newParametros(idVenta,fechaVenta,codigoProducto,cantidad,precio,cuitCliente);
				if(pVentas != NULL)
				{
					printf("%s,%s,%s,%s,%s,%s\n",idVenta,fechaVenta,codigoProducto,cantidad,precio,cuitCliente);
					ll_add(pArrayListVentas,pVentas);
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
