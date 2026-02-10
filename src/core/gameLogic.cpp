#include "gameLogic.h"
#include "globals.h"
#include "programLogic.h"
#include <iostream>

GameLogic::GameLogic() {
    // Attempt to load the tree from a file
    ptrRoot = loadTree();
    ptrCurrentNode = nullptr;
}

void GameLogic::play() {
    std::cout << "Amount of animals currently loaded: " << countAnimals(getRoot()) << std::endl << std::endl;
    ptrCurrentNode = ptrRoot;
    questionLoop(ptrCurrentNode);
}

Node* GameLogic::getRoot() {
    return ptrRoot;
}

Node* GameLogic::getCurrentNode() {
    return ptrCurrentNode;
}

void GameLogic::setCurrentNode(Node* ptrNode) {
    ptrCurrentNode = ptrNode;
}

void GameLogic::questionLoop(Node* ptrNode) {
    if (!ptrNode) return;

    if (ptrNode->isQuestion) {
        Node* nextNode = answerHandler.processAnswer(ptrNode, RESPONSE);
        if (nextNode) {
            questionLoop(nextNode);
        }
        else {
			// If no next node, try alternative path
            Node* alternativeNode = answerHandler.popProbablyNode();
            if (alternativeNode) questionLoop(alternativeNode);
        }
    }
    else {
        cliHandleAnimalNode(ptrNode);
    }
}

bool GameLogic::isYes(const std::string& answer) {
    std::string lower = answer;
    for (char& c : lower) c = static_cast<char>(tolower(c));
    return (lower == "yes" || lower == "y");
}

void GameLogic::cliInteraction(Node* ptrNode) {
    std::cout << ptrNode->text << " (yes/no/probably yes/probably no): ";
    std::string userInput;
    std::getline(std::cin, userInput);

	// Normalize the input
    if (userInput == "y") userInput = "yes";
    if (userInput == "n") userInput = "no";
    if (userInput == "py") userInput = "probably yes";
    if (userInput == "pn") userInput = "probably no";

    RESPONSE = userInput; // Return as is for further processing
}

void GameLogic::cliHandleAnimalNode(Node* ptrNode) {
    std::cout << "I think your animal is: " << ptrNode->text << std::endl;
    std::cout << "Was I correct? (yes/no): ";
    std::string userInput;
    std::getline(std::cin, userInput);

    if (isYes(userInput)) {
        std::cout << "Great! Do you want to play again? (yes/no): ";
        std::getline(std::cin, userInput);
        if (isYes(userInput)) play();
        else std::cout << "Thanks for playing!" << std::endl;
    }
    else {
		// Try alternative path if available
        Node* alternativePath = answerHandler.popProbablyNode();
        if (alternativePath) {
            std::cout << "Wait... I remember you weren't sure about a previous question. Let's try the other path!" << std::endl;
            questionLoop(alternativePath);
        }
        else {
			std::string newAnimal, newQuestion;
            std::cout << "I give up. I don't know this animal." << std::endl;
			std::cout << "What animal were you thinking of? " << std::endl;
			std::getline(std::cin, newAnimal);
			std::cout << "Please provide a question that distinguishes " << newAnimal << " from " << ptrNode->text << "." << std::endl;
			std::getline(std::cin, newQuestion);
			// Here you could implement learning logic to add the new animal
			learn(ptrNode, newQuestion, newAnimal, getRoot()); // Placeholder values for learning
            std::cout << "Great! Do you want to play again? (yes/no): ";
            std::getline(std::cin, userInput);
            if (isYes(userInput)) play();
            else std::cout << "Thanks for playing!" << std::endl;
        }
    }
}

