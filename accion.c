 /**/
/* @brief Utilidades para las acciones de un personaje*/
/**/
/* Este modulo contiene las funciones para ejecutar las acciones de un personaje*/
/**/
/* @file accion.c*/
/* @author Carlos Carrascal*/
/* @date 01-11-2010*/
/**/


#include "accion.h"


ACCION * creaAccion(char *fichMundo, char * fichReglas)
{
	ACCION * acc=NULL;

	acc=(ACCION *)calloc(1, sizeof(ACCION));
	if(acc==NULL)
		return NULL;
		
	acc->id=NADA;
	acc->objetoD=NULL;
	acc->objetoI=NULL;
	acc->jugadorD=NULL;
	acc->jugadorI=NULL;
	acc->dir=N;
	
	acc->m=NULL;
	acc->m=iniMundo(fichMundo);
	if(acc->m==NULL)
	{
		free(acc);
		return NULL;
	}

	acc->reglas=NULL;
	acc->reglas=iniReglas(fichReglas);
	if(acc->reglas==NULL)
	{
		destruyeMundo(&(acc->m));
		free(acc);
		return NULL;
	}

	return acc;
}


STATUS destruyeAccion(ACCION ** acc)
{
	if(acc==NULL)
		return OK;
	if(*acc==NULL)
		return OK;
		
	if((*acc)->objetoD!=NULL)
	{
		free((*acc)->objetoD);
		(*acc)->objetoD=NULL;
	}
	if((*acc)->objetoI!=NULL)
	{
		free((*acc)->objetoI);
		(*acc)->objetoI=NULL;
	}	
	if((*acc)->jugadorD!=NULL)
	{
		free((*acc)->jugadorD);
		(*acc)->jugadorD=NULL;
	}
	if((*acc)->jugadorI!=NULL)
	{
		free((*acc)->jugadorI);
		(*acc)->jugadorI=NULL;
	}
	destruyeReglas(&((*acc)->reglas));
	destruyeMundo(&((*acc)->m));

	free(*acc);
	*acc=NULL;

	return OK;
}


MUNDO *saberMundoAccion(ACCION *a)
{
	if(a==NULL)
		return NULL;

	return a->m;
}


STATUS cambiaIdAccion(ACCION * accion, TIPOACCION tipo)
{
	if(accion==NULL || tipo<0)
		return ERR;
	
	accion->id=tipo;
	return OK;
}


TIPOACCION saberTipoAccion(ACCION *a)
{
	if(a==NULL)
		return NADA;

	return a->id;
}


STATUS cambiaDAccion(ACCION * accion, char * cadena)
{
	if(accion==NULL || cadena==NULL)
		return ERR;
		
	if(accion->objetoD!=NULL)
		free(accion->objetoD);

	accion->objetoD=(char *)calloc(strlen(cadena)+1,sizeof(char));
	if(accion->objetoD==NULL)
		return ERR;
		
	strcpy(accion->objetoD, cadena);
	
	return OK;
}


char * saberDAccion(ACCION *a)
{
	if(a==NULL)
		return NULL;
	
	return a->objetoD;

}


STATUS cambiaIAccion(ACCION * accion, char * cadena)
{
	if(accion==NULL || cadena==NULL)
		return ERR;
		
	if(accion->objetoI!=NULL)
		free(accion->objetoI);
	
	accion->objetoI=(char *)calloc(strlen(cadena)+1,sizeof(char));
	if(accion->objetoI==NULL)
		return ERR;
		
	strcpy(accion->objetoI, cadena);
	
	return OK;
}


STATUS cambiaJugDAccion(ACCION * accion, char * cadena)
{
	if(accion==NULL || cadena==NULL)
		return ERR;
		
	if(accion->jugadorD!=NULL)
		free(accion->jugadorD);

	accion->jugadorD=(char *)calloc(strlen(cadena)+1,sizeof(char));
	if(accion->jugadorD==NULL)
		return ERR;
		
	strcpy(accion->jugadorD, cadena);
	
	if(creaNombreJug(dameJugador(accion->m, 0), cadena)==ERR)
		return ERR;
	
	return OK;
}

STATUS cambiaJugIAccion(ACCION * accion, char * cadena)
{
	if(accion==NULL || cadena==NULL)
		return ERR;
		
	if(accion->jugadorI!=NULL)
		free(accion->jugadorI);

	accion->jugadorI=(char *)calloc(strlen(cadena)+1,sizeof(char));
	if(accion->jugadorI==NULL)
		return ERR;
		
	strcpy(accion->jugadorI, cadena);
	
	return OK;
}

char * saberJugIAccion(ACCION *a)
{
	if(a==NULL)
		return NULL;

	return a->jugadorI;
}

STATUS cambiaDirAccion(ACCION * accion, DIRECCION dir)
{
	if(accion==NULL || dir<0)
		return ERR;
	
	accion->dir=dir;
	return OK;
}


