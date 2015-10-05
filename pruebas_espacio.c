/**/
/* @brief Cliente de pruebas del modulo espacio*/
/* Se realizan las pruebas de todas las funciones de ESPACIO que no sean llamadas directas a funciones de otros módulos, como podrían ser las funciones de inventario. */
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_espacio.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */


#include "espacio.h"

#define NUM_PRUEBAS 24
#define EXIT(X) {destruyeEspacio(&e);return X;}

/*Funciones de prueba*/
/*Primera: prueba de validación de Destruido*/
int prueba1()
{
	ESPACIO *e=NULL;
	
	if(isEspDestruido(e)==FALSE)
		return -1;

	e=(ESPACIO *)calloc(1,sizeof(ESPACIO));
	if(!e)
		return 100;
	else
		if(isEspDestruido(e)==TRUE)
		{
			free(e);
			return -2;
		}

	free(e);
return 0;
}

/*Segunda: prueba de creación de ESPACIOS*/
int prueba2()
{
	ESPACIO *e=NULL;

	creaEspacio(&e);
	if(!e)
		return -1;

	if(creaEspacio(&e)==0)
		EXIT(-2);
	
	if(isEspEmpty(e)==FALSE)
		EXIT(-3);

	destruyeEspacio(&e);
return 0;
}

/*Tercera: prueba de destruyeEspacio*/
int prueba3()
{
	ESPACIO *e=NULL;

	destruyeEspacio(&e);
	if(e)
		return -1;
	creaEspacio(&e);
	destruyeEspacio(&e);
	if(e)
		return -2;
return 0;
}

