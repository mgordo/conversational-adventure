/**/
/* Cuerpo de las primitivas de lector xml */
/* Este modulo contiene los cuerpos de los prototipos de las funciones de lectura en xml */
/* lectorxml.c */
/* Autores: Miguel Gordo y Carlos Carrascal*/
/* @version 1.0 */
/* @date 29-10-2010 */

#include "lectorxml.h"

MUNDO *iniMundo(char *nombrefich){

	xmlDocPtr doc=NULL;   /* Puntero a la estructura xmlDoc */
  	xmlNodePtr cur=NULL;  /* Puntero a la estructura xmlNode */
	xmlChar * espacios=NULL, *objetos=NULL, *jugadores=NULL, *uniones=NULL;
	MUNDO *mundo=NULL;
	int esp=0,obj=0,jug=0,uni=0;
	
	if(nombrefich==NULL) return NULL;
	
	
	doc = xmlParseFile(nombrefich);
	if(!doc)
		return NULL;
		
	
	cur = xmlDocGetRootElement(doc);
	if (!cur) {
    xmlFreeDoc(doc);
    return NULL;
  }

	if (xmlStrcmp(cur->name, (const xmlChar *) "mundo")) {/*Si no lee un mundo lo primero de todo*/
    
    		xmlFreeDoc(doc);
    		return NULL;
  	}

	/*Se requiere, en la etiqueta de mundo, cuatro atributos con el numero espacios, objetos, etc...*/
	espacios = xmlGetProp(cur, (const xmlChar *) "numero_espacios");
	if (espacios == NULL) {
      xmlFreeDoc(doc);
      return NULL;
    }

	objetos = xmlGetProp(cur, (const xmlChar *) "numero_objetos");
	if (objetos == NULL) {
      xmlFreeDoc(doc);
      return NULL;
    }
	
	jugadores = xmlGetProp(cur, (const xmlChar *) "numero_jugadores");
	if (jugadores == NULL) {
      xmlFreeDoc(doc);
      return NULL;
    }
    
    uniones = xmlGetProp(cur, (const xmlChar *) "numero_uniones");
	if (uniones == NULL) {
      xmlFreeDoc(doc);
      return NULL;
    }
    uni=atoi((char *)uniones);
    esp=atoi((char *)espacios);
    obj=atoi((char *)objetos);
    jug=atoi((char *)jugadores);
    mundo=nuevoMundo(esp, obj, jug, uni);
    
    if(!mundo){
    	xmlFreeDoc(doc);
    	return NULL;
    }
    
    
    cur = cur->xmlChildrenNode;
    
    
    while (cur != NULL) {
    if ((!xmlStrcmp(cur->name, (const xmlChar *) "espacio"))){

      if( procesaEspacio(doc, cur, mundo) != OK){
          xmlFreeDoc(doc);
          destruyeMundo(&mundo);
          return NULL;
      }
    }
    
    
    if ((!xmlStrcmp(cur->name, (const xmlChar *) "objeto"))){

      if( procesaObjeto(doc, cur, mundo) != OK){
          xmlFreeDoc(doc);
          destruyeMundo(&mundo);
          return NULL;
      }
    }
    
    if ((!xmlStrcmp(cur->name, (const xmlChar *) "jugador"))){

      if( procesaJugador(doc, cur, mundo) != OK){
          xmlFreeDoc(doc);
          destruyeMundo(&mundo);
          return NULL;
      }
    }
    
    if ((!xmlStrcmp(cur->name, (const xmlChar *) "union"))){

      if( procesaUnion(doc, cur, mundo) != OK){
          xmlFreeDoc(doc);
          destruyeMundo(&mundo);
          return NULL;
      }
    }
    
    
    
    
    cur = cur->next;
  }
    
    
  xmlFreeDoc(doc);
  return mundo;
    
    
    
}

/*FUNCIONES PARA PROCESAR JUGADORES*/

