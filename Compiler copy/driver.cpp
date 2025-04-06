#include <iostream>
#include <fstream>
#include <vector>
#include "scanner.h"
#include "treegen.h"
#include "logiccheck.h"
#include "midgen.h"
#include "finalgen.h"

using namespace std;

int main() {
    // file read
    ifstream infile("input.txt");

    if (!infile) {
        cerr << "Error: Cannot open input.txt\n";
        return 1;
    }

    string code((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
    infile.close();
    cout << "Input file read successfully.\n";

    //LA
    vector<Token> newToken = tokenize(code);
    if (newToken.empty()) {
        cerr << "Error: No newToken generated\n";
        return 1;
    }
    cout<<"newToken (" << newToken.size()<<") :\n";
    for(const auto& t : newToken){
        cout<<"Type : "<<t.type<<", Value : "<<t.value<<"\n";
    }
    cout << "Lexical analysis completed. newToken: " << newToken.size() << "\n";

    //Parsing
    Node* ast = parse(newToken);
    if (!ast) {
        cerr << "Error: Parser failed\n";
        return 1;
    }
    cout << "Parsing successful.\n";

    //semantic analysis
    try {
        semanticCheck(ast);
        cout << "Semantic analysis passed.\n";
    } catch (const exception& e) {
        cerr << "Semantic Error: " << e.what() << "\n";
        return 1;
    }

    // ICG
    vector<string> tac = generate3AC(ast);
    if (tac.empty()) {
        cerr << "Error: No intermediate code generated\n";
        return 1;
    }
    for(const auto& line : tac){
        cout<<line<<"\n";
    }
    cout << "3-address code (TAC) generation completed.\n";

    // 6. Generate assembly output
    string outputPath = "output.asm";
    ofstream asmfile(outputPath);
    if (!asmfile) {
        cerr << "Error: Cannot create output.asm\n";
        return 1;
    }

    generateAssembly(tac, asmfile);
    asmfile.close();
    cout << "Assembly code written to output.asm\n";

    // 7. Verify output
    ifstream check(outputPath);
    if (!check) {
        cerr << "Error: Output file not found\n";
        return 1;
    }
    check.close();

    cout << "Successfully created output.txt\n";
    return 0;
}
