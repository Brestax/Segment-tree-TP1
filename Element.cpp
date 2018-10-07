/*
	Archivo: Element.cpp
*/

#include <iostream>
#include <cstdlib>

#include "Element.hpp"

Element::Element(){
	_EmptyStatus = false;
}

Element::Element(const Element & e){
	if(!(_EmptyStatus = e._EmptyStatus)){
		_Number = e._Number;
	}
}

double Element::GetData(void){
	return _Number;
}

bool Element::IsEmpty(void){
	return _EmptyStatus;
}

void Element::SetData(double d){
	_EmptyStatus = false;
	_Number = d;
}

void Element::Empty(void){
	_EmptyStatus = true;
}

Element& Element::operator=(const Element & e){
	if(!(_EmptyStatus = e._EmptyStatus)){
		_Number = e._Number;
	}
	return *this;
}

Element& Element:: operator=(double d){
	_EmptyStatus = false;
	_Number = d;
	return *this;
}

Element::~Element(){
}


