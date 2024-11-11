#pragma once
#include "Venta.h"
#include "DetalleVenta.h"
#include "ArchivoVentas.h"
#include <string>

class ArchivoDetallesVentas
{
    public:
        ArchivoDetallesVentas();

        bool agregarDetalleVenta(const DetalleVenta &detalleVenta);
        void mostrarDetallesVenta(int idVenta);
        void listaDetallesVentas();
        int buscarPorId(int idVenta);
        bool agregarDetalleVenta(const DetalleVenta &detalleVenta, ArchivoVentas &archivoVentas);

    private:
        std::string _fileName;

        DetalleVenta buscarDetallesVenta(int posicion);
        int getCantidadRegistros();
};
