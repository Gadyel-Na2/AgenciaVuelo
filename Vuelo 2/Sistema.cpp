#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Constructor
Sistema::Sistema() {
    numClientes = 0;
    numVuelos = 0;
    numReservaciones = 0;
    inicializarDatos();
}

void Sistema::inicializarDatos() {
    // Inicializar clientes con algunos que ya tienen más de 50,000 km
    clientes[0] = Cliente(1, "Juan Perez", "juan.perez@email.com", 55000.0);
    clientes[1] = Cliente(2, "Maria Garcia", "maria.garcia@email.com", 75000.0);
    clientes[2] = Cliente(3, "Carlos Lopez", "carlos.lopez@email.com", 25000.0);
    clientes[3] = Cliente(4, "Ana Martinez", "ana.martinez@email.com", 60000.0);
    numClientes = 4;
    
    // Inicializar vuelos disponibles
    vuelos[0] = Vuelo(101, "Ciudad de Mexico", "Nueva York", "2025-12-15", 5, 8500.0, 50, 3360.0);
    vuelos[1] = Vuelo(102, "Guadalajara", "Los Angeles", "2025-12-16", 4, 6200.0, 30, 2450.0);
    vuelos[2] = Vuelo(103, "Monterrey", "Miami", "2025-12-17", 3, 7800.0, 40, 2890.0);
    vuelos[3] = Vuelo(104, "Cancun", "Madrid", "2025-12-18", 10, 15000.0, 25, 8200.0);
    vuelos[4] = Vuelo(105, "Ciudad de Mexico", "Tokyo", "2025-12-20", 14, 22000.0, 20, 11300.0);
    vuelos[5] = Vuelo(106, "Tijuana", "San Francisco", "2025-12-21", 3, 5500.0, 35, 1200.0);
    numVuelos = 6;
    
    cout << "Sistema inicializado con " << numClientes << " clientes y " 
         << numVuelos << " vuelos disponibles." << endl;
}

void Sistema::anadirCliente() {
    if (numClientes >= 10) {
        cout << "\nERROR: No se pueden agregar mas clientes. Limite alcanzado (10)." << endl;
        return;
    }
    
    int id;
    string nombre, email;
    double km;
    
    cout << "\n=== AGREGAR NUEVO CLIENTE ===" << endl;
    cout << "Ingrese ID del cliente: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);
    cout << "Ingrese email: ";
    getline(cin, email);
    cout << "Ingrese kilometros acumulados: ";
    cin >> km;
    
    clientes[numClientes] = Cliente(id, nombre, email, km);
    numClientes++;
    
    cout << "\nCliente agregado exitosamente!" << endl;
    clientes[numClientes-1].mostrarInformacion();
}

void Sistema::mostrarTodosVuelos() {
    cout << "\n======================================" << endl;
    cout << "    VUELOS DISPONIBLES" << endl;
    cout << "======================================" << endl;
    
    if (numVuelos == 0) {
        cout << "No hay vuelos disponibles en este momento." << endl;
        return;
    }
    
    for (int i = 0; i < numVuelos; i++) {
        vuelos[i].mostrarInformacion();
    }
}

Cliente* Sistema::buscarClientePorId(int id) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].getId() == id) {
            return &clientes[i];
        }
    }
    return nullptr;
}

Vuelo* Sistema::buscarVueloPorNumero(int numeroVuelo) {
    for (int i = 0; i < numVuelos; i++) {
        if (vuelos[i].getNumeroVuelo() == numeroVuelo) {
            return &vuelos[i];
        }
    }
    return nullptr;
}

bool Sistema::iniciarSesionCliente(int idCliente) {
    Cliente* cliente = buscarClientePorId(idCliente);
    if (cliente == nullptr) {
        cout << "\nCliente no encontrado. Por favor registrese primero." << endl;
        return false;
    }
    
    cout << "\nBienvenido, " << cliente->getNombre() << "!" << endl;
    if (cliente->tieneDescuento()) {
        cout << "*** Usted es cliente frecuente y tiene 40% de descuento! ***" << endl;
    }
    return true;
}

