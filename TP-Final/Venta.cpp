#include "Venta.h"
#include <iostream>

using namespace std;

Venta::Venta()
{
    _idVenta = 0;
    _idCliente = 0;
    _idEmpleado = 0;
    _total = 0.0f;
    _fechaVenta = Fecha();
}

int Venta::getIdVenta() const
{
    return _idVenta;
}

int Venta::getIdCliente() const
{
    return _idCliente;
}

int Venta::getIdEmpleado() const
{
    return _idEmpleado;
}

float Venta::getTotal() const
{
    return _total;
}

Fecha Venta::getFechaVenta() const
{
    return _fechaVenta;
}

void Venta::setIdVenta(const int idVenta)
{
    _idVenta = idVenta;
}

void Venta::setIdCliente(const int IdCliente)
{
    _idCliente = IdCliente;
}

void Venta::setIdEmpleado(const int IdEmpleado)
{
    _idEmpleado = IdEmpleado;
}

void Venta::setTotal(const float total)
{
    _total = total;
}

void Venta::setFechaVenta(const Fecha& fechaVenta)
{
    _fechaVenta = fechaVenta;
}

void Venta::cargar(int idVenta)
{
    _idVenta = idVenta;

    cout << "Ingrese el ID Cliente: ";
    cin >> _idCliente;

    cout << "Ingrese el ID Empleado: ";
    cin >> _idEmpleado;

    cout << "Ingrese la Fecha de Venta (dd/mm/aaaa): " << endl;
    _fechaVenta.cargar();

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Venta::mostrar()
{
    cout << "--------------------------" << endl;
    cout << "ID Venta: " << _idVenta << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "ID Empleado: " << _idEmpleado << endl;
    cout << "Total: " << _total << endl;
    cout << "Fecha de Venta: ";
    _fechaVenta.mostrar();
    cout << endl;
    cout << "--------------------------" << endl;
}
