/*
	Archivo: Utils.hpp
*/

#ifndef _UTILS_HPP_INCLUDED_
#define _UTILS_HPP_INCLUDED_

#include <iostream>

#include "Element.hpp"
#include "Red.hpp"
#include "Error.hpp"
#include "Package.hpp"

#define LINE_DIVIDER ','
#define SENSOR_DIVIDER ';'

status_t ParseAll(istream & is, Red & Object);
status_t ManageQuerys(istream & is, ostream & os, Red & Object);

#endif
