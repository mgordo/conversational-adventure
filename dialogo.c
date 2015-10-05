#define EXIT(x,y,z) {destruyeDialogue(&x); destruyeAccion(&y); destruyePantalla(&z); return ERR;}


/**
 * @brief Utilidades para el dialogo
 *
* Este modulo contiene el codigo de las funciones que interactuan con el juego
 *
 * @file dialogo.c
 * @author Carlos Carrascal
 * @version 1.0
 * @date 01-12-2010*/


/*Esquema de pruebas:*/

/*Destacaremos que este modulo no dispone de bateria de pruebas propia, ya que simplemente es llamado por el main y su funcionamiento es probado mediante la ejecucion del juego presentado como modelo*/

#include "dialogo.h"

STATUS dialogo(char * fmundo, char * freglas, char * fdialogo)
{
	ACCION * accion=NULL;
	char entrada[MAX_LEN],entrada2[MAX_LEN], aux1[MAX_LEN], aux2[MAX_LEN], aux3[MAX_LEN], seps[41], dest[MAX_LEN], final[MAX_LEN], nombre[MAX_LEN], resul_accion[MAX_LEN], info[MAX_LEN];
	PV * pantalla=NULL;
	GAMES fin=KEEP;
	DIALOGUE * dialogo=NULL;
	int patron=-1, i=0, fl=0;
	
	if((!fmundo) || (!freglas) || (!fdialogo))
		return ERR;

	/*Caracteres a eliminar*/
	strcpy(seps,"!|@∑#$~%¨&/()=?°ø`^[+*]{Á«},;.:-_");

	/*Se inicializa todo lo necesario*/
	accion=creaAccion(fmundo,freglas);
	if(accion==NULL)
		EXIT(dialogo,accion,pantalla);

	pantalla=creaPV(23,49,'|','-','+');
	if(pantalla==NULL)
		EXIT(dialogo,accion,pantalla);
	
	dialogo=iniDialogo(fdialogo);
	if(dialogo==NULL)
		EXIT(dialogo,accion,pantalla);
	
	/*El usuario debe introducir su nombre*/
	printf("Introduce tu nombre: ");
	if(leeUsuario(pantalla, nombre)==ERR)
		EXIT(dialogo,accion,pantalla);

	if(cambiaJugDAccion(accion, nombre)==ERR)
		EXIT(dialogo,accion,pantalla);

	/*Historia inicial*/
	patron=busca_patron(dialogo, "/");
	if(selecciona_plantilla(dialogo, patron, dest)==ERR)
		EXIT(dialogo,accion,pantalla);

	/*Imprimir pantalla con dest*/	
	if(imprimePV(pantalla, saberMundoAccion(accion), dest)==ERR)
		EXIT(dialogo,accion,pantalla);

	/*Proceso real del juego*/
	while(fin==KEEP)
	{
		for(i=0;i<MAX_LEN;i++)
		{
			resul_accion[i]='\0';
			info[i]='\0';
			entrada[i]='\0';
			aux1[i]='\0';
			aux2[i]='\0';
			aux3[i]='\0';
			dest[i]='\0';
			final[i]='\0';
			nombre[i]='\0';
		}
		
		
		/*Lectura y limpieza de la entrada*/
		if(leeUsuario(pantalla, entrada2)==ERR)
			EXIT(dialogo,accion,pantalla);
			
		if(eliminaCars(aux1, entrada2, seps)==ERR)
			EXIT(dialogo,accion,pantalla);
		if(aMayusculas(aux2, aux1)==ERR)
			EXIT(dialogo,accion,pantalla);
		if(limpiaPalabras(aux3, aux2)==ERR)
			EXIT(dialogo,accion,pantalla);
		if(limpiaEspacios(entrada, aux3)==ERR)
			EXIT(dialogo,accion,pantalla);
		
		/*Una accion puede no entenderse, no poder realizarse o que sea correcta, con lo cual tenemos tres casos. Ahora bien, si es correcta, puede que se trate de hablar con alguien, o de examinar algo. Si se trata de examinar, el resultado (info) se imprime sin modificiacion alguna*/
		fl=0;
		if(interpretaFrase(dialogo,accion,entrada)==ERR)
		{
			patron=busca_patron(dialogo, "*");
			if(selecciona_plantilla(dialogo, patron, info)==ERR)
				EXIT(dialogo,accion,pantalla);
			fl=1;
		}
		if(accion->id==FIN)
			break;
		
		if(fl!=1 && ejecutaAccion(accion, resul_accion, &fin)==ERR)
		{
			patron=busca_patron(dialogo, "^");
			if(selecciona_plantilla(dialogo, patron, info)==ERR)
				EXIT(dialogo,accion,pantalla);	 
		}
		else if(fl!=1 && saberTipoAccion(accion)==DECIR)
		{
			patron=tbusca_patron(dialogo, saberDAccion(accion), saberJugIAccion(accion));
			if(selecciona_plantilla(dialogo, patron, final)==ERR)
			{			
				patron=busca_patron(dialogo,"*");
				selecciona_plantilla(dialogo,patron,final);
			}
			sprintf(info, "\n%s: %s", saberJugIAccion(accion), final);
		}
		
		else if(fl!=1 && saberTipoAccion(accion)!=EXAMINAR_INV && saberTipoAccion(accion)!=EXAMINAR_OBJ && saberTipoAccion(accion)!=EXAMINAR_ESP && fl!=1)
		{
			sprintf(aux1,"ACC_%s", entrada);
			
			patron=tbusca_patron(dialogo, aux3, "VERBOS");
			if(patron!=NO_ENCONTRADO)
			{
				if(selecciona_plantilla(dialogo, patron, aux3)==ERR)
				return ERR;
			}
			


			patron=busca_patron(dialogo,aux3);	
			strcpy(aux2,strstr(entrada," ")+1);	
		
			if(selecciona_plantilla(dialogo, patron, final)==ERR)
				EXIT(dialogo,accion,pantalla);	 
			aux2[strlen(aux2)]='\0';
			/*Le agrego lo correspondiente que falte*/
			if(reemplazaAsterisco(info, final, aux2)==ERR)
				EXIT(dialogo,accion,pantalla);
		}
		else if(fl!=1)
			info[0]='\0';
		/*Concatenamos lo que haya devuelto la plantilla con el resultado de la accion*/
		i=strlen(info);
		info[i]='\n';
		strcpy(&info[i+1],resul_accion);
		if(imprimePV(pantalla, saberMundoAccion(accion), info)==ERR)
			EXIT(dialogo,accion,pantalla);
	}
	printf("Antes de terminar, te gusto el juego?: ");
	if(leeUsuario(pantalla, nombre)==ERR)
		EXIT(dialogo,accion,pantalla);

	patron=busca_patron(dialogo, "ACABAR");
	dest[0]='\0';
	if(selecciona_plantilla(dialogo, patron, dest)==ERR)
			EXIT(dialogo,accion,pantalla);

	if(imprimePV(pantalla, saberMundoAccion(accion), dest)==ERR)
		EXIT(dialogo,accion,pantalla);	
	
	destruyeDialogue(&dialogo);
	destruyeAccion(&accion);
	destruyePantalla(&pantalla);
	return OK;
}

