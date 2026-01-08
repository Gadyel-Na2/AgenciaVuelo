#ifndef VUELO_H
#define VUELO_H

#include <string>
using namespace std;

class Vuelo {
private:
    int numeroVuelo;
    string origen;
    string destino;
    string fecha;
    int duracion;
    double precio;
    int asientosDisponibles;
    double distanciaKm;

public:
    // Constructor
    Vuelo();
    Vuelo(int numeroVuelo, string origen, string destino, string fecha, 
          int duracion, double precio, int asientosDisponibles, double distanciaKm);
    
    // Getters
    int getNumeroVuelo() const;
    string getOrigen() const;
    string getDestino() const;
    string getFecha() const;
    int getDuracion() const;
    double getPrecio() const;
    int getAsientosDisponibles() const;
    double getDistanciaKm() const;
    
    // Setters
    void setNumeroVuelo(int numeroVuelo);
    void setOrigen(string origen);
    void setDestino(string destino);
    void setFecha(string fecha);
    void setDuracion(int duracion);
    void setPrecio(double precio);
    void setAsientosDisponibles(int asientos);
    void setDistanciaKm(double distancia);
    
    // Métodos específicos
    double agregarPrecio() const;
    bool hayAsientosDisponibles() const;
    void reservarAsiento();
    void mostrarInformacion() const;
};

#endif
