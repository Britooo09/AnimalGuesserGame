#pragma once
#include "../include/node.h"
#include <iostream>
#include <fstream>
#include <regex>

// When the program fails at guessing, this function creates a new question and animal
void learn(Node* ptrCurrentNode, std::string newQuestion, std::string newAnimal, Node* ptrRoot);

// Save the tree structure to a file
	// This function uses the to_json function to convert the tree into a JSON format and saves it to a file.
void to_json(nlohmann::ordered_json& j, const Node* ptrSaveNode);
void saveTree(Node* ptrRoot);

// Clean the text by removing the prefix (e.g., [Level 01] or [Animal 011]) and returning only the actual question or animal name.
std::string cleanText(std::string rawText);

// Load the tree structure from a file de texto
	// This function reads the JSON content from a file, converts it back into the tree structure using the from_json function, and returns a pointer to the root of the tree.
void from_json(const nlohmann::ordered_json& j, Node*& ptrNode);
Node* loadTree();

// Free all dynamic memory occupied by the tree
void cleanMemory();
