/*Fichero: programa de prueba del protoripo.

Autor: Antonio Jimenez Pastor
Fecha: 17-11-2010
*/

#include "dialogo.h"

#define TAM_NOM 256
#define NUM_JUEG 1
/*Funcion principal*/

int main()
{
	char *nombre[NUM_JUEG]=
	{
		"Draco Dormiens Nunquam Titillandus"
	};
	char *nom_fich[NUM_JUEG]=
	{
		"Draco.xml"	
	};
	char fich_mun[TAM_NOM], fich_dia[TAM_NOM], fich_reg[TAM_NOM]; 
	char buff[TAM_NOM];
	int i;
	
	
	/*Imprimimos las opciones para iniciar un juego entre los disponibles*/
	printf("------------------------------------------------------------------\n\tElija un juego de la lista para comenzar a jugar:\n\n");
	for(i=0;i<NUM_JUEG;i++)
		printf("\t\t- %s (%d)\n", nombre[i],i+1);
	printf("------------------------------------------------------------------\n");
	printf("\n>");

	i=0;
	/*Leemos el juego que queremos iniciar*/
	while(i<=0||i>NUM_JUEG)
	{
		fgets(buff,TAM_NOM-1,stdin);
		if(sscanf(buff,"%d",&i)<=0)
			printf("Elije un numero de la lista. Hay que introducir un numero hasta el %d\n", NUM_JUEG);
		else if(i<=0||i>NUM_JUEG)
			printf("Elije un numero de la lista. Hay que introducir un numero hasta el %d\n", NUM_JUEG);
	}
	
	/*Creamos los nombres de los ficheros a abrir*/
	strcpy(fich_mun,"mundo_");
	strcpy(fich_dia,"dialogo_");
	strcpy(fich_reg,"reglas_");
	
	strcat(fich_mun,nom_fich[i-1]);
	strcat(fich_dia,nom_fich[i-1]);
	strcat(fich_reg,nom_fich[i-1]);
	
	/*Ejecutamos el juego en cuestión*/
	if(dialogo(fich_mun,fich_reg,fich_dia)==ERR)
		printf("Ocurrio un error durante el juego...\n\nAbortando programa\n\n");
	
return 0;
}
