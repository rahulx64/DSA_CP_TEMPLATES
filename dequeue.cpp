#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;

    // Insertion Operations
    dq.push_back(10);        // Back: 10
    dq.push_front(20);       // Front: 20  Back: 10
    dq.emplace_back(30);     // Back: 10 30
    dq.emplace_front(40);    // Front: 40 20

    // Access Operations
    std::cout << "Front element: " << dq.front() << std::endl;  // 40
    std::cout << "Back element: " << dq.back() << std::endl;    // 30
    std::cout << "Element at index 1: " << dq.at(1) << std::endl; // 20

    // Capacity Operations
    std::cout << "Size: " << dq.size() << std::endl;  // 4

    // Removal Operations
    dq.pop_back();   // Removes 30
    dq.pop_front();  // Removes 40

    // Modify and Erase
    dq.insert(dq.begin() + 1, 50);  // Inserts 50 at index 1
    dq.erase(dq.begin());           // Erases the first element (20)

    // Iterator Operations
    std::cout << "Elements in deque: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";  // Prints remaining elements (50, 10)
    }
    std::cout << std::endl;

    // Clear the deque
    dq.clear();

    // Check if deque is empty
    if (dq.empty()) {
        std::cout << "Deque is empty!" << std::endl;
    }

    return 0;
}
