#include "ReservaSimple.h"



ReservaSimple::ReservaSimple(int id, Atencion* atencion, Cliente* cliente, Mascota* mascota):Reserva(id,cliente,mascota)
{
	this->atencion = atencion;
}

ReservaSimple::~ReservaSimple()
{
}

string ReservaSimple::toString()
{
	stringstream ss;
	ss << "{ReservaSimple:{" << Reserva::toString()<<","<<"atencion:"<<atencion->toString()<<"}";
	return ss.str();	
}
