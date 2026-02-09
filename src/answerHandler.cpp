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
        probablyStack.push(ptrNode);
        return ptrNode->yes;
    }
    if (isProbablyNo(answer)) {
        probablyStack.push(ptrNode);
        return ptrNode->no;
    }

    // Respuestas definitivas
    if (answer == "yes" || answer == "y") return ptrNode->yes;
    if (answer == "no" || answer == "n") return ptrNode->no;

    return nullptr; // fallback
}

Node* AnswerHandler::popProbablyNode() {
    if (probablyStack.empty()) return nullptr;
    Node* topNode = probablyStack.top();
    probablyStack.pop();
    return topNode;
}
