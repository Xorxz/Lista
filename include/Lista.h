#include "Nodo.h" 

class Lista
{
public:
	Nodo *H;
	Nodo *T;
	Lista();
	Lista(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	int RemoveInicio();
	int RemoveFinal();
	void VaciarLista();
	Nodo *BuscarElemento(int Dato);
	void AddRef(int Dato,int Ref);
	int RemoveRef(int Ref);
	void Show();
};