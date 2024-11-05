#include "Proveedor.h"
#include <iostream>

using namespace std;

Proveedor::Proveedor()
{
    _idProveedor = 0;
    Persona();
}

int Proveedor::getIdProveedor() const
{
    return _idProveedor;
}

void Proveedor::setIdProveedor(const int idProveedor)
{
    _idProveedor = idProveedor;
}

void Proveedor::cargar()
{
    cout << "Ingrese el ID Proveedor: ";
    cin >> _idProveedor;
    Persona::cargar();

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Proveedor::mostrar()
{
    cout << "---------------------------------" << endl;
    cout << "ID Proveedor: " << _idProveedor << endl;
    Persona::mostrar();
    cout << "---------------------------------" << endl;
    cout << endl;
}
