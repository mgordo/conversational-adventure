/*****************************************/
/* @file espacio.c*/
/* Fichero que contiene el código del las funciones de ESPACIO*/
/* @author Antonio Jimenez y Miguel Gordo*/
/* @version 0.0*/

#include "espacio.h"

/*Funciones públicas*/

/*
Nombre: creaEspacio
Entradas: un puntero al puntero donde se quiere guardar el espacio
Salidas: Devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
*/
STATUS creaEspacio(ESPACIO **e)
{
	if(isEspDestruido(*e)==FALSE)
		return ERR;	/*Error X, el espacio contiene datos*/

	*e=(ESPACIO *)calloc(1,sizeof(ESPACIO));
	
	(*e)->descGrafica=NULL;
	(*e)->filas=-1;
	(*e)->columnas=-1;
	(*e)->id=-1;
	(*e)->descripcion=NULL;
	(*e)->descExaminar=NULL;
	(*e)->inv=creaInventario();
	(*e)->luminoso=FALSE;
	(*e)->norte=-1;
	(*e)->sur=-1;
	(*e)->este=-1;
	(*e)->oeste=-1;
	(*e)->arriba=-1;
	(*e)->abajo=-1;

return OK;
}

/*
Nombre: destruyeEspacio
Entradas: un puntero al puntero que se quiere destruir
Salidas: devuelve el resultado de la operación
Posibles errores:
*/
STATUS destruyeEspacio(ESPACIO **e)
{
	if(isEspDestruido(*e)==TRUE)
		return OK;

	if((*e)->descripcion)
		free((*e)->descripcion);
	if((*e)->descExaminar)
		free((*e)->descExaminar);
	destruyeInventario(&((*e)->inv));
	if((*e)->descGrafica){
		free((*e)->descGrafica[0]);
		free((*e)->descGrafica);
	}
	free(*e);

	*e=NULL;

return OK;
}

STATUS cambiaEspDescGrafica(ESPACIO *e,char *dibujo,int filas,int columnas){
	
	int i=0,j=0,t=0;
	if(e==NULL || dibujo==NULL || filas<=0 || columnas<=0) return ERR;
	
	if(e->descGrafica){
		free(e->descGrafica[0]);
		free(e->descGrafica);
		e->filas=-1;
		e->columnas=-1;
	}
	
	e->filas=filas;
	e->columnas=columnas;
	
	if(!(e->descGrafica=(char **) calloc(e->filas,sizeof(char *)))){
			return ERR;
		}
		
	if(!(e->descGrafica[0]=(char *)calloc(filas*columnas,sizeof(char)))){
		free(e->descGrafica);
		return ERR;
	}
	
	for(i=1;i<e->filas;i++)
		e->descGrafica[i]=&(e->descGrafica[0][i*columnas]);
	for(i=0;i<e->filas;i++){
		for(j=0;j<e->columnas;j++){
			e->descGrafica[i][j]=dibujo[t];
			t++;
		}
	}
	return OK;
}

/*
Nombre: cambiaEspId
Entradas: un puntero al espacio a modificar y un ID
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspId(ESPACIO *e, ID id)
{
	if(isEspDestruido(e)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->id=id;

	if(e->id!=id)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK; 
}

/*
Nombre: cambiaEspDescripcion
Entradas: un puntero al espacio a modificar y una cadena con la descripción
Salidas: El resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error A: Fallo en la reserva de memoria
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspDescripcion(ESPACIO *e, char *desc)
{
	if(isEspDestruido(e)==TRUE||desc==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descripcion)
		free(e->descripcion);

	e->descripcion=(char *)calloc(strlen(desc)+1,sizeof(char));
	if(!(e->descripcion))
		return ERR;	/*Error A, no se ha reservado memoria*/

	strcpy(e->descripcion,desc);

	if(strcmp(e->descripcion,desc)!=0)
		return ERR;	/*Error Y, no se ha copiado el dato*/

return OK;
}

/*
Nombre: cambiaEspDescExaminar
Entradas: un puntero al espacio a modificar y una cadena con la descripción
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error A: Fallo en la reserva de memoria
	- Error Y: Fallo al copiar el dato
*/	
STATUS cambiaEspDescExaminar(ESPACIO *e, char *desc)
{
	if(isEspDestruido(e)==TRUE||desc==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descExaminar)
		free(e->descExaminar);

	e->descExaminar=(char *)calloc(strlen(desc)+1,sizeof(char));
	if(!(e->descExaminar))
		return ERR;	/*Error A, no se ha reservado memoria*/

	strcpy(e->descExaminar,desc);

	if(strcmp(e->descExaminar,desc)!=0)
		return ERR;	/*Error Y, no se ha copiado el dato*/

return OK;
}

