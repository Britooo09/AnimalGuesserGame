#include "../include/gameLogic.h"
#include "../include/programLogic.h"
#include <iostream>

GameLogic::GameLogic() {
    // Initial tree
    ptrRoot = new Node("Is it a mammal?", true);
    ptrRoot->yes = new Node("Dog", false);
    ptrRoot->no = new Node("Lizard", false);

    ptrCurrentNode = nullptr;
}

void GameLogic::play() {
    ptrCurrentNode = ptrRoot;
    questionLoop(ptrCurrentNode);
}

Node* GameLogic::getRoot()
{
	return ptrRoot;
}

void GameLogic::questionLoop(Node* ptrNode) {
    if (!ptrNode) {
        std::cerr << "Error: null node encountered." << std::endl;
        return;
    }

    if (ptrNode->isQuestion) {
        std::cout << ptrNode->text 
                  << " (yes / no / probably yes / probably no): ";

        std::string userInput;
        std::getline(std::cin, userInput);

        Node* ptrNextNode = answerHandler.processAnswer(ptrNode, userInput);

        questionLoop(ptrNextNode);
    }
    else {
        cliHandleAnimalNode(ptrNode);
    }
}



bool GameLogic::isYes(const std::string& answer) {
    std::string lower = answer;
    for (char& c : lower) {
        c = static_cast<char>(tolower(c));
    }

    return (lower == "yes" || lower == "y");
}

bool GameLogic::cliInteraction(Node* ptrNode) {
    std::cout << ptrNode->text << " (yes/no): ";

    std::string userInput;
    std::getline(std::cin, userInput);

    if (isYes(userInput)) {
        return true;
    }
    else {
        return false;
    }
}


void GameLogic::cliHandleAnimalNode(Node* ptrNode) {
    std::cout << "I think your animal is: " << ptrNode->text << std::endl;
    std::cout << "Was I correct? (yes/no): ";

    std::string userInput;
    std::getline(std::cin, userInput);

    if (isYes(userInput)) {
        std::cout << "Great! Do you want to play again? (yes/no): ";
        std::getline(std::cin, userInput);

        if (isYes(userInput)) {
            play();
            return;
        }
        else {
            std::cout << "Thanks for playing!" << std::endl;
        }
    }
    else {
        std::cout << "I couldn't guess your animal." << std::endl;
        std::cout << "Learning mode should be called here." << std::endl;

        // Placeholder for the future learning function
        learn();
    }
}
