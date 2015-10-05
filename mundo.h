/**
 * @brief Utilidades para crear y modificar el mundo
 *
 * Este modulo contiene los prototipos de las funciones para todas las acciones posibles respecto al mundo
 *
 * @file mundo.h
 * @author Carlos Carrascal, Antonio Jiménez y Miguel Gordo
 * @version 1.0
 * @date 02-11-2010
*/


#include "jugador.h"
#include "espacio.h"
#include "objeto.h"
#include "union.h"

#ifndef _MUNDO_H
#define _MUNDO_H

/**
 * @brief Estructura básica de un mundo
 *
 * Esta estructura contiene todos los espacios, jugadores y objetos de un mundo
 */
typedef struct
{
	ESPACIO ** espacios; /*!< Puntero a un array de punteros a ESPACIO's*/
	OBJETO ** objetos;/*!< Puntero a un array de punteros a OBJETO's*/
	JUGADOR ** jugador;/*!< Puntero a un array de punteros a JUGADOR'es*/
	UNION ** uniones;/*!< Puntero a un array de punteros a UNION'es*/
	int numesp;/*!< Numero que indica la cantidad de ESPACIO's del MUNDO*/
	int numobj;/*!< Numero que indica la cantidad de OBJETO's del MUNDO*/
	int numjug;/*!< Numero que indica la cantidad de JUGADOR'es del MUNDO*/
	int numuni;/*!< Numero que indica la cantidad de UNION'es del MUNDO*/
} MUNDO;


/***************************************/
/**Funciones básicas del mundo***********/
/***************************************/

/**
 * @brief crea un mundo
 *
 * nuevoMundo() reserva memoria para un mundo completo
 *
 * @param numesp es el numero de espacios a reservar
 * @param numobj es el numero de objetos a reservar
 * @param numjug es el numero de personajes a reservar
 * @param numuni es el numero de uniones a reservar
 * 
 * @return un puntero al nuevo mundo creado, o NULL si dió error
 */
MUNDO * nuevoMundo(int numesp, int numobj, int numjug, int numuni);

/**
 * @brief Libera un mundo completo
 *
 * destruyeMundo() recorre toda la estructura liberando todos los objetos, espacios y jugadores
 *
 * @param m es un puntero de un puntero al mundo
 *
 * @return no tiene devolucion
*/
void destruyeMundo(MUNDO ** m);

/**
 * @brief informa del numero de jugadores
/**
 * saberNumJug() accede a la estructura y guarda en num lo pedido
/**
 * @param m es un puntero al mundo
 * @param num es un puntero a un entero
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS saberNumJug(MUNDO *m, int *num);

/**
 * @brief informa del numero de objetos
/**
 * saberNumObj() accede a la estructura y guarda en num lo pedido
/**
 * @param m es un puntero al mundo
 * @param num es un puntero a un entero
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS saberNumObj(MUNDO *m, int *num);


/**
 * @brief informa del numero de espacios
/**
 * saberNumEsp() accede a la estructura y guarda en num lo pedido
/**
 * @param m es un puntero al mundo
 * @param num es un puntero a un entero
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS saberNumEsp(MUNDO *m, int *num);


/**
 * @brief informa del numero de uniones
/**
 * saberNumUni() accede a la estructura y guarda en num lo pedido
/**
 * @param m es un puntero al mundo
 * @param num es un puntero a un entero
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS saberNumUni(MUNDO *m, int *num);



/***************************************/
/**Funciones básicas para crear objetos**/
/***************************************/


