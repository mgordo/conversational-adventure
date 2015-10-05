/**
* @file reglas.h
* @author Antonio Jim�nez Pastor
* @version 1.0
* Fichero que contiene las estructuras y declaraciones necesarias para el manejo de la estructura REGLA
*/

#ifndef _REGLAS_H
#define _REGLAS_H

#include "mundo.h"
#include "tipos.h"

/** @brief Enumeraci�n que permitir� saber que funci�n de MUNDO llamar para comprobar la regla*/
typedef enum{
	/*!<Modificar Valores*/
	P_LOC_OBJ,
	P_MOV_OBJ,
	P_OCU_OBJ,
	P_ENC_OBJ,
	P_CON_OBJ,
	P_LUZ_OBJ,
	P_LOC_JUG,
	P_MAX_JUG,
	P_LUM_ESP,
	P_NOR_ESP,
	P_SUR_ESP,
	P_EST_ESP,
	P_OES_ESP,
	P_ARR_ESP,
	P_ABA_ESP,
	P_ABI_UNI,
	/*!< Comprobar campo*/
	LOC_OBJ,
	MOV_OBJ,
	MOVI_OBJ,
	OCU_OBJ,
	ENC_OBJ,
	LOC_JUG,
	LUM_ESP,
	ABI_UNI,
	KEY_UNI,
	OBJ_IN_OBJ,
	OBJ_IN_JUG,
	OBJ_IN_ESP,
	/*!< Valores de fin de juego*/
	WIN_GAME,
	LOSE_GAME
} CAMPO;

/** @brief Estructura REGLA*/
typedef struct{
	/*!< Campos de modificar*/
	int num_influido, tam_datos_i; /*!< Tamanio de los campos Influido (ID) y valor_cam (bytes)*/
	ID *influido; /*!< Array de ID's que seran los que se veran modificados al ejecutar la REGLA*/
	CAMPO *c;/*!< Array de CAMPO's que indicaran las funciones que se deben usar para ejecutar una REGLA*/
	void *valor_cam;/*!< Array de bytes con los datos con los que se modificara el mundo al ejecutar la REGLA*/
	/*!< Campos para comprobar*/
	int num_disparador, tam_datos_d;/*!< Tamanio de los campos Disparador (ID) y valor (bytes)*/
	ID *disp;/*!< Array de ID's que seran los campos que provocaran el disparo de la REGLA*/
	CAMPO *key;/*!< Array de CAMPO's que indicaran las funciones con las que se evaluara la REGLA*/
	void *valor;/*!< Array de bytes con los datos para evaluar la REGLA*/
	/*!< Otros valores*/
	BOOL anterior;/*!< Valor booleano que indica la ultima evaluacion de la REGLA*/
	char *frase;/*!< Cadena de caracteres que se devolvera al ejecutar una REGLA*/
} REGLA;


/**
/* @brief Estructura b�sica para almacenar las reglas*/
/**
/* Esta estructura contiene todas las reglas y su n�mero*/
/**/
typedef struct
{
	REGLA ** normas; /*!< Array de punteros a REGLA's*/
	int cantidad; /*!< Numero que indica la cantidad de REGLA's*/
} REGLAS;

/**Descripci�n de la estructura:
 *	- t es un TIPOREGLA que permitir� saber cu�ndo hay que verificar una REGLA
 *	- num_influido es el numero de acciones a realizar
 *	- tam_datos_i es el numero de bytes de los datos que se pasar�n como argumento a las funciones de las acciones
 *	- influido es un puntero a un array de ids de las ESTRUCTURAS que hay que cambiar
 *	- c es un array de valores de CAMPO que permitir�n saber qu� funciones usar para cambiar los valores
 *	- valor_cam es un puntero a un array de datos que ser�n los datos que se introducir�n en los respectivos campos marcados con anterioridad
 *	- num_disparador es el numero de condiciones
 *	- tam_datos_d es el numero de bytes que contienen los resultados esperados en las funciones de la evaluaci�n
 *	- disp es un array de ids de las ESTRUCTURAS que disparan/validan la regla
 *	- key es un array de valores de la enumeraci�n CAMPO que marcar� con qu� funciones de mundo se validar�n los datos
 *	- valor es un puntero a un array de datos con los que validar los campos
 *	- anterior es un campo que indica el resultado de la �ltima evaluaci�n de la regla

 *NOTA: como los datos son de tipo desconocido, se tienen punteros a void que luego se castear�n para que coincida con los datos que corresponda
*/


