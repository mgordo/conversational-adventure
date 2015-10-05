
/**/
/* Autor: Miguel Gordo*/
/* Fecha: 3-XI-2010*/
/* Equipo 06, proyecto prog, modulo inventario.c*/
/**/



#include<stdio.h>
#include"inventario.h"



INVENTARIO *creaInventario(){

	return inicializarConjunto();

}


STATUS destruyeInventario(INVENTARIO **i){

	return destruyeConjunto(i);
}


STATUS insertaInventario(INVENTARIO *i, const ID *e){

	return insertarIdConjunto(i,e);

}


STATUS extraeInventario(INVENTARIO *i,const ID e){

	return extraerIdConjunto(i, e);

}


BOOL estaInventario(const INVENTARIO *i,const  ID *e){

	return estaId(i, e);

}



int tamanioInventario(const INVENTARIO *i){

	return cardinalidadConjunto (i);

}


ID obtenerIdInventario(INVENTARIO *i, int indice){

	return obtenerIdConjunto(i,indice);

}


BOOL vacioInventario(const INVENTARIO *i){

	return esConjuntoVacio(i);

}

