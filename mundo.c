/**/
/* @brief Utilidades para crear y modificar el mundo*/
/**/
/* Este modulo contiene las funciones para todas las acciones posibles respecto al mundo*/
/**/
/* @file mundo.c*/
/* @author Carlos Carrascal*/
/* @version 1.0*/
/* @date 02-11-2010*/
/**/


#include "mundo.h"


/****************************************/
/*Funciones básicas del mundo************/
/****************************************/


MUNDO * nuevoMundo(int numesp, int numobj, int numjug, int numuni)
{
	MUNDO *mundo=NULL;
	
	mundo=(MUNDO *)calloc(1,sizeof(MUNDO));
	
	if(mundo==NULL)
		return NULL;

	mundo->numesp=numesp;
	mundo->numobj=numobj;
	mundo->numjug=numjug;
	mundo->numuni=numuni;

	mundo->objetos=(OBJETO **)calloc(numobj, sizeof(OBJETO *));

	if(mundo->objetos==NULL)
	{
		free(mundo);	
		return NULL;
	}
	mundo->espacios=(ESPACIO **)calloc(numesp, sizeof(ESPACIO *));

	if(mundo->espacios==NULL)
	{	
		free(mundo->objetos);
		free(mundo);	
		return NULL;
	}
	mundo->jugador=(JUGADOR **)calloc(numjug, sizeof(JUGADOR *));

	if(mundo->jugador==NULL)
	{	
		free(mundo->espacios);
		free(mundo->objetos);
		free(mundo);	
		return NULL;
	}

	mundo->uniones=(UNION **)calloc(numuni, sizeof(UNION *));

	if(mundo->uniones==NULL)
	{	
		free(mundo->jugador);
		free(mundo->espacios);
		free(mundo->objetos);
		free(mundo);	
		return NULL;
	}

	return mundo;
}


void destruyeMundo(MUNDO ** m)
{
	int i=0;

	if(m==NULL || *m==NULL)
		return;

	for(i=0;i<(*m)->numesp;i++)
	{
		if((*m)->espacios[i]!=NULL)
			destruyeEspacio(&((**m).espacios[i]));
	}
	for(i=0;i<(*m)->numobj;i++)
	{
		if((*m)->objetos[i]!=NULL)
			destruyeObjeto(&((**m).objetos[i]));
	}

	for(i=0;i<(*m)->numjug;i++)
	{
		if((*m)->jugador[i]!=NULL)
			destruyeJugador(&((**m).jugador[i]));
	}

	for(i=0;i<(*m)->numuni;i++)
	{
		if((*m)->uniones[i]!=NULL)
			destruyeUnion(&((**m).uniones[i]));
	}
	
	if((*m)->espacios)
		free((*m)->espacios);
	if((*m)->jugador)
		free((*m)->jugador);
	if((*m)->objetos)
		free((*m)->objetos);
	if((*m)->uniones)
		free((*m)->uniones);	
	
	
	free(*m);
	*m=NULL;
return;
}

STATUS saberNumJug(MUNDO *m, int *num)
{
	if(m==NULL || num==NULL)
		return ERR;
		
	(*num)=(m->numjug);
	
	return OK;
}

STATUS saberNumObj(MUNDO *m, int *num)
{
	if(m==NULL || num==NULL)
		return ERR;
		
	(*num)=(m->numobj);
	
	return OK;
}

STATUS saberNumEsp(MUNDO *m, int *num)
{
	if(m==NULL || num==NULL)
		return ERR;
		
	(*num)=(m->numesp);
	
	return OK;
}

STATUS saberNumUni(MUNDO *m, int *num)
{
	if(m==NULL || num==NULL)
		return ERR;
		
	(*num)=(m->numuni);
	
	return OK;
}

/****************************************/
/*Funciones básicas para crear objetos***/
/****************************************/


STATUS guardaObj(MUNDO *m, OBJETO * objeto)
{
	int i=0;

	if(m==NULL || objeto==NULL)
		return ERR;
	
	while(i<m->numobj && m->objetos[i]!=NULL)
		i++;

	if(i==m->numobj)
		return ERR;

	m->objetos[i]=objeto;

	return OK;
}


STATUS creaObj(OBJETO ** objeto)
{
	return creaObjeto(objeto);
}


