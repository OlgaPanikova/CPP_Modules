#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& copy) {
	*this =  copy;
}

RPN& RPN::operator=(const RPN& other) {
  (void)other;
  return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string &token) {
  return token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos;
}

int RPN::performOperation(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) throw std::runtime_error("Division by zero");
                return a / b;
            default: throw std::runtime_error("Invalid operator");
        }
}

int RPN::evaluate(const std::string &expression) {
        std::stack<int> s;
        std::istringstream iss(expression);
        std::string token;

        while (iss >> token) {
            if (isdigit(token[0])) 
            {
                s.push(stringToInt(token));
            } else if (isOperator(token)) {
                if (s.size() < 2) throw std::runtime_error("Not enough operands");
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int result = performOperation(a, b, token[0]);
                s.push(result);
            } else {
                throw std::runtime_error("Invalid token: " + token);
            }
        }

        if (s.size() != 1) throw std::runtime_error("Invalid expression");
        return s.top();
    }

int RPN::stringToInt(const std::string &str) {
        std::stringstream ss(str);
        int num;
        ss >> num;
        if (ss.fail() || !ss.eof()) {
            throw std::runtime_error("Invalid number: " + str);
    }
        return num;
    }