/**
 * @brief Guarda un objeto en el mundo
/**
 * guardaObj() guarda en la primera posicion libre el elemento recibido  
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS guardaObj(MUNDO *m, OBJETO * objeto);


/**
 * @brief crea un objeto
/**
 * creaObj() reserva la memoria 
/**
 * @param objeto es un puntero a un puntero tipo objeto
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaObj(OBJETO ** objeto);


/**
 * @brief Destruye un objeto
/**
 * destruyeObj() elimina la reserva de memoria 
/**
 * @param objeto es un puntero a un puntero tipo objeto
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS destruyeObj(OBJETO ** objeto);


/**
 * @brief Modifica la id de un objeto
/**
 * creaIdObjMundo() modifica la id de cierto objeto
/**
 * @param objeto es un puntero al objeto
 * @param id es la id a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdObjMundo(OBJETO * objeto, ID id);


/**
 * @brief Modifica el nombre de un objeto
/**
 * creaNombreObj() guarda como nombre la cadena nombre
/**
 * @param objeto es un puntero al objeto
 * @param nombre es un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaNombreObj(OBJETO * objeto, char * nombre);


/**
 * @brief Modifica la descripcion de un objeto
/**
 * creaDescObj() guarda como descripcion la cadena descripcion
/**
 * @param objeto es un puntero al objeto
 * @param descripcion es un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaDescObj(OBJETO * objeto, char *descripcion);


/**
 * @brief Modifica la descripcion de un objeto movido
/**
 * creaDescMovidoObj() guarda como descripcion secundaria a la cadena descMovido
/**
 * @param objeto es un puntero al objeto
 * @param descMovido es un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaDescMovidoObj(OBJETO * objeto, char * descMovido);


/**
 * @brief Modifica el examinado de un objeto
/**
 * creaExamObj() guarda como examinado a la cadena examinar
/**
 * @param objeto es un puntero al objeto
 * @param examinar un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaExamObj(OBJETO * objeto, char * examinar);


/**
 * @brief Establece si un objeto se puede mover o no
/**
 * creaMovilObj() pone en TRUE o FALSE la indicacion movil
/**
 * @param objeto es un puntero al objeto
 * @param movil es un booleano que indica si se mueve o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaMovilObj(OBJETO * objeto, BOOL movil);


/**
 * @brief Establece si un objeto ha sido movido o no
/**
 * creaMovidoObj() pone a TRUE o FALSE la indicacion movido
/**
 * @param objeto es un puntero al objeto
 * @param movido es un booleano que indica si se movio o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaMovidoObj(OBJETO * objeto,BOOL movido);


/**
 * @brief Establece si un objeto esta oculto o no
/**
 * creaOcultoObj() pone a TRUE o FALSE la indicacion oculto
/**
 * @param objeto es un puntero al objeto
 * @param oculto es un booleano que indica si esta oculto o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaOcultoObj(OBJETO * objeto, BOOL oculto);


/**
 * @brief Establece si un objeto esta encendido o no
/**
 * creaEncendidoObj() pone a TRUE o FALSE la indicacion encendido
/**
 * @param objeto es un puntero al objeto
 * @param encendido es un booleano que indica si esta encendido o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaEncendidoObj(OBJETO * objeto, BOOL encendido);


/**
 * @brief Establece si un objeto es contenedor o no
/**
 * creaContenedorObj() pone a TRUE o FALSE la indicacion contenedor
/**
 * @param objeto es un puntero al objeto
 * @param contenedor es un booleano que indica si puede contener o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaContenedorObj(OBJETO * objeto, BOOL contenedor);


/**
 * @brief Establece si un objeto se puede encender o no
/**
 * creaLuzObj() pone a TRUE o FALSE la indicacion luz
/**
 * @param objeto es un puntero al objeto
 * @param luz es un booleano que indica si se puede encender o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaLuzObj(OBJETO * objeto, BOOL luz);


/***************************************/
/**Funciones para objeto*****************/
/***************************************/

/**
 * @brief devuelve el objeto sabiendo la id
/**
 * dameObjeto() devuelve un puntero a un objeto sabiendo la id
/**
 * @param m es un puntero al mundo
 * @param id es el identificador a buscar
 * 
 * @return un puntero al objeto o NULL si falló
/***/
OBJETO * dameObjeto(MUNDO * m, ID id);

/**
 * @brief consigues el objeto sabiendo el nombre
/**
 * consigueObjeto() devuelve un puntero a un objeto cuyo nombre coincide con uno dado
/**
 * @param m es un puntero al mundo
 * @param nombre es un puntero a la cadena donde está el nombre buscado
/**
 * @return un puntero al objeto encontrado o NULL si dió error
/***/
OBJETO * consigueObjeto(MUNDO * m, char * nombre);


/**
 * @brief devuelve el nombre de un objeto
/**
 * darNombreObj() devuelve en una cadena dada el nombre de un objeto teniendo su puntero
/**
 * @param objeto es un puntero al objeto deseado
 * @param nombre es un puntero al array donde guardar dicho nombre
/**
 * @return ERR si se produjo error,OK si se hizo correctamente
/***/
STATUS darNombreObj(OBJETO * objeto, char *nombre);


