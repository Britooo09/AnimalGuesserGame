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

    AnswerHandler answerHandler;

    void questionLoop(Node* ptrNode);
    bool isYes(const std::string& answer);
    std::string cliInteraction(Node* ptrNode);
    void cliHandleAnimalNode(Node* ptrNode);
};
