/* @file: Cliente de pruebas para el módulo conjunto*/
/* @author: Miguel Gordo*/
/* Este módulo inicializa un cojunto cj e introduce una serie de números en él, que posteriormente trata de buscar. Se prueban búsquedas que deberían ser erróneas*/
/* Se eliminan algunas y se repite el mismo proceso. Por último se incluyen los números del 1 al 1000 y se extraen los impares,y se comprueban que sólo quedan éstos*/
/* Se libera el conjunto*/
/**/

#include<stdio.h>
#include"conjunto.h"
#include<stdlib.h>
#include<assert.h>


int main(void){

    CONJUNTO *cj;
    int i;
    ID a=4;
    cj = inicializarConjunto();
    /* creación correcta */
    assert(esConjuntoVacio(cj));
    insertarIdConjunto(cj, &a);
    a=1;
    insertarIdConjunto(cj, &a);
	a=15;
    insertarIdConjunto(cj, &a);
	a=5;
    insertarIdConjunto(cj, &a);
	a=20;
    insertarIdConjunto(cj, &a);
   /* inclusiones correctas */
    assert(insertarIdConjunto(cj, &a) == ERR);
	a=4;
    assert(estaId(cj, &a));
	a=1;
    assert(estaId(cj, &a));
	a=15;
    assert(estaId(cj, &a));
	a=5;
    assert(estaId(cj, &a));
	a=20;
    assert(estaId(cj, &a));
	a=0;
    assert(!estaId(cj, &a));
	a=2;
    assert(!estaId(cj, &a));
    assert(cardinalidadConjunto(cj)== 5);
	a=4;
    extraerIdConjunto(cj, a);
	a=20;
    extraerIdConjunto(cj, a);
    /* eliminación correctas */
	a=4;
    assert(!estaId(cj, &a));
	a=20;
    assert(!estaId(cj, &a));
    assert(cardinalidadConjunto(cj)== 3);
    a=1;
    assert(extraerIdConjunto(cj, a)==OK);
    a=15;
    assert(extraerIdConjunto(cj, a)==OK);
    a=5;
    assert(extraerIdConjunto(cj, a)==OK);

    /*Incluye los números del uno al 1000 y extrae los impares, comrueba que solo quedan los pares y que quedan todos. Esto prueba la memoria dinámica*/

	for(i=1;i<=1000;i++){
		a=(ID)i;
		assert(insertarIdConjunto(cj, &a)==OK);
	}

	a=256;
	i=indiceIdConjunto(cj, &a);
	assert(a==obtenerIdConjunto(cj, i));/*Comprueba que el índice obtenido corresponde al ID dado*/

	for(i=1;i<=1000;i=i+2){
		a=(ID)i;
		assert(extraerIdConjunto(cj, a)==OK);
	}
	for(i=2;i<=1000;i=i+2){
		a=(ID)i;
		assert(estaId(cj, &a)==TRUE);
	}

	assert(cardinalidadConjunto(cj)== 500);

    /* destrucción correcta */
    destruyeConjunto(&cj);
    assert(cj == NULL);
    
    printf("Pruebas superadas con éxito\n");
    
    return 0;
}

