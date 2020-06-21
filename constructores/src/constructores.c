/*
 ============================================================================
 Name        : constructores.c
 Author      : Nahu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // NO ES UN BUEN METODO PERO ES UN BUEN EJEMPLO A TENER XD
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;

} eEmpleado;

int cargarEmpleado(eEmpleado* e, int legajo, char* nombre, char sexo, float sueldo, eFecha fecha);
eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* emp);
eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio);
int mostrarEmpleados(eEmpleado* vec, int tam);
int agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp);

int main()
{
    eEmpleado* nuevoEmpleado;
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));
    int tam = 0;
    if( lista == NULL)
    {
        printf("No se pudo conseguir lugar\n");
        exit(EXIT_FAILURE);
    }
    // Creo un nuevo empleado hardcodeado

    nuevoEmpleado = newEmpleadoParam(1, "Jorge", 'm', 25000, 12, 5, 2010);
    printf("\n");
    printf("\n 2-MUESTRO nuevoEmpleado");
    mostrarEmpleado(nuevoEmpleado);
    if( agregarEmpleado(lista, &tam, nuevoEmpleado))
    {
        printf("4-Empleado agregado con exito tam %d \n", tam);
        mostrarEmpleado(lista+(tam-2));
    }
    else
    {
        printf("No se pudo agregar el empleado\n");
    }
    // Creo un nuevo empleado hardcodeado
    eEmpleado* nuevoEmpleado1 = newEmpleadoParam(2, "Juana", 'm', 25000, 12, 5, 2010);
    printf("\n");
    printf("\n 2-MUESTRO nuevoEmpleado");
    mostrarEmpleado(nuevoEmpleado1);
   if( agregarEmpleado(lista, &tam, nuevoEmpleado1))
    {
        printf("4-Empleado agregado con exito tam %d \n", tam);
        mostrarEmpleado(lista+(tam-1));
    }
    else
    {
        printf("No se pudo agregar el empleado\n");
        mostrarEmpleado(lista+tam);
    }
    // Creo un nuevo empleado hardcodeado
    eEmpleado*  nuevoEmpleado2 = newEmpleadoParam(3, "Matias", 'm', 25000, 12, 5, 2010);
    printf("\n");
    printf("\n 2-MUESTRO nuevoEmpleado");
    mostrarEmpleado(nuevoEmpleado2);
    if( agregarEmpleado(lista, &tam, nuevoEmpleado2))
    {
        printf("4-Empleado agregado con exito tam %d \n", tam);
        mostrarEmpleado(lista+(tam-1));
    }
    else
    {
        printf("No se pudo agregar el empleado\n");
    }


    /*printf("\n");
    printf("\n ***5-Mostrar estructura*** \n ");
    printf("\n>>>>>tam %d", tam);

    mostrarEmpleados(lista, 3);
*/

    free(nuevoEmpleado);
    free(lista);
    return 0;
}

int cargarEmpleado(eEmpleado* e, int legajo, char* nombre, char sexo, float sueldo, eFecha fecha)
{
    int todoOk = 0;

    e->legajo = legajo;
    strcpy(e->nombre, nombre);
    e->sexo = sexo;
    e ->sueldo = sueldo;
    e->fIngreso = fecha;
    todoOk = 1;

    return todoOk;
}

eEmpleado* newEmpleado()
{

    eEmpleado* p;

    p = (eEmpleado*) malloc( sizeof(eEmpleado));

    if( p != NULL)
    {
        p->legajo = 0;
        strcpy(p->nombre, "sin definir");
        p->sexo = 'm';
        p->sueldo = 0;
        p->fIngreso = (eFecha)
        {
            1,1,1990
        };
    }

    return p;

}


int mostrarEmpleado(eEmpleado* emp)
{
    int todoOk =0;

    if( emp != NULL)
    {
        printf("\n");
        printf(" %d  %s  %c  %.2f  %02d/%02d/%d\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, emp->fIngreso.dia, emp->fIngreso.mes, emp->fIngreso.anio);
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio)
{

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {

        nuevoEmpleado->legajo = leg;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sexo = sexo;
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->fIngreso.dia = dia;
        nuevoEmpleado->fIngreso.mes = mes;
        nuevoEmpleado->fIngreso.anio = anio;
    }
    printf("\n************************************\n");
    printf("1-Muestro dentro de newEmpleadoParam");
    mostrarEmpleado(nuevoEmpleado);

    return nuevoEmpleado;
}

int agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp)
{
    eEmpleado* aux;
    int todoOk = 0;

    printf("\n 3-DENTRO DE agregarEmpleado");
    printf("\nValor de tam %d", *tam);
    printf("\nlegajo = %d ", emp->legajo);


    if( vec != NULL && tam != NULL && emp != NULL){
        *(vec + *tam) = *emp;

        if (*tam == 0){
            *tam = *tam + 1;
        }

       //printf("\n tamanio %d", tamanio);
       printf("\n tam %d \n", *tam);
       aux =(eEmpleado*)realloc(vec ,(sizeof(eEmpleado)* (*tam)));

       if( aux != NULL){
            vec = aux;
            if(*tam>0){*tam = *tam + 1;}
            todoOk = 1;
        }
        else{
            printf("No realoco");
        }

    }

    return todoOk;

}

int mostrarEmpleados(eEmpleado* vec, int tam)
{
    int todoOk = 0;

    if( vec != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            mostrarEmpleado(vec+i);
        }
        todoOk = 1;
    }

    return todoOk;
}
