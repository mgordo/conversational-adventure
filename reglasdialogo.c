/**/
/* reglasdialogo.c*/
/* Contiene el cuerpo de las primitivas de reglasdialogo.h*/
/* Autor: Miguel Gordo*/
/* Fecha: 29-XI-2010*/

#include"reglasdialogo.h"

DIALOGUE *creaDialogue(int tam_rules,int tam_rel,int tam_theme,int tam_plant){
	
	DIALOGUE *dial=NULL;
	if(tam_rules<=0 || tam_rel<=0 || tam_theme<=0 || tam_plant<=0) return NULL;
	
	if(!(dial=(DIALOGUE *)calloc(1,sizeof(DIALOGUE)))){
		return NULL;
	}
	
	if(!(dial->rules=(REGLAD **)calloc(tam_rules,sizeof(REGLAD *)))){
		free(dial);
		return NULL;
	}
	
	if(!(dial->rel=(RELATION **)calloc(tam_rel,sizeof(RELATION *)))){
		free(dial->rules);
		free(dial);
		return NULL;
	}
	
	if(!(dial->theme=(TEMA **)calloc(tam_theme,sizeof(TEMA *)))){
		free(dial->rel);
		free(dial->rules);
		free(dial);
		return NULL;
	}
	
	if(!(dial->plant=(PLANTILLA **)calloc(tam_plant,sizeof(PLANTILLA *)))){
		free(dial->theme);
		free(dial->rel);
		free(dial->rules);
		free(dial);
		return NULL;
	}
	dial->tam_theme=tam_theme;
	dial->tam_rel=tam_rel;
	dial->tam_rules=tam_rules;
	dial->tam_plant=tam_plant;
	return dial;
}

STATUS destruyeDialogue(DIALOGUE **dial){
	
	int i=0;
	if(dial==NULL || *dial==NULL) return OK;
	
	if((*dial)->theme){
		for(i=0;i<(*dial)->tam_theme;i++)
			destruyeTema(&((*dial)->theme[i]));
		free((*dial)->theme);
	}
	if((*dial)->rel){
		for(i=0;i<(*dial)->tam_rel;i++)
			destruyeRelation(&((*dial)->rel[i]));
		free((*dial)->rel);
	}
	if((*dial)->rules){
		for(i=0;i<(*dial)->tam_rules;i++)
			destruyeReglad(&((*dial)->rules[i]));
		 free((*dial)->rules);
	}
	if((*dial)->plant){
		for(i=0;i<(*dial)->tam_plant;i++)
			destruyePlantilla(&((*dial)->plant[i]));
		free((*dial)->plant);
	}
	free(*dial);
	*dial=NULL;
	return OK;
	
}

REGLAD *creaReglad(){

	REGLAD *rule=NULL;
	
	rule=(REGLAD *)calloc(1,sizeof(REGLAD));
	return rule;
}

STATUS destruyeReglad(REGLAD **rule){

	if(!rule || *rule==NULL) return OK;
	
	if((*rule)->patron) free((*rule)->patron);
	free((*rule));
	*rule=NULL;
	return OK;

}

PLANTILLA *creaPlantilla(){

	PLANTILLA *plant=NULL;
	plant=(PLANTILLA *)calloc(1,sizeof(PLANTILLA));
	return plant;

}

TEMA *creaTema(){

	TEMA *theme=NULL;
	theme=(TEMA *)calloc(1,sizeof(TEMA));
	return theme;

}

STATUS destruyeTema(TEMA **theme){

	if(!theme || *theme==NULL) return OK;
	
	free(*theme);
	*theme=NULL;
	return OK;

}

RELATION *creaRelation(){

	RELATION *rel=NULL;
	rel=(RELATION *)calloc(1,sizeof(RELATION));
	return rel;
}

STATUS destruyeRelation(RELATION **rel){

	if(!rel || *rel==NULL) return OK;
	
	free(*rel);
	*rel=NULL;
	return OK;

}

STATUS destruyePlantilla(PLANTILLA **plant){
	
	if(!plant || *plant==NULL) return OK;	
	
	if((*plant)->plantilla) free((*plant)->plantilla);
	free(*plant);
	*plant=NULL;
	return OK;

}

STATUS iniRelation(RELATION *rel, int *ent){
	
	int i=0;
	if(!rel || !ent) return ERR;
	
	for(i=0;ent[i]!=-1;i++){
		if(i==MAX_REGLAS) return ERR;
		rel->relacion[i]=ent[i];
	}
	if(i==MAX_REGLAS) return ERR;
	else rel->relacion[i]=ent[i]; /*-1 final*/
	return OK;
	
}

