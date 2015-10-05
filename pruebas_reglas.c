/**/
/* @brief Cliente de pruebas del modulo reglas*/
/* Se realizan las pruebas de todas las funciones de REGLA que no sean llamadas directas a funciones de otros módulos.*/
/* Por todo lo demás, se hará una función para cada funcionalidad posible, comprobando los casos posibles y devolviendo 0 si se realizan correctamente- Para facilitar la corrección se devuelve un número negativo para cada error posible. */
/* El main que se contiene en este fichero ejecuta todas las pruebas e imprime el resultado por pantalla */
/* @file pruebas_reglas.c */
/* @author Antonio Jiménez*/
/* @version 1.0 */

/*Includes y defines*/
#include "reglas.h"
#include "lectorxml.h"
#define EXIT(X) {if(r) destruyeRegla(&r);return X;}
#define NUM_PRUEBAS 30

/*Funciones de prueba*/

/*Prueba 1: prueba la funcionalidad de creaRegla()*/
int prueba1()
{
	REGLA *r=NULL;

	creaRegla(&r);
	if(!r)
		EXIT(-1);
	if(isEmptyRegla(r)==FALSE)
		EXIT(-2);
	if(creaRegla(&r)!=ERR)
		EXIT(-3);
	if(isEmptyRegla(r)==FALSE)
		EXIT(-4);

	EXIT(0);
}

/*Prueba 2: prueba la funcionalidad de destruyeRegla()*/
int prueba2()
{
	REGLA *r=NULL;

	if(destruyeRegla(&r)!=OK)
		EXIT(-1);
	if(r)
		EXIT(-2);
	creaRegla(&r);
	if(destruyeRegla(&r)!=OK)
		EXIT(-3);
	if(r)
		EXIT(-4);

	EXIT(0);
}


/*Prueba 4: prueba la funcionalidad de cambiaTamanioInfluido()*/
int prueba4()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;

	creaRegla(&r);
	if(cambiaTamanioInfluido(r,i1)!=OK)
		EXIT(-1);
	if(r->num_influido!=i1)
		EXIT(-2);
	if(cambiaTamanioInfluido(r,i2)!=OK)
		EXIT(-3);
	if(r->num_influido!=i2)
		EXIT(-4);
	if(cambiaTamanioInfluido(r,i3)!=ERR)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 5: prueba la funcionalidad de cambiaTamanioDatosInfluido()*/
int prueba5()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;

	creaRegla(&r);
	if(cambiaTamanioDatosInfluido(r,i1)!=OK)
		EXIT(-1);
	if(r->tam_datos_i!=i1)
		EXIT(-2);
	if(cambiaTamanioDatosInfluido(r,i2)!=OK)
		EXIT(-3);
	if(r->tam_datos_i!=i2)
		EXIT(-4);
	if(cambiaTamanioDatosInfluido(r,i3)!=ERR)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 6: prueba la funcionalidad de cambiaInfluido()*/
int prueba6()
{
	REGLA *r=NULL;
	int i;
	ID ids1[10]={0,1,2,3,4,5,6,7,8,9}, ids2[5]={1,2,3,4,5};

	if(cambiaInfluido(r,ids1,10)!=ERR)
		EXIT(-1);
	
	creaRegla(&r);

	if(cambiaInfluido(r,ids1,10)==ERR)
		EXIT(-2);
	for(i=0;i<10;i++)
		if((r->influido)[i]!=i)
			EXIT(-3);

	if(cambiaInfluido(r,ids2,5)==ERR)
		EXIT(-4);
	for(i=0;i<5;i++)
		if((r->influido)[i]!=i+1)
			EXIT(-5);

	EXIT(0);
}

/*Prueba 7: prueba la funcionalidad de cambiaCampoInfluido()*/
int prueba7()
{
	REGLA *r=NULL;
	int i;
	CAMPO ids1[10]={0,1,2,3,4,5,6,7,8,9}, ids2[5]={1,2,3,4,5};

	if(cambiaCampoInfluido(r,ids1,10)!=ERR)
		EXIT(-1);
	
	creaRegla(&r);

	if(cambiaCampoInfluido(r,ids1,10)==ERR)
		EXIT(-2);
	for(i=0;i<10;i++)
		if((r->c)[i]!=i)
			EXIT(-3);

	if(cambiaCampoInfluido(r,ids2,5)==ERR)
		EXIT(-4);
	for(i=0;i<5;i++)
		if((r->c)[i]!=i+1)
			EXIT(-5);

	EXIT(0);
}

