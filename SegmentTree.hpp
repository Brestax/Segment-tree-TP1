/*
	Archivo: SegmentTree.hpp
*/

#ifndef _SEGMENTTREE_HPP_INCLUDED
#define _SEGMENTTREE_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

#include "Element.hpp"
#include "Package.hpp"
#include "Quartet.hpp"

class SegmentTree{

private:

	int _Leng, _UsedLeafs;
	Quartet * _Array;

	SegmentTree();
	SegmentTree(const SegmentTree &);
	
public:
	SegmentTree(const ArrayElement &);
	Package& GetSegment(int, int);
	~SegmentTree();
};

#endif