STATUS destruyeObj(OBJETO ** objeto)
{
	return destruyeObj(objeto);
}


STATUS creaIdObjMundo(OBJETO * objeto, ID id)
{
	return cambiaIdObj(objeto, id);
}


STATUS creaNombreObj(OBJETO * objeto, char * nombre)
{
	return cambiaNombreObj(objeto, nombre);
}


STATUS creaDescObj(OBJETO * objeto, char *descripcion)
{
	return cambiaDescripcionObj(objeto, descripcion);
}


STATUS creaDescMovidoObj(OBJETO * objeto, char * descMovido)
{
	return cambiaDescrMovido(objeto, descMovido);
}


STATUS creaExamObj(OBJETO * objeto, char * examinar)
{
	return cambiaDescrExamObj(objeto, examinar);
}


STATUS creaMovilObj(OBJETO * objeto, BOOL movil)
{
	return cambiaMovil(objeto, movil);
}


STATUS creaMovidoObj(OBJETO * objeto,BOOL movido)
{
	return cambiaMovido(objeto, movido);
}


STATUS creaOcultoObj(OBJETO * objeto, BOOL oculto)
{
	return cambiaOculto(objeto, oculto);
}


STATUS creaEncendidoObj(OBJETO * objeto, BOOL encendido)
{
	return cambiaEncendido(objeto, encendido);
}


STATUS creaContenedorObj(OBJETO * objeto, BOOL contenedor)
{
	return cambiaContenedor(objeto, contenedor);
}


STATUS creaLuzObj(OBJETO * objeto, BOOL luz)
{
	return cambiaLuz(objeto, luz);
}


/****************************************/
/*Funciones para objeto******************/
/****************************************/


OBJETO * dameObjeto(MUNDO * m, ID id)
{
	int i=0;
	ID aux=-1;

	if(m==NULL || id<0)
		return NULL;

	while(i<m->numobj)
	{
		saberIdObj(m->objetos[i], &aux);
		if(aux==id)
			return m->objetos[i];
		i++;
	}	
	return NULL;
}


OBJETO * consigueObjeto(MUNDO * m, char * nombre)
{
	int i=0, auxi=-1;
	char aux[MAX_LEN]="\0";
	
	for(i=0;i<m->numobj;i++)
	{
		saberTamNombreObj(m->objetos[i], &auxi);
		if(auxi>MAX_LEN||auxi<0)
			return NULL;
		
		if(saberNombreObj(m->objetos[i], aux)==ERR)
			return NULL;
	
		if(strcmp(nombre,aux)==0)
			return m->objetos[i];

	}
	
	return NULL;

}


STATUS darNombreObj(OBJETO * objeto, char *nombre)
{
	int aux=-1;

	if(objeto==NULL || nombre==NULL)
		return ERR;
	saberTamNombreObj(objeto,&aux);
	if(aux>MAX_LEN||aux<0)
		return ERR;
	else
		return saberNombreObj(objeto, nombre);
}


ID darLocObj(MUNDO *m, OBJETO * objeto)
{
	ID idobj=-1, idesp=-1;
	int i=0;

	if(saberIdObj(objeto, &idobj)==ERR)
		return -1;
		
	if(idobj<-1)
		return -1;
	
	for(i=0;i<m->numesp;i++)
	{
		if(isObjinEsp(m->espacios[i], idobj)==TRUE)
		{
			if(saberEspId(m->espacios[i], &idesp)==ERR)
				return -1;
			return idesp;	
		}
	}
	return -1;
}


STATUS dameDescrObj(OBJETO * objeto, char *descripcion, int max_len)
{
	int aux=-1;
	if(objeto==NULL || descripcion==NULL || max_len<=0) 
		return ERR;

	if(isMovido(objeto)==FALSE)
	{
		saberTamDescrObj(objeto,&aux);
		if(aux>max_len||aux<0)
			return ERR;
		else
			return saberDescrObj(objeto, descripcion);
	}
	else
	{
		saberTamDescrMovido(objeto,&aux);
		if(aux>max_len||aux<0)
			return ERR;
		else
			return saberDescrMovido(objeto, descripcion);
	}
}

