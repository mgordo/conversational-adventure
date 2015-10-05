/*****************************************/
/*Fichero: objeto.c*/
/*Fichero que contiene el código de todas las funciones que permiten manejar un OBJETO*/
/*Autor: Antonio Jimenez*/
/*V 1.0*/

#include "objeto.h"

/*Funciones públicas*/

/*
Nombre: creaObjeto
Entradas: un puntero donde guardar el nuevo objeto. Se modificará al reservar uno nuevo.
Salidas: devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores
	- Error B: El objeto no está destruido
	- Error A: Error al reservar memoria
Reserva toda la memoria necesaria para un OBJETO y la inicializa a vacío
*/
STATUS creaObjeto(OBJETO **o)
{
	if(isObjDestruido(*o)==FALSE)
		return ERR;	/*Error B: El puntero tiene un valor y suponemos que contiene un objeto*/
	*o=(OBJETO *)calloc(1,sizeof(OBJETO));
	if(!(*o))
		return ERR;	/*Error A: Error en la reserva de memoria*/
	/*Iniciamos los datos a vacío*/
	(*o)->id=-1;
	(*o)->nombre=NULL;
	(*o)->descripcion=NULL;
	(*o)->descMovido=NULL;
	(*o)->descExaminar=NULL;
	(*o)->movil=FALSE;
	(*o)->movido=FALSE;
	(*o)->oculto=FALSE;
	(*o)->encendido=FALSE;
	(*o)->luz=FALSE;
	(*o)->contenedor=FALSE;
	(*o)->inv=creaInventario();

return OK;
}

/*
Nombre: destruyeObjeto
Entradas: un puntero al OBJETO que destruir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Libera toda la memoria reservada para un OBJETO y pone el puntero a NULL
*/
STATUS destruyeObjeto(OBJETO **o)
{
	if(isObjDestruido(*o)==TRUE)
		return OK;
	if((*o)->nombre!=NULL)
		free((*o)->nombre);
	if((*o)->descripcion!=NULL)
		free((*o)->descripcion);
	if((*o)->descMovido!=NULL)
		free((*o)->descMovido);
	if((*o)->descExaminar!=NULL)
		free((*o)->descExaminar);
	destruyeInventario(&((*o)->inv));
	free((*o));
	*o=NULL;

return OK;
}

