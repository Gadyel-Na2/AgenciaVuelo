#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
using namespace std;

class Reservacion {
private:
    int idReservacion;
    int idCliente;
    int numeroVuelo;
    double precioFinal;
    string destinoVuelo;
    bool descuentoAplicado;

public:
    // Constructor
    Reservacion();
    Reservacion(int idReservacion, int idCliente, int numeroVuelo, 
                double precioFinal, string destinoVuelo, bool descuentoAplicado);
    
    // Getters
    int getIdReservacion() const;
    int getIdCliente() const;
    int getNumeroVuelo() const;
    double getPrecioFinal() const;
    string getDestinoVuelo() const;
    bool getDescuentoAplicado() const;
    
    // Setters
    void setIdReservacion(int id);
    void setIdCliente(int idCliente);
    void setNumeroVuelo(int numeroVuelo);
    void setPrecioFinal(double precio);
    void setDestinoVuelo(string destino);
    void setDescuentoAplicado(bool descuento);
    
    // Métodos específicos
    void mostrarInformacion() const;
    void cancelarReservacion();
    string iniciarSesion();
};

#endif