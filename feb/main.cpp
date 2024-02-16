#include "res.h"
#include <iostream>

int Algorythms::fib(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

void Algorythms::fibDynamic(int n) {
    fibresult[0] = 1;
    fibresult[1] = 1;

    for (int i )
}

int main() {
    // Your code here
    Algorythms alg;

    std::cout << alg.fib(10) << std::endl;
    
    return 0;
}
