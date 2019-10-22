#include "regular_expression_converter.h"

RegularExpressionConverter::RegularExpressionConverter(std::string regexp)
    : postfix_converter_(regexp) {}

void RegularExpressionConverter::createBinaryTree() {
  Stack<BinaryTree<char>> tree_stack;
  std::string postfix_expression = postfix_converter_.convertInfixToPostfix(); 
  for (int i = 0; i < postfix_expression.size(); i++) {
    if (isalpha(postfix_expression[i]))
      tree_stack.push(BinaryTree<char>(postfix_expression[i]));
    else if (isBinary(postfix_expression[i])) {
      BinaryTree<char> right = tree_stack.pop();
      BinaryTree<char> left = tree_stack.pop();
      BinaryTree<char> middle_op(postfix_expression[i]);
      middle_op.insertTrees(left,right);
      tree_stack.push(middle_op);
    }
    else { 
      BinaryTree<char> operand = tree_stack.pop();
      BinaryTree<char> unary_op(postfix_expression[i]);
      unary_op.insertTrees(operand);
      tree_stack.push(unary_op); 
    }
  }
  tree_stack.top().printPreorder(std::cout);
}

bool RegularExpressionConverter::isBinary(char regexp_operator) {
  return (regexp_operator == '&' || regexp_operator == '|')? true : false;
}