STATUS procesaJugador(xmlDocPtr doc, xmlNodePtr cur,MUNDO *mundo){
	
	JUGADOR *jug=NULL;
	xmlChar * id=NULL;
	int idint=0;
	
	
	
	if(!doc || !cur || !mundo) return ERR;
	
	if(creaJug(&jug)==ERR) return ERR;
	
	
	id = xmlGetProp(cur, (const xmlChar *) "id");
    if (id != NULL) {
    	idint=atoi((char *) id);
    	
      if(ERR==creaIdJug(jug, (ID) idint)){
      	xmlFree(id);
      	return ERR;
      }
      xmlFree(id);
    }
	
	else{
		return ERR;
	}
	

	cur = cur->xmlChildrenNode;
    while (cur != NULL) {
      if ((!xmlStrcmp(cur->name, (const xmlChar *) "nombre"))) {
          if(procesaNombreJugador(doc,cur,jug)==ERR){
    	      destruyeJugador(&jug);
              return ERR;
          }
       }if ((!xmlStrcmp(cur->name, (const xmlChar *) "localizacion"))) {
          if(procesaLocalizacionJugador(doc, cur, jug)==ERR){
	      destruyeJugador(&jug);
              return ERR;
          }
      } else if ((!xmlStrcmp(cur->name, (const xmlChar *) "max_objetos"))) {
          if(procesaMaxObjetosJugador(doc, cur,jug)==ERR){
	      destruyeJugador(&jug);
              return ERR;
          }
      } else if ((!xmlStrcmp(cur->name, (const xmlChar *) "objetos_iniciales"))) {
          if(procesaobjInvJugador(doc, cur,jug)==ERR){
	      destruyeJugador(&jug);
              return ERR;
          }
      }  
        cur = cur->next;
    }
    
	if(ERR==guardaJug(mundo, jug)){		/*ATENCION, SUSCEPTIBLE A CAMBIOS*/
		destruyeJugador(&jug);
    		return ERR;
	}

	



    return OK;


}



STATUS procesaNombreJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug){
	
	xmlChar * name=NULL;
	
	if(!doc || !cur || !jug) return ERR;

	name = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
	if(!name) return ERR;

	if(ERR==creaNombreJug(jug, (char *) name)){
		xmlFree(name);
		return ERR;
	}
	xmlFree(name);
	return OK;
} /*SE LE PEDIRÁ AL JUGADOR EL NOMBRE*/


STATUS procesaLocalizacionJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug){

	xmlChar * localizacion=NULL;
	int loc=0;
	if(!doc || !cur || !jug) return ERR;

	localizacion = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!localizacion) return ERR;

	loc=atoi((char *)localizacion);
	
	if(ERR==creaLocJug(jug,loc)){
		xmlFree(localizacion);
		return ERR;
	}
	xmlFree(localizacion);
	return OK;
	
}

STATUS procesaMaxObjetosJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug){

	xmlChar * maximo=NULL;
	int max=0;
	if(!doc || !cur || !jug) return ERR;

	maximo = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!maximo) return ERR;

	max=atoi((char *)maximo);
	
	if(ERR==creaMaxObjJug(jug,max)){
		xmlFree(maximo);
		return ERR;
	}
	xmlFree(maximo);
	return OK;

}

STATUS procesaobjInvJugador(xmlDocPtr doc,xmlNodePtr cur,JUGADOR *jug){

	xmlChar * id=NULL;
	int idint=0;
	
	if(!doc || !cur || !jug) return ERR;

	cur = cur->xmlChildrenNode;
	
	 while (cur != NULL) {
	
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "objeto"))) {

			id = xmlGetProp(cur, (const xmlChar *) "id");
			if(!id){
				return ERR;
			}else{
				idint=atoi((char *)id);
				if(ERR==meteObjJug(jug,(ID) idint)){/*Coge_objeto o que?*/
					xmlFree(id);
					return ERR;
				}
				
				id=NULL;
			}
		}

		cur = cur->next;

	}

	xmlFree(id);	
		
	return OK;

}

