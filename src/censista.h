#ifndef CENSISTA_H_
#define CENSISTA_H_

#define NOMBRE_LENG 51
#define TELEFONO_LENG 20

typedef struct{
	int legajoCensista;
	char nombre[NOMBRE_LENG];
	int edad;
	char telefono[TELEFONO_LENG];
}Censista;

int censista_listar(Censista* pArray, int largo);
int censista_listarVivienda(Censista pArray, int largo);

#endif /* CENSISTA_H_ */
