#pragma once
#include "Cliente.h"
class Atencion
{
protected:

	int cod;
	string descripcion;
	int costo;
public:
	Atencion(int  cod);
	Atencion(int cod, string descripcion, float costo);
	static bool cmpCod(Atencion* a1, Atencion* a2);
	virtual string toString();

	bool operator==(Atencion* A);








};

