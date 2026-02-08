#include "../include/programLogic.h"
#include "../include/node.h"


void play() {

}

void learn(Node* ptrCurrentNode , std::string newQuestion, std::string newAnimal) {
	ptrCurrentNode->makeQuestion(newQuestion, newAnimal);
	}

void to_json(nlohmann::ordered_json& j, const Node* ptrSaveNode) {
    if (ptrSaveNode == nullptr) {
        j = nullptr;
    }
    else {
        j = nlohmann::ordered_json::object();
        j["isQuestion"] = ptrSaveNode->isQuestion;

        if (ptrSaveNode->isQuestion) {
            // Format for questions: [Level 01] Question?
            j["text"] = "[Level " + ptrSaveNode->levelCode + "] " + ptrSaveNode->text;

            if (ptrSaveNode->yes != nullptr) j["yes"] = ptrSaveNode->yes;
            if (ptrSaveNode->no != nullptr) j["no"] = ptrSaveNode->no;
        }
        else {
            // Format for animals as requested: [Animal 011] Name
            j["text"] = "[Animal " + ptrSaveNode->levelCode + "] " + ptrSaveNode->text;
        }
    }
}

void saveTree(Node* ptrRoot) {
    // Define the path to the archive file
    static const std::string ARCHIVE_PATH = "../../../data/animal_tree.json";

    // 1. Use ordered_json to ensure keys like "text" appear before "yes"/"no"
    nlohmann::ordered_json j;

    // 2. Explicitly call to_json to avoid implicit conversion errors
    to_json(j, ptrRoot);

    std::ofstream file(ARCHIVE_PATH);

    if (file.is_open()) {
        // Save with 4-space indentation for readability
        file << j.dump(4);
        file.close();
        std::cout << "Tree saved successfully in: " << ARCHIVE_PATH << std::endl;
    }
    else {
        std::cerr << "Error: Could not open the file in 'data/'. Ensure the folder exists." << std::endl;
    }
}

void loadTree() {

}

void cleanMemory() {

}
