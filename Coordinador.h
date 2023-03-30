#ifndef COORDINADOR_H
#define COORDINADOR_H
#include "Inventario.h"
#include "Usuario.h"
#include <iostream>
#include <string>
using namespace std;

class Coordinador : public Usuario {
public:
  Inventario inventario;
  // Constructor de coordinador
  Coordinador(Inventario i) { this->tipo = "Coordinador"; this->inventario = i;}

  // Métodos para agregar, eliminar, o modificar inventario
  void agregarArticulo() {
    int choice;
    string n;
    int id;
    double p;
    int d;
    cout << "Que tipo de articulo desea agregar?" << endl;
    cout << "(1) Articulo de Tecnologia" << endl
         << "(2) Articulo de Deporte" << endl
         << "(3) Articulo Extranjero" << endl;
    cout << endl << "Opcion: ";
    cin >> choice;
    switch (choice) {
    case 1: {
      cout << "Ingrese el nombre del articulo: ";
      cin >> n;
      cout << "Ingrese el id del articulo: ";
      cin >> id;
      cout << "Ingrese el precio del articulo: ";
      cin >> p;
      cout << "Ingrese la disponibilidad del articulo: ";
      cin >> d;
      this->inventario.addTecnologia(n, id, p, d);
      break;
    }
    case 2: {
      cout << "Ingrese el nombre del articulo: ";
      cin >> n;
      cout << "Ingrese el id del articulo: ";
      cin >> id;
      cout << "Ingrese el precio del articulo: ";
      cin >> p;
      cout << "Ingrese la disponibilidad del articulo: ";
      cin >> d;
      this->inventario.addDeporte(n, id, p, d);
      break;
    }
    case 3: {
      cout << "Ingrese el nombre del articulo: ";
      cin >> n;
      cout << "Ingrese el id del articulo: ";
      cin >> id;
      cout << "Ingrese el precio del articulo: ";
      cin >> p;
      cout << "Ingrese la disponibilidad del articulo: ";
      cin >> d;
      this->inventario.addExtranjero(n, id, p, d);
      break;
    }
    default: {
      cout << "Opción inválida" << endl;
      break;
    }
    }
  }

  void modificarArticulo() {
    int choice;
    int idBuscado;
    cout << endl;
    cout << "1. Modificar nombre" << endl;
    cout << "2. Modificar precio" << endl;
    cout << "3. Modificar disponibilidad" << endl;
    cout << "4. Volver al menú principal" << endl;
    cout << "Opción: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << "Ingrese el id del articulo al que desea modificarle el nombre: ";
      cin >> idBuscado;
      this->inventario.modNombre(idBuscado);
      break;
    }
    case 2: {
      cout << "Ingrese el id del articulo al que desea modificarle el precio: ";
      cin >> idBuscado;
      this->inventario.modPrecio(idBuscado);
      break;
    }
    case 3: {
      cout << "Ingrese el id del articulo al que desea modificarle la "
              "disponibilidad: ";
      cin >> idBuscado;
      this->inventario.modDisponibilidad(idBuscado);
      break;
    }
    case 4: {
      break;
    }
    default: {
      cout << "Opción inválida" << endl;
      break;
    }
    }
  }

  void eliminarArticulo() {
    int idBuscado;
    cout << "Ingrese el id del articulo al que desea eliminar: ";
    cin >> idBuscado;
    if(inventario.existe(idBuscado) == true){
      inventario.remove(idBuscado);
    }
    else{ cout << "El id ingresado no existe" << endl; }
  }
};
#endif
