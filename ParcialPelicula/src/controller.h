/*
 * controller.h
 *
 *  Created on: 18 jun. 2020
 *      Author: Nahu_
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadData(char* path,LinkedList* pArrayListPelicula);

int controller_ListPelicula(LinkedList* pArrayListPelicula);

int controller_utiliceMap(void* pPuntero);

int controller_GenerateAmountFile(char* path,LinkedList* pArrayListPelicula);

int controller_informes(LinkedList* pArrayListPelicula);
#endif /* CONTROLLER_H_ */
