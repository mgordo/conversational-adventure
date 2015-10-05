/**
 * @brief Primitivas de Conjunto 
 * Este modulo contiene los prototipos de las funciones de manejo de conjuntos 
 * @file conjunto.h 
 * @author Miguel Gordo 
 * @version 1.0 
 * @date 29-10-2010 
*/

#ifndef _CONJUNTO_H
#define _CONJUNTO_H




#include"tipos.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/** @brief Definición de la estructura que albergará un conjunto */
typedef struct {
	ID *elems;	/*!< Array de elementos del conjunto*/
	int card;	/*!< Cardinalidad del conjunto*/
	int max;	/*!< Máximo número de elementos del conjunto*/
} CONJUNTO;

/**Definición del puntero a función para comparar con búsqueda binaria*/
typedef int (* pfunc_compar)(ID *, ID *);


/**
 * @brief Inicialización de Conjunto
 * inicializarConjunto() construye un conjunto de Id
 * @return puntero al Conjunto que ha conseguido inicializar
 * NULL si hubiera error
 */
CONJUNTO *inicializarConjunto ();

/**
 * @brief destruyeConjunto
 * DestruyeConjunto permite liberar toda la memoria asociada a un conjunto
 * @param c es puntero al conjunto a liberar
 * @return OK si se liberó correctamente, ERR en caso contrario. c adquiere el valor NULL para evitar llamadas erroneas a posteriori en caso de OK
*/
STATUS destruyeConjunto(CONJUNTO **c);


/**
 * @brief Comparación de Id
 * idcompar permite comparar dos ID para ver si son iguales, mayor o menor que el otro
 * @param a es primer puntero a ID
 * @param b es segundo puntero a ID
 * @return Un número negativo, cero o positivo si a<b, a=b o a>b respectivamente
*/
int idcompar(ID *a, ID *b);

/**
 * @brief CardinalidadConjunto

 * Cardinalidad Conjunto obtiene el cardinal de un conjunto
 * @param c es puntero al conjunto del que obtener los datos
 * @return un entero con la cardinalidad de ese conjunto
*/
int cardinalidadConjunto (const CONJUNTO *c);


/**
 * @brief Es conjunto Vacío
 *
 * esConjuntoVacío permite determinar si un conjunto es vacío o no
 * @param c es puntero al conjunto del que obtener los datos
 * @return BOOL que indica TRUE si es vacío y FALSE en el caso contrario
*/
BOOL esConjuntoVacio (const CONJUNTO *c);

/**
 * @brief estaid
 *
 * estaid permite saber si un ID determinado se encuentra o no en el conjunto
 * @param c es puntero a Conjunto en el que buscar
 * @param e es puntero a ID que contiene el ID a buscar
 * @return TRUE si está en el conjunto y FALSE en el caso contrario
*/
BOOL estaId(const CONJUNTO *c, const ID *e);


/**
 * @brief insertarIdConjunto
 *
 * insertarIdConjunto permite insertar un Id en un conjunto
 * @param c es puntero a Conjunto en el que insertar
 * @param e es puntero a ID que contiene el ID a insertar
 * @return OK si se insertó correctamente o ERR si hubo error
*/
STATUS insertarIdConjunto (CONJUNTO *c, const ID *e);

/**
 * @brief extraerIdConjunto
 * extraerIdConjunto permite eliminar un Id en un conjunto
 * @param c es puntero a Conjunto en el que extraer
 * @param e es puntero a ID que contiene el ID a extraer
 * @return OK si se extrajo correctamente o ERR si hubo error
*/
STATUS extraerIdConjunto(CONJUNTO *c, const ID e);

/**
 * @brief indiceIdConjunto
 * indiceIdConjunto obtiene el indice del ID buscado
 * @param c es puntero a Conjunto en el que buscar
 * @param e es puntero a ID que contiene el ID a buscar
 * @return -1 si no existe en el conjunto o el índice en el que se encuentra
*/
int indiceIdConjunto(CONJUNTO *c, const ID *e);

/**
 * @brief obtenerIdConjunto
 * Permite consultar el ID de un índice dado
 * @param c es puntero a Conjunto en el que buscar
 * @param indice es entero que indica el índice a consultar
 * @return ID del elemento o ID nulo si no existiera
*/
ID obtenerIdConjunto(CONJUNTO *c, int indice);

#endif



