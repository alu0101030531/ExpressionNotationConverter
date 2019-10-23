// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo BinaryTree.h: Crea un árbol a partir de un nodo raíz  
//                     
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "binary_node.h"
#include <iostream>

// Modo de Uso:
//  BinaryTree arbol1('c');
//  arbol1.printPreorder();
//  BinaryTree arbol2('a');
//  arbol1.insertTree(arbol2);
//  arbol1.printPreorder
template <class T>
class BinaryTree {
 public:
  BinaryTree(T data);
  BinaryTree(const BinaryTree<T>& obj);
   ~BinaryTree();
  BinaryNode<T>* getRoot() const {return root;};
  void insertTrees(BinaryTree<T>& left, BinaryTree<T>& right);
  void insertTrees(BinaryTree<T>& left);
  void printPreorder(std::ostream& os);
  int  getSize();
 private:
  void constructTree(BinaryNode<T>* in_node, BinaryNode<T>* out_node);
  void destroyTree(BinaryNode<T>* node);
  int getSize(int& num_nodes, BinaryNode<T>* node);
  void insertTree(BinaryNode<T>* node, BinaryNode<T>* out_node);
  void printPreorder(std::ostream& os, BinaryNode<T>* node);
 private:
  BinaryNode<T>* root;    // Nodo raíz del árbol
};

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& obj) {
  root = new BinaryNode<T>(obj.getRoot()->getData());
  insertTree(root,obj.getRoot());
}


// Construye un árbol a partir de un dato
template <class T>
BinaryTree<T>::BinaryTree(T data) {
 root = new BinaryNode<T>(data);
}

template <class T>
BinaryTree<T>::~BinaryTree() {
  if (root->getLeft() != nullptr)
  destroyTree(root->getLeft());
  if (root->getRight() != nullptr)
  destroyTree(root->getRight());
  root = nullptr;
}

template <class T>
void BinaryTree<T>::destroyTree(BinaryNode<T>* node) {
  if (node == nullptr)
    return;
  destroyTree(node->getLeft());
  destroyTree(node->getRight());
  delete node;
}

// Devuelve los nodos generados por el árbol
template <class T> 
int BinaryTree<T>::getSize() {
  int num_nodes=0;
  return getSize(num_nodes, root);
}

// Recorre los nodos sumando el número de estos
template <class T>
int BinaryTree<T>::getSize(int& num_nodes, BinaryNode<T>* node) {
  if (node == nullptr)
    return num_nodes;
  num_nodes++;
  getSize(num_nodes, node->getLeft());
  getSize(num_nodes, node->getRight());
}

// Inserta un árbol a la izquierda de root
template <class T>
void BinaryTree<T>::insertTrees(BinaryTree<T>& left) {
  BinaryNode<T>* left_root = new BinaryNode<T>(left.getRoot()->getData());
  root->setLeft(left_root);
  insertTree(root->getLeft(), left.getRoot());
}

// Inserta dos árboles a derecha e izquierda
template <class T>
void BinaryTree<T>::insertTrees(BinaryTree<T>& left, BinaryTree<T>& right) {
  BinaryNode<T>* left_root = new BinaryNode<T>(left.getRoot()->getData());
  BinaryNode<T>* right_root = new BinaryNode<T>(right.getRoot()->getData());
  root->setLeft(left_root);
  root->setRight(right_root);
  insertTree(root->getLeft(), left.getRoot());
  insertTree(root->getRight(), right.getRoot());
}

// Copia los nodos de un árbol al árbol de la instancia
template <class T>
void BinaryTree<T>::insertTree(BinaryNode<T>* node, BinaryNode<T>* out_node) {
  if (out_node->getLeft() == nullptr)
    return;
  BinaryNode<T>* left_node = new BinaryNode<T>(out_node->getLeft()->getData());
  node->setLeft(left_node);
  insertTree(node->getLeft(), out_node->getLeft());
  if (out_node->getRight() == nullptr)
    return;
  BinaryNode<T>* right_node = new BinaryNode<T>(out_node->getRight()->getData());
  node->setRight(right_node);
  insertTree(node->getRight(), out_node->getRight());
}

// Muestra el árbol en preorden
template <class T>
void BinaryTree<T>::printPreorder(std::ostream& os) {
  printPreorder(os,root);
}

// Recorre el árbol mostrando los nodos según los visita
template <class T>
void BinaryTree<T>::printPreorder(std::ostream& os, BinaryNode<T>* node) {
  if (node == nullptr)
    return;
  os << node->getData();
  printPreorder(os, node->getLeft());
  printPreorder(os, node->getRight());
}

#endif // BINARY_NODE_H