void Sistema::realizarReservacion() {
    if (numReservaciones >= 10) {
        cout << "\nERROR: No se pueden realizar mas reservaciones. Limite alcanzado (10)." << endl;
        return;
    }
    
    int idCliente;
    cout << "\n=== REALIZAR RESERVACION ===" << endl;
    cout << "Ingrese su ID de cliente: ";
    cin >> idCliente;
    
    if (!iniciarSesionCliente(idCliente)) {
        return;
    }
    
    Cliente* cliente = buscarClientePorId(idCliente);
    
    mostrarTodosVuelos();
    
    int numeroVuelo;
    cout << "\nIngrese el numero de vuelo que desea reservar: ";
    cin >> numeroVuelo;
    
    Vuelo* vuelo = buscarVueloPorNumero(numeroVuelo);
    
    if (vuelo == nullptr) {
        cout << "\nVuelo no encontrado." << endl;
        return;
    }
    
    if (!vuelo->hayAsientosDisponibles()) {
        cout << "\nLo sentimos, no hay asientos disponibles en este vuelo." << endl;
        return;
    }
    
    double precioOriginal = vuelo->getPrecio();
    double precioFinal = precioOriginal;
    bool descuentoAplicado = false;
    
    if (cliente->tieneDescuento()) {
        precioFinal = precioOriginal * 0.6; // 40% de descuento
        descuentoAplicado = true;
        cout << "\nPrecio original: $" << precioOriginal << endl;
        cout << "Descuento 40% aplicado: $" << (precioOriginal * 0.4) << endl;
        cout << "Precio final: $" << precioFinal << endl;
    } else {
        cout << "\nPrecio del vuelo: $" << precioFinal << endl;
    }
    
    char confirmacion;
    cout << "\nDesea confirmar la reservacion? (s/n): ";
    cin >> confirmacion;
    
    if (confirmacion == 's' || confirmacion == 'S') {
        vuelo->reservarAsiento();
        cliente->acumularKilometros(vuelo->getDistanciaKm());
        
        int idReservacion = numReservaciones + 1;
        reservaciones[numReservaciones] = Reservacion(
            idReservacion, 
            idCliente, 
            numeroVuelo, 
            precioFinal, 
            vuelo->getDestino(), 
            descuentoAplicado
        );
        numReservaciones++;
        
        cout << "\n*** RESERVACION EXITOSA ***" << endl;
        reservaciones[numReservaciones-1].mostrarInformacion();
        
        char imprimirBoleto;
        cout << "Desea imprimir su boleto? (s/n): ";
        cin >> imprimirBoleto;
        if (imprimirBoleto == 's' || imprimirBoleto == 'S') {
            this->imprimirBoleto(idReservacion);
        }
    } else {
        cout << "\nReservacion cancelada." << endl;
    }
}

void Sistema::setCliente() {
    anadirCliente();
}

void Sistema::imprimirReservaciones() {
    cout << "\n======================================" << endl;
    cout << "    TODAS LAS RESERVACIONES" << endl;
    cout << "======================================" << endl;
    
    if (numReservaciones == 0) {
        cout << "No hay reservaciones registradas." << endl;
        return;
    }
    
    for (int i = 0; i < numReservaciones; i++) {
        reservaciones[i].mostrarInformacion();
        
        Cliente* cliente = buscarClientePorId(reservaciones[i].getIdCliente());
        if (cliente != nullptr) {
            cout << "Nombre del cliente: " << cliente->getNombre() << endl;
        }
        
        Vuelo* vuelo = buscarVueloPorNumero(reservaciones[i].getNumeroVuelo());
        if (vuelo != nullptr) {
            cout << "Origen: " << vuelo->getOrigen() << " -> Destino: " 
                 << vuelo->getDestino() << endl;
            cout << "Fecha: " << vuelo->getFecha() << endl;
        }
        cout << "-----------------------------------" << endl;
    }
}

Vuelo Sistema::buscarVuelo(string origen, string destino, string fecha) {
    cout << "\n=== BUSQUEDA DE VUELOS ===" << endl;
    cout << "Buscando vuelos de " << origen << " a " << destino 
         << " en fecha " << fecha << endl;
    
    bool encontrado = false;
    for (int i = 0; i < numVuelos; i++) {
        if (vuelos[i].getOrigen() == origen && 
            vuelos[i].getDestino() == destino && 
            vuelos[i].getFecha() == fecha) {
            vuelos[i].mostrarInformacion();
            encontrado = true;
            return vuelos[i];
        }
    }
    
    if (!encontrado) {
        cout << "No se encontraron vuelos con esos criterios." << endl;
    }
    
    return Vuelo();
}

