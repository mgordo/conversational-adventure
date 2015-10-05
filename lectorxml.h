/**
 * @brief Primitivas de lector xml 
 * Este modulo contiene los prototipos de las funciones de lectura en xml 
 * @file lectorxml.h 
 * @author Miguel Gordo y Carlos Carrascal
 * @version 1.0 
 * @date 29-10-2010 
*/



#include"mundo.h"
#include<stdio.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>


#ifndef _LECTORXML_H
#define _LECTORXML_H


/*****************************************************************/

/**		FUNCIONES DE LECTOR		*/		

/*****************************************************************/

/**
 * @brief Inicialización de Mundo
 * Esta función permite leer un mundo de fichero xml e inicializar un MUNDO con esos datos
 * @param nombrefich es puntero a char con el nombre del fichero xml
 * @return Puntero al mundo correctamente inicializado, NULL en caso contrario
 * @author Miguel Gordo*/

MUNDO *iniMundo(char *nombrefich);

/*****************************************************************/

/**		FUNCIONES DE LECTURA JUGADOR			*/

/*****************************************************************/

/**
 * @brief Procesa Jugador
 * Esta función permite leer todos los campos de un jugador de un fichero xml. Al salir estará guardado en mundo
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param mundo es puntero al MUNDO en el que introducir el jugador
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaJugador(xmlDocPtr doc, xmlNodePtr cur,MUNDO *mundo);

/**
 * @brief ProcesaNombreJugador
 * Esta función permite leer el nombre de un jugador
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param jug es puntero al jugador en el que introducir el nombre
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaNombreJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug);

/**
 * @brief ProcesaLocalizacionJugador
 * Esta función permite leer la posición de un jugador
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param jug es puntero al jugador en el que introducir la localización
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaLocalizacionJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug);

/**
 * @brief ProcesaMaxObjetosJugador
 * Esta función permite leer el máximo de objetos de un jugador
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param jug es puntero al jugador en el que introducir el máximo
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaMaxObjetosJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug);

/**
 * @brief ProcesInvJugador
 * Esta función permite leer el inventario inicial de un jugador
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param jug es puntero al jugador en el que introducir el máximo
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaobjInvJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug);


/*****************************************************************/

/**		FUNCIONES DE LECTURA ESPACIO			*/

/*****************************************************************/

/**
 * @brief Procesa Espacio
 * Esta función permite leer todos los campos de un espacio de un fichero xml. Al salir estará guardado en mundo
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param mundo es puntero al MUNDO en el que introducir el espacio
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaEspacio(xmlDocPtr doc,xmlNodePtr cur,MUNDO *mundo);

/**
 * @brief procesaDescripcionEspacio
 * Esta función permite leer la descripción de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la descripción a leer
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaDescripcionEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief Procesa Descripción Gráfica Espacio
 * Esta función permite leer la descripción gráfica de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la descripción gráfica
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaDescrGraficaEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaEdescripcionEspacio
 * Esta función permite leer la descripción de un espacio a examinar
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la descripción de examinar a leer
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/
	
STATUS procesaEdescripcionEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaNorteEspacio
 * Esta función permite leer el norte de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión norte
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaNorteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaSurEspacio
 * Esta función permite leer el sur de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión sur
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaSurEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaEsteEspacio
 * Esta función permite leer el este de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión este
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaEsteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaOesteEspacio
 * Esta función permite leer el oeste de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión oeste
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaOesteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaArribaEspacio
 * Esta función permite leer el arriba de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión arriba
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaArribaEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaAbajoEspacio
 * Esta función permite leer el abajo de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la conexión abajo
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaAbajoEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);

/**
 * @brief procesaLuzEspacio
 * Esta función permite leer el campo Luz de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir la luz
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaLuzEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);


/**
 * @brief procesaObjetosEspacio
 * Esta función permite leer los objetos de un espacio
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param espacio es puntero al ESPACIO en el que introducir los objetos
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaObjetosEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio);


/*****************************************************************/

/**		FUNCIONES DE LECTURA UNION			*/	

/*****************************************************************/

/**
 * @brief Procesa Union
 * Esta función permite leer todos los campos de una union de un fichero xml. Al salir estará guardado en mundo
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param mundo es puntero al MUNDO en el que introducir la union
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaUnion(xmlDocPtr doc, xmlNodePtr cur,MUNDO *mundo);

/**
 * @brief Procesa la Id de llegada
 * Esta función permite leer la Id del espacio de llegada de una union
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param uni es puntero a la union en la cual introducir la id de llegada
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaIdLlegada(xmlDocPtr doc,xmlNodePtr cur, UNION * uni);

/**
 * @brief Procesa la llave que lo abre
 * Esta función permite leer la llave que abre una union
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param uni es puntero a la union en la cual introducir la llave
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/


STATUS procesaKeyUnion(xmlDocPtr doc, xmlNodePtr cur, UNION * uni);

/**
 * @brief Procesa la Id de salida
 * Esta función permite leer la Id del espacio de salida de una union
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param uni es puntero a la union en la cual introducir la id de salida
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaIdSalida(xmlDocPtr doc,xmlNodePtr cur, UNION * uni);

/**
 * @brief Procesa union abierta
 * Esta funcion permite leer el campo Abierta de una union
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param uni es puntero a la union en la cual introducir el booleano abierta
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaUnionAbierta(xmlDocPtr doc, xmlNodePtr cur, UNION * uni);

/*****************************************************************/

/**		FUNCIONES DE LECTURA OBJETO			*/

/*****************************************************************/


/**
 * @brief Procesa Objeto
 * Esta función permite leer todos los campos de un objeto de un fichero xml. Al salir estará guardado en mundo
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param mundo es puntero al MUNDO en el que introducir el objeto
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaObjeto(xmlDocPtr doc, xmlNodePtr cur, MUNDO *mundo);


/**
 * @brief ProcesaNombreObjeto
 * Esta función permite leer el nombre de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es puntero al objeto en el que introducir el nombre
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaNombreObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaDescripcionObjeto
 * Esta función permite leer la descripción de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto en el que introducir la descripción a leer
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaDescripcionObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaDescMovido
 * Esta función permite leer la descripcion de un objeto movido
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto en el que introducir la descripcion a leer
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaDescMovido(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaLuzObjeto
 * Esta función permite leer el campo Luz de un onjeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es puntero al OBJETO en el que introducir la luz
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/

STATUS procesaLuzObjeto(xmlDocPtr doc,xmlNodePtr cur,OBJETO *objeto);

/**
 * @brief procesaDescExaminar
 * Esta función permite leer la descripción de un objeto al ser examinado
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto en el que introducir la descripcion a leer
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaDescExaminar(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaMovilObjeto
 * Esta función permite leer el campo Movil de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto donde introducir movil
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaMovilObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaMovidoObjeto
 * Esta función permite leer el campo Movido de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto donde introducir movido
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaMovidoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaOcultoObjeto
 * Esta función permite leer el campo Oculto de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto donde introducir Oculto
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaOcultoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaEncendidoObjeto
 * Esta función permite leer el campo Encendido de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto donde introducir Encendido
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaEncendidoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief procesaContenedorObjeto
 * Esta función permite leer el campo Contenedor de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es un puntero al objeto donde introducir Contenedor
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaContenedorObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);


/**
 * @brief ProcesInvObjeto
 * Esta función permite leer el inventario inicial de un objeto
 * @param doc es puntero a la estructura xmlDoc
 * @param cur es puntero a la estructura xmlNode
 * @param objeto es puntero al objeto en el que introducir el inventario
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Carlos Carrascal*/

STATUS procesaInvObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto);

#endif



