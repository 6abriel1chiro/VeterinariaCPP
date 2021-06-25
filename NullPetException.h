#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class NullPetException :public exception
{
private:

	string message;

public:
	NullPetException(string pet)
	{
		stringstream ss;
		ss << "Mascota " << pet << " inexistente";
		message = ss.str();
	}

	const char* what() const throw() {

		return message.c_str();
	}
};








