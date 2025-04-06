#include "treegen.h"
#include <stack>
#include <map>

int precedence(const std::string& op) {
    if (op == "^") return 3;
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
}

// Simple parser for expressions using Shunting Yard
Node* parse(const std::vector<Token>& tokens) {
    std::stack<Node*> operands;
    std::stack<std::string> operators;

    // Handle function definition: FUNC LPAREN VARIABLE RPAREN ASSIGN
    if (tokens.size() > 5 &&
        tokens[0].type == FUNC &&
        tokens[1].type == LPAREN &&
        tokens[2].type == VARIABLE &&
        tokens[3].type == RPAREN &&
        tokens[4].type == ASSIGN) {
        
        Node* funcNode = new Node{tokens[0].value, nullptr, new Node{tokens[2].value, nullptr, nullptr}};
        // Now parse the rest of the expression (from tokens[5] onwards)
        std::vector<Token> exprTokens(tokens.begin() + 5, tokens.end());
        Node* exprTree = parse(exprTokens);  // Recursive call
        return new Node{"=", funcNode, exprTree};
    }

    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token& tok = tokens[i];
    
        if (tok.type == NUMBER || tok.type == VARIABLE) {
            operands.push(new Node{tok.value, nullptr, nullptr});
    
        } else if (tok.type == OPERATOR) {
            while (!operators.empty() && operators.top() != "(" &&
                   precedence(operators.top()) >= precedence(tok.value)) {
                std::string op = operators.top(); operators.pop();
                Node* right = operands.top(); operands.pop();
                Node* left = operands.top(); operands.pop();
                operands.push(new Node{op, left, right});
            }
            operators.push(tok.value);
    
        } else if (tok.type == LPAREN) {
            operators.push(tok.value);  // push "(" as-is
    
        } else if (tok.type == RPAREN) {
            while (!operators.empty() && operators.top() != "(") {
                std::string op = operators.top(); operators.pop();
                Node* right = operands.top(); operands.pop();
                Node* left = operands.top(); operands.pop();
                operands.push(new Node{op, left, right});
            }
            if (!operators.empty() && operators.top() == "(") {
                operators.pop();  // pop the matching "("
            }
        }
    }
    

    while (!operators.empty()) {
        Node* right = operands.top(); operands.pop();
        Node* left = operands.top(); operands.pop();
        operands.push(new Node{operators.top(), left, right});
        operators.pop();
    }

    return operands.empty() ? nullptr : operands.top();
}
