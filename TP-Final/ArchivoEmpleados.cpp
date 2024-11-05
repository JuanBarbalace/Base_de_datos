#include "ArchivoEmpleados.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoEmpleados::ArchivoEmpleados()
{
    _fileName = "empleados.dat";
}

bool ArchivoEmpleados::agregarEmpleado(const Empleado &empleado)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&empleado, sizeof(Empleado), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoEmpleados::mostrarEmpleado(int idEmpleado)
{
    int posicion;

    posicion = buscarPorId(idEmpleado);

    if(posicion != -1)
    {
        Empleado empleado;

        empleado = buscarEmpleado(posicion);

        empleado.mostrar();
    }
    else
    {
        cout << "Empleado no encontrado." << endl;
    }
}

void ArchivoEmpleados::modificarEmpleado(int idEmpleado, const Empleado &empleadoAModificar)
{
    int posicion = buscarPorId(idEmpleado);

    if(posicion != -1)
    {
        modificar(posicion, empleadoAModificar);
        cout << "Empleado modificado." << endl;
    }
    else
    {
        cout << "Empleado no encontrado." << endl;
    }
}

void ArchivoEmpleados::listaEmpleados()
{
    int cantidad = getCantidadRegistros();

    Empleado* empleados;

    empleados = new Empleado[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        empleados[x] = buscarEmpleado(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(empleados[j].getIdEmpleado() > empleados[j + 1].getIdEmpleado())
            {
                Empleado temp = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        empleados[x].mostrar();
    }

    delete[] empleados;
}

int ArchivoEmpleados::buscarPorId(int idEmpleado)
{
    int posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Empleado empleado;

    while(fread(&empleado, sizeof(Empleado), 1, pFile) == 1)
    {
        if(empleado.getIdEmpleado() == idEmpleado)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}




// Metodos Privado

Empleado ArchivoEmpleados::buscarEmpleado(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Empleado empleado;

    if(pFile == nullptr)
    {
        return empleado;
    }

    fseek(pFile, sizeof(Empleado) * posicion, SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, pFile);

    fclose(pFile);

    return empleado;
}

bool ArchivoEmpleados::modificar(int posicion, const Empleado &empleado)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Empleado) * posicion, SEEK_SET);
    result = fwrite(&empleado, sizeof(Empleado), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoEmpleados::getCantidadRegistros()
{
    int total;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);

    fclose(pFile);

    return total / sizeof(Empleado);
}
