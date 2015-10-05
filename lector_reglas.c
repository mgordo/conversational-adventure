 /**/
/* @brief Cuerpo de las primitivas de lector de reglas xml*/
/**/
/* Este modulo contiene el codigo de las funciones de lectura de reglas en xml*/
/* @file lectorreglas.c*/
/* @author Carlos Carrascal*/
/* @date 25-11-2010*/
/**/


#include "lector_reglas.h"

/*FUNCION PARA PROCESAR REGLA*/

STATUS procesaReglas(xmlDocPtr doc, xmlNodePtr cur, REGLA * regla)
{

	if(!doc || !cur || !regla)
		return ERR;
	
	cur = cur->xmlChildrenNode;
	cur = cur->next;
	
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "condiciones")))
		{
			if(procesaCondiciones(doc, cur, regla)==ERR)
				return ERR;
		} 
		cur = cur->next;
		cur = cur->next;

		if ((!xmlStrcmp(cur->name, (const xmlChar *) "consecuencias"))) 
		{
			if(procesaConsecuencias(doc, cur, regla)==ERR)
				return ERR;
		}
		cur = cur->next;
		cur = cur->next;

		if ((!xmlStrcmp(cur->name, (const xmlChar *) "frase"))) 
		{
			if(procesaFrase(doc, cur, regla)==ERR)
				return ERR;
		}
	        
	return OK;
}

/*FUNCION PARA PROCESAR CONDICIONES*/

STATUS procesaCondiciones(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla)
{
	xmlChar * num_cond=NULL, * aux=NULL;
	int numcond=0, i=0, j=0;
	ID * id=NULL;
	ID num=-1;
	BOOL bol=FALSE;
	CAMPO * key=NULL, campo;
	void * valor=NULL;
	char *medio=NULL, *medio1=NULL;

	if(!doc || !cur || !regla)
		return ERR;
	

	num_cond = xmlGetProp(cur, (const xmlChar *) "num_cond");
	if (!num_cond) 
      	return ERR;

  	numcond=atoi((char *)num_cond);

	if(cambiaTamanioDisparador(regla, numcond)==ERR)
		return ERR;
		
	id=(ID*)calloc(numcond,sizeof(ID));
	if(!id)
		return ERR;

	key=(CAMPO*)calloc(numcond,sizeof(CAMPO));
	if(!key)
		return ERR;

	valor=(void *)calloc(numcond*2,sizeof(double));
	if(!valor)
		return ERR;

	cur = cur->xmlChildrenNode;
	cur = cur->next;

	while(cur!=NULL)
	{
		if(xmlStrcmp(cur->name,(const xmlChar *)"condicion")!=0)
		{
			cur=cur->next;
			continue;
		}

		aux = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

		medio1=strtok((char *)aux, ",");
		if(!medio1)
			return ERR;
			
		campo=seleccionaCampo(medio1);
		
		memcpy(key+i, &campo, sizeof(CAMPO));


		medio=strtok(NULL, ",");
		if(!medio)
			return ERR;
				
		num=atoi(medio);
		
		memcpy(id+i, &num, sizeof(ID));
			
			
		if((strcmp(medio1, "OBJ_IN_OBJ")==0) || (strcmp(medio1, "OBJ_IN_JUG")==0) || (strcmp(medio1, "OBJ_IN_ESP")==0) || (strcmp(medio1, "LOC_JUG")==0) )
		{
			medio=strtok(NULL, ",");
			if(!medio)
				return ERR;

			num=atoi(medio);

			memcpy(valor+j, &num, sizeof(ID));
			j+=sizeof(ID);
		}
		
		medio=strtok(NULL, ",");
			if(!medio)
				return ERR;

		if(strcmp(medio,"TRUE")==0)
			bol=TRUE;
		else if(strcmp(medio,"FALSE")==0)
			bol=FALSE;
		else
			return ERR;
		
		memcpy(valor+j,&bol,sizeof(BOOL));
		
		j+=sizeof(BOOL);
		
		cur = cur->next;
		i++;
  	}
	

	if(cambiaDisparador(regla, id, numcond)==ERR)
		return ERR;

	if(cambiaCampoDisparador(regla, key, numcond)==ERR)
		return ERR;

	if(cambiaValorDisparador(regla, valor, j)==ERR)
		return ERR;
		
	if(cambiaTamanioDatosDisparador(regla,j)==ERR)
		return ERR;
	
	free(id);
	free(key);
	free(valor);

	return OK;
}	


