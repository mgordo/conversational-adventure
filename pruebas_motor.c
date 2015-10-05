/**/
/* @brief Cliente de pruebas del modulo motor*/
/* Se realizan las pruebas de todas las funciones de PV que no sean llamadas directas a funciones de otros módulos, en cuyo caso se dirá que la función siempre funciona */
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_motor.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */


#include "motor.h"
#define EXIT(X) {if(pant) destruyePV(&pant); return X;}
#define NUM_PRUEBAS 4
#define fil 21
#define col 42
#define ver '|'
#define hor '-'
#define esq '+'


/*Prueba 1: prueba la funcionalidad de leeUsuario*/
int prueba1()
{
	char frase[50];
	PV *pant=NULL;
	
	pant=creaPV(fil,col,ver,hor,esq);	
	if(!pant)
		EXIT(-1);	
	
	
	printf("Introduce Hola:\n");
	
	leeUsuario(pant,frase);
	if(strcmp("Hola\n", frase))
		EXIT(-1);
		
	printf("Introduce Que tal:\n");
	
	leeUsuario(pant,frase);
	if(strcmp("Que tal\n", frase))
		EXIT(-2);
		
	printf("Introduce ?? te odio:\n");
	
	leeUsuario(pant,frase);
	if(strcmp("?? te odio\n", frase))
		EXIT(-3);
		
EXIT(0);				
}

/*Prueba 2: prueba la funcionalidad de creaPV*/
int prueba2()
{
return 0;
}

/*Prueba 3: prueba la funcionalidad de destruyePV*/
int prueba3()
{
return 0;
}

/*Prueba 4: prueba la funcionalidad de imprimePV*/
int prueba4()
{
	int i=0;
	/*Creamos un mundo de prueba*/
	MUNDO * m=NULL;
	OBJETO * obj1=NULL;
	JUGADOR * jug=NULL;
	ESPACIO * esp1=NULL;
	char *cadena="Prueba", resul[100], *pt=resul;

	/*Inicializamos un mundo*/
	
	m=nuevoMundo(1,1,1,1);

	creaObj(&obj1);
	creaIdObjMundo(obj1, 0);
	creaNombreObj(obj1, "caja");
	creaDescObj(obj1, "es marron");
	creaDescMovidoObj(obj1, "es pesada");
	creaExamObj(obj1, "parece vieja");
	creaMovilObj(obj1, TRUE);
	creaMovidoObj(obj1, FALSE);
	creaOcultoObj(obj1, FALSE);
	creaEncendidoObj(obj1, FALSE);
	creaContenedorObj(obj1, TRUE);
	creaLuzObj(obj1, FALSE);
	guardaObj(m, obj1);

	creaJug(&jug);
	creaIdJug(jug, 0);
	creaNombreJug(jug, "chuck");
	creaLocJug(jug, 0);
	creaMaxObjJug(jug, 2);
	guardaJug(m, jug);
	

	creaEsp(&esp1);
	creaIdEspMundo(esp1, 0);
	creaDescEsp(esp1, "arido");
	creaExamEsp(esp1, "te vas a quemar");
	meteObjEsp(esp1, 0);
	creaLumEsp(esp1, TRUE);
	guardaEsp(m, esp1);

	meteObjEsp(dameEspacio(m,0),0);

	/*Codigo de preparación del texto a introducir, que es la parte a probar*/
	darDescrEsp(dameEspacio(m,darLocJug(dameJugador(m,0))), pt, MAX_LEN);
	pt+=strlen(pt)+1;
	pt[-1]='\n';
	*pt='\n';
	pt++;
	/*Guardamos en frase los objetos del inventario*/
	strcpy(pt,"Objetos del inventario\n");
	pt+=strlen(pt);
		
	for(i=0; i<(m->numobj); i++)
	{
		if(isObjInInvMun(dameJugador(m,0),darIdObj(m->objetos[i])))
		{
			if(i!=0)
			{
				pt[0]=','; pt[1]=' '; pt+=2;
			}
			darNombreObj(dameObjeto(m,i),pt);	
			pt+=strlen(pt);
		}
	}
	*pt='\n';
	pt++;

	strcpy(pt,"Ves:\n");
	pt+=strlen(pt);
	for(i=0; i<(m->numesp); i++)
	{
		if(isObjInEspMun(dameEspacio(m,darLocJug(dameJugador(m,0))),darIdObj(m->objetos[i])))
		{
			if(i!=0)
			{
				pt[0]=','; pt[1]=' '; pt+=2;
			}
			darNombreObj(dameObjeto(m,i),pt);	
			pt+=strlen(pt);
		}
	}
	*pt='\n';
	pt++;

	/*Guardamos el resultado de la última acción*/
	strcpy(pt,cadena);
	if(strcmp(resul,"arido\n\nObjetos del inventario\n\nVes:\ncaja\nPrueba"))
	{
		destruyeMundo(&m);
		return -100;
	}

	cogeObjeto(m,obj1,jug);
	pt=resul;

	/*Repetimos con un objeto en el inventario*/
	darDescrEsp(dameEspacio(m,darLocJug(dameJugador(m,0))), pt, MAX_LEN);
	pt+=strlen(pt)+1;
	pt[-1]='\n';
	*pt='\n';
	pt++;
	/*Guardamos en frase los objetos del inventario*/
	strcpy(pt,"Objetos del inventario\n");
	pt+=strlen(pt);
		
	for(i=0; i<(m->numobj); i++)
	{
		if(i!=0)
		{
			pt[0]=','; pt[1]=' '; pt+=2;
		}
		if(isObjInInvMun(dameJugador(m,0),darIdObj(m->objetos[i])))
		{
			darNombreObj(dameObjeto(m,i),pt);	
			pt+=strlen(pt);

		}
	}
	*pt='\n';
	pt++;

	strcpy(pt,"Ves:\n");
	pt+=strlen(pt);
	for(i=0; i<(m->numobj); i++)
	{
		if(i!=0)
		{
			pt[0]=','; pt[1]=' '; pt+=2;
		}
		if(isObjInEspMun(dameEspacio(m,darLocJug(dameJugador(m,0))),darIdObj(m->objetos[i])))
		{
			darNombreObj(dameObjeto(m,i),pt);	
			pt+=strlen(pt);
		}
	}
	*pt='\n';
	pt++;

	/*Guardamos el resultado de la última acción*/
	strcpy(pt,cadena);

	if(strcmp(resul,"arido\n\nObjetos del inventario\ncaja\nVes:\n\nPrueba"))
	{
		destruyeMundo(&m);
		return -101;
	}

	destruyeMundo(&m);
return 0;
}

int main()
{
	printf("Pruebas del módulo motor grafico. Número de pruebas: %d\n\nResultados de las pruebas:\n\t-0 Salida correcta\n\t-(<0) Error\n\n", NUM_PRUEBAS);

	printf("Prueba 1: prueba la funcionalidad de leeUsuario(): %d\n", prueba1());
	printf("Prueba 2: prueba la funcionalidad de creaPV(): %d\n", prueba2());
	printf("Prueba 3: prueba la funcionalidad de destruyePV(): %d\n", prueba3());
	printf("Prueba 4: prueba la funcionalidad de imprimePV(): %d\n", prueba4());

return 0;
}
