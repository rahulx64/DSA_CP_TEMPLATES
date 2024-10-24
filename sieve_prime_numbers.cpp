#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;  

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {

            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }


    cout << "Prime numbers from 1 to " << n << " are: ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}
