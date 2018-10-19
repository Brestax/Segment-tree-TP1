/*
	Archivo: SegmentTree.cpp
*/

#include "Element.hpp"
#include "Package.hpp"
#include "Quartet.hpp"
#include "SegmentTree.hpp"

Quartet& _GetSegment(int, int, int);

SegmentTree::SegmentTree(){
	_Leng = 0;
	_UsedLeafs = 0;
	_Array = NULL;
}

SegmentTree::SegmentTree(const SegmentTree & s){
	_Leng = s._Leng;
	_UsedLeafs = s._UsedLeafs;

	_Array = new Quartet[_Leng];
	for(int i = 0; i < _Leng; i++)
		_Array[i] = s._Array[i];
}

SegmentTree::SegmentTree(const ArrayElement &Source){
	int Pos, LeafPosition;
	int SourceLeng = Source.UsedSize();

	// resuelvo los casos en que el largo es 0 o 1
	if(!SourceLeng){
		_Array = NULL;
		_Leng = 0;
		return;
	}
	if(SourceLeng == 1){
		_Array = new Quartet;
		_Leng = 1;
		if(!(Array[0].IsEmpty())){
			_Array[0].SetMin(Source[0].GetData());
			_Array[0].SetMax(Source[0].GetData());
			_Array[0].SetTotal(Source[0].GetData());
			_Array[0].SetQuantity(1);
		}
		return;
	}

	// Busco el numero que sea exponente de dos mayor al numero de datos, ya que ese debe ser el numero de hojas del arbol
	for(i = 0, j = 1; SourceLeng <= 2 * j; i++, j*=2){
	}

	_Leng = (2 * j) * 2 - 1;
	LeafPosition = (2 * j) - 1;
	_Array = new Quartet[_Leng];

	// Se llenan los nodos hoja con los valores del arreglo de elementos
	for(i = LeafPosition, j = 0; i < LeafPosition + SourceLeng; i++, j++){
		if(Source[j].IsEmpty())
			continue;
		_Array[i].SetMin(Source[j].GetData());
		_Array[i].SetMax(Source[j].GetData());
		_Array[i].SetTotal(Source[j].GetData());
		_Array[i].SetQuantity(1);
		_Array[i].SetRight(j);
		_Array[i].SetLeft(j + 1);
	}

	// Se rellena los nodos hoja vacios con sus extremos de su intervalo para poder llenar a los padres
	for(; i < _Leng; i++, j++){
		_Array[i].SetRight(j);
		_Array[i].SetLeft(j + 1);		
	}

	// Calculo todos los campos de cada nodo que no sea hoja
	for(i = LeafPosition - 1; i >= 0; --i){		
		// Primero de todo seteo los extremos del segmento ya que hay que setear todos los nodos de la misma manera
		_Array[i].SetRight(_Array[(i * 2) + 1].GetRight());
		_Array[i].SetLeft(_Array[(i * 2) + 2].GetLeft());

		// Si sus dos hijos estan vacios no se hace nada
		if((_Array[(i * 2) + 1].GetInfinity()) && (_Array[(i * 2) + 2].GetInfinity()))
			continue;

		// Si uno de sus dos nodos hijos esta vacio se llena el nodo con los resultados de su otro hijo
		if(!(_Array[(i * 2) + 1].GetInfinity()) && (_Array[(i * 2) + 2].GetInfinity())){
			_Array[i].SetMin(_Array[(i * 2) + 1].GetMin());
			_Array[i].SetMax(_Array[(i * 2) + 1].GetMax());			
			_Array[i].SetTotal(_Array[(i * 2) + 1].GetTotal());			
			_Array[i].SetQuantity(_Array[(i * 2) + 1].GetQuantity());
			continue;
		}
		if((_Array[(i * 2) + 1].GetInfinity()) && !(_Array[(i * 2) + 2].GetInfinity())){
			_Array[i].SetMin(_Array[(i * 2) + 1].GetMin());
			_Array[i].SetMax(_Array[(i * 2) + 1].GetMax());			
			_Array[i].SetTotal(_Array[(i * 2) + 1].GetTotal());			
			_Array[i].SetQuantity(_Array[(i * 2) + 1].GetQuantity());
			continue;

		}

		// Llegado al caso de que los dos nodos hijo tienen datos, se resuelve cada campo por separado
		if(_Array[(i * 2) + 1].GetMin() < _Array[(i * 2) + 2].GetMin()){
			_Array[i].SetMin(_Array[(i * 2) + 1].GetMin());
		}else{
			_Array[i].SetMin(_Array[(i * 2) + 2].GetMin());
		}
	
		if(_Array[(i * 2) + 1].GetMax() > _Array[(i * 2) + 2].GetMax()){
			_Array[i].SetMax(_Array[(i * 2) + 1].GetMax());
		}else{
			_Array[i].SetMax(_Array[(i * 2) + 2].GetMax());
		}

		_Array[i].SetTotal(_Array[(i * 2) + 1].GetTotal() + _Array[(i * 2) + 2].GetTotal());
		_Array[i].SetQuantity(_Array[(i * 2) + 1].GetQuantity() + _Array[(i * 2) + 2].GetQuantity());
	}
}

Package& SegmentTree::GetSegment(int Left, int Right){
	Quartet aux;
	Package Answer;	

	// Revisar limites
	if(Left > _UsedLeafs){
		Answer.SetRangeStatus(true);
	}
	if(End > _UsedLeafs){
		Right = _UsedLeafs;
	}

	// Si el rango esta mal salgo del query
	if(Answer.GetRangeStatus()){ 
		return Answer;
	}

	// LLAmamos a la funcion recursiva que es privada y se recive un Quartet 
	aux = _GetSegment(0, Left, Right);

	// Se transforman las soluciones de Quartet a Paquete
	if(!aux.GetInfinity()){
		Answer.SetMin(aux.GetMax());
		Answer.SetMax(aux.GetMax());
		Answer.SetAverage(aux.GetTotal()/aux.GetQuantity());
		Answer.SetQuantity(aux.GetQuantity());
	}else
		Answer.SetRangeStatus(true);

	return Answer;
}

SegmentTree::~SegmentTree(){
	if(_Array == Null)
		delete [] _Array;
}


Quartet& _GetSegment(int Node, int Left, int Right){
	int Middle;
	Quartet LeftPart, RightPart;

	// Si el intervalo es exactamente el que se pide, se devuelve el quartet que se tiene
	if((_Array[Node].GetLeft() == Left) && (_Array[Node].GetRight() == Right)){
		return _Array[Node];
	}

	Middle = (_Array[Node].GetLeft() + _Array[Node].GetRight()) / 2;

	// Si el extremo derecho del intervalo es mayor que la mitad del nodo le pide la respuesta al hijo izquierdo
	if(Right <= Middle)
		return _GetSegment(2 * Node + 1, Right, Left);

	// Si el extremo izquierdo del intervalo es menor que la mitad del intervalo del nodo, se le pide la respuesta del intervalo al hijo derecho
	if(Left >= Middle)
		return _GetSegment(2 * Node + 2, Right, Left);

	// En este punto la respuesta es una combinacion de los dos hijos, por lo que se le pide sus respectivas respuestas y luego se combinan
	LeftPart = _GetSegment(2 * Node + 1, Left, Middle);
	RightPart = _GetSegment(2 * Node + 2, Middle, Right);

	return LeftPart.Merge(RightPart);
}
