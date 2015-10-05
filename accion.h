/**
 * @brief Utilidades para las acciones de un personaje
 *
 * Este modulo contiene los prototipos de las funciones para ejecutar las acciones de un personaje
 *
 * @file accion.h
 * @author Carlos Carrascal
 * @version 1.0
 * @date 01-11-2010
 */



#ifndef _ACCION_H
#define _ACCION_H


#include "mundo.h"
#include "reglas.h"
#include "lectorxml.h"
#include "lector_reglas.h"

/**
 * @brief Lista de acciones disponibles
/**/
typedef enum
{
	IR,
	COGER,
	DEJAR,
	ENCIENDE,
	APAGA,
	METER,
	SACAR,
	EXAMINAR_OBJ,
	EXAMINAR_ESP,
	EXAMINAR_INV,
	ABRIR,
	FIN,
	DAR,
	PEDIR,
	DECIR,
	NADA=-1
} TIPOACCION;


/**
 * @brief Estructura básica para ejecutar una accion
 *
 * Esta estructura contiene toda la información necesaria para poder ejecutar cualquier accion de un personaje
 */
typedef struct
{
	TIPOACCION id;  /*!< Tipo de accion a realizar */
	char * objetoD;  /*!< Puntero al nombre de un objeto directo*/ 
	char * objetoI;  /*!< Puntero al nombre de un objeto indirecto*/ 
	char * jugadorD;  /*!< Puntero al nombre del jugador que realiza la accion principal*/
	char * jugadorI;  /*!< Puntero al nombre del jugador que realiza la accion secundaria*/
	DIRECCION dir;  /*!< Direccion del movimiento (ya sea abrir o moverse) */
	REGLAS *reglas;  /*!< Reglas para el juego */
	MUNDO *m;  /*!< Mundo de juego */
} ACCION;



/**
 * @brief reserva una accion
 *
 * creaAccion() reserva memoria para una estructura accion
 *
 * @param fichMundo es el nombre del fichero del cual leer mundo 
 * @param fichReglas es el nombre del fichero del cual leer las reglas 
 *
 * @return un puntero a la reserva, o NULL si falló
 */
ACCION * creaAccion(char *fichMundo, char * fichReglas);


/**
 * @brief elimina una accion
 *
 * destruyeAccion() libera la memoria
 *
 * @param acc es un puntero a la estructura accion
 *
 * @return no puede llegar a fallar, devuelve OK
 */
STATUS destruyeAccion(ACCION **acc);


/**
 * @brief devuelve el mundo de accion
 *
 * saberMundoAccion() permite acceder al mundo de una accion
 *
 * @param a es un puntero a la estructura accion
 * 
 * @return el puntero al MUNDO que corresponda
 */
MUNDO * saberMundoAccion(ACCION *a);


/**
 * @brief modifica el tipo de accion
 *
 * cambiaIdAccion() pone un TIPOACCION a una accion concreta
 *
 * @param accion es un puntero a la estructura accion
 * @param tipo es un TIPOACCION a guardar
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaIdAccion(ACCION * accion, TIPOACCION tipo);


/**
 * @brief proporciona informacion sobre accion
 *
 * saberTipoAccion() permite acceder al campo id de una accion
 *
 * @param a es un puntero a la estructura accion
 * 
 * @return el TIPOACCION que corresponda
 */
TIPOACCION saberTipoAccion(ACCION *a);


/**
 * @brief modifica el objeto directo
 *
 * cambiaDAccion() guarda una cadena en objeto directo
 *
 * @param accion es un puntero a la estructura accion
 * @param cadena es la cadena a guardar
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaDAccion(ACCION * accion, char * cadena);


/**
 * @brief proporciona informacion sobre accion
 *
 * saberDAccion() permite acceder al campo objeto directo de una accion
 *
 * @param a es un puntero a la estructura accion
 * 
 * @return el puntero a char que corresponda
 */
char * saberDAccion(ACCION *a);


/**
 * @brief modifica el objeto indirecto
 *
 * cambiaIAccion() guarda una cadena en objeto indirecto
 *
 * @param accion es un puntero a la estructura accion
 * @param cadena es la cadena a guardar
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaIAccion(ACCION * accion, char * cadena);


/**
 * @brief modifica el jugador directo
 *
 * cambiaJugDAccion() guarda una cadena en el jugador
 *
 * @param accion es un puntero a la estructura accion
 * @param cadena es la cadena a guardar
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaJugDAccion(ACCION * accion, char * cadena);


/**
 * @brief modifica el jugador indirecto
 *
 * cambiaJugIAccion() guarda una cadena en el jugador
 *
 * @param accion es un puntero a la estructura accion
 * @param cadena es la cadena a guardar
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaJugIAccion(ACCION * accion, char * cadena);


/**
 * @brief proporciona informacion sobre accion
 *
 * saberJugIAccion() permite acceder al jugador indirecto de una accion
 *
 * @param a es un puntero a la estructura accion
 * 
 * @return el puntero a char que corresponda
 */
char * saberJugIAccion(ACCION *a);


/**
 * @brief modifica la direccion de un movimiento
 *
 * cambiaDirAccion() pone una direccion en dir
 *
 * @param accion es un puntero a la estructura accion
 * @param dir es una direccion
 *
 * @return OK si fue correcto, ERR si falló
 */
STATUS cambiaDirAccion(ACCION * accion, DIRECCION dir);


/**
 * @brief ejecuta cualquier acción excepto examinar
 *
 * ejecutaAccion() escoge entre las diferentes acciones posibles definidas en TipoAccion
 *
 * @param a es un puntero a una estructura accion auxiliar que contiene toda la informacion necesaria
 * @param info es una cadena con los nombres de los jugadores o el examinado de espacios o objetos, segun convenga
 * @param fin indica el estado del juego
 * 
 * @return ERR si ha fallado, OK si se ejecuta correctamente
 */
STATUS ejecutaAccion(ACCION *a, char *info, GAMES * fin);


#endif

