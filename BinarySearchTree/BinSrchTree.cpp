#include "BinSrchTree.h"
/*
                           35
            18                        68
        7         26                        99
      3   12   22   30
*/

int main(){
    BinSrchTree tree;

    tree.insert( new BinaryNode(35));
    tree.insert( new BinaryNode(18));
    tree.insert( new BinaryNode(7));
    tree.insert( new BinaryNode(26));
    tree.insert( new BinaryNode(12));
    tree.insert( new BinaryNode(3));
    tree.insert( new BinaryNode(22));
    tree.insert( new BinaryNode(30));
    tree.insert( new BinaryNode(68));
    tree.insert( new BinaryNode(99));

    printf("노드의 개수 : %d\n", tree.getCount());
    printf("단말의 개수 : %d\n", tree.getLeafCount());

    tree.levelorder();// 트리순회

    //노드 탐색
    tree.search(26);
    tree.search(25);
    //삭제연산
    printf("case1 : 노드 3 삭제\n");
    tree.remove(3);
    tree.levelorder();//level순회로 트리확인

    printf("case2 : 노드 68 삭제\n");
    tree.remove(68);
    tree.levelorder();//level순회로 트리확인

    printf("case3 : 노드 18 삭제\n");
    tree.remove(18);
    tree.levelorder();//level순회로 트리확인

    printf("case3 : 노드 35 삭제\n");
    tree.remove(35);
    tree.levelorder();//level순회로 트리확인


    printf("노드의 개수 : %d\n", tree.getCount());
    printf("단말의 개수 : %d\n", tree.getLeafCount());
}