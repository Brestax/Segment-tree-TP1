/*
	Archivo: Quartet.hpp
*/

#ifndef _ARRAYELEMENT_HPP_INCLUDED
#define _ARRAYELEMENT_HPP_INCLUDED

class Quartet{

private:
	double _Min;
	double _Max;
	double _Total;
	int	_Quantity;
	int _Left;
	int _Right;
	bool _InfinityStatus;	// Se usa para definir definir al minimo como infinito y el maximo como menos infinito es caso de comparar
public:
	Quartet();
	Quartet(const Quartet &);
	double GetTotal(void);
	double GetMin(void);
	double GetMax(void);
	int GetQuantity(void);
	int GetLeft(void);
	int GetRight(void);
	bool GetInfinity(void);
	void SetTotal(double);
	void SetMin(double);
	void SetMax(double);
	void SetQuantity(int);
	void SetLeft(int);
	void SetRight(int);
	void ToInfinity(void);
	void Clear();			// Esta funcion setea todos los numeros en cero y el flag en true
	Quartet& operator=(const Quartet &);
	Quartet Merge(const Quartet &);
	~Quartet();
};

#endif
