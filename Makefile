CC=gcc
CFLAGS=-g -ansi
XML = `xml2-config --cflags` `xml2-config --libs`
EXE= $(PRUEBAS)
DIR=G2221_Eq06_Producto_Final

all: game pruebas_conjunto pruebas_jugador pruebas_espacio pruebas_objeto pruebas_union pruebas_mundo pruebas_lector_mundo pruebas_reglas pruebas_accion pruebas_lector_reglas pruebas_iografica pruebas_motor pruebas_reglasdialogo pruebas_lector_reglasdialogo pruebas_UtilCadena autores

PO1 = conjunto.o inventario.o
PO2 = espacio.o union.o jugador.o objeto.o
PO3 = mundo.o lectorxml.o reglas.o lector_reglas.o accion.o
PO4 = UtilCadena.o reglasdialogo.o lector_reglasdialogo.o
POG = iografica.o motor.o
DIA = dialogo.o
PO = $(PO1) $(PO2) $(PO3) $(PO4) $(POG) $(DIA)

PRU1 = pruebas_conjunto
PRU2 = pruebas_jugador pruebas_espacio pruebas_objeto pruebas_union
PRU3 = pruebas_mundo pruebas_lector_mundo pruebas_reglas pruebas_accion pruebas_lector_reglas
PRUG = pruebas_iografica pruebas_motor
PRU4 = pruebas_reglasdialogo pruebas_lector_reglasdialogo pruebas_UtilCadena
PRUEBAS = $(PRU1) $(PRU2) $(PRU3) $(PRUG) $(PRU4)

##################################
#Primer nivel:
#Conjunto--Inventario#
##################################
conjunto.o: conjunto.h conjunto.c tipos.h
	@echo Generando conjunto.o ...
	$(CC) $(CFLAGS) -c conjunto.c
pruebas_conjunto: conjunto.o pruebas_conjunto.c
	@echo Generando Pruebas del conjunto: ejecutable pruebas_conjunto ...
	$(CC) $(CFLAGS) -o pruebas_conjunto conjunto.o pruebas_conjunto.c
inventario.o: conjunto.o inventario.c inventario.h
	@echo Generando inventario.o ...
	$(CC) $(CFLAGS) -c inventario.c
##################################
#Compilación del primer nivel:
nivel1: $(PO1)
##################################


##################################
#Segundo nivel:
#Jugador--Objeto--Espacio--Union
##################################
jugador.o: inventario.o jugador.c jugador.h
	@echo Generando jugador.o ...
	$(CC) $(CFLAGS) -c jugador.c
pruebas_jugador: jugador.o pruebas_jugador.c 
	@echo Generando Pruebas del Jugador: ejecutable pruebas_jugador ...
	$(CC) $(CFLAGS) -o pruebas_jugador jugador.o pruebas_jugador.c inventario.o conjunto.o
objeto.o: inventario.o objeto.c objeto.h
	@echo Generando objeto.o ...
	$(CC) $(CFLAGS) -c objeto.c
pruebas_objeto: objeto.o pruebas_objeto.c
	@echo Generando Pruebas de objeto: ejecutable pruebas_objeto ...
	$(CC) $(CFLAGS) -o pruebas_objeto pruebas_objeto.c objeto.o inventario.o conjunto.o
espacio.o: inventario.o espacio.h espacio.c
	@echo Generando espacio ...
	$(CC) $(CFLAGS) -c espacio.c
pruebas_espacio: espacio.o pruebas_espacio.c
	@echo Generando  ...
	$(CC) $(CFLAGS) -o pruebas_espacio pruebas_espacio.c espacio.o inventario.o conjunto.o
union.o: union.h union.c
	@echo Generando union.o ...
	$(CC) $(CFLAGS) -c union.c
pruebas_union: union.o pruebas_union.c
	@echo Generando Pruebas de la Union: ejecutable pruebas_union ...
	$(CC) $(CFLAGS) -o pruebas_union pruebas_union.c union.o inventario.o conjunto.o

###################################
#Compilación del segundo nivel:
nivel2: $(PO2)
###################################


###################################
#Tercer nivel:
#Mundo--Lector Mundo--accion--Reglas--Lector Reglas accion
###################################
mundo.o: nivel2 mundo.h mundo.c 
	@echo Generando mundo.o ...
	$(CC) $(CFLAGS) -c mundo.c
pruebas_mundo: mundo.o pruebas_mundo.c
	@echo Generando Pruebas del Mundo:ejecutable pruebas_mundo...
	$(CC) $(CFLAGS) -o pruebas_mundo pruebas_mundo.c mundo.o $(PO1) $(PO2)
lectorxml.o: mundo.o lectorxml.c lectorxml.h
	@echo Generando lector_mundo.o...
	$(CC) $(CFLAGS) $(XML) -c lectorxml.c
pruebas_lector_mundo: lectorxml.o pruebaslectorxml.c
	@echo Generando Pruebas del Lector Mundo: ejecutable pruebas_lector_mundo...
	$(CC) $(CFLAGS) $(XML) -o pruebas_lector_mundo pruebaslectorxml.c lectorxml.o mundo.o $(PO1) $(PO2)
accion.o: mundo.o accion.c accion.h
	@echo Generando accion.o...
	$(CC) $(CFLAGS) $(XML) -c accion.c
pruebas_accion: $(PO3) pruebas_accion.c 
	@echo Generando pruebas_accion: ejecutable pruebas_accion...
	$(CC) $(CFLAGS) $(XML) -o pruebas_accion pruebas_accion.c $(PO1) $(PO2) $(PO3) 
