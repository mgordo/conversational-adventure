/**
 * @brief Primitivas de la Reglas diálogo
 * Este modulo contiene los prototipos de las funciones de Reglas acciones 
 * @file reglasdialogo.h 
 * @author Miguel Gordo
 * @version 1.0 
 * @date 24-11-2010 
*/

#include <stdio.h>
#include <string.h>
#include"tipos.h"
#include <stdlib.h>
#include <time.h>
#ifndef REGLASDIALOGO_H_
#define REGLASDIALOGO_H_


/** @brief Estructura REGLAD*/
typedef struct _regla 
{
    char *patron;       /*!<Cadena del patron. Si cumple este patron se ejecuta la regla*/ 
    int ini;            /*!< Indica la primera plantilla a considerar */
    int fin;            /*!< Indica la ultima plantilla a considerar*/ 
     /* El numero de plantillas que incluye una regla 
     se calcularia como fin - ini */
    int ult;             /*!< Indica la ultima plantilla usada */
} REGLAD;

/** @brief Estructura TEMA*/
typedef struct{

	ID tema; /*!< ID del tema*/
	char nombre[MAX_LEN]; /*!< Nombre del TEMA. Sirve para reconocerlo visualmente*/
}TEMA;

/** @brief Estructura PLANTILLA*/
typedef struct{
	char *plantilla;/*!< Cadena de la PLANTILLA*/
}PLANTILLA;

/** @brief Estructura RELATION*/
typedef struct{

	int relacion[MAX_REGLAS];/*!< Array de números que indican las relaciones del DIALOGUE*/

}RELATION;

/** @brief Estructura DIALOGUE*/
typedef struct{
	REGLAD **rules;/*!< Array de punteros de REGLAD's*/
	int tam_rules;/*!< Numero de reglas del DIALOGUE*/
	RELATION **rel;/*!< Array de punteros de RELATION's*/
	int tam_rel;/*!< Numero de relaciones del DIALOGUE*/
	TEMA **theme;/*!< Array de punteros de TEMA's*/
	int tam_theme;/*!< Numero de temas del DIALOGUE*/
	PLANTILLA **plant;/*!< Array de punteros de PLANTILLA's*/
	int tam_plant;/*!< Numero de plantillas del DIALOGUE*/
}DIALOGUE;

/**Siempre tantas relaciones como temas!*/


/**
 * @brief creaDialogue
 * Esta función permite crear un diálogo
 * @param tam_rules es entero con el tamaño del array rules
 * @param tam_theme es entero con el tamaño del array theme
 * @param tam_rel es entero con el tamaño del array rel
 * @param tam_plant es entero con el tamaño del array plant
 * @return puntero al de diálogo correctamente creado o NULL en caso contrario
 * @author Miguel Gordo*/
DIALOGUE *creaDialogue(int tam_rules,int tam_rel,int tam_theme,int tam_plant);

/**
 * @brief destruyeDiálogo
 * Esta función permite destruir un diálogo
 * @param dial es puntero a puntero a diálogo al que liberar (quedará a NULL)
 * @return OK si se destruyó correctamente, ERR caso contrario
 * @author Miguel Gordo*/

STATUS destruyeDialogue(DIALOGUE **dial);

/**
 * @brief creaReglad
 * Esta función permite crear una reglaDialogo
 * @return puntero a REGLAD correctamente inicializada o NULL en caso contrario
 * @author Miguel Gordo*/

REGLAD *creaReglad();

/**
 * @brief destruyeReglad
 * Esta función permite destruir una reglaDialogo
 * @param rule es doble puntero a REGLAD a destruir
 * @return OK si se liberó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS destruyeReglad(REGLAD **rule);

/**
 * @brief creaPlantilla
 * Esta función permite crear una plantilla
 * @return puntero a PLANTILLA correctamente inicializada o NULL en caso contrario
 * @author Miguel Gordo*/

PLANTILLA *creaPlantilla();

/**
 * @brief creaTema
 * Esta función permite crear un Tema
 * @return puntero a TEMA correctamente inicializada o NULL en caso contrario
 * @author Miguel Gordo*/

TEMA *creaTema();

/**
 * @brief destruyeTema
 * Esta función permite destruir un Tema
 * @param theme es doble puntero a TEMA a destruir
 * @return OK si se liberó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS destruyeTema(TEMA **theme);

/**
 * @brief creaRelation
 * Esta función permite crear una relación
 * @return puntero a RELATION correctamente inicializada o NULL en caso contrario
 * @author Miguel Gordo*/

RELATION *creaRelation();

