/**
 * @file jugador.h
 * Fichero que contiene los prototipos y las estructuras de un JUGADOR
 * @author Antonio Jimenez
 * @version 0.0
 * 
 *Información útil:
 * 
 *	- Este módulo depende del módulo CONJUNTO, por lo que se incluirá el .h correspondiente
*/

#include <string.h>
#include "inventario.h"

#ifndef _JUGADOR_H
#define _JUGADOR_H

/** @brief Definición de la estructura JUGADOR*/
typedef struct {
	ID id; /*!< Una ID que identifica al JUGADOR*/
	char *nombre;/*!< UNa cadena con el nombre del JUGADOR*/
	ID localizacion;/*!< UNa ID que indica el ESPACIO donde se encuentra el JUGADOR*/
	int maxObjetos;/*!< UN número que indica el maximo de OBJETOS que caben en el INVENTARIO*/
	INVENTARIO *inv;/*!< Un INVENTARIO donde se almacenan los OBJETO's del JUGADOR*/
} JUGADOR;

/**
 * Información de la estructura:
 * 
 *	- id es el identificador del JUGADOR
 *	- nombre es una cadena que contiene el nombre de un personaje
 *	- localización es un id que permite saber en que JUGADOR se encuantra el personaje
 *	- maxJugadors es el límite de jugadors que puede llevar el personaje en cuestión
 *	- inv es el INVENTARIO que lleva encima el personaje
 * 
 */ 

/**
 * @brief Creación de JUGADOR
 * creaJUGADOR() se encarga de reservar la memoria para un nuevo JUGADOR
 * @param j es un puntero a un puntero a JUGADOR, que será donde se guarde la dirección de el JUGADOR que se reserve
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS creaJugador(JUGADOR **j);

/**
 * @brief Destrucción de JUGADOR
 * destruyeJUGADOR() se encarga de liberar toda la memoria que hubiese resrvado un JUGADOR en caso de estar reservada
 * @param j es un puntero al puntero del JUGADOR que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jiménez Pastor*/
STATUS destruyeJugador(JUGADOR **j);

/**
 * @brief Cambiar ID
 * cambiaIdJug() permite cambiar la ID con que se etiqueta un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaIdJug(JUGADOR *j, ID id);

/**
 * @brief Cambiar Descripcion
 * cambiaNombreJug() permite cambiar el nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param nombre es una cadena con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaNombreJug(JUGADOR *j, char *nombre);

/**
 * @brief Cambiar ID
 * cambiaLocalizacionJug() permite cambiar la ID del espacio en la que se encuentra un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaLocalizacionJug(JUGADOR *j, ID id);

/**
 * @brief Cambiar ID
 * cambiaMaxObjetos() permite cambiar el máximo de objetos que puede tener un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param num es un numero con el que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaMaxObjetos(JUGADOR *j, int num);

/**
 * @brief ¿Está destruido?
 * isJugDestruido() permite saber si un JUGADOR está destruido o no
 * @param o es un puntero al JUGADOR a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isJugDestruido(JUGADOR *o);

/**
 * @brief ¿Está vacio?
 * isJugEmpty() permite saber si un JUGADOR está rellenado o no
 * @param o es un puntero al JUGADOR a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isJugEmpty(JUGADOR *o);

/**
 * @brief Saber ID
 * saberIdJug() permite saber la ID de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberIdJug(JUGADOR *j, ID *id);

/**
 * @brief Descripción de un JUGADOR
 * saberNombreJug() permite saber el contenido del nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param nombre es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberNombreJug(JUGADOR *j, char *nombre);

/**
 * @brief Saber ID
 * saberLugarJug() permite saber la ID del espacio donde se encuentra el JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberLugarJug(JUGADOR *j, ID *id);

/**
 * @brief Tamaño de Descripcion
 * saberMaxObjetos() permite saber el numero máximo de objetos de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberMaxObjetos(JUGADOR *j, int *num);

/**
 * @brief Tamaño de Descripcion
 * saberTamJugNombre() permite saber el tamaño de la cadena que contiene el nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberTamJugNombre(JUGADOR *j, int *num);

	/*Funciones de manejo de INVENTARIO*/

/**
 * @brief Tamaño del inventario
 * tamInventario() permite saber cuantos objeto se encuentran en el JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS tamInventario(JUGADOR *j, int *num);

/**
 * @brief Objeto contenido
 * isObjInInv() permite saber si un objeto se encuentra en el inventario de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es una ID del objeto que se quiere saber si está o no en el JUGADOR
 * @return TRUE o FALSE según el caso
 * @author Antonio Jiménez Pastor*/
BOOL isObjInInv(JUGADOR *j, ID id);


/**
 * @brief Saber un Objeto
 * objetoIesimoInv() permite saber el iésimo objeto del inventario del JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param i es la posición que se desea conocer
 * @return devuelve la ID del objeto que se encuentre en dicha posición
 * @author Antonio Jiménez Pastor*/
ID objetoIesimoInv(JUGADOR *j, int i);


/**
 * @brief Introducir objetos
 * meterObjInInv() introduce un objeto en el inventario de un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID del objeto que se desea guardar
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS meterObjInInv(JUGADOR *j, ID id);

/**
 * @brief Sacar objetos
 * sacarObjInInv() extrae de un inventario de un JUGADOR un objeto
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID del objeto que se desea extraer
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS sacarObjInInv(JUGADOR *j, ID id);

#endif


