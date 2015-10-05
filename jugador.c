/*****************************************/
/* @file objeto.c*/
/* Fichero que contiene el código de todas las funciones que permiten manejar un OBJETO*/
/* @author Antonio Jimenez*/
/* @version 1.0*/

#include "jugador.h"

/*Funciones públicas*/

/*
Nombre: creaJugador
Entradas: un puntero al puntero donde guardar el nuevo jugador. Se modificará al reservar uno nuevo, de ahí que se 
Salidas: devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores
	- Error B: El jugador no está destruido
	- Error A: Error al reservar memoria
*/
STATUS creaJugador(JUGADOR **j)
{
	if(isJugDestruido(*j)==FALSE)
		return ERR;	/*Error B, hay algo en el puntero, por lo que no se sobreescribe*/

	*j=(JUGADOR *)calloc(1,sizeof(JUGADOR));
	if(!(*j))
		return ERR;	/*Error A, no se ha reservado memoria*/

	/*Iniciamos los valores a una cofiguración absurda, es decir, vacía*/
	(*j)->id=-1;
	(*j)->nombre=NULL;
	(*j)->localizacion=-1;
	(*j)->maxObjetos=-1;
	((*j)->inv)=creaInventario();

return OK;	/*Finalizació correcta*/
}

/*
Nombre: destruyeJugador
Entradas: un puntero al puntero de un JUGADOR que se desea destruir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: NINGUNO
*/
STATUS destruyeJugador(JUGADOR **j)
{
	if(isJugDestruido(*j)==TRUE)
		return OK;
	if((*j)->nombre)
		free((*j)->nombre);
	destruyeInventario(&((*j)->inv));

	free(*j);
	*j=NULL;

return OK;	/*Finalización correcta*/
}

/*
Nombre: cambiaIdJug
Entradas: un puntero al JUGADOR a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaIdJug(JUGADOR *j, ID id)
{
	if(isJugDestruido(j)==TRUE||id<0)
		return ERR;	/*Error X, error de parámetros*/

	j->id=id;

	if(id!=j->id)
		return ERR;	/*Error Z, error al copiar el dato*/

return OK;	/*Finalización correcta*/
}

/*
Nombre: cambiaNombreJug
Entradas: un puntero al JUGADOR a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error A: Fallo en la reserva de memoria
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaNombreJug(JUGADOR *j, char *nombre)
{
	if(isJugDestruido(j)==TRUE||nombre==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/
		
	if(j->nombre)
		free(j->nombre);
		
	j->nombre=(char *)calloc(strlen(nombre)+1,sizeof(char));
	
	if(!(j->nombre))
		return ERR;	/*Error A, no se ha reservado memoria para la cadena*/

	 strcpy(j->nombre,nombre);
	if(strcmp(j->nombre,nombre)!=0)
		return ERR;	/*Error Z, la cadena no se ha copiado correctamente*/

return OK;	/*Finalización correcta*/
}

/*
Nombre: cambiaLocalizacionJug
Entradas: un puntero al JUGADOR a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaLocalizacionJug(JUGADOR *j, ID id)
{
	if(isJugDestruido(j)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	j->localizacion=id;

	if(j->localizacion!=id)
		return ERR;	/*Error Z, el dato no se ha copiado correctamente*/

return OK;	/*Finalización correcta*/
}

/*
Nombre: cambiaLocalizacionJug
Entradas: un puntero al JUGADOR a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaMaxObjetos(JUGADOR *j, int num)
{
	if(isJugDestruido(j)==TRUE||num<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	j->maxObjetos=num;

	if(j->maxObjetos!=num)
		return ERR;	/*Error Z, el dato no se ha copiado correctamente*/

return OK;	/*Finalización correcta*/
}

/*
Nombre: isJugDestruido
Entradas: un puntero al JUGADOR a mirar
Salidas: Devuelve un BOOL según si cumple unas condiciones. (Se especifican en el .c)
Posibles errores: NINGUNO
*/
BOOL isJugDestruido(JUGADOR *j)
{
	if(j==NULL) return TRUE;	/*El jugador no existe, está destruido*/

return FALSE;	/*Si el puntero no es NULL se considera que hay algo guardado, y por tanto no está destruido*/
}

/*
Nombre: isJugEmpty
Entradas: un puntero al JUGADOR a mirar
Salidas: Devuelve un BOOL según si cumple unas condiciones. (Se especifican en el .c)
Posibles errores: NINGUNO
*/
BOOL isJugEmpty(JUGADOR *j)
{
	if(isJugDestruido(j)==TRUE)
		return TRUE;

	/*Comprobamos que todos los campos están recién incializados*/
	if(j->id!=-1)
		return FALSE;
	else if(j->nombre!=NULL)
		return FALSE;
	else if(j->localizacion!=-1)
		return FALSE;
	else if(j->maxObjetos!=-1)
		return FALSE;
	else if(vacioInventario(j->inv)==FALSE)
		return FALSE;

return TRUE;
}

/*
Nombre: saberIdJug
Entradas: un puntero al JUGADOR a mirar y un puntero a un ID donde guardar el dato
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberIdJug(JUGADOR *j, ID *id)
{
	if(isJugEmpty(j)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(j->id<0)
		return ERR;	/*Error Y, el campo no está relleno*/

	*id=j->id;

