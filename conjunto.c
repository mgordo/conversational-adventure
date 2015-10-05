
#include <stdio.h>
#include "conjunto.h"


/**/
/* @brief masmemoria (interna)*/
/**/
/* masmemoria amplia el array de elementos en un factor de 2 cada vez que se la llame*/
/* @param c es puntero a Conjunto en el que ampliar la memoria reservada*/
/* @return OK si no hubo errores y ERR si los hubo*/


static STATUS masmemoria(CONJUNTO *c);

/**/
/* @brief insertsort*/

/* insertsort es el algoritmo insertsort para ordenar tablas. Ordena internamente el conjunto para hacer más eficiente la búsqueda de claves*/
/* @param c es puntero a Conjunto en el que buscar*/
/* @return OK si no hubo errores y ERR si los hubo*/


static STATUS insertsort(CONJUNTO *c);

/*IMLEMENTACIÓN de las primitivas*/

CONJUNTO *inicializarConjunto()

{
	CONJUNTO *c=NULL;
	if(!(c=(CONJUNTO *)calloc(1,sizeof(CONJUNTO))))
		return NULL;
	c->elems=NULL;
	if(!(c->elems=(ID *)calloc(16,sizeof(CONJUNTO)))){/*Inicializa el conjunto a 16 elementos*/
		free(c);
		return NULL;
	}
	c->max=16;
        c->card=0;
        return c;
        
}

STATUS destruyeConjunto(CONJUNTO **c){


	if((*c)!=NULL){
		free((*c)->elems);
		free(*c);
		*c=NULL;
		return OK;
	}else
		return ERR;
}
		

int cardinalidadConjunto(const CONJUNTO *c)

{
	if(c==NULL) return -1;
        return c->card;
        
}

BOOL esConjuntoVacio(const CONJUNTO *c)

{

        if(cardinalidadConjunto(c)==0){
                return TRUE;
        }else{
                return FALSE;
        }
       
}

BOOL estaId(const CONJUNTO *c, const ID *e)

{

	ID *resul=NULL;
	resul= (ID *)bsearch(e,c->elems,(size_t)cardinalidadConjunto(c), sizeof(ID),(int(*)(const void *, const void *)) idcompar);
	if(resul==NULL) return FALSE;
	else return TRUE;	
         
}

static STATUS insertsort(CONJUNTO *c){


	int i, j,t;
	ID temp;
	
	if(c==NULL) return ERR;	

	t=cardinalidadConjunto(c);
	for(i=1; i<t; i++){
	
		temp = c->elems[i];
		j = i-1;
			while(temp<(c->elems[j]) && j>=0){
		
				c->elems[j+1] = c->elems[j];
				j = j-1;
			}
		c->elems[j+1] = temp;
	}
	return OK;
}


static STATUS masmemoria(CONJUNTO *c){
	

	ID *mas=NULL;
	if(c==NULL) return ERR;
	
	if(!(mas=(ID *)calloc(2*c->max,sizeof(ID))))/*Aumentamos la capacidad máxima al doble cada vez que se requiera memoria*/
		return ERR;
	memcpy(mas,c->elems,c->max*sizeof(ID));
	free(c->elems);/*Tras copiar los datos liberamos la memoria antigua y reasignamos la localización del nuevo array*/
	c->elems=mas;
	c->max*=2;
	return OK;

}

STATUS insertarIdConjunto(CONJUNTO *c, const ID *e)

{

        if(estaId(c,e)==TRUE){
                return ERR;
        }
        if(cardinalidadConjunto(c)==c->max){/*Si no hubiera más memoria, reserva más*/
                if(masmemoria(c)==ERR) return ERR;
		c->elems[cardinalidadConjunto(c)]=*e;
       		c->card++;
		insertsort(c);/*Después de la inserción reordena el array*/
		return OK;
        }
	else{
      	  	 c->elems[cardinalidadConjunto(c)]=*e;
       		 c->card++;
		 insertsort(c);
        return OK;
	}
        
}


STATUS extraerIdConjunto(CONJUNTO *c, const ID e){
	
	int indice=0;
	ID temporal;

	if(c==NULL) return ERR;
	/*No se llama a estaId para no hacer dos búsquedas binarias similares*/

	else if(esConjuntoVacio(c)==TRUE) return ERR;	

	else{

		indice=indiceIdConjunto(c,&e);/*Obtengo su índice, lo intercambio con el de la última posición, resto en 1 la cardinalidad y ordeno con insertsort*/
		if(indice==-1) return ERR;
		temporal=c->elems[indice];
		c->elems[indice]=c->elems[cardinalidadConjunto(c)-1];
		c->elems[cardinalidadConjunto(c)-1]=temporal;
		c->card-=1;
		insertsort(c);
		return OK;
	}
		
}


int indiceIdConjunto(CONJUNTO *c, const ID *e){
	
	ID *resul=NULL;
	if(c==NULL || e==NULL) return -1;
	
	resul= (ID *)bsearch(e,c->elems,(size_t)cardinalidadConjunto(c), sizeof(ID),(int(*)(const void *, const void *)) idcompar);
	if(resul==NULL) return -1;
	else return resul-(c->elems);
}

ID obtenerIdConjunto(CONJUNTO * c, int indice){

	if(c==NULL || indice<0) return 0;
	
	if(indice>=cardinalidadConjunto(c)) return 0;

	else return c->elems[indice];
}



int idcompar(ID *a, ID *b){

	if((*a)-(*b)>0)
		return 1;
	if((*a)-(*b)<0)
		return -1;
	else
		return 0;
}