/*
Nombre: cambiaIdObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaIdObj(OBJETO *o, ID id)
{
	if(isObjDestruido(o)==TRUE)
		return ERR;	/*Error X, los punteros no son válidos*/

	o->id=id;
	if(id!=o->id)
		return ERR;	/*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaNombreObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay tres tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
	- Error A: Fallo en la reserva de memoria
*/
STATUS cambiaNombreObj(OBJETO *o, char *nombre)
{
	if(isObjDestruido(o)==TRUE||nombre==NULL)
		return ERR;	/*Error X, los punteros no son válidos*/

	if(o->nombre!=NULL)
		free(o->nombre);

	o->nombre=(char *)calloc(strlen(nombre)+1,sizeof(char));
	if(!o) 
		return ERR;	/*Error A, no hay memoria*/

	strcpy(o->nombre, nombre);
	if(strcmp(nombre,o->nombre)!=0)
		return ERR;	/*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaDescripcionObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
	- Error A: Fallo en la reserva de memoria
*/
STATUS cambiaDescripcionObj(OBJETO *o, char *descr)
{
	if(isObjDestruido(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son válidos*/

	if(o->descripcion!=NULL)
		free(o->descripcion);

	o->descripcion=(char *)calloc(strlen(descr)+1,sizeof(char));
	if(!o) 
		return ERR;	/*Error A, no hay memoria*/

	strcpy(o->descripcion, descr);
	if(strcmp(descr,o->descripcion)!=0)
		return ERR;	/*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaDescrMovido
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
	- Error A: Fallo en la reserva de memoria
*/
STATUS cambiaDescrMovido(OBJETO *o, char *descr)
{
	if(isObjDestruido(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son válidos*/

	if(o->descMovido!=NULL)
		free(o->descMovido);

	o->descMovido=(char *)calloc(strlen(descr)+1,sizeof(char));
	if(!o) 
		return ERR;	/*Error A, no hay memoria*/

	strcpy(o->descMovido, descr);
	if(strcmp(descr,o->descMovido)!=0)
		return ERR;	/*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaDecrExamObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
	- Error A: Fallo en la reserva de memoria
*/
STATUS cambiaDescrExamObj(OBJETO *o, char *descr)
{
	if(isObjDestruido(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son válidos*/

	if(o->descExaminar!=NULL)
		free(o->descExaminar);

	o->descExaminar=(char *)calloc(strlen(descr)+1,sizeof(char));
	if(!o) 
		return ERR;	/*Error A, no hay memoria*/

	strcpy(o->descExaminar, descr);
	if(strcmp(descr,o->descExaminar)!=0)
		return ERR;	/*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaMovil
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaMovil(OBJETO *o, BOOL movil)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->movil=movil;
	if(o->movil!=movil)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaMovido
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaMovido(OBJETO *o, BOOL movido)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->movido=movido;
	if(o->movido!=movido)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaOculto
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaOculto(OBJETO *o, BOOL oculto)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->oculto=oculto;
	if(o->oculto!=oculto)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaEncendido
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaEncendido(OBJETO *o, BOOL encendido)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->encendido=encendido;
	if(o->encendido!=encendido)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaLuz
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaLuz(OBJETO *o, BOOL luz)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->luz=luz;
	if(o->luz!=luz)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: cambiaContenedor
Entradas: un puntero al OBJETO a mirar y un valor BOOL a introducir
Salidas: Devuelve un STATUS con el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Z: Fallo al copiar el dato
*/
STATUS cambiaContenedor(OBJETO *o, BOOL contenedor)
{
	if(isObjDestruido(o)==TRUE)
		return ERR; /*Error X, punteros no válidos*/

	o->contenedor=contenedor;
	if(o->contenedor!=contenedor)
		return ERR; /*Error Z, fallo al copiar el dato*/

return OK;
}

/*
Nombre: isMovil
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Comprueba si el OBJETO es Movil o no
*/
BOOL isMovil(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->movil;
}

/*
Nombre: isMovido
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Comprueba si el OBJETO ha sido movido o no
*/
BOOL isMovido(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->movido;
}

/*
Nombre: isOculto
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Comprueba si el OBJETO está oculto o no
*/
BOOL isOculto(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->oculto;
}

/*
Nombre: isEncendido
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
*/
BOOL isEncendido(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->encendido;
}

/*
Nombre: isLuz
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
*/
BOOL isLuz(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->luz;
}

/*
Nombre: isContenedor
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL como resultado de la operación
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
*/
BOOL isContenedor(OBJETO *o)
{
	if(isObjDestruido(o)==TRUE)
		return FALSE;

return o->contenedor;
}

/*
Nombre: isObjDestruido
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL según si cumple unas condiciones.
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Comprueba si el objeto está destruido o no
*/
BOOL isObjDestruido(OBJETO *o)
{
	if(o==NULL)
		return TRUE;

return FALSE;
}

/*
Nombre: isObjEmpty
Entradas: un puntero al OBJETO a mirar
Salidas: Devuelve un BOOL según si cumple unas condiciones.
Posibles errores: Hay un tipo de error.
	- Error X: Fallo en los punteros
Averigua si el OBJETO está en el mismo estado que recién creado
*/
BOOL isObjEmpty(OBJETO *o)
{
	if (isObjDestruido(o)==TRUE)
		return TRUE;

	if(o->id>0)
		return FALSE;
	if(o->nombre!=NULL||o->descripcion!=NULL||o->descMovido!=NULL||o->descExaminar!=NULL)
		return FALSE;
	if(o->movil==TRUE||o->movido==TRUE||o->oculto==TRUE||o->luz==TRUE||o->encendido==TRUE||o->contenedor==TRUE)
		return FALSE;

return TRUE;
}

/*
Nombre: saberNombreObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena donde guardar el nombre
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
Copia en nombre el contenido del campo nombre del OBJETO
*/
STATUS saberNombreObj(OBJETO *o, char *nombre)
{
	if(isObjEmpty(o)==TRUE||nombre==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->nombre==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	strcpy(nombre,o->nombre);

return OK;
}

/*
Nombre: saberTamNombreObj
Entradas: un puntero al OBJETO a mirar y un puntero a un entero donde guardar el dato
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberTamNombreObj(OBJETO *o, int *num)
{
	if(isObjEmpty(o)==TRUE||num==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->nombre==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	*num=strlen(o->nombre);

return OK;	
}

/*
Nombre: saberDescrObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena donde guardar la descripción
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
Copia en descr el contenido del campo descripcion del OBJETO
*/
STATUS saberDescrObj(OBJETO *o, char *descr)
{
	if(isObjEmpty(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descripcion==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	strcpy(descr,o->descripcion);

return OK;
}

/*
Nombre: saberTamDescrObj
Entradas: un puntero al OBJETO a mirar y un puntero a un entero donde guardar el dato
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberTamDescrObj(OBJETO *o, int *num)
{
	if(isObjEmpty(o)==TRUE||num==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descripcion==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	*num=strlen(o->descripcion);

return OK;	
}

/*
Nombre: saberDescrMovido
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena donde guardar la descripción
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
Copia en descr el contenido del campo descMovido del OBJETO
*/
STATUS saberDescrMovido(OBJETO *o, char *descr)
{
	if(isObjEmpty(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descMovido==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	strcpy(descr,o->descMovido);

return OK;
}

/*
Nombre: saberTamDescrMovido
Entradas: un puntero al OBJETO a mirar y un puntero a un entero donde guardar el dato
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberTamDescrMovido(OBJETO *o, int *num)
{
	if(isObjEmpty(o)==TRUE||num==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descMovido==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	*num=strlen(o->descMovido);

return OK;	
}

/*
Nombre: saberDescrExamObj
Entradas: un puntero al OBJETO a mirar y un puntero a una cadena donde guardar la descripción
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
Copia en descr el contenido del campo descExaminar del OBJETO
*/
STATUS saberDescrExamObj(OBJETO *o, char *descr)
{
	if(isObjEmpty(o)==TRUE||descr==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descExaminar==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	strcpy(descr,o->descExaminar);

return OK;
}

/*
Nombre: saberTamDescrExamObj
Entradas: un puntero al OBJETO a mirar y un puntero a un entero donde guardar el dato
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberTamDescrExamObj(OBJETO *o, int *num)
{
	if(isObjEmpty(o)==TRUE||num==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->descExaminar==NULL)
		return ERR;	/*Error Y, el campo está vacío*/

	*num=strlen(o->descExaminar);

return OK;	
}

/*
Nombre: saberIdObj
Entradas: un puntero al OBJETO a mirar y un puntero a la ID donde guardar el id del objeto
Salidas: Devuelve un STATUS que indica el resultado de la operación
Posibles errores: Hay dos tipos de errores.
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
Copia en id el contenido del campo id del OBJETO
*/
STATUS saberIdObj(OBJETO *o, ID *id)
{
	if(isObjEmpty(o)==TRUE||id==NULL)
		return ERR;	/*Error X, los punteros no son aceptables*/

	if(o->id<0)
		return ERR; /*Error Y, el campo no está relleno*/

	*id=o->id;

return OK;
}

	/*Funciones de manejo del inventario*/

/*
Nombre: sacarObjObj
Entradas: un puntero al objeto que se quiere modificar y una ID del objeto que se quiere sacar
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error C: El objeto no está en el inventario
	- Error D: Fallo en la función de INVENTARIO
*/
STATUS sacarObjObj(OBJETO *o, ID id)
{
	if(isObjEmpty(o)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

return extraeInventario((o->inv),id);
}

/*
Nombre: meterObjObj
Entradas: un puntero al objeto a modificar y una ID dl objeto que se quiere introducir
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error D: FAllo en la función de INVENTARIO
*/
STATUS meterObjObj(OBJETO *o, ID id)
{
	if(isObjEmpty(o)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/
return insertaInventario((o->inv),&id);
}

/*
Nombre: saberObjTamInv
Entradas: un puntero al objeto que se quiere comprobar y un puntero al número donde guardar la información
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error D: Fallo en la función de INVENTARIO
*/
STATUS saberObjTamInv(OBJETO *o, int *num)
{
	if(isObjEmpty(o)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	*num=tamanioInventario((o->inv));
return OK;
}

/*
Nombre: isObjinObj
Entradas: el puntero a un objeto que se quiera comprobar y la id del objeto a mirar
Salidas: un valor BOOL que indica si el objeto está o no
Posibles errores:
	- Error X: Fallo en los punteros
*/
BOOL isObjinObj(OBJETO *o, ID id)
{
	if(isObjEmpty(o)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

return estaInventario((o->inv), &id);
}

/*
Nombre: saberObjIesimoObj
Entradas: un puntero al objeto que se quiere mirar y el índice que se quiere mirar
Salidas: devuelve la ID del objeto que se encuentre en esa posición
Posibles errores: 
	- Error X: Fallo en los punteros (-1)
	- Error D: Fallo en la función de INVENTARIO (-1)
*/
ID saberObjIesimoObj(OBJETO *o, int i)
{
	if(isObjEmpty(o)==TRUE||i<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

return obtenerIdInventario(o->inv, i);
}
