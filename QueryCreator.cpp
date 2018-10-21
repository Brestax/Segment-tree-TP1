/*
	Archivo: QueryCreator.cpp
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Cmdline.hpp"

#define QUERRY_STRING ",1,349"

using namespace std;

static void opt_output(string const &);
static void opt_number(string const &);
static void opt_help(string const &);

/********************* Elementos golbales *********************/

static option_t options[] = {
	{1, "o", "output", NULL, opt_output, OPT_MANDATORY},
	{1, "n", "number", NULL, opt_number, OPT_MANDATORY},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static ostream *oss = 0;
static fstream ofs;
static int Number;

/********************* Cuerpo principal *********************/

int main(int argc, char * const argv[]){

	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente.
	cmdl.parse(argc, argv);	// Metodo de parseo de la clase cmdline. Settea las variables globales

	for(int i = 0; i < Number; i++){
		*oss << QUERRY_STRING << endl;
	}

	return EXIT_SUCCESS;
}

/********************* Funciones de parceo *********************/

static void opt_output(string const &arg){
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	ofs.open(arg.c_str(), ios::out);
	oss = &ofs;

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

static void opt_number(string const &arg){
	stringstream StringRead(arg);

	if(!(StringRead >> Number)){
		exit(1);
	}
}


static void opt_help(string const &arg){
	cout << "cmdline -d file [-i file] [-o file]"
	     << endl;
	exit(0);
}




	




