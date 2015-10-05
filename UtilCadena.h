/**
* @brief Utilidades de transformacion de cadenas
* Este modulo contiene los prototipos de las funciones de transformacion de cadenas
* @file UtilCadena.h
* @author Carlos Carrascal
* @date 23-11-2010
*/

#ifndef UTILCADENA_H_
#define UTILCADENA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipos.h"


/**
* @brief Eliminacion de caracteres
* @author Carlos Carrascal
* eliminaCars() copia ori en dst y elimina los caracteres presentes en seps
* @param dst cadena de caracteres donde guardar
* @param ori cadena de caracteres original
* @param seps cadenas de los caracteres no deseados
* @return OK si fue bien, ERR si fallo
*/
STATUS eliminaCars(char * dst, char * ori, char * seps);


/**
* @brief Transformacion de cadena a mayusculas
* @author Carlos Carrascal
* aMayusculas() copia ori en dst y transforma caracter a caracter a mayuscula
* @param dst cadena de caracteres donde guardar
* @param ori cadena de caracteres aleatoria
* @return OK si fue bien, ERR si fallo
*/
STATUS aMayusculas(char * dst, char * ori);


/**
* @brief Sustitucion de caracteres
* @author Carlos Carrascal
* reemplazaAsterisco() sustituye los asteriscos de ori por lo que ponga en ins, y lo almacenará en dst
* @param dst cadena de caracteres donde guardar
* @param ori cadena de caracteres original
* @param ins cadena de caracteres que sustituir
* @return OK si fue bien, ERR si fallo
*/
STATUS reemplazaAsterisco(char * dst, char * ori, char * ins);


/**
* @brief Eliminacion los caracteres de espacio
* @author Carlos Carrascal
* limpiaEspacios() almacena en dst la cadena ori sin ningun espacio ni al principio ni al final de la cadena, ni con dos espacios seguidos
* @param dst cadena de caracteres donde guardar
* @param ori cadena de caracteres original
* @return OK si fue bien, ERR si fallo
*/
STATUS limpiaEspacios(char * dst, char * ori);


/**
* @brief Eliminacion de palabras comunes
* @author Carlos Carrascal
* limpiaPalabras() almacena en dst la cadena ori quitando palabras comunes como articulos, determinantes, posesivos, etc.
* @param dst cadena de caracteres donde guardar
* @param ori cadena de caracteres original
* @return OK si fue bien, ERR si fallo
*/
STATUS limpiaPalabras(char * dst, char * ori);

#endif /* UTILCADENA_H_ */

