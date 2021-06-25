#include "AtencionPeluqueria.h"

AtencionPeluqueria::AtencionPeluqueria(int cod, string descripcion, float costo, int minutos):Atencion(cod, descripcion, costo)
{
	this->minutos = minutos;
}

AtencionPeluqueria::~AtencionPeluqueria()
{
}

string AtencionPeluqueria::toString()
{
	stringstream ss;
	ss << "{tipo:AtencionPeluqueria" << Atencion::toString() << ",duracion:" << minutos<< "}";
	return ss.str();
}
