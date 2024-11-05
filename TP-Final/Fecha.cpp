#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha()
{
    fechaDefaul();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;

    validarFecha();
}

void Fecha::fechaDefaul()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

void Fecha::validarFecha()
{
    if(!diaEsValido() || !mesEsValido() || !anioEsValido())
    {
        fechaDefaul();
    }
}

bool Fecha::diaEsValido()
{
    int diasEnMeses[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(esBisiesto() && _mes == 2)
    {
        return _dia >= 1 && _dia <= 29;
    }
    else if(_dia >= 1 && _dia <= diasEnMeses[_mes - 1])
    {
        return true;
    }

    return false;
}

bool Fecha::esBisiesto()
{
    return (_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0);
}

bool Fecha::mesEsValido()
{
    return _mes >= 1 && _mes <= 12;
}

bool Fecha::anioEsValido()
{
    return (_anio > 1000 && _anio < 2025);
}

void Fecha::cargar()
{
    do
    {
        cout << "Dia: ";
        cin >> _dia;
        cout << "Mes: ";
        cin >> _mes;
        cout << "A¤o: ";
        cin >> _anio;

        if (!diaEsValido() || !mesEsValido() || !anioEsValido())
        {
            cout << "+--------------------------------------+" << endl;
            cout << "|  Fecha invalida, intente nuevamente  |" << endl;
            cout << "+--------------------------------------+" << endl;
            system("pause");
            system("cls");
        }
    }
    while (!diaEsValido() || !mesEsValido() || !anioEsValido());
}

void Fecha::mostrar() const
{
    cout << _dia << "/" << _mes << "/" << _anio;
}
