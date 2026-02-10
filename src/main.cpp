#include <iostream>
#include "../include/node.h"
#include "../include/gameLogic.h" 

using namespace std;

void advanceToNextNode(Node*& ptrCurrentNode, bool answer) {
	if (ptrCurrentNode->yes) {
		if (answer) {
			ptrCurrentNode = ptrCurrentNode->yes;
		}
		else {
			ptrCurrentNode = ptrCurrentNode->no;
		}
	}
	else {
		std::cerr << "Error: No Advance. Current node has no branches to advance to." << endl;
	}
}

int main()
{
	cout << "--- THIS IS A TEST. IT WILL BE REMOVED LATER ---" << endl << endl;
// Create a simple tree for testing
	//Node* ptrRoot = new Node("Is it a mammal?", true);
	//ptrRoot->yes = new Node("Dog", false);
	//ptrRoot->no = new Node("Lizard", false);
	//ptrRoot->levelCode = "R";

// Test loading the tree from a file
	//Node* ptrRoot = loadTree();

	GameLogic game;
	game.play();

	cout << "The root of this tree is: " << game.getRoot()->text << endl;

	return 0;
}
