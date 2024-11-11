#include "ArchivoVentas.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoVentas::ArchivoVentas()
{
    _fileName = "ventas.dat";
}

bool ArchivoVentas::agregarVenta(const Venta &venta)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&venta, sizeof(Venta), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoVentas::mostrarVenta(int idVenta)
{
    int posicion;

    posicion = buscarPorId(idVenta);

    if(posicion != -1)
    {
        Venta venta;

        venta = buscarVenta(posicion);

        venta.mostrar();
    }
    else
    {
        cout << "Venta no encontrado." << endl;
    }
}

void ArchivoVentas::modificarVenta(int idVenta, const Venta &ventaAModificar)
{
    int posicion;

    posicion = buscarPorId(idVenta);

    if(posicion != -1)
    {
        modificar(posicion, ventaAModificar);
    }
    else
    {
        cout << "Venta no encontrada." << endl;
    }
}

void ArchivoVentas::listaVentas()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    Venta* ventas;

    ventas = new Venta[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        ventas[x] = buscarVenta(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(ventas[j].getIdVenta() > ventas[j + 1].getIdVenta())
            {
                Venta temp = ventas[j];
                ventas[j] = ventas[j + 1];
                ventas[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        ventas[x].mostrar();
    }

    delete[] ventas;
}

int ArchivoVentas::buscarPorId(int idVenta)
{
    int posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Venta venta;

    while(fread(&venta, sizeof(Venta), 1, pFile) == 1)
    {
        if(venta.getIdVenta() == idVenta)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}

Venta ArchivoVentas::buscarVenta(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Venta venta;

    if(pFile == nullptr)
    {
        return venta;
    }

    fseek(pFile, sizeof(Venta) * posicion, SEEK_SET);
    fread(&venta, sizeof(Venta), 1, pFile);

    fclose(pFile);

    return venta;
}





// Metodos Privado

bool ArchivoVentas::modificar(int posicion, const Venta &venta)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Venta) * posicion, SEEK_SET);
    result = fwrite(&venta, sizeof(Venta), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoVentas::getCantidadRegistros()
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

    return total / sizeof(Venta);
}
