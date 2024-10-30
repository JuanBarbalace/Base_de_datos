
#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

class DetalleCompra {
public:
    // Constructor por defecto
    DetalleCompra();

    // Constructor parametrizado
    DetalleCompra(int idCompra, int idProducto, int idFactura, int cantidad, float precioUnitario);

    // Getters
    int getIdCompra() const;
    int getIdProducto() const;
    int getIdFactura() const;
    int getCantidad() const;
    float getPrecioUnitario() const;

    // Setters
    void setIdCompra(int id);
    void setIdProducto(int id);
    void setIdFactura(int id);
    void setCantidad(int cant);
    void setPrecioUnitario(float precio);

    // Calcula el subtotal
    float calcularSubtotal() const;

    // Representación en cadena de texto
    std::string toString() const;

private:
    int idCompra;
    int idProducto;
    int idFactura;
    int cantidad;
    float precioUnitario;
};

#endif
