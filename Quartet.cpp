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

bool Quartet::GetInfinity(void){
	return _InfinityStatus;
}

void Quartet::SetTotal(double d){
	_Total = d;
}

void Quartet::SetMin(double d){
	_Min = d;
	_InfinityStatus = false;
}

void Quartet::SetMax(double d){
	_Max = d;
	_InfinityStatus = false
}

void Quartet::SetQuantity(int i){
	_Quantity = i;
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

Quartet::~Quartet(){
}
























