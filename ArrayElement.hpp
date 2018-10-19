/*
	Archivo: ArrayElement.hpp
*/

#ifndef _ARRAYELEMENT_HPP_INCLUDED_
#define _ARRAYELEMENT_HPP_INCLUDED_

#include <iostream>
#include <cstdlib>

#include "Element.hpp"

class ArrayElement{

private:
	int _Leng;
	int _Used;
	Element * _Array;

	ArrayElement();		// Este metodo es privao debido a que no se quiere que se cree un Array con un nunmero de elementos no definido

public:

	ArrayElement(int);
	ArrayElement(const ArrayElement &);
	int UsedSize() const;
	Element& operator[](int pos);
	Element& operator[](int pos) const;
	void Append(const Element &);
	~ArrayElement();
};

#endif
