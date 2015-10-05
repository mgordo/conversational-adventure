/**
* @brief Utilidades para el dialogo
* Este modulo contiene los prototipos de las funciones que interactuan con el juego
* @file dialogo.h
* @author Carlos Carrascal
* @version 1.0
* @date 01-12-2010
*/

#include "motor.h"
#include "accion.h"
#include "UtilCadena.h"
#include "lector_reglasdialogo.h"


/**
* @brief el usuario interactuca con el juego
* dialogo() reserva una accion y la ejecuta siguiendo sus reglas
* @param fmundo es el fichero del cual leer el mundo
* @param freglas es el fichero del cual leer las reglas 
* @param fdialogo es el fichero del cual leer las reglas del dialogo
* @return OK si todo fue bien, ERR en caso contrario
*/
STATUS dialogo(char * fmundo, char * freglas, char * fdialogo);


/**
* @brief dada una frase se interpreta y se crea una accion
* interpretaFrase() modifica una accion con las cadenas necesarias
* @param dialogo es un puntero al dialogo
* @param accion es un puntero a la estructura accion
* @param cadena es la entrada del usuario
* @return OK si todo fue bien, ERR en caso contrario
*/
STATUS interpretaFrase(DIALOGUE * dialogo, ACCION * accion, char * cadena);


