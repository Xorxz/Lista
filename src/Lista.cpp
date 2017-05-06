#include "Lista.h"

Lista::Lista()
{
	this->H = NULL;
	this->T = NULL;
}

Lista::Lista(int Dato)
{
	Nodo *aux = new  Nodo(Dato);
	this->H = aux; 
	this->T = aux;
}

bool Lista::ListaVacia()
{
	if (this->H == NULL && this->T == NULL)
		return true;
	return false;
}

void Lista::AddInicio(int Dato)
{
	Nodo *aux = new Nodo(Dato,this->H);
	if (ListaVacia())
	{		
		this->T = aux;
	}
	this->H = aux;
}

void Lista::AddFinal(int Dato)
{
	Nodo *aux = new Nodo(Dato);
	if (!ListaVacia())
	{
		this->T->setSig(aux);
		this->T = aux;
	}
	else
	{
		this->H = aux;
		this->T = aux;
	}
}

int Lista::RemoveInicio()
{
	if (!ListaVacia())
	{
		int Dato = H->getDato();
		this->H = H->getSig();
		if (H == NULL)
		{
			this->T = NULL;
		}
		return Dato;
	}
	else
	{
	std::cout<<"La lista está vacia "<<std::endl;
	return NULL;
	}
}

int Lista::RemoveFinal()
{
	if (ListaVacia())
	{
		std::cout<< "La lista está vacia " <<std::endl;
		return NULL;
	}
	else
	{
	int Dato = this->T->getDato();
	if (this->H != this->T)
	{
		Nodo *aux = this->H;
		while(aux->getSig() != this->T)
		{
			aux = aux->getSig();
		}
	
		T = aux;	
		T->setSig(NULL);	
	}
	else
	{
		H = NULL;
		T = NULL;
	}
	return Dato;
	}
}

void Lista::VaciarLista()
{
	if (ListaVacia())
	{
		std::cout<< "La lista está vacia " <<std::endl;
		
	}
	else
	{
		Nodo *aux = H;
		while(aux != NULL)
		{
			this->H = H->getSig();
			aux = aux->getSig();
		}
		
	}
}

Nodo *Lista::BuscarElemento(int Dato)
{
	if (!ListaVacia())
	{
		Nodo* aux = H;
		while(aux->getDato()!= Dato && aux!=T)
		{
			aux=aux->getSig();
		}
		if(aux->getDato() == Dato)
		{
			//std::cout<<"nodo encontrado: "<< aux->getDato()<< std::endl;
			return aux;
		}
		else
		{
			std::cout<<"elemento no encontrado"<<std::endl;
		}
	}
	else
	{
		std::cout<<"Lista vacia, elementos no encontrados"<<std::endl;	
		return NULL;
	}	
}

void Lista::AddRef(int Dato, int Ref)
{
	if (ListaVacia())
	{
		Nodo *aux = new Nodo(Dato);
		this->H = aux;
		this->T = this->H;
		std::cout << "no se encontro referencia porque la lista está vacía " << std::endl;
		return ;
	}
	else
	{
		Nodo *aux2 = BuscarElemento(Ref);
		if(BuscarElemento(Ref)->getDato() == Ref)
		{
			Nodo *aux = new Nodo(Dato,aux2->getSig());
			aux2->setSig(aux);
		}
		else
		{
			std::cout << "no se encontro referencia, no se agrega" << std::endl;
		}
	}
}

int Lista::RemoveRef(int Ref)
{
	if(ListaVacia())
	{
		std::cout<< "La lista esta vacia " <<std::endl;
	}
	else
	{
		Nodo *aux = this->H;
		int Dato;
		if(aux == BuscarElemento(Ref))
		{
			Dato = RemoveInicio();
			return Dato;
		}
		else if((aux == BuscarElemento(Ref)) && (aux == this->T))
		{
			Dato = RemoveFinal();
			return Dato;
		}
		else if(aux != BuscarElemento(Ref) && (aux == this->T))
		{
			std::cout<< "no se encuentra referencia" <<std::endl;
			return NULL;
		}
		else
		{
			int Dato = BuscarElemento(Ref)->getDato();
			while(aux->getSig() != BuscarElemento(Ref))
			{
				aux = aux->getSig();
			}		
			Nodo *aux2 = aux->getSig();
			aux->setSig(aux2->getSig());
			aux2->setSig(NULL);
			return Dato;
		}	
	}
}

void Lista::Show()
{
	Nodo* aux = this->H;
	while(aux != NULL)
	{
		std::cout<< aux->getDato() <<std::endl;
		aux = aux->getSig();
	}
}