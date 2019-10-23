// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 5 CyA - Expresiones regulares
// Fecha: 14/10/2019
// Archivo regular_expression_converter.cpp: Definiciones de la clase RegularExpressionConverter
//                     
// Referencias: 
//              https://campusvirtual.ull.es/1920/mod/assign/view.php?id=114057
// Historial de revisiones
//                    20/10/2019 - Creación del código


#include "regular_expression_converter.h"

// Crea un convertidor de expresiones regulares a partir de un string que representa una expresion regular
RegularExpressionConverter::RegularExpressionConverter(std::string regexp)
    : postfix_converter_(regexp), expression_tree_(createBinaryTree()) {}

// Crea el árbol binario de la expresión
BinaryTree<char> RegularExpressionConverter::createBinaryTree() {
  std::stack<BinaryTree<char>> tree_stack;
  std::string postfix_expression = postfix_converter_.convertInfixToPostfix(); 
  for (int i = 0; i < postfix_expression.size(); i++) {
    if (isalpha(postfix_expression[i]))
      tree_stack.push(BinaryTree<char>(postfix_expression[i]));
    else if (isBinary(postfix_expression[i])) {
      BinaryTree<char> right = tree_stack.top();
      tree_stack.pop();
      BinaryTree<char> left = tree_stack.top();
      tree_stack.pop(); 
      BinaryTree<char> middle_op(postfix_expression[i]);
      middle_op.insertTrees(left,right);
      tree_stack.push(middle_op);
    }
    else { 
      BinaryTree<char> operand = tree_stack.top();
      tree_stack.pop();
      BinaryTree<char> unary_op(postfix_expression[i]);
      unary_op.insertTrees(operand);
      tree_stack.push(unary_op); 
    }
  } 
  tree_stack.top().printPreorder(std::cout);
  return tree_stack.top();
}

// Comprueba si el operadores es binarios
bool RegularExpressionConverter::isBinary(char regexp_operator) {
  return (regexp_operator == '&' || regexp_operator == '|')? true : false;
}
