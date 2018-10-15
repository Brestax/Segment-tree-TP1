/*
	Archivo: SegmentTree.hpp
*/

#ifndef _SEGMENTTREE_HPP_INCLUDED
#define _SEGMENTTREE_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

#include "Quartet.hpp"

class SegmentTree{

private:

	int _Leng, _UsedLeafs;
	Quartet * _Array;

	SegmentTree();
	SegmentTree(const SegmentTree &);
	Quartet& _GetSegment(int, int, int);
	
public:
	SegmentTree(const ArrayElement &);
	Quartet& GetSegment(int, int);
	~SegmentTree();
};

#endif














