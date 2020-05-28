/*
 * person.c
 *
 *  Created on: 28 may. 2020
 *      Author: Nahu_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person* person_new()
{
	Person* this = NULL;
	  this = (Person*)malloc(sizeof(Person));
	  if(this!=NULL)
	  {
		  this->age=0;
		  this->something = 0;
	  }
	return this;
}

int person_setAge(Person* this,int i)
{
	int retorno = -1;
	if(this!=NULL && i>=0)
	{
	printf("\nAge:");
	scanf("%d",&i);
	this->age=i;
	retorno = 0;
	}
	return retorno;
}

int person_setSomething(Person* this,int i)
{

	int retorno = -1;
	if(this!=NULL && i>=0)
	{
	printf("\nSomething:");
	scanf("%d",&i);
	this->something=i;
	retorno = 0;
	}
	return retorno;
}

int person_getAge(Person* this)
{
	int aux;
	if(this!=NULL)
	{
		aux = this->age;
	}
	return aux;
}

int person_getSomething(Person* this)
{
	int aux;
	if(this!=NULL)
	{
		aux = this->something;
	}
	return aux;
}

void person_free(Person* this)
{
	if(this != NULL)
	free(this);
}
