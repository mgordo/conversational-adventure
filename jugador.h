/**
 * @file jugador.h
 * Fichero que contiene los prototipos y las estructuras de un JUGADOR
 * @author Antonio Jimenez
 * @version 0.0
 * 
 *Informaci�n �til:
 * 
 *	- Este m�dulo depende del m�dulo CONJUNTO, por lo que se incluir� el .h correspondiente
*/

#include <string.h>
#include "inventario.h"

#ifndef _JUGADOR_H
#define _JUGADOR_H

/** @brief Definici�n de la estructura JUGADOR*/
typedef struct {
	ID id; /*!< Una ID que identifica al JUGADOR*/
	char *nombre;/*!< UNa cadena con el nombre del JUGADOR*/
	ID localizacion;/*!< UNa ID que indica el ESPACIO donde se encuentra el JUGADOR*/
	int maxObjetos;/*!< UN n�mero que indica el maximo de OBJETOS que caben en el INVENTARIO*/
	INVENTARIO *inv;/*!< Un INVENTARIO donde se almacenan los OBJETO's del JUGADOR*/
} JUGADOR;

/**
 * Informaci�n de la estructura:
 * 
 *	- id es el identificador del JUGADOR
 *	- nombre es una cadena que contiene el nombre de un personaje
 *	- localizaci�n es un id que permite saber en que JUGADOR se encuantra el personaje
 *	- maxJugadors es el l�mite de jugadors que puede llevar el personaje en cuesti�n
 *	- inv es el INVENTARIO que lleva encima el personaje
 * 
 */ 

/**
 * @brief Creaci�n de JUGADOR
 * creaJUGADOR() se encarga de reservar la memoria para un nuevo JUGADOR
 * @param j es un puntero a un puntero a JUGADOR, que ser� donde se guarde la direcci�n de el JUGADOR que se reserve
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS creaJugador(JUGADOR **j);

/**
 * @brief Destrucci�n de JUGADOR
 * destruyeJUGADOR() se encarga de liberar toda la memoria que hubiese resrvado un JUGADOR en caso de estar reservada
 * @param j es un puntero al puntero del JUGADOR que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jim�nez Pastor*/
STATUS destruyeJugador(JUGADOR **j);

/**
 * @brief Cambiar ID
 * cambiaIdJug() permite cambiar la ID con que se etiqueta un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaIdJug(JUGADOR *j, ID id);

/**
 * @brief Cambiar Descripcion
 * cambiaNombreJug() permite cambiar el nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param nombre es una cadena con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaNombreJug(JUGADOR *j, char *nombre);

/**
 * @brief Cambiar ID
 * cambiaLocalizacionJug() permite cambiar la ID del espacio en la que se encuentra un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID con la que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaLocalizacionJug(JUGADOR *j, ID id);

/**
 * @brief Cambiar ID
 * cambiaMaxObjetos() permite cambiar el m�ximo de objetos que puede tener un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param num es un numero con el que se desea modificar el JUGADOR
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaMaxObjetos(JUGADOR *j, int num);

/**
 * @brief �Est� destruido?
 * isJugDestruido() permite saber si un JUGADOR est� destruido o no
 * @param o es un puntero al JUGADOR a verificar
 * @return TRUE o FALSE seg�n sea el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isJugDestruido(JUGADOR *o);

/**
 * @brief �Est� vacio?
 * isJugEmpty() permite saber si un JUGADOR est� rellenado o no
 * @param o es un puntero al JUGADOR a verificar
 * @return TRUE o FALSE seg�n sea el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isJugEmpty(JUGADOR *o);

/**
 * @brief Saber ID
 * saberIdJug() permite saber la ID de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberIdJug(JUGADOR *j, ID *id);

/**
 * @brief Descripci�n de un JUGADOR
 * saberNombreJug() permite saber el contenido del nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param nombre es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberNombreJug(JUGADOR *j, char *nombre);

/**
 * @brief Saber ID
 * saberLugarJug() permite saber la ID del espacio donde se encuentra el JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberLugarJug(JUGADOR *j, ID *id);

/**
 * @brief Tama�o de Descripcion
 * saberMaxObjetos() permite saber el numero m�ximo de objetos de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberMaxObjetos(JUGADOR *j, int *num);

/**
 * @brief Tama�o de Descripcion
 * saberTamJugNombre() permite saber el tama�o de la cadena que contiene el nombre de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberTamJugNombre(JUGADOR *j, int *num);

	/*Funciones de manejo de INVENTARIO*/

/**
 * @brief Tama�o del inventario
 * tamInventario() permite saber cuantos objeto se encuentran en el JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS tamInventario(JUGADOR *j, int *num);

/**
 * @brief Objeto contenido
 * isObjInInv() permite saber si un objeto se encuentra en el inventario de un JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param id es una ID del objeto que se quiere saber si est� o no en el JUGADOR
 * @return TRUE o FALSE seg�n el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isObjInInv(JUGADOR *j, ID id);


/**
 * @brief Saber un Objeto
 * objetoIesimoInv() permite saber el i�simo objeto del inventario del JUGADOR
 * @param j es un puntero al JUGADOR a verificar
 * @param i es la posici�n que se desea conocer
 * @return devuelve la ID del objeto que se encuentre en dicha posici�n
 * @author Antonio Jim�nez Pastor*/
ID objetoIesimoInv(JUGADOR *j, int i);


/**
 * @brief Introducir objetos
 * meterObjInInv() introduce un objeto en el inventario de un JUGADOR
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID del objeto que se desea guardar
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS meterObjInInv(JUGADOR *j, ID id);

/**
 * @brief Sacar objetos
 * sacarObjInInv() extrae de un inventario de un JUGADOR un objeto
 * @param j es un puntero al JUGADOR a modificar
 * @param id es una ID del objeto que se desea extraer
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS sacarObjInInv(JUGADOR *j, ID id);

#endif


