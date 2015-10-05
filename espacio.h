/**
 * @file espacio.h
 * Fichero que contiene los prototipos y las estructuras de un ESPACIO
 * @author Antonio Jimenez y Miguel Gordo
 * @version 1.0
 * 
 * Informaci�n �til:
 * 
 *	- Este m�dulo depende del m�dulo CONJUNTO, por lo que se incluir� el .h correspondiente
 */


#include <string.h>
#include "inventario.h"
#ifndef _ESPACIO_H
#define _ESPACIO_H

/** @brief Definici�n de la estructura ESPACIO*/
typedef struct {
	ID id;	/*!< ID del espacio*/
	char *descripcion; /*!< Cadena que contiene la descripci�n que se da al estar en un espacio*/
	char *descExaminar; /*!< Cadena que contiene la descripci�n que se da al examinar el espacio*/
	char **descGrafica; /*!< Descripcion gr�fica*/
	int filas; /*!< Filas de la descripcion gr�fica*/
	int columnas; /*!< Columnas de la descripcion gr�fica*/
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
 * Informaci�n de la estructura:
 * 
 *	- id es el identificador del espacio
 *	- descripcion es un puntero a una cadena que almacenar� la descripci�n b�sica del espacio
 *	- descExaminar es un puntero a una cadena que almacenar� una descripci�n exaustiva del objeto
 *	- inv ser� el inventario del espacio, que almacenar� los objeto que haya en dicho espacio
 *	- luminoso es un atributo que indica si un espacio est� iluminado o no
 *	- norte, sur, este, oeste, arriba, abajao son los id de las uniones que haya en esa direcci�n
 */

/**
 * @brief Creaci�n de Espacio
 * creaEspacio() se encarga de reservar la memoria para un nuevo Espacio
 * @param e es un puntero a un puntero a ESPACIO, que ser� donde se guarde la direcci�n de el ESPACIO que se reserve
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS creaEspacio(ESPACIO **e);

/**
 * @brief Destrucci�n de Espacio
 * destruyeEspacio() se encarga de liberar toda la memoria que hubiese resrvado un Espacio en caso de estar reservada
 * @param e es un puntero al puntero del Espacio que se desea destruir
 * @return Siempre devuelve OK. No hay posibilidad de error
 * @author Antonio Jim�nez Pastor*/
STATUS destruyeEspacio(ESPACIO **e);

/**
 * @brief Cambiar ID
 * cambiaEspId() permite cambiar la ID con que se etiqueta un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspId(ESPACIO *e, ID id);

/**
 * @brief Cambiar Grafica
 * cambiaEspDescGrafica() permite cambiar la descripci�n gr�fica de un espacio
 * @param e es puntero al espacio en el que guardar la desscripci�n gr�fica
 * @param dibujo es puntero de char con la descripci�n gr�fica a guardar
 * @param filas es entero con el n�mero de filas de la descripci�n gr�fica
 * @param columnas es entero con el n�mero de columnas de la descripci�n gr�fica
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo*/
STATUS cambiaEspDescGrafica(ESPACIO *e,char *dibujo,int filas,int columnas);

/**
 * @brief Cambiar Descripcion
 * cambiaEspDescripcion() permite cambiar la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param desc es una cadena con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspDescripcion(ESPACIO *e, char *desc);

/**
 * @brief Cambiar Examinar
 * cambiaEspDescExaminar() permite modificar la descripcion examinar de un ESPACIo
 * @param e es un puntero al ESPACIO a modificar
 * @param desc es una cadena con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspDescExaminar(ESPACIO *e, char *desc);

/**
 * @brief Cambiar Luminoso
 * cambiaEspLuminoso() permite modificar el estado del espacio entre luminoso y no luminoso
 * @param e es un puntero al ESPACIO a modificar
 * @param luz es un BOOL con el que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspLuminoso(ESPACIO *e, BOOL luz);

/**
 * @brief Cambiar Norte
 * cambiaEspNorte() permite cambiar la ID de la UNION que se encuentra al norte del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspNorte(ESPACIO *e, ID n);

/**
 * @brief Cambiar Sur
 * cambiaEspSur() permite cambiar la ID de la UNION que se encuentra al sur del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspSur(ESPACIO *e, ID n);

/**
 * @brief Cambiar Este
 * cambiaEspEste() permite cambiar la ID de la UNION que se encuentra al este del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspEste(ESPACIO *e, ID n);

/**
 * @brief Cambiar Oeste
 * cambiaEspOeste() permite cambiar la ID de la UNION que se encuentra al oeste del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspOeste(ESPACIO *e, ID n);

/**
 * @brief Cambiar Arriba
 * cambiaEspArriba() permite cambiar la ID de la UNION que se encuentra arriba del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspArriba(ESPACIO *e, ID n);

/**
 * @brief Cambiar Abajo
 * cambiaEspAbajo() permite cambiar la ID de la UNION que se encuentra abajo del ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param n es una ID con la que se desea modificar el ESPACIO
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS cambiaEspAbajo(ESPACIO *e, ID n);

/**
 * @brief �Est� destruida?
 * isEspDestruido() permite saber si un ESPACIO est� destruido o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE seg�n sea el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isEspDestruido(ESPACIO *e);

/**
 * @brief �Est� vacio?
 * isEspEmpty() permite saber si un ESPACIO ha sido rellenado o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE seg�n sea el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isEspEmpty(ESPACIO *e);

/**
 * @brief �Est� iluminado?
 * isEspLuminoso() permite saber si un ESPACIO tiene luz propia o no
 * @param e es un puntero al ESPACIO a verificar
 * @return TRUE o FALSE seg�n sea el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isEspLuminoso(ESPACIO *e);

/**
 * @brief Saber ID
 * saberEspid() permite saber la ID de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspId(ESPACIO *e, ID *id);

/**
 * @brief Descripci�n de un ESPACIO
 * saberEspDescripcion() permite saber el contenido de la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param desc es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspDescripcion(ESPACIO *e, char *desc);

/**
 * @brief saberEspDescrGrafica
 * Esta funci�n permite saber la descripci�n Gr�fica de un espacio a examinar
 * @param dibujo es puntero a matriz que contendr� el espacio
 * @param filas es puntero a int que contendr� el n�mero de filas de la descripci�n gr�fica
 * @param esp es puntero al ESPACIO del que conocer la descripci�n gr�fica
 * @param columnas es puntero a int que contendr� el n�mero de columnas de la descripci�n gr�fica
 * @return ERR si no se idevolvi� correctamente o OK en caso contrario
 * @author Miguel Gordo*/
STATUS saberEspDescrGrafica(ESPACIO *esp,char ***dibujo,int *filas, int *columnas);

/**
 * @brief Examinar un espacio
 * saberEspDescExaminar() permite saber el contenido de la descripcion examinar de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param desc es un puntero a una cadena donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspDescExaminar(ESPACIO *e, char *desc);

/**
 * @brief Tama�o de Descripcion
 * saberEspTamDesc() permite saber el tama�o de la cadena que contiene la descripcion de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspTamDesc(ESPACIO *e, int *num);

/**
 * @brief Tama�o de Examinar
 * saberEspTamDescExam() permite saber el tama�o de la cadena que contiene la descripci�n examinar del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspTamDescExam(ESPACIO *e, int *num);

/**
 * @brief Saber Norte
 * saberEspNorte() permite saber la ID de el ESPACIO que se encuentra al norte del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspNorte(ESPACIO *e, ID *id);

/**
 * @brief Saber Sur
 * saberEspSur() permite saber la ID de el ESPACIO que se encuentra al sur del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspSur(ESPACIO *e, ID *id);

/**
 * @brief Saber Este
 * saberEspEste() permite saber la ID de el ESPACIO que se encuentra al este del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspEste(ESPACIO *e, ID *id);

/**
 * @brief Saber Oeste
 * saberEspOeste() permite saber la ID de el ESPACIO que se encuentra al oeste del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspOeste(ESPACIO *e, ID *id);

/**
 * @brief Saber Arriba
 * saberEspArriba() permite saber la ID de el ESPACIO que se encuentra arriba del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspArriba(ESPACIO *e, ID *id);

/**
 * @brief Saber Abajo
 * saberEspAbajo() permite saber la ID de el ESPACIO que se encuentra abajo del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es un puntero a una ID donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspAbajo(ESPACIO *e, ID *id);

	/*Funciones de manejo del inventario*/

/**
 * @brief Sacar objetos
 * sacarEspObj() extrae de un inventario de un ESPACIO un objeto
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID del objeto que se desea extraer
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS sacarEspObj(ESPACIO *e, ID id);

/**
 * @brief Introducir objetos
 * meterEspObj() introduce un objeto en el inventario de un ESPACIO
 * @param e es un puntero al ESPACIO a modificar
 * @param id es una ID del objeto que se desea guardar
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS meterEspObj(ESPACIO *e, ID id);

/**
 * @brief Tama�o del inventario
 * saberEspTamInv() permite saber cuantos objeto se encuentran en el ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param num es un puntero a un entero donde guardar el dato
 * @return puede devolver ERR u OK seg�n se realice la operaci�n mal o bien respectivamente
 * @author Antonio Jim�nez Pastor*/
STATUS saberEspTamInv(ESPACIO *e, int *num);

/**
 * @brief Objeto contenido
 * isObjinEsp() permite saber si un objeto se encuentra en el inventario de un ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param id es una ID del objeto que se quiere saber si est� o no en el ESPACIO
 * @return TRUE o FALSE seg�n el caso
 * @author Antonio Jim�nez Pastor*/
BOOL isObjinEsp(ESPACIO *e, ID id);

/**
 * @brief Saber un Objeto
 * saberEspIesimoObj() permite saber el i�simo objeto del inventario del ESPACIO
 * @param e es un puntero al ESPACIO a verificar
 * @param i es la posici�n que se desea conocer
 * @return devuelve la ID del objeto que se encuentre en dicha posici�n
 * @author Antonio Jim�nez Pastor*/
ID saberEspIesimoObj(ESPACIO *e, int i);

#endif


