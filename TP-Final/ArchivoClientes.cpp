#include "ArchivoClientes.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoClientes::ArchivoClientes()
{
    _fileName = "clientes.dat";
}

bool ArchivoClientes::agregarCliente(const Cliente &cliente)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&cliente, sizeof(Cliente), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

void ArchivoClientes::mostrarCliente(int idCliente)
{
    int posicion;

    posicion = buscarPorId(idCliente);

    if(posicion != -1)
    {
        Cliente cliente;

        cliente = buscarCliente(posicion);

        cliente.mostrar();
    }
    else
    {
        cout << "Cliente no encontrado." << endl;
    }
}

void ArchivoClientes::modificarCliente(int idCliente, const Cliente &clienteAModificar)
{
    int posicion;

    posicion = buscarPorId(idCliente);

    if(posicion != -1)
    {
        modificar(posicion, clienteAModificar);
        cout << "Cliente modificado." << endl;
    }
    else
    {
        cout << "Cliente no encontrado." << endl;
    }
}

void ArchivoClientes::listaClientes()
{
    int cantidad;

    cantidad = getCantidadRegistros();

    Cliente* clientes;

    clientes = new Cliente[cantidad];

    for(int x = 0; x < cantidad; x++)
    {
        clientes[x] = buscarCliente(x);
    }

    for(int i = 0; i < cantidad - 1; i++)
    {
        for(int j = 0; j < cantidad - i - 1; j++)
        {
            if(clientes[j].getIdCliente() > clientes[j + 1].getIdCliente())
            {
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidad; x++)
    {
        clientes[x].mostrar();
    }

    delete[] clientes;
}

int ArchivoClientes::buscarPorId(int idCliente)
{
    int posicion;

    posicion = 0;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    Cliente cliente;

    while(fread(&cliente, sizeof(Cliente), 1, pFile) == 1)
    {
        if(cliente.getIdCliente() == idCliente)
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

Cliente ArchivoClientes::buscarCliente(int posicion)
{
    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb");

    Cliente cliente;

    if(pFile == nullptr)
    {
        return cliente;
    }

    fseek(pFile, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return cliente;
}

bool ArchivoClientes::modificar(int posicion, const Cliente &cliente)
{
    bool result;

    FILE *pFile;
    pFile = fopen(_fileName.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, sizeof(Cliente) * posicion, SEEK_SET);
    result = fwrite(&cliente, sizeof(Cliente), 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoClientes::getCantidadRegistros()
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

    return total / sizeof(Cliente);
}
