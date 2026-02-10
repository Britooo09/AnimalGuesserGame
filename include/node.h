#pragma once
#include "../include/json.hpp"
#include <string>

class Node {
public:
    std::string text;
    bool isQuestion;
    std::string levelCode;
    Node* yes;
    Node* no;

    Node(std::string t, bool q);
    void makeQuestion(std::string question, std::string newLeaf);
};