/**
 * @brief devuelve el espacio donde se encuentra un objeto
/**
 * darLocObj() devuelve la id del espacio donde se encuentra un objeto teniendo el puntero de este
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto deseado
/**
 * @return devuelve la id del espacio buscado
/***/
ID darLocObj(MUNDO *m, OBJETO * objeto);


/**
 * @brief devuelve la descripcion inicial de un objeto
/**
 * dameDescrObj() guarda en una cadena la descripcion de un objeto siempre que no supere el tamaño
/**
 * @param objeto es un puntero al objeto deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS dameDescrObj(OBJETO * objeto, char *descripcion, int max_len);


/**
 * @brief mete un objeto en otro
/**
 * meteObjObj() almacena en el inventario de un objeto a otro objeto
/**
 * @param objeto es un puntero al objeto que guarda
 * @param id es la id del objeto a guardar
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS meterObjObj(OBJETO *objeto, ID id);

/**
 * @brief devuelve la descripcion al examinar un objeto
/**
 * darDescrexamObj() guarda en una cadena la descripcion de un objeto siempre que no supere el tamaño
/**
 * @param o es un puntero al objeto deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrexamObj(OBJETO * o, char *descripcion, int max_len);

/**
 * @brief devuelve la descripcion inicial de un objeto
/**
 * darDescrObj() guarda en una cadena la descripcion de un objeto siempre que no supere el tamaño
/**
 * @param objeto es un puntero al objeto deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrObj(OBJETO * objeto, char *descripcion, int max_len);

/**
 * @brief devuelve la descripcion de un objeto movido
/**
 * darDescrMovidoObj() guarda en una cadena la descripcion de un objeto movido siempre que no supere el tamaño
/**
 * @param objeto es un puntero al objeto deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrMovidoObj(OBJETO * objeto, char *descripcion, int max_len);

/**
 * @brief devuelve la id de un objeto
/**
 * darIdObj() devuelve la id del un objeto teniendo el puntero a este
/**
 * @param o es un puntero al objeto deseado
/**
 * @return devuelve la id del espacio buscado o menor que cero si es error
/***/
ID darIdObj(OBJETO * o);

/**
 * @brief informa si un objeto es movil
/**
 * darMovilObj() accede al campo movil de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darMovilObj(OBJETO * o);

/**
 * @brief informa si un objeto ha sido movido
/**
 * darMovidoObj() accede al campo movido de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darMovidoObj(OBJETO * o);

/**
 * @brief informa si un objeto es oculto
/**
 * darOcultoObj() accede al campo oculto de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darOcultoObj(OBJETO * o);

/**
 * @brief informa si un objeto esta encendido
/**
 * darEncendidoObj() accede al campo encendido de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darEncendidoObj(OBJETO * o);

/**
 * @brief informa si un objeto se puede encender
/**
 * darLuzObj() accede al campo luz de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darLuzObj(OBJETO * o);

/**
 * @brief informa si un objeto es contenedor
/**
 * darContenedorObj() accede al campo contenedor de un objeto
/**
 * @param o es un puntero al objeto deseado
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL darContenedorObj(OBJETO * o);

/**
 * @brief informa si un objeto esta en otro objetor
/**
 * isObjInObjMun() informa si un objeto, dada su id, esta dentro de un objeto del cual tenemos su puntero
/**
 * @param o es un puntero al objeto contenedor
 * @param id es la id del objeto contenido
/**
 * @return TRUE o FALSE dependiendo del objeto
/***/
BOOL isObjInObjMun(OBJETO * o, ID id);

/**
 * @brief sacamos un objeto de otro
/**
 * sacaObjOfObj() extrae una id del inventario de otro objeto dado
/**
 * @param cont es un puntero al objeto contenedor
 * @param obj es la id del objeto contenido
/**
 * @return OK si todo fue correcto, ERR en caso contario
/***/
STATUS sacaObjOfObj(OBJETO *cont, ID obj);

/****************************************/
/**Funciones básicas para crear un jugador/
/****************************************/