/*Prueba 8: prueba la funcionalidad de cambiaValorInfluido()*/
int prueba8()
{
	REGLA *r=NULL;
	char *cosa1="Hola", *cosa2="opKDPOkdajpAJ";
	int j=10;

	
	if(cambiaValorInfluido(r,cosa1,5)!=ERR)
		EXIT(-1);

	creaRegla(&r);

	if(cambiaValorInfluido(r,cosa1,-20)!=ERR)
		EXIT(-2);
	if(cambiaValorInfluido(r,NULL,10)!=ERR)
		EXIT(-3);

	if(cambiaValorInfluido(r,cosa1,5)==ERR)
		EXIT(-4);
	if(strcmp(r->valor_cam,cosa1)!=0)
		EXIT(-5);

	if(cambiaValorInfluido(r,cosa2,14)==ERR)
		EXIT(-6);
	if(strcmp(r->valor_cam,cosa2)!=0)
		EXIT(-7);

	if(cambiaValorInfluido(r,&j,sizeof(int))==ERR)
		EXIT(-8);
	if(memcmp(r->valor_cam,&j,sizeof(int))!=0)
		EXIT(-9);

	EXIT(0);
}

/*Prueba 9: prueba la funcionalidad de cambiaTamanioDisparador()*/
int prueba9()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;

	creaRegla(&r);
	if(cambiaTamanioDisparador(r,i1)!=OK)
		EXIT(-1);
	if(r->num_disparador!=i1)
		EXIT(-2);
	if(cambiaTamanioDisparador(r,i2)!=OK)
		EXIT(-3);
	if(r->num_disparador!=i2)
		EXIT(-4);
	if(cambiaTamanioDisparador(r,i3)!=ERR)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 10: prueba la funcionalidad de cambiaTamanioDdatosDisparador()*/
int prueba10()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;

	creaRegla(&r);
	if(cambiaTamanioDatosDisparador(r,i1)!=OK)
		EXIT(-1);
	if(r->tam_datos_d!=i1)
		EXIT(-2);
	if(cambiaTamanioDatosDisparador(r,i2)!=OK)
		EXIT(-3);
	if(r->tam_datos_d!=i2)
		EXIT(-4);
	if(cambiaTamanioDatosDisparador(r,i3)!=ERR)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 11: prueba la funcionalidad de cambiaDisparador()*/
int prueba11()
{
	REGLA *r=NULL;
	int i;
	ID ids1[10]={0,1,2,3,4,5,6,7,8,9}, ids2[5]={1,2,3,4,5};

	if(cambiaDisparador(r,ids1,10)!=ERR)
		EXIT(-1);
	
	creaRegla(&r);

	if(cambiaDisparador(r,ids1,10)==ERR)
		EXIT(-2);
	for(i=0;i<10;i++)
		if((r->disp)[i]!=i)
			EXIT(-3);

	if(cambiaDisparador(r,ids2,5)==ERR)
		EXIT(-4);
	for(i=0;i<5;i++)
		if((r->disp)[i]!=i+1)
			EXIT(-5);

	EXIT(0);
}

/*Prueba 12: prueba la funcionalidad de cambiaCampoDisparador*/
int prueba12()
{
	REGLA *r=NULL;
	int i;
	CAMPO ids1[10]={0,1,2,3,4,5,6,7,8,9}, ids2[5]={1,2,3,4,5};

	if(cambiaCampoDisparador(r,ids1,10)!=ERR)
		EXIT(-1);
	
	creaRegla(&r);

	if(cambiaCampoDisparador(r,ids1,10)==ERR)
		EXIT(-2);
	for(i=0;i<10;i++)
		if((r->key)[i]!=i)
			EXIT(-3);

	if(cambiaCampoDisparador(r,ids2,5)==ERR)
		EXIT(-4);
	for(i=0;i<5;i++)
		if((r->key)[i]!=i+1)
			EXIT(-5);

	EXIT(0);
}

