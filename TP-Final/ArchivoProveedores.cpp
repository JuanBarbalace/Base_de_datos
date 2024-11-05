#include "ArchivoProveedores.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoProveedores::ArchivoProveedores()
{
    _fileName = "proveedor.dat";
}

bool ArchivoProveedores::agregarProveedor(const Proveedor &proveedor)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&proveedor, sizeof(Proveedor), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoProveedores::mostrarProveedor(int idProveedor)
{
    int posicion;

    posicion = buscarPorId(idProveedor);

    if(posicion != -1)
    {
        Proveedor proveedor;

        proveedor = buscarProveedor(posicion);

        proveedor.mostrar();
    }
    else
    {
        cout << "Proveedor no encontrado." << endl;
    }
}

void ArchivoProveedores::modificarProveedor(int idProveedor, const Proveedor &proveedorAModificar)
{
    int posicion = buscarPorId(idProveedor);

    if(posicion != -1)
    {
        modificar(posicion, proveedorAModificar);
        cout << "Proveedor modificado." << endl;
    }
    else
    {
        cout << "Proveedor no encontrado." << endl;
    }
}

void ArchivoProveedores::listaProveedores()
{
    int cantidad = getCantidadRegistros();

    Proveedor* proveedores;

    proveedores = new Proveedor[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        proveedores[x] = buscarProveedor(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(proveedores[j].getIdProveedor() > proveedores[j + 1].getIdProveedor())
            {
                Proveedor temp = proveedores[j];
                proveedores[j] = proveedores[j + 1];
                proveedores[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        proveedores[x].mostrar();
    }

    delete[] proveedores;
}

int ArchivoProveedores::buscarPorId(int idProveedor)
{
    int posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Proveedor proveedor;

    while(fread(&proveedor, sizeof(Proveedor), 1, pFile) == 1)
    {
        if(proveedor.getIdProveedor() == idProveedor)
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

Proveedor ArchivoProveedores::buscarProveedor(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Proveedor proveedor;

    if(pFile == nullptr)
    {
        return proveedor;
    }

    fseek(pFile, sizeof(Proveedor) * posicion, SEEK_SET);
    fread(&proveedor, sizeof(Proveedor), 1, pFile);

    fclose(pFile);

    return proveedor;
}

bool ArchivoProveedores::modificar(int posicion, const Proveedor &proveedor)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Proveedor) * posicion, SEEK_SET);
    result = fwrite(&proveedor, sizeof(Proveedor), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoProveedores::getCantidadRegistros()
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

    return total / sizeof(Proveedor);
}