/**
 * @brief Guarda un jugador en el mundo
/**
 * guardaJug() guarda en la primera posicion libre el elemento recibido  
/**
 * @param m es un puntero al mundo
 * @param jugador es un puntero al jugador a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS guardaJug(MUNDO *m, JUGADOR * jugador);


/**
 * @brief crea un jugador
/**
 * creaJug() reserva la memoria 
/**
 * @param jugador es un puntero a un puntero tipo jugador
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaJug(JUGADOR ** jugador);

/**
 * @brief Destruye un jugador
/**
 * destruyeJug() elimina la reserva de memoria 
/**
 * @param jugador es un puntero a un puntero tipo jugador
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS destruyeJug(JUGADOR ** jugador);


/**
 * @brief Modifica la id de un jugador
/**
 * creaIdJug() modifica la id de un jugador dado
/**
 * @param jugador es un puntero al jugador
 * @param id es la id a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdJug(JUGADOR * jugador, ID id);


/**
 * @brief Modifica el nombre de un jugador
/**
 * creaNombreJug() guarda como nombre la cadena nombre
/**
 * @param jugador es un puntero al jugador
 * @param nombre es un puntero a la cadena con la informacion
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaNombreJug(JUGADOR * jugador, char * nombre);


/**
 * @brief Modifica la posicion de un jugador
/**
 * creaLocJug() modifica la id de la posicion de un jugador dado
/**
 * @param jugador es un puntero al jugador
 * @param id es la id a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaLocJug(JUGADOR * jugador, ID id);


/**
 * @brief Modifica el tamaño del inventario de un jugador
/**
 * creaMaxObjJug() cambia el tamaño de un inventario
/**
 * @param jugador es un puntero al jugador
 * @param max es un entero con el tamaño deseado
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaMaxObjJug(JUGADOR * jugador, int max);


/**
 * @brief introduce un objeto en un inventario de un jugador
/**
 * meteObjJug() guarda en el inventario de del jugador un objeto
/**

 * @param jugador es un puntero al jugador donde guardar
 * @param id es la id del objeto a guardar
/**
 * @return OK si fue correcto, ERR si falló
/***/
STATUS meteObjJug(JUGADOR *jugador, ID id);



/***************************************/
/**Funciones para jugador****************/
/***************************************/

/**
 * @brief devuelve el jugador sabiendo la id
/**
 * dameJugador() devuelve un puntero a un jugador sabiendo la id
/**
 * @param m es un puntero al mundo
 * @param id es el identificador a buscar
 * 
 * @return un puntero al jugador o NULL si falló
/***/
JUGADOR * dameJugador(MUNDO * m, ID id);


/**
 * @brief devuelve el nombre de un jugador
/**
 * darNombreJug() devuelve en una cadena dada el nombre de un jugador teniendo su puntero
/**
 * @param jugador es un puntero al jugador deseado
 * @param nombre es un puntero al array donde guardar dicho nombre
 * @param max_len es el tamaño de nombre
/**
 * @return ERR si se produjo error,OK si se hizo correctamente
/***/
STATUS darNombreJug(JUGADOR *jugador, char *nombre, int max_len);


/**
 * @brief devuelve la localizacion de un jugador
/**
 * darLocJug() devuelve la id del espacio donde se situa
/**
 * @param jugador es un puntero al jugador deseado
/**
 * @return la ID del espacio
/***/
ID darLocJug(JUGADOR * jugador);


/**
 * @brief consigues el jugador sabiendo el nombre
/**
 * consigueJugador() devuelve un puntero a un jugador cuyo nombre coincide con uno dado
/**
 * @param m es un puntero al mundo
 * @param nombre es un puntero a la cadena donde está el nombre buscado
/**
 * @return un puntero al objeto encontrado o NULL si dió error
/***/
JUGADOR * consigueJugador(MUNDO * m, char * nombre);

/**
 * @brief informa sobre el inventario de un jugador
/**
 * dameInvExaminar() devuelve dentro de info una cadena con los nombres de los objetos del inventario
/**
 * @param m es un puntero al mundo
 * @param jug es un puntero al jugador deseado
 * @param info es un puntero a la cadena donde guardar los datos
/**
 * @return  ERR si se produjo error,OK si se hizo correctamente
/***/
STATUS dameInvExaminar(MUNDO *m, JUGADOR * jug, char * info);

/**
 * @brief informa sobre la id de un jugador
/**
 * darIdJug() devuelve el identificador de un jugador
/**
 * @param j es un puntero al jugador deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darIdJug(JUGADOR * j);

/**
 * @brief informa sobre el inventario de un jugador
/**
 * darMaxJug() devuelve el tamaño del inventario de un jugador
/**
 * @param j es un puntero al jugador deseado
/**
 * @return un entero con el tamaño
/***/
int darMaxJug(JUGADOR * j);

