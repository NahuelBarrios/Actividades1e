
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadData(char* path,LinkedList* pArrayVentas);

int informe(char* path,LinkedList* pArrayVentas);

int cantVendida(void* p);
int cantDiezMil(void* p);
int cantMayorVeinte(void* p);
int cantLCDFunc(void* p);

#endif /* CONTROLLER_H_ */