/*FUNCIONES DE PROCESAR ESPACIOS*/

STATUS procesaEspacio(xmlDocPtr doc,xmlNodePtr cur,MUNDO *mundo){

	xmlChar * id=NULL;
	int idint=0;
	ESPACIO *espacio=NULL;
	if(!doc || !cur || !mundo) return ERR;


	id = xmlGetProp(cur, (const xmlChar *) "id");

	if(!id) return ERR;
	else{

		idint=atoi((char *)id);
		if(ERR==creaEsp(&espacio)){
			xmlFree(id);
			return ERR;
		}

		if(ERR==creaIdEspMundo(espacio,(ID)idint)){
			xmlFree(id);
			destruyeEsp(&espacio); 
			return ERR;
		}

		xmlFree(id);
	}

	cur = cur->xmlChildrenNode; /* Primer nodo */

	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "descripcion"))) {
		      if( procesaDescripcionEspacio(doc, cur, espacio)==ERR){
				destruyeEspacio(&espacio);
			 	return ERR;
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "edescripcion"))) {
	      		if(procesaEdescripcionEspacio(doc, cur, espacio)==ERR){
			    destruyeEspacio(&espacio);
			    return ERR;
			}
		 } else if ((!xmlStrcmp(cur->name, (const xmlChar *) "norte"))) {
 		     if(procesaNorteEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
 	  	 } else if ((!xmlStrcmp(cur->name, (const xmlChar *) "sur"))) {
 		     if(procesaSurEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
 	  	 } else if ((!xmlStrcmp(cur->name, (const xmlChar *) "este"))) {
 		     if(procesaEsteEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "oeste"))) {
 		     if(procesaOesteEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "arriba"))) {
 		     if(procesaArribaEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "abajo"))) {
 		     if(procesaAbajoEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "luz_inicial"))) {/*Procesar encendido)*/
 		     if(procesaLuzEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		}else if((!xmlStrcmp(cur->name, (const xmlChar *) "descripcion_grafica"))) {
			if(procesaDescrGraficaEspacio(doc,cur,espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "objetos"))) {
 		     if(procesaObjetosEspacio(doc, cur, espacio)==ERR){
			   destruyeEspacio(&espacio);
 			   return ERR;
		     }
		}
 	   cur = cur->next;
  	}
	
	if(ERR==guardaEsp(mundo,espacio)){
		destruyeEspacio(&espacio);
		return ERR;
	}
	
	return OK;

}

STATUS procesaDescripcionEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * descrp=NULL;

	if(!doc || !cur || !espacio) return ERR;

	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp) return ERR;
	
	if(ERR==creaDescEsp(espacio, (char *)descrp)){
		xmlFree(descrp);
		return ERR;
	}

	xmlFree(descrp);
	return OK;


}

STATUS procesaDescrGraficaEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){
	
	xmlChar * descrp=NULL;
	xmlChar * filas=NULL;
	xmlChar * columnas=NULL;
	int f=-1,c=-1;
	if(!doc || !cur || !espacio) return ERR;
	
	filas = xmlGetProp(cur, (const xmlChar *) "filas");
	if(!filas) return ERR;
	columnas = xmlGetProp(cur, (const xmlChar *) "columnas");
	if(!columnas){
		xmlFree(filas);
		return ERR;
	}

	f=atoi((char *)filas);
	c=atoi((char *)columnas);
	
	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp){
		xmlFree(filas);
		xmlFree(columnas);
		return ERR;
	}
	if(ERR==creaDescrGraficaEsp(espacio, (char *)descrp,f,c)){
		xmlFree(descrp);
		xmlFree(filas);
		xmlFree(columnas);
		return ERR;
	}
	xmlFree(filas);
	xmlFree(columnas);
	xmlFree(descrp);
	return OK;
	
}

