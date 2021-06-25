#include "Cliente.h"


Cliente::Cliente(int ci)
{
	this->ci = ci;

}

Cliente::Cliente(int ci, string nombre, long fono)
{
	this->ci = ci;
	this->nombre = nombre;
	this->fono = fono;

}

Cliente::~Cliente()
{
}

Lista<Mascota>& Cliente::getMascotas()
{
	// TODO: insert return statement here
	return mascotas;
}

string Cliente::toString()
{
	//{ci:12347,nombre:Aldo,fono:55557,mascotas:[{
	int counter=0;
	stringstream ss;
	mascotas.sort2(Mascota::cmpNombre);
	ss << "{";
	ss << "ci:" << ci << "," << "nombre:" << nombre << "," << "fono:" << fono << "," << "mascotas:" << "[";

	Nodo<Mascota>* aux = mascotas.getFirst();
	while (aux != NULL)
	{
		ss << aux->getDato()->toString();
		aux = aux->getNext();
		counter++;
		if (counter < mascotas.getLen())
		{
			ss << ",";
		}

	}

	ss << "]";
	ss << "}";
	return ss.str();
}

string Cliente::toStringAlpha()
{
	stringstream ss;
		ss << "{ci:" << ci << ",nombre:" << nombre << ",fono:" << fono << "}";
		return ss.str();
	
}

bool Cliente::operator==(Cliente* c)
{
	return ci==c->ci;
}

bool Cliente::cmpNombre(Cliente* c1, Cliente* c2)
{
	return c1->nombre > c2->nombre;

}
