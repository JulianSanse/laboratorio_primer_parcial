/*
 ============================================================================
 Name        : laboratorio_primer_parcial.c
 Author      : Julian San Sebastian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "vivienda.h"
#include "censista.h"

#define VIVIENDAS_LENG 100
#define CENSISTAS_LENG 3


int main(void) {
	setbuf(stdout, NULL);
	Censista censistas[CENSISTAS_LENG] = {{100, "Julian", 19, "11 3519-6798"}, {101, "Mario", 24, "4301-54678"},{102, "Yanina", 23, "5902-37487"}};
	Vivienda viviendas[VIVIENDAS_LENG];
	vivienda_initArray(viviendas, VIVIENDAS_LENG);
	Vivienda auxVivienda;
	int id = 20000;
	int indexPosicion;
	int ingresoVivienda = 0;

	char opcionElegida;

	do{
		utn_getCaracter(&opcionElegida, "\n\n A.ALTA VIVIENDA \n\n B.MODIFICAR VIVIENDA \n\n C.BAJA VIVIENDA \n\n D.LISTAR VIVIENDAS \n\n E.LISTAR CENSISTAS \n\n F. SALIR \n\n", "Caracter invalido", 'A', 'F', 3);
		switch(opcionElegida){
			case 'A':
					if(utn_getString(auxVivienda.calle, CALLE_LENG, "Ingrese la calle de la vivienda \n", "Calle invalida \n", 3) == 0 &&
					   utn_getNumero(&auxVivienda.cantidadPersonas, "Ingrese la cantidad de personas \n", "Cantidad Invalida \n", 0, 20, 3) == 0 &&
					   utn_getNumero(&auxVivienda.cantidadHabitaciones, "Ingrese la cantidad de habitaciones \n", "Cantidad Invalida \n", 0, 20, 3) == 0 &&
					   utn_getNumero(&auxVivienda.tipoVivienda, "Ingrese el tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO) \n", "Cantidad Invalida \n", 1, 4, 3) == 0 &&
					   utn_getNumero(&auxVivienda.legajoCensista, "Ingrese el legajo del censista \n", "Ese legajo de censista no existe!\n", 100, 102, 3) == 0)
					{
						auxVivienda.idVivienda = id;
						id++;

						vivienda_add(viviendas, VIVIENDAS_LENG, auxVivienda.idVivienda, auxVivienda.calle, auxVivienda.cantidadPersonas, auxVivienda.cantidadHabitaciones, auxVivienda.tipoVivienda, auxVivienda.legajoCensista);
						ingresoVivienda = 1;
					}

				break;
			case 'B':
				if(ingresoVivienda == 0){
					printf("\n Debe ingresar una vivienda primero!! \n");
				}else{
					if(utn_getNumero(&id, "Ingrese el id de la vivienda que quiere modifar \n", "Id invalido \n", 20000, 21001, 3) == 0){
						indexPosicion= findViviendaById(viviendas, VIVIENDAS_LENG, id);
					}
					if(indexPosicion== -1){
						printf("\n Id no encontrada!!\n");
					}else{
						do{
							utn_getCaracter(&opcionElegida, "\n\n A.MODIFICAR CALLE \n\n B.MODIFICAR CANTIDAD DE PERSONAS \n\n C.MODIFICAR CANTIDAD DE HABITACIONES \n\n D.MODIFICAR EL TIPO DE VIVIENDA \n\n E. SALIR \n\n ", "Caracter invalido", 'A', 'E', 3);
							vivienda_modificar(viviendas, indexPosicion, opcionElegida);
						}while(opcionElegida != 'E');
					}
				}
				break;
			case 'C':
				if(ingresoVivienda == 0){
					printf("Debe ingresar una vivienda primero!!");
				}else{
					if(utn_getNumero(&id, "Ingrese el id de la vivienda que quiere dar de baja \n", "Id invalido \n", 20000, 21001, 3) == 0){
						indexPosicion= findViviendaById(viviendas, VIVIENDAS_LENG, id);
					}
					if(indexPosicion== -1){
						printf("\n Id no encontrada!!\n");
					}else{
						vivienda_baja(viviendas, indexPosicion);
					}
				}
				break;
			case 'D':
					if(ingresoVivienda == 0){
						printf("Debe ingresar una vivienda primero!!");
					}else{
						vivienda_ordenarPorNombre(viviendas,  VIVIENDAS_LENG);
						vivienda_imprimir(viviendas, VIVIENDAS_LENG);
					}
					break;
			case 'E':
					censista_listar(censistas, CENSISTAS_LENG);
				break;
			case 'F':
				printf("Saliendo...");
				break;
			default:
				printf("Opcion Invalida!");
		}


	}while(opcionElegida != 'F');




}
