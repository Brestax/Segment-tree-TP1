/*
	Archivo: SegmentTree.cpp
*/

#include "SegmentTree.hpp"
#include "Quartet.hpp"

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

SegmentTree::~SegmentTree(){
	if(_Array == Null)
		delete [] _Array;
}



