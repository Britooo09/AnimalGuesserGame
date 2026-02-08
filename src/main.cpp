#include <iostream>
#include "../include/node.h"
#include "../include/programLogic.h"

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

// Test the makeQuestion function
	Node* ptrRoot = new Node("Lizard", false);
	ptrRoot->levelCode = "R";
	ptrRoot->makeQuestion("Is it a mammal?", "Dog");

	Node* ptrCurrentNode = ptrRoot;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;

	advanceToNextNode(ptrCurrentNode, true);
	cout << "Move to the \"yes\" branch (Dog):" << endl << endl;
	
	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;
	
	ptrCurrentNode->makeQuestion("Does it meow?", "Cat");
	cout << "Check the values again:" << endl << endl;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;
	
	advanceToNextNode(ptrCurrentNode, false);
	cout << "Move to the \"no\" branch (Dog):" << endl << endl;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;

	learn(ptrCurrentNode, "Does it slither?", "Snake", ptrRoot);
	cout << "Check the values again:" << endl << endl;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;

	advanceToNextNode(ptrCurrentNode, true);
	cout << "Move to the \"yes\" branch (Snake):" << endl << endl;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;
	cout << "Level code: " << ptrCurrentNode->levelCode << endl << endl;



	return 0;
}
