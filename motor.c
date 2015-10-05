/**/
/* @brief Primitivas del motor gráfico*/
/* Este modulo contiene el código de las funciones del motor gráfico */
/* @file motor.h */
/* @author Miguel Gordo y Antonio Jiménez*/
/* @version 1.0 */
/* @date 2-12-2010 */

#include "motor.h"

STATUS leeUsuario(PV *pant,char *lectura)
{
	return leePantalla(pant,lectura,MAX_LEN-1);
}


PV *creaPV(int filasizq, int columnasizq ,char columna, char fila, char esquina)
{
	return creaPantalla(filasizq, columnasizq, columna, fila, esquina);
}


STATUS destruyePV(PV **pant)
{
	return destruyePantalla(pant);
}


STATUS imprimePV(PV *pant,MUNDO *mundo, char *resul_accion)
{
	char **dibujo=NULL;
	char *frase=NULL;
	int filas=0, columnas=0, i=0, fl=0;
	char *pt=NULL;

	if (pant==NULL|| mundo==NULL||resul_accion==NULL)
		return ERR;
		
	if(borraPantalla(pant)==ERR)
		return ERR;
		
	darDescrGraficaEsp(dameEspacio(mundo,darLocJug(dameJugador(mundo,0))),&dibujo,&filas,&columnas);
	introduceDibujoPantalla(pant,dibujo);
	/*Hay que liberar todo lo que se reservó*/
	free(dibujo[0]);
	free(dibujo);
	
	frase=(char *)calloc(4*MAX_LEN, sizeof(char));
	pt=frase;
	if(pt==NULL)
		return ERR;

	for(i=0;i<mundo->numobj;i++)
		if((isObjInInvMun(dameJugador(mundo,0),darIdObj(mundo->objetos[i]))==TRUE)&&(darEncendidoObj(mundo->objetos[i])==TRUE))
		{
			fl=1;
			break;
		}

	if(darLumEsp(dameEspacio(mundo,darLocJug(dameJugador(mundo,0))))==TRUE||fl==1)
	{
		darDescrEsp(dameEspacio(mundo,darLocJug(dameJugador(mundo,0))), pt, MAX_LEN);
		pt+=strlen(pt)+1;
		pt[-1]='\n';
		*pt='\n';
		pt++;
		/*Guardamos en frase los objetos del espacio*/
		strcpy(pt,"Ves:\n");
		pt+=strlen(pt);
		for(i=0,fl=0; i<(mundo->numobj); i++)
		{
			if((darOcultoObj(dameObjeto(mundo,darIdObj(mundo->objetos[i])))==FALSE)&&isObjInEspMun(dameEspacio(mundo,darLocJug(dameJugador(mundo,0))),darIdObj(mundo->objetos[i])))
			{
				if(fl!=0)
				{
					pt[0]=','; pt[1]=' '; pt+=2;
				}
				darNombreObj(dameObjeto(mundo,darIdObj(mundo->objetos[i])),pt);	
				pt+=strlen(pt);
				fl=1;
			}
		}
		*pt='\n';
		pt++;	

		/*Guardamos el resultado de la última acción*/
		strcpy(pt,resul_accion);
	}
	else
		strcpy(frase, "No ves nada\n\n Deberías llevar un objeto luminoso\n");
	introduceDescrPantalla(pant, frase);
	
	imprimePantalla(pant);
	
	free(frase);
	
return OK;	
}
