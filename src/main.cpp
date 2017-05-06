#include "Lista.h"

int main()
{
	Lista l = Lista(3);
	l.ListaVacia();
	l.AddInicio(4);
	l.AddInicio(4);
	l.AddFinal(5);
	l.AddFinal(5);
	l.BuscarElemento(5);
	l.RemoveInicio();
	l.RemoveFinal();
	l.AddRef(9,4);
	l.RemoveRef(5);
	l.Show();
	l.VaciarLista();
	std::cout<< "------------------"<< std::endl;
	l.AddInicio(4);
	l.Show();	
	return 0;
}