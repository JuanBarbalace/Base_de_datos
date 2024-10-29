#ifndef PERSONA_CLASS_H_INCLUDED
#define PERSONA_CLASS_H_INCLUDED

#include <iostream>
#include <cstring> // Para usar funciones como strcpy y strlen
using namespace std;



class Producto {
private:
    int id;
    char nombre[50];
    char descripcion[100];
    float precioCompra;
    float precioVenta;
    int stock;
    int stockMin;
    int stockMax;
    char categoria[30]; // categoria se puede clasificar mejor con una clase categoria

public:
    // Constructor
    /*Producto(int id, const char* nombre, const char* descripcion, float precioCompra, float precioVenta, int stock, int stockMin, int stockMax, const char* categoria)
        : id(id), precioCompra(precioCompra), precioVenta(precioVenta), stock(stock), stockMin(stockMin), stockMax(stockMax) {
        strcpy(this->nombre, nombre);
        strcpy(this->descripcion, descripcion);
        strcpy(this->categoria, categoria);
    }*/

    // Métodos de registro, modificación, eliminación
    void registrar() {

        cout << "Ingrese el ID del producto: ";
        cin >> id;

        cin.ignore(); // Limpiar el buffer antes de leer cadenas de texto

        cout << "Ingrese el nombre del producto: ";
        cin.getline(nombre, 50);

        cout << "Ingrese la descripcion del producto: ";
        cin.getline(descripcion, 100);

        cout << "Ingrese el precio de compra: ";
        cin >> precioCompra;

        cout << "Ingrese el precio de venta: ";
        cin >> precioVenta;

        cout << "Ingrese el stock: ";
        cin >> stock;

        cout << "Ingrese el stock mínimo: ";
        cin >> stockMin;

        cout << "Ingrese el stock máximo: ";
        cin >> stockMax;

        cin.ignore(); // Limpiar el buffer de nuevo para leer la categoria

        cout << "Ingrese la categoria: ";
        cin.getline(categoria, 30);

        cout << "Producto registrado con éxito.\n";
    }

     // Método para registrar el producto en el archivo
    void guardarEnArchivo(const char* nombreArchivo) {
        FILE* archivo = fopen(nombreArchivo, "ab"); // "ab" para añadir en binario
        if (archivo == nullptr) {
            cerr << "No se pudo abrir el archivo para escritura.\n";
            return;
        }
        fwrite(this, sizeof(Producto), 1, archivo);
        fclose(archivo);
        cout << "Producto guardado en archivo.\n";
    }

    // Método para mostrar los productos guardados en el archivo
    void mostrarProductos() {
        FILE* archivo = fopen("productos.dat", "rb");
        if (archivo == nullptr) {
            cerr << "No se pudo abrir el archivo para lectura.\n";
            return;
        }

        while (fread(this, sizeof(Producto), 1, archivo) == 1) {
            this->mostrar();
        }
        fclose(archivo);
    }

    void mostrar() const {
        cout << "ID: " << id << "\nNombre: " << nombre << "\nDescripcion: " << descripcion
             << "\nPrecio Compra: " << precioCompra << "\nPrecio Venta: " << precioVenta
             << "\nStock: " << stock << "\nStock Minimo: " << stockMin << "\nStock Maximo: " << stockMax
             << "\nCategoria: " << categoria << "\n\n";
    }

    // Método para buscar un producto por ID
    static Producto buscarProducto(int idBusqueda) {
        FILE* archivo = fopen("productos.dat", "rb");
        if (archivo == nullptr) {
            cerr << "No se pudo abrir el archivo para lectura.\n";
            return Producto();
        }

        Producto producto;
        while (fread(&producto, sizeof(Producto), 1, archivo) == 1) {
            if (producto.id == idBusqueda) {
                fclose(archivo);
                cout << "Producto con ID " << idBusqueda << " encontrado.\n";
                producto.mostrar(); // se puede quitar no es necesario tenerlo
                return producto;
            }
        }
        fclose(archivo);
        cout << "Producto con ID " << idBusqueda << " no encontrado.\n";
        return Producto(); // Retorna un producto vacío si no se encuentra
    }

