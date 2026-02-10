#include <iostream>
#include "../include/node.h"
#include "../include/programLogic.h"
using namespace std;

int main() {
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
  
	// Free all dynamic memory before exiting (by explicitly passing the root)
	cleanMemory(ptrRoot);
  
	return 0;
}