STATUS procesaEdescripcionEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * descrp=NULL;

	if(!doc || !cur || !espacio) return ERR;

	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp) return ERR;
	
	if(ERR==creaExamEsp(espacio, (char *)descrp)){
		xmlFree(descrp);
		return ERR;
	}
	
	if(descrp)
		xmlFree(descrp);
	return OK;

}


STATUS procesaNorteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * norte=NULL;
	int n=0;
	if(!doc || !cur || !espacio) return ERR;

	norte = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!norte) return ERR;

	n=atoi((char *)norte);
	
	if(ERR==creaNorteEsp(espacio,n)){
		xmlFree(norte);
		return ERR;
	}
	xmlFree(norte);
	return OK;


}


STATUS procesaSurEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * sur=NULL;
	int s=0;
	if(!doc || !cur || !espacio) return ERR;

	sur = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!sur) return ERR;

	s=atoi((char *)sur);
	
	if(ERR==creaSurEsp(espacio,s)){
		xmlFree(sur);
		return ERR;
	}
	xmlFree(sur);
	return OK;


}


STATUS procesaEsteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * este=NULL;
	int e=0;
	if(!doc || !cur || !espacio) return ERR;

	este = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!este) return ERR;

	e=atoi((char *)este);
	
	if(ERR==creaEsteEsp(espacio,e)){
		xmlFree(este);
		return ERR;
	}
	xmlFree(este);
	return OK;


}


STATUS procesaOesteEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * oeste=NULL;
	int o=0;
	if(!doc || !cur || !espacio) return ERR;

	oeste = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!oeste) return ERR;

	o=atoi((char *)oeste);
	
	if(ERR==creaOesteEsp(espacio,o)){
		xmlFree(oeste);
		return ERR;
	}
	xmlFree(oeste);
	return OK;


}


STATUS procesaArribaEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * arriba=NULL;
	int a=0;
	if(!doc || !cur || !espacio) return ERR;

	arriba = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!arriba) return ERR;

	a=atoi((char *)arriba);
	
	if(ERR==creaArribaEsp(espacio,a)){
		xmlFree(arriba);
		return ERR;
	}
	xmlFree(arriba);
	return OK;


}


STATUS procesaAbajoEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * abajo=NULL;
	int a=0;
	if(!doc || !cur || !espacio) return ERR;

	abajo = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!abajo) return ERR;

	a=atoi((char *)abajo);
	
	if(ERR==creaAbajoEsp(espacio,a)){
		xmlFree(abajo);
		return ERR;
	}
	xmlFree(abajo);
	return OK;


}



STATUS procesaLuzEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){/*Para ilumina*/

	xmlChar * luz=NULL;
	BOOL ilu=TRUE;
	if(!doc || !cur || !espacio) return ERR;

	luz = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!luz) return ERR;
	if(strcmp("TRUE",(char *)luz)==0)
		ilu=TRUE;
	else
		ilu=FALSE;
	if(ERR==creaLumEsp(espacio,ilu)){
		xmlFree(luz);
		return ERR;
	}
	xmlFree(luz);
	return OK;
	
}


STATUS procesaObjetosEspacio(xmlDocPtr doc,xmlNodePtr cur,ESPACIO *espacio){

	xmlChar * id=NULL;
	int idint=0;
	
	if(!doc || !cur || !espacio) return ERR;
	
	else{
		
	
		cur = cur->xmlChildrenNode;
		
		 while (cur != NULL) {
		
			if ((!xmlStrcmp(cur->name, (const xmlChar *) "objeto"))) {

				id = xmlGetProp(cur, (const xmlChar *) "id");
				if(!id){
					return ERR;
				}else{
					idint=atoi((char *)id);
					if(ERR==meteObjEsp(espacio,(ID) idint)){
						xmlFree(id);
						return ERR;
					}
				
				id=NULL;
				}
			}

			cur = cur->next;

		}

	xmlFree(id);	
		
	return OK;
	}
}


