/**/
/* lector_reglasdialogo.c*/
/* Contiene el cuerpo de las funciones de lector_reglasdialogo.h*/
/* Autor: Miguel Gordo*/
/* Fecha: 30-XI-2010*/
#include"lector_reglasdialogo.h"

DIALOGUE *iniDialogo(char *nombrefich){
	DIALOGUE *dial=NULL;
	TEMA *theme=NULL;
	RELATION *rel=NULL;
	REGLAD *rule=NULL;
	PLANTILLA *plant=NULL;
	xmlDocPtr doc=NULL;   /* Puntero a la estructura xmlDoc */
  	xmlNodePtr cur=NULL;  /* Puntero a la estructura xmlNode */
  	int temas=0,plantillas=0,reglas=0,relaciones=0;
  	xmlChar * planti=NULL, *rules=NULL, *relations=NULL, *themes=NULL, *idtem=NULL, *ntem=NULL;
  	
  	if(nombrefich==NULL) return NULL;
  	
  	doc=xmlParseFile(nombrefich);
  	
  	if(!doc) return NULL;
  	
  	cur=xmlDocGetRootElement(doc);
  	if (!cur) {
    xmlFreeDoc(doc);
    return NULL;
  }
  
  if (xmlStrcmp(cur->name, (const xmlChar *) "dialogo")) {/*Si no lee un dialogo lo primero de todo*/
    
    		xmlFreeDoc(doc);
    		return NULL;
  	}
  	
  	themes = xmlGetProp(cur, (const xmlChar *) "temas");
  	if(!themes){
  		xmlFree(doc);
  		return NULL;
  	}
  	
  	planti=xmlGetProp(cur, (const xmlChar *) "plantillas");
  	if(!planti){
  		xmlFree(doc);
  		xmlFree(themes);
  		return NULL;
  	}
  	
  	rules=xmlGetProp(cur,(const xmlChar *) "reglas");
  	if(!rules){
  		xmlFree(doc);
  		xmlFree(themes);
  		xmlFree(planti);
  		return NULL;
  	}
  	
  	relations=xmlGetProp(cur,(const xmlChar *) "relaciones");
  	if(!relations){
  		xmlFree(doc);
  		xmlFree(themes);
  		xmlFree(planti);
  		xmlFree(rules);
  		return NULL;
  	}
  	
  	temas=atoi((char *)themes);
  	plantillas=atoi((char *)planti);
  	reglas=atoi((char *)rules);
  	relaciones=atoi((char *)relations);
  	
  	xmlFree(themes);
  	xmlFree(planti);
  	xmlFree(rules);
  	xmlFree(relations);
  	
  	dial=creaDialogue(reglas,relaciones,temas,plantillas);
  	if(!dial){
  		xmlFree(doc);
  		return NULL;
  	}
  	
  	cur = cur->xmlChildrenNode;
  	
  	while (cur != NULL) {
  	
  		if ((!xmlStrcmp(cur->name, (const xmlChar *) "tema"))){
				idtem=xmlGetProp(cur,(const xmlChar *) "id");
				if(!idtem){
					xmlFree(doc);
					destruyeDialogue(&dial);
					return NULL;
				}
				ntem=xmlGetProp(cur,(const xmlChar *) "nombre");
				if(!ntem){
					xmlFree(doc);
					xmlFree(idtem);
					destruyeDialogue(&dial);
					return NULL;
				}
			   theme=creaTema();
			   if(!theme){
			   	xmlFree(doc);
			   	xmlFree(idtem);
			   	xmlFree(ntem);
			   	destruyeDialogue(&dial);
			   	return NULL;
			   }
			   temas=atoi((char *)idtem);
			   if(iniTema(theme,temas,(char *)ntem)==ERR){
			   	xmlFree(doc);
			   	xmlFree(idtem);
			   	xmlFree(ntem);
		   		destruyeTema(&theme);
			   	destruyeDialogue(&dial);
			   	return NULL;
			   }
			   
		 	 	xmlFree(ntem);
		  		xmlFree(idtem);
		  		if(ERR==guardaTema(dial,theme)){
		  			destruyeTema(&theme);
		  			xmlFree(doc);
		  			destruyeDialogue(&dial);
		  			return NULL;
		  		}
		  		
		   
      }/*Fin primer if*/
      
      
    if ((!xmlStrcmp(cur->name, (const xmlChar *) "plantilla"))){
      	plant=creaPlantilla();
      	if(!plant){
      		xmlFree(doc);
      		destruyeDialogue(&dial);
      		return NULL;
      	}
      	if(ERR==procesaPlantilla(doc,cur,plant)){
      		xmlFree(doc);
      		destruyePlantilla(&plant);
      		destruyeDialogue(&dial);
      		return NULL;
      	}
      	if(ERR==guardaPlantilla(dial,plant)){
      		xmlFree(doc);
      		destruyePlantilla(&plant);
      		destruyeDialogue(&dial);
      		return NULL;
      	}
      
      }/*Fin segundo if*/
      
   if ((!xmlStrcmp(cur->name, (const xmlChar *) "regla"))){
   	rule=creaReglad();
   	if(!rule){
   		xmlFree(doc);
   		destruyeDialogue(&dial);
   		return NULL;
   	}
   	idtem=xmlGetProp(cur,(const xmlChar *) "ini");
   	if(!idtem){
   		xmlFree(doc);
   		destruyeDialogue(&dial);
   		destruyeReglad(&rule);
   		return NULL;
   	}
   	
   	temas=atoi((char *)idtem);
   	xmlFree(idtem);
   	idtem=xmlGetProp(cur,(const xmlChar *) "fin");
   	if(!idtem){
   		xmlFree(doc);
   		destruyeDialogue(&dial);
   		destruyeReglad(&rule);
   		return NULL;
   	}
   	
   	reglas=atoi((char *)idtem);
   	xmlFree(idtem);
		if(ERR==procesaRegla(doc,cur,rule,temas,reglas)){/*Temas y reglas tienen ini y fin*/
			destruyeReglad(&rule);
			xmlFree(doc);
			destruyeDialogue(&dial);
			return NULL;
		}
		if(ERR==guardaReglad(dial,rule)){
			xmlFree(doc);
			destruyeReglad(&rule);
			destruyeDialogue(&dial);
			return NULL;
		}
		
	}/*Fin tercer if*/
	
	if ((!xmlStrcmp(cur->name, (const xmlChar *) "relacion"))){
		rel=creaRelation();
		if(!rel){
			xmlFree(doc);
			destruyeDialogue(&dial);
			return NULL;
		}
		idtem=xmlGetProp(cur,(const xmlChar *) "number");
		if(!idtem){
			xmlFree(doc);
			destruyeRelation(&rel);
			destruyeDialogue(&dial);
			return NULL;
		}
		reglas=atoi((char *)idtem);/*reglas contiene number*/
		xmlFree(idtem);
		if(ERR==procesaRelacion(doc,cur,rel,reglas)){	
			destruyeRelation(&rel);
			xmlFree(doc);
			destruyeDialogue(&dial);
			return NULL;
		}
		if(ERR==guardaRelation(dial,rel)){
			destruyeRelation(&rel);
			xmlFree(doc);
			destruyeDialogue(&dial);
			return NULL;
		}
		
	}/*Fin cuarto if*/
   	
    cur = cur->next; 
   }/*Fin While*/
   xmlFree(doc);
   return dial;
}
  	
  STATUS procesaRegla(xmlDocPtr doc, xmlNodePtr cur,REGLAD *rule, int ini, int fin){

		
		xmlChar *patron=NULL;
		if(!cur || !doc || !rule || ini<0 || fin<ini) return ERR;
		
		patron = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
		if(!patron) return ERR;
		
		if(ERR==iniRegla(rule,ini,fin,(char *)patron)){
			xmlFree(patron);
			return ERR;
		}
		xmlFree(patron);
		return OK;		
}

