#pragma once

#include "node.h"
#include <string>

class GameLogic {
public:
    GameLogic();
    void play();
    Node* getRoot();

private:
    Node* ptrRoot;
    Node* ptrCurrentNode;

    // Recursive question loop
    void questionLoop(Node* ptrNode);

    // This function must NOT request input. It only evaluates the answer
    bool isYes(const std::string& answer);

    // Function for CLI cin and cout interaction
	bool cliInteraction(Node* ptrNode);

    // Called when the game reaches an animal node
    void cliHandleAnimalNode(Node* ptrNode);
};
