/**/
/* pruebas_reglasdialogo.c*/
/* Contiene el cliente de pruebas del módulo reglasdialogo*/
/* Las funciones de guardar, y crear (temas, reglas, relaciones y plantillas) se probarán en lector_reglasdialogo.c*/
/* Autor: Miguel Gordo*/
/* Fecha: 29-XI-2010*/


#include"reglasdialogo.h"
#include<stdio.h>
#include<assert.h>

int main(){
	
	DIALOGUE *dial=NULL;
	REGLAD *rule=NULL;
	TEMA *theme=NULL;
	PLANTILLA *plant=NULL;
	RELATION *rel=NULL;
	int i=0;
	char dest[MAX_LEN];
	int rel2[MAX_LEN];
	dial=creaDialogue(5,4,4,5);/*Un diálogo de 5 reglas, 4 relaciones, 4 temas, 5 plantillas*/
	assert(dial!=NULL);
	
	for(i=0;i<dial->tam_rules;i++){
		rule=creaReglad();
		if(ERR==guardaReglad(dial,rule)){
			free(rule);
			destruyeDialogue(&dial);
		}
	}
	
		for(i=0;i<dial->tam_rel;i++){
		rel=creaRelation();
		if(ERR==guardaRelation(dial,rel)){
			free(rel);
			destruyeDialogue(&dial);
		}
	}
	
		for(i=0;i<dial->tam_theme;i++){
		theme=creaTema();
		if(ERR==guardaTema(dial,theme)){
			free(theme);
			destruyeDialogue(&dial);
		}
	}
	
		for(i=0;i<dial->tam_plant;i++){
		plant=creaPlantilla();
		if(ERR==guardaPlantilla(dial,plant)){
			free(plant);
			destruyeDialogue(&dial);
		}
	}
	
	/*IniTema*/
	assert(OK==iniTema((dial->theme[0]), 1, "Bienvenida"));
	assert(OK==iniTema((dial->theme[1]), 2, "Despedida"));
	assert(OK==iniTema((dial->theme[2]), 3, "Mumble"));
	assert(OK==iniTema((dial->theme[3]), 4, "Negacion"));
	

	
	/*IniPnatillas*/
	assert(OK==iniPlantilla((dial->plant[0]),"Saludos"));
	assert(OK==iniPlantilla((dial->plant[1]),"Bye"));
	assert(OK==iniPlantilla((dial->plant[2]),"Hasta luego"));
	assert(OK==iniPlantilla((dial->plant[3]),"OK"));
	assert(OK==iniPlantilla((dial->plant[4]),"NO"));
	/*Inicialización reglas*/
	assert(OK==iniRegla((dial->rules[0]),0,0,"HOLA"));
	assert(OK==iniRegla((dial->rules[1]),1,2,"ADIOS"));
	assert(OK==iniRegla((dial->rules[2]),1,2,"FAREWELL"));
	assert(OK==iniRegla((dial->rules[3]),3,3,"HUM"));
	assert(OK==iniRegla((dial->rules[4]),4,4,"SI"));
	/*Ini relaciones*/
	rel2[0]=0;
	rel2[1]=-1;
	assert(OK==iniRelation((dial->rel[0]),rel2));
	rel2[0]=1;
	rel2[1]=2;
	rel2[2]=-1;
	assert(OK==iniRelation((dial->rel[1]),rel2));
	rel2[0]=3;
	rel2[1]=-1;
	assert(OK==iniRelation((dial->rel[2]),rel2));
	rel2[0]=4;
	rel2[1]=-1;
	assert(OK==iniRelation((dial->rel[3]),rel2));
	
	assert(busca_patron(dial,"EY, HOLA")==0);
	assert(OK==selecciona_plantilla(dial,0,dest));
	assert(!strcmp(dest,"Saludos"));
	
	assert(busca_patron(dial,"MUMBLE")==NO_ENCONTRADO);
	
	assert(busca_patron(dial,"EY, FAREWELL")==2);
	assert(OK==selecciona_plantilla(dial,2,dest));
	assert((!strcmp(dest,"Bye")) || (!strcmp(dest,"Hasta luego")));
	
	assert(ERR==selecciona_plantilla(dial,NO_ENCONTRADO,dest));
	
	assert(busca_patron(dial,"SI")==4);
	assert(OK==selecciona_plantilla(dial,4,dest));
	assert(!strcmp(dest,"NO"));
	
	assert(busca_patron(dial,"HUM")==3);
	assert(OK==selecciona_plantilla(dial,3,dest));
	assert(!strcmp(dest,"OK"));
	
	assert(tbusca_patron(dial,"HUM","Mumble")==3);
	assert(OK==selecciona_plantilla(dial,3,dest));
	assert(!strcmp(dest,"OK"));	
	
	assert(tbusca_patron(dial,"SI","Negacion")==4);
	assert(OK==selecciona_plantilla(dial,4,dest));
	assert(!strcmp(dest,"NO"));
	
	assert(selecciona_plantilla(dial,0,NULL)==ERR);
	
	assert(OK==destruyeDialogue(&dial));
	printf("Todo Correcto\n");
	return 0;
	
}
