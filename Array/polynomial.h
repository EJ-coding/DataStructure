#include <iostream>

using namespace std;

class Polynomial{
    public:
        Polynomial(){
            capacity = 1;
            terms = 0;
            termArray = new termArray[capacity] = {1};
        }
        ~Polynomial(){
            delete []termArray;
        }

    private:
        Term *termArray; //0이 아닌 항의 배열
        int capacity; // TermArray의 크기
        int terms; //0이 아닌 항의 수 


    class Term{
        friend Polynomial;
        private :
            float coef; // 계수
            int exp; // 지수 
    }
};

