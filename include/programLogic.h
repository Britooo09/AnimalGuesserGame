#pragma once
#include "../include/node.h"
#include <iostream>
#include <fstream>

// Start the tree exploration by asking the user
void play();

// When the program fails at guessing, this function creates a new question and animal
void learn(Node* ptrCurrentNode, std::string newAnimal, std::string newQuestion);

// Save the tree structure to a file
void to_json(nlohmann::ordered_json& j, const Node* ptrSaveNode);
void saveTree(Node* ptrRoot);

// Load the tree structure from a file de texto
void loadTree();

// Free all dynamic memory occupied by the tree
void cleanMemory();
