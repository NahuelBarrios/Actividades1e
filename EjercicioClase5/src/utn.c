#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "numeros.h"


int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[4060];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}


int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//*****************************************************************************************************************************

/*
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1; // indico q me va a retornar mal
	char bufferStr[4060];//Auxiliar
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) // Valido los parametros
	{
		do
		{
			if(!getString(mensaje,mensajeError,minimo,maximo,&reintentos,bufferStr)) //==0 sin errores !0

			          if(isValidInt(bufferStr)==1)
			           {
			        	  *pResultado=atoi(bufferStr);
			        	  retorno = 0; // indico al retorno que salio todo Ok.
			        	  break; // salgo
			           }
			          else
			          {
			        	  printf("%s",mensajeError); // imprimo el msj de error
			        	  reintentos--; // decremento los reintentos
			          }
		}while(reintentos >= 0);
	}
	return retorno;
}



int isValidInt(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//**************************************************************

float utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1; // indico q me va a retornar mal
	char bufferStr[4060];//Auxiliar
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) // Valido los parametros
	{
		do
		{
			if(!getString(mensaje,mensajeError,minimo,maximo,&reintentos,bufferStr)) //==0 sin errores !0
			{
				if(isValidInt(bufferStr)==1)
				 {
					*pResultado=atof(bufferStr);
					retorno = 0; // indico al retorno que salio todo Ok.
					break; // salgo
				 }
				else
				{
					printf("%s",mensajeError); // imprimo el msj de error
					reintentos--; // decremento los reintentos
				}
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int isValidFloat(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='-' && stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

*/
//***************************************************************

