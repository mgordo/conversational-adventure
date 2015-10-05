/*****************************************/
/* @file union.h*/
/* Fichero que contiene los prototipos y las estructuras de un ESPACIO*/
/* @author Antonio Jimenez*/
/* @version 1.0*/

/*Información útil:

	- Este módulo depende del módulo CONJUNTO, por lo que se incluirá el .h correspondiente

*/

#include "union.h"

/*Funciones públicas*/

/*
Nombre: creaUnion
Entradas: un puntero al puntero donde se guardará la UNION
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error A: Fallo con la memoria
*/
STATUS creaUnion(UNION **u)
{
	if(isUniDestruida(*u)==FALSE)
		return ERR;	/*Error X, hay datos en esa unión*/

	(*u)=(UNION *)calloc(1,sizeof(UNION));
	if(!(*u))
		return ERR;	/*Error A, no se reservó memoria*/

	(*u)->id=-1;
	(*u)->salida=-1;
	(*u)->llegada=-1;
	(*u)->abierta=TRUE;
	(*u)->key=-1;

return OK;	/*Finalización correcta*/
}


/*
Nombre: destruyeUnion
Entradas: un puntero al puntero de la UNION que se quiere destruir
Salidas: devuelve siempre 0, la UNION se ha destruido
Posibles errores: 
*/
STATUS destruyeUnion(UNION **u)
{
	if(*u)
		free(*u);

	(*u)=NULL;

return OK;	/*Finalización correcta*/
}


/*
Nombre: cambiaUniId
Entradas: un puntero a la UNION que se desea cambiar y la ID que se desea guardar
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaUniId(UNION *u, ID id)
{
	if(isUniDestruida(u)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	u->id=id;

	if(u->id!=id)
		return ERR;	/*Error Z, el dato no se copió bien*/

return OK;
}


/*
Nombre: cambiaUniSalida
Entradas: un puntero a la UNION que se desea cambiar y la ID del espacio de donde sale la UNION
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaUniSalida(UNION *u, ID id)
{
	if(isUniDestruida(u)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	u->salida=id;

	if(u->salida!=id)
		return ERR;	/*Error Z, el dato no se copió bien*/

return OK;	
}


/*
Nombre: cambiaUniLlegada
Entradas: un puntero a la UNION que se desea cambiar y la ID del espacio a donde llega la UNION
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaUniLlegada(UNION *u, ID id)
{
	if(isUniDestruida(u)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	u->llegada=id;

	if(u->llegada!=id)
		return ERR;	/*Error Z, el dato no se copió bien*/

return OK;
}


/*
Nombre: cambiaUniAbierta
Entradas: un puntero a la UNION que se desea cambiar y un valor BOOl que se desea introducir
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaUniAbierta(UNION *u, BOOL abierto)
{
	if(isUniDestruida(u)==TRUE)
		return ERR;	/*Error X, parámetros no válidos*/

	u->abierta=abierto;

	if(u->abierta!=abierto)
		return ERR;	/*Error Z, el dato no se copió correctamente*/

return OK;
}

/*
Nombre: cambiaUniAbierta
Entradas: un puntero a la UNION que se desea cambiar y una ID con el objeto que abre la unión
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaUniKey(UNION *u, ID key)
{
	if(isUniDestruida(u)==TRUE||key<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	u->key=key;

	if(u->key!=key)
		return ERR;	/*Error Z, el dato no se copió bien*/

return OK;
}


/*
Nombre: isUniDestruida
Entradas: un puntero a la UNION que se desea comprobar
Salidas: Devuelve un valor BOOL que indica si la UNION está destruida o no
Posibles errores: 
*/
BOOL isUniDestruida(UNION *u)
{
	if(u==NULL)
		return TRUE;

return FALSE;
}


/*
Nombre: isUniEmpty
Entradas: un puntero a la UNION que se desea comprobar
Salidas: Devuelve un valor BOOL que indica si la UNION está vacía o no
Posibles errores: 
*/
BOOL isUniEmpty(UNION *u)
{
	if(isUniDestruida(u)==TRUE)
		return TRUE;
	
	if(u->id>=0||u->salida>=0||u->llegada>=0||u->key>=0)
		return FALSE;
	if(u->abierta==FALSE)
		return FALSE;

return TRUE;
}


/*
Nombre: isUniAbierta
Entradas: un puntero a la UNION que se desea comprobar
Salidas: Devuelve un valor BOOL que indica si la UNION está vacía o no
Posibles errores: 
*/
BOOL isUniAbierta(UNION *u)
{
	if(isUniDestruida(u)==TRUE)
		return FALSE;

return u->abierta;
}

/*
Nombre: saberUniId
Entradas: un puntero a la UNION de la que se desea la información y un puntero a una ID donde guardarla
Salidas: Devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberUniId(UNION *u, ID *id)
{
	if(isUniEmpty(u)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	if(u->id<0)
		return ERR;	/*Error Y, el campo no está completo*/

	(*id)=u->id;

return OK;
}


/*
Nombre: saberUniSalida
Entradas: un puntero a la UNION de la que se desea la información y un puntero a una ID donde guardarla
Salidas: Devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberUniSalida(UNION *u, ID *id)
{
	if(isUniEmpty(u)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	if(u->salida<0)
		return ERR;	/*Error Y, el campo no está completo*/

	(*id)=u->salida;

return OK;
}


/*
Nombre: saberUniLlegada
Entradas: un puntero a la UNION de la que se desea la información y un puntero a una ID donde guardarla
Salidas: Devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberUniLlegada(UNION *u, ID *id)
{
	if(isUniEmpty(u)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	if(u->llegada<0)
		return ERR;	/*Error Y, el campo no está completo*/

	(*id)=u->llegada;

return OK;
}

/*
Nombre: saberUniLlegada
Entradas: un puntero a la UNION de la que se desea la información y un puntero a una ID donde guardarla
Salidas: Devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberUniKey(UNION *u, ID *id)
{
	if(isUniEmpty(u)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	if(u->key<0)
		return ERR;	/*Error Y, el campo no está completo*/

	(*id)=u->key;

return OK;
}
