#pragma once
#include "Cliente.h"
#include <string>

class ArchivoClientes
{
    public:
        ArchivoClientes();

        bool agregarCliente(const Cliente &cliente);
        void mostrarCliente(int idCliente);
        void modificarCliente(int idCliente, const Cliente &clienteAModificar);
        void listaClientes();
        int buscarPorId(int idCliente);

    private:
        std::string _fileName;

        Cliente buscarCliente(int posicion);
        bool modificar(int posicion, const Cliente &cliente);
        int getCantidadRegistros();
};
