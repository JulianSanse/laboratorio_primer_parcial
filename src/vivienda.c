#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "utn.h"

/**
 * \brief Recibe un array e inicializa la variable is empty en 1 para indicar que esta vacio.
 * \param pArray Array a inicializar
 * \paran largo Largo del array
 * return Retorna 0 en caso de exito y -1 si no
 */
int vivienda_initArray(Vivienda* pArray, int largo){
	int retorno = -1;
	int i;
	if(pArray != NULL && largo > 0){
		for(i=0; i< largo; i++){
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Agrega una vivienda al array de vivienda y muestra un mensaje que dice que se cargo con exito
 * \param  pArray Es la lista de viviendas
 * \param largo Es el Largo de la lista de viviendas
 * \param id Es la id de la vivienda que se va autoincrementando
 * \param calle Es la calle donde se encuentra la vivienda
 * \param cantidadPersonas Es la cantida de personas que viven en la vivienda
 * \param cantidadHabitaciones Es la cantidad de habitaciones que posee la vivienda
 * \param tipoVivienda Es un numero que hace referencia al tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
 * \param legajoCensista Es el legajo del censista
 * return Retorna 0 en caso de exito y -1 si no
 */
int vivienda_add(Vivienda* pArray, int largo, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista){
	int retorno = -1;
	if(pArray != NULL && id >= 20000 && cantidadPersonas > 0 && cantidadHabitaciones > 0 && (tipoVivienda >= 1 && tipoVivienda < 5) && legajoCensista > 0){
		for(int i = 0; i < largo; i++){
			if(pArray[i].isEmpty == 1){
				pArray[i].idVivienda = id;
				strcpy(pArray[i].calle, calle);
				pArray[i].cantidadPersonas = cantidadPersonas;
				pArray[i].cantidadHabitaciones = cantidadHabitaciones;
				pArray[i].tipoVivienda = tipoVivienda;
				pArray[i].legajoCensista= legajoCensista;
				pArray[i].isEmpty = 0;
				printf("----------------------------------------------------------\n"
						"La vivienda se cargo correctamente!! Id de la vivienda: %d \n"
						"----------------------------------------------------------\n" ,id);
				break;
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief Recibe un id, la busca en la lista y devuelve la posicion del elemento
 * \param pArray Lista en la que se busca el id
 * \param largo Largo de la lista
 * \param id Id a buscar
 * return devuelve la posicion del elemento en caso de encontrarla y -1 si no la encuentra
 */
int findViviendaById(Vivienda* pArray, int largo,int id){
	if(pArray != NULL && largo > 0 && id >= 20000 ){
		for(int i = 0; i< largo; i++){
			if(pArray[i].idVivienda == id){
				return i;
			}
		}
	}
	return -1;
}
/*
 * \brief Recibe una posicion de un array y permite modificar dicho elemento
 * \param pArray Lista en donde se busca el elemento por su posicion
 * \param indexPosicion Posicion del elemento a buscar
 * \param opcionElegida Campo que se quiere modificar del elemento buscado
 * return Retorna 0 en caso de exito y -1 si no
 */
int vivienda_modificar(Vivienda* pArray, int indexPosicion, int opcionElegida){

	int retorno = -1;

	if(pArray != NULL && indexPosicion >= 0 && (opcionElegida >= 'A' && opcionElegida <= 'E')){
		switch(opcionElegida){
			case 'A':
				if(utn_getString(pArray[indexPosicion].calle, CALLE_LENG, "Ingrese la calle de la vivienda que quiere modificar\n", "Calle invalida \n", 3) == 0){
					printf("Calle modificada correctamente");
					retorno = 0;
				}
				break;
			case 'B':
				if(utn_getNumero(&pArray[indexPosicion].cantidadPersonas, "Ingrese la cantidad de personas de la vivienda que quiere modificar \n", "Cantidad de personas invalida", 1, 20, 3) == 0){
					printf("Cantidad de personas modificadas correctamente");
					retorno = 0;
				}
				break;
			case 'C':
				if(utn_getNumero(&pArray[indexPosicion].cantidadHabitaciones, "Ingrese la cantidad de habitaciones de la vivienda que quiere modificar \n", "Cantidad de habitaciones invalida", 1, 20, 3) == 0){
					printf("Cantidad de habitaciones modificadas correctamente");
					retorno = 0;
				}
				break;
			case 'D':
				if(utn_getNumero(&pArray[indexPosicion].tipoVivienda, "Ingrese el tipo de la vivienda que quiere modificar (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)\n", "Tipo de vivienda incorrecto", 1, 4, 3) == 0){
					printf("Tipo de vivienda modificado correctamente");
					retorno = 0;
				}
				break;
		}
	}

	return retorno;

}
/*\brief Busca una vivienda en la lista por su posicion y la da de baja
 * \param pArray Lista de viviendas
 * \param indexPosicon Posicion del elemento a dar de baja
 * return Retorna 0 en caso de exito y -1 si no
 */
int vivienda_baja(Vivienda* pArray, int indexPosicion){
	int retorno = -1;
	if(pArray != NULL && indexPosicion >= 0){
		pArray[indexPosicion].isEmpty = 1;
		printf("Vivienda dada de baja correctamente!");
		retorno = 0;
	}
	return retorno;
}
/*\brief Ordena la lista de viviendas por la calle, en caso que sean iguales lo hace por cantidad de personas
 * \param pArray Lista de viviendas
 * \param largo Largo de la lista de viviendas
 * return retorna 0 en caso de exito y -1 si no
 */
int vivienda_ordenarPorNombre(Vivienda* pArray, int largo){
	int retorno = -1;
	int i;
	int j;
	Vivienda auxiliar;

	if(pArray != NULL && largo > 0){
		retorno = 0;
		for(i=0; i<largo; i++){
			for (j= i+1; j < largo; j++){
				if((strcmp(pArray[i].calle, pArray[j].calle)) > 0){
					auxiliar = pArray[i];
					pArray[i]= pArray[j];
					pArray[j]= auxiliar;
				}else{
					if((strcmp(pArray[i].calle, pArray[j].calle)) == 0 && pArray[i].cantidadPersonas < pArray[j].cantidadPersonas){
						auxiliar = pArray[i];
						pArray[i]= pArray[j];
						pArray[j]= auxiliar;
					}
				}

			}

		}
	}
	return retorno;
}
/**
 * \brief Imprime en consola la lista de viviendas
 * \param pArray Lista de viviendas
 * \param largo Largo de la lista
 * return 0 en caso de exito y -1 sino
 */
int vivienda_imprimir(Vivienda* pArray, int largo){
	int retorno = -1;
	char vivienda[20];

	if(pArray != NULL && largo > 0){
		printf("\nId       Calle                     Cant. personas   Cant. habitaciones    Tipo de vivienda    Legajo Censista\n");
		for(int i = 0; i<largo; i++){
			if(pArray[i].isEmpty == 0){
				retorno= 0;
				switch(pArray[i].tipoVivienda){
					case 1:
						strcpy(vivienda, "CASA");
						break;
					case 2:
						strcpy(vivienda, "DEPARTAMENTO");
						break;
					case 3:
						strcpy(vivienda, "CASILLA");
						break;
					case 4:
						strcpy(vivienda, "CHOZA");
						break;
				}
				printf("\n%-8d %-25s %-16d %-21d %d.%-17s %d\n", pArray[i].idVivienda, pArray[i].calle, pArray[i].cantidadPersonas, pArray[i].cantidadHabitaciones, pArray[i].tipoVivienda, vivienda, pArray[i].legajoCensista);
			}
		}
	}


	return retorno;
}

int vivienda_addCasaACensista(Vivienda* pArrayJulian, Vivienda* pArrayMario, Vivienda* pArrayYanina, int largo, int id, char* calle, int personas, int habitaciones, int tipoVivienda, int legajo, int* contadorViviendasJulian, int* contadorViviendasMario, int* contadorViviendasYanina){
	int retorno = -1;
	int i;
	switch(legajo){
			case 100:
				if(pArrayJulian != NULL){
					for(i = 0; i<largo; i++){
						if(pArrayJulian[i].isEmpty == 1){
							pArrayJulian[i].idVivienda = id;
							strcpy(pArrayJulian[i].calle, calle);
							pArrayJulian[i].cantidadPersonas = personas;
							pArrayJulian[i].cantidadHabitaciones = habitaciones;
							pArrayJulian[i].tipoVivienda = tipoVivienda;
							pArrayJulian[i].legajoCensista = legajo;
							pArrayJulian[i].isEmpty = 0;
							contadorViviendasJulian = contadorViviendasJulian + 1;
							break;

						}
					}

				}
				break;
			case 101:
				if(pArrayMario != NULL){
					for(i = 0; i<largo; i++){
						if(pArrayMario[i].isEmpty == 1){
							pArrayMario[i].idVivienda = id;
							strcpy(pArrayMario[i].calle, calle);
							pArrayMario[i].cantidadPersonas = personas;
							pArrayMario[i].cantidadHabitaciones = habitaciones;
							pArrayMario[i].tipoVivienda = tipoVivienda;
							pArrayMario[i].legajoCensista = legajo;
							pArrayMario[i].isEmpty = 0;
							contadorViviendasMario++;
							break;
						}
					}
				}
				break;
			case 102:
				if(pArrayYanina != NULL){
					for(i = 0; i<largo; i++){
						if(pArrayYanina[i].isEmpty == 1){
							pArrayYanina[i].idVivienda = id;
							strcpy(pArrayYanina[i].calle,calle);
							pArrayYanina[i].cantidadPersonas = personas;
							pArrayYanina[i].cantidadHabitaciones = habitaciones;
							pArrayYanina[i].tipoVivienda = tipoVivienda;
							pArrayYanina[i].legajoCensista = legajo;
							pArrayYanina[i].isEmpty = 0;
							contadorViviendasYanina++;
							break;
						}
					}
				}
				break;

	}
	return retorno;
}
