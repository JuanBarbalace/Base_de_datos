#pragma once
#include "ArchivoProductos.h"
#include "Producto.h"

class DetalleVenta
{
    public:
        DetalleVenta();

        int getIdVenta() const;
        int getIdProducto() const;
        int getIdFactura() const;
        int getCantidad() const;
        float getPrecioUnit() const;
        float getSubTotal() const;

        void setIdVenta(int idVenta);
        void setIdProducto(int idProducto);
        void setIdFactura(int idFactura);
        void setCantidad(int cantidad);
        void setPrecioUnit(float precioUnit);

        void cargar(int idVenta, int idProducto, ArchivoProductos& archivoProductos);
        void mostrar();

    private:
        int _idVenta;
        int _idProducto;
        int _idFactura;
        int _cantidad;
        float _precioUnit;
};
