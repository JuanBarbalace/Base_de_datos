#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente()
{
    _idCliente = 0;
    Persona();
}

int Cliente::getIdCliente() const
{
    return _idCliente;
}

void Cliente::setIdCliente(const int idCliente)
{
    _idCliente = idCliente;
}

void Cliente::cargar()
{
    cout << "Ingrese el ID Cliente: ";
    cin.ignore();
    cin >> _idCliente;
    Persona::cargar();

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Cliente::mostrar()
{
    cout << "---------------------------------" << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    Persona::mostrar();
    cout << "---------------------------------" << endl;
    cout << endl;
}
