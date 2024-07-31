#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "curves.h"


void printPoints(const std::vector<std::tuple<int, int>>& pts) {
    for (const auto& point : pts) {
        std::cout << "(" << std::get<0>(point) << ", " << std::get<1>(point) << ")" << std::endl;
    }
}


int main() {
    int p = 13; 

    std::cout << "Enter order of prime field: "; 
    std::cin >> p;
    std::vector<int> Fp = F(p);

    if(!(isPrime(p) && p>=3)) {
        std::cout << "WARNING: p isn't prime and/or p isn't geq 3" << "\n";
    }

    std::cout << "Points on the elliptic curve over the field " << "F" << p << ": " << "\n";
    printPoints(Points(Fp, p, 3, 8));

  
    return 0;
}