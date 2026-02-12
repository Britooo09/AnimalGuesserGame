#include "answerHandler.h"
#include <algorithm>


AnswerHandler::AnswerHandler() {}

bool AnswerHandler::isProbablyYes(const std::string& answer) {
    std::string lower = answer;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return (lower == "probably yes" || lower == "py");
}

bool AnswerHandler::isProbablyNo(const std::string& answer) {
    std::string lower = answer;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return (lower == "probably no" || lower == "pn");
}

Node* AnswerHandler::processAnswer(Node* ptrNode, const std::string& answer) {
    if (isProbablyYes(answer)) {
		// The user wants to go YES, so we save NO in the stack for future
        if (ptrNode->no) probablyStack.push(ptrNode->no);
        return ptrNode->yes;
    }
    if (isProbablyNo(answer)) {
		// The user wants to go NO, so we save YES in the stack for future
        if (ptrNode->yes) probablyStack.push(ptrNode->yes);
        return ptrNode->no;
    }

	// Answer is definitely YES or NO
    if (answer == "yes" || answer == "y") return ptrNode->yes;
    if (answer == "no" || answer == "n") return ptrNode->no;

    return nullptr;
}

Node* AnswerHandler::popProbablyNode() {
    if (probablyStack.empty()) { 
        return nullptr; 
    }
    Node* topNode = probablyStack.top();
    probablyStack.pop();
    return topNode;
}
