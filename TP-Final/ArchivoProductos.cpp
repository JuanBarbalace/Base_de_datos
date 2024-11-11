#include "ArchivoProductos.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoProductos::ArchivoProductos()
{
    _fileName = "productos.dat";
}

bool ArchivoProductos::agregarProducto(const Producto &producto)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&producto, sizeof(Producto), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoProductos::mostrarProducto(int idProducto)
{
    int posicion;

    posicion = buscarPorId(idProducto);

    if(posicion != -1)
    {
        Producto producto;

        producto = buscarProducto(posicion);

        producto.mostrar();
    }
    else
    {
        cout << "Producto no encontrado." << endl;
    }
}

void ArchivoProductos::modificarProducto(int idProducto, const Producto &productoAModificar)
{
    int posicion;

    posicion = buscarPorId(idProducto);

    if(posicion != -1)
    {
        modificar(posicion, productoAModificar);
        cout << "Producto modificado." << endl;
    }
    else
    {
        cout << "Producto no encontrado." << endl;
    }
}

void ArchivoProductos::listaProductos()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    Producto* productos;

    productos = new Producto[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        productos[x] = buscarProducto(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(productos[j].getIdProducto() > productos[j + 1].getIdProducto())
            {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        productos[x].mostrar();
    }

    delete[] productos;
}

int ArchivoProductos::buscarPorId(int idProducto)
{
    int posicion;

    posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Producto producto;

    while(fread(&producto, sizeof(Producto), 1, pFile) == 1)
    {
        if(producto.getIdProducto() == idProducto)
        {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);

    return -1;
}

Producto ArchivoProductos::buscarProducto(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Producto producto;

    if(pFile == nullptr)
    {
        return producto;
    }

    fseek(pFile, sizeof(Producto) * posicion, SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);

    fclose(pFile);

    return producto;
}





// M‚todos privados

bool ArchivoProductos::modificar(int posicion, const Producto &producto)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Producto) * posicion, SEEK_SET);
    result = fwrite(&producto, sizeof(Producto), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoProductos::getCantidadRegistros()
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

    return total / sizeof(Producto);
}
