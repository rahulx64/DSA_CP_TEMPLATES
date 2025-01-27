#include <iostream>
using namespace std;

const long long N = 2e5 + 7; // Maximum size of the Fenwick Tree
const long long maxn = N;

struct FenwickTree {
    long long BIT[maxn] = {0}; // Fenwick Tree array initialized to 0

    // Query function to get the prefix sum from index 1 to i (1-based index)
    long long query(long long i) {
        i++; // Adjusting to 1-based indexing
        long long sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= (i & -i); // Move to the parent node
        }
        return sum;
    }

    // Update function to add 'val' to the element at index i (1-based index)
    void update(long long i, long long val) {
        i++; // Adjusting to 1-based indexing
        while (i <= maxn) {
            BIT[i] += val;
            i += (i & -i); // Move to the next node
        }
    }

    // Range update function to add 'val' to all elements in the range [l, r]
    void rupdate(long long l, long long r, long long val) {
        update(l, val);     // Add 'val' to index l
        update(r + 1, -val); // Subtract 'val' from index r + 1
    }
} fenw;

int main() {
    FenwickTree fenw;

    // Example usage
    fenw.update(3, 5); // Add 5 to index 3
    fenw.update(5, 10); // Add 10 to index 5

    cout << "Prefix sum up to index 5: " << fenw.query(5) << endl;

    fenw.rupdate(2, 4, 3); // Add 3 to all elements in the range [2, 4]
    cout << "Prefix sum up to index 5 after range update: " << fenw.query(5) << endl;

    return 0;
}
