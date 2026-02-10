#pragma once

#include "node.h"
#include <string>

class GameLogic {
public:
    GameLogic();
    void play();
    Node* getRoot();
    Node* getCurrentNode();
    void setCurrentNode(Node* ptrNode);
    void questionLoop(Node* ptrNode);

private:
    Node* ptrRoot;
    Node* ptrCurrentNode;

    bool isYes(const std::string& answer);
    void cliInteraction(Node* ptrNode);
    void cliHandleAnimalNode(Node* ptrNode);
};
