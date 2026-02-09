#pragma once

#include <string>
#include "node.h"

class GameLogic {
public:
    GameLogic();

    void play();

    // This function receives the user's answer already prepared.
    // It must NOT use cout or cin.
    void processAnswer(const std::string& answer);

private:
    Node* ptrRoot;
    Node* ptrCurrentNode;

    // Recursive question loop
    void questionLoop(Node* ptrNode);

    // This function must NOT request input. It only evaluates the answer.
    bool isYes(const std::string& answer);

    // Called when the game reaches an animal node
    void handleAnimalNode(Node* ptrNode);

    // Placeholder for the future learning function
    void learnNewAnimal(Node* ptrNode); 
};

