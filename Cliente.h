#ifndef CLIENTE_H
#define CLIENTE_H
#include "Carrito.h"
#include "Inventario.h"
#include "Usuario.h"
#include <iostream>
using namespace std;

class Cliente : public Usuario {
public:
  Carrito carrito;
  // Constructor cliente
  Cliente(Carrito c) {
    this->tipo = "Cliente";
    this->carrito = c;
  }

  // metodo para comprar un articulo
  void comprarArticulo(Inventario i) {
    string nombreComprar;
    int cantidadComprar;
    bool existe = false;
    cout << "Estos son los articulos disponibles" << endl;
    i.show();
    cout << endl << "Ingrese el nombre del articulo que desea comprar: ";
    cin >> nombreComprar;
1    cout << endl << "Ingrese la cantidad que desea comprar: ";
    cin >> cantidadComprar;
    system("clear");
    Node *actualI = i.head;
    while (actualI != NULL) {
      if (actualI->articulo.nombre == nombreComprar) {
        existe = true;
        if (actualI->articulo.disponibilidad >= cantidadComprar) {
          this->carrito.add(actualI->articulo, cantidadComprar);
          actualI->articulo.disponibilidad -= cantidadComprar;
          cout << actualI->articulo.nombre << " ha sido agregado al carrito"
               << endl;
          cout << "Llevas " << this->carrito.contar()
               << " articulos en tu carrito: " << endl;
          this->carrito.show();
        }
        if (actualI->articulo.disponibilidad < cantidadComprar) {
          cout << "Operacion fallida. Superaste las unidades disponibles"
               << endl;
        }
      }
      actualI = actualI->next;
    }
    if (existe == false) {
      cout << "Articulo no encontrado" << endl;
    }
  }

  void pagar() {
    cout << "Compra exitosa" << endl;
    this->carrito.sumar();
    this->carrito.vaciarCarrito();
  }

  void devolver(Inventario i) {
    cout << "Compra cancelada" << endl
         << "Se han devuelto los articulos de tu carrito al inventario" << endl;
    int cantidadDevuelta;
    Node *actualC = this->carrito.head;
    Node *actualI = i.head;
    while (actualC != NULL) {
      while (actualI != NULL) {
        if (actualC->articulo.nombre == actualI->articulo.nombre) {
          actualI->articulo.disponibilidad += actualC->articulo.disponibilidad;
        }
        actualI = actualI->next;
      }
      actualC = actualC->next;
    }
    this->carrito.vaciarCarrito();
  }
};

#endif