/*Prueba 13: prueba la funcionalidad de cambiaValorDisparador()*/
int prueba13()
{
	REGLA *r=NULL;
	char *cosa1="Hola", *cosa2="opKDPOkdajpAJ";
	int j=10;

	
	if(cambiaValorDisparador(r,cosa1,5)!=ERR)
		EXIT(-1);

	creaRegla(&r);

	if(cambiaValorDisparador(r,cosa1,-20)!=ERR)
		EXIT(-2);
	if(cambiaValorDisparador(r,NULL,10)!=ERR)
		EXIT(-3);

	if(cambiaValorDisparador(r,cosa1,5)==ERR)
		EXIT(-4);
	if(strcmp(r->valor,cosa1)!=0)
		EXIT(-5);

	if(cambiaValorDisparador(r,cosa2,14)==ERR)
		EXIT(-6);
	if(strcmp(r->valor,cosa2)!=0)
		EXIT(-7);

	if(cambiaValorDisparador(r,&j,sizeof(int))==ERR)
		EXIT(-8);
	if(memcmp(r->valor,&j,1*sizeof(int))!=0)
		EXIT(-9);

	EXIT(0);
}

/*Prueba 14: prueba la funcionalidad de cambiaAnterior()*/
int prueba14()
{
	REGLA *r=NULL;
	
	creaRegla(&r);

	if(cambiaAnterior(r,TRUE)==ERR)
		EXIT(-1);
	if(r->anterior!=TRUE)
		EXIT(-2);

	if(cambiaAnterior(r,FALSE)==ERR)
		EXIT(-3);
	if(r->anterior!=FALSE)
		EXIT(-4);

	EXIT(0);
}

/*Prueba 15: prueba la funcionalidad de cambiaFrase()*/
int prueba15()
{
	REGLA *r=NULL;
	char *c1="Hola", *c2="Que tal", *c3="WTF?!_";

	creaRegla(&r);

	if(cambiaFrase(r,c1)==ERR)
		EXIT(-1);
	if(strcmp(r->frase,c1)!=0)
		EXIT(-2);

	if(cambiaFrase(r,c2)==ERR)
		EXIT(-3);
	if(strcmp(r->frase,c2)!=0)
		EXIT(-4);

	if(cambiaFrase(r,c3)==ERR)
		EXIT(-5);
	if(strcmp(r->frase,c3)!=0)
		EXIT(-6);

	EXIT(0);
}


/*Prueba 17: prueba la funcionalidad de saberTamanioInfluido()*/
int prueba17()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;
	int v=-1;

	creaRegla(&r);
	if(saberTamanioInfluido(r,&v)!=ERR)
		EXIT(-1);
	cambiaTamanioInfluido(r,i1);
	if(saberTamanioInfluido(r,&v)==ERR)
		EXIT(-2);
	if(v!=i1)
		EXIT(-3);
	
	cambiaTamanioInfluido(r,i2);
	if(saberTamanioInfluido(r,&v)!=OK)
		EXIT(-4);
	if(v!=i2)
		EXIT(-5);
		
	cambiaTamanioInfluido(r,i3);
	if(saberTamanioInfluido(r,&v)!=OK)
		EXIT(-6);
	if(v!=i2)
		EXIT(-7);

	EXIT(0);
}

/*Prueba 18: prueba la funcionalidad de saberTamanioDatosInfluido()*/
int prueba18()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;
	int v=-1;

	creaRegla(&r);
	if(saberTamanioDatosInfluido(r,&v)!=ERR)
		EXIT(-1);
	cambiaTamanioDatosInfluido(r,i1);
	if(saberTamanioDatosInfluido(r,&v)==ERR)
		EXIT(-2);
	if(v!=i1)
		EXIT(-3);
	
	cambiaTamanioDatosInfluido(r,i2);
	if(saberTamanioDatosInfluido(r,&v)!=OK)
		EXIT(-4);
	if(v!=i2)
		EXIT(-5);
		
	cambiaTamanioDatosInfluido(r,i3);
	if(saberTamanioDatosInfluido(r,&v)!=OK)
		EXIT(-6);
	if(v!=i2)
		EXIT(-7);

	EXIT(0);
}

