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
        // El usuario quiere ir por SI, así que guardamos el NO en la pila para el futuro
        if (ptrNode->no) probablyStack.push(ptrNode->no);
        return ptrNode->yes;
    }
    if (isProbablyNo(answer)) {
        // El usuario quiere ir por NO, así que guardamos el SI en la pila para el futuro
        if (ptrNode->yes) probablyStack.push(ptrNode->yes);
        return ptrNode->no;
    }

    // Respuestas definitivas (sin cambios)
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
