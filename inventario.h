/**
 * @brief Primitivas de inventario
 *
 * Este modulo contiene los prototipos de las funciones de manejo de inventario
 * @file inventario.h
 * @author Miguel Gordo
 * @version 1.0
 * @date 2-XI-2010
*/


#ifndef _INVENTARIO_H
#define _INVENTARIO_H

#include"conjunto.h"
#include<stdio.h>

/** @brief Estructura INVENTARIO*/

typedef CONJUNTO INVENTARIO;


/**
 * @brief Crea inventario
/**
 * Crea inventario permite reservar memoria para el inventario de un jugador
 * @return puntero a inventario con la dirección reservada
/**
*/

INVENTARIO *creaInventario();


/**
 * @brief Destruye inventario
/**
 * Destruye inventario permite liberar la memoria dedicada al inventario
 * @param i es un puntero al puntero del inventario, para modificar su contenido después de liberar la memoria
 * @return OK o ERR en caso de Error
 * 
*/
STATUS destruyeInventario(INVENTARIO **i);


/**
 * @brief insertaInventario
/**
 * insertaInventario permite insertar un elemento en un inventario dado
 * @param i es puntero al inventario en el que insertar
 * @param e es puntero al ID que se quiere insertar
 * @return OK o ERR en caso de Error
/**
*/

STATUS insertaInventario(INVENTARIO *i, const ID *e);


/**
 * @brief extraerInventario
/**
 * Esta función permite extraer un objeto del inventario, eliminándolo del mismo
 * @param i es puntero al inventario del que obtener el objeto
 * @param e es una ID del objeto que se quiere extraer
 * @return OK si se extrajo y eliminó correctamente o ERR en caso contrario
/**
*/

STATUS extraeInventario(INVENTARIO *i,const ID e);

/**
 * @brief estaInventario
/**
 * estaInventario permite consultar si un determinado objeto se encuentra o no en el inventario
 * @param i es puntero al inventario en el que consultar
 * @param e es puntero al ID que consultar
 * @return BOOL que indica TRUE si está y FALSE en el caso contrario
/**
*/

BOOL estaInventario(const INVENTARIO *i,const ID *e);


/**
 * @brief tamanioInventario
/**
 * Permite consultar el tamaño actual de un inventario
 * @param i es puntero al inventario a consultar
 * @return int con el número de objetos en el inventario
/**
*/

int tamanioInventario(const INVENTARIO *i);

/**
 * @brief vacioInventario
/**
 * Esta función permite determinar si un inventario está o no vacio
 * @param i es puntero al inventario a consultar
 * @return BOOL que indica TRUE si es vacío y FALSE en el caso contrario
/**
*/

BOOL vacioInventario(const INVENTARIO *i);

/**
 * @brief obtenerIdInventario
/**
 * Esta función permite obtener el ID asocociado al índice iésimo de un inventario
 * @param i es puntero al inventario a consultar
 * @param indice es el índice iésimo del que obtener su ID
 * @return ID en dicha posición, ID nulo en caso contrario
/**
*/

ID obtenerIdInventario(INVENTARIO *i, int indice);


#endif




