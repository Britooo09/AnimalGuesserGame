#include "../include/answerHandler.h"
#include <algorithm>

AnswerHandler::AnswerHandler() {}

bool AnswerHandler::isYes(const std::string& answer) {
    std::string lower = answer;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return (lower == "yes" || lower == "y");
}

bool AnswerHandler::isProbablyYes(const std::string& answer) {
    std::string lower = answer;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return (lower == "probably yes");
}

bool AnswerHandler::isProbablyNo(const std::string& answer) {
    std::string lower = answer;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return (lower == "probably no");
}

Node* AnswerHandler::processAnswer(Node* ptrCurrentNode, const std::string& answer) {

    if (isYes(answer)) {
        return ptrCurrentNode->yes;
    }

    if (isProbablyYes(answer)) {
        probablyStack.push(ptrCurrentNode);
        return ptrCurrentNode->yes;
    }

    if (isProbablyNo(answer)) {
        probablyStack.push(ptrCurrentNode);
        return ptrCurrentNode->no;
    }

    return ptrCurrentNode->no;
}