/**
 * @brief destruyeRelation
 * Esta función permite destruir una relación
 * @param rel es doble puntero a RELATION a destruir
 * @return OK si se liberó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS destruyeRelation(RELATION **rel);

/**
 * @brief destruyePlantilla
 * Esta función permite destruir una plantilla
 * @param plant es doble puntero a PLANTILLA a destruir
 * @return OK si se liberó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS destruyePlantilla(PLANTILLA **plant);

/**
 * @brief guardaReglaD
 * Esta función guardar una REGLAD en un DIALOGUE
 * @param rule es puntero a REGLAD a guardar
 * @param dial es puntero al DIALOGUE en el que guardar
 * @return OK si se guardó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS guardaReglad(DIALOGUE *dial,REGLAD *rule);

/**
 * @brief guardaTema
 * Esta función guardar un TEMA en un DIALOGUE
 * @param theme es puntero a TEMA a guardar
 * @param dial es puntero al DIALOGUE en el que guardar
 * @return OK si se guardó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS guardaTema(DIALOGUE *dial,TEMA *theme);

/**
 * @brief guardaPlantilla
 * Esta función guardar una PLANTILLA en un DIALOGUE
 * @param plant es puntero a PLANTILLA a guardar
 * @param dial es puntero al DIALOGUE en el que guardar
 * @return OK si se guardó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS guardaPlantilla(DIALOGUE *dial,PLANTILLA *plant);

/**
 * @brief guardaRelation
 * Esta función guardar una RELATION en un DIALOGUE
 * @param rel es puntero a RELATION a guardar
 * @param dial es puntero al DIALOGUE en el que guardar
 * @return OK si se guardó correctamente, ERR en caso contrario
 * @author Miguel Gordo*/

STATUS guardaRelation(DIALOGUE *dial,RELATION *rel);

/**
 * @brief iniRelation
 * Esta función permite inicializar una relación
 * @param rel es puntero relación que inicializar
 * @param ent es array de ints que contienen la relación tema-regla
 * @return OK si se inicializó correctamente, ERR caso contrario
 * @author Miguel Gordo*/

STATUS iniRelation(RELATION *rel, int *ent);

/**
 * @brief iniRegla
 * Esta función permite inicializar una regla
 * @param rule es puntero reglad que inicializar
 * @param ini es entero a la primera plantilla
 * @param fin es entero a la última plantilla
 * @param patron es cadena con el patrón del tema
 * @return OK si se inicializó correctamente, ERR caso contrario
 * @author Miguel Gordo*/

STATUS iniRegla(REGLAD *rule,int ini, int fin, char *patron);

/**
 * @brief iniTema
 * Esta función permite inicializar un tema
 * @param theme es puntero a tema que inicializar
 * @param id es id del tema
 * @param nombre es el nombre del tema (para una mejor interpretación)
 * @return OK si se inicializó correctamente, ERR caso contrario
 * @author Miguel Gordo*/

STATUS iniTema(TEMA *theme, ID id, char *nombre);

/**
 * @brief iniPlantilla
 * Esta función permite inicializar una plantilla
 * @param plant es puntero a plantilla a inicializar
 * @param plantilla es la plantilla a introducir
 * @return OK si se inicializó correctamente, ERR caso contrario
 * @author Miguel Gordo*/

STATUS iniPlantilla(PLANTILLA *plant, char *plantilla);

/**
 * @brief busca_patron
 * Esta función permite obtener un patrón para una determinada entrada, buscando entre todos los temas disponibles
 * @param dial es puntero a estructura DIALOGUE donde se encuentran los datos
 * @param entrada es cadena de char que contiene la entrada del usuario
 * @return NO_ENCONTRADO si no se encontró patrón en ningún tema
 * @author Miguel Gordo*/

int busca_patron(DIALOGUE *dial, char *entrada);

/**
 * @brief tbusca_patron
 * Esta función permite obtener un patrón para una determinada entrada, buscando únicamente en el tema especificado por su nombre
 * @param dial es puntero a estructura DIALOGUE donde se encuentran los datos
 * @param entrada es cadena de char que contiene la entrada del usuario
 * @param ntema es el nombre del tema en el que buscar patrones
 * @return NO_ENCONTRADO si no se encontró patrón en ningún tema
 * @author Miguel Gordo*/

int tbusca_patron(DIALOGUE *dial, char *entrada, char *ntema);

/**
 * @brief selecciona_plantilla
 * Esta función permite seleccionar una plantilla aleatoriamente mediante un patrón
 * @param dial es puntero a estructura DIALOGUE donde se encuentran los datos
 * @param ind_patron es el índice del patrón del que obtener plantilla aleatoriamente
 * @param dest es cadena en la que guardar la plantilla
 * @return NULL si hubo error o plantilla para el patrón deseado
 * @author Miguel Gordo*/

STATUS selecciona_plantilla(DIALOGUE *dial, int ind_patron,char *dest);

#endif

