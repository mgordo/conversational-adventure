/**
 * @file espacio.h
 * Fichero que contiene los prototipos y las estructuras de un ESPACIO
 * @author Antonio Jimenez y Miguel Gordo
 * @version 1.0
 * 
 * Información útil:
 * 
 *	- Este módulo depende del módulo CONJUNTO, por lo que se incluirá el .h correspondiente
 */


#include <string.h>
#include "inventario.h"
#ifndef _ESPACIO_H
#define _ESPACIO_H

/** @brief Definición de la estructura ESPACIO*/
typedef struct {
	ID id;	/*!< ID del espacio*/
	char *descripcion; /*!< Cadena que contiene la descripción que se da al estar en un espacio*/
	char *descExaminar; /*!< Cadena que contiene la descripción que se da al examinar el espacio*/
	char **descGrafica; /*!< Descripcion gráfica*/
	int filas; /*!< Filas de la descripcion gráfica*/
	int columnas; /*!< Columnas de la descripcion gráfica*/
	INVENTARIO *inv; /*!< Inventario con los objetos que se encuentren en el Espacio*/
	BOOL luminoso; /*!< Booleano que indica si un Espacio tiene luz propia o no*/
	ID norte; /*!< ID de la Union del norte*/
	ID sur; /*!< ID de la Union del sur*/
	ID este; /*!< ID de la Union del este*/
	ID oeste; /*!< ID de la Union del oeste*/
	ID arriba; /*!< ID de la Union de abajo*/
	ID abajo; /*!< ID de la Union de abajo*/
} ESPACIO;

/**
 * Información de la estructura:
 * 
 *	- id es el identificador del espacio
 *	- descripcion es un puntero a una cadena que almacenará la descripción básica del espacio
 *	- descExaminar es un puntero a una cadena que almacenará una descripción exaustiva del objeto
 *	- inv será el inventario del espacio, que almacenará los objeto que haya en dicho espacio
 *	- luminoso es un atributo que indica si un espacio está iluminado o no
 *	- norte, sur, este, oeste, arriba, abajao son los id de las uniones que haya en esa dirección
 */

/**
 * @brief Creación de Espacio
 * creaEspacio() se encarga de reservar la memoria para un nuevo Espacio
 * @param e es un puntero a un puntero a ESPACIO, que será donde se guarde la dirección de el ESPACIO que se reserve
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS creaEspacio(ESPACIO **e);

/**
 * @brief Destrucción de Espacio
 * destruyeEspacio() se encarga de liberar toda la memoria que hubiese resrvado un Espacio en caso de estar reservada
 * @param e es un puntero al puntero del Espacio que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jiménez Pastor*/
STATUS destruyeEspacio(ESPACIO **e);

/**
 * @brief Cambiar ID
 * cambiaEspId() permite cambiar la ID con que se etiqueta un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspId(ESPACIO *e, ID id);

/**
 * @brief Cambiar Grafica
 * cambiaEspDescGrafica() permite cambiar la descripción gráfica de un espacio
 * @param e es puntero al espacio en el que guardar la desscripción gráfica
 * @param dibujo es puntero de char con la descripción gráfica a guardar
 * @param filas es entero con el número de filas de la descripción gráfica
 * @param columnas es entero con el número de columnas de la descripción gráfica
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/
STATUS cambiaEspDescGrafica(ESPACIO *e,char *dibujo,int filas,int columnas);

/**
 * @brief Cambiar Descripcion
 * cambiaEspDescripcion() permite cambiar la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param desc es una cadena con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspDescripcion(ESPACIO *e, char *desc);

/**
 * @brief Cambiar Examinar
 * cambiaEspDescExaminar() permite modificar la descripcion examinar de un ESPACIo
 * @param e es un puntero al ESPACIO a modificar
 * @param desc es una cadena con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspDescExaminar(ESPACIO *e, char *desc);

/**
 * @brief Cambiar Luminoso
 * cambiaEspLuminoso() permite modificar el estado del espacio entre luminoso y no luminoso
 * @param e es un puntero al ESPACIO a modificar
 * @param luz es un BOOL con el que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspLuminoso(ESPACIO *e, BOOL luz);

/**
 * @brief Cambiar Norte
 * cambiaEspNorte() permite cambiar la ID de la UNION que se encuentra al norte del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspNorte(ESPACIO *e, ID n);

/**
 * @brief Cambiar Sur
 * cambiaEspSur() permite cambiar la ID de la UNION que se encuentra al sur del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspSur(ESPACIO *e, ID n);

/**
 * @brief Cambiar Este
 * cambiaEspEste() permite cambiar la ID de la UNION que se encuentra al este del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspEste(ESPACIO *e, ID n);

/**
 * @brief Cambiar Oeste
 * cambiaEspOeste() permite cambiar la ID de la UNION que se encuentra al oeste del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspOeste(ESPACIO *e, ID n);

/**
 * @brief Cambiar Arriba
 * cambiaEspArriba() permite cambiar la ID de la UNION que se encuentra arriba del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspArriba(ESPACIO *e, ID n);

/**
 * @brief Cambiar Abajo
 * cambiaEspAbajo() permite cambiar la ID de la UNION que se encuentra abajo del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEspAbajo(ESPACIO *e, ID n);

/**
 * @brief ¿Está destruida?
 * isEspDestruido() permite saber si un ESPACIO está destruido o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isEspDestruido(ESPACIO *e);

/**
 * @brief ¿Está vacio?
 * isEspEmpty() permite saber si un ESPACIO ha sido rellenado o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isEspEmpty(ESPACIO *e);

/**
 * @brief ¿Está iluminado?
 * isEspLuminoso() permite saber si un ESPACIO tiene luz propia o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isEspLuminoso(ESPACIO *e);

/**
 * @brief Saber ID
 * saberEspid() permite saber la ID de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspId(ESPACIO *e, ID *id);

/**
 * @brief Descripción de un ESPACIO
 * saberEspDescripcion() permite saber el contenido de la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param desc es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspDescripcion(ESPACIO *e, char *desc);

/**
 * @brief saberEspDescrGrafica
 * Esta función permite saber la descripción Gráfica de un espacio a examinar
 * @param dibujo es puntero a matriz que contendrá el espacio
 * @param filas es puntero a int que contendrá el número de filas de la descripción gráfica
 * @param esp es puntero al ESPACIO del que conocer la descripción gráfica
 * @param columnas es puntero a int que contendrá el número de columnas de la descripción gráfica
 * @return ERR si no se idevolvió correctamente o OK en caso contrario
 * @author Miguel Gordo*/
