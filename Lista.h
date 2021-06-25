#pragma once
#include <sstream>
#include "Nodo.h"
#include "nullClientException.h"
template <class T>
class Lista
{
private:
	Nodo<T>* first;
	Nodo<T>* last;
	int len;

public:
	Lista();
	~Lista();

	int getLen();

	void removeFirst();

	void registrar(T* dato);

	void mostrar(void (*mostrarT)(T*));
	T* buscar(T* dato);


	bool isEmpty();

	void ordenar(bool(*sortBy)(T*, T*));
	void sort2(bool(*sortBy)(T*, T*));

	T* operator[](int i);






	void deleteNode(T* dato);
	void destroyList();
	Nodo<T>* getFirst();


};

template<class T>
inline Lista<T>::Lista()
{
	first = NULL;
	last = NULL;
	len = 0;
}

template <class T>
void Lista<T>::destroyList()
{
	Nodo<T>* temp;						//pointer to deallocate the 
									//  memory occupied by the node
	while (first != NULL)			//while there are nodes in the list
	{
		temp = first;				//set temp to the current node
		first = first->getNext();	//advance first to the next node
		delete temp;				//deallocate the memory occupied by temp
	}

	last = NULL;	//iniitialize last to NULL
					//  (first has already been set to NULL
					//		by the while loop)
	len = 0;
}

template<class T>
inline Nodo<T>* Lista<T>::getFirst()
{
	return first;
}



template<class T>
inline Lista<T>::~Lista()
{

	//destroyList();
}

template<class T>
inline int Lista<T>::getLen()
{
	return len;
}
template <class T>
bool Lista<T>::isEmpty()
{
	return (first == NULL);
}

template<class T>
inline void Lista<T>::ordenar(bool(*sortBy)(T*, T*))
{
	Nodo<T>* aux;
	Nodo<T>* nextAux;
	T* dato;

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		aux = first;
		nextAux = aux->getNext();
		while (aux->getNext() != NULL)
		{
			if ((*sortBy)(aux->getDato(), nextAux->getDato()))
			{
				sorted = false;
				dato = aux->getDato();
				aux->setDato(nextAux->getDato());
				nextAux->setDato(dato);
			}
			aux = nextAux;
			nextAux = nextAux->getNext();
		}
	}

}
template<class T>
inline void Lista<T>::sort2(bool(*sortBy)(T*, T*))
{
	Nodo<T>* aux = first;
	Nodo<T>* nextAux;
	T* dato;
	while (aux->getNext() != NULL)
	{
		nextAux = aux->getNext();
		while (nextAux != NULL)
		{
			if ((*sortBy)(aux->getDato(), nextAux->getDato()))
			{
				dato = aux->getDato();
				aux->setDato(nextAux->getDato());
				nextAux->setDato(dato);
			}
			nextAux = nextAux->getNext();
		}
		aux = aux->getNext();
	}

}

template<class T>
inline T* Lista<T>::operator[](int i)
{
	Nodo<T>* aux=first;

	for (int j = 0; j <= i; j++)
	{
		if(j==i)
		return aux->getDato();

		aux = aux->getNext();

	}
	return nullptr;


}










template<class T>
inline void Lista<T>::removeFirst()
{

	if (first == NULL)			//CASE 1; list is empty
		cout << "vacio." << endl;
	else  //CASE 2: delete first node 
	{
		this->first = this->first->getNext();
	}
}

template<class T>
inline void Lista<T>::registrar(T* dato)
{
	if (first == NULL)
		first = new Nodo<T>(dato);
	else
	{
		Nodo<T>* aux = first;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();

		}
		aux->createNext(dato);
	}
	len++;

}

template<class T>
inline void Lista<T>::mostrar(void(*mostrarT)(T*))
{

	Nodo<T>* aux = first;
	while (aux != NULL)
	{
		(*mostrarT)(aux->getDato());
		aux = aux->getNext();

	}


}


template<class T>
T* Lista<T>::buscar(T* dato)
{
	Nodo<T>* aux = first;
	while (aux != NULL)
	{
		if (*(aux->getDato()) == dato)
		{
			return aux->getDato();
		}
		aux = aux->getNext();

	}
	return nullptr;

}



template <class T>
void Lista<T>::deleteNode(T* dato)
{
	Nodo<T>* current;				//pointer to traverse the list
	Nodo<T>* trailCurrent;			//pointer just before current
	bool found;

	if (first == NULL)			//CASE 1; list is empty
		cerr << "vacio." << endl;
	else
	{							//CASE 2: delete first node 
		if (*(first->getDato()) == dato)
		{
			current = first;
			first = first->getNext();
			len--;
			if (first == NULL)   //list has only one node
				last = NULL;
			delete current;
		}
		else  //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;		//set trailCurrent to point to
										//  the first node
			current = first->getNext(); //set current to point to the 
										//  second node

			while (current != NULL && !found)
			{
				if (!(*(current->getDato()) == dato))
				{
					trailCurrent = current;
					current = current->getNext();
				}
				else
					found = true;
			} // end while

			if (found) //CASE 3; if found, delete the node
			{
				trailCurrent->createNext(current->getNext()->getDato());
				len--;

				if (last == current)			//node to be deleted was 
											//  the last node
					last = trailCurrent;	//update the value of last

				delete current;				//delete the node from the list
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}
