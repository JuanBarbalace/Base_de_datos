#include "ArchivoDetallesCompras.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoDetallesCompras::ArchivoDetallesCompras()
{
    _fileName = "detallesCompras.dat";
}

bool ArchivoDetallesCompras::agregarDetalleCompra(const DetalleCompra &detalleCompra)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoDetallesCompras::mostrarDetallesCompra(int idCompra)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    DetalleCompra detalleCompra;
    int posicion = 0;
    bool estado = false;

    while (fread(&detalleCompra, sizeof(DetalleCompra), 1, pFile) == 1)
    {
        if (detalleCompra.getIdCompra() == idCompra)
        {
            detalleCompra = buscarDetallesCompra(posicion);
            detalleCompra.mostrar();
            estado = true;
        }
        posicion++;
    }

    fclose(pFile);

    if (!estado)
    {
        cout << "Detalles de compra no encontrados." << endl;
    }
}

void ArchivoDetallesCompras::listaDetallesCompras()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    DetalleCompra* detallesCompras;

    detallesCompras = new DetalleCompra[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        detallesCompras[x] = buscarDetallesCompra(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(detallesCompras[j].getIdCompra() > detallesCompras[j + 1].getIdCompra())
            {
                DetalleCompra temp = detallesCompras[j];
                detallesCompras[j] = detallesCompras[j + 1];
                detallesCompras[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        detallesCompras[x].mostrar();
    }

    delete[] detallesCompras;
}

int ArchivoDetallesCompras::buscarPorId(int idCompra)
{
    int posicion;

    posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    DetalleCompra detalleCompra;

    while(fread(&detalleCompra, sizeof(DetalleCompra), 1, pFile) == 1)
    {
        if(detalleCompra.getIdCompra() == idCompra)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}

bool ArchivoDetallesCompras::agregarDetalleCompra(const DetalleCompra &detalleCompra, ArchivoCompras &archivoCompras)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if (pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&detalleCompra, sizeof(DetalleCompra), 1, pFile) == 1;

    fclose(pFile);

    int idCompra;

    idCompra = detalleCompra.getIdCompra();

    int posicion = archivoCompras.buscarPorId(idCompra);

    if (posicion != -1)
    {
        Compra compra;
        compra = archivoCompras.buscarCompra(posicion);
        compra.setTotal(compra.getTotal() + detalleCompra.getSubTotal());
        archivoCompras.modificarCompra(posicion, compra);
    }

    return result;
}






// M‚todos privados

DetalleCompra ArchivoDetallesCompras::buscarDetallesCompra(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    DetalleCompra detalleCompra;

    if(pFile == nullptr)
    {
        return detalleCompra;
    }

    fseek(pFile, sizeof(DetalleCompra) * posicion, SEEK_SET);
    fread(&detalleCompra, sizeof(DetalleCompra), 1, pFile);

    fclose(pFile);

    return detalleCompra;
}

int ArchivoDetallesCompras::getCantidadRegistros()
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

    return total / sizeof(DetalleCompra);
}