STATUS saberEspDescrGrafica(ESPACIO *esp,char ***dibujo,int *filas, int *columnas);

/**
 * @brief Examinar un espacio
 * saberEspDescExaminar() permite saber el contenido de la descripcion examinar de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param desc es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspDescExaminar(ESPACIO *e, char *desc);

/**
 * @brief Tamaño de Descripcion
 * saberEspTamDesc() permite saber el tamaño de la cadena que contiene la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspTamDesc(ESPACIO *e, int *num);

/**
 * @brief Tamaño de Examinar
 * saberEspTamDescExam() permite saber el tamaño de la cadena que contiene la descripción examinar del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspTamDescExam(ESPACIO *e, int *num);

/**
 * @brief Saber Norte
 * saberEspNorte() permite saber la ID de el ESPACIO que se encuentra al norte del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspNorte(ESPACIO *e, ID *id);

/**
 * @brief Saber Sur
 * saberEspSur() permite saber la ID de el ESPACIO que se encuentra al sur del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspSur(ESPACIO *e, ID *id);

/**
 * @brief Saber Este
 * saberEspEste() permite saber la ID de el ESPACIO que se encuentra al este del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspEste(ESPACIO *e, ID *id);

/**
 * @brief Saber Oeste
 * saberEspOeste() permite saber la ID de el ESPACIO que se encuentra al oeste del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspOeste(ESPACIO *e, ID *id);

/**
 * @brief Saber Arriba
 * saberEspArriba() permite saber la ID de el ESPACIO que se encuentra arriba del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspArriba(ESPACIO *e, ID *id);

/**
 * @brief Saber Abajo
 * saberEspAbajo() permite saber la ID de el ESPACIO que se encuentra abajo del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspAbajo(ESPACIO *e, ID *id);

	/*Funciones de manejo del inventario*/

/**
 * @brief Sacar objetos
 * sacarEspObj() extrae de un inventario de un ESPACIO un objeto
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID del objeto que se desea extraer
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS sacarEspObj(ESPACIO *e, ID id);

/**
 * @brief Introducir objetos
 * meterEspObj() introduce un objeto en el inventario de un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID del objeto que se desea guardar
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS meterEspObj(ESPACIO *e, ID id);

/**
 * @brief Tamaño del inventario
 * saberEspTamInv() permite saber cuantos objeto se encuentran en el ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberEspTamInv(ESPACIO *e, int *num);

/**
 * @brief Objeto contenido
 * isObjinEsp() permite saber si un objeto se encuentra en el inventario de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es una ID del objeto que se quiere saber si está o no en el ESPACIO
 * @return TRUE o FALSE según el caso
 * @author Antonio Jiménez Pastor*/
BOOL isObjinEsp(ESPACIO *e, ID id);

/**
 * @brief Saber un Objeto
 * saberEspIesimoObj() permite saber el iésimo objeto del inventario del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param i es la posición que se desea conocer
 * @return devuelve la ID del objeto que se encuentre en dicha posición
 * @author Antonio Jiménez Pastor*/
ID saberEspIesimoObj(ESPACIO *e, int i);

#endif


