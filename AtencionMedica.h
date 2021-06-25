#pragma once
#include "Atencion.h"
class AtencionMedica :
    public Atencion
{
private:
    string medicamento;
public:

    AtencionMedica(int cod, string descripcion, float costo, string medicamento);
    ~AtencionMedica();
    string toString();

};

