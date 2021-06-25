#pragma once
#include "Reserva.h"
class ReservaSimple :
    public Reserva
{
private:
    Atencion* atencion;


public:

    ReservaSimple(int id, Atencion* atencion,Cliente* cliente, Mascota* mascota );
    ~ReservaSimple();

    string toString();
};

