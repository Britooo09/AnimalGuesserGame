#pragma once

#include "node.h"
#include "answerHandler.h"
#include <string>

class GameLogic {
public:
    GameLogic();
    void play();
    Node* getRoot();

private:
    Node* ptrRoot;
    Node* ptrCurrentNode;

    AnswerHandler answerHandler; // manejador de respuestas

    void questionLoop(Node* ptrNode);
    bool isYes(const std::string& answer);
    bool cliInteraction(Node* ptrNode);
    void cliHandleAnimalNode(Node* ptrNode);
};
