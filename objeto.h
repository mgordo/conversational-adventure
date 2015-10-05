/**
 * @file objeto.h
 * Fichero que contiene los prototipos y las estructuras de un OBJETO
 * @author Antonio Jimenez
 * @version 1.0
 * 

 *Información útil:
 * 
 *	- Este módulo depende del módulo INVENTARIO, por lo que se incluirá el .h correspondiente
 * 
 * */
#include <string.h>
#include "inventario.h"

#ifndef _OBJETO_H
#define _OBJETO_H

/** @brief Definición de la estructura OBJETO*/
typedef struct {
	ID id; /*!< Una ID que caracteriza al OBJETO*/
	char *nombre;/*!< Una cadena con el nombre del OBJETO*/
	char *descripcion;/*!< Una cadena con la descripcion del OBJETO*/
	char *descMovido;/*!< Una cadena con la descripcion del OBJETO al moverlo*/
	char *descExaminar;/*!< Una cadena con la descripcion del OBJETO al examinarlo*/
	BOOL movil;/*!< Un booleano que indica si el OBJETO se puede mover*/
	BOOL movido;/*!< Un booleano que indica si el OBJETO se ha movido*/
	BOOL oculto;/*!< Un booleano que indica si el OBJETO está oculto*/
	BOOL encendido;/*!< Un booleano que indica si el OBJETO está encendido*/
	BOOL luz;/*!< Un booleano que indica si el OBJETO se puede encender*/
	BOOL contenedor;/*!< Un booleano que indica si el OBJETO es contenedor o no*/
	INVENTARIO *inv;/*!< INVENTARIO donde se guardan las ID's de los objetos que estén dentro del OBJETO*/
} OBJETO;

/**
 *Información de la estructura:
 * 
 *	- id es el identificador del objeto en cuestión
 *	- localización es el id que señala en que OBJETO se encuentra el objeto
 *	- nombre es una cadena con el nombre del objeto
 *	- descripcion es una cadena que contiene la descripción del objeto a simple vista
 *	- descMovido es una cadena que contiene la descripción del objeto una vez movido
 *	- descExaminar es una cadena que contiene la descripción del objeto al usar el comando examinar sobre él
 *	- movil es un dato de tipo booleano que indica si el objeto se puede mover o no
 *	- movido es un dato de tipo booleano que indica si el objeto ha sido movido o no
 *	- oculto es un dato de tipo booleano que indica si el objeto se ve o no
 **/ 

/**
 * @brief Creación de OBJETO
 * creaOBJETO() se encarga de reservar la memoria para un nuevo OBJETO
 * @param o es un puntero a un puntero a OBJETO, que será donde se guarde la dirección de el OBJETO que se reserve
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS creaObjeto(OBJETO **o);

/**
 * @brief Destrucción de OBJETO
 * destruyeOBJETO() se encarga de liberar toda la memoria que hubiese resrvado un OBJETO en caso de estar reservada
 * @param o es un puntero al puntero del OBJETO que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jiménez Pastor*/
STATUS destruyeObjeto(OBJETO **o);

/**
 * @brief Cambiar ID
 * cambiaIdObj() permite cambiar la ID con que se etiqueta un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param id es una ID con la que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaIdObj(OBJETO *o, ID id);

/**
 * @brief Cambiar Descripcion
 * cambiaNombreObj() permite cambiar el nombre de un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param nombre es una cadena con la que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaNombreObj(OBJETO *o, char *nombre);

/**
 * @brief Cambiar Descripcion
 * cambiaDescripcionObj() permite cambiar la descripcion de un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param descr es una cadena con la que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaDescripcionObj(OBJETO *o, char *descr);

/**
 * @brief Cambiar Descripcion
 * cambiaDescrMovido() permite cambiar la descripcion movido de un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param descr es una cadena con la que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaDescrMovido(OBJETO *o, char *descr);

/**
 * @brief Cambiar Descripcion
 * cambiaDescrExamObj() permite cambiar la descripcion examinar de un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param descr es una cadena con la que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaDescrExamObj(OBJETO *o, char *descr);

/**
 * @brief Cambiar Luminoso
 * cambiaOculto() permite modificar el estado del OBJETO entre oculto y no oculto
 * @param o es un puntero al OBJETO a modificar
 * @param oculto es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaOculto(OBJETO *o, BOOL oculto);


/**
 * @brief Cambiar Luminoso
 * cambiaMovil() permite modificar el estado del OBJETO entre movible y no movible
 * @param o es un puntero al OBJETO a modificar
 * @param movil es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaMovil(OBJETO *o, BOOL movil);

/**
 * @brief Cambiar Luminoso
 * cambiaMovido() permite modificar el estado del OBJETO entre movido y no movido
 * @param o es un puntero al OBJETO a modificar
 * @param movido es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaMovido(OBJETO *o, BOOL movido);

/**
 * @brief Cambiar Luminoso
 * cambiaEncendido() permite modificar el estado del OBJETO entre encendido o apagado
 * @param o es un puntero al OBJETO a modificar
 * @param encendido es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaEncendido(OBJETO *o, BOOL encendido);

/**
 * @brief Cambiar Luminoso
 * cambiaLuz() permite modificar el estado del OBJETO entre luminoso y no luminoso
 * @param o es un puntero al OBJETO a modificar
 * @param luz es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaLuz(OBJETO *o, BOOL luz);

/**
 * @brief Cambiar Luminoso
 * cambiaContenedor() permite modificar el estado del OBJETO entre contenedor y no contenedor
 * @param o es un puntero al OBJETO a modificar
 * @param contenedor es un BOOL con el que se desea modificar el OBJETO
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS cambiaContenedor(OBJETO *o, BOOL contenedor);

/**
 * @brief ¿Es movil?
 * isMovil() permite saber si un OBJETO se puede mover o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isMovil(OBJETO *o);

/**
 * @brief ¿Está movido?
 * isMovido() permite saber si un OBJETO se ha movido o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isMovido(OBJETO *o);

/**
 * @brief ¿Está oculto?
 * isOculto() permite saber si un OBJETO está oculto o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isOculto(OBJETO *o);

/**
 * @brief ¿Está iluminado?
 * isEncendido() permite saber si un OBJETO está encendido o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isEncendido(OBJETO *o);

/**
 * @brief ¿Es luminoso?
 * isLuz() permite saber si un OBJETO tiene luz propia o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isLuz(OBJETO *o);

/**
 * @brief ¿Es contenedor?
 * isContenedor() permite saber si un OBJETO puede contener otros objetos o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isContenedor(OBJETO *o);

/**
 * @brief ¿Está destruido?
 * isObjDestruido() permite saber si un OBJETO está destruido o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isObjDestruido(OBJETO *o);

/**
 * @brief ¿Está vacio?
 * isObjEmpty() permite saber si un OBJETO está relleno o no
 * @param o es un puntero al OBJETO a verificar
 * @return TRUE o FALSE según sea el caso
 * @author Antonio Jiménez Pastor*/
