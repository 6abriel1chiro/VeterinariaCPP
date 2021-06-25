#pragma once
#include"Atencion.h"

class Reserva
{
protected:

	int id;
	Mascota* mascota;
	Cliente* cliente;

	

	//Las atenciones se reservan de dos maneras :
	//� Simple, en la cual se debe registrar : identificador, atenci�n, cliente y mascota.
	//� Combo, en el cual se deben registrar : identificador, la primera atenci�n, la segunda atenci�n, cliente y mascota




public:
	Reserva(int id);
	Reserva(int id, Cliente* cliente, Mascota* mascota);

	~Reserva();
	virtual string toString();



};