void Sistema::imprimirBoleto(int idReservacion) {
    Reservacion* reservacion = nullptr;
    for (int i = 0; i < numReservaciones; i++) {
        if (reservaciones[i].getIdReservacion() == idReservacion) {
            reservacion = &reservaciones[i];
            break;
        }
    }
    
    if (reservacion == nullptr) {
        cout << "\nReservacion no encontrada." << endl;
        return;
    }
    
    Cliente* cliente = buscarClientePorId(reservacion->getIdCliente());
    Vuelo* vuelo = buscarVueloPorNumero(reservacion->getNumeroVuelo());
    
    if (cliente == nullptr || vuelo == nullptr) {
        cout << "\nError al obtener informacion del boleto." << endl;
        return;
    }
    
    // Crear archivo de texto con formato de boleto
    string nombreArchivo = "boleto_" + to_string(idReservacion) + ".txt";
    
    #ifdef _WIN32
        string rutaCompleta = string(getenv("USERPROFILE")) + "\\Downloads\\" + nombreArchivo;
    #else
        string rutaCompleta = string(getenv("HOME")) + "/Downloads/" + nombreArchivo;
    #endif
    
    ofstream archivo(rutaCompleta);
    
    if (!archivo.is_open()) {
        cout << "\nError al crear el archivo del boleto." << endl;
        return;
    }
    
    // Diseño del boleto compacto (max 40 caracteres)
    archivo << "========================\n";
    archivo << "   BOLETO DE VUELO\n";
    archivo << "========================\n";
    archivo << "\n";
    archivo << "PASAJERO: " << cliente->getNombre() << "\n";
    archivo << "\n";
    archivo << "----------------------------------------\n";
    archivo << "VUELO #" << vuelo->getNumeroVuelo() << "\n";
    archivo << "----------------------------------------\n";
    archivo << "De:    " << vuelo->getOrigen() << "\n";
    archivo << "A:     " << vuelo->getDestino() << "\n";
    archivo << "Fecha: " << vuelo->getFecha() << "\n";
    archivo << "Hora:  " << vuelo->getDuracion() << " hrs\n";
    archivo << "\n";
    
    if (reservacion->getDescuentoAplicado()) {
        archivo << "DESCUENTO 40% APLICADO\n";
        archivo << "Precio Original: $" << vuelo->getPrecio() << "\n";
    }
    
    archivo << "TOTAL: $" << reservacion->getPrecioFinal() << "\n";
    archivo << "\n";
    archivo << "Reservacion: #" << reservacion->getIdReservacion() << "\n";
    archivo << "========================\n";
    archivo << "Buen viaje y vuelo seguro!\n";
    archivo << "========================\n";
    
    archivo.close();
    
    cout << "\n*** BOLETO GENERADO EXITOSAMENTE ***" << endl;
    cout << "El boleto se ha guardado en: " << rutaCompleta << endl;
}

void Sistema::mostrarMenu() {
    int opcion;
    
    do {
        cout << "\n========================================" << endl;
        cout << "    SISTEMA DE GESTION DE VUELOS" << endl;
        cout << "========================================" << endl;
        cout << "1. Agregar Cliente" << endl;
        cout << "2. Mostrar Todos los Vuelos" << endl;
        cout << "3. Realizar Reservacion" << endl;
        cout << "4. Mostrar Todas las Reservaciones" << endl;
        cout << "5. Buscar Vuelo por Criterios" << endl;
        cout << "6. Reimprimir Boleto" << endl;
        cout << "7. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                anadirCliente();
                break;
            case 2:
                mostrarTodosVuelos();
                break;
            case 3:
                realizarReservacion();
                break;
            case 4:
                imprimirReservaciones();
                break;
            case 5: {
                string origen, destino, fecha;
                cin.ignore();
                cout << "\nIngrese ciudad de origen: ";
                getline(cin, origen);
                cout << "Ingrese ciudad de destino: ";
                getline(cin, destino);
                cout << "Ingrese fecha (AAAA-MM-DD): ";
                getline(cin, fecha);
                buscarVuelo(origen, destino, fecha);
                break;
            }
            case 6: {
                int idReserva;
                cout << "\nIngrese el ID de la reservacion: ";
                cin >> idReserva;
                imprimirBoleto(idReserva);
                break;
            }
            case 7:
                cout << "\nGracias por usar el sistema. Hasta pronto!" << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }
    } while(opcion != 7);
}