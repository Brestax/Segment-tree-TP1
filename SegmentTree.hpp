/*
	Archivo: SegmentTree.hpp
*/

#ifndef _SEGMENTTREE_HPP_INCLUDED_
#define _SEGMENTTREE_HPP_INCLUDED_

#include <iostream>
#include <cstdlib>

#include "Element.hpp"
#include "ArrayElement.hpp"
#include "Package.hpp"
#include "Quartet.hpp"

class SegmentTree{

private:

	int _Leng, _UsedLeafs;
	Quartet * _Array;

	SegmentTree();
	SegmentTree(const SegmentTree &);
	friend Quartet& _GetSegment(int, int, int);
	
public:
	SegmentTree(const ArrayElement &);
	Package& GetSegment(int, int);
	~SegmentTree();
};

#endif














