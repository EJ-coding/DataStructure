#include "StudentStack.h"

int main(){
    StudentStack stack;
    stack.push( Student(20170001,"가나다", "컴퓨터학부"));
    stack.push( Student(20180003, "라마바", "컴퓨터학부"));
    stack.push( Student(20170231,"사아자", "컴퓨터학부"));
    
    stack.display();
    stack.pop();
    stack.display();

}