/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Creaci�n de Reglas
* Esta funci�n crea una regla y la guarda en un puntero que previamente era NULL
* @param r puntero al puntero donde se desea guardar la regla
* @return devuelve un STATUS con el resultado de la operaci�n
*/
STATUS creaRegla(REGLA **r);


/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Destrucci�n de Reglas
* destruyeRegla() se encarga de liberar toda la memoria que hubiese sido reservada
* para una regla, y pone el puntero de dicha regla a NULL
* @param r puntero al puntero de la regla que se desea destruir
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS destruyeRegla(REGLA **r);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Numero de Acciones
* @param r puntero a la regla que se desea modificar
* @param i es el numero que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaTamanioInfluido(REGLA *r, int i);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Tama�o Datos de Acciones
* @param r puntero a la regla que se desea modificar
* @param t es el numero que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaTamanioDatosInfluido(REGLA *r, int t);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de IDs de Acciones
* @param r puntero a la regla que se desea modificar
* @param inf es un array de ID's a guardar
* @param tam es el numero de ID's que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaInfluido(REGLA *r, ID *inf, int tam);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Funciones de Acciones
* @param r puntero a la regla que se desea modificar
* @param c es un array de CAMPO's que se desea guardar
* @param tam es el numero de CAMPO's que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaCampoInfluido(REGLA *r, CAMPO *c, int tam);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Datos de Acciones
* @param r puntero a la regla que se desea modificar
* @param datos es un array sde bytes que se desea guardar
* @param tam es el numero de bytes que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaValorInfluido(REGLA *r, void *datos, int tam);

/**
* @author Antonio Jimenez Pastor*
* @date 24-11-2010
* @brief Modificaci�n de N�mero de Condiciones
* @param r puntero a la regla que se desea modificar
* @param i es el numero que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaTamanioDisparador(REGLA *r, int i);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Tama�o de los Datos de las Condiciones
* @param r puntero a la regla que se desea modificar
* @param t es el numero que se desea guardar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaTamanioDatosDisparador(REGLA *r, int t); 

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de IDs de las Condiciones
* @param r puntero a la regla que se desea modificar
* @param dis es un array de ID's que se desea guardar
* @param tam es el numero de ID's que hay
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaDisparador(REGLA *r, ID *dis, int tam);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de las Funciones de Condiciones
* @param r puntero a la regla que se desea modificar
* @param c es un array de CAMPO's que se deea guardar
* @param tam es el numero de CAMPO's que se quiere cambiar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaCampoDisparador(REGLA *r, CAMPO *c, int tam);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Datos de Condiciones
* @param r puntero a la regla que se desea modificar
* @param datos es un array de bytes que se desean guardar
* @param tam es el numero de bytes que se quiere cambiar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaValorDisparador(REGLA *r, void *datos, int tam);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Evaluaci�n Anterior
* @param r puntero a la regla que se desea modificar
* @param valor es un booleano por el que se quiere cambiar
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaAnterior(REGLA *r, BOOL valor);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Modificaci�n de Frase
* cambiaFrase() copia en el campo frase el contenido de la cadena correspondiente
* @param r puntero a la regla que se desea modificar
* @param frase un puntero a la cadena de donde sacar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS cambiaFrase(REGLA *r, char *frase);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Numero de Acciones
* @param r puntero a la regla de la que se desea el dato
* @param i es un puntero a un numero donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberTamanioInfluido(REGLA *r, int *i);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Tama�o de Datos Influidos
* @param r puntero a la regla de la que se desea el dato
* @param t es un puntero a un numero donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberTamanioDatosInfluido(REGLA *r, int *t);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de IDs influidas
* @param r puntero a la regla de la que se desea el dato
* @param inf es un array de ID's donde guardar los datos
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberInfluido(REGLA *r, ID *inf);


/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Campos Influidos
* @param r puntero a la regla de la que se desea el dato
* @param c es un array de CAMPO's donde guardar los datos
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberCampoInfluido(REGLA *r, CAMPO *c);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Datos con los que Modificar
* @param r puntero a la regla de la que se desea el dato
* @param datos es un array de bytes donde guardar los datos
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberValorInfluido(REGLA *r, void *datos);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Numero de Disparadores
* @param r puntero a la regla de la que se desea el dato
* @param i es un puntero a un numero donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberTamanioDisparador(REGLA *r, int *i);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Tama�o de los Datos Disparadores
* @param r puntero a la regla de la que se desea el dato
* @param t es un puntero a un numero donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberTamanioDatosDisparador(REGLA *r, int *t); 

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de IDs Disparadores
* @param r puntero a la regla de la que se desea el dato
* @param dis es un array de ID's donde guardar los datos
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberDisparador(REGLA *r, ID *dis);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Campos Disparadores
* @param r puntero a la regla de la que se desea el dato
* @param c es un array de CAMPO's donde guardar los datos
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberCampoDisparador(REGLA *r, CAMPO *c);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Datos
* saberValorDisparador() se encarga de extraer de la regla los datos que se desean como resultado
* en las funciones de condici�n.
* @param r es la regla de la que se desean los datos
* @param datos es un puntero a un array de bytes donde guardar los datos
* @return un valos STATUS con el resultado de la operaci�n
*/
STATUS saberValorDisparador(REGLA *r, void *datos);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Ultima verificaci�n
* saberAnterior() guarda en valor si la regla r fue evaluada con anterioridad y si fue verdadera
* o, por el contrario, falsa.
* @param r puntero a la regla de la que se desea el dato
* @param valor un puntero a un dato booleano donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberAnterior(REGLA *r, BOOL *valor);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Extracci�n de Frase
* saberFrase() copia en frase el contenido del campo correspondiente de la estructura REGLA
* @param r puntero a la regla de la que se desea el dato
* @param frase un puntero a la cadena donde guardar el dato
* @return un valor STATUS con el resultado de la operaci�n
*/
STATUS saberFrase(REGLA *r, char *frase);


