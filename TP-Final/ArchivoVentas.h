#pragma once
#include "Venta.h"
#include <string>

class ArchivoVentas
{
    public:
        ArchivoVentas();

        bool agregarVenta(const Venta &venta);
        void mostrarVenta(int idVenta);
        void modificarVenta(int idVenta, const Venta &ventaAModificar);
        void listaVentas();
        int buscarPorId(int idVenta);
        Venta buscarVenta(int posicion);

    private:
        std::string _fileName;

        bool modificar(int posicion, const Venta &venta);
        int getCantidadRegistros();
};