reglas.o: mundo.o reglas.c reglas.h
	@echo Generando reglas.o...
	$(CC) $(CFLAGS) -c reglas.c
pruebas_reglas: reglas.o pruebas_reglas.c
	@echo Generando Pruebas de Reglas: ejecutable pruebas_reglas...
	$(CC) $(CFLAGS) $(XML) -o pruebas_reglas reglas.o pruebas_reglas.c mundo.o lectorxml.o $(PO1) $(PO2)
lector_reglas.o: reglas.o accion.o lector_reglas.c lector_reglas.h
	@echo Generando lector_reglas.o...
	$(CC) $(CFLAGS) $(XML) -c lector_reglas.c
pruebas_lector_reglas: lector_reglas.o pruebas_lector_reglas.c
	@echo Generando Pruebas del Lector de las Reglas de las accion: ejecutable pruebas_lector_reglas...
	$(CC) $(CFLAGS) $(XML)  -o pruebas_lector_reglas pruebas_lector_reglas.c $(PO3) $(PO2) $(PO1) 

###################################
#Compilación del tercer nivel
nivel3: $(PO3)
###################################


###################################
#Cuarto nivel:
#Dialogo--Reglas Dialogo--Lector Reglas Dialogo--Util Cadena--Motor Grafico
###################################
#pruebas_dialogo:
#	@echo Generando dialogo.o...
#	$(CC) $(CFLAGS) -c dialogo.c
reglasdialogo.o: nivel3
	@echo Generando reglasdialogo.o...
	$(CC) $(CFLAGS) -c reglasdialogo.c
pruebas_reglasdialogo: pruebas_reglasdialogo.c reglasdialogo.o
	@echo Generando Pruebas del Reglas del Dialogo: ejecutable pruebas_reglasdialogo...
	$(CC) $(CFLAGS) -o pruebas_reglasdialogo pruebas_reglasdialogo.c reglasdialogo.o
lector_reglasdialogo.o: lector_reglasdialogo.c lector_reglasdialogo.h reglasdialogo.o
	@echo Generando lector_reglasdialogo.o...
	$(CC) $(CFLAGS) $(XML) -c lector_reglasdialogo.c
pruebas_lector_reglasdialogo: pruebas_lector_reglasdialogo.c lector_reglasdialogo.o
	@echo Generando Pruebas del Lector de las Reglas del Dialogo: ejecutable pruebas_lector_reglasdialogo...
	$(CC) $(CFLAGS) $(XML) -o pruebas_lector_reglasdialogo pruebas_lector_reglasdialogo.c lector_reglasdialogo.o reglasdialogo.o
UtilCadena.o: UtilCadena.c UtilCadena.h
	@echo Generando UtilCadena.o...
	$(CC) $(CFLAGS) -c UtilCadena.c
pruebas_UtilCadena: UtilCadena.o pruebas_UtilCadena.c
	@echo Generando Pruebas de UtilCadena: ejecutable pruebas_UtilCadena...
	$(CC) $(CFLAGS) -o pruebas_UtilCadena  pruebas_UtilCadena.c UtilCadena.o


###################################
#Compilación del cuarto nivel
nivel4: $(PO4)
###################################


###################################
#Nivel gráfico:
#I/O Gráfica -- Motor Gráfico
###################################
iografica.o: 
	@echo Generando iografica.o...
	$(CC) $(CFLAGS) -c iografica.c
pruebas_iografica: iografica.o
	@echo Generando Pruebas de la I/O Grafica: ejecutable pruebas_iografica...
	$(CC) $(CFLAGS) -o pruebas_iografica pruebas_iografica.c iografica.o
motor.o: iografica.o
	@echo Generando motor.o...
	$(CC) $(CFLAGS) -c motor.c
pruebas_motor: motor.o mundo.o
	@echo Generando Pruebas del motor grafico: ejecutable pruebas_motor...
	$(CC) $(CFLAGS) -o pruebas_motor pruebas_motor.c $(POG) mundo.o $(PO2) $(PO1)

###################################
#Compilación del nivel gráfico
nivelg: $(POG)
###################################

###################################
#Compilacion de todos los niveles a excepcion del Dialogo
niveles: nivel1 nivel2 nivel3 nivelg nivel4
###################################

##################################
#Dialogo
##
##################################
dialogo.o: nivel1 nivel2 nivel3 nivel4 nivelg dialogo.h dialogo.c
	@echo Generando dialogo.o...
	$(CC) $(CFLAGS) $(XML) -c dialogo.c

##################################
#Compilación completa:
todo: $(DIA)
##################################


########################################################
#Compilación por niveles de las pruebas
pru1: $(PRU1)
pru2: $(PRU2)
pru3: $(PRU3)
pru4: $(PRU4)
prug: $(PRUG)
pruebas: $(PRUEBAS)
########################################################

##################################
#Compilación del juego
game: dialogo.o
	@echo Instalando el juego...
	$(CC) $(CFLAGS) $(XML) -o game main.c $(PO)


documentacion: 

clean :
	rm -f *.o *~ core $(EXE) game

dist: all clean
	cd .. ; zip -r $(DIR).zip $(DIR)

autores:
	@ echo "--------------------------------------------------------------"
	@ echo "Este Increíble, Poderoso, y Magnífico Juego ha sido desarrollado por  "
	@ echo "Carrascal Manzanares, Carlos; Gordo Garcia, Miguel y Jimenez Pastor, Antonio"
	@ echo "--------------------------------------------------------------"
