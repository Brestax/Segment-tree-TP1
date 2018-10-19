/*
	Archivo: Element.hpp
*/

#ifndef _ELEMENT_HPP_INCLUDED
#define _ELEMENT_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

class Element{

private:
	double _Number;
	bool _EmptyStatus;
public:
	Element();			// Cuando se crean los datos se crean vacios
	Element(const Element &);
	double GetData(void);
	bool IsEmpty(void);
	void SetData(double);
	void Empty(void);	// Vacia el dato de lo que tenga
	Element& operator=(const Element &);
	Element& operator=(double);
	~Element();
};

#endif
