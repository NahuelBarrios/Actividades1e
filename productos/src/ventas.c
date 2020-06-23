#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ventas.h"

eVentas* ventas_new()
{
	eVentas* this;

	this = (eVentas*)malloc(sizeof(eVentas));

	if(this != NULL)
	{
		this->idVenta=0;
		strcpy(this->fechaVenta,"");
		strcpy(this->codigoProducto,"");
		this->cantidad=0;
		this->precio=0;
		strcpy(this->cuitCliente,"");
	}
	return this;
}

eVentas* ventas_newParametros(char* id,char* fecha,char* codigo,char* cantidad, char* precio, char* cuit)
{
	eVentas* this = ventas_new();

	if(this != NULL)
	{
		venta_setId(this,atoi(id));
		venta_setFecha(this,fecha);
		venta_setCodProducto(this,codigo);
		venta_setCantidad(this,atoi(cantidad));
		venta_setPrecio(this,atoi(precio));
		venta_setCuit(this,cuit);
	}
	return this;
}


//***********Set y get Id***********************
int venta_setId(eVentas*this, int id)
{
	int retorno = -1;

	if(this!=NULL && id>=0)
	{
		this->idVenta = id;
		retorno = 0;
	}
	return retorno;
}

int venta_getId(eVentas* this,int* id)
{
	int retorno = -1;

		if(this!=NULL && id!= NULL)
		{
			*id = this->idVenta;
			retorno = 0;
		}
		return retorno;
}

//************Set y get Fecha**************************
int venta_setFecha(eVentas* this,char* fecha)
{
	int retorno = -1;

	if(this!=NULL && fecha!= NULL)
	{
		strcpy(this->fechaVenta,fecha);
		retorno = 0;
	}
	return retorno;
}

int venta_getFecha(eVentas* this,char* fecha)
{
	int retorno = -1;

	if(this!=NULL && fecha!= NULL)
	{
		strcpy(fecha,this->fechaVenta);
		retorno = 0;
	}
	return retorno;
}
//************Set y get CodigoProducto**************************
int venta_setCodProducto(eVentas* this,char* codigo)
{
	int retorno = -1;

	if(this!=NULL && codigo!= NULL)
	{
		strcpy(this->codigoProducto,codigo);
		retorno = 0;
	}
	return retorno;
}

int venta_getCodProducto(eVentas* this,char* codigo)
{
	int retorno = -1;

	if(this!=NULL && codigo!= NULL)
	{
		strcpy(codigo,this->codigoProducto);
		retorno = 0;
	}
	return retorno;
}
//************Set y get Cantidad**************************
int venta_setCantidad(eVentas*this, int QTY)
{
	int retorno = -1;

	if(this!=NULL && QTY>=0)
	{
		this->cantidad = QTY;
		retorno = 0;
	}
	return retorno;
}

int venta_getCantidad(eVentas* this,int* QTY)
{
	int retorno = -1;

		if(this!=NULL && QTY!= NULL)
		{
			*QTY = this->cantidad;
			retorno = 0;
		}
		return retorno;
}
//************Set y get Precio**************************
int venta_setPrecio(eVentas*this, int precio)
{
	int retorno = -1;

	if(this!=NULL && precio>=0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int venta_getPrecio(eVentas* this,int* precio)
{
	int retorno = -1;

		if(this!=NULL && precio!= NULL)
		{
			*precio = this->precio;
			retorno = 0;
		}
		return retorno;
}
//************Set y get CUIT**************************
int venta_setCuit(eVentas* this,char* cuit)
{
	int retorno = -1;

	if(this!=NULL && cuit!= NULL)
	{
		strcpy(this->cuitCliente,cuit);
		retorno = 0;
	}
	return retorno;
}

int venta_getCuit(eVentas* this,char* cuit)
{
	int retorno = -1;

	if(this!=NULL && cuit!= NULL)
	{
		strcpy(cuit,this->cuitCliente);
		retorno = 0;
	}
	return retorno;
}
