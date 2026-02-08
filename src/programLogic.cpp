#include "../include/programLogic.h"
#include "../include/node.h"
#include <string>

void play() {

}

void learn(Node* ptrCurrentNode ,std::string newAnimal, std::string newQuestion) {
	std::string oldAnimal = ptrCurrentNode->text; // Store the old animal's name before overwriting it
	ptrCurrentNode->text = newQuestion; // Update the current node's text to the new question
	ptrCurrentNode->isQuestion = true; // Mark the current node as a question
	
	ptrCurrentNode->yes = new Node(newAnimal, false); // Create a new "yes" node for the new animal
	ptrCurrentNode->no = new Node(oldAnimal, false); // Create a new "no" node for the old animal
	}

void saveTree() {

}

void loadTree() {

}

void cleanMemory() {

}