STATUS procesaPlantilla(xmlDocPtr doc, xmlNodePtr cur,PLANTILLA *plant){
	
	xmlChar *plantilla=NULL;
	if(!doc || !cur || !plant) return ERR;
	plantilla = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
	if(!plantilla) return ERR;
	
	if(ERR==iniPlantilla(plant,(char *)plantilla)){
		xmlFree(plantilla);
		return ERR;
	}
	xmlFree(plantilla);
	return OK;	
}

STATUS procesaRelacion(xmlDocPtr doc, xmlNodePtr cur,RELATION *rel,int tam){
	
	int i=0,number=0;
	int *numbers=NULL;
	xmlChar *numero=NULL;
	if(!doc || !cur || !rel || tam<=0) return ERR;
	
	if(!(numbers=(int *)calloc(tam,sizeof(int)))) return ERR;
	cur = cur->xmlChildrenNode;
	while(cur!=NULL){
		 if ((!xmlStrcmp(cur->name, (const xmlChar *) "numero"))) {
			 numero = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			 if(!numero){
				 free(numbers);
				 return ERR;
			 }
			 number=atoi((char *)numero);
			 xmlFree(numero);
			 numbers[i]=number;/*Si el usuario introduce más de los debidos, no funcionará correctamente*/
			 i++;
	}
		 cur = cur->next;
	}/*Fin while*/
	
	if(iniRelation(rel,numbers)){
		free(numbers);
		return ERR;
	}
	free(numbers);
	return OK;
	
}
