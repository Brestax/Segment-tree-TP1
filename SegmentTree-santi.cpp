#include "SegmentTree.hpp"
#include "Quartet.hpp"

SegmentTree::SegmentTree(const ArrayElement &Array){
	int Pos;
	ArrayLen = Array.GetLen();
	if(!ArrayLen){
		_Array = NULL;
		return;
	}
	if(ArrayLen == 1){
		_Array = new Quartet;
		return;
	}
	
	for(i = 0, j = 1; ArrayLen < 2 * j; i++, j*=2){
	}

	_Len = (2 * j) * 2 - 1;
	_Array = new Quartet[_Len];


	for(i = (_Len - 1) / 2, j = 0; i < (_Len - 1) / 2 + ArrayLen; i++, j++){
		if(Array[j].IsEmpty())
			continue;
		_Array[i].SetMin(Array[j].GetNumber());
		_Array[i].SetMax(Array[j].GetNumber());
		_Array[i].SetTotal(Array[j].GetNumber());
		_Array[i].SetQuantity(1);
	}

	Pos = _Len;
	while(Pos){
		if(Array[j].IsEmpty())
			continue;
		if(_Array[Pos].GetMin > _Array[Pos - 1]){
			_Array[(Pos - 1) / 2].SetMin(_Array[Pos - 1]);
			_Array[(Pos - 1) / 2].SetMin(_Array[Pos - 1]);

		}
	}
}

