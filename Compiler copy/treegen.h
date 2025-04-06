#ifndef PARSER_H
#define PARSER_H
#include "scanner.h"

struct Node {
    std::string value;
    Node* left;
    Node* right;
};

Node* parse(const std::vector<Token>& tokens);
#endif