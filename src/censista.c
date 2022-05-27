#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censista.h"

/**
 * \brief Muestra la lista de censistas en pantalla
 * \param pArray Lista de censistas
 * \param largo Largo de la lista
 * return Retorna 0 en caso de exito y -1 si no
 */
int censista_listar(Censista* pArray, int largo){
	int retorno = -1;
	if(pArray != NULL && largo > 0){
		printf("\nLegajo	Nombre	 Edad	 Telefono");
		for(int i = 0; i < largo; i++){
			printf("\n%-7d %-8s %-7d %s \n", pArray[i].legajoCensista, pArray[i].nombre, pArray[i].edad, pArray[i].telefono);
		}
		retorno = 0;
	}
	return retorno;
}

int censista_listarVivienda(Censista pArray, int largo){


	printf("\nLegajo	Nombre	 Edad	 Telefono");

	printf("\n%-7d %-8s %-7d %s \n", pArray.legajoCensista, pArray.nombre, pArray.edad, pArray.telefono);




}


