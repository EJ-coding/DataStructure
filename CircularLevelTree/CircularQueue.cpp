#include "BinaryTree.h"

/*
        A
   B       C
D     E   F
*/

int main(){
    BinaryTree tree;
    BinaryNode* d =new BinaryNode('D',NULL,NULL);
    BinaryNode* e =new BinaryNode('E',NULL,NULL);
    BinaryNode* b =new BinaryNode('B',d,e);
    BinaryNode* f =new BinaryNode('F',NULL,NULL);
    BinaryNode* c =new BinaryNode('C',f,NULL);
    BinaryNode* a =new BinaryNode('A',b,c);

    tree.setRoot(a);
    tree.levelorder(); 
    printf("Number of node : %d\n",tree.getCount());
    printf("Number of leaf node : %d\n",tree.getLeafCount());
    printf("Height of Tree : %d \n", tree.getHeight());

}