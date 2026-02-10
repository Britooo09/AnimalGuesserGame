#include "../include/programLogic.h"
#include "../include/node.h"


void play() {

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
    inputFile >> jsonObject;
    inputFile.close();

	// Create a pointer for the root node and populate it using the from_json function
    Node* ptrRoot = nullptr;
    from_json(jsonObject, ptrRoot);

    std::cout << "Tree loaded successfully from: " << ARCHIVE_PATH << std::endl;

    return ptrRoot;
}

void cleanMemory() {

}
