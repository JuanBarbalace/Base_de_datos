#include "Persona.h"
#include <iostream>
#include "cstring"

using namespace std;

Persona::Persona()
{
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_nroDoc, "");
    strcpy(_direccion, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _fechaNac = Fecha();
}

const char* Persona::getNombre() const
{
    return _nombre;
}

const char* Persona::getApellido() const
{
    return _apellido;
}

const char* Persona::getNroDoc() const
{
    return _nroDoc;
}

const char* Persona::getDireccion() const
{
    return _direccion;
}

const char* Persona::getTelefono() const
{
    return _telefono;
}

const char* Persona::getEmail() const
{
    return _email;
}

Fecha Persona::getFechaNac() const
{
    return _fechaNac;
}

void Persona::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}

void Persona::setNroDoc(const char* nroDoc)
{
    strcpy(_nroDoc, nroDoc);
}

void Persona::setDireccion(const char* direccion)
{
    strcpy(_direccion, direccion);
}

void Persona::setTelefono(const char* telefono)
{
    strcpy(_telefono, telefono);
}

void Persona::setEmail(const char* email)
{
    strcpy(_email, email);
}

void Persona::setFechaNac(const Fecha& fechaNac)
{
    _fechaNac = fechaNac;
}

void Persona::cargar()
{
    cout << "Ingrese el Nombre: ";
    cin.ignore();
    cin.getline(_nombre, sizeof(_nombre));

    cout << "Ingrese el Apellido: ";
    cin.getline(_apellido, sizeof(_apellido));

    cout << "Ingrese el Numero de Documento: ";
    cin.getline(_nroDoc, sizeof(_nroDoc));

    cout << "Ingrese la Direcci¢n: ";
    cin.getline(_direccion, sizeof(_direccion));

    cout << "Ingrese el Tel‚fono: ";
    cin.getline(_telefono, sizeof(_telefono));

    cout << "Ingrese el Email: ";
    cin.getline(_email, sizeof(_email));

    cout << "Ingrese la Fecha de Nacimiento (dd/mm/aaaa): " << endl;
    _fechaNac.cargar();
}

void Persona::mostrar()
{
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Numero Documento: " << _nroDoc << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Fecha de Nacimiento: ";
    _fechaNac.mostrar();
    cout << endl;
}
