// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares 
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 15/10/2019
// Archivo stack.h: Define una pila de tipo genérico mediante el uso de templates 
//                     
//                 
// Referencias: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
//                    
// Historial de revisiones
//                    15/10/2019 - Creación del código

#ifndef STACK_H
#define STACK_H

#include <list>

// Ejemplo de uso:
//  stack<int> pila;
//  for (int i = 0; i < 10; i++)
//    pila.push(i);  
//  while (!pila.empty())
//    pila.pop();   
template<class T>
class Stack {
 public:
  Stack() {};
  T pop();
  void push(T data);
  T top();
  bool empty();
  int size();
 private:
  std::list<T> data_; 
};

// Devuelve y elimina el último elemento de la pila
template<class T>
T Stack<T>::pop() {
  if (!empty()) {
    T top = data_.back();
    data_.pop_back();
    return top;
  }
}

// Empuja un nuevo elemento en la pila
template<class T>
void Stack<T>::push(T data) {
  data_.push_back(data);
}

// Devuelve 1 si la pila está vacia
template<class T>
bool Stack<T>::empty() {
  return data_.empty();
}

// Devuelve el tamaño de la pila
template<class T>
int Stack<T>::size() {
  return data_.size();
}

// Devuelve el último elemento
template<class T>
T Stack<T>::top() {
  return data_.back();
}
#endif // STACK_H
