#include <iostream>
#include "ArrayStack.h"

int main(){
    ArrayStack stack;
    for(int i =1 ; i< 11 ; i++){
        stack.push(i);//10개의 데이터를 스택에 넣는다.
    }
    stack.display();
    stack.pop();
    stack.pop();
    stack.display(); //2개를 비우고 난 뒤 결과
}