#include "../include/node.h"
#include <string>

Node::Node(std::string t, bool q) : text(t), isQuestion(q), yes(nullptr), no(nullptr) {}

void Node::makeQuestion(std::string question, std::string newLeaf) {
	if (!isQuestion) {
		isQuestion = true;
		yes = new Node(newLeaf, false); // Node "yes" becomes the new animal (which is now the "affirmative" answer to the new question)
		no = new Node(text, false); // Node "no" becomes the old animal (which is now the "negative" answer to the new question)
		text = question; // The current node's text becomes the new question that distinguishes the new animal from the old one
	}
}