/*Prueba 19: prueba la funcionalidad de saberInfluido()*/
int prueba19()
{
	REGLA *r=NULL;
	ID id[10], id1[5]={0,1,2,3,4},id2[10]={1,2,3,4,5,6,7,8,9,10};
	int i;

	creaRegla(&r);
	if(!r)
		return -809;
	if(saberInfluido(r,id)!=ERR)
		EXIT(-1);

	cambiaInfluido(r,id1,5);
	if(saberInfluido(r,id)==ERR)
		EXIT(-2);
	for(i=0;i<5;i++)
	{
		if(id[i]!=i)
			EXIT(-3-i);
	}

	cambiaInfluido(r,id2,10);
	if(saberInfluido(r,id)==ERR)
		EXIT(-8);
	for(i=0;i<10;i++)
	{
		if(id[i]!=i+1)
			EXIT(-9-i);
	}

	EXIT(0);
}

/*Prueba 20: prueba la funcionalidad de saberCampoInfluido()*/
int prueba20()
{
	REGLA *r=NULL;
	CAMPO id[10], id1[5]={0,1,2,3,4},id2[10]={1,2,3,4,5,6,7,8,9,10};
	int i;

	creaRegla(&r);
	if(saberCampoInfluido(r,id)!=ERR)
		EXIT(-1);

	cambiaCampoInfluido(r,id1,5);
	if(saberCampoInfluido(r,id)==ERR)
		EXIT(-2);
	for(i=0;i<5;i++)
	{
		if(id[i]!=i)
			EXIT(-3-i);
	}

	cambiaCampoInfluido(r,id2,10);
	if(saberCampoInfluido(r,id)==ERR)
		EXIT(-8);
	for(i=0;i<10;i++)
	{
		if(id[i]!=i+1)
			EXIT(-9-i);
	}

	EXIT(0);
}

/*Prueba 21: prueba la funcionalidad de saberValorInfluido()*/
int prueba21()
{
	REGLA *r=NULL;
	char pt[10], *cosa1="Hola";
	int j=10;

	creaRegla(&r);
	if(saberValorInfluido(r,pt)!=ERR)
		EXIT(-1);

	cambiaValorInfluido(r,cosa1,5);
	if(saberValorInfluido(r,pt)==ERR)
		EXIT(-2);
	if(memcmp(pt,cosa1,5*sizeof(char))!=0)
		EXIT(-3);

	cambiaValorInfluido(r,&j,sizeof(int));
	if(saberValorInfluido(r,pt)==ERR)
		EXIT(-4);
	if(memcmp(pt,&j,sizeof(int))!=0)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 22: prueba la funcionalidad de saberTamanioDisparador()*/
int prueba22()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;
	int v=-1;

	creaRegla(&r);
	if(saberTamanioDisparador(r,&v)!=ERR)
		EXIT(-1);
	cambiaTamanioDisparador(r,i1);
	if(saberTamanioDisparador(r,&v)==ERR)
		EXIT(-2);
	if(v!=i1)
		EXIT(-3);
	
	cambiaTamanioDisparador(r,i2);
	if(saberTamanioDisparador(r,&v)!=OK)
		EXIT(-4);
	if(v!=i2)
		EXIT(-5);
		
	cambiaTamanioDisparador(r,i3);
	if(saberTamanioDisparador(r,&v)!=OK)
		EXIT(-6);
	if(v!=i2)
		EXIT(-7);

	EXIT(0);
}

/*Prueba 23: prueba la funcionalidad de saberTamanioDatosDisparador()*/
int prueba23()
{
	REGLA *r=NULL;
	int i1=10,i2=20,i3=-2;
	int v=-1;

	creaRegla(&r);
	if(saberTamanioDatosDisparador(r,&v)!=ERR)
		EXIT(-1);
	cambiaTamanioDatosDisparador(r,i1);
	if(saberTamanioDatosDisparador(r,&v)==ERR)
		EXIT(-2);
	if(v!=i1)
		EXIT(-3);
	
	cambiaTamanioDatosDisparador(r,i2);
	if(saberTamanioDatosDisparador(r,&v)!=OK)
		EXIT(-4);
	if(v!=i2)
		EXIT(-5);
	
	cambiaTamanioDatosDisparador(r,i3);
	if(saberTamanioDatosDisparador(r,&v)!=OK)
		EXIT(-4);
	if(v!=i2)
		EXIT(-5);
	
	EXIT(0);
}

