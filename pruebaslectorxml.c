/*Módulo de pruebas del lector xml*/
/*Este cliente de pruebas del lectorxml lee un fichero llamado pruebasmundo.xml. En él hay un pequeño mundo con tres espacios, 4 uniones y algunos objetos*/
/*El cliente lee el fichero y llama a las funciones de "saber" del módulo mundo para comprobar que se han leído correctamente todos los datos*/
/*Autor: Miguel Gordo*/
/*Fecha: 14-XI-2010*/

#include"lectorxml.h"
#include<assert.h>
#define MAX_ 256

int main (int argc,char **argv){

	MUNDO *mundo=NULL;
	ESPACIO *esp=NULL;
	OBJETO *obj=NULL;
	UNION *uni=NULL;
	JUGADOR *jug=NULL;
	char *description=NULL;
	char **dibujo=NULL;
	ID id=1, x=0;
	BOOL herman=FALSE;
	int maximo=0,i,j,filas=0,columnas=0;

	if(argc!=2){
		printf("Error, debe de introducir el nombre del fichero xml a parsear\n");
		return ERR;
	}
	
	if(!(description=(char*)calloc(MAX_,sizeof(char)))){
		printf("Error reservando memoria\n");
		return ERR;
	}
	
	
	mundo=iniMundo(argv[1]);
		
	if(!mundo){
		printf("No hay mundo\n");
		return ERR;
	}
	
	/*Espacios*/
	id=1;
	esp=dameEspacio(mundo, id);
	assert(esp!=NULL);
	assert(OK==darDescrEsp(esp, description, MAX_));
	assert(strcmp(description, "Punto de entrada")==0);
	assert(OK==darDescrexamEsp(esp,description, MAX_));/*MAX_? Es necesario? Ver prototipo Carras*/
	assert(strcmp(description, "Al oeste se ve el edificio de la escuela")==0);
	x=darNorteEsp(esp);/*Será así el prototipo*/
	assert(x==10);
	x=darSurEsp(esp);/*Será así el prototipo*/
	assert(x==20);
	
	assert(OK==saberEspDescrGrafica(esp,&dibujo,&filas, &columnas));
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++)
			printf("%c",dibujo[i][j]);
		printf("\n");
	}
	
	free(dibujo[0]);
	free(dibujo);
	
	id=2;
	esp=dameEspacio(mundo, id);
	assert(esp!=NULL);
	assert(OK==darDescrEsp(esp, description, MAX_));
	assert(strcmp(description, "Terraza de la cafeteria")==0);
	assert(OK==darDescrexamEsp(esp,description, MAX_));/*MAX_? Es necesario? Ver prototipo Carras*/
	assert(strcmp(description, "Al oeste se ve el edificio de la escuela")==0);
	x=darSurEsp(esp);/*Será así el prototipo*/
	assert(x==30);
	
	id=3;
	esp=dameEspacio(mundo, id);
	assert(esp!=NULL);
	assert(OK==darDescrEsp(esp, description, MAX_));
	assert(strcmp(description, "Hall principal de la escuela")==0);
	assert(OK==darDescrexamEsp(esp,description, MAX_));/*MAX_? Es necesario? Ver prototipo Carras*/
	assert(strcmp(description, "Estas en un hall grande con columnas, hay dos pasillos al sur y al norte, la puerta de entrada al este, y al oeste otra puerta mas pequena")==0);
	x=darNorteEsp(esp);/*Será así el prototipo*/
	assert(x==40);
	herman=darLumEsp(esp);
	assert(herman==TRUE);
	
	/*Objetos*/
	id=4;
	obj=dameObjeto(mundo,id);
	assert(obj!=NULL);
	assert(OK==darNombreObj(obj,description));
	assert(strcmp(description, "Tablon")==0);
	assert(OK==darDescrObj(obj,description,MAX_));
	assert(strcmp(description, "Horarios")==0);
	assert(OK==darDescrexamObj(obj,description,MAX_));/*Será así la función?*/
	assert(strcmp(description, "Estan los horarios de ingenieria informatica")==0);
	assert(OK==darDescrMovidoObj(obj,description,MAX_));/*Será así?*/
	assert(strcmp(description, "NO PUEDES MOVERME, SI LO LEES KAPUT")==0);
	herman=darMovilObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darMovidoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darOcultoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darLuzObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darEncendidoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darContenedorObj(obj);/*Será asi*/
	assert(herman==TRUE);
	


	id=5;
	obj=dameObjeto(mundo,id);
	assert(obj!=NULL);
	assert(OK==darNombreObj(obj,description));
	assert(strcmp(description, "Notas")==0);
	assert(OK==darDescrObj(obj,description,MAX_));
	assert(strcmp(description, "Notas de Informática")==0);
	assert(OK==darDescrexamObj(obj,description,MAX_));/*Será así la función?*/
	assert(strcmp(description, "Has aprobado PPROG!")==0);
	assert(OK==darDescrMovidoObj(obj,description,MAX_));/*Será así?*/
	assert(strcmp(description, "NO PUEDES MOVERME, SI LO LEES KAPUT")==0);
	herman=darMovilObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darMovidoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darOcultoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darLuzObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darEncendidoObj(obj);/*Será asi*/
	assert(herman==FALSE);
	herman=darContenedorObj(obj);/*Será asi*/
	assert(herman==FALSE);
	
	/*Jugador*/
	id=9;
	jug=dameJugador(mundo,id);
	assert(jug!=NULL);
	x=darLocJug(jug);/*Será asi?*/
	assert(x==1);
	maximo=darMaxJug(jug);/*Será esta?*/
	assert(maximo==3);
	
	/*Uniones*/
	id=10;
	uni=dameUnion(mundo,id);
	assert(uni!=NULL);
	herman=darAbiertaUni(uni);/*Será esta?*/
	assert(herman==TRUE);
	x=darLlegadaUni(uni);/*Será?*/
	assert(x==2);
	x=darSalidaUni(uni);
	assert(x==1);
	maximo=darKeyUni(uni);
	assert(maximo==-1);
	
	
	id=20;
	uni=dameUnion(mundo,id);
	assert(uni!=NULL);
	herman=darAbiertaUni(uni);/*Será esta?*/
	assert(herman==TRUE);
	x=darLlegadaUni(uni);/*Será?*/
	assert(x==3);
	x=darSalidaUni(uni);
	assert(x==1);
	maximo=darKeyUni(uni);
	assert(maximo==-1);
	
	id=30;
	uni=dameUnion(mundo,id);
	assert(uni!=NULL);
	herman=darAbiertaUni(uni);/*Será esta?*/
	assert(herman==TRUE);
	x=darLlegadaUni(uni);/*Será?*/
	assert(x==1);
	x=darSalidaUni(uni);
	assert(x==2);
	maximo=darKeyUni(uni);
	assert(maximo==-1);
	
	id=40;
	uni=dameUnion(mundo,id);
	assert(uni!=NULL);
	herman=darAbiertaUni(uni);/*Será esta?*/
	assert(herman==TRUE);
	x=darLlegadaUni(uni);/*Será?*/
	assert(x==1);
	x=darSalidaUni(uni);
	assert(x==3);
	maximo=darKeyUni(uni);
	assert(maximo==-1);
	
	free(description);
	destruyeMundo(&mundo);
	
	assert(mundo==NULL);
	
	printf("Éxito Rotundo! Hooray!\n");
	
	return 0;
}




