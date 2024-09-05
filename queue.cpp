#include <iostream>
#include <queue>

int main() {
    // Declare a queue of integers
    std::queue<int> q;

    // Add elements (enqueue)
    q.push(10);  // Add 10 to the queue
    q.push(20);  // Add 20 to the queue
    q.push(30);  // Add 30 to the queue

    // Display and remove elements from the queue (dequeue)
    while (!q.empty()) {
        // Get the front element
        std::cout << "Front of the queue: " << q.front() << std::endl;

        // Remove the front element
        q.pop();
    }

    return 0;
}