/*FUNCIONES PARA PROCESAR UNIONES*/

STATUS procesaUnion(xmlDocPtr doc, xmlNodePtr cur, MUNDO *mundo)
{	
	UNION *uni=NULL;
	xmlChar * id=NULL;
	int idint=0;
	
	if(!doc || !cur || !mundo) 
		return ERR;
	
	id = xmlGetProp(cur, (const xmlChar *) "id");
  	
	if (!id)	
		return ERR;
	else
	{
    		idint=atoi((char *) id);
    	
		if(creaUni(&uni)==ERR)
		{
			xmlFree(id);
			return ERR;
		}    		

		if(creaIdUniMundo(uni, (ID) idint)==ERR)
		{
    		  	xmlFree(id);
			destruyeUni(&uni);
   		   	return ERR;
      		}
      		xmlFree(id);
    	}

	cur = cur->xmlChildrenNode;

    	while (cur != NULL) {
     	
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "llegada")))
		{ 
          if(procesaIdLlegada(doc, cur, uni)==ERR)
			 {
    	     		destruyeUni(&uni);
            	return ERR;
          }
		}
		
		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "salida")))
		{
			if(procesaIdSalida(doc, cur, uni)==ERR)
			{
				destruyeUni(&uni);
              			return ERR;
          		}
		}
		else if((!xmlStrcmp(cur->name,(const xmlChar *) "key"))){
			if(procesaKeyUnion(doc,cur, uni)==ERR){
				destruyeUni(&uni);
              			return ERR;
          		}

		}
		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "abierta"))) 
		{
			if(procesaUnionAbierta(doc, cur, uni)==ERR)
			{
	      			destruyeUni(&uni);
              			return ERR;
          		}
		}

        	cur = cur->next;
    	}
    
	if(guardaUni(mundo, uni)==ERR)
	{
		destruyeUnion(&uni);
    		return ERR;
	}

    return OK;
}


STATUS procesaIdLlegada(xmlDocPtr doc,xmlNodePtr cur, UNION * uni)
{

	xmlChar * llegada=NULL;
	int a=0;

	if(!doc || !cur || !uni) 
		return ERR;

	llegada = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!llegada) 
		return ERR;

	a=atoi((char *) llegada);
	
	if(creaIdLlegadaUni(uni, a)==ERR)
	{
		xmlFree(llegada);
		return ERR;
	}
	xmlFree(llegada);
	return OK;
}


STATUS procesaIdSalida(xmlDocPtr doc,xmlNodePtr cur, UNION * uni)
{

	xmlChar * salida=NULL;
	int a=0;

	if(!doc || !cur || !uni) 
		return ERR;

	salida = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!salida) 
		return ERR;

	a=atoi((char *) salida);
	
	if(creaIdSalidaUni(uni, a)==ERR)
	{
		xmlFree(salida);
		return ERR;
	}
	xmlFree(salida);
	return OK;
}

STATUS procesaKeyUnion(xmlDocPtr doc, xmlNodePtr cur, UNION * uni){

	xmlChar * salida=NULL;
	int a=0;

	if(!doc || !cur || !uni) 
		return ERR;

	salida = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!salida) 
		return ERR;

	a=atoi((char *) salida);
	
	if(creaKeyUni(uni, a)==ERR)
	{
		xmlFree(salida);
		return ERR;
	}
	xmlFree(salida);
	return OK;

}


STATUS procesaUnionAbierta(xmlDocPtr doc, xmlNodePtr cur, UNION * uni)
{
	xmlChar * open=NULL;
	BOOL abierta=TRUE;

	if(!doc || !cur || !uni) 
		return ERR;

	open = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!open) 
		return ERR;

	if(strcmp("TRUE",(char *)open)==0)
		abierta=TRUE;
	else
		abierta=FALSE;

	if(creaAbiertaUni(uni,abierta)==ERR)
	{
		xmlFree(open);
		return ERR;
	}

	xmlFree(open);
	return OK;
}


