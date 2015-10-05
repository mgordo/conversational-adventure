/**
 * @brief Cuerpo de las primitivas de lector de reglas xml
 *
 * Este modulo contiene los cuerpos de los prototipos de las funciones de lectura de reglas en xml
 * @file lector_reglas.h
 * @author Carlos Carrascal
 * @date 25-11-2010
*/




#ifndef _LECTORREG_H
#define _LECTORREG_H


#include "reglas.h"
#include <stdio.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>


/*****************************************************************/
/**		FUNCIONES DE LECTOR				*/
/*****************************************************************/

/**
 * @brief Inicialización de reglas
 * Esta función permite leer un conjunto de reglas de un fichero xml y almacenarlas
 * @param nombrefich es puntero a char con el nombre del fichero xml
 * @return Puntero a la estructura regla correctamente inicializada, NULL en caso contrario
 * @author Carlos Carrascal*/

REGLAS *iniReglas(char *nombrefich);

/*****************************************************************/
/**		FUNCIONES DE LECTURA REGLA			*/
/*****************************************************************/

/**
 * @brief Procesa Regla
 * Esta función permite leer todos los campos de una regla de un fichero xml. Al salir estará guardado en la estructura regla
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param regla es puntero a REGLA en el que introducir los datos
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaReglas(xmlDocPtr doc, xmlNodePtr cur, REGLA * regla);

/*****************************************************************/
/**		FUNCIONES DE LECTURA CONDICIONES		*/
/*****************************************************************/

/**
 * @brief Procesa Condiciones
 * Esta función permite leer los campos de una regla correspondientes a las condiciones de ejecución desde un fichero xml. Al salir será guardado en la estructura regla
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param regla es puntero a REGLA en el que introducir los datos
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaCondiciones(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla);

/*****************************************************************/
/**		FUNCIONES DE LECTURA CONSECUENIAS		*/
/*****************************************************************/

/**
 * @brief Procesa Consecuencias
 * Esta función permite leer los campos de una regla correspondientes a las consecuencias de ejecución desde un fichero xml. Al salir será guardado en la estructura regla
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param regla es puntero a REGLA en el que introducir los datos
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaConsecuencias(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla);

/*****************************************************************/
/**		FUNCIONES DE LECTURA FRASE		*/
/*****************************************************************/

/**
 * @brief Procesa Frase
 * Esta función permite leer la frase asociada a una regla correspondientes desde un fichero xml. Al salir será guardado en la estructura regla
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param regla es puntero a REGLA en el que introducir los datos
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaFrase(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla);

/*****************************************************************/
/**		FUNCION AUXILIAR 				*/
/*****************************************************************/

/**
 * @brief seleccionaCampo
 * Esta funcion convierte un char en su correspondiente campo
 * @param medio1 es el char a convertir
 * @return devuelve directamente el tipo campo que corresponda
 * @author Carlos Carrascal*/
CAMPO seleccionaCampo(char *medio1);

#endif



