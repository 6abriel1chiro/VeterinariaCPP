#include "AtencionMedica.h"

AtencionMedica::AtencionMedica(int cod, string descripcion, float costo, string medicamento):Atencion(cod,descripcion,costo)
{
	this->medicamento = medicamento;
}

AtencionMedica::~AtencionMedica()
{
}

string AtencionMedica::toString()
{
	stringstream ss;
	ss << "{tipo:AtencionMedica" << Atencion::toString() << ",medicamentos:" << medicamento << "}";
	return ss.str();
}
