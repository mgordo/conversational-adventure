/**/
/* @brief Pruebas del lector de reglas*/
/**/
/* Se encuentra el main necesario para probar todas las funciones*/
/* @file pruebas_lectorreglas.c*/
/* @author Carlos Carrascal*/
/* @date 05-12-2010*/
/**/


/*Esquema de pruebas:*/

/* En un main se utilizarán todas las funciones del modulo para comprobar su correcto funcionamiento*/
/* No se controlarán los errores de aquellas funciones que pertenecen a modulos inferiores ya que ya han sido debidamente testados*/
/* El procedimiento es el siguiente, si una funcion falla se imprimira por pantalla que funcion es y, en su caso, que apartado falla si acaso esa funcion se testea de varias maneras*/

/*Resultados:*/

/*El modulo ha superado todas las pruebas, incluido el test del programa valgrind*/

#include "lector_reglas.h"
#include "accion.h"
#include "reglas.h"
#define EXIT(x, y) {destruyeReglas(&x); free(y); return -1;}

int main()
{
	int i=-1;
	REGLAS *reglas=NULL;
	ID id=100;
	CAMPO campo=100;
	BOOL *datos=NULL;
	char frase[MAX_LEN]="\0";

	datos=(BOOL *)calloc(1,sizeof(BOOL));
	if(datos==NULL)
		return ERR;

	/*Pruebas iniReglas*/

	reglas=iniReglas("reglas_de_prueba.xml");
	if(reglas==NULL)
	{
		printf("Fallo en la funcion iniReglas()\n");
		free(datos);
		return -1;
	}

	/*Pruebas procesaConsecuencias*/

	if(saberTamanioInfluido(reglas->normas[0], &i)==ERR)
		EXIT(reglas,datos);
	if(i!=1)
		{
			printf("Fallo en la funcion 1 procesaConsecuencias()\n");
			EXIT(reglas,datos);
		}
	i=-1;

	if(saberTamanioDatosInfluido(reglas->normas[1], &i)==ERR)
		EXIT(reglas,datos);
	if(i!=sizeof(int))
		{
			printf("Fallo en la funcion 2 procesaConsecuencias()\n");
			EXIT(reglas,datos);
		}
	i=-1;

	if(saberInfluido(reglas->normas[1], &id)==ERR)
		EXIT(reglas,datos);
	if(id!=9)
		{
			printf("Fallo en la funcion 3 procesaConsecuencias()\n");
			EXIT(reglas,datos);
		}
	id=100;

	if(saberCampoInfluido(reglas->normas[0], &campo)==ERR)
			EXIT(reglas,datos);
	if(campo!=P_OCU_OBJ)
		{
			printf("Fallo en la funcion 4 procesaConsecuencias()\n");
			EXIT(reglas,datos);
		}
	campo=100;

	if(saberValorInfluido(reglas->normas[0], datos)==ERR)
		EXIT(reglas,datos);
	if(*datos!=FALSE)
		{
			printf("Fallo en la funcion 5 procesaConsecuencias()\n");
			EXIT(reglas,datos);
		}


	/*Pruebas procesaCondiciones*/

	
	if(saberTamanioDisparador(reglas->normas[0], &i)==ERR)
		EXIT(reglas,datos);
	if(i!=1)
		{
			printf("Fallo en la funcion 1 procesaCondiciones()\n");
			EXIT(reglas,datos);
		}
	i=-1;

	if(saberTamanioDatosDisparador(reglas->normas[1], &i)==ERR)
		EXIT(reglas,datos);
	if(i!=sizeof(BOOL))
		{
			printf("Fallo en la funcion 2 procesaCondiciones()\n");
			EXIT(reglas,datos);
		}
	i=-1;

	if(saberDisparador(reglas->normas[1], &id)==ERR)
		EXIT(reglas,datos);
	if(id!=8)
		{
			printf("Fallo en la funcion 3 procesaCondiciones()\n");
			EXIT(reglas,datos);
		}

	if(saberCampoDisparador(reglas->normas[2], &campo)==ERR)
			EXIT(reglas,datos);
	if(campo!=OBJ_IN_JUG)
		{
			printf("Fallo en la funcion 4 procesaCondiciones()\n");
			EXIT(reglas,datos);
		}

	if(saberValorDisparador(reglas->normas[0], datos)==ERR)
		EXIT(reglas,datos);
	if(*(int *)datos!=0)
		{
			printf("Fallo en la funcion 5 procesaCondiciones()\n");
			EXIT(reglas,datos);
		}

	/*Pruebas procesaFrase*/
	
	if(saberFrase(reglas->normas[2], frase)==ERR)
		EXIT(reglas,datos);
	if(strcmp(frase, "Se acabo!")!=0)
		{
			printf("Fallo en la funcion procesaFrase()\n");
			EXIT(reglas,datos);
		}
	
	printf("\n\nTodas las pruebas se han realizado correctamente.\n\n\a");
	destruyeReglas(&reglas);
	free(datos);
	return 1;
}
