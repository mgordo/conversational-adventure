/**/
/* @brief Cliente de pruebas del modulo jugador*/
/* Se realizan las pruebas de todas las funciones de JUGADOR que no sean llamadas directas a funciones de otros módulos, como podrían ser las funciones de inventario. */
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_jugador.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */

#include "jugador.h"

#define NUM_PRUEBAS 11
#define EXIT(X) {destruyeJugador(&j);return X;}

/*Funciones de prueba*/
/*Primera: prueba de validación de isJugDestruido*/
int prueba1()
{
	JUGADOR *j=NULL;
	
	if(isJugDestruido(j)==FALSE)
		return -1;

	j=(JUGADOR *)calloc(1,sizeof(JUGADOR));
	if(!j)
		return 100;
	else
		if(isJugDestruido(j)==TRUE)
		{
			free(j);
			return -2;
		}

	free(j);
return 0;
}

/*Segunda: prueba de creación de JUGADOR*/
int prueba2()
{
	JUGADOR *j=NULL;

	creaJugador(&j);
	if(!j)
		return -1;

	if(creaJugador(&j)!=ERR)
		EXIT(-2);
		
	if(isJugEmpty(j)!=TRUE)
		EXIT(-3);

	free(j);
return 0;
}

/*Tercera: prueba de destruyeJugador*/
int prueba3()
{
	JUGADOR *j=NULL;

	destruyeJugador(&j);
	if(j)
		return -1;
	creaJugador(&j);
	destruyeJugador(&j);
	if(j)
		return -2;
return 0;
}

/*Cuarta: prueba de cambiaIdJug*/
int prueba4()
{
	JUGADOR *j=NULL;

	if(cambiaIdJug(j,45)!=ERR)
		return -1;

	creaJugador(&j);

	if(j->id!=-1)
		EXIT(-2);
	cambiaIdJug(j,1);
	if(j->id!=1)
		EXIT(-3);
	cambiaIdJug(j,123);
	if(j->id!=123)
		EXIT(-4);

EXIT(0);
}

/*Quinta: prueba de cambiaNombreJug*/
int prueba5()
{
	JUGADOR *j=NULL;

	if(cambiaNombreJug(j,"coso")!=ERR)
		return -1;

	creaJugador(&j);
	cambiaNombreJug(j,"coso");
	if(strcmp("coso",j->nombre)!=0)
		EXIT(-2);
	cambiaNombreJug(j,"coso y cosa");
	if(strcmp("coso y cosa",j->nombre)!=0)
		EXIT(-3);

EXIT(0);
}
/*Sexta: prueba de cambiaLocalizacionJug*/
int prueba6()
{
	JUGADOR *j=NULL;

	if(cambiaLocalizacionJug(j,45)!=ERR)
		return -1;

	creaJugador(&j);

	if(j->localizacion!=-1)
		EXIT(-2);
	cambiaLocalizacionJug(j,1);
	if(j->localizacion!=1)
		EXIT(-3);
	cambiaLocalizacionJug(j,123);
	if(j->localizacion!=123)
		EXIT(-4);

EXIT(0);
}

/*Séptima: prueba de cambiaMaxObjetos*/
int prueba7()
{
	JUGADOR *j=NULL;

	if(cambiaMaxObjetos(j,45)!=ERR)
		return -1;

	creaJugador(&j);

	if(j->maxObjetos!=-1)
		EXIT(-2);
	cambiaMaxObjetos(j,1);
	if(j->maxObjetos!=1)
		EXIT(-3);
	cambiaMaxObjetos(j,123);
	if(j->maxObjetos!=123)
		EXIT(-4);

EXIT(0);
}


/*Octaba: prueba de saberNombreJug*/
int prueba8()
{
	JUGADOR *j=NULL;
	char algo[20];

	if(saberNombreJug(j,algo)!=ERR)
		return -1;

	creaJugador(&j);
	if(saberNombreJug(j,algo)!=ERR)
		EXIT(-2);
	cambiaNombreJug(j,"coso");
	saberNombreJug(j,algo);
	if(strcmp(algo,"coso")!=0)
		EXIT(-3);
	cambiaNombreJug(j,"coso y cosa");
	saberNombreJug(j,algo);
	if(strcmp(algo,"coso y cosa")!=0)
		EXIT(-4);

EXIT(0);
}


/*Novena: prueba de saberIdJug*/
int prueba9()
{
	JUGADOR *j=NULL;
	ID id;

	if(saberIdJug(j, &id)!=ERR)
		return -1;

	creaJugador(&j);
	if(saberIdJug(j, &id)!=ERR)
		EXIT(-2);

	cambiaIdJug(j,2);
	saberIdJug(j, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Décima: prueba de saberLugarJug*/
int prueba10()
{
	JUGADOR *j=NULL;
	ID id;

	if(saberLugarJug(j, &id)!=ERR)
		return -1;

	creaJugador(&j);
	if(saberLugarJug(j, &id)!=ERR)
		EXIT(-2);

	cambiaLocalizacionJug(j,2);
	saberLugarJug(j, &id);
	if(id!=2)
		EXIT(-3);

EXIT(0);
}

/*Undécima: prueba de saberMaxObjetos*/
int prueba11()
{
	JUGADOR *j=NULL;
	int num;

	if(saberMaxObjetos(j, &num)!=ERR)
		return -1;

	creaJugador(&j);
	if(saberMaxObjetos(j, &num)!=ERR)
		EXIT(-2);

	cambiaMaxObjetos(j,2);
	saberMaxObjetos(j, &num);
	if(num!=2)
		EXIT(-3);

EXIT(0);
}


/*Función main*/
int main(int argc, char **argv)
{
	if(argc<2)
	{
		printf("Número de pruebas: %d\n\nCódigos de error:\n\t-1 hubo error\n\t0 no hubo error\n\n", NUM_PRUEBAS);
		printf("Prueba 1: se prueba la funcionalidad de isJugDestruido\t%d\n", prueba1());
		printf("Prueba 2: se prueba la funcionalidad de creaJugador\t%d\n", prueba2());
		printf("Prueba 3: se prueba la funcionalidad de destruyeJugador\t%d\n", prueba3());
		printf("Prueba 4: se prueba la funcionalidad de cambiaIdJug\t%d\n", prueba4());
		printf("Prueba 5: se prueba la funcionalidad de cambiaNombreJug\t%d\n", prueba5());
		printf("Prueba 6: se prueba la funcionalidad de cambiaLocalizacionJug\t%d\n", prueba6());
		printf("Prueba 7: se prueba la funcionalidad de cambiaMaxObjetos\t%d\n", prueba7());
		printf("Prueba 8: se prueba la funcionalidad de saberNombreJug\t%d\n", prueba8());
		printf("Prueba 9: se prueba la funcionalidad de saberIdJug\t%d\n", prueba9());
		printf("Prueba 10: se prueba la funcionalidad de saberLugarJug\t%d\n", prueba10());
		printf("Prueba 11: se prueba la funcionalidad de saberMaxObjetos\t%d\n", prueba11());
	}
	else
	{
		printf("Para uso del programa:\n\t%s\n\n", argv[0]);
	}
return 0;
}
