/**/
/* @brief Main de prueba para el modulo accion*/
/**/
/* Contiene un main donde se prueban todas las funciones presentes en el modulo accion*/
/**/
/* @file pruebas_accion.c*/
/* @author Carlos Carrascal*/
/* @date 06-11-2010*/
/**/


#include "accion.h"

int main()
{
	ACCION * accion=NULL;
	GAMES fin=KEEP;
	char examinado[MAX_LEN];


	accion=creaAccion("mundo_de_prueba.xml", "reglas_de_prueba.xml");
	if(accion==NULL)
	{
		printf("Fallo en la funcion creaAccion()\n");
		return -1;
	}
	
	if(cambiaIdAccion(accion, COGER)==ERR)
	{
		printf("Fallo en la funcion cambiaIdAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	
	if(cambiaDAccion(accion, "Mandoble")==ERR)
	{
		printf("Fallo en la funcion 1 cambiaDAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	if(strcmp("Mandoble",accion->objetoD)!=0)
	{
		printf("Fallo en la funcion 2 cambiaDAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	
	if(cambiaIAccion(accion, "Caja")==ERR)
	{
		printf("Fallo en la funcion 1 cambiaIAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	if(strcmp("Caja",accion->objetoI)!=0)
	{
		printf("Fallo en la funcion 2 cambiaIAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}	

	if(cambiaJugDAccion(accion, "Chuck")==ERR)
	{
		printf("Fallo en la funcion 1 cambiaJugDAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	if(strcmp("Chuck",accion->jugadorD)!=0)
	{
		printf("Fallo en la funcion 2 cambiaJugDAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	if(cambiaJugIAccion(accion, "Stallone")==ERR)
	{
		printf("Fallo en la funcion 1 cambiaJugIAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	if(strcmp("Stallone",accion->jugadorI)!=0)
	{
		printf("Fallo en la funcion 2 cambiaJugIAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	if(cambiaDirAccion(accion, N)==ERR)
	{
		printf("Fallo en la funcion cambiaDirAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	if(ejecutaAccion(accion, examinado, &fin)==ERR)
	 {
		printf("Fallo en la funcion 1 ejecutaAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	cambiaIdAccion(accion, IR);

	if(ejecutaAccion(accion, examinado, &fin)==ERR)
	{
		printf("Fallo en la funcion 2 ejecutaAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	cambiaIdAccion(accion, DAR);

	if(ejecutaAccion(accion, examinado, &fin)==ERR)
	{
		printf("Fallo en la funcion 3 ejecutaAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}
	if(fin!=VICTORY)
	{
		printf("Fallo en la funcion 3 ejecutaAccion()\n");
		destruyeAccion(&accion);
		return -1;
	}

	printf("Aleluya! Mumble te lo agradeceria!\n");
	destruyeAccion(&accion);
	return 1;
}
