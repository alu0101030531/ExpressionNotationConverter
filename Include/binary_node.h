// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo BinaryNode.h: Crea nodos que tienen un dato, y un hijo izquierdo y derecho
//                     
//                 
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include <vector>
#include <iostream>

// Modo de Uso:
// BinaryNode<char> nodo('c');
// nodo.getLeft();
// nodo.setRight();
//char caracter =  nodo.getData();

template <class T>
class BinaryNode {
 public:
  BinaryNode(T data, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr);
  T getData() const { return data_;};
  BinaryNode<T>* getLeft() const {return left_;};
  BinaryNode<T>* getRight() const {return right_;};
  void setLeft(BinaryNode<T>* left) {left_ = left;};
  void setRight(BinaryNode<T>* right) {right_ = right;};
 private:
  T data_;                                // Dato que guarda
  BinaryNode<T>* left_;                   // Puntero al hijo izquierdo   
  BinaryNode<T>* right_;                  // Puntero al hijo derecho
};

// Construye un nodo binario a partir de un dato, un hijo derecho y uno izquierdo, si no son especificados valen nullptr
template <class T>
BinaryNode<T>::BinaryNode(T data, BinaryNode<T>* left, BinaryNode<T>* right)
    : data_(data), left_(left), right_(right) {
}

#endif // BINARY_NODE_H
