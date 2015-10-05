

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/**
* @brief Primitivas de la interfaz gráfica
* Este modulo contiene los prototipos de las funciones de interfaz gráfica 
* @file iografica.h 
* @author Miguel Gordo
* @version 1.0 
* @date 16-11-2010 
*/



#ifndef _IOGRAFICA_H
#define _IOGRAFICA_H

/*Declaración de la estructura para una interfa gráfica PANTALLA*/

#include"tipos.h"

/** @brief Definicion de PANTALLA*/
typedef struct{
	char **matrixI; /*!< Matriz parte izquierda*/
	char **matrixD; /*!< Matriz parte derecha*/
	int filasI; /*!< Numero de filas a la iquierda*/
	int columnasD;/*!< Numero de columnas a la derecha*/
	int filasD;/*!< Numero de filas a la derecha*/
	int columnasI; /*!< Numero de columnas a la iquierda*/
	char columna;  /*!< Caracter separador de columna*/
	char fila; /*!< Caracter separador de fila*/
	char esquina; /*!< Caracter separador de esquina*/
}PANTALLA;

/*SIEMPRE 80x24*/
/*MINIMO PARA LOS DIBUJOS: 42x21*/
/*ESTÁNDAR ES: 21x47 (filas * columnas) para la descrgrafica*/
/*Los dibujos deberán tener siempre tamaño (x-2)x(y-2), siendo x tamaño de columnas bloque izquierdo y tamaño filas, respect.*/
/*ATENCIÓN FILAS Y COLUMNAS DE MATRIZ IZQUIERDA SIEMPRE CONSTANTES*/
/*PARA QUE LOS DIBUJOS NO SE DESCOLOQUEN AL IMPRIMIR. PUEDE VARIAR EL TAMAÑO GENERAL DE LA PANTALLA*/

/****************************************************************/

/*		FUNCIONES DE IOGRAFICA				*/

/****************************************************************/

/**
* @brief Inicialización de Pantalla
* Esta función permite crear un pantalla
* @param filasizq son las filas de la sección del dibujo
* @param columnasizq son las columnas de la sección del dibujo
* @param columna es el caracter delimitador de columnas
* @param fila es el caracter delimitador de filas
* @param esquina es el caracter delimitador de esquinas
* @return Puntero a la pantalla correctamente inicializada, NULL en caso contrario
* @author Miguel Gordo
*/

PANTALLA *creaPantalla(int filasizq, int columnasizq ,char columna, char fila, char esquina);

/**
* @brief Destrucción pantalla
* Esta función permite destruir una pantalla
* @param pant es doble puntero a pantalla a destruir
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS destruyePantalla(PANTALLA **pant);

/**
* @brief Imprime pantalla
* Esta función permite imprimir una pantalla por la salida estándar
* @param pant es puntero a pantalla a imprimir
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS imprimePantalla(PANTALLA *pant);

/**
* @brief borra pantalla
* Esta función permite borrar el contenido de una pantalla
* @param pant es puntero a pantalla a borrar
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS borraPantalla(PANTALLA *pant);

/**
* @brief Introduce Dibujo pantalla
* Esta función permite introducir un dibujo (la descripción gráfica de un espacio) en una pantalla, sección izquierda
* El dibujo no puede tener mayor dimensión que la especificada para cada dibujo
* @param pant es puntero a pantalla a guardar
* @param dibujo es matriz de la descripción gráfica de un objeto
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS introduceDibujoPantalla(PANTALLA *pant, char **dibujo);

/**
* @brief Introduce Descr pantalla
* Esta función permite introducir un texto en una pantalla, sección derecha.
* Los caracteres especiales \n o \t se trataran pertinentemente. \n simulará un salto de línea en pantalla, \t simulará una tabulación de 4 espacios
* Puede darse un formato especial si se tiene en cuenta esto (dos saltos de línea, sangrías, etc)
* @param pant es puntero a pantalla a guardar
* @param descr es cadena de caracteres con el texto a imprimir
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS introduceDescrPantalla(PANTALLA *pant,char *descr);

/**
* @brief Lee pantalla
* Esta función permite leer una frase del usuario a través de una pantalla. No se eliminan caracteres extraños, no se comprueban entradas correctas
* @param pant es puntero a pantalla a guardar la lectura. Reserve memoria con anterioridad
* @param lectura es cadena de char que contendrá la frase del usuario
* @param tamanio es entero con el tamaño de la cadena lectura
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS leePantalla(PANTALLA *pant, char *lectura, int tamanio);

#endif