/**
 * @brief informa si cierto objeto lo tiene un jugador
/**
 * isObjInInvMun() devuelve un booleano diciendo si un objeto se situa dentro del inventario de un jugador
/**
 * @param j es un puntero al jugador deseado
 * @param id es la id del objeto a buscar
/**
 * @return un booleano que indiqui TRUE o FALSE
/***/
BOOL isObjInInvMun(JUGADOR * j, ID id);

/**
 * @brief extrae un objeto del inventario de un jugador
/**
 * sacaObjOfInv() extrae la id de un objeto del conjunto que forma el inventario de un jugador
/**
 * @param cont es un puntero al jugador deseado
 * @param obj es la id del objeto a extraer
/**
 * @return  ERR si se produjo error,OK si se hizo correctamente
/***/
STATUS sacaObjOfInv(JUGADOR *cont, ID obj);

/***************************************/
/**Funciones básicas para crear espacios*/
/***************************************/


/**
 * @brief Guarda un espacio en el mundo
/**
 * guardaEsp() guarda en la primera posicion libre el elemento recibido  
/**
 * @param m es un puntero al mundo
 * @param espacio es un puntero al espacio a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS guardaEsp(MUNDO *m, ESPACIO * espacio);


/**
 * @brief crea un espacio
/**
 * creaEsp() reserva la memoria necesaria
/**
 * @param espacio es un puntero a un puntero tipo espacio
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaEsp(ESPACIO ** espacio);

/**
 * @brief creaDescGraficaEsp
 * Esta función permite cambiar la descripción gráfica de un espacio
 * @param espacio es puntero al espacio en el que guardar la desscripción gráfica
 * @param dibujo es puntero de char con la descripción gráfica a guardar
 * @param filas es entero con el número de filas de la descripción gráfica
 * @param columnas es entero con el número de columnas de la descripción gráfica
 * @return ERR si no se introdujo correctamente o OK en caso contrario
 * @author Miguel Gordo
*/
STATUS creaDescrGraficaEsp(ESPACIO *espacio,char *dibujo,int filas,int columnas);

/**
 * @brief Destruye un espacio
/**
 * destruyeEsp() elimina la reserva de memoria 
/**
 * @param espacio es un puntero a un puntero tipo espacio
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS destruyeEsp(ESPACIO ** espacio);

/**
 * @brief Modifica la id de un espacio
/**
 * creaIdEspMundo() modifica la id de cierto espacio
/**
 * @param espacio es un puntero al espacio
 * @param id es la id a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdEspMundo(ESPACIO * espacio, ID id);


/**
 * @brief Modifica la descripcion de un espacio
/**
 * creaDescEsp() guarda como descripcion la cadena descripcion
/**
 * @param espacio es un puntero al espacio
 * @param descripcion es un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaDescEsp(ESPACIO * espacio, char *descripcion);


/**
 * @brief Modifica el examinado de un espacio
/**
 * creaExamEsp() guarda como examinado a la cadena examinar
/**
 * @param espacio es un puntero al espacio
 * @param examinar un puntero a la cadena con los datos
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaExamEsp(ESPACIO * espacio, char * examinar);


/**
 * @brief introduce un objeto en un espacio
/**
 * meteObjEsp() guarda en el inventario del espacio un objeto
/**
 * @param espacio es un puntero al espacio donde guardar
 * @param id es la id del objeto a guardar
/**
 * @return OK si fue correcto, ERR si falló
/***/
STATUS meteObjEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece si un espacio es luminoso o no
/**
 * creaLumEsp() pone en TRUE o FALSE la indicacion luminoso
/**
 * @param espacio es un puntero al espacio 
 * @param luminoso es un booleano que indica si es luminoso o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaLumEsp(ESPACIO *espacio, BOOL luminoso);


/**
 * @brief Establece la posible union al norte de un espacio
/**
 * creaNorteEsp() indica la ID de la union norte si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaNorteEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece la posible union al sur de un espacio
/**
 * creaSurEsp() indica la ID de la union sur si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaSurEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece la posible union al este de un espacio
/**
 * creaEsteEsp() indica la ID de la union este si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaEsteEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece la posible union al oeste de un espacio
/**
 * creaOesteEsp() indica la ID de la union oeste si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaOesteEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece la posible union encima de un espacio
/**

 * creaArribaEsp() indica la ID de la union arriba si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaArribaEsp(ESPACIO * espacio, ID id);


/**
 * @brief Establece la posible union debajo de un espacio
/**
 * creaAbajoEsp() indica la ID de la union abajo si existiera
/**
 * @param espacio es un puntero al espacio
 * @param id es la id de la union si acaso esta existe
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaAbajoEsp(ESPACIO * espacio, ID id);


/***************************************/
/**Funciones para espacio****************/
/***************************************/