/*FUNCION PARA PROCESAR CONSECUENCIAS*/

STATUS procesaConsecuencias(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla)
{
	xmlChar * num_cons=NULL,* aux=NULL;

	int numcons=0, i=0, j=0;
	ID * id=NULL;
	ID num=-1;
	BOOL bol=FALSE;
	CAMPO * key=NULL, campo;
	void * valor=NULL;
	char *medio=NULL, *medio1=NULL;

	if(!doc || !cur || !regla)
		return ERR;
	

	num_cons = xmlGetProp(cur, (const xmlChar *) "num_cons");
	if (!num_cons) 
      	return ERR;

   numcons=atoi((char *)num_cons);

	if(cambiaTamanioInfluido(regla, numcons)==ERR)
		return ERR;
		
	id=(ID*)calloc(numcons,sizeof(ID));
	if(!id)
		return ERR;

	key=(CAMPO*)calloc(numcons,sizeof(CAMPO));
	if(!key)
		return ERR;

	valor=(void *)calloc(numcons*2,sizeof(double));
	if(!valor)
		return ERR;

	cur = cur->xmlChildrenNode;
	cur = cur->next;

	while(cur!=NULL)
	{
		if(xmlStrcmp(cur->name,(const xmlChar *)"consecuencia")!=0)
		{
			cur=cur->next;
			continue;
		}
		
		aux = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

		medio1=strtok((char *)aux, ",");
		if(!medio1)
			return ERR;
			
		campo=seleccionaCampo(medio1);
		
		memcpy(key+i, &campo, sizeof(CAMPO));
		
		if(campo==WIN_GAME || campo==LOSE_GAME)
		{
			cur = cur->next;
			break;		
		}


		medio=strtok(NULL, ",");
			if(!medio)
				return ERR;
				
		num=atoi(medio);
		
		memcpy(id+i, &num, sizeof(ID));
			
			
		medio=strtok(NULL, ",");
			if(!medio)
				return ERR;


		if(campo==P_OCU_OBJ||campo==P_ENC_OBJ||campo==P_CON_OBJ||campo==P_LUZ_OBJ||campo==P_LUM_ESP||campo==P_ABI_UNI||campo==P_MOV_OBJ)
		{
			if(strcmp(medio,"TRUE")==0)
				bol=TRUE;
			else if(strcmp(medio,"FALSE")==0)
				bol=FALSE;
			else
				return ERR;
				
			memcpy(valor+j,&bol,sizeof(BOOL));
			j+=sizeof(BOOL);
		}
		else
		{
			num=atoi(medio);
			memcpy(valor+j,&num,sizeof(ID));		
			j+=sizeof(ID);
		}
		
		cur = cur->next;
		i++;
	}

	
	if(cambiaInfluido(regla, id, numcons)==ERR)
		return ERR;

	if(cambiaCampoInfluido(regla, key, numcons)==ERR)
		return ERR;

	if(cambiaValorInfluido(regla, valor, j)==ERR)
		return ERR;
		
	if(cambiaTamanioDatosInfluido(regla,j)==ERR)
		return ERR;

	free(id);
	free(key);
	free(valor);

	return OK;
}


/*FUNCION PARA PROCESAR FRASE*/

STATUS procesaFrase(xmlDocPtr doc,xmlNodePtr cur, REGLA *regla)
{
	xmlChar * frase=NULL;

	if(!doc || !cur || !regla)
		return ERR;
	
	frase = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(cambiaFrase(regla, (char *)frase)==ERR)
			return ERR;

	return OK;
}


