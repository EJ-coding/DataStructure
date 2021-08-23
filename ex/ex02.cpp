#include <iostream>

using namespace std;
//정수 2개의 참조(reference)를 인자로 받아서 값을 서로 바꿔주는 swap 함수를 작성하세요.
//call by reference로 a,b에 각각 참조자 num1,num2로 둬서 값자채를 바꾼다.
void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){ 
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}