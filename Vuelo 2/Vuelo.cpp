#include "Vuelo.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Vuelo::Vuelo() {
    numeroVuelo = 0;
    origen = "";
    destino = "";
    fecha = "";
    duracion = 0;
    precio = 0.0;
    asientosDisponibles = 0;
    distanciaKm = 0.0;
}

// Constructor con parámetros
Vuelo::Vuelo(int numeroVuelo, string origen, string destino, string fecha,
             int duracion, double precio, int asientosDisponibles, double distanciaKm) {
    this->numeroVuelo = numeroVuelo;
    this->origen = origen;
    this->destino = destino;
    this->fecha = fecha;
    this->duracion = duracion;
    this->precio = precio;
    this->asientosDisponibles = asientosDisponibles;
    this->distanciaKm = distanciaKm;
}

// Getters
int Vuelo::getNumeroVuelo() const {
    return numeroVuelo;
}

string Vuelo::getOrigen() const {
    return origen;
}

string Vuelo::getDestino() const {
    return destino;
}

string Vuelo::getFecha() const {
    return fecha;
}

int Vuelo::getDuracion() const {
    return duracion;
}

double Vuelo::getPrecio() const {
    return precio;
}

int Vuelo::getAsientosDisponibles() const {
    return asientosDisponibles;
}

double Vuelo::getDistanciaKm() const {
    return distanciaKm;
}

// Setters
void Vuelo::setNumeroVuelo(int numeroVuelo) {
    this->numeroVuelo = numeroVuelo;
}

void Vuelo::setOrigen(string origen) {
    this->origen = origen;
}

void Vuelo::setDestino(string destino) {
    this->destino = destino;
}

void Vuelo::setFecha(string fecha) {
    this->fecha = fecha;
}

void Vuelo::setDuracion(int duracion) {
    this->duracion = duracion;
}

void Vuelo::setPrecio(double precio) {
    this->precio = precio;
}

void Vuelo::setAsientosDisponibles(int asientos) {
    this->asientosDisponibles = asientos;
}

void Vuelo::setDistanciaKm(double distancia) {
    this->distanciaKm = distancia;
}

// Métodos específicos
double Vuelo::agregarPrecio() const {
    return precio;
}

bool Vuelo::hayAsientosDisponibles() const {
    return asientosDisponibles > 0;
}

void Vuelo::reservarAsiento() {
    if (hayAsientosDisponibles()) {
        asientosDisponibles--;
        cout << "Asiento reservado exitosamente. Asientos restantes: " 
             << asientosDisponibles << endl;
    } else {
        cout << "No hay asientos disponibles para este vuelo." << endl;
    }
}

void Vuelo::mostrarInformacion() const {
    cout << "\n--- Vuelo #" << numeroVuelo << " ---" << endl;
    cout << "Origen: " << origen << " -> Destino: " << destino << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Duracion: " << duracion << " horas" << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Distancia: " << distanciaKm << " km" << endl;
    cout << "Asientos disponibles: " << asientosDisponibles << endl;
    cout << "------------------------\n" << endl;
}