BOOL isObjEmpty(OBJETO *o);

/**
 * @brief Descripción de un OBJETO
 * saberNombreObj() permite saber el contenido del nombre de un OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param nombre es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberNombreObj(OBJETO *o, char *nombre);

/**
 * @brief Tamaño de Examinar
 * saberTamNombreObj() permite saber el tamaño de la cadena que contiene el nombre del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberTamNombreObj(OBJETO *o, int *num);

/**
 * @brief Descripción de un OBJETO
 * saberDescrObj() permite saber el contenido de la descripcion de un OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param descr es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberDescrObj(OBJETO *o, char *descr);

/**
 * @brief Tamaño de Examinar
 * saberTamDescrObj() permite saber el tamaño de la cadena que contiene la descripción del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberTamDescrObj(OBJETO *o, int *num);

/**
 * @brief Descripción de un OBJETO
 * saberDescrMovido() permite saber el contenido de la descripcion movido de un OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param descr es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberDescrMovido(OBJETO *o, char *descr);

/**
 * @brief Tamaño de Examinar
 * saberTamDescrMovido() permite saber el tamaño de la cadena que contiene la descripción movido del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberTamDescrMovido(OBJETO *o, int *num);

/**
 * @brief Descripción de un OBJETO
 * saberDescrExamObj() permite saber el contenido de la descripcion examinar de un OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param descr es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberDescrExamObj(OBJETO *o, char *descr);

/**
 * @brief Tamaño de Examinar
 * saberTamDescExamObj() permite saber el tamaño de la cadena que contiene la descripción examinar del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberTamDescrExamObj(OBJETO *o, int *num);

/**
 * @brief Saber Norte
 * saberIdObj() permite saber la ID del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberIdObj(OBJETO *o, ID *id);

	/*Funciones de manejo del inventario*/

/**
 * @brief Sacar objetos
 * sacarObjObj() extrae de un inventario de un OBJETO un objeto
 * @param o es un puntero al OBJETO a modificar
 * @param id es una ID del objeto que se desea extraer
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS sacarObjObj(OBJETO *o, ID id);

/**
 * @brief Introducir objetos
 * meterObjObj() introduce un objeto en el inventario de un OBJETO
 * @param o es un puntero al OBJETO a modificar
 * @param id es una ID del objeto que se desea guardar
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS meterObjObj(OBJETO *o, ID id);

/**
 * @brief Tamaño del inventario
 * saberObjTamInv() permite saber cuantos objeto se encuentran en el OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK según se realice la operación mal o bien respectivamente
 * @author Antonio Jiménez Pastor*/
STATUS saberObjTamInv(OBJETO *o, int *num);

/**
 * @brief Objeto contenido
 * isObjinObj() permite saber si un objeto se encuentra en el inventario de un OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param id es una ID del objeto que se quiere saber si está o no en el OBJETO
 * @return TRUE o FALSE según el caso
 * @author Antonio Jiménez Pastor*/
BOOL isObjinObj(OBJETO *o, ID id);

/**
 * @brief Saber un Objeto
 * saberObjIesimoObj() permite saber el iésimo objeto del inventario del OBJETO
 * @param o es un puntero al OBJETO a verificar
 * @param i es la posición que se desea conocer
 * @return devuelve la ID del objeto que se encuentre en dicha posición
 * @author Antonio Jiménez Pastor*/
ID saberObjIesimoObj(OBJETO *o, int i);


#endif


