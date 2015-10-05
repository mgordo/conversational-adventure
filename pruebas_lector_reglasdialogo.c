/**/
/* pruebas_lector_reglasdialogo.c*/
/* Contiene el cliente de pruebas de lector_reglas_dialogo*/
/* Autor: Miguel Gordo*/
/* Fecha: 3-XII-2010*/

#include"lector_reglasdialogo.h"
#include<assert.h>

int main(){
	
	ID i=0;
	DIALOGUE *dial=NULL;
	char fichero[50];
	strcpy(fichero,"pruebasdialogo.xml");
	
	dial=iniDialogo(fichero);
	assert(dial!=NULL);
	/*Comprobación de los temas*/
	for(i=0;i<4;i++)
		assert((dial->theme[i])->tema==(i+1));
	/*Comprobación de plantillas*/
	assert(strcmp((dial->plant[0])->plantilla,"Saludos")==0);
	assert(strcmp((dial->plant[1])->plantilla,"Bye")==0);
	assert(strcmp((dial->plant[2])->plantilla,"Hasta luego")==0);
	assert(strcmp((dial->plant[3])->plantilla,"OK")==0);
	assert(strcmp((dial->plant[4])->plantilla,"NO")==0);
	/*Comprobación de reglas*/
	assert(strcmp((dial->rules[0])->patron,"HOLA")==0);
	assert((dial->rules[0])->ini==0);
	assert((dial->rules[0])->fin==0);
	
	assert(strcmp((dial->rules[1])->patron,"ADIOS")==0);
	assert((dial->rules[1])->ini==1);
	assert((dial->rules[1])->fin==2);
	
		assert(strcmp((dial->rules[2])->patron,"FAREWELL")==0);
	assert((dial->rules[2])->ini==1);
	assert((dial->rules[2])->fin==2);
	
	assert(strcmp((dial->rules[3])->patron,"HUM")==0);
	assert((dial->rules[3])->ini==3);
	assert((dial->rules[3])->fin==3);
	
	assert(strcmp((dial->rules[4])->patron,"SI")==0);
	assert((dial->rules[4])->ini==4);
	assert((dial->rules[4])->fin==4);
	/*Comprobación de relaciones*/
	assert((dial->rel[0])->relacion[0]==0);
	assert((dial->rel[0])->relacion[1]==-1);
	
	assert((dial->rel[1])->relacion[0]==1);
	assert((dial->rel[1])->relacion[1]==2);
	assert((dial->rel[1])->relacion[2]==-1);
	
	assert((dial->rel[2])->relacion[0]==3);
	assert((dial->rel[2])->relacion[1]==-1);
	
	assert((dial->rel[3])->relacion[0]==4);
	assert((dial->rel[3])->relacion[1]==-1);
	
	assert(OK==destruyeDialogue(&dial));
	printf("Éxito rotundo en las pruebas del lector_reglasdialogo!\n");
	return OK;
}
