/**
 * @brief Tipos del Proyecto
 * @file tipos.h
 * @version 1.0
 * @author Todos
 * 
 *Descripción: definición de constantes, tipos, errores y BOOL

 *Fecha: 23-01-2009
*/

#ifndef _TIPOS_H
#define _TIPOS_H

/** @brief Enumeracion BOOL */
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
/** @brief Enumeracion STATUS */
typedef enum { ERR = -1, OK = 0 } STATUS;
/** @brief Enumeracion ID */
typedef long int ID;
/** @brief Enumeracion DIRECCION */
typedef enum { N=0, S, E, O, U, D} DIRECCION;
/** @brief Enumeracion GAMES */
typedef enum {OVER=-6,VICTORY,KEEP} GAMES;

/** @brief Definicion del maximo de Reglas */
#define MAX_REGLAS 50
/** @brief Definicion de la Longitud maxima de cadenas*/
#define MAX_LEN 2048
/** @brief Definicion del numero maximo de filas para la iografica*/
#define MAX_FILAS 24
/** @brief Definicion del numero maximo de columnas para la iografica*/
#define MAX_COLUMNAS 80
/** @brief Definicion */
#define NO_ENCONTRADO -10

#endif
