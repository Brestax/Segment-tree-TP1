/*
	Archivo: Red.cpp
*/

#ifndef _RED_HPP_INCLUDED_
#define _RED_HPP_INCLUDED_

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Element.hpp"
#include "ArrayElement.hpp"
#include "Package.hpp"
#include "SegmentTree.hpp"

#define MSG_BAD_RANGE "NO DATA"
#define MSG_BAD_QUERY "BAD QUERY"
#define MSG_BAD_ID "NO ID"

#define INITIAL_LENGTH_VECTOR 25

class Red {

private:

	string * _Ids;
	ArrayElement ** _Sensors;
	SegmentTree ** _Trees;
	Package  * _Pack;

	int _Amount;   		// Cantidad de sensores almacenados

	void CreateVectors(int);

public:

	Red();
	Red(int);
	Red(const Red &);
	int GetLeng(void) const;
	Package * GetPackage() const;
	void SetSensors(string * &, size_t);
	void PrintPackage(std::ostream &);					//Impresion de los datos acumulados en el paquetem se imprime en el stream que se le pasa y lo hace con formato
	void MakeSmallQuery(string, int, int);				//Le paso un string con la ID del sensor y los rangos para hacer el query
	void MakeBigQuery(int, int);						//Le paso los rangos para hacer la query ya que lo hace sobre todos los sensores
	void MakeComplexQuery(string * &, int, int, int);	//Le paso un vector de strings con los Ids de los sensores, la cantidad de sensores y los rangos para el query
	void MakeSmallQueryTree(string, int, int);			
	void MakeBigQueryTree(int, int);
	void MakeComplexQueryTree(string * &, int, int, int);
	void AppendRow(Element * &);
	void ProcessTrees(void);
	~Red();

};

#endif





