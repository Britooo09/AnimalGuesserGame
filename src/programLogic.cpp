#include "../include/programLogic.h"
#include <iostream>

// Recursive deletion in post-order (left, right, root)
static void deleteTree(Node* node) {
    std::cout << "Deleted node" << std::endl;
    if (node == nullptr) return;
    deleteTree(node->yes);
    deleteTree(node->no);
    delete node;
	node = nullptr; // Avoid dangling pointers
}

void play() {
  
}

void learn() {
   
}

void saveTree() {
   
}

void loadTree() {
    
}

void cleanMemory(Node* root) {
    deleteTree(root);
	std::cout << "All memory cleaned up." << std::endl;
}
