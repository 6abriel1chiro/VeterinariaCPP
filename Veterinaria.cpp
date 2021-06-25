#include "Veterinaria.h"

Veterinaria::Veterinaria()
{
}

Veterinaria::~Veterinaria()
{
}

void Veterinaria::registrarAtencion(Atencion* a)
{
	atenciones.registrar(a);
}

void Veterinaria::registrarReservaSimple(int idReserva, int codigoAtencion, int ciCliente, string nombreMascota)
{


	string str = "" + codigoAtencion;




	if (!atencionExiste(codigoAtencion))	throw NullAtentionException(codigoAtencion);//throw string("Atencion" + str + "inexistente");
	if (!clienteExiste(ciCliente))	throw nullClientException();
	if (!mascotaExiste(ciCliente, nombreMascota)) throw NullPetException(nombreMascota); //throw string("Mascota" + nombreMascota + "inexistente");
		reservas.registrar(
							new ReservaSimple(idReserva,
							atenciones.buscar(new Atencion(codigoAtencion)),
							Clientes::getInst().buscar(ciCliente),
							Clientes::getInst().buscar(ciCliente)->getMascotas().buscar(new Mascota(nombreMascota)
							)
						)
					);

	

}
	

	


void Veterinaria::registrarReservaCombo(int idReserva, int codigoAtencion1,int codigoAtencion2, int ciCliente, string nombreMascota)
{

	//buscar en lista
	
	if (atencionExiste(codigoAtencion1) && atencionExiste(codigoAtencion2) && clienteExiste(ciCliente) && mascotaExiste(ciCliente, nombreMascota))
	{
		reservas.registrar(new ReservaCombo(idReserva, atenciones.buscar(new Atencion(codigoAtencion1)), atenciones.buscar(new Atencion(codigoAtencion2)), Clientes::getInst().buscar(ciCliente), Clientes::getInst().buscar(ciCliente)->getMascotas().buscar(new Mascota(nombreMascota))));
	}
	
}

string Veterinaria::toString()
{
	Nodo<Atencion>* auxA = atenciones.getFirst();
	Nodo<Reserva>* auxR = reservas.getFirst();
	int counter = 0;
	atenciones.sort2(Atencion::cmpCod);
	stringstream ss;


	ss << "{atenciones:[";
	while (auxA != NULL)
	{
		ss << auxA->getDato()->toString();
		auxA = auxA->getNext();
		counter++;
		if (counter < atenciones.getLen())
		{
			ss << ",";
		}

	}
	ss << "]";
	ss << ",reservas:[";
	counter = 0;
	while (auxR != NULL)
	{
		ss << auxR->getDato()->toString();
		auxR = auxR->getNext();
		counter++;
		if (counter < reservas.getLen())
		{
			ss << ",";
		}

	}
	ss << "]}";


	return ss.str();
}

bool Veterinaria::atencionExiste(int codigoAtencion)
{
	
	Atencion* a = atenciones.buscar(new Atencion(codigoAtencion));
	return a!= NULL;


}

bool Veterinaria::clienteExiste(int ciCliente)
{
	
	Cliente* c = Clientes::getInst().buscar(ciCliente);
	return c != NULL;


	

}

bool Veterinaria::mascotaExiste(int ciCliente,string nombreMascota)
{
	
	Mascota* m = Clientes::getInst().buscar(ciCliente)->getMascotas().buscar(new Mascota(nombreMascota));
	return m != NULL;

	
}