REGLAS *iniReglas(char *nombrefich)
{
	xmlDocPtr doc=NULL;
  	xmlNodePtr cur=NULL;
	xmlChar * num_reglas=NULL;
	int numreglas=0, i=0;
	REGLAS * reglas=NULL;
	
	if(!nombrefich) 
		return NULL;
	
	doc = xmlParseFile(nombrefich);
	if(!doc)
		return NULL;
		
	cur = xmlDocGetRootElement(doc);
	if (!cur) 
	{
   		xmlFreeDoc(doc);
    	return NULL;
  	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "reglas"))
	{
     	xmlFreeDoc(doc);
    	return NULL;
  	}

	num_reglas = xmlGetProp(cur, (const xmlChar *) "numero_reglas");
	if (num_reglas == NULL) 
	{
		xmlFreeDoc(doc);
      	return NULL;
   	}

    numreglas=atoi((char *)num_reglas);
    
	reglas=creaReglas(numreglas); 
	if(!reglas)
	{
      xmlFreeDoc(doc);
      return NULL;
   } 
    
    cur = cur->xmlChildrenNode;
    cur = cur->next;
        
    for(i=0;i<numreglas;i++)
	 {
    	if ((!xmlStrcmp(cur->name, (const xmlChar *) "regla")))
		{
			if(procesaReglas(doc, cur, reglas->normas[i]) != OK)
			{
				destruyeReglas(&reglas);
		   			xmlFreeDoc(doc);
         			return NULL;
      	}
    	} 
    	else
    		i--;   
    	cur = cur->next;
    	cur = cur->next;
  	}
    
  xmlFreeDoc(doc);
  return reglas;   
}

/*FUNCION AUXILIAR*/

CAMPO seleccionaCampo(char *medio1)
{
	if(medio1==NULL)
		return ERR;


		if(strcmp(medio1,"P_LOC_OBJ")==0)
			return P_LOC_OBJ;
		else if(strcmp(medio1,"P_MOV_OBJ")==0)
			return P_MOV_OBJ;
		else if(strcmp(medio1,"P_OCU_OBJ")==0)
			return P_OCU_OBJ;
		else if(strcmp(medio1,"P_ENC_OBJ")==0)
			return P_ENC_OBJ;
		else if(strcmp(medio1,"P_CON_OBJ")==0)
			return P_CON_OBJ;
		else if(strcmp(medio1,"P_LUZ_OBJ")==0)
			return P_LUZ_OBJ;
		else if(strcmp(medio1,"P_LOC_JUG")==0)
			return P_LOC_JUG;
		else if(strcmp(medio1,"P_MAX_JUG")==0)
			return P_MAX_JUG;
		else if(strcmp(medio1,"P_LUM_ESP")==0)
			return P_LUM_ESP;
		else if(strcmp(medio1,"P_NOR_ESP")==0)
			return P_NOR_ESP;
		else if(strcmp(medio1,"P_SUR_ESP")==0)
			return P_SUR_ESP;
		else if(strcmp(medio1,"P_EST_ESP")==0)
			return P_EST_ESP;
		else if(strcmp(medio1,"p_OES_ESP")==0)
			return P_OES_ESP;
		else if(strcmp(medio1,"P_ARR_ESP")==0)
			return P_ARR_ESP;
		else if(strcmp(medio1,"P_ABA_ESP")==0)
			return P_ABA_ESP;
		else if(strcmp(medio1,"P_ABI_UNI")==0)
			return P_ABI_UNI;
		else if(strcmp(medio1,"LOC_OBJ")==0)
			return LOC_OBJ;
		else if(strcmp(medio1,"MOV_OBJ")==0)
			return MOV_OBJ;
		else if(strcmp(medio1,"MOVI_OBJ")==0)
			return MOVI_OBJ;
		else if(strcmp(medio1,"OCU_OBJ")==0)
			return OCU_OBJ;
		else if(strcmp(medio1,"ENC_OBJ")==0)
			return ENC_OBJ;
		else if(strcmp(medio1,"LOC_JUG")==0)
			return LOC_JUG;
		else if(strcmp(medio1,"LUM_ESP")==0)
			return LUM_ESP;
		else if(strcmp(medio1,"ABI_UNI")==0)
			return ABI_UNI;
		else if(strcmp(medio1,"KEY_UNI")==0)
			return KEY_UNI;
		else if(strcmp(medio1,"OBJ_IN_OBJ")==0)
			return OBJ_IN_OBJ;
		else if(strcmp(medio1,"OBJ_IN_JUG")==0)
			return OBJ_IN_JUG;
		else if(strcmp(medio1,"OBJ_IN_ESP")==0)
			return OBJ_IN_ESP;
		else if(strcmp(medio1,"WIN_GAME")==0)
			return WIN_GAME;
		else if(strcmp(medio1,"LOSE_GAME")==0)
			return LOSE_GAME;
		else
			return -1;
	
}
