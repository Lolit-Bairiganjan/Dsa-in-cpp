#include <iostream>
using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftNode;
    treeNode* rightNode;

    treeNode(int val){
        data = val;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

class bst{
private:
    treeNode* root;

public:
    bst(){ root = nullptr; }

    treeNode* insertHelper(int val, treeNode* node){
        if(node == nullptr) return new treeNode(val);

        treeNode* curr = node;
        treeNode* parent = nullptr;
        while(curr != nullptr){
            parent = curr;
            if(val < curr->data) curr = curr->leftNode;
            else curr = curr->rightNode;
        }
        if(val < parent->data) parent->leftNode = new treeNode(val);
        else parent->rightNode = new treeNode(val);
        return node;
    }

    treeNode* searchHelper(int val, treeNode* node){
        if(node == nullptr || node->data == val) return node;
        if(val < node->data) return searchHelper(val, node->leftNode);
        else return searchHelper(val, node->rightNode);
    }

    treeNode* deleteHelper(int val, treeNode* node){
        node = search(val);
        
    }

    void insert(int val){
        root = insertHelper(val, root);
    }

    treeNode* search(int val){
        return searchHelper(val, root);
    }

    treeNode* deleteNode(int val){
        return deleteHelper(val, root);
    }
};

int main(){
    bst bst1;
    bst1.insert(3);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(5);
    bst1.insert(6);
    bst1.insert(4);

    treeNode* searchedItem = bst1.search(8);
    cout << searchedItem->data << endl;

    return 0;
}
