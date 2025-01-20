#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>


class RPN {
private:
  bool isOperator(const std::string &token);
  int performOperation(int a, int b, char op);
  int stringToInt(const std::string &str);

public:
  RPN();
  RPN(const RPN& copy);
  RPN& operator=(const RPN& other);
  ~RPN();
  int evaluate(const std::string &expression);

};

#endif