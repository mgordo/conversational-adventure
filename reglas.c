/**/
/* @file reglas.c */
/* @author Antonio Jiménez Pastor*/
/* @version 0.0 */
/* Fichero que contiene el código para el manejo de la estructura REGLA*/
/* */

#include "reglas.h"

STATUS creaRegla(REGLA **r)
{
	if ((*r)!=NULL)
		return ERR;	/*Ya había datos en ese puntero*/

	*r=(REGLA *)calloc(1,sizeof(REGLA));
	if(!(*r))
		return ERR;	/*No se reserva memoria*/

	(*r)->num_influido=-1;
	(*r)->tam_datos_i=-1;
	(*r)->influido=NULL;
	(*r)->c=NULL;
	(*r)->valor_cam=NULL;
	(*r)->num_disparador=-1;
	(*r)->tam_datos_d=-1;
	(*r)->disp=NULL;
	(*r)->key=NULL;
	(*r)->valor=NULL;
	(*r)->anterior=FALSE;
	(*r)->frase=NULL;

return OK;
}


STATUS destruyeRegla(REGLA **r)
{
	if(isReglaDestruida(*r))
		return OK;

	if((*r)->influido!=NULL)
		free((*r)->influido);
	if((*r)->c!=NULL)
		free((*r)->c);
	if((*r)->valor_cam!=NULL)
		free((*r)->valor_cam);
	if((*r)->disp!=NULL)
		free((*r)->disp);
	if((*r)->key!=NULL)
		free((*r)->key);
	if((*r)->valor!=NULL)
		free((*r)->valor);
	if((*r)->frase!=NULL)
		free((*r)->frase);

	free(*r);
	(*r)=NULL;

return OK;	
}


STATUS cambiaTamanioInfluido(REGLA *r, int i)
{
	if(isReglaDestruida(r)||i<0)
		return ERR;	/*Error en los punteros*/

	r->num_influido=i;

	if(r->num_influido!=i)
		return ERR;	/*Error al copiar el dato*/
return OK;
}


STATUS cambiaTamanioDatosInfluido(REGLA *r, int t)
{
	if(isReglaDestruida(r)||t<0)
		return ERR;	/*Error en los punteros*/

	r->tam_datos_i=t;

	if(r->tam_datos_i!=t)
		return ERR;	/*Error al copiar el dato*/
return OK;
}


