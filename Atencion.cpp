#include "Atencion.h"

Atencion::Atencion(int cod)
{
	this->cod = cod;

}

Atencion::Atencion(int cod, string descripcion, float costo)
{
	this->cod = cod;
	this->descripcion = descripcion;
	this->costo = costo;
}

bool Atencion::cmpCod(Atencion* a1, Atencion* a2)
{
	return a1->cod > a2->cod;
}

string Atencion::toString()
{
	stringstream ss;
	ss << ",codigo:" << cod << ",descripcion:" << descripcion << ",costo:" << costo;
	return ss.str();
}

bool Atencion::operator==(Atencion* A)
{
	return A->cod==cod;
}
