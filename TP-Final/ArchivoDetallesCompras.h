#pragma once
#include "DetalleCompra.h"
#include "ArchivoCompras.h"
#include <string>

class ArchivoDetallesCompras
{
    public:
        ArchivoDetallesCompras();

        bool agregarDetalleCompra(const DetalleCompra &detalleCompra);
        void mostrarDetallesCompra(int idCompra);
        void listaDetallesCompras();
        int buscarPorId(int idCompra);
        bool agregarDetalleCompra(const DetalleCompra &detalleCompra, ArchivoCompras &archivoCompras);

    private:
        std::string _fileName;

        DetalleCompra buscarDetallesCompra(int posicion);
        int getCantidadRegistros();
};

