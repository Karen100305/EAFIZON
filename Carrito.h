#ifndef CARRITO_H
#define CARRITO_H
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Carrito : public LinkedList {
public:
  // constructor carrito
  Carrito() {
    Articulo null("NULL", 0, 0, 0);
    head = new Node(null);
  }

  // método para añadir un nuevo articulo de deporte al carrito
  void addDeporte(string n, int id, double p, int d) {
    if (existe(n) == false) {
      articuloDeporte newDeporte(n, id, p, d);
      if (head->articulo.nombre == "NULL") {
        delete head;
        head = new Node(newDeporte);
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = new Node(newDeporte);
      }
    } else {
      Node *actual = head;
      while (actual != NULL) {
        if (actual->articulo.nombre == n) {
          actual->articulo.disponibilidad += d;
        }
        actual = actual->next;
      }
    }
  }

  // método para añadir un nuevo articulo de deporte al carrito
  void addExtranjero(string n, int id, double p, int d) {
    if (existe(n) == false) {
      articuloExtranjero newExtranjero(n, id, (p+(p*0.1)), d);
      if (head->articulo.nombre == "NULL") {
        delete head;
        head = new Node(newExtranjero);
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = new Node(newExtranjero);
      }
    } else {
      Node *actual = head;
      while (actual != NULL) {
        if (actual->articulo.nombre == n) {
          actual->articulo.disponibilidad += d;
        }
        actual = actual->next;
      }
    }
  }

  // método para añadir un articulo nuevo de tecnologia al carrito
  void addTecnologia(string n, int id, double p, int d) {
    if (existe(n) == false) {
      articuloTecnologia newTecno(n, id, p, d);
      if (head->articulo.nombre == "NULL") {
        delete head;
        head = new Node(newTecno);
      } else {
        Node *actual = head;
        while (actual->next != NULL) {
          actual = actual->next;
        }
        actual->next = new Node(newTecno);
      }
    } else {
      Node *actual = head;
      while (actual != NULL) {
        if (actual->articulo.nombre == n) {
          actual->articulo.disponibilidad += d;
        }
        actual = actual->next;
      }
    }
  }

  void add(Articulo a, int c) {
    if (a.tipo == "Deporte") {
      addDeporte(a.nombre, a.id, a.precio, c);
    } else if (a.tipo == "Tecnologia") {
      addTecnologia(a.nombre, a.id, a.precio, c);
    } else if (a.tipo == "Extranjero"){
      addExtranjero(a.nombre, a.id, a.precio, c);
    }
  }

  void vaciarCarrito() {
    while (head->next != NULL) {
      Node *actual = head;
      head = head->next;
      delete actual;
    }
    Articulo null("NULL", 0, 0, 0);
    head = new Node(null);
  }

  int contar() {
    int contador = 0;
    Node *current = head;
    while (current != NULL) {
      contador++;
      current = current->next;
    }
    return contador;
  }

  void sumar() {
    double subtotal = 0;
    double total = 0;
    bool descuento = false;
    Node *current = head;
    while (current != NULL) {
      subtotal += (current->articulo.precio * current->articulo.disponibilidad);
      if (current->articulo.tipo == current->next->articulo.tipo){
        descuento = true;
      }
      current = current->next;
    }
    if (descuento == true){
      total = subtotal * 0.9;
      cout << "Se ha aplicado un 10% de descuento"<<endl;
    }
    cout << "El subtotal es: $"<<subtotal << endl;
    cout << endl << "Has pagado: $" << total << endl;
  }

  void show() {
    if (head == NULL) {
      cout << "El carrito esta vacio." << endl;
    }
    Node *actual = head;
    while (actual != NULL) {
      cout << endl;
      cout << "Nombre: " << actual->articulo.nombre << endl;
      cout << "Precio: " << actual->articulo.precio
           << "    Cantidad: " << actual->articulo.disponibilidad << endl;
      cout << endl << endl;
      actual = actual->next;
    }
  }
};

#endif
