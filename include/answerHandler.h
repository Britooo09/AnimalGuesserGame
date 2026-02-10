#pragma once
#include <stack>
#include <iostream>
#include "node.h"
#include <string>

class AnswerHandler {
public:
    AnswerHandler();

	// Process the user's answer and return the next node to navigate to
    Node* processAnswer(Node* ptrNode, const std::string& answer);

	// Return the last saved node from the probably stack
    Node* popProbablyNode();

private:
    std::stack<Node*> probablyStack;

    bool isProbablyYes(const std::string& answer);
    bool isProbablyNo(const std::string& answer);
};