/*Cuarta: prueba de cambiaEspId*/
int prueba4()
{
	ESPACIO *e=NULL;

	if(cambiaEspId(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->id!=-1)
		EXIT(-2);
	cambiaEspId(e,1);
	if(e->id!=1)
		EXIT(-3);
	cambiaEspId(e,123);
	if(e->id!=123)
		EXIT(-4);

EXIT(0);
}

/*Quinta: prueba de cambiaEspDescripcion*/
int prueba5()
{
	ESPACIO *e=NULL;

	if(cambiaEspDescripcion(e,"coso")!=ERR)
		return -1;

	creaEspacio(&e);
	cambiaEspDescripcion(e,"coso");
	if(strcmp("coso",e->descripcion)!=0)
		EXIT(-2);
	cambiaEspDescripcion(e,"coso y cosa");
	if(strcmp("coso y cosa",e->descripcion)!=0)
		EXIT(-3);

EXIT(0);
}


/*Sexta: prueba de cambiaEspDescExaminar*/
int prueba6()
{
	ESPACIO *e=NULL;

	if(cambiaEspDescExaminar(e,"coso")!=ERR)
		return -1;

	creaEspacio(&e);
	cambiaEspDescExaminar(e,"coso");
	if(strcmp("coso",e->descExaminar)!=0)
		EXIT(-2);
	cambiaEspDescExaminar(e,"coso y cosa");
	if(strcmp("coso y cosa",e->descExaminar)!=0)
		EXIT(-3);

EXIT(0);
}
/*Séptima: prueba de cambiaEspLuminoso*/
int prueba7()
{
	ESPACIO *e=NULL;

	if(cambiaEspLuminoso(e,TRUE)!=ERR)
		return -1;

	creaEspacio(&e);

	cambiaEspLuminoso(e,TRUE);
	if(e->luminoso!=TRUE)
		EXIT(-2);

	cambiaEspLuminoso(e,FALSE);
	if(e->luminoso!=FALSE)
		EXIT(-3);

EXIT(0);
}

/*Octava: prueba de cambiaEspNorte*/
int prueba8()
{
	ESPACIO *e=NULL;

	if(cambiaEspNorte(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->norte!=-1)
		EXIT(-2);
	cambiaEspNorte(e,1);
	if(e->norte!=1)
		EXIT(-3);
	cambiaEspNorte(e,123);
	if(e->norte!=123)
		EXIT(-4);

EXIT(0);
}

/*Novena: prueba de cambiaEspSur*/
int prueba9()
{
	ESPACIO *e=NULL;

	if(cambiaEspSur(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->sur!=-1)
		EXIT(-2);
	cambiaEspSur(e,1);
	if(e->sur!=1)
		EXIT(-3);
	cambiaEspSur(e,123);
	if(e->sur!=123)
		EXIT(-4);

EXIT(0);
}

/*Décima: prueba de cambiaEspEste*/
int prueba10()
{
	ESPACIO *e=NULL;

	if(cambiaEspEste(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->este!=-1)
		EXIT(-2);
	cambiaEspEste(e,1);
	if(e->este!=1)
		EXIT(-3);
	cambiaEspEste(e,123);
	if(e->este!=123)
		EXIT(-4);

EXIT(0);
}

/*Undécima: prueba de cambiaEspOeste*/
int prueba11()
{
	ESPACIO *e=NULL;

	if(cambiaEspOeste(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->oeste!=-1)
		EXIT(-2);
	cambiaEspOeste(e,1);
	if(e->oeste!=1)
		EXIT(-3);
	cambiaEspOeste(e,123);
	if(e->oeste!=123)
		EXIT(-4);

EXIT(0);
}

/*Duodécima: prueba de cambiaEspArriba*/
int prueba12()
{
	ESPACIO *e=NULL;

	if(cambiaEspArriba(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->arriba!=-1)
		EXIT(-2);
	cambiaEspArriba(e,1);
	if(e->arriba!=1)
		EXIT(-3);
	cambiaEspArriba(e,123);
	if(e->arriba!=123)
		EXIT(-4);

EXIT(0);
}

/*Décimotercera: prueba de cambiaEspAbajo*/
int prueba13()
{
	ESPACIO *e=NULL;

	if(cambiaEspAbajo(e,45)!=ERR)
		return -1;

	creaEspacio(&e);

	if(e->abajo!=-1)
		EXIT(-2);
	cambiaEspAbajo(e,1);
	if(e->abajo!=1)
		EXIT(-3);
	cambiaEspAbajo(e,123);
	if(e->abajo!=123)
		EXIT(-4);

EXIT(0);
}

/*Decimocuarta: prueba de isEspLuminoso*/
int prueba14()
{
	ESPACIO *e=NULL;

	if(isEspLuminoso(e)!=FALSE)
		return -1;

	creaEspacio(&e);

	cambiaEspLuminoso(e, TRUE);
	if(isEspLuminoso(e)!=TRUE)
		EXIT(-2);
	cambiaEspLuminoso(e,FALSE);
	if(isEspLuminoso(e)!=FALSE)
		EXIT(-3);

EXIT(0);
}



/*Decimoquinta: prueba de saberEspDescripcion*/
int prueba15()
{
	ESPACIO *e=NULL;
	char algo[20];

	if(saberEspDescripcion(e,algo)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspDescripcion(e,algo)!=ERR)
		EXIT(-2);
	cambiaEspDescripcion(e,"coso");
	saberEspDescripcion(e,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaEspDescripcion(e,"coso y cosa");
	saberEspDescripcion(e,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}

/*Decimosexta: prueba de saberEspDescExaminar*/
int prueba16()
{
	ESPACIO *e=NULL;
	char algo[20];

	if(saberEspDescExaminar(e,algo)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspDescExaminar(e,algo)!=ERR)
		EXIT(-2);
	cambiaEspDescExaminar(e,"coso");
	saberEspDescExaminar(e,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaEspDescExaminar(e,"coso y cosa");
	saberEspDescExaminar(e,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}
/*Decimoseptima: prueba de saberEspId*/
int prueba17()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspId(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspId(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspId(e,2);
	saberEspId(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Decimonoctava: prueba de saberEspNorte*/
int prueba18()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspNorte(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspNorte(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspNorte(e,2);
	saberEspNorte(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Decimonovena: prueba de saberEspAbajo*/
int prueba19()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspAbajo(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspAbajo(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspAbajo(e,2);
	saberEspAbajo(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}


/*Vigesima: prueba de saberEspSur*/
int prueba20()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspSur(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspSur(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspSur(e,2);
	saberEspSur(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Vigesimoprimera: prueba de saberEspEste*/
int prueba21()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspEste(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspEste(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspEste(e,2);
	saberEspEste(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Vigesimosegunda: prueba de saberEspOeste*/
int prueba22()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspOeste(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspOeste(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspOeste(e,2);
	saberEspOeste(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Vigesimotercera: prueba de saberEspArriba*/
int prueba23()
{
	ESPACIO *e=NULL;
	ID id;

	if(saberEspArriba(e, &id)!=ERR)
		return -1;

	creaEspacio(&e);
	if(saberEspArriba(e, &id)!=ERR)
		EXIT(-2);

	cambiaEspArriba(e,2);
	saberEspArriba(e, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}



/*Función main*/
int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Número de pruebas: %d\n\nCódigos de error:\n\t-1 hubo error\n\t0 no hubo error\n\n", NUM_PRUEBAS);
		printf("Prueba 1: se prueba la funcionalidad de isEspDestruido\t%d\n", prueba1());
		printf("Prueba 2: se prueba la funcionalidad de creaEspacio\t%d\n", prueba2());
		printf("Prueba 3: se prueba la funcionalidad de destruyeEspacio\t%d\n", prueba3());
		printf("Prueba 4: se prueba la funcionalidad de cambiaEspId\t%d\n", prueba4());
		printf("Prueba 5: se prueba la funcionalidad de cambiaEspDescripcion\t%d\n", prueba5());
		printf("Prueba 6: se prueba la funcionalidad de cambiaEspDescExaminar\t%d\n", prueba6());
		printf("Prueba 7: se prueba la funcionalidad de cambiaEspLuminoso\t%d\n", prueba7());
		printf("Prueba 8: se prueba la funcionalidad de cambiaEspNorte\t%d\n", prueba8());
		printf("Prueba 9: se prueba la funcionalidad de cambiaEspSur\t%d\n", prueba9());
		printf("Prueba 10: se prueba la funcionalidad de cambiaEspEste\t%d\n", prueba10());
		printf("Prueba 11: se prueba la funcionalidad de cambiaEspOeste\t%d\n", prueba11());
		printf("Prueba 12: se prueba la funcionalidad de cambiaEspArriba\t%d\n", prueba12());
		printf("Prueba 13: se prueba la funcionalidad de cambiaEspAbajo\t%d\n", prueba13());
		printf("Prueba 14: se prueba la funcionalidad de isEspLuminoso\t%d\n", prueba14());
		printf("Prueba 15: se prueba la funcionalidad de saberEspDescripcion\t%d\n", prueba15());
		printf("Prueba 16: se prueba la funcionalidad de saberEspDescExaminar\t%d\n", prueba16());
		printf("Prueba 17: se prueba la funcionalidad de saberEspId\t%d\n", prueba17());
		printf("Prueba 18: se prueba la funcionalidad de saberEspNorte\t%d\n", prueba18());
		printf("Prueba 19: se prueba la funcionalidad de saberEspAbajo\t%d\n", prueba19());
		printf("Prueba 20: se prueba la funcionalidad de saberEspSur\t%d\n", prueba20());
		printf("Prueba 21: se prueba la funcionalidad de saberEspEste\t%d\n", prueba21());
		printf("Prueba 22: se prueba la funcionalidad de saberEspOeste\t%d\n", prueba22());
		printf("Prueba 23: se prueba la funcionalidad de saberEspArriba\t%d\n", prueba23());
	}
	else
	{
		printf("Para uso del programa:\n\t%s\n\n", argv[0]);
	}
return 0;
}
