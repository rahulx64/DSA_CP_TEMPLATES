#include <iostream>
#include <stack>

int main() {
    // Creating a stack of integers
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.top() << std::endl; // 30

    // Pop the top element
    myStack.pop();

    std::cout << "Top element after pop: " << myStack.top() << std::endl; // 20

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        std::cout << "Stack is not empty!" << std::endl;
    }

    // Get the size of the stack
    std::cout << "Size of the stack: " << myStack.size() << std::endl; // 2

    return 0;
}
