#ifndef SISTEMA_H
#define SISTEMA_H

#include "Cliente.h"
#include "Vuelo.h"
#include "Reservacion.h"
#include <string>
using namespace std;

class Sistema {
private:
    Cliente clientes[10];
    Vuelo vuelos[10];
    Reservacion reservaciones[10];
    int numClientes;
    int numVuelos;
    int numReservaciones;

public:
    // Constructor
    Sistema();
    
    // Métodos de gestión
    void anadirCliente();
    void mostrarTodosVuelos();
    void realizarReservacion();
    void setCliente();
    void mostrarMenu();
    void imprimirReservaciones();
    Vuelo buscarVuelo(string origen, string destino, string fecha);
    void imprimirBoleto(int idReservacion);
    
    // Métodos auxiliares
    void inicializarDatos();
    Cliente* buscarClientePorId(int id);
    Vuelo* buscarVueloPorNumero(int numeroVuelo);
    bool iniciarSesionCliente(int idCliente);
};

#endif