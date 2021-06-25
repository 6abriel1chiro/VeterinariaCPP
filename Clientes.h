#pragma once
#include "Cliente.h"
#include "Lista.h"
#include "nullClientException.h"
class Clientes
{
private:
	Lista<Cliente> clientes;


	Clientes();
public:

	
	~Clientes();
	static  Clientes&  getInst();
	Lista<Cliente>& getClientes();

	void registrar(Cliente* c);
	Cliente* buscar(int cod);
	string toString();




		
};

