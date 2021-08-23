#include "CircularQueue.h"

class BinaryTree
{
    BinaryNode* root;

public:
    BinaryTree(): root(NULL) {}
    void setRoot(BinaryNode* node)  { root = node;}
    BinaryNode* getRoot()           { return root;}
    bool isEmpty()                  { return root == NULL ;}

    //트리 노드 개수 구하는 함수
    int getCount()                  { return isEmpty()? 0: getCount(root);}
    //순환 호출에 의해 node를 루트로하는 서브트리의 노드 수 계산
    int getCount(BinaryNode* node){
        if(node == NULL) return 0;
        return 1+getCount(node->getLeft())+getCount(node->getRight());
    }
    //트리의 단말노드 개수 구하기
    int getLeafCount()              { return isEmpty()? 0 : getLeafCount(root);}
    //재귀 호출통해 node를 루트로 하는 서비트리의 단말 노드 수 계산
    int getLeafCount(BinaryNode* node){
        if( node == NULL) return 0;
        if ( node->isLeaf()){
            return 1;
        }else{
            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
        }
    }

    //트리의 높이를 구하는 함수
    int getHeight()                 { return isEmpty()? 0 : getHeight(root);}
    int getHeight(BinaryNode* node){
        if(node == NULL)    return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? hLeft+1: hRight+1;
    }

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
    //래밸순환탐색
    void levelorder(){
        printf("\nlevel order: ");
        if(!isEmpty()){
            CircularQueue q;
            q.enqueue(root);
            while( !q.isEmpty()){
                BinaryNode* n = q.dequeue();
                if(n!=NULL){
                    printf("[%c]",n->getData());
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        printf("\n");
    }
};