#ifndef PERSONA_CLASS_H_INCLUDED
#define PERSONA_CLASS_H_INCLUDED

#include <iostream>
#include <cstring> // Para usar funciones como strcpy y strlen
using namespace std;



class Producto {
private:
     // categoria se puede clasificar mejor con una clase categoria

public:

    int id;
    char nombre[50];
    char descripcion[100];
    float precioCompra;
    float precioVenta;
    int stock;
    int stockMin;
    int stockMax;
    char categoria[30];

    // Métodos de registro, modificación, eliminación
    void registrar() {

        //cout << "Ingrese el ID del producto: ";
        //cin >> id;

        //cin.ignore(); // Limpiar el buffer antes de leer cadenas de texto

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

    void mostrar() const {
        cout << "ID: " << id << "\nNombre: " << nombre << "\nDescripcion: " << descripcion
             << "\nPrecio Compra: " << precioCompra << "\nPrecio Venta: " << precioVenta
             << "\nStock: " << stock << "\nStock Minimo: " << stockMin << "\nStock Maximo: " << stockMax
             << "\nCategoria: " << categoria << "\n\n";
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

class ArchivoProducto{
private:

    const char* _fileName;

public:

    ArchivoProducto() { _fileName = "productos.dat"; }


    void mostrarProductos() {
        FILE* archivo = fopen(_fileName, "rb");
        if (archivo == nullptr) {
            cout << "No se pudo abrir el archivo para lectura.\n";
            return;
        }
        Producto producto;
        while (fread(&producto, sizeof(Producto), 1, archivo) == 1) {
            producto.mostrar();
        }
        fclose(archivo);
    }

    // Método para eliminar un producto del archivo
    void eliminarProducto(int idBusqueda) {
        FILE* archivo = fopen(_fileName, "rb");
        FILE* archivoTemp = fopen("temp.dat", "wb");
        if (archivo == nullptr || archivoTemp == nullptr) {
            cout << "No se pudo abrir los archivos para eliminación.\n";
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


    // Método para buscar un producto por ID
    Producto buscarProducto(int idBusqueda) {
        FILE* archivo = fopen(_fileName, "rb");
        if (archivo == nullptr) {
            cout << "No se pudo abrir el archivo para lectura.\n";
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

     // Método para registrar el producto en el archivo
    void guardarEnArchivo() {
        FILE* archivo = fopen(_fileName, "ab"); // "ab" para añadir en binario
        if (archivo == nullptr) {
            cout << "No se pudo abrir el archivo.\n";
            return;
        }
        Producto producto;
        ArchivoProducto file_prod;
        producto.registrar();
        producto.id = file_prod.getLastId();
        fwrite(&producto, sizeof(Producto), 1, archivo);
        fclose(archivo);
        cout << "Producto guardado.\n";
    }

    bool idExists(int id){
        FILE* archivo = fopen(_fileName, "rb");
        if (archivo == nullptr) {
            cout << "No se pudo abrir el archivo.\n";
            return 0;
        }

        Producto producto;
        while(fread(&producto, sizeof(Producto), 1, archivo) == 1){
            if(id == producto.id){
                fclose(archivo);
                return true;
            }
       }
       fclose(archivo);
       return false;
    }

    int getLastId(){
        FILE* archivo = fopen(_fileName, "rb");
        if (archivo == nullptr) {
            cout << "No se pudo abrir el archivo.\n";
            return 0;
        }

        Producto producto;
        int lastId = 0;

        while(fread(&producto, sizeof(Producto), 1, archivo) == 1){
            lastId = producto.id;
        };
        lastId = producto.id + 1;
        ArchivoProducto ar;
        bool exists = ar.idExists(lastId);

        while(exists){
            lastId++;
            exists = ar.idExists(lastId);
        }

        fclose(archivo);

        return lastId;
    }


};


#endif // PERSONA_CLASS_H_INCLUDED
