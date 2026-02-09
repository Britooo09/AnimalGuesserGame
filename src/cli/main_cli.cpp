#include <iostream>
#include "node.h"
#include "programLogic.h"

using namespace std;

int main()
{
	cout << "--- THIS IS A TEST. IT WILL BE REMOVED LATER ---" << endl << endl;

	Node* ptrRoot = new Node("Is it a mammal?", true);
	ptrRoot->yes = new Node("Dog", false);
	ptrRoot->no = new Node("Lizard", false);

	Node* ptrCurrentNode = ptrRoot;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ptrCurrentNode->yes->text << endl;
	cout << "No branch: " << ptrCurrentNode->no->text << endl << endl;

	cout << "Move to the \"yes\" branch (Dog):" << endl << endl;
	ptrCurrentNode = ptrCurrentNode->yes;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl << endl;

	ptrCurrentNode->makeQuestion("Does it meow?", "Cat");

	cout << "Check the values again:" << endl << endl;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl << endl;

	cout << "Move to the \"no\" branch (Dog):" << endl << endl;
	ptrCurrentNode = ptrCurrentNode->no;

	cout << "Current node: " << ptrCurrentNode->text << endl;
	cout << "Yes branch: " << ((ptrCurrentNode->yes == nullptr) ? ("Null") : (ptrCurrentNode->yes->text)) << endl;
	cout << "No branch: " << ((ptrCurrentNode->no == nullptr) ? ("Null") : (ptrCurrentNode->no->text)) << endl;

	return 0;
}