STATUS darDescrexamObj(OBJETO * o, char *descripcion, int max_len)
{
	int i=0;

	if(o==NULL || descripcion==NULL || max_len<=0) 
		return ERR;
	
	if(saberTamDescrExamObj(o, &i)==ERR)
		return ERR;
	if(max_len<i)
		return ERR;	
	else
		return saberDescrExamObj(o, descripcion);
}

STATUS darDescrObj(OBJETO * o, char *descripcion, int max_len)
{
	int i=0;

	if(o==NULL || descripcion==NULL || max_len<=0) 
		return ERR;
	
	if(saberTamDescrObj(o, &i)==ERR)
		return ERR;
	if(max_len<i)
		return ERR;	
	else
		return saberDescrObj(o, descripcion);
}

STATUS darDescrMovidoObj(OBJETO * o, char *descripcion, int max_len)
{
	int i=0;

	if(o==NULL || descripcion==NULL || max_len<=0) 
		return ERR;
	
	if(saberTamDescrMovido(o, &i)==ERR)
		return ERR;

	if(max_len<i)
		return ERR;	
	else
		return saberDescrMovido(o, descripcion);
}

STATUS meterObjOnObj(OBJETO *objeto, ID id)
{
	return meterObjObj(objeto, id);
}

ID darIdObj(OBJETO * o)
{

	ID id=-1;
	saberIdObj(o, &id);
	return id;
}

BOOL darMovilObj(OBJETO * o)
{
	return isMovil(o);
}

BOOL darMovidoObj(OBJETO * o)
{
	return isMovido(o);
}

BOOL darOcultoObj(OBJETO * o)
{
	return isOculto(o);
}

BOOL darEncendidoObj(OBJETO * o)
{
	return isEncendido(o);
}

BOOL darLuzObj(OBJETO * o)
{
	return isLuz(o);
}

BOOL darContenedorObj(OBJETO * o)
{
	return isContenedor(o);
}

BOOL isObjInObjMun(OBJETO * o, ID id)
{
	return isObjinObj(o, id);
}

STATUS sacaObjOfObj(OBJETO *cont, ID obj)
{
	return sacarObjObj(cont,obj);
}


/*****************************************/
/*Funciones básicas para crear un jugador*/
/*****************************************/


STATUS guardaJug(MUNDO *m, JUGADOR * jugador)
{
	int i=0;

	if(m==NULL || jugador==NULL)
		return ERR;
	
	while(i<m->numjug && m->jugador[i]!=NULL)
		i++;

	if(i==m->numjug)
		return ERR;

	m->jugador[i]=jugador;

	return OK;
}


STATUS creaJug(JUGADOR ** jugador)
{
	return creaJugador(jugador);
}


STATUS destruyeJug(JUGADOR ** jugador)
{
	return destruyeJugador(jugador);
}


STATUS creaIdJug(JUGADOR * jugador, ID id)
{
	return cambiaIdJug(jugador, id);
}


STATUS creaNombreJug(JUGADOR * jugador, char * nombre)
{
	return cambiaNombreJug(jugador, nombre);
}


STATUS creaLocJug(JUGADOR * jugador, ID id)
{
	return cambiaLocalizacionJug(jugador, id);
}


STATUS creaMaxObjJug(JUGADOR * jugador, int max)
{
	return cambiaMaxObjetos(jugador, max);
}


STATUS meteObjJug(JUGADOR *jugador, ID id)
{
	return meterObjInInv(jugador, id);
}



/****************************************/
/*Funciones para jugador*****************/
/****************************************/


JUGADOR * dameJugador(MUNDO * m, ID id)
{
	int i=0;
	ID aux=-1;

	if(m==NULL || id<0)
		return NULL;

	while(i<m->numjug)
	{
		saberIdJug(m->jugador[i], &aux);
		if(aux==id)
			return m->jugador[i];
		i++;
	}	
	return NULL;
}


STATUS darNombreJug(JUGADOR *jugador, char *nombre, int max_len)
{
	int aux=-1;

	if(jugador==NULL || nombre==NULL || max_len<=0)
		return ERR;

	saberTamJugNombre(jugador, &aux);
	if(aux==-1)
		return ERR;
	if(aux>max_len)
		return ERR;
	
	return saberNombreJug(jugador, nombre);
}


ID darLocJug(JUGADOR * jugador)
{
	ID espacio=-1;
	saberLugarJug(jugador, &espacio);

	return espacio;	
}


