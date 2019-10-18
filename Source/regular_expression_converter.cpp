#include "regular_expression_converter.h"

RegularExpressionConverter::RegularExpressionConverter(std::string regexp)
    : postfix_converter_(regexp) {}

void RegularExpressionConverter::createBinaryTree() {
  Stack<BinaryNode<char>> tree_stack;
  std::string postfix_expression = postfix_converter_.convertInfixToPostfix(); 
  for (int i = 0; i < postfix_expression.size(); i++) {
    if (isalpha(postfix_expression[i]))
      tree_stack.push(BinaryNode<char>(postfix_expression[i]));
    else if (isBinary(postfix_expression[i])) {
      BinaryNode<char> right = tree_stack.pop();
      BinaryNode<char> left = tree_stack.pop();
      tree_stack.push(BinaryNode<char>(postfix_expression[i], left, right));
    }
    else { 
      BinaryNode<char> operand = tree_stack.pop();
      tree_stack.push(BinaryNode<char>(postfix_expression[i], &operand)); 
    }
  }
  tree_stack.top().preorderPrint(std::cout);
}

bool RegularExpressionConverter::isBinary(char regexp_operator) {
  return (regexp_operator == '&' || regexp_operator == '|')? true : false;
}
