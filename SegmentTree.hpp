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
	int Leng;
	Quartet * _Array;

	SegmentTree();
	SegmentTree(const SegmentTree &);

public:
	SegmentTree(const ArrayElement &);

	~SegmentTree();
};

#endif