/**
 * @brief devuelve la descripcionde un espacio
/**
 * dameDescrEsp() guarda en una cadena la descripcion de un  espacio siempre que no supere el tamaño
/**
 * @param espacio es un puntero al espacio deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrEsp(ESPACIO * espacio, char *descripcion, int max_len);

/**
 * @brief devuelve la descripcion grafica de un espacio
/**
 * darDescrGraficaEsp() guarda en una cadena la descripcion grafica de un espacio y los tamaños
/**
 * @param e es un puntero al espacio deseado
 * @param descripcion es un triple puntero a char donde guardar la descripcion grafica pedida
 * @param filas es donde guardar el tamaño de las filas
 * @param columnas es donde guardar el tamaño de las columnas
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrGraficaEsp(ESPACIO * e, char ***descripcion, int * filas, int * columnas);


/**
 * @brief devuelve el espacio sabiendo la id
/**
 * dameEspacio() devuelve un puntero a un espacio sabiendo la id
/**
 * @param m es un puntero al mundo
 * @param id es el identificador a buscar
 * 
 * @return un puntero al espacio o NULL si falló
/***/
ESPACIO * dameEspacio(MUNDO * m, ID id);

/**
 * @brief informa sobre la id de un espacio
/**
 * darIdEsp() devuelve el identificador de un espacio
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darIdEsp(ESPACIO *e);

/**
 * @brief devuelve la descripcion al examinar un espacio
/**
 * darDescrexamEsp() guarda en una cadena la descripcion de un espacio siempre que no supere el tamaño
/**
 * @param e es un puntero al espacio deseado
 * @param descripcion es un puntero a una cadena donde guardar la descripcion pedida
 * @param max_len es el tamaño de descripcion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS darDescrexamEsp(ESPACIO * e, char *descripcion, int max_len);

/**
 * @brief informa si cierto espacio es luminoso
/**
 * darLumEsp() accede al campo luminoso de un espacio dado
/**
 * @param e es un puntero al espacio deseado
/**
 * @return un booleano que indique TRUE o FALSE
/***/
BOOL darLumEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta al norte
/**
 * darNorteEsp() devuelve el identificador de la union que se situa al norte
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darNorteEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta al sur
/**
 * darSurEsp() devuelve el identificador de la union que se situa al sur
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darSurEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta al este
/**
 * darEsteEsp() devuelve el identificador de la union que se situa al este
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darEsteEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta al oeste
/**
 * darOesteEsp() devuelve el identificador de la union que se situa al oeste
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darOesteEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta arriba
/**
 * darArribaEsp() devuelve el identificador de la union que se situa arriba
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darArribaEsp(ESPACIO *e);

/**
 * @brief informa sobre la id de la union que esta abajo
/**
 * darAbajoEsp() devuelve el identificador de la union que se situa abajo
/**
 * @param e es un puntero al espacio deseado
/**
 * @return una ID que sera negativa en caso de error
/***/
ID darAbajoEsp(ESPACIO *e);

/**
 * @brief informa si cierto objeto se situa en un espacio
/**
 * isObjInEspMun() devuelve un booleano diciendo si un objeto se situa dentro del inventario de un espacio
/**
 * @param e es un puntero al espacio deseado
 * @param id es la id del objeto a buscar
/**
 * @return un booleano que indique TRUE o FALSE
/***/
BOOL isObjInEspMun(ESPACIO *e, ID id);

/**
 * @brief extrae un objeto del inventario de un espacio
/**
 * sacaObjOfEsp() extrae la id de un objeto del conjunto que forma el inventario de un espacio
/**
 * @param cont es un puntero al espacio deseado
 * @param obj es la id del objeto a extraer
/**
 * @return  ERR si se produjo error,OK si se hizo correctamente
/***/
STATUS sacaObjOfEsp(ESPACIO *cont, ID obj);


/***************************************/
/**Funciones basicas para crear uniones**/
/***************************************/


