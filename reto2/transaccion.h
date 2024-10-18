#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
using namespace std;

enum CategoriaCombustible { Regular, Premium, EcoExtra };

class Transaccion {
private:
    int id;
    string fecha;
    double litros;
    CategoriaCombustible categoria;
    double monto;

public:
    Transaccion(int _id, string _fecha, double _litros, CategoriaCombustible _categoria, double _monto);
    void mostrarTransaccion() const;
    double getMonto() const; // Método getter para el monto
    CategoriaCombustible getCategoria() const; // Método getter para la categoría
    double getLitros() const; // Método getter para los litros
};

#endif // TRANSACCION_H
