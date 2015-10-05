/**
* @brief Primitivas del motor gráfico
* Este modulo contiene los prototipos de las funciones del motor gráfico 
* @file motor.h 
* @author Miguel Gordo y Antonio Jiménez
* @version 1.0 
* @date 16-11-2010 
*/

#include"mundo.h"
#include"iografica.h"

#ifndef _MOTOR_H
#define _MOTOR_H

/** @brief Estructura Pantalla Virtual*/
typedef PANTALLA PV;

/****************************************************************/

/*		FUNCIONES DEL MOTOR GRÁFICO				*/

/****************************************************************/

/**
* @brief Lee usuario
* Esta función permite leer una frase del usuario a través de una pantallaV
* @param pant es puntero a pantalla a guardar la lectura
* @param lectura es cadena de char que contendrá la frase del usuario
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS leeUsuario(PV *pant,char *lectura);

/**
* @brief Inicialización de PantallaVirtual
* Esta función permite crear un pantallaV
* @param filasizq son las filas de la sección izquierda
* @param columnasizq son las columnas de la sección izquierda*
* @param columna es el caracter delimitador de columnas
* @param fila es el caracter delimitador de filas
* @param esquina es el caracter delimitador de esquinas
* @return Puntero a la pantallaV correctamente inicializada, NULL en caso contrario
* @author Miguel Gordo
*/

PV *creaPV(int filasizq, int columnasizq ,char columna, char fila, char esquina);

/**
* @brief Destrucción pantallaV
* Esta función permite destruir una pantallaV
* @param pant es doble puntero a pantallaV a destruir
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS destruyePV(PV **pant);

/**
* @brief Imprime pantallaV
* Esta función permite imprimir una pantallaV por la salida estándar
* @param pant es puntero a pantallaV a imprimir
* @param mundo es puntero a mundo en el que se chequeará todo lo referente a impresión
* @param resul_accion es una cadena que había devuelto una accion tras ejecutarse
* @return OK en caso correcto, ERR en caso contrario
* @author Miguel Gordo
*/

STATUS imprimePV(PV *pant,MUNDO *mundo, char *resul_accion);

#endif
