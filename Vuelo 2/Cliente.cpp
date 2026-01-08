#include "Cliente.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Cliente::Cliente() {
    id = 0;
    nombre = "";
    email = "";
    kilometrosAcumulados = 0.0;
}

// Constructor con parámetros
Cliente::Cliente(int id, string nombre, string email, double kilometrosAcumulados) {
    this->id = id;
    this->nombre = nombre;
    this->email = email;
    this->kilometrosAcumulados = kilometrosAcumulados;
}

// Getters
int Cliente::getId() const {
    return id;
}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getEmail() const {
    return email;
}

double Cliente::getKilometrosAcumulados() const {
    return kilometrosAcumulados;
}

// Setters
void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}

void Cliente::setEmail(string email) {
    this->email = email;
}

void Cliente::setKilometrosAcumulados(double kilometros) {
    this->kilometrosAcumulados = kilometros;
}

// Métodos específicos
void Cliente::acumularKilometros(double kilometros) {
    kilometrosAcumulados += kilometros;
    cout << "Se han acumulado " << kilometros << " kilometros. Total: " 
         << kilometrosAcumulados << " km" << endl;
}

bool Cliente::tieneDescuento() const {
    return kilometrosAcumulados >= 50000.0;
}

void Cliente::mostrarInformacion() const {
    cout << "\n=== INFORMACION DEL CLIENTE ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "Kilometros Acumulados: " << kilometrosAcumulados << " km" << endl;
    if (tieneDescuento()) {
        cout << "CLIENTE FRECUENTE: Tiene 40% de descuento" << endl;
    }
    cout << "================================\n" << endl;
}