#include "BinaryTree.h"
//이진 탐색트리는 이진트리를 상속받음
class BinSrchTree : public BinaryTree
{

public:
    BinSrchTree(void) {}
    ~BinSrchTree(void) {}

    //키 값으로 노드를 순환하여 탐색 ,재귀함수호출 비효율적일 수 있음
    //n을 루트로 갖는 서브트리에서 key값을 갖는 노드 탐색
    BinaryNode* searchRecur(BinaryNode* n, int key){
        if( n == NULL) return NULL;
        if(key == n->getData()){
            return n;
        }else if(key < n->getData()){
            return searchRecur(n->getLeft(),key);
        }else{
            return searchRecur(n->getRight(),key);
        }
        
    }
    /*
   //노드 클래스의 멤버로 구현(일반함수가 아님)
   BinaryNode* BinaryNode::search(int key){
       if(key == data){
           return data;
       }else if( key < data && left!=NULL){
           return left->search(key);
       }else if( key > data && right!=NULL){
           return right->search(key);
       }else{
           return NULL;
       }
   }
   */
    //이진탐색트리 삽입  root로 부터 새로운 노드n삽입
    void insertRecur(BinaryNode* r,BinaryNode* n){
        if( n->getData() == r->getData()){
            return;//같은 숫자는 삽입불가
        }else if( n->getData() < r->getData()){
            if(r->getLeft() == NULL){//왼쪽 노드 비었으면 삽입
                r->setLeft(n);
            }else{
                insertRecur(r->getLeft(),n);
            }
        }else{//삽입할 숫자가 현재 data보다 클경우
            if(r->getRight() == NULL){
                r->setRight(n);//오른쪽 노드 비었으면 삽입
            }else{
                insertRecur(r->getRight(),n);
            }
        }
    }
    //이진탐색트리의 삭제 : 삭제할 node의 부모노드와 삭제할 node
    void remove(BinaryNode* parent, BinaryNode* node){
        if(node->isLeaf()){ //case1: 삭제하려는 노드가 단말노드일 경우
            //부모노드가 단말노드일경우 ,node == root일경우
            if(parent==NULL){
                root=NULL; //공백상태
            }else{
                if( parent->getLeft() == node){
                    parent->setLeft(NULL);
                }else{
                    parent->setRight(NULL);
                }
            }
        }else if( node->getLeft() == NULL || node->getRight() == NULL){ //case2: 삭제하려는 노드가 왼쪽이나 오른쩍 자식만 갖는경우
            //삭제할 노드의 유일한 자식노드 : child
            BinaryNode* child =(node->getLeft()!=NULL)? node->getLeft(): node->getRight();
            //삭제할 노드가 root이면 자식노드가 root됨
            if(node == root) {
                root = child;
            }else{
                if(parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);
            }
        }else{//case3: 삭제하려는 노드가 두개의 서브트리를 갖는경우
            //삭제하려는 노드의 오른쪽 서브트리에서 가장 노드를 탐색
            //succ : 후계노드(오른쪽 서브트리에서 key가 가장 작은 노드)
            //succp(succeed parent) : 후계노드의 부모 노드
            BinaryNode* succp = node; //처음엔 삭제할 노드를 후계노드의 부모로 둔다.
            BinaryNode* succ = node->getRight(); // 후계노드를 삭제노드의 오른쪽 노드로 두고 탐색한다.
            while(succ->getLeft() != NULL){ //후계노드 탐색
                succp = succ;//후계노드의 부모를 오른쪽 노드로 내려가서 탐색
                succ = succp->getLeft();//후계노드
            }
            //후계 노드의 부모와 후계 노드의 오른쪽 자식을 연결
            if(succp->getLeft() == succ){//후계노드 부모의 왼쪽노드가 후계노드일경우:탐색성공했을경우
                succp->setLeft(succ->getRight());
            }else{ //후계노드가 삭제할 노드의 바로 오른쪽 자식일 경우(후계노드는 왼쪽 자식이 없고 오른쪽 자식만 있을경우)
                succp->setRight(succ->getRight());//NULL
            }
            //후계 노드 정보를 삭제할 노드에 복사
            node->setData(succ->getData());
            //삭제할 노드를 후계노드로 변경: 후계노드삭제
            node = succ;

        }
        delete node;//메모리 동적 해제
    }
    //이진탐색 트리의 탐색연산
    BinaryNode* search(int key){
        BinaryNode* node = searchRecur(root, key);
        if( node != NULL){
            printf("탐색 성공: 키값이 %d인 노드  = 0x%x\n",node->getData(),node);
        }else{
            printf("탐색 실패 : 키값이 %d 인 노드 없음\n",key);
        }
        return node;

    }

    //이진 탐색트리의 삽입연산
    void insert(BinaryNode* n){
        if( n == NULL)  return;
        if( isEmpty())  
            root = n;
        else   
            insertRecur(root,n);

    }

    //이진 탐색 트리의 삭제연산
    void remove(int key){
        if(isEmpty())
            return;
        //삭제할 노드와 삭제노드의 부모노드를 찾는다.
        BinaryNode* parent = NULL;
        BinaryNode* node = root; //삭제할 노드
        while( node != NULL && node->getData() != key){
            parent = node;
            node = (key < node->getData())? node->getLeft() : node->getRight();

            //없앨 노드가 트리에 없을 때
            if(node == NULL){
                printf("Error: key is not in the tree..\n");
                return;
            }
            //없앨 노드가 트리에 있음
            else{
                remove(parent,node);//삭제연산시작
            }
        }

    }

};