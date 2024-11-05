#include "Empleado.h"
#include <iostream>

using namespace std;

Empleado::Empleado()
{
    _idEmpleado = 0;
    Persona();
}

int Empleado::getIdEmpleado() const
{
    return _idEmpleado;
}

Fecha Empleado::getFechaContratacion() const
{
    return _fechaContratacion;
}

void Empleado::setIdEmpleado(const int idEmpleado)
{
    _idEmpleado = idEmpleado;
}

void Empleado::setFechaContratacion(const Fecha& fechaContratacion)
{
    _fechaContratacion = fechaContratacion;
}

void Empleado::cargar()
{
    cout << "Ingrese el ID Empleado: ";
    cin >> _idEmpleado;
    Persona::cargar();
    cout << "Ingrese la Fecha de Contratacion (dd/mm/aaaa): " << endl;
    _fechaContratacion.cargar();

    system("cls");
    cout << "+--------------------------------+" << endl;
    cout << "|  Datos cargados correctamente  |" << endl;
    cout << "+--------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Empleado::mostrar()
{
    cout << "---------------------------------" << endl;
    cout << "ID Empleado: " << _idEmpleado << endl;
    Persona::mostrar();
    cout << "Fecha de Contratacion: ";
    _fechaContratacion.mostrar();
    cout << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
}
