#ifndef AVLPROJECT_AVLTREE_H
#define AVLPROJECT_AVLTREE_H

#include "TreeNode.h"
#include <string>
#include <iostream>
#include <vector>

class AVLTree {
public:
    TreeNode* root;

    AVLTree() : root(nullptr) {}

    void Insert(const std::string& name, int ID) {
        if (SearchID(ID, root)) {
            std::cout << "unsuccessful" << std::endl;
            return;
        }

        root = Insert(name, ID, root);
        std::cout << "successful" << std::endl;
    }

    void PrintInOrder() {
        vector<string> names;
        InOrderNames(root, names);
        PrintNames(names);
    }

    void PrintPostOrder() {
        vector<string> names;
        PostOrderNames(root, names);
        PrintNames(names);
    }

    void PrintPreOrder() {
        vector<string> names;
        PreOrderNames(root, names);
        PrintNames(names);
    }


    void RemoveID(int id) {
        bool success;
        root = RemoveID(id, root, success);
        if (success) {
            std::cout << "successful" << std::endl;
        } else {
            std::cout << "unsuccessful" << std::endl;
        }
    }

    void SearchID(int id) {
        if (SearchID(id, root)) {

        } else {
            std::cout << "unsuccessful" << std::endl;
        }
    }

    void SearchName(const std::string& name) {
        if (!SearchName(name, root)) {
            std::cout << "unsuccessful" << std::endl;
        }
    }

    void PrintLevelCount() {
        if (root == nullptr)
            std::cout << "0" << std::endl;
        else
            std::cout << root->height << std::endl;
    }

    void removeInOrder(int target) {
        int count = 0;
        bool success;
        root = removeInOrder(target, count, root, success);
        if (success) {
            std::cout << "successful" << std::endl;
        } else {
            std::cout << "unsuccessful" << std::endl;
        }
    }

private:

    void PrintNames(vector<string>& names){
        for(int i = 0; i < names.size(); i++){
            if(i == names.size() - 1) cout << names[i] << endl;
            else cout << names[i] << ", ";

        }
    }

    TreeNode* removeInOrder(int target, int& count, TreeNode* node, bool& success) {
        if (node == nullptr) {
            success = false;
            return nullptr;
        }

        node->left = removeInOrder(target, count, node->left, success);

        if (success) {
            UpdateHeightAndBalance(node);
            return Rebalance(node);
        }

        if (count == target) {
            success = true;
            return RemoveNode(node);
        }
        count++;

        node->right = removeInOrder(target, count, node->right, success);

        if (node != nullptr) {
            UpdateHeightAndBalance(node);
            return Rebalance(node);
        }

        return node;
    }

    bool SearchName(const std::string& name, TreeNode* node) {
        if (node == nullptr) return false;
        if (node->name == name) {
            std::cout << node->id << std::endl;
            return true;
        }

        return SearchName(name, node->left) || SearchName(name, node->right);
    }

    bool SearchID(int id, TreeNode* node) {
        if (node == nullptr) return false;
        if (node->id == id){
            cout << node->name << endl;
            return true;
        }

        if (node->id > id) return SearchID(id, node->left);
        if (node->id < id) return SearchID(id, node->right);
        return false;
    }

    TreeNode* RemoveID(int id, TreeNode* node, bool& success) {
        if (node == nullptr) {
            success = false;
            return nullptr;
        }

        if (node->id == id) {
            success = true;
            return RemoveNode(node);
        } else {
            if (node->id > id) {
                node->left = RemoveID(id, node->left, success);
            } else {
                node->right = RemoveID(id, node->right, success);
            }
            if (node != nullptr) {
                UpdateHeightAndBalance(node);
                return Rebalance(node);
            }
        }
        return node;
    }

    TreeNode* Insert(const std::string& name, int ID, TreeNode* node) {
        if (node == nullptr) {
            return new TreeNode(name, ID);
        }

        if (ID < node->id) {
            node->left = Insert(name, ID, node->left);
        } else {
            node->right = Insert(name, ID, node->right);
        }

        UpdateHeightAndBalance(node);
        return Rebalance(node);
    }

    TreeNode* Rebalance(TreeNode* node) {
        if (node->isImbalancedRight()) {
            if (node->right->isLeftHeavy()) {
                node->right = RotateRight(node->right);
                return RotateLeft(node);
            } else {
                return RotateLeft(node);
            }
        }
        if (node->isImbalancedLeft()) {
            if (node->left->isRightHeavy()) {
                node->left = RotateLeft(node->left);
                return RotateRight(node);
            } else {
                return RotateRight(node);
            }
        }
        return node;
    }

    TreeNode* RotateLeft(TreeNode* node) {
        TreeNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        UpdateHeightAndBalance(node);
        UpdateHeightAndBalance(newRoot);

        return newRoot;
    }

    TreeNode* RotateRight(TreeNode* node) {
        TreeNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        UpdateHeightAndBalance(node);
        UpdateHeightAndBalance(newRoot);

        return newRoot;
    }

    TreeNode* RemoveNode(TreeNode* node) {
        if (node->NumOfChildren() == 0) {
            delete node;
            return nullptr;
        } else if (node->NumOfChildren() == 1) {
            TreeNode* child = (node->left != nullptr) ? node->left : node->right;
            delete node;
            return child;
        } else {
            if (node->right->left != nullptr) {
                TreeNode* parent = node;
                TreeNode* inOrderSuccessor = node->right;
                while (inOrderSuccessor->left != nullptr) {
                    parent = inOrderSuccessor;
                    inOrderSuccessor = inOrderSuccessor->left;
                }

                if (parent != node) {
                    parent->left = inOrderSuccessor->right;
                    inOrderSuccessor->right = node->right;
                }
                inOrderSuccessor->left = node->left;

                delete node;
                return inOrderSuccessor;
            } else {
                TreeNode* newRoot = node->right;
                newRoot->left = node->left;
                delete node;
                return newRoot;
            }
        }
    }

    void UpdateHeightAndBalance(TreeNode* node) {
        if (node == nullptr) return;
        node->UpdateHeight();
        node->UpdateBalance();
    }

    void InOrderNames(TreeNode* node, vector<string>& names) {
        if (node == nullptr) return;
        InOrderNames(node->left, names);
        names.push_back(node->name);
        InOrderNames(node->right, names);
    }

    void PreOrderNames(TreeNode* node, vector<string>& names) {
        if (node == nullptr) return;
        names.push_back(node->name);
        PreOrderNames(node->left, names);
        PreOrderNames(node->right, names);
    }

    void PostOrderNames(TreeNode* node, vector<string>& names) {
        if (node == nullptr) return;
        PostOrderNames(node->left, names);
        PostOrderNames(node->right, names);
        names.push_back(node->name);
    }
};

#endif //AVLPROJECT_AVLTREE_H
