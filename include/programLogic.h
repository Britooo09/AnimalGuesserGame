#pragma once

// When the program fails at guessing, this function creates a new question and animal
void learn();

// Save the tree structure to a file
void saveTree();

// Load the tree structure from a file de texto
void loadTree();

// Free all dynamic memory occupied by the tree
void cleanMemory();
