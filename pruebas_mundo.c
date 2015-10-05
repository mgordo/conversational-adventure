/**/
/* @Aqui se ejecutaran las pruebas para comprobar si mundo es correcto*/
/* @file pruebas_mundo.c*/
/* @author Carlos Carrascal*/
/* @date 14/11/2010 */
/**/


/*Esquema de pruebas:*/

/* En un main se utilizaran todas las funciones para comprobar su correcto funcionamiento*/
/* No se controlaran los errores de aquellas funciones que consisten unicamente en llamar a otra funcion de otro modulo, ya que ese error provendria de otro modulo ya testeado, lo cual no es posible*/
/* Estas funciones especiales no se usarán para estas pruebas si no son necesarias*/
/* No se controlarán los errores de aquellas funciones que pertenecen a modulos inferiores por la misma razon*/
/* El procedimiento es el siguiente, si una funcion falla se imprimira por pantalla que funcion es y, en su caso, que apartado falla si acaso esa funcion se testea de varias maneras*/

/*Resultados:*/

/*El modulo ha superado todas las pruebas, incluido el test del programa valgrind*/

#include "mundo.h"

int main()
{
	MUNDO * m=NULL;
	OBJETO * obj1=NULL, * obj2=NULL, * obj3=NULL, * obj4=NULL;
	JUGADOR * jug=NULL, * jug2=NULL, * jug3=NULL;
	ESPACIO * esp1=NULL, * esp2=NULL, * esp3=NULL;
	UNION * uni=NULL, * uni2=NULL;
	ID aux1=-1, aux2=-1;
	char cadena[50];
	int i=0, num=0;

	/*Funciones para mundo*/
	
	m=nuevoMundo(2,2,2,1);
	if(m==NULL)
	{
		printf("Error en la función nuevoMundo()\n");
		return -1;
	}
	
	destruyeMundo(&m);
	
	if(m!=NULL)
	{
		printf("Error grave en la funcion destruyeMundo()\n");
		return -1;
	}
	
	m=nuevoMundo(2,2,2,1);
	if(m==NULL)
	{
		printf("Error en la función nuevoMundo()\n");
		return -1;
	}
	
	if(saberNumJug(m, &num)==ERR)
	{
		printf("Error en la función 1 saberNumJug()\n");
		return -1;
	}
	if(num!=2)
	{
		printf("Error en la función 2 saberNumJug()\n");
		return -1;
	}
	num=0;
	
	if(saberNumObj(m, &num)==ERR)
	{
		printf("Error en la función 1 saberNumObj()\n");
		return -1;
	}
	if(num!=2)
	{
		printf("Error en la función 2 saberNumObj()\n");
		return -1;
	}
	num=0;
	
	if(saberNumEsp(m, &num)==ERR)
	{
		printf("Error en la función 1 saberNumEsp()\n");
		return -1;
	}
	if(num!=2)
	{
		printf("Error en la función 2 saberNumEsp()\n");
		return -1;
	}
	num=0;
	
	if(saberNumUni(m, &num)==ERR)
	{
		printf("Error en la función 1 saberNumUni()\n");
		return -1;
	}
	if(num!=1)
	{
		printf("Error en la función 2 saberNumUni()\n");
		return -1;
	}

		
	/*Funciones para objeto*/

	creaObj(&obj1);
	creaObj(&obj2);

	creaIdObjMundo(obj1, 0);
	creaIdObjMundo(obj2, 1);

	creaNombreObj(obj1, "caja");
	creaNombreObj(obj2, "lapiz");

	creaDescObj(obj1, "es marron");
	creaDescObj(obj2, "es amarillo y con luz");

	creaDescMovidoObj(obj1, "es pesada");
	creaDescMovidoObj(obj2, "esta gastado y con moho");

	creaExamObj(obj1, "parece vieja");
	creaExamObj(obj2, "esta muy mordido");

	creaMovilObj(obj1, TRUE);
	creaMovilObj(obj2, TRUE);
	
	creaMovidoObj(obj1, FALSE);
	creaMovidoObj(obj2, TRUE);

	creaOcultoObj(obj1, FALSE);
	creaOcultoObj(obj2, TRUE);

	creaEncendidoObj(obj1, FALSE);
	creaEncendidoObj(obj2, FALSE);

	creaContenedorObj(obj1, TRUE);
	creaContenedorObj(obj2, FALSE);

	creaLuzObj(obj1, FALSE);
	creaLuzObj(obj2, TRUE);

	if(m==NULL || obj1==NULL || obj2==NULL)
	{
		printf("Fallo no esperando en espacio\n");
		destruyeMundo(&m);
		return -1;
	}
	
	if(guardaObj(m, obj1)==ERR)
	{
		printf("Error en la funcion 1 guardaObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(guardaObj(m, obj2)==ERR)
	{
		printf("Error en la funcion 2 guardaObj()\n");
		destruyeMundo(&m);
		return -1;
	}	

	obj3=dameObjeto(m, 0);
	if(obj3==NULL)
	{
		printf("Error en la funcion 1 dameObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}

	aux1=darIdObj(obj1);
	aux2=darIdObj(obj3);
	if(aux1!=aux2)
	{
		printf("Error en la funcion 2 dameObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	aux1=-1;
	aux2=-1;
	
	obj4=consigueObjeto(m,"lapiz");
	if(obj4==NULL)
	{
		printf("Error en la funcion 1 consigueObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	aux1=darIdObj(obj2);
	aux2=darIdObj(obj4);
	if(aux1!=aux2)
	{
		printf("Error en la funcion 2 consigueObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	aux1=-1;
	aux2=-1;
	
	if(darNombreObj(obj2, cadena)==ERR)
	{
		printf("Error en la funcion 1 darNombreObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(strcmp(cadena, "lapiz")!=0)
	{
		printf("Error en la funcion 2 darNombreObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	for(i=0;i<50;i++)
		cadena[i]='\0';

 	if(dameDescrObj(obj2, cadena, 50)==ERR)
	{
		printf("Error en la funcion 1 dameDescrObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(strcmp(cadena, "esta gastado y con moho")!=0)
	{
		printf("Error en la funcion 2 dameDescrObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	for(i=0;i<50;i++)
		cadena[i]='\0';	
	
	if(dameDescrObj(obj1, cadena, 50)==ERR)
	{
		printf("Error en la funcion 3 dameDescrObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(strcmp(cadena, "es marron")!=0)
	{
		printf("Error en la funcion 4 dameDescrObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	/*Funciones para jugador*/

	creaJug(&jug);
	creaJug(&jug3);

	creaIdJug(jug, 0);
	creaIdJug(jug3, 1);

	creaNombreJug(jug, "chuck");
	creaNombreJug(jug3, "rasta");

	creaLocJug(jug, 0);
	creaLocJug(jug3, 1);

	creaMaxObjJug(jug, 2);
	creaMaxObjJug(jug3, 2);

	if(guardaJug(m, jug)==ERR)
	{
		printf("Error en la funcion 1 guardaJug()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(guardaJug(m, jug3)==ERR)
	{
		printf("Error en la funcion 2 guardaJug()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	for(i=0;i<50;i++)
		cadena[i]='\0';

	if(darNombreJug(jug, cadena, 50)==ERR)
	{
		printf("Error en la funcion 1 darNombreJug()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(strcmp(cadena, "chuck")!=0)
	{
		printf("Error en la funcion 2 darNombreJug()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	jug2=consigueJugador(m,"chuck");
	if(jug2==NULL)
	{
		printf("Error en la funcion 1 consigueJugador()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	aux1=darIdJug(jug);
	aux2=darIdJug(jug2);
	if(aux1!=aux2)
	{
		printf("Error en la funcion 2 consigueJugador()\n");
		destruyeMundo(&m);
		return -1;
	}

	/*Funciones para union*/

	creaUni(&uni);

	creaIdUniMundo(uni, 0);
	
	creaIdSalidaUni(uni, 0);

	creaIdLlegadaUni(uni, 1);

	creaAbiertaUni(uni, TRUE);
	
	if(guardaUni(m, uni)==ERR)
	{
		printf("Error en la funcion guardaUni()\n");
		destruyeMundo(&m);
		return -1;
	}

	uni2=dameUnion(m, 0);
	if(uni2==NULL)
	{
		printf("Error en la funcion 1 dameUnion()\n");
		destruyeMundo(&m);
		return -1;
	}


	aux1=darIdUni(uni);
	aux2=darIdUni(uni);
	if(aux1!=aux2)
	{
		printf("Error en la funcion 2 dameUnion()\n");
		destruyeMundo(&m);
		return -1;
	}

	aux1=-1;
	aux2=-1;

	/*Funciones para espacio*/


	creaEsp(&esp1);
	creaEsp(&esp2);

	creaIdEspMundo(esp1, 0);
	creaIdEspMundo(esp2, 1);
	
	creaDescEsp(esp1, "arido");
	creaDescEsp(esp2, "humedo");

	creaExamEsp(esp1, "te vas a quemar");
	creaExamEsp(esp2, "te vas a constipar");

	meteObjEsp(esp1, 0);
	meteObjEsp(esp2, 1);

	creaLumEsp(esp1, TRUE);
	creaLumEsp(esp2, TRUE);

	creaNorteEsp(esp1, 0);
	
	
	if(guardaEsp(m, esp1)==ERR)
	{
		printf("Error en la funcion 1 guardaEsp()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(guardaEsp(m, esp2)==ERR)
	{
		printf("Error en la funcion 2 guardaEsp()\n");
		destruyeMundo(&m);
		return -1;
	}

	for(i=0;i<50;i++)
		cadena[i]='\0';

	if(darDescrEsp(esp2, cadena, 50)==ERR)
	{
		printf("Error en la funcion 1 darDescrEsp()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(strcmp(cadena, "humedo")!=0)
	{
		printf("Error en la funcion 2 darDescrEsp()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	esp3=dameEspacio(m, 0);
	if(esp3==NULL)
	{
		printf("Error en la funcion 1 dameEspacio()\n");
		destruyeMundo(&m);
		return -1;
	}

	aux1=darIdEsp(esp1);
	aux2=darIdEsp(esp3);
	if(aux1!=aux2)
	{
		printf("Error en la funcion 2 dameEspacio()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	aux1=-1;
	aux2=-1;
	
	/*Funciones para Acciones del usuario*/
	
	for(i=0;i<50;i++)
		cadena[i]='\0';

	if(dameEspacioExaminar(m,jug,cadena)==ERR)
	{
		printf("Error en la funcion 1 dameEspacioExaminar()\n");
		destruyeMundo(&m);
		return -1;
	}
	if(strcmp(cadena, "te vas a quemar")!=0)
	{
		printf("Error en la funcion 2 dameEspacioExaminar()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(cogeObjeto(m, obj1, jug)==ERR)
	{
		printf("Error en la funcion 1 cogeObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjInInv(jug, 0)==FALSE)
	{
		printf("Error en la funcion 2 cogeObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}


	if(muevePersonaje(m, N, jug)==ERR)
	{
		printf("Error en la funcion muevePersonaje()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(cogeObjeto(m, obj2, jug)==ERR)
	{
		printf("Error en la funcion 3 cogeObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjInInv(jug, 1)==FALSE)
	{
		printf("Error en la funcion 4 cogeObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(intercambioObj(jug, jug3, obj2)==ERR)
	{
		printf("Error en la funcion 1 intercambioObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjInInv(jug3, 1)==FALSE)
	{
		printf("Error en la funcion 2 intercambioObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjInInv(jug, 1)==TRUE)
	{
		printf("Error en la funcion 3 intercambioObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(intercambioObj(jug3, jug, obj2)==ERR)
	{
		printf("Error en la funcion 4 intercambioObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(enciende(m, obj1, jug)==TRUE)
	{
		printf("Error cachondo en la funcion enciende(), has encendido una caja\n");
		destruyeMundo(&m);
		return -1;
	}

	if(apaga(m, obj2, jug)==ERR)
	{
		printf("Error en la funcion apaga()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	if(meterObjObjAc(m, obj1, obj2, jug)==ERR)
	{
		printf("Error en la funcion 1 meterObjObjAc()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjinObj(obj1, 1)==FALSE)
	{
		printf("Error en la funcion 2 meterObjObj()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(sacarObjObjAc(m, obj1, obj2, jug)==ERR)
	{
		printf("Error en la funcion 1 sacarObjObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	if(isObjInInv(jug, 1)==FALSE)
	{
		printf("Error en la funcion 2 sacarObjObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	
	if(isObjinObj(obj1, 1)==TRUE)
	{
		printf("Error en la funcion 3 sacarObjObj()\n");
		destruyeMundo(&m);
		return -1;
	}	
	
	for(i=0;i<50;i++)
		cadena[i]='\0';
	
	if(dameObjetoExaminar(m,obj2,jug,cadena)==ERR)
	{
		printf("Error en la funcion 1 dameObjetoExaminar()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	if(strcmp(cadena, "esta muy mordido")!=0)
	{
		printf("Error en la funcion 2 dameObjetoExaminar()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	if(dejaObjeto(m, obj2, jug)==ERR)
	{
		printf("Error en la funcion 1 dejaObjeto()\n");
		destruyeMundo(&m);
		return -1;
	}

	if(isObjInInv(jug, 1)==TRUE)
	{
		printf("Error en la funcion 2 dejaObjObj()\n");
		destruyeMundo(&m);
		return -1;
	}
	
	printf("\n\nTodas las pruebas se han realizado correctamente.\n\n\a");
	destruyeMundo(&m);
	return OK;
}
