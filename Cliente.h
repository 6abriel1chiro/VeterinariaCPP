#pragma once
#include"Mascota.h"
#include"Lista.h"
class Cliente
{
private:

	int ci;
	string nombre;
	long fono;

	Lista<Mascota> mascotas;
public:

	Cliente(int ci);
	Cliente(int ci,string nombre, long fono);
	~Cliente();
	Lista<Mascota>& getMascotas();
	string toString();
	string toStringAlpha();
	bool operator==(Cliente* c);
	static bool cmpNombre(Cliente* c1, Cliente* c2);





};

