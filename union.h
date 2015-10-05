/**
 * @file union.h
 * Fichero que contiene los prototipos y las estructuras de una UNION
 * @author Antonio Jimenez
 * @version 1.0
 * 
/**Información útil:
 * 
 *	- Este módulo depende del módulo CONJUNTO, por lo que se incluirá el .h correspondiente
*/

#include <string.h>
#include "conjunto.h"

#ifndef _UNION_H
#define _UNION_H


/**Definición de la estructura UNION*/
typedef struct {
	ID id; /*!< Es la ID que identifica a la UNION*/
	ID salida;/*!< Es la ID del ESPACIO de salida*/
	ID llegada;/*!< Es la ID del ESPACIO de llegada*/
	BOOL abierta;/*!< Es un booleano que indica si la unión está abierta o no*/	
	ID key;/*!< Es la ID del OBJETO que abre la UNION*/
} UNION;

/**
 *Información de la estructura:
 * 
 *	- id es el identificador de la unión
 *	- salida es el identificador del espacio de donde sale la unión
 *	- llegada es el identificador del espacio al que llega la unión
 *	- abierta es un valor BOOL que indica si la unión está abierta o no. Si no estuviese abierta, no se podría atravesar
 **/ 

/**
 * @brief Creación de Unión
 * creaUnion() se encarga de reservar la memoria para una nueva Unión
 * @param u es un puntero a un puntero a UNION, que será donde se guarde la dirección de la UNION que se reserve
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS creaUnion(UNION **u);

/**
 * @brief Destrucción de Unión
 * destruyeUnion() se encarga de liberar toda la memoria que hubiese resrvado una Unión en caso de estar reservada
 * @param u es un puntero al puntero de la Unión que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jiménez Pastor*/
STATUS destruyeUnion(UNION **u);

/**
 * @brief Cambio de Id
 * cambiaUniId() se encarga de etiquetar una UNION con una Id concreta
 * @param u es un puntero a la UNION a modificar
 * @param id es una ID con la que se desea modificar la UNION
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaUniId(UNION *u, ID id);

/**
 * @brief Cambio de Salida
 * cambiaUniSalida() cambia la ID del espacio del que parte la UNION
 * @param u es un puntero a la UNION a modificar
 * @param id es una ID con la que se desea modificar la UNION
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaUniSalida(UNION *u, ID id);

/**
 * @brief Cambio de Llegada
 * cambiaUniLlegada() cambia la ID del espacio al que llega la UNION
 * @param u es un puntero a la UNION a modificar
 * @param id es una ID con la que se desea modificar la UNION
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaUniLlegada(UNION *u, ID id);

/**
 * @brief Cambio de Abierta
 * cambiaUniAbierta() permite definir si una UNION está o no abierta
 * @param u es un puntero a la UNION a modificar
 * @param abierto es un BOOL con el dato que se desea introducir
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaUniAbierta(UNION *u, BOOL abierto);

/**
 * @brief Cambio de Llave
 * cambiaUniKey() permite determinar la ID del objeto que permita abrir una UNION
 * @param u es un puntero a la UNION a modificar
 * @param key es la ID con la que desea modificar la UNION
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaUniKey(UNION *u, ID key);

/**
 * @brief ¿Está destruida?
 * isUniDestruida() permite saber si una UNION está destruida o no
 * @param u es un puntero a la UNION a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isUniDestruida(UNION *u);

/**
 * @brief ¿Está vacía?
 * isUniEmpty() permite saber si una UNION ha sido rellenada con datos o no
 * @param u es un puntero a la UNION a comprobar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isUniEmpty(UNION *u);

/**
 * @brief ¿Está abierta?
 * isUniAbierta() permite saber si una UNION está o no abierta
 * @param u es un puntero a la UNION a comprobar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isUniAbierta(UNION *u);

/**
 * @brief Id de la UNION
 * saberUniId() permite saber la ID de la UNION
 * @param u es un puntero a la UNION a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberUniId(UNION *u, ID *id);

/**
 * @brief Espacio Salida
 * saberUniSalida() permite saber la ID del espacio del que parte la UNION
 * @param u es un puntero a la UNION a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberUniSalida(UNION *u, ID *id);

/**
 * @brief Espacio Llegada
 * saberUniLlegada() permite saber la ID del espacio al que llega la UNION
 * @param u es un puntero a la UNION a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberUniLlegada(UNION *u, ID *id);

/**
 * @brief Saber Llave
 * saberUniKey() permite saber la ID del objeto que abre la UNION
 * @param u es un puntero a la UNION a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberUniKey(UNION *u, ID *id);

#endif


