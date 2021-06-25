#include "Reserva.h"

Reserva::Reserva(int id)
{
	this->id = id;

}

Reserva::Reserva(int id,  Cliente* cliente, Mascota* mascota)
{
this->id = id;
this->mascota = mascota;
this->cliente = cliente;

}





Reserva::~Reserva()
{
}

string Reserva::toString()
{
	stringstream ss;
	ss <<"id:" << id<<","<<"cliente:"<<cliente->toStringAlpha()<<","<<"mascota:"<<mascota->toString()<<"}";
	return ss.str();
}
