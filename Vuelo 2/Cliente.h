#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    string email;
    double kilometrosAcumulados;

public:
    // Constructor
    Cliente();
    Cliente(int id, string nombre, string email, double kilometrosAcumulados = 0.0);
    
    // Getters
    int getId() const;
    string getNombre() const;
    string getEmail() const;
    double getKilometrosAcumulados() const;
    
    // Setters
    void setId(int id);
    void setNombre(string nombre);
    void setEmail(string email);
    void setKilometrosAcumulados(double kilometros);
    
    // Métodos específicos
    void acumularKilometros(double kilometros);
    bool tieneDescuento() const;
    void mostrarInformacion() const;
};

#endif