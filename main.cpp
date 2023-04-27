#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
unordered_set<string> keywords {
    "auto", "double", "int", "struct",
    "break", "else", "long", "switch",
    "case", "enum", "register", "typedef",
    "char", "extern", "return", "union",
    "const", "short", "float", "unsigned",
    "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "volatile",
    "do", "if", "static", "while"
};

unordered_set<string> operators {
    "+", "-", "*", "/", "%", "<", ">", "=",
    "==", "!=", ">=", "<="
};
unordered_set<char> delimiters {
    ',', ';', '(', ')', '{', '}'
};

void tokenization(string assembly_language_program) {
    vector<string> tokens;
    string tokenize;
    int i = 0;
    while (i < assembly_language_program.size()) {
       
        while (i < assembly_language_program.size() && isspace(assembly_language_program[i])) {
            i++;
        }
        
        tokenize = "";
        while (i < assembly_language_program.size() && isalnum(assembly_language_program[i])) {
            tokenize += assembly_language_program[i];
            i++;
        }
        if (!tokenize.empty()) {
            if (keywords.count(tokenize)) {
                cout << "Lexeme of keywords: " << tokenize << endl;
            } else {
                cout << "Lexeme of variables: " << tokenize << endl;
            }
            continue;
        }
        
        if (assembly_language_program[i] == '"') {
            tokenize = "";
            i++;
            while (i < assembly_language_program.size() && assembly_language_program[i] != '"') {
                tokenize += assembly_language_program[i];
                i++;
            }
            i++;
            cout << "Lexeme of literals: " << "\"" << tokenize << "\"" << endl;
            continue;
        }
        
        tokenize = "";
        while (i < assembly_language_program.size() && operators.count(tokenize + assembly_language_program[i])) {
            tokenize += assembly_language_program[i];
            i++;
        }
        if (!tokenize.empty()) {
            cout << "Lexeme of operator: " << tokenize << endl;
            continue;
        }
       
        tokenize = "";
        while (i < assembly_language_program.size() && isdigit(assembly_language_program[i])) {
            tokenize += assembly_language_program[i];
            i++;
        }
        if (!tokenize.empty()) {
            cout << "Lexeme of constants: " << tokenize << endl;
            continue;
        }
       
        if (delimiters.count(assembly_language_program[i])) {
            cout << "Lexeme of special symbols or delimiters: " << assembly_language_program[i] << endl;
            i++;
            continue;
        }
        
        i++;
    }
}

int main() {
    string assembly_language_program;
    cout << "Enter Program $ for termination:" << endl;
    getline(cin, assembly_language_program, '$');
    tokenization(assembly_language_program);
    return 0;
}