STATUS ejecutaAccion(ACCION *a, char *info, GAMES *fin)
{
	int j=0, num=0, i=0;
	ESPACIO *esp=NULL;
	GAMES estado=KEEP;
	JUGADOR *jug1=NULL, *jug2=NULL;
	ID id1=-1, id2=-1, fl=0;
	BOOL bol1, bol2;

	if(a==NULL || info==NULL || fin==NULL)
		return ERR;
	
	*fin=estado;

	switch (a->id) 
	{
		case EXAMINAR_ESP:
		{
			if(dameEspacioExaminar(a->m, consigueJugador(a->m, a->jugadorD), info)==ERR)
				return ERR;
			else
				break;
		}		
		case EXAMINAR_INV:
		{
			if(dameInvExaminar(a->m, consigueJugador(a->m, a->jugadorD), info)==ERR)
				return ERR;
			else
				break;
		}	
		case EXAMINAR_OBJ:
		{	if(dameObjetoExaminar(a->m, consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD), info)==ERR)
				return ERR;
			else
				break;
		}
		case IR: 
		{
			if(muevePersonaje(a->m, a->dir, consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case COGER:
		{
      			if(cogeObjeto(a->m,consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case DEJAR:
		{
			if(dejaObjeto(a->m,consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case ENCIENDE:
		{
			if(enciende(a->m, consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case APAGA:
		{
			if(apaga(a->m, consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case METER:
		{
			if(meterObjObjAc(a->m,consigueObjeto(a->m, a->objetoI), consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case SACAR:
		{
			if(sacarObjObjAc(a->m,consigueObjeto(a->m, a->objetoI),consigueObjeto(a->m, a->objetoD), consigueJugador(a->m, a->jugadorD))==ERR)
				return ERR;
			else
				break;
		}
		case ABRIR:
		{
			esp=dameEspacio(a->m, darLocJug(consigueJugador(a->m, a->jugadorD)));			
			if(esp==NULL)
				return ERR;
			
			switch (a->dir)
			{
				case N:
				{
					if(abreUnion(dameUnion(a->m, darNorteEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				case S:
				{
					if(abreUnion(dameUnion(a->m, darSurEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				case E:
				{
					if(abreUnion(dameUnion(a->m, darEsteEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				case O:
				{
					if(abreUnion(dameUnion(a->m, darOesteEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				case U:
				{
					if(abreUnion(dameUnion(a->m, darArribaEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				case D:
				{
					if(abreUnion(dameUnion(a->m, darAbajoEsp(esp)), consigueJugador(a->m, a->jugadorD))==ERR)
						return ERR;
					else
						break;
				}
				default:
					return ERR;
			}	
			break;
		}
		case FIN:
		{
			*fin=OVER;
			return OK;		
		}
		case DAR:
		{
			if(intercambioObj(consigueJugador(a->m, a->jugadorD), consigueJugador(a->m, a->jugadorI), consigueObjeto(a->m, a->objetoD))==ERR)
				return ERR;
			else
				break;
		}		
		case PEDIR:
		{
			if(intercambioObj(consigueJugador(a->m, a->jugadorI), consigueJugador(a->m, a->jugadorD), consigueObjeto(a->m, a->objetoD))==ERR)
				return ERR;
			else
				break;
		}
		case DECIR:
		{
			jug1=consigueJugador(a->m, a->jugadorD);
			if(jug1==NULL)
				return ERR;
			id1=darLocJug(jug1);
			if(id1<0)
				return ERR;
			if(saberNumJug(a->m, &num)==ERR)
				return ERR;

			jug2=consigueJugador(a->m, a->jugadorI);
			if(jug2==NULL)
				return ERR;
			id2=darLocJug(jug2);
			if(id2<0)
				return ERR;
			if(id2!=id1)
				return ERR;
			break;
		}
		default:
			return ERR;
	}
	
		while(fl==0)
		{
			fl=1;
			for(j=0;(j<(a->reglas)->cantidad);j++)
			{
				bol1=evaluaRegla((a->reglas)->normas[j],a->m);
				if(saberAnterior((a->reglas)->normas[j], &bol2)==ERR)
					return ERR;
				if(cambiaAnterior((a->reglas)->normas[j], bol1)==ERR)
					return ERR;

				if(bol1!=bol2 && bol1==TRUE)
				{			
					estado=ejecutaAccionRegla((a->reglas)->normas[j],a->m);
					/*Concatenamos el resultado de la Accion con las frases de las reglas que se ejecuten*/
					i=strlen(info);
					info[i]='\n';
					saberFrase((a->reglas)->normas[j],&info[i+1]);
					fl=0;
					if(estado!=KEEP)
					{
						*fin=estado;
						return OK;
					}
				}
			}
		}
	return OK;
}
