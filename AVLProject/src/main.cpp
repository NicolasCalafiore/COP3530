#include <iostream>
#include "AVLTree.h"
#include "TreeNode.h"
#include <vector>
#include <string>
#include <sstream>

/* Note:
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope.
*/

//AVL TreeNode struct/class - student info, left/right children, height, constructor
//AVLTree class - build/maintain/search/traverse functions, constructor, destructor
// Given - # of lines (commands), commands, | SAMPLE: insert "Brandon" 45679999
//Main function requires instance of AVLTree class

//INSERT - SAMPLE: "insert NAME(string) ID(INT)" | Traverse to correct spot and insert, check if unbalanced, perform rotations and update height
//              print "successful" or "unsuccessful"
//REMOVE - SAMPLE: "remove ID(INT)" | BALANCING NOT REQUIRED | Ensure ID exists | IN-ORDER SUCESSOR = smallest value in the current nodes right subtree
//REMOVE IN ORDER - SAMPLE "removeInorder N(INT)" | Remove Nth node from inorder traversal | print
//              "unsuccessful" or "successful" | BALACNING NOT REQUIRED | N = 0 for first node
//PARSING - REGEX MAY BE USEFUL? | one getline(cin, line) | istringstream in(line) may be useful
// INSERT --> TRAVERSE --> SEARCH --> REMOVE
//Organize by UFID not by Alphabet

using namespace std;

void InitializeCommands(vector<string>& commands, string input);
void Insert(vector<string>& commands, AVLTree& tree);
void Remove(vector<string>& commands, AVLTree& tree);
void Search(vector<string>& commands, AVLTree& tree);
void Inorder(vector<string>& commands, AVLTree& tree);
void Preorder(vector<string>& commands, AVLTree& tree);
void Postorder(vector<string>& commands, AVLTree& tree);
void LevelCount(vector<string>& commands, AVLTree& tree);
void RemoveInOrder(vector<string>& commands, AVLTree& tree);
bool IsValidID(int ID);
bool IsOnlyAlphabetical(string& name);
bool isNumber(string id_str);
void CleanName(string& name);
int main(){

    AVLTree tree;

    int numOfCommands;
    string input;
    string word;
    vector<string> commands;

    getline(cin, input);
    numOfCommands = stoi(input);

    for(int i = 0; i < numOfCommands; i++){
        getline(cin, input);
        InitializeCommands(commands, input);

        if(commands[0] == "insert") Insert(commands, tree);
        else if(commands[0] == "remove") Remove(commands, tree);
        else if(commands[0] == "search") Search(commands, tree);
        else if(commands[0] == "printInorder") Inorder(commands, tree);
        else if(commands[0] == "printPreorder") Preorder(commands, tree);
        else if(commands[0] == "printPostorder") Postorder(commands, tree);
        else if(commands[0] == "printLevelCount") LevelCount(commands, tree);
        else if(commands[0] == "removeInorder") RemoveInOrder(commands, tree);
        else cout << "unsuccessful" << endl;
    }
	return 0;
}

void InitializeCommands(vector<string>& commands, string input){
    commands.clear();
    string token;
    bool inQuotes = false;
    stringstream currentToken;

    for (char c : input) {
        if (c == '\"') {
            inQuotes = !inQuotes;
            currentToken << c;
        } else if (c == ' ' && !inQuotes) {
            if (!currentToken.str().empty()) {
                commands.push_back(currentToken.str());
                currentToken.str("");
                currentToken.clear();
            }
        } else {
            currentToken << c;
        }
    }

    if (!currentToken.str().empty()) {
        commands.push_back(currentToken.str());
    }
}

void Insert(vector<string>& commands, AVLTree& tree){
    string name = commands[1];
    string id_str = commands[2];

    if(isNumber(id_str) && IsValidID(stoi(id_str)) && IsOnlyAlphabetical(name)) {
        CleanName(name);
        tree.Insert(name, stoi(id_str));
    }
    else cout << "unsuccessful" << endl;
}
void Remove(vector<string>& commands, AVLTree& tree){
    string id_str = commands[1];

    if(IsValidID(stoi(id_str)))
        tree.RemoveID(stoi(id_str));
    else cout << "unsuccessful" << endl;
}
void Search(vector<string>& commands, AVLTree& tree){
    string target = commands[1];

    try{
        int ID = stoi(target);
        tree.SearchID(ID);
    }
    catch(exception e){
        CleanName(target);
        tree.SearchName(target);
    }

}
void Inorder(vector<string>& commands, AVLTree& tree){
    tree.PrintInOrder();
}
void Preorder(vector<string>& commands, AVLTree& tree){
    tree.PrintPreOrder();
}
void Postorder(vector<string>& commands, AVLTree& tree){
    tree.PrintPostOrder();
}
void LevelCount(vector<string>& commands, AVLTree& tree){
    tree.PrintLevelCount();
}
void RemoveInOrder(vector<string>& commands, AVLTree& tree){
    string target = commands[1];
    if(isNumber(target))
        tree.removeInOrder(stoi(target));
    else cout << "unsuccessful" << endl;
}

bool IsValidID(int ID) {
    bool valid = (ID >= 10000000 && ID <= 99999999);
    return valid;
}
bool IsOnlyAlphabetical(string& name) {
    for (auto i : name) {
        if (!isalpha(i)) {
            if (i != '"' && i != ' ') {
                return false;
            }
        }
    }
    return true;
}
bool isNumber(string id_str) {
    for (char c : id_str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
void CleanName(string& name){
    name.erase(0, 1);
    name.erase(name.size() - 1, 1);
}


