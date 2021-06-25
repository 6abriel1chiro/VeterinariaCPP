#include "ReservaCombo.h"



ReservaCombo::ReservaCombo(int idReserva, Atencion* atencion1, Atencion* atencion2, Cliente* cliente, Mascota* mascota) :Reserva(idReserva, cliente, mascota)
{
	this->atencion1 = atencion1;
	this->atencion2 = atencion2;
}

ReservaCombo::~ReservaCombo()
{
}

string ReservaCombo::toString()
{
	stringstream ss;
	ss << "{ReservaCombo:{" << Reserva::toString() << "," << "atencion1:" << atencion1->toString() << "," << "atencion2:" << atencion2->toString()<<"}";
	return ss.str();
}
