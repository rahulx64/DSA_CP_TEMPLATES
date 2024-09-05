#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2};

    // Sorting in descending order using an inline lambda function
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;  // Custom condition: sort in descending order
    });

    // Output sorted vector
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
