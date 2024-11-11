#include "ArchivoCompras.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoCompras::ArchivoCompras()
{
    _fileName = "compras.dat";
}

bool ArchivoCompras::agregarCompra(const Compra &compra)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&compra, sizeof(Compra), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoCompras::mostrarCompra(int idCompra)
{
    int posicion;

    posicion = buscarPorId(idCompra);

    if(posicion != -1)
    {
        Compra compra;

        compra = buscarCompra(posicion);

        compra.mostrar();
    }
    else
    {
        cout << "Compra no encontrada." << endl;
    }
}

void ArchivoCompras::modificarCompra(int idCompra, const Compra &compraAModificar)
{
    int posicion;

    posicion = buscarPorId(idCompra);

    if(posicion != -1)
    {
        modificar(posicion, compraAModificar);
    }
    else
    {
        cout << "Compra no encontrada." << endl;
    }
}

void ArchivoCompras::listaCompras()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    Compra* compras;

    compras = new Compra[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        compras[x] = buscarCompra(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(compras[j].getIdCompra() > compras[j + 1].getIdCompra())
            {
                Compra temp = compras[j];
                compras[j] = compras[j + 1];
                compras[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        compras[x].mostrar();
    }

    delete[] compras;
}

int ArchivoCompras::buscarPorId(int idCompra)
{
    int posicion;

    posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Compra compra;

    while(fread(&compra, sizeof(Compra), 1, pFile) == 1)
    {
        if(compra.getIdCompra() == idCompra)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}

Compra ArchivoCompras::buscarCompra(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Compra compra;

    if(pFile == nullptr)
    {
        return compra;
    }

    fseek(pFile, sizeof(Compra) * posicion, SEEK_SET);
    fread(&compra, sizeof(Compra), 1, pFile);

    fclose(pFile);

    return compra;
}





// M‚todos privados

bool ArchivoCompras::modificar(int posicion, const Compra &compra)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Compra) * posicion, SEEK_SET);
    result = fwrite(&compra, sizeof(Compra), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoCompras::getCantidadRegistros()
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

    return total / sizeof(Compra);
}