    // Método para modificar un producto en el archivo
    static void modificarProducto(int idBusqueda, const Producto& productoModificado) {
        FILE* archivo = fopen("productos.dat", "r+b"); // "r+b" para leer y escribir en binario
        if (archivo == nullptr) {
            cerr << "No se pudo abrir el archivo para modificación.\n";
            return;
        }
        Producto producto;
        while (fread(&producto, sizeof(Producto), 1, archivo) == 1) {
            if (producto.id == idBusqueda) {
                fseek(archivo, -sizeof(Producto), SEEK_CUR);
                fwrite(&productoModificado, sizeof(Producto), 1, archivo);
                cout << "Producto modificado con éxito.\n";
                fclose(archivo);
                return;
            }
        }
        cerr << "Producto con ID " << idBusqueda << " no encontrado.\n";
        fclose(archivo);
    }

    // Método para eliminar un producto del archivo
    static void eliminarProducto(int idBusqueda) {
        FILE* archivo = fopen("productos.dat", "rb");
        FILE* archivoTemp = fopen("temp.dat", "wb");
        if (archivo == nullptr || archivoTemp == nullptr) {
            cerr << "No se pudo abrir los archivos para eliminación.\n";
            return;
        }

        Producto producto;
        bool encontrado = false;
        while (fread(&producto, sizeof(Producto), 1, archivo) == 1) {
            if (producto.id == idBusqueda) {
                encontrado = true;
            } else {
                fwrite(&producto, sizeof(Producto), 1, archivoTemp);
            }
        }
        fclose(archivo);
        fclose(archivoTemp);

        remove("productos.dat");
        rename("temp.dat", "productos.dat");

        if (encontrado) {
            cout << "Producto eliminado con éxito.\n";
        } else {
            cout << "Producto con ID " << idBusqueda << " no encontrado.\n";
        }
    }

    void modificar(const char* nuevoNombre, const char* nuevaDescripcion, float nuevoPrecioCompra, float nuevoPrecioVenta, int nuevoStock, int nuevoStockMin, int nuevoStockMax, const char* nuevaCategoria) {
        strcpy(this->nombre, nuevoNombre);
        strcpy(this->descripcion, nuevaDescripcion);
        precioCompra = nuevoPrecioCompra;
        precioVenta = nuevoPrecioVenta;
        stock = nuevoStock;
        stockMin = nuevoStockMin;
        stockMax = nuevoStockMax;
        strcpy(this->categoria, nuevaCategoria);
        cout << "Producto modificado con éxito.\n";
    }

    // Métodos de stock
    int consultarStock() const {
        return stock;
    }

    void actualizarStock(int nuevoStock) {
        stock = nuevoStock;
        cout << "Stock actualizado a " << stock << ".\n";
    }

    // Getters y Setters
    int getIdProducto() const { return id; }
    void setIdProducto(int nuevoId) { id = nuevoId; }

    const char* getNombre() const { return nombre; }
    void setNombre(const char* nuevoNombre) { strcpy(nombre, nuevoNombre); }

    const char* getDescripcion() const { return descripcion; }
    void setDescripcion(const char* nuevaDescripcion) { strcpy(descripcion, nuevaDescripcion); }

    float getPrecioCompra() const { return precioCompra; }
    void setPrecioCompra(float nuevoPrecioCompra) { precioCompra = nuevoPrecioCompra; }

    float getPrecioVenta() const { return precioVenta; }
    void setPrecioVenta(float nuevoPrecioVenta) { precioVenta = nuevoPrecioVenta; }

    int getStock() const { return stock; }
    void setStock(int nuevoStock) { stock = nuevoStock; }

    int getStockMin() const { return stockMin; }
    void setStockMin(int nuevoStockMin) { stockMin = nuevoStockMin; }

    int getStockMax() const { return stockMax; }
    void setStockMax(int nuevoStockMax) { stockMax = nuevoStockMax; }

    const char* getCategoria() const { return categoria; }
    void setCategoria(const char* nuevaCategoria) { strcpy(categoria, nuevaCategoria); }
};




#endif // PERSONA_CLASS_H_INCLUDED
