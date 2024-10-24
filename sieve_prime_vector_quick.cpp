#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n,vector<int> & v) {
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;  
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            v.push_back(i);
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
  vector<int> v={};
    sieveOfEratosthenes(n,v);
    return 0;
}
