#include "Compra.h"
#include <iostream>

using namespace std;

Compra::Compra()
{
    _idCompra = 0;
    _idProveedor = 0;
    _total = 0.0f;
    _fechaCompra = Fecha();
}

int Compra::getIdCompra() const
{
    return _idCompra;
}

int Compra::getIdProveedor() const
{
    return _idProveedor;
}

float Compra::getTotal() const
{
    return _total;
}

Fecha Compra::getFechaCompra() const
{
    return _fechaCompra;
}

void Compra::setIdCompra(const int idCompra)
{
    _idCompra = idCompra;
}

void Compra::setIdProveedor(const int idProveedor)
{
    _idProveedor = idProveedor;
}

void Compra::setTotal(const float total)
{
    _total = total;
}

void Compra::setFechaCompra(const Fecha& fechaCompra)
{
    _fechaCompra = fechaCompra;
}

void Compra::cargar(int idCompra)
{
    _idCompra = idCompra;

    cout << "Ingrese el ID Proveedor: ";
    cin >> _idProveedor;

    cout << "Ingrese el Total: ";
    cin >> _total;

    cout << "Ingrese la Fecha de Compra (dd/mm/aaaa): " << endl;
    _fechaCompra.cargar();

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Compra::mostrar()
{
    cout << "--------------------------" << endl;
    cout << "ID Compra: " << _idCompra << endl;
    cout << "ID Proveedor: " << _idProveedor << endl;
    cout << "Total: " << _total << endl;
    cout << "Fecha de Compra: ";
    _fechaCompra.mostrar();
    cout << endl;
    cout << "--------------------------" << endl;
}
