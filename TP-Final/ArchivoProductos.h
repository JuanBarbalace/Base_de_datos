#pragma once
#include "Producto.h"
#include <string>

class ArchivoProductos
{
    public:
        ArchivoProductos();

        bool agregarProducto(const Producto &producto);
        void mostrarProducto(int idProducto);
        void modificarProducto(int idProducto, const Producto &productoAModificar);
        void listaProductos();
        int buscarPorId(int idProducto);
        Producto buscarProducto(int posicion);

    private:
        std::string _fileName;

        bool modificar(int posicion, const Producto &producto);
        int getCantidadRegistros();
};