STATUS interpretaFrase(DIALOGUE *dialogo, ACCION * accion, char * cadena)
{
	char aux[MAX_LEN], aux2[MAX_LEN], aux3[MAX_LEN], aux4[MAX_LEN], aux5[MAX_LEN], aux6[MAX_LEN];
	int patron=0;
	

	if((!accion) || (!cadena))
		return ERR;
	
	sscanf(cadena, "%s %s %s", aux6, aux2, aux3);
	
	patron=tbusca_patron(dialogo, aux6, "VERBOS");
	if(patron!=NO_ENCONTRADO)
	{
		if(selecciona_plantilla(dialogo, patron, aux)==ERR)
			return ERR;
	}
	else
		strcpy(aux,aux6);

	if(strcmp("IR",aux)==0)
	{
		if(cambiaIdAccion(accion, IR)==ERR)
			return ERR;

		if(strcmp("NORTE", aux2)==0){
			if(cambiaDirAccion(accion, N)==ERR)
				return ERR;}
		else if(strcmp("SUR", aux2)==0){
			if(cambiaDirAccion(accion, S)==ERR)
				return ERR;}			
		else if(strcmp("ESTE", aux2)==0){
			if(cambiaDirAccion(accion, E)==ERR)
				return ERR;}	
		else if(strcmp("OESTE", aux2)==0){
			if(cambiaDirAccion(accion, O)==ERR)
				return ERR;}	
		else if(strcmp("ARRIBA", aux2)==0){
			if(cambiaDirAccion(accion, U)==ERR)
				return ERR;}	
		else if(strcmp("ABAJO", aux2)==0){
			if(cambiaDirAccion(accion, D)==ERR)
				return ERR;}
		else
			return ERR;

		return OK;
	}
	
	else if(strcmp("COGER", aux)==0)
	{
		if(cambiaIdAccion(accion, COGER)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
		
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;

		return OK;
	}
	
	else if(strcmp("DEJAR", aux)==0)
	{
		if(cambiaIdAccion(accion, DEJAR)==ERR)
			return ERR;
			
		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;

		return OK;
	}
	
	else if(strcmp("ENCIENDE", aux)==0)
	{
		if(cambiaIdAccion(accion, ENCIENDE)==ERR)
			return ERR;
			
		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;

		return OK;
	}
	
	else if(strcmp("APAGA", aux)==0)
	{
		if(cambiaIdAccion(accion, APAGA)==ERR)
			return ERR;
			
		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;

		return OK;
	}
	
	else if(strcmp("METER", aux)==0)
	{
		if(cambiaIdAccion(accion, METER)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		patron=tbusca_patron(dialogo, aux3, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux5)==ERR)
				return ERR;
		}
		else
			strcpy(aux5,aux3);
		

		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;
		if(cambiaIAccion(accion, aux5)==ERR)
			return ERR;			

		return OK;
	}
	
	else if(strcmp("SACAR", aux)==0)
	{
		if(cambiaIdAccion(accion, SACAR)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		patron=tbusca_patron(dialogo, aux3, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux5)==ERR)
				return ERR;
		}
		else
			strcpy(aux5,aux3);
		

		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;
		if(cambiaIAccion(accion, aux5)==ERR)
			return ERR;
		return OK;	
	}

	else if(strcmp("EXAMINAR", aux)==0)
	{
		if(strcmp(aux2,"LUGAR")==0)
		{	
			if(cambiaIdAccion(accion, EXAMINAR_ESP)==ERR)
				return ERR;

			return OK;
		}
		else if(strcmp(aux2,"INVENTARIO")==0)
		{	
			if(cambiaIdAccion(accion, EXAMINAR_INV)==ERR)
				return ERR;

			return OK;
		}
		else
		{
			if(cambiaIdAccion(accion, EXAMINAR_OBJ)==ERR)
				return ERR;

			patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
			if(patron!=NO_ENCONTRADO)
			{
				if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
					return ERR;
			}
			else
				strcpy(aux4,aux2);
			
			if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;

			return OK;	
		}
	}
	
	else if(strcmp("ABRIR", aux)==0)
	{
		if(cambiaIdAccion(accion, ABRIR)==ERR)
			return ERR;

		if(strcmp("NORTE", aux2)==0){
			if(cambiaDirAccion(accion, N)==ERR)
				return ERR;}
		else if(strcmp("SUR", aux2)==0){
			if(cambiaDirAccion(accion, S)==ERR)
				return ERR;}				
		else if(strcmp("ESTE", aux2)==0){
			if(cambiaDirAccion(accion, E)==ERR)
				return ERR;}
		else if(strcmp("OESTE", aux2)==0){
			if(cambiaDirAccion(accion, O)==ERR)
				return ERR;}	
		else if(strcmp("ARRIBA", aux2)==0){
			if(cambiaDirAccion(accion, U)==ERR)
				return ERR;}	
		else if(strcmp("ABAJO", aux2)==0){
			if(cambiaDirAccion(accion, D)==ERR)
				return ERR;}
		else 
			return ERR;

		return OK;	
	}
	
	else if(strcmp("FIN", aux)==0)
	{
		if(cambiaIdAccion(accion, FIN)==ERR)
			return ERR;

		return OK;
	}

	else if(strcmp("DAR", aux)==0)
	{
		if(cambiaIdAccion(accion, DAR)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
				return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;	
		if(cambiaJugIAccion(accion, aux3)==ERR)
			return ERR;

		return OK;
	}
	
	else if(strcmp("PEDIR", aux)==0)
	{
		if(cambiaIdAccion(accion, PEDIR)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux2, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux4)==ERR)
			return ERR;
		}
		else
			strcpy(aux4,aux2);
			
		if(cambiaDAccion(accion, aux4)==ERR)
			return ERR;;	
		if(cambiaJugIAccion(accion, aux3)==ERR)
			return ERR;

		return OK;
	}

	else if(strcmp("DECIR", aux)==0)
	{
		if(cambiaIdAccion(accion, DECIR)==ERR)
			return ERR;


		sscanf(cadena, "%s '%[^']' %s", aux, aux2, aux3); 

		if(cambiaDAccion(accion, aux2)==ERR)
			return ERR;

		patron=tbusca_patron(dialogo, aux3, "SINONIMOS");
		if(patron!=NO_ENCONTRADO)
		{
			if(selecciona_plantilla(dialogo, patron, aux5)==ERR)
				return ERR;
		}
		else
			strcpy(aux5,aux3);

		if(cambiaJugIAccion(accion, aux5)==ERR)
			return ERR;
		
		return OK;
	}
	
	else
		return ERR;
		
	return OK;
}
