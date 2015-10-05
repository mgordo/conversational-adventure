/**/
/* @brief Utilidades de transformacion de cadenas*/
/**/
/* Este modulo contiene las pruebas de las funciones de transformacion de cadenas*/
/* @file pruebas_UtilCadena.c*/
/* @author Carlos Carrascal*/
/* @date 23-11-2010*/
/**/

/*Esquema de pruebas:*/

/* En un main se utilizaran todas las funciones para comprobar su correcto funcionamiento*/
/* El procedimiento es el siguiente, si una funcion falla se imprimira por pantalla que funcion es y, en su caso, que apartado falla si acaso esa funcion se testea de varias maneras*/

/*Resultados:*/

/*El modulo ha superado todas las pruebas, incluido el test del programa valgrind*/

#include "UtilCadena.h"

int main()
{
	char cadena1[MAX_LEN]="\0", cadena2[MAX_LEN]="\0", cadena3[MAX_LEN]="\0", cadena4[MAX_LEN]="\0", cadena5[MAX_LEN]="\0";
	
	if(eliminaCars(cadena1, "An@kin||, *ggghhh...* yo soy tu_padre!!", "@|*_!")==ERR)
	{
		printf("Fallo en la devolucion de 1 eliminaCars\n");
		return -1;
	}

	if(strcmp(cadena1, "An kin  ,  ggghhh...  yo soy tu padre  ")!=0)
	{
		printf("Fallo en la ejecucion de 2 eliminaCars\n");
		return -1;
	}

	if(aMayusculas(cadena2, "AnAkin, ggghhh..., yo soy tu padre")==ERR)
	{
		printf("Fallo en la devolucion de 1 aMayusculas\n");
		return -1;
	}
	if(strcmp(cadena2, "ANAKIN, GGGHHH..., YO SOY TU PADRE")!=0)
	{
		printf("Fallo en la ejecucion de 2 aMayusculas\n");
		return -1;
	}

	if(reemplazaAsterisco(cadena3, "Anakin,*, yo soy tu padrastro", "hijo mio")==ERR)
	{
		printf("Fallo en la devolucion de 1 reemplazaAsterisco\n");
		return -1;
	}
	if(strcmp(cadena3, "Anakin, hijo mio, yo soy tu padrastro")!=0)
	{
		printf("Fallo en la ejecucion de 2 reemplazaAsterisco\n");
		return -1;
	}

	if(limpiaEspacios(cadena4, "  Anakin,  tio, eres un  pesaico  que no veas.  ")==ERR)
	{
		printf("Fallo en la devolucion de 1 limpiaEspacios\n");
		return -1;
	}

	if(strcmp(cadena4, "Anakin, tio, eres un pesaico que no veas.")!=0)
	{
		printf("Fallo en la ejecucion de 2 limpiaEspacios\n");
		return -1;
	}

	if(limpiaPalabras(cadena5, "ANAKIN ES LA MARIONETA DE UNOS MALOS AL FINAL")==ERR)
	{
		printf("Fallo en la devolucion de 1 limpiaPalabras\n");
		return -1;
	}

	if(strcmp(cadena5, "ANAKIN ES    MARIONETA         MALOS    FINAL")!=0)
	{
		printf("Fallo en la ejecucion de 2 limpiaPalabras\n");
		return -1;
	}

	printf("\n\nTodas las pruebas se han realizado correctamente.\n\n\a");
	return 1;
}

