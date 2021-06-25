#include "Mascota.h"



Mascota::Mascota(string nombre)
{
	this->nombre = nombre;

}

Mascota::Mascota(string nombre, int edad)
{
	this->nombre = nombre;
	this->edad = edad;
}

Mascota::~Mascota()
{
}

bool Mascota::operator==(Mascota* m)
{
	return nombre == m->nombre;
}

bool Mascota::cmpNombre(Mascota* m1, Mascota* m2)
{
	return m1->nombre > m2->nombre;
}

bool Mascota::cmpEdad(Mascota* m1, Mascota* m2)
{
	return m1->edad > m2->edad;
}

string Mascota::toString()
{
	//{nombre:Spike,edad:5}
	stringstream ss;

	ss << "{nombre:" << nombre << "," << "edad:" << edad << "}";
	return ss.str();
}
