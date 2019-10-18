#include "postfix.h"
#include "regular_expression_converter.h"
int main() {
  RegularExpressionConverter t("(A*|B)(AB)*");
  t.createBinaryTree();
};
