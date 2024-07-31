#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>


bool isPrime(int n)
{

    if (n <= 1)
        return false;

    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = (result * base) % mod;
        }
        exp = exp >> 1;    
        base = (base * base) % mod;  
    }
    return result;
}



// Tonelli-Shanks Algorithm for square root mod p
bool TS(long long n, long long p, long long& x1, long long& x2) {
    
    // No solution 
    if (modExp(n, (p - 1) / 2, p) != 1) {
        return false; 
    }
    
    if (p % 4 == 3) {
        x1 = modExp(n, (p + 1) / 4, p);
        x2 = p - x1;
        return true;
    }
    
    long long s = 0;
    long long q = p - 1;
    while (q % 2 == 0) {
        s++;
        q /= 2;
    }
    
    long long z;
    for (z = 2; z < p; z++) {
        if (modExp(z, (p - 1) / 2, p) == p - 1) {
            break;
        }
    }
    
    long long m = s;
    long long c = modExp(z, q, p);
    long long t = modExp(n, q, p);
    long long r = modExp(n, (q + 1) / 2, p);
    
    while (t != 0 && t != 1) {
        long long t2i = t;
        long long i = 0;
        for (i = 1; i < m; i++) {
            t2i = (t2i * t2i) % p;
            if (t2i == 1) {
                break;
            }
        }
        
        long long b = modExp(c, 1 << (m - i - 1), p);
        m = i;
        c = (b * b) % p;
        r = (r * b) % p;
        t = (t * c) % p;
    }
    
    x1 = r;
    x2 = p - r;
    return true;
}

std::vector<int> F(int p) {
    std::vector <int> Fp;

    Fp.push_back(0);
    for (int i = 0; i < p-1; ++i) {
        Fp.push_back(i + 1);  
    }

    return Fp;
}

std::vector<std::tuple<int, int>> Points(std::vector<int> Fp, int p, int A, int B) {
    // Weierstrass equation parameters A, B given by int A, int B.

    std::vector<std::tuple<int, int>> pts;

    for(int k : Fp){
        long long G = pow(k,3) + A*k + B;
        
        long long x1, x2;
        if (TS(G, p, x1, x2)) {
            pts.push_back(std::make_tuple(k, x1));
            pts.push_back(std::make_tuple(k, x2));
        } 

    
    }

    return pts; 
}




