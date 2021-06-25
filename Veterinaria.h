#pragma once
#include "ReservaSimple.h" 
#include "ReservaCombo.h" 
#include "AtencionMedica.h" 
#include "AtencionPeluqueria.h" 
#include "Clientes.h"
#include "nullClientException.h"
#include "NullAtentionException.h"
#include "NullPetException.h"
class Veterinaria
{
private:

	Lista<Atencion> atenciones;
	Lista<Reserva> reservas;

public:
	Veterinaria();
	~Veterinaria();


	void registrarAtencion(Atencion* a);
	void registrarReservaSimple(int idReserva, int codigoAtencion, int ciCliente, string nombreMascota);
	void registrarReservaCombo(int idReserva, int codigoAtencion1, int codigoAtencion2, int ciCliente, string nombreMascota);

	string toString();

	bool atencionExiste(int codigoAtencion);
	bool clienteExiste(int ciCliente);
	bool mascotaExiste(int ciCliente, string nombreMascota);
};

