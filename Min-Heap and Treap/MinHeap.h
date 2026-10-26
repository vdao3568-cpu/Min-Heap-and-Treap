/**
 * AI USAGE; GPT-5.6 Luna
 */
#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <utility>

class MinHeap {
private:
    std::vector<int> data;

    void heapifyUp(std::size_t index) {
        while (index > 0) {
            std::size_t parent = (index - 1) / 2;

            if (data[parent] <= data[index])
                break;

            std::swap(data[parent], data[index]);
            index = parent;
        }
    }

    void heapifyDown(std::size_t index) {
        while (true) {
            std::size_t left = 2 * index + 1;
            std::size_t right = 2 * index + 2;
            std::size_t smallest = index;

            if (left < data.size() && data[left] < data[smallest])
                smallest = left;

            if (right < data.size() && data[right] < data[smallest])
                smallest = right;

            if (smallest == index)
                break;

            std::swap(data[index], data[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    int peekMin() const {
        if (data.empty())
            throw std::runtime_error("Heap is empty.");

        return data[0];
    }

    int removeMin() {
        if (data.empty())
            throw std::runtime_error("Heap is empty.");

        int minimum = data[0];

        data[0] = data.back();
        data.pop_back();

        if (!data.empty())
            heapifyDown(0);

        return minimum;
    }

    void printArray() const {
        std::cout << "[ ";

        for (int value : data)
            std::cout << value << " ";

        std::cout << "]\n";
    }

    bool empty() const {
        return data.empty();
    }
};

#endif