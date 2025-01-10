// b^-1=b^(m-2)%m

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute (base^exp) % mod
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; // If exp is odd
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

// Function to find the multiplicative inverse
long long multiplicativeInverse(long long b, long long mod) {
    return modularExponentiation(b, mod - 2, mod);
}

int main() {
    long long b;
    cout << "Enter value of b: ";
    cin >> b;

    if (b == 0) {
        cout << "Multiplicative inverse does not exist for 0." << endl;
    } else {
        cout << "Multiplicative inverse of " << b << " modulo " << MOD << " is: "
             << multiplicativeInverse(b, MOD) << endl;
    }

    return 0;
}
