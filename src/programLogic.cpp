#include "../include/programLogic.h"
#include "../include/node.h"
#include "../include/gameLogic.h"
#include <iostream>

int countAnimals(Node* ptrRoot) {
	// Base case: if the node is null, it contributes 0 animals
    if (ptrRoot == nullptr) {
        return 0;
    }

	// If it's a leaf node (not a question), it contributes 1 animal
    if (!ptrRoot->isQuestion) {
        return 1;
    }

	// Recursive case: sum the counts from the "yes" and "no" branches
    return countAnimals(ptrRoot->yes) + countAnimals(ptrRoot->no);
}

// Recursive deletion in post-order (left, right, root)
static void deleteTree(Node* node) {
    std::cout << "Deleted node" << std::endl;
    if (node == nullptr) return;
    deleteTree(node->yes);
    deleteTree(node->no);
    delete node;
	node = nullptr; // Avoid dangling pointers
}

void learn(Node* ptrCurrentNode , std::string newQuestion, std::string newAnimal, Node* ptrRoot) {
	std::cout << "Learning new animal: " << newAnimal << " with question: " << newQuestion << std::endl;
    ptrCurrentNode->makeQuestion(newQuestion, newAnimal);
	saveTree(ptrRoot);
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

    // Use ordered_json to ensure keys like "text" appear before "yes"/"no"
    nlohmann::ordered_json j;

    // Explicitly call to_json to avoid implicit conversion errors
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

std::string cleanText(std::string fullText) {
    size_t closingBracket = fullText.find(']');
    if (closingBracket != std::string::npos && closingBracket + 2 < fullText.length()) {
		// Return the substring starting from two characters after the closing bracket to skip the "] " part
        return fullText.substr(closingBracket + 2);
    }
    return fullText;
}

void from_json(const nlohmann::ordered_json& j, Node*& ptrNode) {
    if (j.is_null()) {
        ptrNode = nullptr;
        return;
    }

    bool isQuestion = j.at("isQuestion").get<bool>();
    std::string fullText = j.at("text").get<std::string>();

	// Extract the actual text by removing the prefix [Level XXX] or [Animal XXX]
    std::string textOnly = cleanText(fullText);

	// Create the node with the cleaned text and question status
    ptrNode = new Node(textOnly, isQuestion);

	// Extract the level code from the text (the part between the brackets)
    size_t startPos = fullText.find(' ') + 1;
    size_t endPos = fullText.find(']');
    if (startPos != std::string::npos && endPos != std::string::npos && endPos > startPos) {
        ptrNode->levelCode = fullText.substr(startPos, endPos - startPos);
    }

	// Recursively load the "yes" and "no" branches if this node is a question
    if (isQuestion) {
        if (j.contains("yes")) from_json(j.at("yes"), ptrNode->yes);
        if (j.contains("no")) from_json(j.at("no"), ptrNode->no);
    }
}

Node* loadTree() {
	// Define the path to the archive file
    static const std::string ARCHIVE_PATH = "../../../data/animal_tree.json";

	// Attempt to open the file
    std::ifstream inputFile(ARCHIVE_PATH);

	// If the file doesn't exist, return nullptr to indicate that we should start with a default tree
    if (!inputFile.is_open()) {
        std::cout << "No existing backup found. Starting with default tree." << std::endl;
        return nullptr;
    }

	// Read the JSON content from the file into an ordered_json object
    nlohmann::ordered_json jsonObject;
    try {
        inputFile >> jsonObject;
        inputFile.close();
    }
    catch (nlohmann::json::parse_error& e) {
        std::cerr << "JSON Parse Error: " << e.what() << std::endl;
        inputFile.close();

        // If loading failed, create a default tree
        Node* ptrRoot = new Node("Is it a mammal?", true);
        ptrRoot->levelCode = "R"; // Root node level code

        ptrRoot->yes = new Node("Does it have fur?", true);
        ptrRoot->yes->levelCode = "R1"; // Level code for the "yes" branch of the root
        ptrRoot->yes->yes = new Node("Does it bark?", true);
        ptrRoot->yes->yes->levelCode = "R11"; // Level code for the "yes" branch of the "yes" branch of the root
        ptrRoot->yes->yes->yes = new Node("Dog", false);
        ptrRoot->yes->yes->yes->levelCode = "R111"; // Level code for the "yes" branch of the "yes" branch of the "yes" branch of the root
        ptrRoot->yes->yes->no = new Node("Cat", false);
        ptrRoot->yes->yes->no->levelCode = "R110"; // Level code for the "no" branch of the "yes" branch of the "yes" branch of the root
        ptrRoot->yes->no = new Node("Does it have a trunk?", true);
        ptrRoot->yes->no->levelCode = "R10"; // Level code for the "no" branch of the "yes" branch of the root
        ptrRoot->yes->no->yes = new Node("Elephant", false);
        ptrRoot->yes->no->yes->levelCode = "R101"; // Level code for the "yes" branch of the "no" branch of the "yes" branch of the root
        ptrRoot->yes->no->no = new Node("Dolphin", false);
        ptrRoot->yes->no->no->levelCode = "R100"; // Level code for the "no" branch of the "no" branch of the "yes" branch of the root

        ptrRoot->no = new Node("Does it fly?", true);
        ptrRoot->no->levelCode = "R0"; // Level code for the "no" branch of the root
        ptrRoot->no->yes = new Node("Does it have a beak?", true);
        ptrRoot->no->yes->levelCode = "R01"; // Level code for the "yes" branch of the "no" branch of the root
        ptrRoot->no->yes->yes = new Node("Eagle", false);
        ptrRoot->no->yes->yes->levelCode = "R011"; // Level code for the "yes" branch of the "yes" branch of the "no" branch of the root
        ptrRoot->no->yes->no = new Node("Bat", false);
        ptrRoot->no->yes->no->levelCode = "R010"; // Level code for the "no" branch of the "yes" branch of the "no" branch of the root
        ptrRoot->no->no = new Node("Does it have scales?", true);
        ptrRoot->no->no->levelCode = "R00"; // Level code for the "no" branch of the "no" branch of the root
        ptrRoot->no->no->yes = new Node("Snake", false);
        ptrRoot->no->no->yes->levelCode = "R001"; // Level code for the "yes" branch of the "no" branch of the "no" branch of the root
        ptrRoot->no->no->no = new Node("Frog", false);
        ptrRoot->no->no->no->levelCode = "R000"; // Level code for the "no" branch of the "no" branch of the "no" branch of the root

		saveTree(ptrRoot);
        return ptrRoot;
    }
    
	// Create a pointer for the root node and populate it using the from_json function
    Node* ptrRoot = nullptr;
    from_json(jsonObject, ptrRoot);

    std::cout << "Tree loaded successfully from: " << ARCHIVE_PATH << std::endl;

    return ptrRoot;
}

void cleanMemory(Node* root) {
    deleteTree(root);
	std::cout << "All memory cleaned up." << std::endl;
}
