/*
	Archivo: ArrayElement.cpp
*/

#include <iostream>
#include <cstdlib>

#include "Element.hpp"
#include "ArrayElement.hpp"

#define INIT_LENG 10
#define ERROR_INVALID_ARGUMENT "ArrayElement constructor: negative arguments not allowed."
#define ERROR_ARRAY_INDEX "ArrayElement operator []: index not allowed."

ArrayElement::ArrayElement(){
	_Leng = INIT_LENG;
	_Used = 0;
	_Array = new Element[INIT_LENG];
	// No es necesario inicializar los elementos ya que todos se cnstruyen vacios
}

ArrayElement::ArrayElement(int N){
	//Si el argumento es invalido es invalido sale del programa
	if(N <= 0){
		std::cerr << ERROR_INVALID_ARGUMENT << std::endl;
		exit(EXIT_FAILURE);
	}

	_Leng = N;
	_Used = 0;
	_Array = new Element[_Leng];
	// No es necesario inicializar los elementos ya que todos se cnstruyen vacios
}

ArrayElement::ArrayElement(const ArrayElement & Original){

	_Leng = Original._Leng;
	_Used = Original._Used;
	_Array = new Element[_Leng];

	for (int i = 0; i < _Used; ++i){
		_Array[i] = Original._Array[i];
	}
}

int ArrayElement::UsedSize() const{
	return _Used;
}

Element& ArrayElement::operator[](int pos){
	//Si la posicion ingresada es invalida, sale del programa
	if(pos < 0 && pos >= _Used){
		std::cerr << ERROR_ARRAY_INDEX << std::endl;
		exit(EXIT_FAILURE);
	}

	return _Array[pos];
}

Element& ArrayElement::operator[](int pos) const{
	//Si la posicion ingresada es invalida, sale del programa
	if(pos < 0 || pos >= _Used){
		std::cerr << ERROR_ARRAY_INDEX << std::endl;
		exit(EXIT_FAILURE);
	}

	return _Array[pos];
}

void ArrayElement::Append(const Element & e){
	int NewSize = _Leng * 2;
	Element * aux;

	//Si el Array no esta lleno, agrego el nuevo elemento
	if(_Used < _Leng){
		_Array[_Used] = e;
		_Used ++;
	}else{	// Si el Array esta lleno, hay qe alargarlo antes de incertar
			//el elemento nuevo

		//Primero se copia todo a un Array auxiliar
		aux = new Element[_Leng];
		for(int i = 0; i < _Used; i++){
			aux[i] = _Array[i];
		}

		//Destruye y crea un nuevo Array con el doble de largo
		delete [] _Array;
		_Array = new Element[NewSize];
		_Leng = NewSize;

		//Se rellena el nuevo Array con los datos almacenados en el
		// arreglo auxiliar
		for(int i = 0; i < _Used; i++){
			_Array[i] = aux[i];
		}

		//Se destruye el arreglo auxiliar
		delete [] aux;

		// Se agrega el nuevo elemento
		_Array[_Used] = e;
		_Used++;
   	}
}

ArrayElement::~ArrayElement(){
	delete [] _Array;
}
