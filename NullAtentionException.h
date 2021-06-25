#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class NullAtentionException :public exception
{
private:
	string message;
public:
	
	NullAtentionException(int num)
	{
		stringstream ss;
		//string n = "" + num;
		ss << "Atencion "<< num <<" inexistente";
		message = ss.str();
	}
	const char* what() const throw() {

		return message.c_str();
	}
};

