/*
 * utn.h
 *
 *  Created on: 9 abr. 2020
 *      Author: Nahu_
 */

#ifndef UTN_H_
#define UTN_H_

/* Funcion utn_getInt.
 *
 * Recibe de parametros un entero en el cual le vamos a volcar un resultado en *pResultado que se le va a mostrar en pantalla a un usuario
 * a traves de  *mensaje, con un numero minimo y maximo que debera ingresar sin sobrepasar esos valores. En el caso contrario se le dara
 * reintentos, y al quedarse sin estos se muestra por consola el msj de error.
 * Retorna 0 si esta bien || -1 si esta mal
 */
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int utn_getInt(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);

//int isValidInt(char* stringRecibido);


//************************************************************************************

/*Funcion utn_getFloat.
 *
 * Recibe de parametros un entero en el cual le vamos a volcar un resultado en *pResultado que se le va a mostrar en pantalla a un usuario
 * a traves de  *mensaje, con un numero minimo y maximo que debera ingresar sin sobrepasar esos valores. En el caso contrario se le dara
 * reintentos, y al quedarse sin estos se muestra por consola el msj de error.
 *Retorna 0 si esta bien || -1 si esta mal
 */
float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int isValidFloat(char* stringRecibido);
//****************************************************************************************

//int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);


#endif /* UTN_H_ */
