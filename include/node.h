#pragma once
#include <string>

class Node {
public:
    std::string text;
    bool isQuestion;
    Node* yes;
    Node* no;

    Node(std::string t, bool q);
    void makeQuestion(std::string question, std::string newLeaf);
};
