#include "../include/gameLogic.h"
#include <iostream>

GameLogic::GameLogic() {
    // Initial tree
    ptrRoot = new Node("Is it a mammal?", true);
    ptrRoot->yes = new Node("Does it have fur?", true);
    ptrRoot->yes->yes = new Node("Does it bark?", true);
    ptrRoot->yes->yes->yes = new Node("Dog", false);
    ptrRoot->yes->yes->no = new Node("Cat", false);
    ptrRoot->yes->no = new Node("Does it have a trunk?", true);
    ptrRoot->yes->no->yes = new Node("Elephant", false);
    ptrRoot->yes->no->no = new Node("Dolphin", false);

    ptrRoot->no = new Node("Does it fly?", true);
    ptrRoot->no->yes = new Node("Does it have a beak?", true);
    ptrRoot->no->yes->yes = new Node("Eagle", false);
    ptrRoot->no->yes->no = new Node("Bat", false);
    ptrRoot->no->no = new Node("Does it have scales?", true);
    ptrRoot->no->no->yes = new Node("Snake", false);
    ptrRoot->no->no->no = new Node("Frog", false);

    ptrCurrentNode = nullptr;
}

void GameLogic::play() {
    ptrCurrentNode = ptrRoot;
    questionLoop(ptrCurrentNode);
}

Node* GameLogic::getRoot() {
    return ptrRoot;
}

void GameLogic::questionLoop(Node* ptrNode) {
    if (!ptrNode) return;

    if (ptrNode->isQuestion) {
        Node* nextNode = answerHandler.processAnswer(ptrNode, cliInteraction(ptrNode));
        if (nextNode) {
            questionLoop(nextNode);
        }
        else {
            // Si el input fue inválido, intentar recuperar de la pila
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

std::string GameLogic::cliInteraction(Node* ptrNode) {
    std::cout << ptrNode->text << " (yes/no/probably yes/probably no): ";
    std::string userInput;
    std::getline(std::cin, userInput);

    // Normalización rápida para no complicar el processAnswer
    if (userInput == "y") return "yes";
    if (userInput == "n") return "no";
    if (userInput == "py") return "probably yes";
    if (userInput == "pn") return "probably no";

    return userInput; // Retorna lo que sea que haya escrito
}

void GameLogic::cliHandleAnimalNode(Node* ptrNode) {
    std::cout << "I think your animal is: " << ptrNode->text << std::endl;
    std::cout << "Was I correct? (yes/no): ";
    std::string userInput;
    std::getline(std::cin, userInput);

    if (isYes(userInput)) {
        std::cout << "Great! Do you want to play again? (yes/no): ";
        // ... (resto del código de éxito)
    }
    else {
        // Aquí está la clave:
        Node* alternativePath = answerHandler.popProbablyNode();
        if (alternativePath) {
            std::cout << "Wait... I remember you weren't sure about a previous question. Let's try the other path!" << std::endl;
            questionLoop(alternativePath);
        }
        else {
            std::cout << "I give up. I don't know this animal." << std::endl;
            // Aquí llamarías a learn() en el futuro
        }
    }
}

