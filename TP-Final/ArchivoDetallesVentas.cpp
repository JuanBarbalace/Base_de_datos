#include "ArchivoDetallesVentas.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoDetallesVentas::ArchivoDetallesVentas()
{
    _fileName = "detallesVentas.dat";
}

bool ArchivoDetallesVentas::agregarDetalleVenta(const DetalleVenta &detalleVenta)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoDetallesVentas::mostrarDetallesVenta(int idVenta)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    DetalleVenta detalleVenta;
    int posicion = 0;
    bool estado = false;

    while(fread(&detalleVenta, sizeof(DetalleVenta), 1, pFile) == 1)
    {
        if(detalleVenta.getIdVenta() == idVenta)
        {
            detalleVenta = buscarDetallesVenta(posicion);
            detalleVenta.mostrar();
            estado = true;
        }
        posicion++;
    }

    fclose(pFile);

    if(!estado)
    {
        cout << "Detalles de venta no encontrados." << endl;
    }
}

void ArchivoDetallesVentas::listaDetallesVentas()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    DetalleVenta* detallesVentas;

    detallesVentas = new DetalleVenta[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        detallesVentas[x] = buscarDetallesVenta(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(detallesVentas[j].getIdVenta() > detallesVentas[j + 1].getIdVenta())
            {
                DetalleVenta temp = detallesVentas[j];
                detallesVentas[j] = detallesVentas[j + 1];
                detallesVentas[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        detallesVentas[x].mostrar();
    }

    delete[] detallesVentas;
}

int ArchivoDetallesVentas::buscarPorId(int idVenta)
{
    int posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    DetalleVenta detalleVenta;

    while(fread(&detalleVenta, sizeof(DetalleVenta), 1, pFile) == 1)
    {
        if(detalleVenta.getIdVenta() == idVenta)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}

bool ArchivoDetallesVentas::agregarDetalleVenta(const DetalleVenta &detalleVenta, ArchivoVentas &archivoVentas)
{
    bool result;

    int idVenta, posicion;

    Venta venta;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&detalleVenta, sizeof(DetalleVenta), 1, pFile) == 1;

    fclose(pFile);

    idVenta = detalleVenta.getIdVenta();

    posicion = archivoVentas.buscarPorId(idVenta);

    if(posicion != -1)
    {
        venta = archivoVentas.buscarVenta(posicion);
        venta.setTotal(venta.getTotal() + detalleVenta.getSubTotal());
        archivoVentas.modificarVenta(posicion, venta);
    }

    return result;
}





// Metodos Privado

DetalleVenta ArchivoDetallesVentas::buscarDetallesVenta(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    DetalleVenta detalleVenta;

    if(pFile == nullptr)
    {
        return detalleVenta;
    }

    fseek(pFile, sizeof(DetalleVenta) * posicion, SEEK_SET);
    fread(&detalleVenta, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);

    return detalleVenta;
}

int ArchivoDetallesVentas::getCantidadRegistros()
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

    return total / sizeof(DetalleVenta);
}
