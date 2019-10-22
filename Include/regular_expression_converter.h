#include "postfix.h"
#include "binary_tree.h"

class RegularExpressionConverter {
 public:
  RegularExpressionConverter(std::string regexp);
  void createBinaryTree();
 private:
  bool isBinary(char regexp_operator);
 private:
  PostFix postfix_converter_;
};