/*FUNCIONES PARA PROCESAR OBJETOS*/



STATUS procesaObjeto(xmlDocPtr doc, xmlNodePtr cur, MUNDO *mundo)
{	
	OBJETO * objeto=NULL;
	xmlChar * id=NULL;
	int idint=0;
	
	if(!doc || !cur || !mundo) 
		return ERR;
	
	id = xmlGetProp(cur, (const xmlChar *) "id");
  	
	if (!id)	
		return ERR;
	else
	{
    		idint=atoi((char *) id);
    	
		if(creaObjeto(&objeto)==ERR)
		{
			xmlFree(id);
			return ERR;
		}    		

		if(creaIdObjMundo(objeto, (ID) idint)==ERR)
		{
    		  	xmlFree(id);
			destruyeObjeto(&objeto);
   		   	return ERR;
      		}
      		xmlFree(id);
    	}

	cur = cur->xmlChildrenNode;

    	while (cur != NULL) {
     			
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "nombre")))
		{
			if(procesaNombreObjeto(doc, cur, objeto)==ERR)
			{
				destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "descripcion"))) 
		{
			if(procesaDescripcionObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "descmovido"))) 
		{
			if(procesaDescMovido(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "descexaminar"))) 
		{
			if(procesaDescExaminar(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "movil"))) 
		{
			if(procesaMovilObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "movido"))) 
		{
			if(procesaMovidoObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}


		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "oculto"))) 
		{
			if(procesaOcultoObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}


		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "encendido"))) 
		{
			if(procesaEncendidoObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "contenedor"))) 
		{
			if(procesaContenedorObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}
		else if((!xmlStrcmp(cur->name,(const xmlChar *) "luz"))){
		
			if(procesaLuzObjeto(doc,cur,objeto)==ERR){
				destruyeObjeto(&objeto);
            return ERR;
			}
		}
		
		else if ((!xmlStrcmp(cur->name, (const xmlChar *) "inventario"))) 
		{
			if(procesaInvObjeto(doc, cur, objeto)==ERR)
			{
	      			destruyeObjeto(&objeto);
              			return ERR;
          		}
		}

        	cur = cur->next;
    	}
    
	if(guardaObj(mundo, objeto)==ERR)
	{
		destruyeObjeto(&objeto);
    		return ERR;
	}

    return OK;
}


STATUS procesaNombreObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{	
	xmlChar * name=NULL;
	
	if(!doc || !cur || !objeto)
		return ERR;

	name = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!name) 
		return ERR;

	if(creaNombreObj(objeto, (char *) name)==ERR)
	{
		xmlFree(name);
		return ERR;
	}
	xmlFree(name);
	return OK;
}


STATUS procesaDescripcionObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * descrp=NULL;

	if(!doc || !cur || !objeto)
		return ERR;

	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp) 
		return ERR;
	
	if(creaDescObj(objeto, (char *)descrp)==ERR)
	{
		xmlFree(descrp);
		return ERR;
	}

	xmlFree(descrp);
	return OK;
}


STATUS procesaDescMovido(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * descrp=NULL;

	if(!doc || !cur || !objeto)
		return ERR;

	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp) 
		return ERR;
	
	if(creaDescMovidoObj(objeto, (char *)descrp)==ERR)
	{
		xmlFree(descrp);
		return ERR;
	}

	xmlFree(descrp);
	return OK;
}


STATUS procesaDescExaminar(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * descrp=NULL;

	if(!doc || !cur || !objeto)
		return ERR;

	descrp = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

	if(!descrp) 
		return ERR;
	
	if(creaExamObj(objeto, (char *)descrp)==ERR)
	{
		xmlFree(descrp);
		return ERR;
	}

	xmlFree(descrp);
	return OK;
}


