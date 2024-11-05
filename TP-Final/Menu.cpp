#include "Menu.h"
#include "rlutil.h"
#include <iostream>

#include "Empleado.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "ArchivoClientes.h"
#include "ArchivoEmpleados.h"
#include "ArchivoProveedores.h"

using namespace rlutil;
using namespace std;

Menu::Menu()
{
    setColor(WHITE);
    setBackgroundColor(BLUE);

    cout << "+----------------------------------+" << endl;
    cout << "|  BIENVENIDO A LA APP DE GESTION  |" << endl;
    cout << "+----------------------------------+" << endl;
}

void Menu::menuPrincipal()
{
    int op;

    do{
        anykey();
        cls();

        cout << "+--------------------------+" << endl;
        cout << "|      MENU PRINCIPAL      |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "|1 - Area Ventas.          |" << endl;
        cout << "|2 - Area Compras.         |" << endl;
        cout << "|3 - Area Administrativa.  |" << endl;
        cout << "|4 - Area Inventario.      |" << endl;
        cout << "|0 - Salir.                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,11);
        cin >> op;

        switch(op)
        {
            case 1:
                areaVentas();
                break;
            case 2:
                areaCompras();
                break;
            case 3:
                areaAdministrativa();
                break;
            case 4:
                areaInventario();
                break;
            case 0:
                cls();
                cout << "+------------------------+" << endl;
                cout << "|  ADIOS, VUELVA PRONTO  |" << endl;
                cout << "+------------------------+" << endl;
                exit(0);
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                break;
        }
    }while(op != 0);
}

