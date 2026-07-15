#include "polynomial.h"
#include <iostream>

int main() { 
    Polynomial p;      // 0 
    p.addTerm(1, 3);   // 3x 
    p.addTerm(2, 1);   // x^2 
    p.addTerm(0, -1);  // -1 
 
    Polynomial q(p);   // x^2 + 3x - 1 
    q.addTerm(1, -3);  // -3x 
 
    std::cout << "P(x) = " << p << std::endl; 
    std::cout << "P(1) = " << p.evaluate(1) << std::endl; 
    std::cout << "Q(x) = " << q << std::endl; 
    std::cout << "Q(1) = " << q.evaluate(1) << std::endl; 
    std::cout << "(P+Q)(x) = " << p+q << std::endl; 
    std::cout << "(P*Q)(x) = " << p*q << std::endl; 
}
