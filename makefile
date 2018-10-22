# Archivo: makefile

## Agregue todo el makefile aca, para compilar el archivo de prueba se
## ejecuta "make prueba", mientras que para el main sigue siendo "make all"

## tambien cambie los nombres de los ejecutables a tp0 para el main y a
## ejecprueba para el archivo de pruebas

CC = g++
FLAGS = -Wall -g -pedantic #-W 		#Para que no moleste con lo violeta

all: ejec # clear

ejec: main.o Cmdline.o ArrayElement.o Error.o Package.o Red.o Utils.o SegmentTree.o Element.o Quartet.o 
	$(CC) $(FLAGS) -o tp1 main.o Cmdline.o ArrayElement.o Error.o Package.o Red.o Utils.o Element.o SegmentTree.o Quartet.o

main.o: main.cpp Cmdline.hpp Red.hpp Utils.hpp Error.hpp
	$(CC) $(FLAGS) -o main.o -c main.cpp

Cmdline.o: Cmdline.cpp Cmdline.hpp
	$(CC) $(FLAGS) -o Cmdline.o -c Cmdline.cpp

ArrayElement.o: ArrayElement.cpp ArrayElement.hpp Element.hpp
	$(CC) $(FLAGS) -o ArrayElement.o -c ArrayElement.cpp

Error.o: Error.cpp Error.hpp
	$(CC) $(FLAGS) -o Error.o -c Error.cpp

Package.o: Package.cpp Package.hpp
	$(CC) $(FLAGS) -o Package.o -c Package.cpp

Red.o: Red.cpp Red.hpp Package.hpp ArrayElement.hpp SegmentTree.hpp Element.hpp 
	$(CC) $(FLAGS) -o Red.o -c Red.cpp

Utils.o: Utils.cpp Utils.hpp Red.hpp Error.hpp Package.hpp Element.hpp SegmentTree.hpp
	$(CC) $(FLAGS) -o Utils.o -c Utils.cpp
	
SegmentTree.o: SegmentTree.cpp SegmentTree.hpp Quartet.hpp Package.hpp Element.hpp
	$(CC) $(FLAGS) -o SegmentTree.o -c SegmentTree.cpp

Element.o: Element.cpp Element.hpp
	$(CC) $(FLAGS) -o Element.o -c Element.cpp
	
Quartet.o: Quartet.cpp Quartet.hpp
	$(CC) $(FLAGS) -o Quartet.o -c Quartet.cpp


prueba: ejecprueba clear

ejecprueba: Prueba.o Cmdline.o ArrayElement.o Error.o Package.o Red.o Utils.o
	$(CC) $(FLAGS) -o ejecprueba Prueba.o Cmdline.o ArrayElement.o Error.o Package.o Red.o Utils.o

Prueba.o: Prueba.cpp Cmdline.hpp Utils.hpp Error.hpp Red.hpp ArrayElement.hpp
	$(CC) $(FLAGS) -o Prueba.o -c Prueba.cpp


clear:
	rm *.o