/**
 * @brief Guarda una union en el mundo
/**
 * guardaUni() guarda en la primera posicion libre el elemento recibido  
/**
 * @param m es un puntero al mundo
 * @param uni es un puntero a la union a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS guardaUni(MUNDO *m, UNION * uni);


/**
 * @brief crea una union
/**
 * creaUni() reserva la memoria 
/**
 * @param uni es un puntero a un puntero tipo union
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaUni(UNION ** uni);


/**
 * @brief Destruye una union
/**
 * destruyeUni() elimina la reserva de memoria 
/**
 * @param uni es un puntero a un puntero tipo union
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS destruyeUni(UNION ** uni);


/**
 * @brief Modifica la id de una union
/**
 * creaIdUniMundo() modifica la id de cierta union
/**
 * @param uni es un puntero a union
 * @param id es la id a guardar
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdUniMundo(UNION * uni, ID id);


/**
 * @brief Modifica la id de salida de cierta union
/**
 * creaIdSalidaUni() establece la id del espacio de salida
/**
 * @param uni es un puntero a la union
 * @param id es la id del espacio de salida
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdSalidaUni(UNION * uni, ID id);


/**
 * @brief Modifica la id de llegada de cierta union
/**
 * creaIdLlegadaUni() establece la id del espacio de llegada
/**
 * @param uni es un puntero a la union
 * @param id es la id del espacio de llegada
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaIdLlegadaUni(UNION * uni, ID id);


/**
 * @brief Establece si una union está abierta o no
/**
 * creaAbiertaUni() pone en TRUE o FALSE la indicacion abierta
/**
 * @param uni es un puntero a una union 
 * @param abierta es un booleano que indica si esta abierta o no
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaAbiertaUni(UNION * uni, BOOL abierta);


/**
 * @brief Establece el objeto que abre una union
/**
 * creaKeyUni() guarda la ID del objeto que abre la union
/**
 * @param uni es un puntero a una union 
 * @param objeto es la id del objeto susodicho
/**
 * @return OK si fue correcto, ERR si fallo
/***/
STATUS creaKeyUni(UNION * uni, ID objeto);

/***************************************/
/**Funciones para union******************/
/***************************************/

/**
 * @brief devuelve la union sabiendo la id
/**
 * dameUnion() devuelve un puntero a una union sabiendo la id
/**
 * @param m es un puntero al mundo
 * @param id es el identificador a buscar
/** 
 * @return un puntero al espacio o NULL si falló
/***/
UNION * dameUnion(MUNDO * m, ID id);

/**
 * @brief devuelve la id de cierta union
/**
 * darIdUni() devuelve la id a partir de un puntero a la union
/**
 * @param uni es un puntero a la union deseada
/** 
 * @return la id deseada o negativo si da error
/***/
ID darIdUni(UNION * uni);

/**
 * @brief consigue la id del espacio de salida
/**
 * darSalidaUni() accede mediante al puntero al espacio del cual se sale
/**
 * @param uni es un puntero a la union deseada
/** 
 * @return la id deseada o negativo si da error
/***/
ID darSalidaUni(UNION * uni);

/**
 * @brief devuelve la id del espacio de llegada
/**
 * darLlegadaUni() accede mediante al puntero al espacio al cual se llega
/**
 * @param uni es un puntero a la union deseada
/** 
 * @return la id deseada o negativo si da error
/***/
ID darLlegadaUni(UNION * uni);

/**
 * @brief informa si una union esta abierta o cerrada
/**
 * darAbiertaUni() indica el valor booleano del campo abierto
/**
 * @param uni es un puntero a la union deseada
/** 
 * @return el booleano que indique la posicion
/***/
BOOL darAbiertaUni(UNION * uni);

/**
 * @brief devuelve la id de la llave
/**
 * darKeyUni() devuelve la id del objeto que abre la union
/**
 * @param uni es un puntero a la union deseada
/** 
 * @return la id deseada o negativo si da error
/***/
ID darKeyUni(UNION * uni);


/***************************************/
/**Acciones del usuario******************/
/***************************************/


/**
 * @brief Funcion auxiliar de mueve personaje
/**
 * muevePersonajeAux() realiza varias acciones que se repiten a menudo en muevePersonaje(), de modo que se reaprovecha el codigo
/**
 * @param m es un puntero al mundo
 * @param unionMov es la id de la union que vamos a analizar
 * @param jugador es un puntero al jugador que quiere moverse
/**
 * @return ERR si fallo, OK si es correcto
/***/
STATUS muevePersonajeAux(MUNDO *m, ID unionMov, JUGADOR *jugador);


