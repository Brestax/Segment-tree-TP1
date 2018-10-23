/*
	Archivo: main.cpp
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Cmdline.hpp"
#include "Red.hpp"
#include "Error.hpp"
#include "Utils.hpp"

#define OPTION_TREE "Tree"
#define OPTION_ITERATION "Iteration"

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_data(string const &);
static void opt_process(string const &arg); 
static void opt_help(string const &);

/********************* Elementos golbales *********************/

static option_t options[] = {
	{1, "d", "data", NULL, opt_data, OPT_MANDATORY},
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "p", "Process", "-", opt_process, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *dss = 0;
static istream *iss = 0;
static ostream *oss = 0;
static fstream dfs;
static fstream ifs;
static fstream ofs;
bool ProcessTree;	// Es un bool para determinar si se utiliza el SegmentTree o no

/********************* Cuerpo principal *********************/

int main(int argc, char * const argv[]){

	status_t st;

	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente.
	cmdl.parse(argc, argv);	// Metodo de parseo de la clase cmdline. Settea las variables globales

	Red SensorNet;
	unsigned t0, t1;

	t0 = clock();

	// Se llama a una funcion que parsea todo el archivo de los datos
	if ((st = ParseAll(*dss, SensorNet)) != ST_OK){
		PrintError(st);
		return EXIT_FAILURE;
	}

	// Se llama a una funcion que Processa todas las querys del archivo de entrada y escribe el archivo de salida
	if ((st = ManageQuerys(*iss, *oss, SensorNet)) != ST_OK){
		PrintError(st);
		return EXIT_FAILURE;
	}

	t1 = clock();

	double time = (double (t1 - t0)/CLOCKS_PER_SEC);
	cout <<  time;

	return EXIT_SUCCESS;
}

/********************* Funciones de parceo *********************/


static void opt_input(string const &arg){
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
 	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_output(string const &arg){
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

static void opt_data(string const &arg){
	dfs.open(arg.c_str(), ios::in);
	dss = &dfs;

	//Verificamos que el stream este OK.
	//
	if(!dss->good()){
		cerr << "cannot open "
			 << arg
			 << "."
			 << endl;
		exit(1); 		// EXIT: Terminación del programa en su totalidad
	}
}

static void opt_process(string const &arg){

	if (arg == "-") {
		ProcessTree = true;	// Establezco la opcion estandar como el proceso utilizando el SegmentTree
	}else if(arg == OPTION_TREE){
		ProcessTree = true;
	}else if(arg == OPTION_ITERATION){
		ProcessTree = false;
	}else{
		ProcessTree = true;
	}
}

static void opt_help(string const &arg){
	cout << "cmdline -d file [-i file] [-o file]"
	     << endl;
	exit(0);
}



