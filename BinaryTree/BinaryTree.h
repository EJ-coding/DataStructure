#include "BinaryNode.h"

class BinaryTree
{
    BinaryNode* root;

public:
    BinaryTree(): root(NULL) {}
    void setRoot(BinaryNode* node)  { root = node;}
    BinaryNode* getRoot()           { return root;}
    bool isEmpty()                  { return root == NULL ;}

    //이진트리의 순회 연산
    //중위 순회 LVR 
    void inorder(){ 
        printf("\n inorder :");
        inorder(root);
    }
    void inorder(BinaryNode* node){
        if(node != NULL){
            inorder(node->getLeft());
            printf(" [%c]",node->getData());
            inorder(node->getRight());
        }
    }
    //전위 순회 VLR
    void preorder(){
        printf("\n prerder :");
        preorder(root);
    }
    void preorder(BinaryNode* node){
        if( node != NULL){
            printf("[%c]", node->getData());
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }
    //후위 순회 : LRV
    void postorder(){
        printf("\n postorder :");
        postorder(root);
    }
    void postorder(BinaryNode* node){
        if( node != NULL){
            preorder(node->getLeft());
            preorder(node->getRight());
            printf("[%c]", node->getData());
        }
    }
    //void levelorder()
};