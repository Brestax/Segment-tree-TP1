/*
	Archivo: SegmentTree.cpp
*/

#include "SegmentTree.hpp"
#include "Quartet.hpp"

// Falta setear los valores de cada extremo de cada nodo , es decir de Left y Right de cada Quartet

SegmentTree::SegmentTree(const ArrayElement &Source){

	int Pos, LeafPosition;
	SourceLeng = Source.UsedSize();

	if(!SourceLeng){
		_Array = NULL;
		_Leng = 0;
		return;
	}

	if(SourceLen == 1){
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

	for(i = 0, j = 1; SourceLeng <= 2 * j; i++, j*=2){
	}

	_Len = (2 * j) * 2 - 1;
	LeafPosition = (2 * j) - 1;
	_Array = new Quartet[_Len];

	for(i = LeafPosition, j = 0; i < LeafPosition + SourceLen; i++, j++){
		if(Source[j].IsEmpty())
			continue;
		_Array[i].SetMin(Source[j].GetData());
		_Array[i].SetMax(Source[j].GetData());
		_Array[i].SetTotal(Source[j].GetData());
		_Array[i].SetQuantity(1);
	}

	for(i = LeafPosition - 1; i >= 0; --i){		
		if((_Array[(i * 2) + 1].GetInfinity()) && (_Array[(i * 2) + 2].GetInfinity()))
			continue;

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

Quartet& SegmentTree::GetSegment(int Left, int Right){
	// Falta validar que los valores sean mayores que 0 y ademas que LEft no sea mayor que el numero de valores, ajustar para cuando Right es mayor que el numero de valores

	// Quizas conviene que la funcion devuela un paquete (el mismo que tiene el objeto red) 
	return _GetSegment(0, Left, Right);
}

Quartet& SegmentTree::_GetSegment(int Node, int Left, int Right){
	int Midle;
	Quartet LeftPart, RightPart;

	if((_Array[Node].GetLeft() == Left) && (_Array[Node].GetRight() == Right)){
		return _Array[Node];
	}

	Midle = (_Array[Node].GetLeft() + _Array[Node].GetRight()) / 2;

	if(Right <= Midle)
		return _GetSegment(2 * Node + 1, Right, Left);

	if(Left >= Midle)
		return _GetSegment(2 * Node + 2, Right, Left);

	LeftPart = _GetSegment(2 * Node + 1, Left, Midle);
	RightPart = _GetSegment(2 * Node + 2, Midle, Right);

	return LeftPart.Merge(RightPart);
}

SegmentTree::~SegmentTree(){
	if(_Array == Null)
		delete [] _Array;
}



