/*
 * ventas.h
 *
 *  Created on: 22 jun. 2020
 *      Author: Nahu_
 */

#ifndef VENTAS_H_
#define VENTAS_H_

typedef struct
{
	int idVenta;
	char fechaVenta[51];
	char codigoProducto[51];
	int cantidad;
	int precio;
	char cuitCliente[51];

}eVentas;


eVentas* ventas_new();
eVentas* ventas_newParametros(char* id,char* fecha,char* codigo,char* cantidad, char* precio, char* cuit);

int venta_setId(eVentas*this, int id);
int venta_getId(eVentas* this,int* id);

int venta_setFecha(eVentas* this,char* fecha);
int venta_getFecha(eVentas* this,char* fecha);

int venta_setCodProducto(eVentas* this,char* codigo);
int venta_getCodProducto(eVentas* this,char* codigo);

int venta_setCantidad(eVentas*this, int QTY);
int venta_getCantidad(eVentas* this,int* QTY);

int venta_setPrecio(eVentas*this, int precio);
int venta_getPrecio(eVentas* this,int* precio);

int venta_setCuit(eVentas* this,char* cuit);
int venta_getCuit(eVentas* this,char* cuit);



#endif /* VENTAS_H_ */
