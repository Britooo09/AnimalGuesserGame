#pragma once
#include <stack>
#include "node.h"
#include <string>

class AnswerHandler {
public:
    AnswerHandler();

    // Procesa la respuesta del usuario y devuelve el siguiente nodo a visitar
    Node* processAnswer(Node* ptrNode, const std::string& answer);

    // Devuelve el último nodo guardado en la pila de "probably"
    Node* popProbablyNode();

private:
    std::stack<Node*> probablyStack;

    bool isProbablyYes(const std::string& answer);
    bool isProbablyNo(const std::string& answer);
};
