#include "../include/gameLogic.h"
#include <iostream>

GameLogic::GameLogic() {
    // Initial tree (temporary example)
    ptrRoot = new Node("Is it a mammal?", true);
    ptrRoot->yes = new Node("Dog", false);
    ptrRoot->no = new Node("Lizard", false);

    ptrCurrentNode = ptrRoot;
}

void GameLogic::play() {
    ptrCurrentNode = ptrRoot;
    questionLoop(ptrCurrentNode);
}

void GameLogic::processAnswer(const std::string& answer) {
    if (!ptrCurrentNode) return;

    if (ptrCurrentNode->isQuestion) {
        if (isYes(answer)) {
            ptrCurrentNode = ptrCurrentNode->yes;
        }
        else {
            ptrCurrentNode = ptrCurrentNode->no;
        }
        questionLoop(ptrCurrentNode);
    }
    else {
        handleAnimalNode(ptrCurrentNode);
    }
}

void GameLogic::questionLoop(Node* ptrNode) {
    if (ptrNode == nullptr) {
        std::cerr << "Error: null node encountered." << std::endl;
        return;
    }

    if (ptrNode->isQuestion) {
        // Ask the question (UI layer must handle input/output)
        std::cout << ptrNode->text << " (yes/no): ";

        std::string userInput;
        std::getline(std::cin, userInput);

        if (isYes(userInput)) {
            questionLoop(ptrNode->yes);
        }
        else {
            questionLoop(ptrNode->no);
        }
    }
    else {
        // Reached an animal node
        handleAnimalNode(ptrNode);
    }
}

bool GameLogic::isYes(const std::string& answer) {
    std::string lower = answer;
    for (char& c : lower) {
        c = static_cast<char>(tolower(c));
    }

    return (lower == "yes" || lower == "y");
}

void GameLogic::handleAnimalNode(Node* ptrNode) {
    std::cout << "I think your animal is: " << ptrNode->text << std::endl;
    std::cout << "Was I correct? (yes/no): ";

    std::string userInput;
    std::getline(std::cin, userInput);

    if (isYes(userInput)) {
        std::cout << "Great! Do you want to play again? (yes/no): ";
        std::getline(std::cin, userInput);

        if (isYes(userInput)) {
            play();
        }
        else {
            std::cout << "Thanks for playing!" << std::endl;
        }
    }
    else {
        std::cout << "I couldn't guess your animal." << std::endl;
        std::cout << "Learning mode should be called here." << std::endl;

        // Placeholder for the future learning function
        learnNewAnimal(ptrNode);
    }
}

void GameLogic::learnNewAnimal(Node* ptrNode) {
    // TODO: Implement the learning logic here
    // Example:
    // 1. Ask user for the correct animal
    // 2. Ask for a distinguishing question
    // 3. Call ptrNode->makeQuestion(...)
}