STATUS cambiaInfluido(REGLA *r, ID *inf, int tam)
{
	int i;

	if(isReglaDestruida(r)||inf==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/
	if(r->influido)
		free(r->influido);
	r->influido=(ID *)malloc(tam*sizeof(ID));

	if(!r->influido)
		return ERR;	/*Error al reservar memoria*/

	for(i=0;i<tam;i++)
	{
		r->influido[i]=inf[i];
		if(r->influido[i]!=inf[i])
		{
			free(r->influido);
			r->influido=NULL;
			return ERR;	/*Error al copiar algún dato*/
		}
	}
	cambiaTamanioInfluido(r,tam);

return OK;
}


STATUS cambiaCampoInfluido(REGLA *r, CAMPO *c, int tam)
{
	int i;

	if(isReglaDestruida(r)||c==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/
	if(r->c)
		free(r->c);
	r->c=(CAMPO *)malloc(tam*sizeof(CAMPO));

	if(!r->c)
		return ERR;	/*Error al reservar memoria*/

	for(i=0;i<tam;i++)
	{
		r->c[i]=c[i];
		if(r->c[i]!=c[i])
		{
			free(r->c);
			r->c=NULL;
			return ERR;	/*Error al copiar algún dato*/
		}
	}
	cambiaTamanioInfluido(r,tam);

return OK;
}


STATUS cambiaValorInfluido(REGLA *r, void *datos, int tam)
{
	if(isReglaDestruida(r)||datos==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/

	if(r->valor_cam)
		free(r->valor_cam);
	r->valor_cam=(void *)malloc(tam);

	if(!r->valor_cam)
		return ERR;	/*Error al reservar memoria*/

	memcpy(r->valor_cam,datos,tam);

	if(memcmp(r->valor_cam,datos,tam)!=0)
		return ERR;	/*Error al copiar los datos*/

	cambiaTamanioDatosInfluido(r,tam);

return OK;
}


STATUS cambiaTamanioDisparador(REGLA *r, int i)
{
	if(isReglaDestruida(r)||i<0)
		return ERR;	/*Error en los punteros*/

	r->num_disparador=i;

	if(r->num_disparador!=i)
		return ERR;	/*Error al copiar el dato*/
return OK;
}


STATUS cambiaTamanioDatosDisparador(REGLA *r, int t)
{
	if(isReglaDestruida(r)||t<0)
		return ERR;	/*Error en los punteros*/

	r->tam_datos_d=t;

	if(r->tam_datos_d!=t)
		return ERR;	/*Error al copiar el dato*/
return OK;
} 


STATUS cambiaDisparador(REGLA *r, ID *dis, int tam)
{
	int i;

	if(isReglaDestruida(r)||dis==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/
	if(r->disp)
		free(r->disp);
	r->disp=(ID *)malloc(tam*sizeof(ID));

	if(!r->disp)
		return ERR;	/*Error al reservar memoria*/

	for(i=0;i<tam;i++)
	{
		r->disp[i]=dis[i];
		if(r->disp[i]!=dis[i])
		{
			free(r->disp);
			r->disp=NULL;
			return ERR;	/*Error al copiar algún dato*/
		}
	}
	cambiaTamanioDisparador(r,tam);

return OK;
}


STATUS cambiaCampoDisparador(REGLA *r, CAMPO *c, int tam)
{
	int i;

	if(isReglaDestruida(r)||c==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/
	if(r->key)
		free(r->key);
	r->key=(CAMPO *)malloc(tam*sizeof(CAMPO));

	if(!r->key)
		return ERR;	/*Error al reservar memoria*/

	for(i=0;i<tam;i++)
	{
		r->key[i]=c[i];
		if(r->key[i]!=c[i])
		{
			free(r->key);
			r->key=NULL;
			return ERR;	/*Error al copiar algún dato*/
		}
	}
	cambiaTamanioDisparador(r,tam);

return OK;
}


STATUS cambiaValorDisparador(REGLA *r, void *datos, int tam)
{
	if(isReglaDestruida(r)||datos==NULL||tam<0)
		return ERR;	/*Error en los parámetros*/

	if(r->valor)
		free(r->valor);
	r->valor=(void *)malloc(tam);

	if(!r->valor)
		return ERR;	/*Error en la reserva de memoria*/

	memcpy(r->valor,datos,tam);

	if(memcmp(r->valor,datos,tam)!=0)
		return ERR;	/*Error al copiar los datos*/

	cambiaTamanioDatosDisparador(r,tam);

return OK;
}


STATUS cambiaAnterior(REGLA *r, BOOL valor)
{
	if(isReglaDestruida(r))
		return ERR;	/*Error en los parámetros*/

	r->anterior=valor;
	if(r->anterior!=valor)
		return ERR;	/*Error al copiar el dato*/

return OK;
}


STATUS cambiaFrase(REGLA *r, char *frase)
{
	if(isReglaDestruida(r)||frase==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->frase)
		free(r->frase);

	r->frase=(char *)malloc((strlen(frase)+1)*sizeof(char));
	if(!r->frase)
		return ERR;	/*Error al reservar memoria*/
	
	strcpy(r->frase,frase);
	if(strcmp(r->frase,frase)!=0)
	{
		free(r->frase);
		r->frase=NULL;
		return ERR;	/*Error al copiar el dato*/
	}
	return OK;
}


STATUS saberTamanioInfluido(REGLA *r, int *i)
{
	if(isEmptyRegla(r)||i==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->num_influido==-1)
		return ERR;	/*Campo vacío*/

	*i=r->num_influido;
return OK;
}


STATUS saberTamanioDatosInfluido(REGLA *r, int *t)
{
	if(isEmptyRegla(r)||t==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->tam_datos_i==-1)
		return ERR;	/*Campo vacío*/

	*t=r->tam_datos_i;
return OK;
}


STATUS saberInfluido(REGLA *r, ID *inf)
{
	int i,j;

	if(isEmptyRegla(r)||inf==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->influido==NULL)
		return ERR;
	saberTamanioInfluido(r,&j);
	for(i=0;i<j;i++)
		(inf)[i]=r->influido[i];

return OK;
}


STATUS saberCampoInfluido(REGLA *r, CAMPO *c)
{
	int i,j;

	if(isEmptyRegla(r)||c==NULL)
		return ERR;

	if(r->c==NULL)
		return ERR;
	saberTamanioInfluido(r,&j);
	for(i=0;i<j;i++)
		(c)[i]=r->c[i];

return OK;
}


STATUS saberValorInfluido(REGLA *r, void *datos)
{
	int i=0;
	if(isEmptyRegla(r)||datos==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->valor_cam==NULL)
		return ERR;	/*El campo está vacío*/

	saberTamanioDatosInfluido(r,&i);
	memcpy(datos,r->valor_cam,i);

return OK;
}


STATUS saberTamanioDisparador(REGLA *r, int *i)
{
	if(isEmptyRegla(r)||i==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->num_disparador==-1)
		return ERR;	/*Campo vacío*/

	*i=r->num_disparador;
return OK;
}


STATUS saberTamanioDatosDisparador(REGLA *r, int *t)
{
	if(isEmptyRegla(r)||t==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->tam_datos_d==-1)
		return ERR;	/*Campo vacío*/

	*t=r->tam_datos_d;
return OK;
} 


STATUS saberDisparador(REGLA *r, ID *dis)
{
	int i,j;

	if(isEmptyRegla(r)||dis==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->disp==NULL)
		return ERR;
	saberTamanioDisparador(r,&j);
	for(i=0;i<j;i++)
		(dis)[i]=r->disp[i];

return OK;
}


STATUS saberCampoDisparador(REGLA *r, CAMPO *c)
{
	int i,j;

	if(isEmptyRegla(r)||c==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->key==NULL)
		return ERR;
	saberTamanioDisparador(r,&j);
	for(i=0;i<j;i++)
		(c)[i]=r->key[i];

return OK;
}


STATUS saberValorDisparador(REGLA *r, void *datos)
{
	int i=0;
	if(isEmptyRegla(r)||datos==NULL)
		return ERR;	/*Error en los parámetros*/

	if(r->valor==NULL)
		return ERR;	/*El campo está vacío*/

	saberTamanioDatosDisparador(r,&i);
	memcpy(datos,r->valor,i);

return OK;
}


STATUS saberAnterior(REGLA *r, BOOL *valor)
{



	if(isEmptyRegla(r)||valor==NULL)
		return ERR;	/*Error en los parámetros*/

	*valor=r->anterior;

return OK;
}


STATUS saberFrase(REGLA *r, char *frase)
{
	if(isEmptyRegla(r)||frase==NULL)
		return ERR;	/*Error en los parámetros*/
	if(r->frase==NULL)
		return ERR;

	strcpy(frase,r->frase);

return OK;
}



BOOL isReglaDestruida(REGLA *r)
{
	if(r==NULL)
		return TRUE;

return FALSE;
}


BOOL isEmptyRegla(REGLA *r)
{
	if(isReglaDestruida(r))
		return TRUE;

	if(r->influido!=NULL||r->c!=NULL||r->disp!=NULL||r->key!=NULL||r->valor!=NULL||r->frase!=NULL||r->valor_cam!=NULL)
		return FALSE;

	if(r->anterior!=FALSE)
		return FALSE;

	if(r->num_influido>=0||r->tam_datos_i>=0||r->num_disparador>=0||r->tam_datos_d>=0)
		return FALSE;

return TRUE;
}


BOOL evaluaRegla(REGLA *r, MUNDO *m)
{
	int n=0,i;	/*Entero para guardar el numero de condiciones*/
	BOOL v_b=FALSE, l_b=FALSE;	/*Booleanos: uno para guardar el valor que hay en mundo y otro para el valor que se pide como condición*/
	ID v_i=-1, l_i=-1;	/*IDs: uno para guardar el valor del mundo, y otro para el valor que hay de condicion*/
	ID o_c=-1;	/*ID del objeto contenido*/
	char *p=NULL;	/*Puntero a un BYTE que permitirá extraer los datos de las condiciones*/
	BOOL resultado=TRUE;	/*BOOl del resultado que se devolvera*/

	if(isReglaDestruida(r)||m==NULL)
		return FALSE;	/*Error en el puntero*/

	if(saberTamanioDisparador(r,&n)==ERR)
		return FALSE;	/*Error en el tamaño*/

	/*Ponemos un puntero al comienzo de los datos*/
	p=(char *)r->valor;

	for(i=0;i<n&&resultado==TRUE;i++)
	{
		switch(r->key[i])
		{
			case LOC_OBJ:
			{
				l_i=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_i=darLocObj(m,dameObjeto(m,r->disp[i]));
				if(l_i==v_i){			
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case MOV_OBJ:
			{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darMovilObj(dameObjeto(m,r->disp[i]));
				if(l_b==v_b){			
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case MOVI_OBJ:
			{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darMovidoObj(dameObjeto(m,r->disp[i]));
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case OCU_OBJ:
		 	{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darOcultoObj(dameObjeto(m,r->disp[i]));
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case ENC_OBJ:
			{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darEncendidoObj(dameObjeto(m,r->disp[i]));
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case LOC_JUG:
			{
				l_i=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);
				v_i=darLocJug(dameJugador(m,r->disp[i]));
				if((l_i==v_i&&l_b==TRUE)||(l_i!=v_i&&l_b==FALSE)){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case LUM_ESP:
			{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darLumEsp(dameEspacio(m,r->disp[i]));
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case ABI_UNI:
			{
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_b=darAbiertaUni(dameUnion(m,r->disp[i]));
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case KEY_UNI:
			{
				l_i=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				v_i=darKeyUni(dameUnion(m,r->disp[i]));
				if(l_i==v_i){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case OBJ_IN_OBJ:
			{
				o_c=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);
				v_b=isObjInObjMun(dameObjeto(m,r->disp[i]),o_c);
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case OBJ_IN_JUG:
			{
				o_c=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);
				v_b=isObjInInvMun(dameJugador(m,r->disp[i]),o_c);
				if(l_b==v_b){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			case OBJ_IN_ESP:
			{
				o_c=*((ID *)p);
				p+=sizeof(ID);	/*Movemos el puntero tantas posiciones como se han leído*/
				l_b=*((BOOL *)p);
				p+=sizeof(BOOL);
				v_i=isObjInEspMun(dameEspacio(m,r->disp[i]),o_c);
				if(l_b==v_i){					
					resultado*=TRUE;
					break;
				}
				else{
					resultado*=FALSE;
					break;
				}
			}
			default:
				return FALSE;	/*Error en la key*/
		}
	}


return resultado;
}


GAMES ejecutaAccionRegla(REGLA *r, MUNDO *m)
{
	int n=0,i;	/*Entero para guardar el numero de acciones*/
	BOOL l_b=FALSE;	/*Booleano: Valor que se introducirá en mundo*/
	ID l_i=-1, aux=-1;	/*ID de lo que se vea afectado*/
	/*ID o_c=-1;	*//*ID del objeto que contiene*/
	char *p=NULL;	/*Puntero a un BYTE que permitirá extraer los datos de las condiciones*/
	
	if(isReglaDestruida(r)||m==NULL)
		return ERR;	/*Error en el puntero*/

	if(saberTamanioInfluido(r,&n)==ERR)
		return ERR;	/*Error en el tamaño*/

	/*Ponemos un puntero al comienzo de los datos*/
	p=(char *)r->valor_cam;

	for(i=0;i<n;i++)
	{
		switch(r->c[i])
		{
			case P_LOC_OBJ:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				aux=darLocObj(m, dameObjeto(m,r->influido[i]));
				if(aux!=-1)
				{
					sacaObjOfEsp(dameEspacio(m,aux),r->influido[i]);
				}
				meteObjEsp(dameEspacio(m,l_i),r->influido[i]);
				break;
			}
			case P_MOV_OBJ:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaMovidoObj(dameObjeto(m,r->influido[i]),l_b);
				break;
			}
			case P_OCU_OBJ:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaOcultoObj(dameObjeto(m,r->influido[i]),l_b);
				break;
			}
			case P_ENC_OBJ:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaMovidoObj(dameObjeto(m,r->influido[i]),l_b);
				break;
			}
			case P_CON_OBJ:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaContenedorObj(dameObjeto(m,r->influido[i]),l_b);
				break;
			}
			case P_LUZ_OBJ:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaLuzObj(dameObjeto(m,r->influido[i]),l_b);
				break;
			}
			case P_LOC_JUG:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaLocJug(dameJugador(m,r->influido[i]),l_i);
				break;
			}
			case P_MAX_JUG:
			{
				l_i=*(int *)p;
				p+=sizeof(int);
				creaMaxObjJug(dameJugador(m,r->influido[i]),l_i);
				break;
			}
			case P_LUM_ESP:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaLumEsp(dameEspacio(m,r->influido[i]),l_b);
				break;
			}
			case P_NOR_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaNorteEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_SUR_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaSurEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_EST_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaEsteEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_OES_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaOesteEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_ARR_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaArribaEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_ABA_ESP:
			{
				l_i=*(ID *)p;
				p+=sizeof(ID);
				creaAbajoEsp(dameEspacio(m,r->influido[i]),l_i);
				break;
			}
			case P_ABI_UNI:
			{
				l_b=*(BOOL *)p;
				p+=sizeof(BOOL);
				creaAbiertaUni(dameUnion(m,r->influido[i]),l_b);
				break;
			}
			case WIN_GAME:
			{
				return VICTORY;
			}
			case LOSE_GAME:
			{
				return OVER;
			}
			default:
				return KEEP;
		}
	}

return KEEP;
}

REGLAS *creaReglas(int n)
{
	int i=0, j=0;
	REGLAS *aux=NULL;

	if(n<1)
		return NULL;

	aux=(REGLAS *)calloc(1, sizeof(REGLAS));
	if(aux==NULL)
		return NULL;

	(aux->normas)=(REGLA **)calloc(n, sizeof(REGLA *));
	if(aux==NULL)
	{
		free(aux);
		return NULL;
	}

	for(i=0;i<n;i++)
	{
		if(creaRegla(&(aux->normas[i]))==ERR)
		{
			for(j=0;j<i;j--)
			{
				destruyeRegla(&(aux->normas[i]));
			}
			free(aux->normas);
			free(aux);
			return NULL;
		}	
	}
	aux->cantidad=n;
	return aux;
}


STATUS destruyeReglas(REGLAS ** reglas)
{
	int i=0;

	if(reglas==NULL)
		return OK;
	if(*reglas==NULL)
		return OK;

	for(i=0;i<(*reglas)->cantidad;i++)
	{
		if((*reglas)->normas[i]!=NULL)
			destruyeRegla(&((*reglas)->normas[i]));		
	}
	free((*reglas)->normas);
	free(*reglas);
	*reglas=NULL;
	return OK;
}


