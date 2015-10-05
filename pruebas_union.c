/**/
/* @brief Cliente de pruebas del modulo union*/
/* Se realizan las pruebas de todas las funciones de UNION que no sean llamadas directas a funciones de otros módulos*/
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_union.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */


#include "union.h"

#define NUM_PRUEBAS 13
#define EXIT(X) {destruyeUnion(&u);return X;}

/*Funciones de prueba*/
/*Primera: prueba de validación de Destruido*/
int prueba1()
{
	UNION *u=NULL;
	
	if(isUniDestruida(u)==FALSE)
		return -1;

	u=(UNION *)calloc(1,sizeof(UNION));
	if(!u)
		return 100;
	else
		if(isUniDestruida(u)==TRUE)
		{
			free(u);
			return -2;
		}

	free(u);
return 0;
}

/*Segunda: prueba de creación de UNION*/
int prueba2()
{
	UNION *u=NULL;

	creaUnion(&u);
	if(!u)
		return -1;

	if(creaUnion(&u)==0)
		EXIT(-2);
	
	if(isUniEmpty(u)==FALSE)
		EXIT(-3);

	free(u);
return 0;
}

/*Tercera: prueba de destruyeUnion*/
int prueba3()
{
	UNION *u=NULL;

	destruyeUnion(&u);
	if(u)
		return -1;
	creaUnion(&u);
	destruyeUnion(&u);
	if(u)
		return -2;
return 0;
}

/*Cuarta: prueba de cambiaUniId*/
int prueba4()
{
	UNION *u=NULL;

	if(cambiaUniId(u,45)!=ERR)
		return -1;

	creaUnion(&u);

	if(u->id!=-1)
		EXIT(-2);
	cambiaUniId(u,1);
	if(u->id!=1)
		EXIT(-3);
	cambiaUniId(u,123);
	if(u->id!=123)
		EXIT(-4);

EXIT(0);
}


/*Quinta: prueba de cambiaUniSalida*/
int prueba5()
{
	UNION *u=NULL;

	if(cambiaUniSalida(u,45)!=ERR)
		return -1;

	creaUnion(&u);

	if(u->salida!=-1)
		EXIT(-2);
	cambiaUniSalida(u,1);
	if(u->salida!=1)
		EXIT(-3);
	cambiaUniSalida(u,123);
	if(u->salida!=123)
		EXIT(-4);

EXIT(0);
}

/*Sexta: prueba de cambiaUniLlegada*/
int prueba6()
{
	UNION *u=NULL;

	if(cambiaUniLlegada(u,45)!=ERR)
		return -1;

	creaUnion(&u);

	if(u->llegada!=-1)
		EXIT(-2);
	cambiaUniLlegada(u,1);
	if(u->llegada!=1)
		EXIT(-3);
	cambiaUniLlegada(u,123);
	if(u->llegada!=123)
		EXIT(-4);

EXIT(0);
}


/*Séptima: prueba de cambiaUniAbierta*/
int prueba7()
{
	UNION *u=NULL;

	if(cambiaUniAbierta(u,TRUE)!=ERR)
		return -1;

	creaUnion(&u);

	cambiaUniAbierta(u,TRUE);
	if(u->abierta!=TRUE)
		EXIT(-2);

	cambiaUniAbierta(u,FALSE);
	if(u->abierta!=FALSE)
		EXIT(-3);

EXIT(0);
}

/*Octava: prueba de cambiaUniKey*/
int prueba8()
{
	UNION *u=NULL;

	if(cambiaUniKey(u,45)!=ERR)
		return -1;

	creaUnion(&u);

	if(u->key!=-1)
		EXIT(-2);
	cambiaUniKey(u,1);
	if(u->key!=1)
		EXIT(-3);
	cambiaUniKey(u,123);
	if(u->key!=123)
		EXIT(-4);

EXIT(0);
}


/*Novena: prueba de isUniAbierta*/
int prueba9()
{
		UNION *u=NULL;

	if(isUniAbierta(u)!=FALSE)
		return -1;

	creaUnion(&u);

	cambiaUniAbierta(u, TRUE);
	if(isUniAbierta(u)!=TRUE)
		EXIT(-2);
	cambiaUniAbierta(u,FALSE);
	if(isUniAbierta(u)!=FALSE)
		EXIT(-3);

EXIT(0);
}
/*Décima: prueba de saberUniId*/
int prueba10()
{
	UNION *u=NULL;
	ID id;

	if(saberUniId(u, &id)!=ERR)
		return -1;

	creaUnion(&u);
	if(saberUniId(u, &id)!=ERR)
		EXIT(-2);

	cambiaUniId(u,2);
	saberUniId(u, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Undecima: prueba de saberUniSalida*/
int prueba11()
{
	UNION *u=NULL;
	ID id;

	if(saberUniSalida(u, &id)!=ERR)
		return -1;

	creaUnion(&u);
	if(saberUniSalida(u, &id)!=ERR)
		EXIT(-2);

	cambiaUniSalida(u,2);
	saberUniSalida(u, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Duodecima: prueba de saberUniLlegada*/
int prueba12()
{
	UNION *u=NULL;
	ID id;

	if(saberUniLlegada(u, &id)!=ERR)
		return -1;

	creaUnion(&u);
	if(saberUniLlegada(u, &id)!=ERR)
		EXIT(-2);

	cambiaUniLlegada(u,2);
	saberUniLlegada(u, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Decimotercera: prueba de saberUniKey*/
int prueba13()
{
	UNION *u=NULL;
	ID id;

	if(saberUniKey(u, &id)!=ERR)
		return -1;

	creaUnion(&u);
	if(saberUniKey(u, &id)!=ERR)
		EXIT(-2);

	cambiaUniKey(u,2);
	saberUniKey(u, &id);
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
		printf("Prueba 1: se prueba la funcionalidad de isUniDestruida\t%d\n", prueba1());
		printf("Prueba 2: se prueba la funcionalidad de creaUnion\t%d\n", prueba2());
		printf("Prueba 3: se prueba la funcionalidad de destruyeUnion\t%d\n", prueba3());
		printf("Prueba 4: se prueba la funcionalidad de cambiaUniId\t%d\n", prueba4());
		printf("Prueba 5: se prueba la funcionalidad de cambiaUniSalida\t%d\n", prueba5());
		printf("Prueba 6: se prueba la funcionalidad de cambiaUniLlegada\t%d\n", prueba6());
		printf("Prueba 7: se prueba la funcionalidad de cambiaUniAbierta\t%d\n", prueba7());
		printf("Prueba 8: se prueba la funcionalidad de cambiaUniKey\t%d\n", prueba8());
		printf("Prueba 9: se prueba la funcionalidad de isUniAbierta\t%d\n", prueba9());
		printf("Prueba 10: se prueba la funcionalidad de saberUniId\t%d\n", prueba10());
		printf("Prueba 11: se prueba la funcionalidad de saberUniSalida\t%d\n", prueba11());
		printf("Prueba 12: se prueba la funcionalidad de saberUniLlegada\t%d\n", prueba12());
		printf("Prueba 13: se prueba la funcionalidad de saberUniKey\t%d\n", prueba13());
	}
	else
	{
		printf("Para uso del programa:\n\t%s\n\n", argv[0]);
	}
return 0;
}
