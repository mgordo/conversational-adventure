/**
 * @brief Primitivas de las funciones lector_reglasdialogo
 * Este modulo contiene los prototipos de las funciones de lector_Reglas dialogo 
 * @file lector_reglasdialogo.h 
 * @author Miguel Gordo
 * @version 1.0 
 * @date 24-11-2010 
*/

#ifndef LECTORREGLASDIALOGO_H_
#define LECTORREGLASDIALOGO_H_
#include"reglasdialogo.h"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/**
 * @brief iniDiálogo
 * Esta función permite leer de un fichero xml una estructura DIALOGUE. Los temas se procesan sin llamar a subrutinas
 * @param nombrefich es char pointer con el nombre del fichero xml a leer
 * @return puntero a estrucutra DIALOGUE correctamente inicializada, NULL en caso contrario
 * @author Miguel Gordo*/
DIALOGUE *iniDialogo(char *nombrefich);


/**
 * @brief procesaRegla
 * Esta función permite procesar una estructura REGLAD de un fichero xml 
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param rule es puntero a estructura REGLAD en la que guardar los datos
 * @param ini es entero con el campo ini de la REGLAD
 * @param fin es entero con el campo fin de la REGLAD
 * @return OK si se guardó correctamente o ERR si hubo error
 * @author Miguel Gordo*/
STATUS procesaRegla(xmlDocPtr doc, xmlNodePtr cur,REGLAD *rule, int ini, int fin);

/**
 * @brief iniDiálogo
 * Esta función permite leer de un fichero xml una estructura DIALOGUE 
 * @param plant es un puntero a la PLANTILLA donde se va a guardar lo leido
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @return valor STATUS: OK o ERR dependiendo del resultado de la operacion
 * @author Miguel Gordo*/

STATUS procesaPlantilla(xmlDocPtr doc, xmlNodePtr cur,PLANTILLA *plant);

/**
 * @brief iniDiálogo
 * Esta función permite leer de un fichero xml una estructura DIALOGUE 
 * @param tam es un entero
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param rel es un puntero a la RELATION donde se quiere guardar lo leido
 * @return valor STATUS: OK o ERR dependiendo del resultado de la operacion
 * @author Miguel Gordo*/

STATUS procesaRelacion(xmlDocPtr doc, xmlNodePtr cur,RELATION *rel,int tam);





#endif
