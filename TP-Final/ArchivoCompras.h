#pragma once
#include "Compra.h"
#include <string>

class ArchivoCompras
{
    public:
        ArchivoCompras();

        bool agregarCompra(const Compra &compra);
        void mostrarCompra(int idCompra);
        void modificarCompra(int idCompra, const Compra &compraAModificar);
        void listaCompras();
        int buscarPorId(int idCompra);
        Compra buscarCompra(int posicion);

    private:
        std::string _fileName;

        bool modificar(int posicion, const Compra &compra);
        int getCantidadRegistros();
};
