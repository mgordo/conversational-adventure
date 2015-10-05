#include"iografica.h"
#include<stdio.h>

PANTALLA *creaPantalla(int filasizq, int columnasizq ,char columna, char fila, char esquina){
		
		PANTALLA *pant=NULL;
		int i=0;
		if(filasizq<21 || columnasizq<42 || columnasizq>MAX_COLUMNAS || filasizq>MAX_FILAS) return NULL;
		
		if(!(pant=(PANTALLA *)calloc(1,sizeof(PANTALLA))))
			return NULL;
		
		pant->filasI=filasizq;
		pant->columnasI=columnasizq;
		pant->filasD=filasizq;
		pant->columnasD=MAX_COLUMNAS-columnasizq;
		pant->columna=columna;
		pant->fila=fila;
		pant->esquina=esquina;
		
		if(!(pant->matrixI=(char **) calloc(pant->filasI,sizeof(char *)))){
			free(pant);
			return NULL;
		}
		
		if(!(pant->matrixI[0]=(char *)calloc(pant->filasI*pant->columnasI,sizeof(char)))){
			free(pant->matrixI);
			free(pant);
			return NULL;
		}
		
		if(!(pant->matrixD=(char **)calloc(pant->filasD,sizeof(char *)))){
			free(pant->matrixI[0]);
			free(pant->matrixI);
			free(pant);
			return NULL;
		}
		
		if(!(pant->matrixD[0]=(char *)calloc(pant->filasD*pant->columnasD,sizeof(char)))){
			free(pant->matrixI[0]);
			free(pant->matrixI);
			free(pant->matrixD);
			free(pant);
			return NULL;
		}
		
		for(i=1;i<pant->filasI;i++)
			pant->matrixI[i]=&(pant->matrixI[0][i*pant->columnasI]);
			
		for(i=1;i<pant->filasD;i++)
			pant->matrixD[i]=&(pant->matrixD[0][i*pant->columnasD]);
			
		return pant;
}
		

STATUS destruyePantalla(PANTALLA **pant){
	
		if(pant==NULL || *pant==NULL) return OK;
		
		free((*pant)->matrixD[0]);
		free((*pant)->matrixD);
		free((*pant)->matrixI[0]);
		free((*pant)->matrixI);
		free(*pant);
		*pant=NULL;
		return OK;

}

STATUS imprimePantalla(PANTALLA *pant){
	
	int i,j;
	
	if(pant==NULL) return ERR;
	
	system("clear");
	for(i=0;i<pant->filasI;i++){
		for(j=0;j<pant->columnasI;j++){
			printf("%c",pant->matrixI[i][j]);
		}
		for(j=0;j<pant->columnasD;j++){
			printf("%c",pant->matrixD[i][j]);
		}
		printf("\n");
	}
	
	return OK;
	
}

STATUS borraPantalla(PANTALLA *pant){
	
	int i,j;
	
	if(pant==NULL) return ERR;
	
	for(i=0;i<pant->filasI;i++){
		for(j=0;j<pant->columnasI;j++){
			pant->matrixI[i][j]=' ';
		}
		for(j=0;j<pant->columnasD;j++){
			pant->matrixD[i][j]=' ';
		}
	}
	
	return OK;
	
}

STATUS introduceDibujoPantalla(PANTALLA *pant, char **dibujo){
	
	int i,j;
	
	if(pant==NULL || dibujo==NULL) return ERR;
	
	pant->matrixI[0][0]=pant->esquina;
	pant->matrixI[0][pant->columnasI -1]=pant->esquina;
	pant->matrixI[pant->filasI -1][0]=pant->esquina;
	pant->matrixI[pant->filasI -1][pant->columnasI -1]=pant->esquina;
	
	for(i=1;i<pant->columnasI-1;i++){
		pant->matrixI[0][i]=pant->fila;
		pant->matrixI[pant->filasI-1][i]=pant->fila;
	}
	
	for(i=1;i<pant->filasI-1;i++){
		pant->matrixI[i][0]=pant->columna;
		pant->matrixI[i][pant->columnasI-1]=pant->columna;
	}
	
	for(i=1;i<pant->filasI-1;i++){
		for(j=1;j<pant->columnasI-1;j++){
			pant->matrixI[i][j]=dibujo[i-1][j-1];
		}
	}
	
	return OK;
	
}

STATUS introduceDescrPantalla(PANTALLA *pant,char *descr){
	
	int i=0,j=0,t=0,k=0;
	
	if(pant==NULL || descr==NULL) return ERR;
	
	pant->matrixD[0][pant->columnasD-1]=pant->esquina;
	pant->matrixD[pant->filasD-1][pant->columnasD-1]=pant->esquina;
	
	for(i=0;i<pant->columnasD-1;i++){/*Bucle para copiar los delimitadores superiores o inferiores*/
		pant->matrixD[0][i]=pant->fila;
		pant->matrixD[pant->filasD-1][i]=pant->fila;
	}
	for(i=1;i<pant->filasD-1;i++){/*Bucle de filas*/
		pant->matrixD[i][pant->columnasD-1]=pant->columna;
		for(j=0;j<pant->columnasD-1;j++){/*Bucle de columnas*/
			
			if(j==pant->columnasD-2){
					pant->matrixD[i][j]=' ';
			
			}else if(descr[t]=='\n'){/*Si hay \n o \t pasa a la siguiente línea*/
				for(;j<pant->columnasD-1;j++)
					pant->matrixD[i][j]=' ';
				t++;
			}else if(descr[t]=='\t'){
				k=0;
				while((j<pant->columnasD-1) && k<2){
					pant->matrixD[i][j]=' ';
					if(k!=1)
						j++;
					k++;
				}
				t++;
			}else if(descr[t]!='\0'){
				pant->matrixD[i][j]=descr[t];
				t++;
			}else if(descr[t]=='\0')
				pant->matrixD[i][j]=' ';
		}
	
	}
	return OK;
}

STATUS leePantalla(PANTALLA *pant, char *lectura, int tamanio){
	
	if(pant==NULL || lectura==NULL) return ERR;
	
	printf("> ");
	if(!fgets(lectura,tamanio,stdin)) return ERR;
	
	else return OK;
	
	
}


