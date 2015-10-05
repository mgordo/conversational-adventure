/**/
/* @brief Cliente de pruebas del modulo objeto*/
/* Se realizan las pruebas de todas las funciones de OBJETO que no sean llamadas directas a funciones de otros módulos, como podrían ser las funciones de inventario. */
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_objeto.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */


#include "objeto.h"

#define NUM_PRUEBAS 27
#define EXIT(X) {destruyeObjeto(&o);return X;}

/*Funciones de prueba*/
/*Primera: prueba de validación de Destruido*/
int prueba1()
{
	OBJETO *o=NULL;
	
	if(isObjDestruido(o)==FALSE)
		return -1;

	o=(OBJETO *)calloc(1,sizeof(OBJETO));
	if(!o)
		return 100;
	else
		if(isObjDestruido(o)==TRUE)
		{
			free(o);
			return -2;
		}

	free(o);
return 0;
}

/*Segunda: prueba de creación de OBJETOS*/
int prueba2()
{
	OBJETO *o=NULL;

	creaObjeto(&o);
	if(!o)
		return -1;

	if(creaObjeto(&o)==0)
		EXIT(-2);
	
	if(isObjEmpty(o)==FALSE)
		EXIT(-3);

	free(o);
return 0;
}

/*Tercera: prueba de destruyeObjeto*/
int prueba3()
{
	OBJETO *o=NULL;

	destruyeObjeto(&o);
	if(o)
		return -1;
	creaObjeto(&o);
	destruyeObjeto(&o);
	if(o)
		return -2;
return 0;
}

/*Cuarta: prueba de cambiaIdObj*/
int prueba4()
{
	OBJETO *o=NULL;

	if(cambiaIdObj(o,45)!=ERR)
		return -1;

	creaObjeto(&o);

	if(o->id!=-1)
		EXIT(-2);
	cambiaIdObj(o,1);
	if(o->id!=1)
		EXIT(-3);
	cambiaIdObj(o,123);
	if(o->id!=123)
		EXIT(-4);

EXIT(0);
}

