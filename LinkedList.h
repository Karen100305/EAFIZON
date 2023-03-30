#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Articulos.h"
#include <iostream>
using namespace std;

class Node {
public:
  Articulo articulo;    // producto (es un objeto de tipo articulo)
  Node *next;           // enlace
  Node(Articulo a) {
    this->articulo = a;
    this->next = NULL;
  }
  
  virtual ~Node() {}
};

class LinkedList {
public:
  Node *head = NULL;

  // método para comprobar si un articulo ya existe en la lista enlazada
  bool existe(string n) {
    bool existe = false;
    Node *actual = this->head;
    while (actual != NULL) {
      if (actual->articulo.nombre == n) {
        existe = true;
        return existe;
      }
      actual = actual->next;
    }
    return existe;
  }
  bool existe(int id) {
    bool existe = false;
    Node *actual = this->head;
    while (actual != NULL) {
      if (actual->articulo.id == id) {
        existe = true;
      }
      actual = actual->next;
    }
    return existe;
  }

};

#endif
