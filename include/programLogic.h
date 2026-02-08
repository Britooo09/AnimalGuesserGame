#pragma once

#include "node.h"

// Start the tree exploration by asking the user
void play();

// When the program fails at guessing, this function creates a new question and animal
void learn();

// Save the tree structure to a file
void saveTree();

// Load the tree structure from a text file
void loadTree();

// Free all dynamic memory occupied by the tree. The root is passed explicitly to avoid globals.
void cleanMemory(Node* root);