/*Prueba 24: prueba la funcionalidad de saberDisparador()*/
int prueba24()
{
	REGLA *r=NULL;
	ID id[10], id1[5]={0,1,2,3,4},id2[10]={1,2,3,4,5,6,7,8,9,10};
	int i;

	creaRegla(&r);
	if(saberDisparador(r,id)!=ERR)
		EXIT(-1);

	cambiaDisparador(r,id1,5);
	if(saberDisparador(r,id)==ERR)
		EXIT(-2);
	for(i=0;i<5;i++)
	{
		if(id[i]!=i)
			EXIT(-3-i);
	}

	cambiaDisparador(r,id2,10);
	if(saberDisparador(r,id)==ERR)
		EXIT(-8);
	for(i=0;i<10;i++)
	{
		if(id[i]!=i+1)
			EXIT(-9-i);
	}

	EXIT(0);
}

/*Prueba 25: prueba la funcionalidad de saberCampoDisparador()*/
int prueba25()
{
	REGLA *r=NULL;
	CAMPO id[10], id1[5]={0,1,2,3,4},id2[10]={1,2,3,4,5,6,7,8,9,10};
	int i;

	creaRegla(&r);
	if(r==NULL)
		return -809;
	if(saberCampoDisparador(r,id)!=ERR)
		EXIT(-1);

	if(cambiaCampoDisparador(r,id1,5)==ERR)
		EXIT(-820);
	if(saberCampoDisparador(r,id)==ERR)
		EXIT(-2);
	for(i=0;i<5;i++)
	{
		if(id[i]!=i)
			EXIT(-3-i);
	}

	cambiaCampoDisparador(r,id2,10);
	if(saberCampoDisparador(r,id)==ERR)
		EXIT(-8);
	for(i=0;i<10;i++)
	{
		if(id[i]!=i+1)
			EXIT(-9-i);
	}

	EXIT(0);
}