JUGADOR * consigueJugador(MUNDO * m, char * nombre)
{
	int i=0, auxi=-1;
	char aux[MAX_LEN]="\0";
	
	for(i=0;i<m->numjug;i++)
	{
		saberTamJugNombre(m->jugador[i], &auxi);
		if(auxi>MAX_LEN||auxi<0)
			return NULL;
		
		if(saberNombreJug(m->jugador[i], aux)==ERR)
			return NULL;
		
		
		if(strcmp(nombre,aux)==0)
			return m->jugador[i];
	}
	
	return NULL;
}

STATUS dameInvExaminar(MUNDO *m, JUGADOR * jug, char * info)
{
	int i=0, flag=0;
	char nombre[MAX_LEN];

	if(m==NULL || jug==NULL || info==NULL)
		return ERR;
	info[0]='\0';
	sprintf(info, "Tienes: \n");
	for(i=0;i<m->numobj;i++)
	{
		if(isObjInInv(jug, darIdObj(m->objetos[i]))==TRUE)
		{
			if(darNombreObj(dameObjeto(m, darIdObj(m->objetos[i])), nombre)==ERR)
				return ERR;
			strcat(info,nombre);
			strcat(info, ", ");
			flag=1;
		}
	}
	if(flag==0)
		strcat(info, "No tienes ningun objeto");
	else
		info[strlen(info)-2]='\0';
	return OK;
}


ID darIdJug(JUGADOR * j)
{
	ID id=-1;
	saberIdJug(j, &id);
	return id;
}

int darMaxJug(JUGADOR * j)
{
	int n=-1;
	saberMaxObjetos(j, &n);
	return n;
}

BOOL isObjInInvMun(JUGADOR * j, ID id)
{
	return isObjInInv(j, id);
}

STATUS sacaObjOfInv(JUGADOR *cont, ID obj)
{
	return sacarObjInInv(cont,obj);
}

/****************************************/
/*Funciones básicas para crear espacios**/
/****************************************/


STATUS guardaEsp(MUNDO *m, ESPACIO * espacio)
{
	int i=0;

	if(m==NULL && espacio==NULL)
		return ERR;
	
	while(i<m->numesp && m->espacios[i]!=NULL)
		i++;

	if(i==m->numesp)
		return ERR;

	m->espacios[i]=espacio;

	return OK;
}


STATUS creaEsp(ESPACIO ** espacio)
{
	return creaEspacio(espacio);
}


STATUS destruyeEsp(ESPACIO ** espacio)
{
	return destruyeEspacio(espacio);
}


STATUS creaIdEspMundo(ESPACIO * espacio, ID id)
{
	return cambiaEspId(espacio, id);
}


STATUS creaDescEsp(ESPACIO * espacio, char *descripcion)
{
	return cambiaEspDescripcion(espacio, descripcion);
}


STATUS creaDescrGraficaEsp(ESPACIO *espacio,char *dibujo,int filas,int columnas){
	
	return cambiaEspDescGrafica(espacio,dibujo,filas,columnas);
}


STATUS creaExamEsp(ESPACIO * espacio, char * examinar)
{
	return cambiaEspDescExaminar(espacio, examinar);
}


STATUS meteObjEsp(ESPACIO * espacio, ID id)
{
	return meterEspObj(espacio, id);
}


STATUS creaLumEsp(ESPACIO *espacio, BOOL luminoso)
{
	return cambiaEspLuminoso(espacio, luminoso);
}


STATUS creaNorteEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspNorte(espacio, id);
}


STATUS creaSurEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspSur(espacio, id);
}


STATUS creaEsteEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspEste(espacio, id);
}


STATUS creaOesteEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspOeste(espacio, id);
}


STATUS creaArribaEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspArriba(espacio, id);
}


STATUS creaAbajoEsp(ESPACIO * espacio, ID id)
{
	return cambiaEspAbajo(espacio, id);
}


/****************************************/
/*Funciones para espacio*****************/
/****************************************/


STATUS darDescrEsp(ESPACIO * espacio, char *descripcion, int max_len)
{
	int i=0;

	if(espacio==NULL || descripcion==NULL || max_len<=0) 
		return ERR;
	
	if(saberEspTamDesc(espacio, &i)==ERR)
		return ERR;
	if(max_len<i)
		return ERR;	
	else
		return saberEspDescripcion(espacio, descripcion);
}


