#pragma once
#include "Proveedor.h"
#include <string>

class ArchivoProveedores
{
    public:
        ArchivoProveedores();

        bool agregarProveedor(const Proveedor &proveedor);
        void mostrarProveedor(int idProveedor);
        void modificarProveedor(int idProveedor, const Proveedor &proveedorAModificar);
        void listaProveedores();
        int buscarPorId(int idProveedor);

    private:
        std::string _fileName;

        Proveedor buscarProveedor(int posicion);
        bool modificar(int posicion, const Proveedor &proveedor);
        int getCantidadRegistros();
};
