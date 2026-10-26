/**
 * AI USAGE; GPT-5.6 Luna
 */
#ifndef TREAP_H
#define TREAP_H

#include <iostream>

struct TreapNode {
    int key;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int keyValue, int priorityValue)
        : key(keyValue),
          priority(priorityValue),
          left(nullptr),
          right(nullptr) {}
};

class Treap {
private:
    TreapNode* root = nullptr;

    TreapNode* rotateRight(TreapNode* node) {
        TreapNode* newRoot = node->left;

        node->left = newRoot->right;
        newRoot->right = node;

        return newRoot;
    }

    TreapNode* rotateLeft(TreapNode* node) {
        TreapNode* newRoot = node->right;

        node->right = newRoot->left;
        newRoot->left = node;

        return newRoot;
    }

    TreapNode* insert(TreapNode* node, int key, int priority) {
        if (node == nullptr)
            return new TreapNode(key, priority);

        if (key < node->key) {
            node->left = insert(node->left, key, priority);

            // Max-heap property on priority
            if (node->left->priority > node->priority)
                node = rotateRight(node);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, priority);

            // Max-heap property on priority
            if (node->right->priority > node->priority)
                node = rotateLeft(node);
        }

        return node;
    }

    TreapNode* search(TreapNode* node, int key) const {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

    void printPreorder(TreapNode* node) const {
        if (node == nullptr)
            return;

        std::cout << "(key=" << node->key
                  << ", priority=" << node->priority << ") ";

        printPreorder(node->left);
        printPreorder(node->right);
    }

    void destroy(TreapNode* node) {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~Treap() {
        destroy(root);
    }

    void insert(int key, int priority) {
        root = insert(root, key, priority);
    }

    bool search(int key) const {
        return search(root, key) != nullptr;
    }

    void printPreorder() const {
        printPreorder(root);
        std::cout << "\n";
    }
};

#endif