/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief �Est� destruida una regla?
* isReglaDestruida() averigua si una regla existe o no
* @param r regla que se desea verificar
* @return TRUE si las condiciones se cumplen, y FALSE si no
*/
BOOL isReglaDestruida(REGLA *r);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief �Est� vac�a una regla?
* isEmptyRegla() averigua si una regla est� reci�n creada, y sin datos en su interior
* @param r regla que se desea verificar
* @return TRUE si las condiciones se cumplen, y FALSE si no
*/
BOOL isEmptyRegla(REGLA *r);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Evaluaci�n de la Regla
* evaluaRegla() se encarga de ejecutar una serie de funciones de mundo para verificar el estado
* del mismo. Verifica una a una todas las condiciones y, si todas son ciertas, devolver� TRUE.
* En otro caso, devolver� FALSE.
* @param r regla que se desea verificar
* @param m es un puntero al mundo donde se desea comprobar la REGLA
* @return TRUE si las condiciones se cumplen, y FALSE si no
*/
BOOL evaluaRegla(REGLA *r, MUNDO *m);

/**
* @author Antonio Jimenez Pastor
* @date 24-11-2010
* @brief Ejecuci�n de la consecuencia de una acci�n
* ejecutaAccionRegla() ejecuta una serie de funciones de mundo que lo modificar�n siguiendo
* los par�metros de influenciados. Solo se realizar�n cambios si la regla es de tipo DISPARAR.
* Esta funci�n no se asegura que la regla sea TRUE en ese momento. Se deja eso en manos de quien
* use la funci�n.
* @param r regla que se desea ejecutar
* @param m es un puntero al mundo donde se desea ejecutar la REGLA
* @return un valor STATUS con el resultado de la operaci�n
*/
GAMES ejecutaAccionRegla(REGLA *r, MUNDO *m);

/**
* @brief reserva una 'reglas'
* creaReglas() reserva memoria para una estructura reglas
* @param n es el n�mero de reglas 
* @return un puntero a la reserva, o NULL si fall�
*/
REGLAS * creaReglas(int n);


/**
* @brief destruye una reserva de 'reglas'
* destruyeReglas() libera la memoria reservada anteriormente
* @param reglas es el puntero al puntero de una estructura reglas
* @return OK si fue correcto, ERR si fall�
*/
STATUS destruyeReglas(REGLAS ** reglas);


#endif