return OK;	/*Finalización correcta*/
}

/*
Nombre: saberNombreJug
Entradas: un puntero al JUGADOR a mirar y un puntero a una cadena donde guardar el nombre
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberNombreJug(JUGADOR *j, char *nombre)
{
	if(isJugEmpty(j)==TRUE||nombre==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(j->nombre==NULL)
		return ERR;	/*Error Y, el campo no está completo*/

	strcpy(nombre,j->nombre);

return OK;	/*Finalización correcta*/
}

/*
Nombre: saberLugarJug
Entradas: un puntero al JUGADOR a mirar y un puntero a un ID donde guardar el dato
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberLugarJug(JUGADOR *j, ID *id)
{
	if(isJugEmpty(j)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no so correctos*/

	if(j->localizacion<0)
		return ERR;	/*Error Y, el campo no está completado*/

	*id=j->localizacion;

return OK;	/*Finalización completa*/
}

/*
Nombre: saberNombreJug
Entradas: un puntero al JUGADOR a mirar y un puntero a un entero donde guardar el dato
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberMaxObjetos(JUGADOR *j, int *num)
{
	if(isJugEmpty(j)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(j->maxObjetos<0)
		return ERR;	/*Error Y, el campo no está relleno*/

	*num=j->maxObjetos;

return OK;	/*Finalización correcta*/
}

/*
Nombre: saberTamJugNombre
Entradas: un puntero a un jugador y un puntero a un entero donde guardar el tamaño
Salidas: Devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberTamJugNombre(JUGADOR *j, int *num)
{
	if(isJugEmpty(j)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(j->nombre==NULL)
		return ERR;	/*Error Y, el campo no está relleno*/

	*num=strlen(j->nombre);

return OK;	/*Finalización correcta*/
}

	/*Funciones de manejo de INVENTARIO*/

/*
Nombre: tamInventario
Entradas: un puntero al JUGADOR y un puntero a un entero donde guardar el dato
Salidas: Devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error D: Fallo en las funciones de INVENTARIO
*/
STATUS tamInventario(JUGADOR *j, int *num)
{
	if(isJugDestruido(j)==TRUE||num==NULL)
		return ERR;	/*Error X, los punteros no son correctos*/

	*num=tamanioInventario((j->inv));
	if(*num<0)
		return ERR;	/*Error D, la función de INVENTARIO ha fallado*/

return OK;
}

/*
Nombre: isObjInInv
Entradas: un puntero al JUGADOR y una ID de un OBJETO para ver si se encuentra en el inventario
Salidas: Devuelve un valor BOOL que dice si un objeto está (TRUE) o no (FALSE)
Posibles errores:
	- Error X: Fallo en los punteros
*/
BOOL isObjInInv(JUGADOR *j, ID id)
{
	if(isJugDestruido(j)==TRUE||id<0)
		return FALSE;

return estaInventario((j->inv),&id);
}

/*
Nombre: objetoIesimoInv
Entradas: un puntero al JUGADOR y un entero que indicar a un índice en el inventario
Salidas: Devuelve el ID del objeto que haya. Un número menor que 0 en caso de error
Posibles errores:
	- Error X: Fallo en los punteros
	- Error D: Fallo en la función de INVENTARIO
	- Error C: NO se puede leer: el INVENTARIO no es tan grande
*/

ID objetoIesimoInv(JUGADOR *j, int i)
{
	if(isJugDestruido(j)==TRUE||i<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(i>=tamanioInventario(j->inv))
		return ERR;	/*Error C, el parámetro i es demasiado grande*/

return obtenerIdInventario(j->inv,i);	/*Si es menor que cero, Error D, la función de INVETARIO ha fallado*/
}

/*
Nombre: meterObjInInv
Entradas: un puntero al JUGADOR y una ID de un OBJETO que se quiere introducir en el INVENTARIO
Salidas: Devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error C: No se puede introducir: Inventario Lleno
	- Error D: Fallo en la función de Inventarios
*/
STATUS meterObjInInv(JUGADOR *j, ID id)
{
	if(isJugDestruido(j)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(tamanioInventario((j->inv))==j->maxObjetos)
		return ERR;	/*Error C, el inventario está lleno*/
	
	if(insertaInventario((j->inv),&id)==ERR)
		return ERR;	/*Error D, la función de INVENTARIO ha dado problemas*/

return OK;	/*Finalización correcta*/
}

/*
Nombre: sacarObjInInv
Entradas: un puntero al JUGADOR y una ID de un OBJETO que se quiere sacar del INVENTARIO
Salidas: Devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error C: No se puede sacar: No está
	- Error D: Fallo en la función de Inventarios
*/
STATUS sacarObjInInv(JUGADOR *j, ID id){

	if(isJugDestruido(j)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/
	
	if(estaInventario((j->inv),&id)==FALSE)
		return ERR;	/*Error C, el objeto no está, por lo que no se puede sacar*/

	if(extraeInventario((j->inv),id)==ERR)
		return ERR;	/*Error D, la función de INVENTARIO ha dado un fallo*/

return OK;	/*Finalización correcta*/
}
