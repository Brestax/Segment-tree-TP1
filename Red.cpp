/*
	Archivo: Red.cpp
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Element.hpp"
#include "ArrayElement.hpp"
#include "Package.hpp"
#include "Utils.hpp"
#include "Red.hpp"

Red::Red(){
	_Ids = NULL;
	_Sensors = NULL;
	_Pack = new Package;
	_Amount = 0;
}

Red::Red(int Number){
	_Ids = new string[Number];
	_Sensors = new ArrayElement*[Number + 1];
	for (int i = 0; i <= Number; ++i){
		_Sensors[i] = new ArrayElement(INITIAL_LENGTH_VECTOR);
	}
	_Pack = new Package;
	_Amount = Number;
}

Red::Red(const Red & r){
	int SensorSize;

	SensorSize = r.GetLeng();

	_Ids = new string[SensorSize];
	for (int i = 0; i < SensorSize; ++i){
		_Ids[i] = r._Ids[i];
	}

	_Sensors = new ArrayElement*[SensorSize + 1];
	for (int i = 0; i <= SensorSize; ++i){
		_Sensors[i] = new ArrayElement(*(r._Sensors[i]));
	}

	_Pack = new Package(*(r._Pack))	;
}

int Red::GetLeng(void) const{
	return _Amount;
}

Package * Red::GetPackage()const{
	return _Pack;
}

void Red::SetSensors(string * &Names, size_t Number){
	// Number indica la cantidad de strings que tiene el puntero Names
	string * aux;

	aux = new string[Number];					// Se crea un vector independiente de strings para que el objeto red tenga su propio vector
	for (size_t i = 0; i < Number; ++i){
		aux[i] = Names[i];
	}

	if(_Ids != NULL){							// Si el objeto ya tenia Ids asignados se los borra
		delete [] _Ids;
	}
	_Ids = aux;

	if(_Sensors != NULL){						// Si ya se tenia una tabla de valores se la borra
		for (int i = 0; i < _Amount; ++i){
			delete[] _Sensors[i];
		}
		delete[] _Sensors;
	}

	_Sensors = new ArrayElement*[Number + 1];			// Se crean los arrays de doubles vacios
	for(size_t i = 0; i <= Number; ++i){
		_Sensors[i] = new ArrayElement(INITIAL_LENGTH_VECTOR);
	}

	_Amount = Number; 							// Se le asigna la nueva cantidad de sesores
}

void Red::PrintPackage(std::ostream & os){
	if(_Pack->GetQueryStatus()){
		os << MSG_BAD_QUERY << std::endl;
	}else if(_Pack->GetRangeStatus()){
		os << MSG_BAD_RANGE << std::endl;
	}else if(_Pack->GetIdStatus())
		os << MSG_BAD_ID << std::endl;
	else{
		os << _Pack->GetAverage() << ',' << _Pack->GetMin() << ','
			<< _Pack->GetMax() << ',' << _Pack->GetQuantity() << std::endl;
	}
	(*_Pack).Clear();
}

void Red::MakeSmallQuery(string ID, int Start, int End){
	int i,j;
	int FinalMark;
	Package * aux;

	aux = new Package;

	aux->SetIdStatus(true);
	for(i = 0; i < _Amount; i++){
		if(!(_Ids[i].compare(ID))){
			aux->SetIdStatus(false);
			break;
		}
	}
	if(aux->GetIdStatus()){
		*_Pack = *aux;
		delete aux;
		return;
	}

	// Verifio si el intervalo esta en los Arreglos
	if(Start > _Sensors[i]->UsedSize()){
		_Pack->SetRangeStatus(true);
	}
	if(End > _Sensors[i]->UsedSize()){
		FinalMark = _Sensors[i]->UsedSize();
	}else{
		FinalMark = End;
	}

	// Si el rango esta mal salgo del query
	if(_Pack->GetRangeStatus()){
		delete aux;
		return;
	}

	// Busco un dato que no este vacio
	j = 0;
	while(!((*_Sensors[i])[Start + j]).IsEmpty())
		j++;

	// Hay que setearlos de esta manera ya que en el vector puede ser que el minimo sea mayor que 0 o el maximo menor que 0
	aux->SetMin((*_Sensors[i])[Start]);
	aux->SetMax((*_Sensors[i])[Start]);

	for (j = Start; j < FinalMark; j++){
		if(!((*_Sensors[i])[j]).IsEmpty()){
			if(((*_Sensors[i])[j]).GetData() < aux->GetMin())
				aux->SetMin(((*_Sensors[i])[j]).GetData());
			if(((*_Sensors[i])[j]).GetData() > aux->GetMax())
				aux->SetMax(((*_Sensors[i])[j]).GetData());
			aux->SetQuantity(aux->GetQuantity() + 1);
			aux->SetAverage(aux->GetAverage() + ((*_Sensors[i])[j]).GetData());
		}
	}

	aux->SetAverage(aux->GetAverage() / aux->GetQuantity());

	*_Pack = *aux;
	delete aux;
}

void Red::MakeBigQuery(int Start, int End){
	int FinalMark;		// Indica donde termina la iteracion
	Package * aux;

	aux = new Package;

	////aux->Clear();

	// Verifico si el intervalo esta en los Arreglos
	if(Start > _Sensors[0]->UsedSize()){
		_Pack->SetRangeStatus(true);
	}
	if(End > _Sensors[0]->UsedSize()){
		FinalMark = _Sensors[0]->UsedSize();
	}else{
		FinalMark = End;
	}

	// Si el rango esta mal salgo del query
	if(_Pack->GetRangeStatus())
		return;

	// Busco un dato que no este vacio
	j = 0;
	while(!((*_Sensors[_Amount])[Start + j]).IsEmpty())
		j++;

	// Hay que setearlos de esta manera ya que en el vector puede ser que el minimo sea mayor que 0 o el maximo menor que 0
	aux->SetMin((*_Sensors[_Amount])[Start]);
	aux->SetMax((*_Sensors[_Amount])[Start]);

	for (j = Start; j < FinalMark; j++){
		if(!((*_Sensors[_Amount])[j]).IsEmpty()){
			if(((*_Sensors[_Amount])[j]).GetData() < aux->GetMin())
				aux->SetMin(((*_Sensors[_Amount])[j]).GetData());
			if(((*_Sensors[_Amount])[j]).GetData() > aux->GetMax())
				aux->SetMax(((*_Sensors[_Amount])[j]).GetData());
			aux->SetQuantity(aux->GetQuantity() + 1);
			aux->SetAverage(aux->GetAverage() + ((*_Sensors[_Amount])[j]).GetData());
		}
	}

	aux->SetAverage(aux->GetAverage() / aux->GetQuantity());
	

	*_Pack = *aux;
	delete aux;
}

void Red::MakeComplexQuery(string * & ID, int SensorQuantity, int Start, int End){
	int FinalMark;						// Indica donde termina la iteracion
	Package * aux;
 	int i, j, k;

	aux = new Package;


	// Verifio si el intervalo esta en los Arreglos
	if(Start > _Sensors[0]->UsedSize()){
		_Pack->SetRangeStatus(true);
	}
	if(End > _Sensors[0]->UsedSize()){
		FinalMark = _Sensors[0]->UsedSize();
	}else{
		FinalMark = End;
	}

	// Si el rango esta mal salgo del query
	if(_Pack->GetRangeStatus())
		return;

	aux->SetQuantity(SensorQuantity * (FinalMark - Start));

	// Cuardo el query es complejo hay que encontrar el primer array indicado para setear los valores iniciales de minimo y maximo
	aux->SetIdStatus(true);

	for(i = 0; i < _Amount; i++){
		if(!(_Ids[i].compare(*ID))){
			aux->SetIdStatus(false);
			break;
		}
	}
	if(aux->GetIdStatus()){
		*_Pack = *aux;
		delete aux;
		return;
	}

	// Hay que setearlos de esta manera ya que en el vector puede ser que el minimo sea mayor que 0 o el maximo menor que 0
	aux->SetMin((*_Sensors[i])[Start]);
	aux->SetMax((*_Sensors[i])[Start]);

	//	Finalmente hago el analisis de los datos
	for(i = 0; i < SensorQuantity; ++i){
		// Recorro para comprobar si el Id esta entre los sensores y en que posicion
		aux->SetIdStatus(true);
		for(j = 0; j < _Amount; j++){
			if(!(_Ids[j].compare(ID[i]))){
				aux->SetIdStatus(false);
				break;
			}
		}
		if(aux->GetIdStatus()){
			*_Pack = *aux;
			delete aux;
			return;
		}

		// Una vez identificado el sensor al que se pide, se analiza la informacion
		for(k = Start; k < FinalMark; k++){
			aux->SetAverage(aux->GetAverage() + (*_Sensors[j])[k] / aux->GetQuantity());
			if((*_Sensors[j])[k] < aux->GetMin()){
				aux->SetMin((*_Sensors[j])[k]);
			}
			if((*_Sensors[j])[k] > aux->GetMax()){
				aux->SetMax((*_Sensors[j])[k]);
			}
		}
	}

	*_Pack = *aux;
	delete aux;
}

void Red::MakeSmallQueryTree(string ID, int Start, int End){
	Package *aux;

	aux = new Package;

	// Comparo los strings para buscar el sensor que me pide
	aux->SetIdStatus(true);
	for(int i = 0; i < _Amount; i++){
		if(!(_Ids[i].compare(ID))){
			aux->SetIdStatus(false);
			break;
		}
	}
	if(aux->GetIdStatus()){		// Si el sensor no esta en la lista devuelvo el paquete con el flag apropiado
		*_Pack = *aux;
		delete aux;
		return;
	}	

	// Le pido al segmentree la respuesta para el segmento entre Start y End
	*aux = (*_Trees[i]).GetSegment(Start, End);

	*_Pack = *aux;
	delete aux;
}

void Red::MakeBigQueryTree(int Start, in End){
	Package *aux;

	// Como no tengo que buscar el sensor, directamente pido el resultado del intervalo  [Start,End)
	*aux = (*_Trees[_Amount]).GetSegment(Start, End);

	*_Pack = *aux;
	delete aux;
}

void Red::MakeComplexQueryTree(string * & ID, int SensorQuantity, int Start, int End){

}

void Red::AppendRow(Element * & Data){
	for (int i = 0; i <= _Amount; ++i){
		_Sensors[i]->Append(Data[i]);
	}
}

void ProcesTrees(void){
	_Trees = new SegmentTree*[_Amount + 1];
	for(int i = 0; i <= _Amount; ++i){
		*(_Trees[i]) = new SegmentTree(*(_Sensors[i]));
	}
}

Red::~Red(){
	delete[] _Ids;
	for (int i = 0; i <= _Amount; ++i){
		delete _Sensors[i];
	}
	delete[] _Sensors;
	delete _Pack;
}




