/*
Nombre: cambiaEspLuminoso
Entradas: un puntero al espacio a modificar y un BOOL con el valor que se desea introducir
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Falo al copiar el dato
*/
STATUS cambiaEspLuminoso(ESPACIO *e, BOOL luz)
{
	if(isEspDestruido(e)==TRUE)
		return ERR;	/*Error X, no hay espacio en el que guardar el dato*/

	e->luminoso=luz;

	if((e->luminoso)!=luz)
		return ERR;	/*Error Y, no se ha copiado bien el dato*/

return OK;
}

/*
Nombre: cambiaEspNorte
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión norte
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspNorte(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->norte=n;

	if(e->norte!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: cambiaEspSur
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión sur
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspSur(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->sur=n;

	if(e->sur!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: cambiaEspEste
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión este
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspEste(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->este=n;

	if(e->este!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: cambiaEspOeste
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión oeste
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspOeste(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->oeste=n;

	if(e->oeste!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: cambiaEspArriba
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión arriba
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspArriba(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->arriba=n;

	if(e->arriba!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: cambiaEspAbajo
Entradas: un puntero al espacio a modificar y un ID de la unión a poner como unión abajo
Salidas: el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo al copiar el dato
*/
STATUS cambiaEspAbajo(ESPACIO *e, ID n)
{
	if(isEspDestruido(e)==TRUE||n<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

	e->abajo=n;

	if(e->abajo!=n)
		return ERR;	/*Error Y, el dato no se ha copiado bien*/

return OK;
}

/*
Nombre: isEspDestruido
Entradas: un puntero al espacio a comprobar
Salidas: Devuelve un valor BOOL que indica si el espacio está o no destruido
Posibles errores:
*/
BOOL isEspDestruido(ESPACIO *e)
{
	if(e==NULL)
		return TRUE;

return FALSE;
}

/*
Nombre: isEspEmpty
Entradas: un puntero al espacio a comprobar
Salidas: Devuelve un valor BOOL que indica si el espacio está o no vacío
Posibles errores:
*/
BOOL isEspEmpty(ESPACIO *e)
{
	if(isEspDestruido(e)==TRUE)
		return TRUE;

	if(e->id>=0)
		return FALSE;
	if(e->descripcion!=NULL)
		return FALSE;
	if(e->descExaminar!=NULL)
		return FALSE;
	if(vacioInventario(e->inv)==FALSE)
		return FALSE;
	if(e->norte>=0||e->sur>=0||e->este>=0||e->oeste>=0||e->arriba>=0||e->abajo>=0)
		return FALSE;
	if(e->luminoso!=FALSE)
		return FALSE;

return TRUE;
}

/*
Nombre: isEspLuminoso
Entradas: un puntero al espacio a comprobar
Salidas: Devuelve un valor BOOL que indica si el espacio está iluminado o no
Posibles errores:
	Si el espacio está destruido, se devuelve como si el espacio estuviese oscuro
*/
BOOL isEspLuminoso(ESPACIO *e)
{
	if(isEspDestruido(e)==TRUE)
		return FALSE;

return e->luminoso;
}

/*
Nombre: saberEspId
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo
*/
STATUS saberEspId(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->id<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->id;

return OK;
}

/*
Nombre: saberEspDescripcion
Entradas: un puntero al espacio del que se quiere la información y una cadena donde almacenarlo
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Z: Fallo en el campo
*/
STATUS saberEspDescripcion(ESPACIO *e, char *desc)
{
	if(isEspEmpty(e)==TRUE||desc==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descripcion==NULL)
		return ERR;	/*Error Y, el campo no está completo*/

	strcpy(desc,e->descripcion);

return OK;
}

/*
Nombre: saberEspDescExaminar
Entradas: un puntero al espacio del que se quiere la información y una cadena donde almacenarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Z: Fallo en el campo
*/
STATUS saberEspDescExaminar(ESPACIO *e, char *desc)
{

	if(isEspEmpty(e)==TRUE||desc==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descExaminar==NULL)
		return ERR;	/*Error Y, el campo no está completo*/

	strcpy(desc,e->descExaminar);

return OK;
}

/*
Nombre: saberEspDescrGrafica
Entradas: un puntero al espacio del que se quiere la información, una cadena donde almacenarla y el tamaño de dibujo
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Z: Fallo en el campo
*/
STATUS saberEspDescrGrafica(ESPACIO *esp,char ***dibujo,int *filas, int *columnas){
		int i=0, j=0;
	
	if(!esp || !dibujo || !filas || !columnas) return ERR;
	
	*filas=esp->filas;
	*columnas=esp->columnas;
	
	if(!((*dibujo)=(char **) calloc(esp->filas,sizeof(char *)))){
			return ERR;
		}
		
	if(!(((*dibujo)[0])=(char *)calloc(esp->filas*esp->columnas,sizeof(char)))){
		free((*dibujo));
		return ERR;
	}
	
	for(i=1;i<esp->filas;i++)
		(*dibujo)[i]=&((*dibujo)[0][i*esp->columnas]);
	for(i=0;i<esp->filas;i++){
		for(j=0;j<esp->columnas;j++){
			(*dibujo)[i][j]=esp->descGrafica[i][j];
		}
	}
	return OK;
}


/*
Nombre: saberEspTamDesc
Entradas: un puntero al espacio del que se quiere la información y un puntero al entero donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
*/
STATUS saberEspTamDesc(ESPACIO *e, int *num)
{
	if(isEspDestruido(e)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descripcion==NULL)
		*num=0;
	else
		*num=strlen(e->descripcion);

return OK;
}

/*
Nombre: saberEspTamDescExam
Entradas: un puntero al espacio del que se quiere la información y un puntero al entero donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
*/
STATUS saberEspTamDescExam(ESPACIO *e, int *num)
{
	if(isEspDestruido(e)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->descExaminar==NULL)
		*num=0;
	else
		*num=strlen(e->descExaminar);

return OK;
}

/*
Nombre: saberEspNorte
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspNorte(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->norte<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->norte;

return OK;
}

/*
Nombre: saberEspSur
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspSur(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->sur<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->sur;

return OK;
}

/*
Nombre: saberEspEste
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspEste(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->este<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->este;

return OK;
}

/*
Nombre: saberEspOeste
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspOeste(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->oeste<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->oeste;

return OK;
}

/*
Nombre: saberEspArriba
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspArriba(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->arriba<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->arriba;

return OK;
}

/*
Nombre: saberEspAbajo
Entradas: un puntero al espacio del que se quiere la información y un puntero a una ID donde guardarla
Salidas: devuelve el resultado de la operación
Posibles errores:
	- Error X: Fallo en los punteros
	- Error Y: Fallo en el campo -> No existe la unión
*/
STATUS saberEspAbajo(ESPACIO *e, ID *id)
{
	if(isEspEmpty(e)==TRUE||id==NULL)
		return ERR;	/*Error X, los parámetros no son correctos*/

	if(e->abajo<0)
		return ERR;	/*Error Y, el campo no está competo*/

	*id=e->abajo;

return OK;
}

	/*Funciones de manejo del inventario*/

/*
Nombre: sacarEspObj
Entradas: un puntero al espacio que se quiere modificar y una ID del objeto que se quiere sacar
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error C: El objeto no está en el inventario
	- Error D: Fallo en la función de INVENTARIO
*/
STATUS sacarEspObj(ESPACIO *e, ID id)
{
	if(isEspEmpty(e)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros no son correctos*/

return extraeInventario((e->inv),id);
}

/*
Nombre: meterEspObj
Entradas: un puntero al espacio a modificar y una ID dl objeto que se quiere introducir
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error D: FAllo en la función de INVENTARIO
*/
STATUS meterEspObj(ESPACIO *e, ID id)
{
	if(isEspEmpty(e)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/
return insertaInventario((e->inv),&id);
}

/*
Nombre: saberEspTamInv
Entradas: un puntero al espacio que se quiere comprobar y un puntero al número donde guardar la información
Salidas: devuelve el resultado de la operación
Posibles errores: 
	- Error X: Fallo en los punteros
	- Error D: Fallo en la función de INVENTARIO
*/
STATUS saberEspTamInv(ESPACIO *e, int *num)
{
	if(isEspEmpty(e)==TRUE||num==NULL)
		return ERR;	/*Error X, los parámetros son incorrectos*/

	*num=tamanioInventario((e->inv));
return OK;
}

/*
Nombre: isObjinEsp
Entradas: el puntero a un espacio que se quiera comprobar y la id del objeto a mirar
Salidas: un valor BOOL que indica si el objeto está o no
Posibles errores:
	- Error X: Fallo en los punteros
*/
BOOL isObjinEsp(ESPACIO *e, ID id)
{
	if(isEspEmpty(e)==TRUE||id<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

return estaInventario((e->inv), &id);
}

/*
Nombre: saberEspIesimoObj
Entradas: un puntero al espacio que se quiere mirar y el índice que se quiere mirar
Salidas: devuelve la ID del objeto que se encuentre en esa posición
Posibles errores: 
	- Error X: Fallo en los punteros (-1)
	- Error D: Fallo en la función de INVENTARIO (-1)
*/
ID saberEspIesimoObj(ESPACIO *e, int i)
{
	if(isEspEmpty(e)==TRUE||i<0)
		return ERR;	/*Error X, los parámetros son incorrectos*/

return obtenerIdInventario(e->inv, i);
}