void Menu::areaVentas()
{
    int op;

    do{
        cls();

        cout << "+-------------------------------+" << endl;
        cout << "|         AREA DE VENTAS        |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << "|1 - Registrar Venta.           |" << endl;
        cout << "|2 - Mostrar Venta.             |" << endl;
        cout << "|3 - Mostrar Detalles de Venta. |" << endl;
        cout << "|4 - Mostrar Factura de Venta.  |" << endl;
        cout << "|5 - Historial Ventas.          |" << endl;
        cout << "|6 - Ganancia Mensual.          |" << endl;
        cout << "|7 - Ganancia Anual.            |" << endl;
        cout << "|0 - Atras.                     |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,14);
        cin >> op;

        switch(op)
        {
            case 1:
                // Metodos
                break;
            case 2:
                // Metodos
                break;
            case 3:
                // Metodos
                break;
            case 4:
                // Metodos
                break;
            case 5:
                // Metodos
                break;
            case 6:
                // Metodos
                break;
            case 7:
                // Metodos
                break;
            case 0:
                cls();
                cout << "+--------------------------------+" << endl;
                cout << "|  Volviendo al Menu Principal   |" << endl;
                cout << "+--------------------------------+" << endl;
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}

void Menu::areaCompras()
{
    int op;

    do{
        cls();

        cout << "+--------------------------------+" << endl;
        cout << "|         AREA DE COMPRAS        |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "|1 - Registrar Compra.           |" << endl;
        cout << "|2 - Mostrar Compra.             |" << endl;
        cout << "|3 - Mostrar Detalles de Compra. |" << endl;
        cout << "|4 - Mostrar Factura de Compra.  |" << endl;
        cout << "|5 - Historial Compras.          |" << endl;
        cout << "|6 - Gasto Mensual.              |" << endl;
        cout << "|7 - Gasto Anual.                |" << endl;
        cout << "|0 - Atras.                      |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,14);
        cin >> op;

        switch(op)
        {
            case 1:
                // Metodos
                break;
            case 2:
                // Metodos
                break;
            case 3:
                // Metodos
                break;
            case 4:
                // Metodos
                break;
            case 5:
                // Metodos
                break;
            case 6:
                // Metodos
                break;
            case 7:
                // Metodos
                break;
            case 0:
                cls();
                cout << "+--------------------------------+" << endl;
                cout << "|  Volviendo al Menu Principal   |" << endl;
                cout << "+--------------------------------+" << endl;
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}

void Menu::areaAdministrativa()
{
    int op;

    do{
        cls();

        cout << "+-------------------------+" << endl;
        cout << "|   AREA ADMINISTRATIVA   |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "|1 - Gestion Clientes.    |" << endl;
        cout << "|2 - Gestion Empleados.   |" << endl;
        cout << "|3 - Gestion Proveedores. |" << endl;
        cout << "|0 - Volver al Menu.      |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,10);
        cin >> op;

        switch(op)
        {
            case 1:
                menuClientes();
                break;
            case 2:
                menuEmpleados();
                break;
            case 3:
                menuProveedores();
                break;
            case 0:
                cls();
                cout << "+--------------------------------+" << endl;
                cout << "|  Volviendo al Menu Principal   |" << endl;
                cout << "+--------------------------------+" << endl;
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}

void Menu::areaInventario()
{
    int op;

    do{
        cls();

        cout << "+---------------------------+" << endl;
        cout << "|     AREA DE INVENTARIO    |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "|1 - Registrar Producto.    |" << endl;
        cout << "|2 - Mostrar Producto.      |" << endl;
        cout << "|3 - Modificar Producto.    |" << endl;
        cout << "|4 - Lista Productos.       |" << endl;
        cout << "|0 - Volver al Menu.        |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,11);
        cin >> op;

        switch(op)
        {
            case 1:
                // Metodos
                break;
            case 2:
                // Metodos
                break;
            case 3:
                // Metodos
                break;
            case 4:
                // Metodos
                break;
            case 0:
                cls();
                cout << "+--------------------------------+" << endl;
                cout << "|  Volviendo al Menu Principal   |" << endl;
                cout << "+--------------------------------+" << endl;
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}





// Metodos privados:

void Menu::menuClientes()
{
    int op, idCliente;

    Cliente cliente;
    ArchivoClientes archivoCliente;

    do{
        cls();

        cout << "+------------------------+" << endl;
        cout << "|  GESTION DE CLIENTES   |" << endl;
        cout << "+------------------------+" << endl;
        cout << "|1 - Registrar Cliente.  |" << endl;
        cout << "|2 - Mostrar Cliente.    |" << endl;
        cout << "|3 - Modificar Cliente.  |" << endl;
        cout << "|4 - Lista de Clientes.  |" << endl;
        cout << "|0 - Atras.              |" << endl;
        cout << "+------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,11);
        cin >> op;

        cls();

        switch(op)
        {
            case 1:
                cout << "+------------------------------------------------------+" << endl;
                cout << "|   Ingrese los datos del cliente que quiere agregar   |" << endl;
                cout << "+------------------------------------------------------+" << endl << endl;

                cliente.cargar();
                archivoCliente.agregarCliente(cliente);
                break;
            case 2:
                cout << "+----------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del cliente que desea mostrar: " << endl;
                cout << "+----------------------------------------------+" << endl;

                locate(50,2);
                cin >> idCliente;

                archivoCliente.mostrarCliente(idCliente);
                anykey();
                break;
            case 3:
                cout << "+------------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del cliente que desea modificar: " << endl;
                cout << "+------------------------------------------------+" << endl;

                locate(51,2);
                cin >> idCliente;

                if(archivoCliente.buscarPorId(idCliente) != -1)
                {
                    archivoCliente.mostrarCliente(idCliente);

                    cout << endl;

                    cout << "+------------------------------------------+" << endl;
                    cout << "|   Ingrese los nuevos datos del cliente   |" << endl;
                    cout << "+------------------------------------------+" << endl << endl;

                    cliente.cargar();
                    archivoCliente.modificarCliente(idCliente, cliente);
                }
                else
                {
                    cout << endl;
                    archivoCliente.mostrarCliente(idCliente);
                    anykey();
                }
                break;
            case 4:
                archivoCliente.listaClientes();

                anykey();
                break;
            case 0:
                cls();
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}

void Menu::menuEmpleados()
{
    int op, idEmpleado;

    Empleado empleado;
    ArchivoEmpleados archivoEmpleado;

    do{
        cls();

        cout << "+--------------------------+" << endl;
        cout << "|   GESTION DE EMPLEADOS   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "|1 - Registrar Empleado.   |" << endl;
        cout << "|2 - Mostrar Empleado.     |" << endl;
        cout << "|3 - Modificar Empleado.   |" << endl;
        cout << "|4 - Lista de Empleados.   |" << endl;
        cout << "|0 - Atras.                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,11);
        cin >> op;

        cls();

        switch(op)
        {
            case 1:
                cout << "+------------------------------------------------------+" << endl;
                cout << "|  Ingrese los datos del empleado que quiere agregar   |" << endl;
                cout << "+------------------------------------------------------+" << endl << endl;

                empleado.cargar();

                archivoEmpleado.agregarEmpleado(empleado);
                break;
            case 2:
                cout << "+-----------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del empleado que desea mostrar: " << endl;
                cout << "+-----------------------------------------------+" << endl;

                locate(50,2);
                cin >> idEmpleado;

                archivoEmpleado.mostrarEmpleado(idEmpleado);

                anykey();
                break;
            case 3:
                cout << "+-------------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del empleado que desea modificar: " << endl;
                cout << "+-------------------------------------------------+" << endl;

                locate(52,2);
                cin >> idEmpleado;

                if(archivoEmpleado.buscarPorId(idEmpleado) != -1)
                {
                    archivoEmpleado.mostrarEmpleado(idEmpleado);

                    cout << endl;

                    cout << "+-------------------------------------------+" << endl;
                    cout << "|   Ingrese los nuevos datos del empleado   |" << endl;
                    cout << "+-------------------------------------------+" << endl << endl;

                    empleado.cargar();
                    archivoEmpleado.modificarEmpleado(idEmpleado, empleado);
                }
                else
                {
                    cout << endl;
                    archivoEmpleado.mostrarEmpleado(idEmpleado);
                    anykey();
                }
                break;
            case 4:
                archivoEmpleado.listaEmpleados();

                anykey();
                break;
            case 0:
                cls();
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}

void Menu::menuProveedores()
{
    int op, idProveedor;

    Proveedor proveedor;
    ArchivoProveedores archivoProveedor;

    do{
        cls();

        cout << "+----------------------------+" << endl;
        cout << "|   GESTION DE PROVEEDORES   |" << endl;
        cout << "+----------------------------+" << endl;
        cout << "|1 - Registrar Proveedor.    |" << endl;
        cout << "|2 - Mostrar Proveedor.      |" << endl;
        cout << "|3 - Modificar Proveedor.    |" << endl;
        cout << "|4 - Lista de Proveedores.   |" << endl;
        cout << "|0 - Atras.                  |" << endl;
        cout << "+----------------------------+" << endl;
        cout << "+-----------------+" << endl;
        cout << "|Elija una opcion: " << endl;
        cout << "+-----------------+" << endl;

        locate(20,11);
        cin >> op;

        cls();

        switch(op)
        {
            case 1:
                cout << "+------------------------------------------------------+" << endl;
                cout << "|  Ingrese los datos del proveedor que quiere agregar  |" << endl;
                cout << "+------------------------------------------------------+" << endl << endl;

                proveedor.cargar();

                archivoProveedor.agregarProveedor(proveedor);
                break;
            case 2:
                cout << "+------------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del proveedor que desea mostrar: " << endl;
                cout << "+------------------------------------------------+" << endl;

                locate(50,2);
                cin >> idProveedor;

                archivoProveedor.mostrarProveedor(idProveedor);

                anykey();
                break;
            case 3:
                cout << "+--------------------------------------------------+" << endl;
                cout << "|  Ingrese el ID del proveedor que desea modificar: " << endl;
                cout << "+--------------------------------------------------+" << endl;

                locate(53,2);
                cin >> idProveedor;

                if(archivoProveedor.buscarPorId(idProveedor) != -1)
                {
                    archivoProveedor.mostrarProveedor(idProveedor);

                    cout << endl;

                    cout << "+--------------------------------------------+" << endl;
                    cout << "|   Ingrese los nuevos datos del proveedor   |" << endl;
                    cout << "+--------------------------------------------+" << endl << endl;

                    proveedor.cargar();
                    archivoProveedor.modificarProveedor(idProveedor, proveedor);
                }
                else
                {
                    cout << endl;
                    archivoProveedor.mostrarProveedor(idProveedor);
                    anykey();
                }
                break;
            case 4:
                archivoProveedor.listaProveedores();

                anykey();
                break;
            case 0:
                cls();
                break;
            default:
                cls();
                cout << "+----------------------------------------+" << endl;
                cout << "|  Opcion incorrecta, vuelva a intentar  |" << endl;
                cout << "+----------------------------------------+" << endl;
                anykey();
                break;
        }
    }while(op != 0);
}
