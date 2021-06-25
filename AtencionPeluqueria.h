#pragma once
#include "Atencion.h"
class AtencionPeluqueria :
    public Atencion
{

private:
    int minutos;

public:

    AtencionPeluqueria(int cod, string descripcion, float costo, int minutos);
    ~AtencionPeluqueria();
    string toString();

};

