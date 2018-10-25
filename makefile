# Archivo: makefile

## Agregue todo el makefile aca, para compilar el archivo de prueba se
## ejecuta "make prueba", mientras que para el main sigue siendo "make all"

## tambien cambie los nombres de los ejecutables a tp0 para el main y a
## ejecprueba para el archivo de pruebas

CC = g++
FLAGS = -Wall -g -pedantic #-W 		#Para que no moleste con lo violeta

all: ejec clear

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

########################################################

Pruf: tp1 Pruebas/Consultas_CPU_temp.csv Pruebas/CPU_Temp.csv 
	valgrind --leak-check=full --show-leak-kinds=all ./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/Consultas_CPU_temp.csv
	valgrind --leak-check=full --show-leak-kinds=all ./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/Consultas_CPU_temp.csv -p Iteration

Querys: QueryCreator.exe
	./QueryCreator.exe -o Pruebas/QueryTest1.csv -n 100
	./QueryCreator.exe -o Pruebas/QueryTest2.csv -n 300
	./QueryCreator.exe -o Pruebas/QueryTest3.csv -n 500	
	./QueryCreator.exe -o Pruebas/QueryTest4.csv -n 700
	./QueryCreator.exe -o Pruebas/QueryTest5.csv -n 1000
	./QueryCreator.exe -o Pruebas/QueryTest6.csv -n 3000
	./QueryCreator.exe -o Pruebas/QueryTest7.csv -n 5000
	./QueryCreator.exe -o Pruebas/QueryTest8.csv -n 7000
	./QueryCreator.exe -o Pruebas/QueryTest9.csv -n 10000
	./QueryCreator.exe -o Pruebas/QueryTest10.csv -n 30000
	./QueryCreator.exe -o Pruebas/QueryTest11.csv -n 50000
	./QueryCreator.exe -o Pruebas/QueryTest12.csv -n 70000
	./QueryCreator.exe -o Pruebas/QueryTest13.csv -n 100000
	./QueryCreator.exe -o Pruebas/QueryTest14.csv -n 300000
	./QueryCreator.exe -o Pruebas/QueryTest15.csv -n 500000
	./QueryCreator.exe -o Pruebas/QueryTest16.csv -n 700000
	./QueryCreator.exe -o Pruebas/QueryTest17.csv -n 1000000


Test: tp1 Pruebas/CPU_Temp.csv $(FILES_PRUEBAS) 
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest1.csv -o Pruebas/out1.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest2.csv -o Pruebas/out2.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest3.csv -o Pruebas/out3.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest4.csv -o Pruebas/out4.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest5.csv -o Pruebas/out5.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest6.csv -o Pruebas/out6.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest7.csv -o Pruebas/out7.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest8.csv -o Pruebas/out8.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest9.csv -o Pruebas/out9.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest10.csv -o Pruebas/out10.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest11.csv -o Pruebas/out11.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest12.csv -o Pruebas/out12.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest13.csv -o Pruebas/out13.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest14.csv -o Pruebas/out14.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest15.csv -o Pruebas/out15.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest16.csv -o Pruebas/out16.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest17.csv -o Pruebas/out17.csv

TestFile: tp1 Pruebas/CPU_Temp.csv $(FILES_PRUEBAS) Help/GraficGenerator.m
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest1.csv -o Pruebas/out1.csv | cat > Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest1.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t100\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest2.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest2.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t300\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest3.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest3.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t500\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest4.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest4.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t700\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest5.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest5.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t1000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest6.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest6.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t3000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest7.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest7.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t5000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest8.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest8.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t7000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest9.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest9.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t10000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest10.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest10.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t30000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest11.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest11.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t50000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest12.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest12.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t70000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest13.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest13.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t100000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest14.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest14.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t300000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest15.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest15.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t500000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest16.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest16.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t700000\n" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest17.csv -o Pruebas/out1.csv | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t" >> Pruebas/ExecutionTime.csv
	./tp1 -d Pruebas/CPU_Temp.csv -i Pruebas/QueryTest17.csv -o Pruebas/out1.csv -p Iteration | cat >> Pruebas/ExecutionTime.csv
	$(ECHO) -n -e "\t1000000\n" >> Pruebas/ExecutionTime.csv

############################################################

clear:
	rm *.o