STATUS darDescrGraficaEsp(ESPACIO * e, char ***descripcion, int * filas, int * columnas)
{
	return saberEspDescrGrafica(e, descripcion, filas, columnas);
}


ESPACIO * dameEspacio(MUNDO * m, ID id)
{
	int i=0;
	ID aux=-1;

	if(m==NULL || id<0)
		return NULL;

	while(i<m->numesp)
	{
		saberEspId(m->espacios[i], &aux);
		if(aux==id)
			return m->espacios[i];
		i++;
	}	
	return NULL;
}

ID darIdEsp(ESPACIO *e)
{
	ID id=-1;
	
	saberEspId(e, &id);
	return id;
}

STATUS darDescrexamEsp(ESPACIO * e, char *descripcion, int max_len)
{
	int i=0;

	if(e==NULL || descripcion==NULL || max_len<=0) 
		return ERR;
	
	if(saberEspTamDescExam(e, &i)==ERR)
		return ERR;
	if(max_len<i)
		return ERR;	
	else
		return saberEspDescExaminar(e, descripcion);
}

BOOL darLumEsp(ESPACIO *e)
{
	return isEspLuminoso(e);
}

ID darNorteEsp(ESPACIO *e)
{
	ID id=-1;
	saberEspNorte(e, &id);
	return id;
}

ID darSurEsp(ESPACIO *e)
{
	ID id=-1;
	saberEspSur(e, &id);
	return id;
}

ID darEsteEsp(ESPACIO *e){
	ID id=-1;
	saberEspEste(e, &id);
	return id;
}

ID darOesteEsp(ESPACIO *e){
	ID id=-1;
	saberEspOeste(e, &id);
	return id;
}

ID darArribaEsp(ESPACIO *e)
{
	ID id=-1;
	saberEspArriba(e, &id);
	return id;
}

ID darAbajoEsp(ESPACIO *e)
{
	ID id=-1;
	saberEspAbajo(e, &id);
	return id;
}

BOOL isObjInEspMun(ESPACIO *e, ID id)
{
	return isObjinEsp(e, id);
}

STATUS sacaObjOfEsp(ESPACIO *cont, ID obj)
{
	return sacarEspObj(cont,obj);
}



/****************************************/
/*Funciones basicas para crear uniones***/
/****************************************/


STATUS guardaUni(MUNDO *m, UNION * uni)
{
	int i=0;

	if(m==NULL || uni==NULL)
		return ERR;
	
	while(i<m->numuni && m->uniones[i]!=NULL)
		i++;

	if(i==m->numuni)
		return ERR;

	m->uniones[i]=uni;

	return OK;
}


STATUS creaUni(UNION ** uni)
{
	return creaUnion(uni);
}


STATUS destruyeUni(UNION ** uni)
{
	return destruyeUnion(uni);
}


STATUS creaIdUniMundo(UNION * uni, ID id)
{
	return cambiaUniId(uni, id);
}


STATUS creaIdSalidaUni(UNION * uni, ID id)
{
	return cambiaUniSalida(uni, id);
}


STATUS creaIdLlegadaUni(UNION * uni, ID id)
{
	return cambiaUniLlegada(uni, id);
}


STATUS creaAbiertaUni(UNION * uni, BOOL abierta)
{
	return  cambiaUniAbierta(uni, abierta);
}


STATUS creaKeyUni(UNION * uni, ID objeto)
{
	return cambiaUniKey(uni, objeto);
}

/****************************************/
/*Funciones para union*******************/
/****************************************/


UNION * dameUnion(MUNDO * m, ID id)
{
	int i=0;
	ID aux=-1;

	if(m==NULL || id<0)
		return NULL;

	while(i<m->numuni)
	{
		saberUniId(m->uniones[i], &aux);
		if(aux==id)
			return m->uniones[i];
		i++;
	}	
	return NULL;
}

ID darIdUni(UNION * uni)
{
	ID id=-1;
	saberUniId(uni, &id);
	return id;
}

ID darSalidaUni(UNION * uni)
{
	ID id=-1;
	saberUniSalida(uni, &id);
	return id;
}