/*Prueba 26: prueba la funcionalidad de saberValorDisparador()*/
int prueba26()
{
	REGLA *r=NULL;
	char pt[10], *cosa1="Hola";
	int j=10;

	creaRegla(&r);
	if(saberValorDisparador(r,pt)!=ERR)
		EXIT(-1);

	cambiaValorDisparador(r,cosa1,5);
	if(saberValorDisparador(r,pt)==ERR)
		EXIT(-2);
	if(memcmp(pt,cosa1,5*sizeof(char))!=0)
		EXIT(-3);

	cambiaValorDisparador(r,&j,sizeof(int));
	if(saberValorDisparador(r,pt)==ERR)
		EXIT(-4);
	if(memcmp(pt,&j,sizeof(int))!=0)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 27: prueba la funcionalidad de saberAnterior()*/
int prueba27()
{
	REGLA *r=NULL;
	BOOL valor=FALSE;

	creaRegla(&r);

	if(saberAnterior(r,&valor)!=ERR)
		EXIT(-1);

	cambiaAnterior(r,TRUE);
	if(saberAnterior(r,&valor)==ERR)
		EXIT(-2);
	if(valor!=TRUE)
		EXIT(-3);

	r->tam_datos_i=10;
	cambiaAnterior(r,FALSE);
	if(saberAnterior(r,&valor)==ERR)
		EXIT(-4);
	if(valor!=FALSE)
		EXIT(-5);

	EXIT(0);
}

/*Prueba 28: prueba la funcionalidad de saberFrase()*/
int prueba28()
{
	REGLA *r=NULL;
	char *c1="Hola",*c2="Como vas",*c3="WTF¿!_'";
	char cadena[20];

	creaRegla(&r);
	cambiaFrase(r,c1);
	if(saberFrase(r,cadena)==ERR)
		EXIT(-1);
	if(strcmp(cadena,c1)!=0)
		EXIT(-2);
	
	cambiaFrase(r,c2);
	if(saberFrase(r,cadena)==ERR)
		EXIT(-3);
	if(strcmp(cadena,c2)!=0)
		EXIT(-4);

	cambiaFrase(r,c3);
	if(saberFrase(r,cadena)==ERR)
		EXIT(-5);
	if(strcmp(cadena,c3)!=0)
		EXIT(-6);

	EXIT(0);
}

/*Prueba 29: prueba la funcionalidad de isReglaDestruida()*/
int prueba29()
{
	REGLA *r=NULL;

	if(!isReglaDestruida(r))
		EXIT(-1);
	creaRegla(&r);
	if(isReglaDestruida(r))
		EXIT(-2);
	destruyeRegla(&r);
	if(!isReglaDestruida(r))
		EXIT(-3);
	
	EXIT(0);
}

/*Prueba 30: prueba la funcionalidad de isEmptyRegla()*/
int prueba30()
{
	REGLA *r[13];
	int i, j=0;

	for(i=0;i<13;i++)
	{
		r[i]=NULL;
		creaRegla((&(r[i])));
		if(r[i]==NULL)
		{
			for(j=0;j<i;j++)
				destruyeRegla(&(r[j]));
			return -1000;
		}
	}

	r[1]->num_influido=5;
	r[2]->tam_datos_i=5;
	r[3]->influido=(ID *)5;
	r[4]->c=(CAMPO *)5;
	r[5]->valor_cam=(void *)5;
	r[6]->num_disparador=5;
	r[7]->tam_datos_d=5;
	r[8]->disp=(ID *)5;
	r[9]->key=(CAMPO *)5;
	r[10]->valor=(void *)5;
	r[11]->anterior=TRUE;
	r[12]->frase=(char *)5;

	for(i=1;i<13;i++)
	{
		if(isEmptyRegla(r[i])!=FALSE)	
			j=-1;	
	}

	for(i=0;i<13;i++)
	{
		if(r[i]!=NULL)
			free(r[i]);
	}
	
	return j;
}

/*Prueba 31: prueba la funcionalidad de evaluaRegla()*/
int prueba31()
{
	REGLA *r=NULL;
	MUNDO *m=NULL;
	ID id[2]={3,9};
	ID obj=4, esp=1;
	CAMPO campo[2]={OBJ_IN_ESP,LOC_JUG};
	char *datos;
	BOOL tr=TRUE, fl=FALSE;

	if(evaluaRegla(r,m)!=FALSE)
		EXIT(-1);

	creaRegla(&r);
	if(!r)
		EXIT(31);

	m=iniMundo("pruebasmundo.xml");
	if(!m)
		EXIT(30);

	cambiaDisparador(r,id,2);
	cambiaCampoDisparador(r,campo,2);

	datos=(char *)malloc(sizeof(ID)*2+sizeof(BOOL)*2);
	if(!datos)
	{
		destruyeMundo(&m);
		EXIT(32);
	}
	
	memcpy(datos,&obj,sizeof(ID));
	memcpy(&datos[sizeof(ID)],&tr,sizeof(BOOL));
	memcpy(&datos[sizeof(ID)+sizeof(BOOL)],&esp,sizeof(ID));
	memcpy(&datos[sizeof(BOOL)+2*sizeof(ID)],&fl,sizeof(BOOL));

	cambiaValorDisparador(r,datos,2*sizeof(ID)+2*sizeof(BOOL));

	if(evaluaRegla(r,m)!=FALSE)
	{
		destruyeMundo(&m);
		EXIT(-2);
	}

	memcpy(&datos[sizeof(BOOL)+2*sizeof(ID)],&tr,sizeof(BOOL));

	cambiaValorDisparador(r,datos,2*sizeof(ID)+2*sizeof(BOOL));

	if(evaluaRegla(r,m)!=TRUE)
	{
		destruyeMundo(&m);
		EXIT(-3);
	}

	destruyeMundo(&m);
	EXIT(0);
}

/*Prueba 32: prueba la funcionalidad de ejecutaAccion()*/
int prueba32()
{
	REGLA *r=NULL;
	MUNDO *m=NULL;
	ID id[2]={1,9};
	ID uni=20, esp=3;
	CAMPO campo[2]={P_ARR_ESP,P_LOC_JUG};
	char *datos;

	if(ejecutaAccionRegla(r,m)!=ERR)
		EXIT(-1);

	creaRegla(&r);
	if(!r)
		EXIT(31);

	m=iniMundo("pruebasmundo.xml");
	if(!m)
		EXIT(30);

	cambiaInfluido(r,id,2);
	cambiaCampoInfluido(r,campo,2);

	datos=(char *)malloc(sizeof(ID)*2);
	if(!datos)
	{
		destruyeMundo(&m);
		EXIT(32);
	}

	memcpy(datos,&uni,sizeof(ID));
	memcpy(&datos[sizeof(ID)],&esp,sizeof(ID));

	cambiaValorInfluido(r,datos,2*sizeof(ID));


	if(ejecutaAccionRegla(r,m)==ERR)
	{
		destruyeMundo(&m);
		EXIT(-2);
	}
	if(darArribaEsp(dameEspacio(m,1))!=20)
	{
		destruyeMundo(&m);
		EXIT(-3);
	}
	if(darLocJug(dameJugador(m,9))!=3)
	{
		destruyeMundo(&m);
		EXIT(-4);
	}

	destruyeMundo(&m);
	EXIT(0);
}


/*Función principal*/
int main()
{
	printf("Pruebas del módulo REGLAS. Número de pruebas: %d\n\\nResultados de las pruebas:\n\t-0 Salida correcta\n\t-(<0) Error\n\n", NUM_PRUEBAS);

	printf("Prueba 1: prueba la funcionalidad de creaRegla():%d\n", prueba1());
	printf("Prueba 2: prueba la funcionalidad de destruyeRegla():%d\n", prueba2());
	printf("Prueba 4: prueba la funcionalidad de cambiaTamanioInfluido():%d\n", prueba4());
	printf("Prueba 5: prueba la funcionalidad de cambiaTamanioDatosInfluido():%d\n", prueba5());
	printf("Prueba 6: prueba la funcionalidad de cambiaInfluido():%d\n", prueba6());
	printf("Prueba 7: prueba la funcionalidad de cambiaCampoInfluido():%d\n", prueba7());
	printf("Prueba 8: prueba la funcionalidad de cambiaValorInfluido():%d\n", prueba8());
	printf("Prueba 9: prueba la funcionalidad de cambiaTamanioDisparador():%d\n", prueba9());
	printf("Prueba 10: prueba la funcionalidad de cambiaTamanioDdatosDisparador():%d\n", prueba10());
	printf("Prueba 11: prueba la funcionalidad de cambiaDisparador():%d\n", prueba11());
	printf("Prueba 12: prueba la funcionalidad de cambiaCampoDisparador:%d\n", prueba12());
	printf("Prueba 13: prueba la funcionalidad de cambiaValorDisparador():%d\n", prueba13());
	printf("Prueba 14: prueba la funcionalidad de cambiaAnterior():%d\n", prueba14());
	printf("Prueba 15: prueba la funcionalidad de cambiaFrase():%d\n", prueba15());
	printf("Prueba 17: prueba la funcionalidad de saberTamanioInfluido():%d\n", prueba17());
	printf("Prueba 18: prueba la funcionalidad de saberTamanioDatosInfluido():%d\n", prueba18());
	printf("Prueba 19: prueba la funcionalidad de saberInfluido():%d\n", prueba19());
	printf("Prueba 20: prueba la funcionalidad de sabercampoInfluido():%d\n", prueba20());
	printf("Prueba 21: prueba la funcionalidad de saberValorInfluido():%d\n", prueba21());
	printf("Prueba 22: prueba la funcionalidad de saberTamanioDisparador():%d\n", prueba22());
	printf("Prueba 23: prueba la funcionalidad de saberTamanioDatosDisparador():%d\n", prueba23());
	printf("Prueba 24: prueba la funcionalidad de saberDisparador():%d\n", prueba24());
	printf("Prueba 25: prueba la funcionalidad de saberCampoDisparador():%d\n", prueba25());
	printf("Prueba 26: prueba la funcionalidad de saberValorDisparador():%d\n", prueba26());
	printf("Prueba 27: prueba la funcionalidad de saberAnterior():%d\n", prueba27());
	printf("Prueba 28: prueba la funcionalidad de saberFrase():%d\n", prueba28());
	printf("Prueba 29: prueba la funcionalidad de isReglaDestruida():%d\n", prueba29());
	printf("Prueba 30: prueba la funcionalidad de isEmptyRegla():%d\n", prueba30());
	printf("Prueba 31: prueba la funcionalidad de evaluaRegla():%d\n", prueba31());
	printf("Prueba 32: prueba la funcionalidad de ejecutaAccion():%d\n", prueba32());
return 0;
}