/**
 * @brief Mueve al personaje
/**
 * muevePersonaje() actualiza la localizacion de cierto personaje si es posible
/**
 * @param m es un puntero al mundo
 * @param dir indica la direccion deseada para el movimiento
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS muevePersonaje (MUNDO *m, DIRECCION dir, JUGADOR * jugador);



/**
 * @brief El jugador coge un objeto
/**
 * cogeObjeto() introduce un nuevo objeto en el inventario de un jugador, quitándolo del espacio
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto que se quiere recoger
 * @param jugador es un puntero al jugador que quiere cogerlo
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS cogeObjeto(MUNDO * m, OBJETO * objeto, JUGADOR * jugador);


/**
 * @brief El jugador deja un objeto
/**
 * dejaObjeto() introduce un nuevo objeto en el inventario de un espacio, quitandolo del jugador
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto que se quiere dejar
 * @param jugador es un puntero al jugador que quiere dejarlo
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS dejaObjeto(MUNDO * m, OBJETO * objeto, JUGADOR * jugador);



/**
 * @brief Enciende un objeto
/**
 * enciende() convierte en TRUE la propiedad encendido de un objeto
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto a encender
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS enciende(MUNDO *m, OBJETO * objeto, JUGADOR * jugador);



/**
 * @brief Apaga un objeto
/**
 * apaga() convierte en FALSE la propiedad encendido de un objeto
/**
 * @param m es un puntero al mundo
 * @param objeto es un puntero al objeto a apagar
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS apaga(MUNDO *m, OBJETO * objeto, JUGADOR * jugador);


/**
 * @brief introduce un objeto en otro
/**
 * meterObjObj() agrega un objeto en el inventario de otro objeto y lo elimina del inventario del jugador
/**
 * @param m es un puntero al mundo
 * @param objetoContenedor es un puntero al objeto que recibe
 * @param objetoContenido es un puntero al objeto que introduces
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS meterObjObjAc(MUNDO *m, OBJETO * objetoContenedor, OBJETO * objetoContenido, JUGADOR * jugador);



/**
 * @brief Saca un objeto de otro
/**
 * sacarObjObj() elimina un objeto del inventario de otro objeto y lo agrega al inventario del jugador
/**
 * @param m es un puntero al mundo
 * @param objetoContenedor es un puntero al objeto del que se saca
 * @param objetoContenido es un puntero al objeto que se saca
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS sacarObjObjAc(MUNDO *m, OBJETO * objetoContenedor, OBJETO * objetoContenido, JUGADOR * jugador);


/**
 * @brief devuelve el examinado de un objeto
/**
 * dameObjetoExaminar() guarda en una cadena el examinado de un objeto siempre que no supere el tamaño
/**
 * @param m es un puntero al mundo 
 * @param objeto es un puntero al objeto deseado
 * @param jugador es el jugador en juego
 * @param examinar un puntero a una cadena donde guardar la descripcion pedida
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS dameObjetoExaminar(MUNDO *m, OBJETO * objeto, JUGADOR * jugador, char *examinar);


/**
 * @brief devuelve el examinado de un espacio
/**
 * dameEspacioExaminar() guarda en una cadena el examinado de un espacio siempre que no supere el tamaño
/**
 * @param m es un puntero al mundo 
 * @param jugador es el jugador en juego
 * @param examinar un puntero a una cadena donde guardar la descripcion pedida
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS dameEspacioExaminar(MUNDO *m, JUGADOR * jugador, char *examinar);


/**
 * @brief Abre una union para pasar de un espacio a otro
/**
 * abreUnion() comprueba si la union se puede abrir, y si asi es, lo abre solo si el jugador tiene el objeto necesario
/**
 * @param uni es un puntero a la union
 * @param jugador es un puntero al jugador que realiza el movimiento
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS abreUnion(UNION * uni, JUGADOR * jugador);


/**
 * @brief Un personaje le da un objeto a otro
/**
 * intercambioObj() un objeto se traslada del inventario de da al inventario de recibe
/**
 * @param da es un puntero al jugador que se desprende del objeto
 * @param recibe es un puntero al jugador que recpeciona el objeto
 * @param obj es un puntero al objeto en cuestion
/**
 * @return OK si todo es correcto, ERR si hubo algun fallo
/***/
STATUS intercambioObj(JUGADOR * da, JUGADOR * recibe, OBJETO * obj);

#endif
