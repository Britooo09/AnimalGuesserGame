#pragma once

#include <string>
#include <stack>
#include "node.h"

class AnswerHandler {
public:
    AnswerHandler();

    Node* processAnswer(Node* ptrCurrentNode, const std::string& answer);

private:
    std::stack<Node*> probablyStack;

    bool isYes(const std::string& answer);
    bool isProbablyYes(const std::string& answer);
    bool isProbablyNo(const std::string& answer);
};