/*Quinta: prueba de cambiaNombreObj*/
int prueba5()
{
	OBJETO *o=NULL;

	if(cambiaNombreObj(o,"coso")!=ERR)
		return -1;

	creaObjeto(&o);
	cambiaNombreObj(o,"coso");
	if(strcmp("coso",o->nombre)!=0)
		EXIT(-2);
	cambiaNombreObj(o,"coso y cosa");
	if(strcmp("coso y cosa",o->nombre)!=0)
		EXIT(-3);

EXIT(0);
}
/*Séptima: prueba de cambiaDescripcionObj*/
int prueba7()
{
	OBJETO *o=NULL;

	if(cambiaDescripcionObj(o,"coso")!=ERR)
		return -1;

	creaObjeto(&o);
	cambiaDescripcionObj(o,"coso");
	if(strcmp("coso",o->descripcion)!=0)
		EXIT(-2);
	cambiaDescripcionObj(o,"coso y cosa");
	if(strcmp("coso y cosa",o->descripcion)!=0)
		EXIT(-3);

EXIT(0);
}
/*Octaba: prueba de cambiaDescrMovido*/
int prueba8()
{
	OBJETO *o=NULL;

	if(cambiaDescrMovido(o,"coso")!=ERR)
		return -1;

	creaObjeto(&o);
	cambiaDescrMovido(o,"coso");
	if(strcmp("coso",o->descMovido)!=0)
		EXIT(-2);
	cambiaDescrMovido(o,"coso y cosa");
	if(strcmp("coso y cosa",o->descMovido)!=0)
		EXIT(-3);

EXIT(0);
}
/*Novena: prueba de cambiaDescrExamObj*/
int prueba9()
{
	OBJETO *o=NULL;

	if(cambiaDescrExamObj(o,"coso")!=ERR)
		return -1;

	creaObjeto(&o);
	cambiaDescrExamObj(o,"coso");
	if(strcmp("coso",o->descExaminar)!=0)
		EXIT(-2);
	cambiaDescrExamObj(o,"coso y cosa");
	if(strcmp("coso y cosa",o->descExaminar)!=0)
		EXIT(-3);

EXIT(0);
}
/*Décima: prueba de cambiaOculto*/
int prueba10()
{
	OBJETO *o=NULL;

	if(cambiaOculto(o,TRUE)!=ERR)
		return -1;

	creaObjeto(&o);

	cambiaOculto(o,TRUE);
	if(o->oculto!=TRUE)
		EXIT(-2);

	cambiaOculto(o,FALSE);
	if(o->oculto!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Undécima: prueba de cambiaMovil*/
int prueba11()
{
	OBJETO *o=NULL;

	if(cambiaMovil(o,TRUE)!=ERR)
		return -1;

	creaObjeto(&o);

	cambiaMovil(o,TRUE);
	if(o->movil!=TRUE)
		EXIT(-2);

	cambiaMovil(o,FALSE);
	if(o->movil!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Duedécima: prueba de cambiaMovido*/
int prueba12()
{
	OBJETO *o=NULL;

	if(cambiaMovido(o,TRUE)!=ERR)
		return -1;

	creaObjeto(&o);

	cambiaMovido(o,TRUE);
	if(o->movido!=TRUE)
		EXIT(-2);

	cambiaMovido(o,FALSE);
	if(o->movido!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimotercera: prueba de cambiaEncendido*/
int prueba13()
{
	OBJETO *o=NULL;

	if(cambiaEncendido(o,TRUE)!=ERR)
		return -1;

	creaObjeto(&o);

	cambiaEncendido(o,TRUE);
	if(o->encendido!=TRUE)
		EXIT(-2);

	cambiaEncendido(o,FALSE);
	if(o->encendido!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimocuarta: prueba de cambiaContenedor*/
int prueba14()
{
	OBJETO *o=NULL;

	if(cambiaContenedor(o,TRUE)!=ERR)
		return -1;

	creaObjeto(&o);

	cambiaContenedor(o,TRUE);
	if(o->contenedor!=TRUE)
		EXIT(-2);

	cambiaContenedor(o,FALSE);
	if(o->contenedor!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimoquinta: prueba de isMovil*/
int prueba15()
{
	OBJETO *o=NULL;

	if(isMovil(o)!=FALSE)
		return -1;

	creaObjeto(&o);

	cambiaMovil(o, TRUE);
	if(isMovil(o)!=TRUE)
		EXIT(-2);
	cambiaMovil(o,FALSE);
	if(isMovil(o)!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimosexta: prueba de isMovido*/
int prueba16()
{
	OBJETO *o=NULL;

	if(isMovido(o)!=FALSE)
		return -1;

	creaObjeto(&o);

	cambiaMovido(o, TRUE);
	if(isMovido(o)!=TRUE)
		EXIT(-2);
	cambiaMovido(o,FALSE);
	if(isMovido(o)!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimoséptima: prueba de isOculto*/
int prueba17()
{
	OBJETO *o=NULL;

	if(isOculto(o)!=FALSE)
		return -1;

	creaObjeto(&o);

	cambiaOculto(o, TRUE);
	if(isOculto(o)!=TRUE)
		EXIT(-2);
	cambiaOculto(o,FALSE);
	if(isOculto(o)!=FALSE)
		EXIT(-2);

EXIT(0);
}
/*Decimooctava: prueba de isContenedor*/
int prueba18()
{
		OBJETO *o=NULL;

	if(isContenedor(o)!=FALSE)
		return -1;

	creaObjeto(&o);

	cambiaContenedor(o, TRUE);
	if(isContenedor(o)!=TRUE)
		EXIT(-2);
	cambiaContenedor(o,FALSE);
	if(isContenedor(o)!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Decimonovena: prueba de isEncendido*/
int prueba19()
{
		OBJETO *o=NULL;

	if(isEncendido(o)!=FALSE)
		return -1;

	creaObjeto(&o);

	cambiaEncendido(o, TRUE);
	if(isEncendido(o)!=TRUE)
		EXIT(-2);
	cambiaEncendido(o,FALSE);
	if(isEncendido(o)!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Vigésima: prueba de saberNombreObj*/
int prueba20()
{
	OBJETO *o=NULL;
	char algo[20];

	if(saberNombreObj(o,algo)!=ERR)
		return -1;

	creaObjeto(&o);
	if(saberNombreObj(o,algo)!=ERR)
		EXIT(-2);
	cambiaNombreObj(o,"coso");
	saberNombreObj(o,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaNombreObj(o,"coso y cosa");
	saberNombreObj(o,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}
/*Vigesimoprimera: prueba de saberDescrObj*/
int prueba21()
{
	OBJETO *o=NULL;
	char algo[20];

	if(saberDescrObj(o,algo)!=ERR)
		return -1;

	creaObjeto(&o);
	if(saberDescrObj(o,algo)!=ERR)
		EXIT(-2);
	cambiaDescripcionObj(o,"coso");
	saberDescrObj(o,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaDescripcionObj(o,"coso y cosa");
	saberDescrObj(o,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}
/*Vigesimosegunda: prueba de saberDescrMovido*/
int prueba22()
{
	OBJETO *o=NULL;
	char algo[20];

	if(saberDescrMovido(o,algo)!=ERR)
		return -1;

	creaObjeto(&o);
	if(saberDescrMovido(o,algo)!=ERR)
		EXIT(-2);
	cambiaDescrMovido(o,"coso");
	saberDescrMovido(o,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaDescrMovido(o,"coso y cosa");
	saberDescrMovido(o,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}
/*Vigesimotercera: prueba de saberDescrExamObj*/
int prueba23()
{
	OBJETO *o=NULL;
	char algo[20];

	if(saberDescrExamObj(o,algo)!=ERR)
		return -1;

	creaObjeto(&o);
	if(saberDescrExamObj(o,algo)!=ERR)
		EXIT(-2);
	cambiaDescrExamObj(o,"coso");
	saberDescrExamObj(o,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaDescrExamObj(o,"coso y cosa");
	saberDescrExamObj(o,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}
/*Vigesimocuarta: prueba de saberIdObj*/
int prueba24()
{
	OBJETO *o=NULL;
	ID id;

	if(saberIdObj(o, &id)!=ERR)
		return -1;

	creaObjeto(&o);
	if(saberIdObj(o, &id)!=ERR)
		EXIT(-2);

	cambiaIdObj(o,2);
	saberIdObj(o, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}
/*Vigesimosexta: prueba de cambiaLuz*/
int prueba26()
{
	OBJETO *o=NULL;
	
	if(cambiaLuz(o, TRUE)!=ERR)
		return -1;
		
	creaObjeto(&o);
	
	cambiaLuz(o, TRUE);
	if(o->luz!=TRUE)
		EXIT(-2);
	
	cambiaLuz(o, FALSE);
	if(o->luz!=FALSE)
		EXIT(-3);
		
EXIT(0);
}

/*Vigesimoseptima: prueba de saberLuz*/
int prueba27()
{
	OBJETO *o=NULL;
	
	if(isLuz(o)!=FALSE)
		return -1;
		
	creaObjeto(&o);
	if(isLuz(o)!=FALSE)
		EXIT(-2);
		
	cambiaLuz(o, TRUE);
	if(isLuz(o)!=TRUE)
		EXIT(-3);
		
	cambiaLuz(o, FALSE);
	if(isLuz(o)!=FALSE)
		EXIT(-4);
		
EXIT(0);
}


/*Función main*/
int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Número de pruebas: %d\n\nCódigos de error:\n\t-1 hubo error\n\t0 no hubo error\n\n", NUM_PRUEBAS);
		printf("Prueba 1: se prueba la funcionalidad de isObjDestruido\t%d\n", prueba1());
		printf("Prueba 2: se prueba la funcionalidad de creaObjeto\t%d\n", prueba2());
		printf("Prueba 3: se prueba la funcionalidad de destruyeObjeto\t%d\n", prueba3());
		printf("Prueba 4: se prueba la funcionalidad de cambiaIdObjeto\t%d\n", prueba4());
		printf("Prueba 5: se prueba la funcionalidad de cambiaNombreObj\t%d\n", prueba5());
		printf("Prueba 7: se prueba la funcionalidad de cambiaDescripcionObj\t%d\n", prueba7());
		printf("Prueba 8: se prueba la funcionalidad de cambiaDescrMovido\t%d\n", prueba8());
		printf("Prueba 9: se prueba la funcionalidad de cambiaDescrExamObj\t%d\n", prueba9());
		printf("Prueba 10: se prueba la funcionalidad de cambiaOculto\t%d\n", prueba10());
		printf("Prueba 11: se prueba la funcionalidad de cambiaMovil\t%d\n", prueba11());
		printf("Prueba 12: se prueba la funcionalidad de cambiaMovido\t%d\n", prueba12());
		printf("Prueba 13: se prueba la funcionalidad de cambiaEncendido\t%d\n", prueba13());
		printf("Prueba 14: se prueba la funcionalidad de cambiaContenedor\t%d\n", prueba14());
		printf("Prueba 15: se prueba la funcionalidad de isMovil\t%d\n", prueba15());
		printf("Prueba 16: se prueba la funcionalidad de isMovido\t%d\n", prueba16());
		printf("Prueba 17: se prueba la funcionalidad de isOculto\t%d\n", prueba17());
		printf("Prueba 18: se prueba la funcionalidad de isContenedor\t%d\n", prueba18());
		printf("Prueba 19: se prueba la funcionalidad de isEncendido\t%d\n", prueba19());
		printf("Prueba 20: se prueba la funcionalidad de saberNombreObj\t%d\n", prueba20());
		printf("Prueba 21: se prueba la funcionalidad de saberDescrObj\t%d\n", prueba21());
		printf("Prueba 22: se prueba la funcionalidad de saberDescrMovido\t%d\n", prueba22());
		printf("Prueba 23: se prueba la funcionalidad de saberDescrExamObj\t%d\n", prueba23());
		printf("Prueba 24: se prueba la funcionalidad de saberIdObj\t%d\n", prueba24());
		printf("Prueba 26: se prueba la funcionalidad de cambiaLuz\t%d\n", prueba26());
		printf("Prueba 27: se prueba la funcionalidad de isLuz\t%d\n", prueba27());
	}
	else
	{
		printf("Para uso del programa:\n\t%s\n\n", argv[0]);
	}
return 0;
}
