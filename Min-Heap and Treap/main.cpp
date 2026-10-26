/**
 * AI USAGE; GPT-5.6 Luna
 */
#include <iostream>

#include "MinHeap.h"
#include "Treap.h"

int main() {

    MinHeap heap;

    int values[] = {
        42, 17, 8, 99, 23,
        4, 15, 60, 1, 31
    };

    for (int value : values)
        heap.insert(value);

    std::cout << "Initial min-heap array:\n";
    heap.printArray();

    std::cout << "Minimum element: "
              << heap.peekMin() << "\n";

    heap.removeMin();
    heap.removeMin();

    std::cout << "\nHeap after removing two minimum values:\n";
    heap.printArray();

    heap.insert(2);
    heap.insert(7);

    std::cout << "\nHeap after inserting 2 and 7:\n";
    heap.printArray();

    std::cout << "Current minimum: "
              << heap.peekMin() << "\n";

    Treap treap;

    // At least 10 key-priority pairs
    treap.insert(50, 35);
    treap.insert(30, 80);
    treap.insert(70, 25);
    treap.insert(20, 60);
    treap.insert(40, 90);
    treap.insert(60, 45);
    treap.insert(80, 70);
    treap.insert(10, 20);
    treap.insert(35, 55);
    treap.insert(65, 95);

    std::cout << "\nTreap preorder traversal:\n";
    treap.printPreorder();

    std::cout << "\nSearch results:\n";
    std::cout << "Search 40: "
              << (treap.search(40) ? "Found" : "Not found")
              << "\n";

    std::cout << "Search 100: "
              << (treap.search(100) ? "Found" : "Not found")
              << "\n";

    return 0;
}