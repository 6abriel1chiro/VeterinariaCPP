#include <iostream>
using namespace std;
#pragma once
template<class T>
class ArrayGenerico
{
private:

	T** datos;
	int index;
	int cant;


public:
	ArrayGenerico(int cant);
	~ArrayGenerico();
	void registrar(T* dato);

	T* buscar(T* dato);
	T* operator[](int i);
	void ordenar(bool (*tComparacion)(T*, T*));
	void mostrar(void (*mostrarT)(T*));


	void quitar(T* dato);





};

template<class T>
ArrayGenerico<T>::ArrayGenerico(int cant)
{
	this->cant = cant;
	index = 0;
	datos = new T * [cant];

}
template<class T>
ArrayGenerico<T>::~ArrayGenerico()
{
	for (int i = 0; i < index; i++)
	{
		delete datos[i];
	}
	delete[]datos;

}


template<class T>
void ArrayGenerico<T>::registrar(T* dato)
{
	if (index < cant)
	{
		datos[index] = dato;
		index++;
	}

}

//mostrar  (punntero a una funcion)
template<class T>
void ArrayGenerico<T>::mostrar(void (*mostrarT)(T*))
{
	for (int i = 0; i < index; i++)
	{
		(*mostrarT)(datos[i]);
	}

}


template<class T>
inline void ArrayGenerico<T>::quitar(T* dato)
{
	T* aux;

	// Search x in array 
	int i;
	for (i = 0; i < index; i++)
		if (*datos[i] == dato) {
			datos[i] = NULL;
			break;
		}

	// If x found in array 
	if (i < index)
	{
		// reduce size of array and move all 
		// elements on space ahead 
		index--;
		for (int j = i; j < index; j++)
			datos[j] = datos[j + 1];
	}
}


template<class T>
T* ArrayGenerico<T>::buscar(T* dato)
{
	for (int i = 0; i < index; i++)
	{
		if (*datos[i] == dato)
			return datos[i];
	}
	return nullptr;
}


template<class T>
T* ArrayGenerico<T>::operator[](int i)
{

	return datos[i];

}
//inline mejorar performance

template<class T>
inline void ArrayGenerico<T>::ordenar(bool(*tComparacion)(T*, T*))
{
	for (int i = 0; i < index; i++)
	{
		for (int j = i + 1; j < index; j++)
		{
			if ((*tComparacion)(datos[i], datos[j]))
				swap(datos[i], datos[j]);
		}

	}

}


