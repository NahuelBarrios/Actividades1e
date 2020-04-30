/*
 * alumno.h
 *
 *  Created on: 30 abr. 2020
 *      Author: Nahu_
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	int dia;
	int mes;
	int anio; // LA Ñ NO SE USA
}eFecha;

typedef struct
{
	int legajo;
	char nombre[51];
	int edad;
	char sexo;
	int nota1P;
	int nota2P;


}eAlumno;

#endif /* ALUMNO_H_ */
