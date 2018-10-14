/*
	Archivo: Quartet.cpp
*/

#include <iostream>
#include <cstdlib>

#include "Quartet.hpp"

Quartet::Quartet(){
	_Total = 0;
	_Quantity = 0;
	_InfinityStatus = true;	
}

Quartet::Quartet(conts Quartet & q){
	if(!(_InfinityStatus = q._InfinityStatus)){
		_Min = q._Min;
		_Max = q._Max;
	}
	_Total = q._Total;
	_Quantity = q._Quantity;
}

double Quartet::GetTotal(void){
	return _Total;
}

double Quartet::GetMin(void){
	return _Min;
}

double Quartet::GetMax(void){
	return _Max;
}

int Quartet::GetQuantity(void){
	return _Quantity;
}

int Quartet::GetLeft(void){
	return _Left;
}

int Quartet::GetRight(void){
	return _Right;
}

bool Quartet::GetInfinity(void){
	return _InfinityStatus;
}

void Quartet::SetTotal(double d){
	_Total = d;
	_InfinityStatus = false;
}

void Quartet::SetMin(double d){
	_Min = d;
	_InfinityStatus = false;
}

void Quartet::SetMax(double d){
	_Max = d;
	_InfinityStatus = false;
}

void Quartet::SetQuantity(int i){
	_Quantity = i;
	_InfinityStatus = false;
}

void Quartet::SetLeft(int i){
	_Left = i;
}

void Quartet::SetRight(int i){
	_Right = i;
}

void Quartet::ToInfinity(void){
	_InfinityStatus = true;
}

void Quartet::Clear(void){
	_Total = 0;
	_Quantity = 0;
	_InfinityStatus = true;
}


Quartet& Quartet::operator=(const Quartet & q){
	if(!(_InfinityStatus = q._InfinityStatus)){
		_Min = q._Min;
		_Max = q._Max;
	}
	_Total = q._Total;
	_Quantity = q._Quantity;	
	return *this;
}

Quartet& Quartet::Merge(const Quartet & q){
	Quartet aux;

	if(_Right == q._Left){
		aux._Left = _Left;
		aux._Right = q._Right;
	}else{
		aux._Left = q._Left;
		aux._Right = _Right;
	}

	if(_InfinityStatus && q._InfinityStatus){
		return aux;
	}

	if(!(_InfinityStatus) && q._InfinityStatus){
		aux._InfinityStatus = false;
		aux._Min = _Min;
		aux._Max = _Max;
		aux._Total = _Total;
		aux._Quantity = _Quantity;
		return aux;
	}

	if(_InfinityStatus && !(q._InfinityStatus)){
		aux._InfinityStatus = false;
		aux._Min = q._Min
		aux._Max = q._Max;
		aux._Total = q._Total;
		aux._Quantity = q._Quantity;
		return aux;
	}

	aux._InfinityStatus = false;
	if(_Min <= q._Min)
		aux._Min = _Min;
	else
		aux._Min = q._Min;
	if(_Max >= q._Max)
		aux._Max = _Max;
	else
		aux._Max = q._Max;
	aux._Total = _Total + q._Total;
	aux._Quantity = _Quantity + q._Quantity;

	return aux;
}

Quartet::~Quartet(){
}
























