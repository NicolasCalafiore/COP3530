//
// Created by Administrator on 6/13/2024.
//

#ifndef AVLPROJECT_TREENODE_H
#define AVLPROJECT_TREENODE_H

#include <string>

using namespace std;
class TreeNode{

public:
    string name;
    int id;
    TreeNode* right;
    TreeNode* left;
    int height;
    int balance;

    TreeNode(string name, int id):name(name), id(id), right(nullptr), left(nullptr), height(1), balance(0)
    {

    }

    int NumOfChildren(){
       int sum = 0;
       if(right != nullptr) sum++;
       if(left != nullptr) sum++;
       return sum;
    }
    bool isImbalancedRight(){
        return balance < -1;
    }
    bool isImbalancedLeft(){
        return balance > 1;
    }
    bool isLeftHeavy(){
        return balance > 0;
    }

    bool isRightHeavy(){
        return balance < 0;
    }
    void UpdateBalance(){
        this->balance = GetBalance(this);
    }

    void UpdateHeight(){
        this->height = GetHeight(this);
    }

    void PrintDetails(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Height: " << height << endl;
        cout << "Balance: " << balance << endl << endl;
    }

    TreeNode* GetInOrderSuccessor(){
        return GetInOrderSuccessor(this->right);
    }


private:

    TreeNode* GetInOrderSuccessor(TreeNode* node){
        if(node->left == nullptr){
            return node;
        }
        else return GetInOrderSuccessor(node->left);
    }

    int GetBalance (TreeNode* node){
        if(node == nullptr) return 0;
        int right = 1 + GetHeight(node->right);
        int left = 1 + GetHeight(node->left);
        return left - right;
    }
    int GetHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int right = 1 + GetHeight(node->right);
        int left = 1 + GetHeight(node->left);
        return max(right, left);
    }

};
#endif //AVLPROJECT_TREENODE_H
