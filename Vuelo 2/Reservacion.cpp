#include "Reservacion.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Reservacion::Reservacion() {
    idReservacion = 0;
    idCliente = 0;
    numeroVuelo = 0;
    precioFinal = 0.0;
    destinoVuelo = "";
    descuentoAplicado = false;
}

// Constructor con parámetros
Reservacion::Reservacion(int idReservacion, int idCliente, int numeroVuelo,
                         double precioFinal, string destinoVuelo, bool descuentoAplicado) {
    this->idReservacion = idReservacion;
    this->idCliente = idCliente;
    this->numeroVuelo = numeroVuelo;
    this->precioFinal = precioFinal;
    this->destinoVuelo = destinoVuelo;
    this->descuentoAplicado = descuentoAplicado;
}

// Getters
int Reservacion::getIdReservacion() const {
    return idReservacion;
}

int Reservacion::getIdCliente() const {
    return idCliente;
}

int Reservacion::getNumeroVuelo() const {
    return numeroVuelo;
}

double Reservacion::getPrecioFinal() const {
    return precioFinal;
}

string Reservacion::getDestinoVuelo() const {
    return destinoVuelo;
}

bool Reservacion::getDescuentoAplicado() const {
    return descuentoAplicado;
}

// Setters
void Reservacion::setIdReservacion(int id) {
    this->idReservacion = id;
}

void Reservacion::setIdCliente(int idCliente) {
    this->idCliente = idCliente;
}

void Reservacion::setNumeroVuelo(int numeroVuelo) {
    this->numeroVuelo = numeroVuelo;
}

void Reservacion::setPrecioFinal(double precio) {
    this->precioFinal = precio;
}

void Reservacion::setDestinoVuelo(string destino) {
    this->destinoVuelo = destino;
}

void Reservacion::setDescuentoAplicado(bool descuento) {
    this->descuentoAplicado = descuento;
}

// Métodos específicos
void Reservacion::mostrarInformacion() const {
    cout << "\n=== RESERVACION #" << idReservacion << " ===" << endl;
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Numero de Vuelo: " << numeroVuelo << endl;
    cout << "Destino: " << destinoVuelo << endl;
    cout << "Precio Final: $" << precioFinal << endl;
    if (descuentoAplicado) {
        cout << "*** DESCUENTO DE 40% APLICADO ***" << endl;
    }
    cout << "================================\n" << endl;
}

void Reservacion::cancelarReservacion() {
    cout << "\nReservacion #" << idReservacion << " ha sido cancelada." << endl;
    cout << "Se ha procesado el reembolso de $" << precioFinal << endl;
}

string Reservacion::iniciarSesion() {
    return "Sesion iniciada para cliente con ID: " + to_string(idCliente);
}