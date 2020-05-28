/*
 * person.h
 *
 *  Created on: 28 may. 2020
 *      Author: Nahu_
 */

#ifndef PERSON_H_
#define PERSON_H_

typedef struct
{
	int age;
	int something;

}Person;

Person* person_new();

int person_setAge(Person* this,int i);

int person_setSomething(Person* this,int i);

int person_getAge(Person* this);

int person_getSomething(Person* this);

void person_free(Person* this);

#endif /* PERSON_H_ */
