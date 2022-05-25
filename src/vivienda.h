#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#define CALLE_LENG 25

typedef struct{
	int idVivienda;
	char calle[CALLE_LENG];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
}Vivienda;

int vivienda_initArray(Vivienda* pArray, int largo);
int vivienda_add(Vivienda* pArray, int largo,  int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista);
int findViviendaById(Vivienda* pArray, int largo,int id);
int vivienda_modificar(Vivienda* pArray, int indexPosicion, int opcionElegida);
int vivienda_baja(Vivienda* pArray, int indexPosicion);
int vivienda_ordenarPorNombre(Vivienda* pArray, int largo);
int vivienda_imprimir(Vivienda* pArray, int largo);

#endif /* VIVIENDA_H_ */
