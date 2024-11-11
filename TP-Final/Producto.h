#pragma once

class Producto
{
    public:
        Producto();

        int getIdProducto() const;
        const char* getNombre() const;
        const char* getCategoria() const;
        const char* getDescripcion() const;
        float getPrecioCompra() const;
        float getPrecioVenta() const;
        int getStock() const;
        int getStockMinimo() const;
        int getStockMaximo() const;

        void setIdProducto(int idProducto);
        void setNombre(const char* nombre);
        void setCategoria(const char* categoria);
        void setDescripcion(const char* descripcion);
        void setPrecioCompra(float precioCompra);
        void setPrecioVenta(float precioVenta);
        void setStock(int stock);
        void setStockMinimo(int stockMinimo);
        void setStockMaximo(int stockMaximo);

        void cargar();
        void mostrar();

    private:
        int _idProducto;
        char _nombre[30];
        char _categoria[30];
        char _descripcion[50];
        float _precioCompra;
        float _precioVenta;
        int _stock;
        int _stockMinimo;
        int _stockMaximo;
};
