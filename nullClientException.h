#pragma once
#include <iostream>
using namespace std;
class nullClientException:public exception
{

public:
	const char* what() const throw() {

		return "Cliente inexistente";
	}
};

