#include "Clientes.h"

Clientes::Clientes()
{
}

Clientes::~Clientes()
{
}

Clientes& Clientes::getInst()
{
	// TODO: insert return statement here
	static Clientes inst;
	return inst;
}

Lista<Cliente>& Clientes::getClientes()
{
	// TODO: insert return statement here
	return clientes;
}

void Clientes::registrar(Cliente* c)
{
	clientes.registrar(c);
}

Cliente* Clientes::buscar(int cod)
{

	Cliente* c = new Cliente(cod);
	if (clientes.buscar(c) == nullptr) throw nullClientException();
		return clientes.buscar(c);

	
	

}

string Clientes::toString()
{

	int counter = 0;
	clientes.sort2(Cliente::cmpNombre);
	stringstream ss;
		Nodo<Cliente>* aux = clientes.getFirst();
		ss << "[";
	while (aux != NULL)
	{
		ss << aux->getDato()->toString();
		aux = aux->getNext();
		counter++;
		if (counter < clientes.getLen())
		{
			ss << ",";
		}

	}
	ss << "]";
	return ss.str();
}