STATUS iniPlantilla(PLANTILLA *plant, char *plantilla){
	
	if(!plant || !plantilla) return ERR;
	if(!(plant->plantilla=(char *)calloc(strlen(plantilla)+1,sizeof(char)))) return ERR;
	strcpy(plant->plantilla,plantilla);
	return OK;
}

STATUS iniTema(TEMA *theme, ID id, char *nombre){
	
	if(!theme || id<0 || nombre==NULL) return ERR;
	
	theme->tema=id;
	strcpy(theme->nombre,nombre);
	return OK;
	
}

STATUS iniRegla(REGLAD *rule,int ini, int fin, char *patron){
	
		if(!rule || !patron || ini<0 || fin <0 || fin<ini) return ERR;
		
		rule->ini=ini;
		rule->fin=fin;
		rule->ult=-1;
		if(!(rule->patron=(char *)calloc(strlen(patron)+1,sizeof(char)))) return ERR;
		strcpy(rule->patron,patron);
		return OK;
}

int busca_patron(DIALOGUE *dial, char *entrada){
	
		int i,j;
		if(!dial || !entrada) return NO_ENCONTRADO;
		
		for(i=0;i<dial->tam_theme;i++){
			for(j=0;(dial->rel[i])->relacion[j]!=-1;j++){
				if(strstr(entrada,(dial->rules[(dial->rel[i])->relacion[j]])->patron)!=NULL)
					return (dial->rel[i])->relacion[j];
			}
		}
		return NO_ENCONTRADO;	
}

STATUS selecciona_plantilla(DIALOGUE *dial, int ind_patron,char *dest){
	
	int x=0;
	if(ind_patron<0 || ind_patron==NO_ENCONTRADO || !dial || !dest) return ERR;
	
	if((dial->rules[ind_patron])->fin-(dial->rules[ind_patron])->ini==0){/*Si solo hay una plantilla, devuelve la misma siempre*/
		strcpy(dest,(dial->plant[(dial->rules[ind_patron])->ini])->plantilla);
		return OK;
	}else{
		do
			x=(rand()%((dial->rules[ind_patron])->fin-(dial->rules[ind_patron])->ini+1))+(dial->rules[ind_patron])->ini;/*Genera un aleatorio entre la primera
			y la última plantilla, mientras no sea la última escrita a fin de no repetir*/
	
		while(x==(dial->rules[ind_patron])->ult);
			
		(dial->rules[ind_patron])->ult=x;
			
		strcpy(dest,(dial->plant[(dial->rules[ind_patron])->ult])->plantilla);
		return OK;
		
	}
}
	
	
STATUS guardaReglad(DIALOGUE *dial,REGLAD *rule){
	
	int i=0;
	if(!dial || !rule) return ERR;
	
	for(i=0;i<dial->tam_rules && dial->rules[i]!=NULL;i++);
	
	if(i==dial->tam_rules) return ERR;
	
	else
		dial->rules[i]=rule;
		
	return OK;
}	

STATUS guardaTema(DIALOGUE *dial,TEMA *theme){

	int i=0;
	if(!dial || !theme) return ERR;
	
	for(i=0;i<dial->tam_theme && dial->theme[i]!=NULL;i++);
	
	if(i==dial->tam_theme) return ERR;
	
	else
		dial->theme[i]=theme;
		
	return OK;
}



STATUS guardaPlantilla(DIALOGUE *dial,PLANTILLA *plant){

	int i=0;
	if(!dial || !plant) return ERR;
	
	for(i=0;i<dial->tam_plant && dial->plant[i]!=NULL;i++);
	
	if(i==dial->tam_plant) return ERR;
	
	else
		dial->plant[i]=plant;
		
	return OK;
}

STATUS guardaRelation(DIALOGUE *dial,RELATION *rel){

	int i=0;
	if(!dial || !rel) return ERR;
	
	for(i=0;i<dial->tam_rel && dial->rel[i]!=NULL;i++);
	
	if(i==dial->tam_rel) return ERR;
	
	else
		dial->rel[i]=rel;
		
	return OK;
}


int tbusca_patron(DIALOGUE *dial, char *entrada, char *ntema){

	int i,tema=NO_ENCONTRADO;
	if(!dial || !entrada || !ntema) return NO_ENCONTRADO;
	
	for(i=0;i<dial->tam_theme && tema==NO_ENCONTRADO;i++){
		if(strcmp(ntema,dial->theme[i]->nombre)==0)
			tema=i;
	}
	
	if(tema==NO_ENCONTRADO) return NO_ENCONTRADO;
	
	for(i=0;(dial->rel[tema])->relacion[i]!=-1;i++){
		if(strstr(entrada,(dial->rules[(dial->rel[tema])->relacion[i]])->patron)!=NULL)
				return (dial->rel[tema])->relacion[i];
	}
	
	return NO_ENCONTRADO;	



}






