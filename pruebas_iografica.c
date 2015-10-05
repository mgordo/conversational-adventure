
/**/
/* @brief Cliente de la interfaz Gráfica. Éste cliente no puede verificarse más que manualmente. Se imprimirán por pantalla unas indicaciones*/
/* sobre la salida esperada, y se debe ascender hasta el inicio de la ejecución para comprobar si los resultados que se describen abajo son los que el programa ha ejecutado*/
/* @file pruebas iografica.c */
/* @author Miguel Gordo*/
/* @version 1.0 */
/* @date 16-11-2010 */


#include"iografica.h"
#include<stdio.h>
#include<assert.h>
#include<string.h>

int main(){


	PANTALLA *pant=NULL;
	int i,j;
	char **matrix;
	char descr[1024];
	
	if(!(matrix=(char **)calloc(21,sizeof(char *)))) return ERR;
	
	for(i=0;i<21;i++){
		if(!(matrix[i]=(char *)calloc(47,sizeof(char)))){
			i--;
			while(i>=0)
				free(matrix[i]);
			free(matrix);
			return ERR;
		}
	}
	
	pant=creaPantalla(23,49,'|','-','+');
	assert(pant!=NULL);
	
	
	
	for(i=0;i<21;i++){
		for(j=0;j<47;j++){
			matrix[i][j]='0';
			
			if(j%2==0)
				matrix[i][j]='1';
			
		}
	}
	
	
	strcpy(descr,"Estas en el espacio de PPROG. Ves Matrix\n\tEn el suelo ves el codigo fuente\n\nTu inventario\nNo puedes hacer eso");	
	
	assert(OK==introduceDibujoPantalla(pant,matrix));
	assert(OK==introduceDescrPantalla(pant,descr));
	assert(OK==imprimePantalla(pant));
	assert(OK==borraPantalla(pant));
	assert(OK==imprimePantalla(pant));
	assert(OK==introduceDescrPantalla(pant,descr));
	assert(OK==imprimePantalla(pant));
	assert(OK==borraPantalla(pant));
	assert(OK==introduceDibujoPantalla(pant,matrix));
	assert(OK==imprimePantalla(pant));
	assert(OK==borraPantalla(pant));
	assert(OK==imprimePantalla(pant));
	
	
	for(i=0;i<21;i++)
		free(matrix[i]);
	free(matrix);
	
	assert(OK==destruyePantalla(&pant));
	
	printf("En estas pruebas se realizarán varias tareas. Compruebe si los resultados que ha obtenido concuerdan con los que aquí describimos. Ajuste su terminal a 80x24\n");
	printf("\t1) Usted debería ver como primera imagen en la sección izquierda unos y ceros, y en la sección derecha una posible descripción del juego. Acotado por los caracteres +,-,|\n");
	printf("\t2) Usted debería de ver un espacio completo de su terminal en blanco, fruto de un borrado integral\n");
	printf("\t3) Usted debería ver la misma sección derecha que en la primera prueba, salvo que no contendrá delimitadores izquierdos\n");
	printf("\t4) Usted debería ver únicamente el dibujo izquierdo de unos y ceros, perfectamente acotado\n");
	printf("\t5) Mismo resultado que en 2)\n");
	printf("\n Si usted consigue estos resultados, enhorabuena! No hay problemas con su capacidad gráfica!\n");
	
	return 0;
	
}