ID darLlegadaUni(UNION * uni)
{
	ID id=-1;
	saberUniLlegada(uni, &id);
	return id;
}

BOOL darAbiertaUni(UNION * uni)
{
	return isUniAbierta(uni);	
}

ID darKeyUni(UNION * uni)
{
	ID id=-1;
	saberUniKey(uni, &id);
	return id;
}

/****************************************/
/*Acciones del usuario*******************/
/****************************************/


STATUS muevePersonajeAux(MUNDO *m, ID unionMov, JUGADOR *jugador)
{
	ID espacio_llegada=-1;
	UNION * uni=NULL;

	uni=dameUnion(m, unionMov);
	if(uni==NULL)
		return ERR;

	if(isUniAbierta(uni)==TRUE)
	{
		if(saberUniLlegada(uni, &espacio_llegada)==ERR)
			return ERR;
		if(espacio_llegada==-1)
			return ERR;
		if(cambiaLocalizacionJug(jugador, espacio_llegada)==ERR)
			return ERR;
		else
			return OK;
	}
	else
		return ERR;
}


STATUS muevePersonaje(MUNDO *m, DIRECCION dir, JUGADOR * jugador)
{
	ID espacio_jug=-1;
	ID union_mov=-1;
	ESPACIO * espacio=NULL;

	if(m==NULL || jugador==NULL)
		return ERR;

	espacio_jug=darLocJug(jugador);
	if(espacio_jug<0)
		return ERR;

	espacio=dameEspacio(m, espacio_jug);
	if(espacio==NULL)
		return ERR;

	switch(dir)
	{
		case N:
			if(saberEspNorte(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);

		case S:
			if(saberEspSur(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);

		case E:
			if(saberEspEste(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);

		case O:
			if(saberEspOeste(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);

		case U:
			if(saberEspArriba(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);
	
		case D:
			if(saberEspAbajo(espacio, &union_mov)==ERR)
				return ERR;
			if(union_mov==-1)
				return ERR;
			return muevePersonajeAux(m, union_mov, jugador);

		default:
			return ERR;
		}
return OK;
}


STATUS cogeObjeto(MUNDO *m, OBJETO * objeto, JUGADOR * jugador)
{
	ID idObjeto=-1, idjugador=-1;
	ESPACIO *espacio=NULL;

	if(objeto==NULL || jugador==NULL || m==NULL)
		return ERR;
	
	if(isMovil(objeto)==FALSE)
		return ERR;

	idObjeto=darLocObj(m, objeto);
	if(idObjeto<0)
		return ERR;

	idjugador=darLocJug(jugador);

	if(idjugador<0)
		return ERR;

	if(idjugador!=idObjeto)
		return ERR;


	espacio=dameEspacio(m, idObjeto);
	if(espacio==NULL)
		return ERR;
	
	

	if(meteObjJug(jugador, darIdObj(objeto))==ERR)
		return ERR;
	
	if(sacarEspObj(espacio, darIdObj(objeto))==ERR)
	{
		sacarObjInInv(jugador, darIdObj(objeto));
		return ERR;
	}	
	
	return OK;
}


STATUS dejaObjeto(MUNDO * m, OBJETO * objeto, JUGADOR * jugador)
{
	ID idjugador=-1;
	ID idobjeto=-1;
	ESPACIO * espacio=NULL;

	if(objeto==NULL || jugador==NULL || m==NULL)
		return ERR;

	idjugador=darLocJug(jugador);
	if(idjugador<0)
		return ERR;

	espacio=dameEspacio(m, idjugador);
	if(espacio==NULL)
		return ERR;

	if(saberIdObj(objeto, &idobjeto)==ERR)
	if(idobjeto==-1)
		return ERR;

	if(sacarObjInInv(jugador, idobjeto)==ERR)
		return ERR;
	
	if(meterEspObj(espacio, idobjeto)==ERR)
	{
		meterObjInInv(jugador, idobjeto);
		return ERR;
	}
	
	return OK;
}


STATUS enciende(MUNDO *m, OBJETO * objeto, JUGADOR * jugador)
{
	ID idJug=-1, idObj=-1, id=-1;

	if(objeto==NULL || jugador==NULL)
		return ERR;

	if(isEncendido(objeto)==TRUE)
		return OK;
		
	if(isLuz(objeto)==FALSE)
		return ERR;

	if(saberIdObj(objeto, &id)==ERR)
		return ERR;

	if(isObjInInv(jugador, id)==TRUE)
		return cambiaEncendido(objeto, TRUE);

	idObj=darLocObj(m, objeto);
	if(idObj<0)
		return ERR;
	
	if(saberLugarJug(jugador, &idJug)==ERR)
		return ERR;

	if(idJug==idObj)
		return cambiaEncendido(objeto, TRUE);
	else 
		return ERR;
}


STATUS apaga(MUNDO *m, OBJETO * objeto, JUGADOR * jugador)
{
	ID idJug=-1, idObj=-1, id=-1;

	if(objeto==NULL || jugador==NULL)
		return ERR;
		
	if(isLuz(objeto)==FALSE)
		return ERR;

	if(isEncendido(objeto)==FALSE)
		return OK;
	
	if(saberIdObj(objeto, &id)==ERR)
		return ERR;

	if(isObjInInv(jugador, id)==TRUE)
		return cambiaEncendido(objeto, FALSE);

	idObj=darLocObj(m, objeto);
	if(idObj<0)
		return ERR;
	
	if(saberLugarJug(jugador, &idJug)==ERR)
		return ERR;

	if(idJug==idObj)
		return cambiaEncendido(objeto, FALSE);
	else 
		return ERR;
}


STATUS meterObjObjAc(MUNDO *m, OBJETO * objetoContenedor, OBJETO * objetoContenido, JUGADOR * jugador)
{
	ID objEnedor=-1;
	ID objEnido=-1;

	if(objetoContenedor==NULL || objetoContenido==NULL || jugador==NULL)
		return ERR;


	if(isContenedor(objetoContenedor)==FALSE)
		return ERR;
	
	if(saberIdObj(objetoContenedor, &objEnedor)==ERR)
		return ERR;
	if(objEnedor==-1)
		return ERR;

	if(saberIdObj(objetoContenido, &objEnido)==ERR)
		return ERR;
	if(objEnido==-1)
		return ERR;
	
	if(isObjInInv(jugador, objEnedor)==FALSE&&isObjInEspMun(dameEspacio(m,darLocJug(jugador)),objEnedor)==FALSE)
		return ERR;
	if(isObjInInv(jugador, objEnido)==FALSE)
		return ERR;

	if(meterObjOnObj(objetoContenedor, objEnido)==ERR)
		return ERR;

	if(sacarObjInInv(jugador, objEnido)==ERR)
	{
		sacarObjObj(objetoContenedor, objEnido);
		return ERR;
	}
	return OK;
}



STATUS sacarObjObjAc(MUNDO *m,OBJETO * objetoContenedor, OBJETO * objetoContenido, JUGADOR * jugador)
{
	ID objEnedor=-1, objEnido=-1;

	if(objetoContenedor==NULL || objetoContenido==NULL || jugador==NULL)
		return ERR;
	
	if(saberIdObj(objetoContenedor, &objEnedor)==ERR)
		return ERR;
	if(objEnedor==-1)
		return ERR;

	if(saberIdObj(objetoContenido, &objEnido)==ERR)
		return ERR;
	if(objEnido==-1)
		return ERR;

	if(isObjinObj(objetoContenedor, objEnido)==FALSE)
		return ERR;
	if(isObjInInv(jugador, objEnedor)==FALSE&&isObjInEspMun(dameEspacio(m,darLocJug(jugador)),objEnedor)==FALSE)
		return ERR;


	if(sacarObjObj(objetoContenedor, objEnido)==ERR)
		return ERR;

	if(meterObjInInv(jugador, objEnido)==ERR)
	{
		meterObjOnObj(objetoContenedor, objEnido);
		return ERR;
	}
	return OK;
}



STATUS dameObjetoExaminar(MUNDO *m, OBJETO * objeto, JUGADOR * jugador, char *examinar)
{
	ID idlugjugador=-1, idlugobjeto=-1, idobjeto=-1, idaux=-1;
	int i=0, aux=-1, j=0;
	char nombre[MAX_LEN];

	if(m==NULL || objeto==NULL || examinar==NULL || jugador==NULL) 
		return ERR;

	if(saberLugarJug(jugador, &idlugjugador)==ERR)
		return ERR;
	if(idlugjugador==-1)
		return ERR;

	idlugobjeto=darLocObj(m, objeto);

	if(saberIdObj(objeto, &idobjeto)==ERR)
		return ERR;
	if(idobjeto==-1)
		return ERR;

	if(idlugobjeto==idlugjugador || isObjInInv(jugador, idobjeto))
	{
		for(i=0;i<m->numobj;i++)
		{
		
			if(saberIdObj(m->objetos[i], &idaux)==ERR)
				return ERR;
			if(idaux==-1)
				return ERR;

			if((isObjInInv(jugador, idaux)==TRUE && isEncendido(m->objetos[i])==TRUE) || isObjInInv(jugador, idobjeto) || darLumEsp(dameEspacio(m,darLocJug(jugador))))
			{
				saberTamDescrExamObj(objeto,&aux);
				if(aux>MAX_LEN||aux<0)
					return ERR;
				else
				{
					if(saberDescrExamObj(objeto, examinar)==ERR)
						return ERR;

					if(darContenedorObj(objeto)==TRUE)
					{
						strcat(examinar, "\nDentro ves: \n");
						for(j=0;j<m->numobj;j++)
						{
							if(isObjInObjMun(objeto, darIdObj(m->objetos[j]))==TRUE)
							{
								if(darNombreObj(dameObjeto(m, darIdObj(m->objetos[j])), nombre)==ERR)
									return ERR;
								strcat(examinar,nombre);
								strcat(examinar, ", ");
							}
						}
						examinar[strlen(examinar)-2]='\0';
					}
					return OK;
				}
					
			}
		}
	}
	return ERR;
}



STATUS dameEspacioExaminar(MUNDO *m, JUGADOR * jugador, char *examinar)
{
	ID idjugador=-1, idobjeto=-1;
	int i=0, aux=-1;
	ESPACIO * espacio=NULL;

	if(m==NULL || examinar==NULL || jugador==NULL) 
		return ERR;

	if(saberLugarJug(jugador, &idjugador)==ERR)
		return ERR;
	if(idjugador==-1)
		return ERR;

	espacio=dameEspacio(m, idjugador);
	if(espacio==NULL)
		return ERR;
	
	
	for(i=0;i<m->numobj;i++)
	{		
		if(saberIdObj(m->objetos[i], &idobjeto)==ERR)
			return ERR;
		if(idobjeto==-1)
			return ERR;
		
		if((isObjInInv(jugador, idobjeto)==TRUE && isEncendido(m->objetos[i])==TRUE) || isEspLuminoso(espacio)==TRUE)
		{
			saberEspTamDescExam(espacio,&aux);
			if(aux>MAX_LEN||aux<0)
				return ERR;
			else
				return saberEspDescExaminar(espacio, examinar);
		}
	}
	return ERR;
}



STATUS abreUnion(UNION * uni, JUGADOR * jugador)
{
	ID idobj=-1; 

	if(uni==NULL || jugador==NULL)
		return ERR;
	
	if(isUniAbierta(uni)==TRUE)
		return OK;
		
	if(saberUniKey(uni,&idobj)==ERR)
		return ERR;
	if(idobj==-1)
		return ERR;
		
	if(isObjInInv(jugador, idobj)==FALSE)
		return ERR;
	
	if(creaAbiertaUni(uni, TRUE)==ERR)
		return ERR;
		
return OK;
}


STATUS intercambioObj(JUGADOR * da, JUGADOR * recibe, OBJETO * obj)
{
	ID objeto=-1, jug1=-1, jug2=-1;

	if(da==NULL || recibe==NULL || obj==NULL)
		return ERR;

	if(saberIdObj(obj, &objeto)==ERR)
		return ERR;
	if(objeto==-1)
		return ERR;
		
	jug1=darLocJug(da);
	if(jug1==-1)
		return ERR;
		
	jug2=darLocJug(recibe);
	if(jug2==-1)
		return ERR;
		
	if(jug1!=jug2)
		return ERR;
		
	if(isObjInInv(da, objeto)==FALSE)
		return ERR;
		
	if(sacarObjInInv(da, objeto)==ERR)
		return ERR;

	if(meterObjInInv(recibe, objeto)==ERR)
	{	
		meterObjInInv(da, objeto);
		return ERR;
	}
	return OK;
}

