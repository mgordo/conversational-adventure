/**/
/* @brief Utilidades de transformacion de cadenas*/
/**/
/* Este modulo contiene el codigo de las funciones de transformacion de cadenas*/
/* @file UtilCadena.c*/
/* @author Carlos Carrascal*/
/* @date 23-11-2010*/
/**/


#include "UtilCadena.h"


STATUS eliminaCars(char * dst, char * ori, char * seps)
{
	char *p=NULL;	
	
	if(dst==NULL || ori==NULL || seps==NULL)
		return ERR;

	strcpy(dst,ori);
	/*Quita los caracteres que se especifican en seps*/
	p=strpbrk(dst,seps);
	/*Desde que encuentra un caractero prohibido, hasta que se acaba la cadena*/
	while(p!=NULL)
	{
		p[0]=' ';
		p=strpbrk(p+1,seps);
	}

	dst[strlen(ori)]='\0';
	return OK;
}

STATUS aMayusculas(char * dst, char * ori)
{
	int i=-1;		

	if(dst==NULL || ori==NULL)
		return ERR;

	/*Recorre secuencialmente la cadena pasándola a mayusculas*/
	for(i=0;ori[i]; i++) 
	{
		dst[i] = toupper(ori[i]);
	}

	dst[strlen(ori)]='\0';
	return OK;
}

STATUS reemplazaAsterisco(char * dst, char * ori, char * ins)
{
	int tam=strlen(ori),i=-1, j=-1;

	if(dst==NULL||ori==NULL||ins==NULL)
 		return ERR;

	/*Ira buscando caracter a caracter de ori viendo si es o no*/
	for(i=0, j=0;i<tam;i++)		
	{
		/*Si encuentra asterisco, copia en su lugar ins, y aumenta la posicion tanto como el tamaño de ins*/
		if(ori[i]=='*')		
		{			
			dst[j]=' ';
			j++;
			strcpy(&(dst[j]),ins);	
			j+=strlen(ins);		
		}
		/*Si no lo es, seguimos copiando con normalidad*/
		else
		{			 
			dst[j]=ori[i];		
			j++;			
		}
	}
	dst[j]='\0';
return OK;
}

STATUS limpiaEspacios(char * dst, char * ori)
{
	int i=0, c=-1, j=-1;
	char temp[MAX_LEN];

	if(dst==NULL||ori==NULL) 
		return ERR;
		
	/*Busca el primer espacio, y copia hasta ahí en tmp*/
	while(ori[i]==' ')
		i++;
	strcpy(temp, &ori[i]);
	
	/*Desde el final buscamos el primer caracter no espacio, y lo convertimos en el final de la cadena*/
	i=strlen(temp)-1;
	while(temp[i]==' ')	
		i--;
	temp[i+1]='\0';
	
	/*Se copia en dst desde temporal comprobando que no haya dos espacios seguidos, usando la flag 'c'*/
	for(i=0, j=0, c=0;temp[i]!='\0'; i++)	
	{							
		if(temp[i]!=' ')	
			c=0;
		if(c==0)				
		{
			dst[j]=temp[i];
			j++;				
		}
		if(temp[i]==' ')		
			c++;
	}


	return OK;
}


STATUS limpiaPalabras(char * dst, char * ori)
{
	char *s2[21], *aux="auxiliar";
	int i=0, j=0, sum=0;
	
	/*Lista de palabras indeseables*/
		s2[0] = " LA ";
   	s2[1] = " EL ";
		s2[2] = " LO ";
   	s2[3] = " LE ";
   	s2[4] = " SI ";
   	s2[5] = " LO ";
   	s2[6] = " LAS ";
   	s2[7] = " LES ";
   	s2[8] = " LOS ";
   	s2[9] = " UN ";
   	s2[10] = " UNA ";
   	s2[11] = " UNOS ";
   	s2[12] = " UNAS ";
   	s2[13] = " DE ";
   	s2[14] = " DEL ";
   	s2[15] = " A ";
   	s2[16] = " AL ";
   	s2[17] = " MI ";
   	s2[18] = " TU ";
   	s2[19] = " SU ";
   	s2[20] = " EN ";
	
	/*Copiando la cadena en dst no modificamos la original*/
	strcpy(dst, ori);

	for (i=0;i<21;i++)
	{
		/*Buscamos la palabra s2[i] en dst*/
		aux=strstr(dst, s2[i]);
		while(aux!=NULL)
		{	/*Convertimos la palabra exacta en espacios*/
			j=0;
			for(j=0;j<strlen(s2[i]);j++)
			{
				dst[strlen(dst)-strlen(aux)+j]=' ';
			}
			sum+=j;		
			aux=strstr(dst, s2[i]);
		}
	}
	dst[MAX_LEN-sum]='\0';

   return OK;
}