STATUS procesaMovilObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * aux1=NULL;
	BOOL aux2=TRUE;

	if(!doc || !cur || !objeto)
		return ERR;

	aux1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!aux1)
		return ERR;

	if(strcmp("TRUE",(char *)aux1)==0)
		aux2=TRUE;
	else
		aux2=FALSE;

	if(creaMovilObj(objeto, aux2)==ERR)
	{
		xmlFree(aux1);
		return ERR;
	}
	xmlFree(aux1);
	return OK;
}


STATUS procesaMovidoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * aux1=NULL;
	BOOL aux2=TRUE;

	if(!doc || !cur || !objeto)
		return ERR;

	aux1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!aux1)
		return ERR;

	if(strcmp("TRUE",(char *)aux1)==0)
		aux2=TRUE;
	else
		aux2=FALSE;

	if(creaMovidoObj(objeto, aux2)==ERR)
	{
		xmlFree(aux1);
		return ERR;
	}
	xmlFree(aux1);
	return OK;
}

STATUS procesaLuzObjeto(xmlDocPtr doc,xmlNodePtr cur,OBJETO *objeto){

	xmlChar * luz=NULL;
	BOOL ilu=TRUE;
	if(!doc || !cur || !objeto) return ERR;

	luz = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!luz) return ERR;
	if(strcmp("TRUE",(char *)luz)==0)
		ilu=TRUE;
	else
		ilu=FALSE;
	if(ERR==creaLuzObj(objeto,ilu)){
		xmlFree(luz);
		return ERR;
	}
	xmlFree(luz);
	return OK;

}

STATUS procesaOcultoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * aux1=NULL;
	BOOL aux2=TRUE;

	if(!doc || !cur || !objeto)
		return ERR;

	aux1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!aux1)
		return ERR;

	if(strcmp("TRUE",(char *)aux1)==0)
		aux2=TRUE;
	else
		aux2=FALSE;

	if(creaOcultoObj(objeto, aux2)==ERR)
	{
		xmlFree(aux1);
		return ERR;
	}
	xmlFree(aux1);
	return OK;
}


STATUS procesaEncendidoObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * aux1=NULL;
	BOOL aux2=TRUE;

	if(!doc || !cur || !objeto)
		return ERR;

	aux1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!aux1)
		return ERR;

	if(strcmp("TRUE",(char *)aux1)==0)
		aux2=TRUE;
	else
		aux2=FALSE;

	if(creaEncendidoObj(objeto, aux2)==ERR)
	{
		xmlFree(aux1);
		return ERR;
	}
	xmlFree(aux1);
	return OK;
}


STATUS procesaContenedorObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{
	xmlChar * aux1=NULL;
	BOOL aux2=TRUE;

	if(!doc || !cur || !objeto)
		return ERR;

	aux1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

	if(!aux1)
		return ERR;

	if(strcmp("TRUE",(char *)aux1)==0)
		aux2=TRUE;
	else
		aux2=FALSE;

	if(creaContenedorObj(objeto, aux2)==ERR)
	{
		xmlFree(aux1);
		return ERR;
	}
	xmlFree(aux1);
	return OK;
}

STATUS procesaInvObjeto(xmlDocPtr doc, xmlNodePtr cur, OBJETO * objeto)
{

	xmlChar * id=NULL;
	int idint=0;
	
	if(!doc || !cur || !objeto) return ERR;

	cur = cur->xmlChildrenNode;
	
	 while (cur != NULL) {
	
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "objeto"))) {

			id = xmlGetProp(cur, (const xmlChar *) "id");
			if(!id){
				return ERR;
			}else{
				idint=atoi((char *)id);
				if(ERR==meterObjObj(objeto,(ID) idint)){
					xmlFree(id);
					return ERR;
				}
				
				id=NULL;
			}
		}

		cur = cur->next;

	}

	xmlFree(id);	
		
	return OK;

}

