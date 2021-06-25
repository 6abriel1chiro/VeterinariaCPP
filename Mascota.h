#pragma once
#include <iostream>
#include<sstream>
using namespace std;

class Mascota
{
private:
	string nombre;
	int edad;

public:
	Mascota(string nombre);
	Mascota(string nombre, int edad);
	~Mascota();

	bool operator==(Mascota* m);
	static bool cmpNombre(Mascota* m1, Mascota* m2);
	static bool cmpEdad(Mascota* m1, Mascota* m2);
	string toString();



};

