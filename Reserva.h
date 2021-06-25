#pragma once
#include"Atencion.h"

class Reserva
{
protected:

	int id;
	Mascota* mascota;
	Cliente* cliente;

	

	//Las atenciones se reservan de dos maneras :
	//• Simple, en la cual se debe registrar : identificador, atención, cliente y mascota.
	//• Combo, en el cual se deben registrar : identificador, la primera atención, la segunda atención, cliente y mascota




public:
	Reserva(int id);
	Reserva(int id, Cliente* cliente, Mascota* mascota);

	~Reserva();
	virtual string toString();



};

