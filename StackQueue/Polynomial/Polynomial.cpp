#include <iostream>

using namespace std;

 

template <typename T> class Chain;

 

template <typename T>

class ChainNode

{

private:

        T data;

        ChainNode<T> *link;

public:

        ChainNode(T element = 0, ChainNode *next = NULL) :data(element), link(next)

        {

        }

        T getData()

        {

               return data;

        }

        ChainNode *Link()

        {

               return link;

        }

        friend class Chain<T>;

        template <typename T>

        friend ostream &operator<<(ostream &os, Chain<T> &c); //출력

};

 

template <typename T>

class Chain

{

private:

        ChainNode<T> *first;

        ChainNode<T> *last;

public:

        Chain()

        {

               first = NULL;

        }

        ChainNode<T> *getFirst() //처음 노드 반환

        {

               return first;

        }

        ChainNode<T> *Insert(ChainNode<T> *x, T i) //노드 추가

        {

               if (first)

               {

                       ChainNode<T> *temp = new ChainNode<T>(i, x->link);

                       x->link = temp; //x가 temp를 가르키도록

                       return x->link; //위치를 반환해야 그 다음 위치에 값을 대입

               }

               else //기존 노드가 없을 경우

               {

                       first = new ChainNode<T>(i);

                       return first;

               }

        }

        int Length()

        {

               int len = 0;

               ChainNode *temp = first;

 

               while (temp != NULL)

               {

                       temp = temp->link;

                       len++;

               }

               return len;

        }

        void Delete(ChainNode<T> *x)

        {

               if (first == NULL)

               {

                       cout << "체인은 비어있다" << endl;

                       return;

               }

               if (x == first)

                       first = first->link; //다음 노드를 가리킨다

               else

               {

                       ChainNode<T> *temp = first;

                       while (temp->link != x)

                       {

                              temp = temp->link; //x 전 노드를 찾아간다

                       }

                       temp->link = x->link; //x 다음을 temp와 연결시켜 자연스럽게 x가 없어지도록 한다

               }

               delete x;

        }

        void InsertBack(const T &item)

        {

               if (first)

               {

                       last->link = new ChainNode<T>(item);

                       last = last->link;

                       last->link = NULL;

               }

               else

               {

                       first = last = new ChainNode<T>(item);

                       first->link = NULL;

               }

        }

        void Concatenate(Chain<T> &b) //합치다

        {

               if (first)

               {

                       last->link = b.first;

                       last = b.last;

               }

               else

               {

                       first = b.first;

                       last = b.last;

               }

        }

        void Reverse() //거꾸로

        {

               ChainNode<T> *current = first, *previous = NULL; //previous는 current 전 노드

 

               while (current)

               {

                       ChainNode<T> *r = previous; //previous의 위치를 기억해두었다가

                       previous = current;

                       current = current->link;

                       previous->link = r; //이전의 current가 이전의 previous를 가르키도록 한다

               }

               first = previous;

        }

        class ChainIterator

        {

        private:

               ChainNode<T> *current;

        public:

               ChainIterator(ChainNode<T> *startNode = NULL)

               {

                       current = startNode;

               }

               T getData()

               {

                       return current->data;

               }

               T &operator*() const

               {

                       return current->data;

               }

               T *operator->()

               {

                       return &current->data;

               }

               ChainIterator &operator++() //++c

               {

                       current = current->link;

                       return *this;

               }

               ChainIterator operator++(int) //c++

               {

                       ChainIterator old = *this;

                       current = current->link;

                       return old;

               }

               bool operator!=(const ChainIterator right) const

               {

                       return current != right.current;

               }

               bool operator==(const ChainIterator right) const

               {

                       return current = right.current;

               }

               bool operator&&(const ChainIterator right) const

               {

                       return current && right.current;

               }

               template <typename T>

               friend ostream &operator<<(ostream &os, Chain<T> &c); //출력

        };

        ChainIterator begin()

        {

               return ChainIterator(first);

        }

        ChainIterator end()

        {

               return ChainIterator(0);

        }

        template <typename T>

        friend ostream &operator<<(ostream &os, Chain<T> &c); //출력

};

 

template <typename T>

ostream &operator<<(ostream &os, Chain<T> &c)

{

        Chain<T>::ChainIterator i = c.begin();

        while (i != c.end())

        {

               os << i.getData() << "->";

               i++;

        }

        os << i.getData();

        os << endl;

        return os;

}

 

class Polynomial

{

public:

        struct Term

        {

               int coef; //계수

               int exp; //지수

               Term Set(int c, int e)

               {

                       coef = c;

                       exp = e;

                       return *this;

               }

        };

private:

        Chain<Term> poly;

public:

        Polynomial()

        {

        }

        void InsertTerm(Term &term)

        {

               poly.InsertBack(term); //식 추가

        }

        Polynomial operator+(Polynomial &b) //오름차순이 되어있다고 가정

        {

               Term temp;

               Chain<Term>::ChainIterator ai = poly.begin(), bi = b.poly.begin();

              

               Polynomial c; //두 식의 합을 반환할 클래스

               while (ai && bi)

               {

                       if (ai->exp == bi->exp) //지수가 동일할시 더하고

                       {

                              int sum = ai->coef + bi->coef;

                              if (sum)

                                      c.poly.InsertBack(temp.Set(sum, ai->exp));

                              ai++;

                              bi++;

                       }

                       else if (ai->exp < bi->exp) //지수가 더 작은 쪽을 먼저 더한다, 그래야 높은 지수끼리 기다리고 더할 수 있다

                       {

                              c.poly.InsertBack(temp.Set(ai->coef, ai->exp));

                              ai++;

                       }

                       else

                       {

                              c.poly.InsertBack(temp.Set(bi->coef, bi->exp));

                              bi++;

                       }

               }

               while (ai != 0) //식이 더 많은 쪽을 마저 더한다

               {

                       c.poly.InsertBack(temp.Set(ai->coef, ai->exp));

                       ai++;

               }

               while (bi != 0)

               {

                       c.poly.InsertBack(temp.Set(bi->coef, bi->exp));

                       bi++;

               }

               return c;

        }

        int Eval(int x)

        {

               int sum = 0;

               Chain<Term>::ChainIterator ai = poly.begin();

 

               while (ai != 0)

               {

                       for (int i = 0; i < ai->exp; i++)

                       {

                              x *= x;

                       }

                       sum += ai->coef*x;

                       ai++;

               }

               return sum;

        }

        friend ostream &operator<<(ostream &os, Polynomial &p);

        friend istream &operator>>(istream &is, Polynomial &p);

};

 

ostream &operator<<(ostream &os, Polynomial &p)

{

        Chain<Polynomial::Term>::ChainIterator i = p.poly.begin();

        while (1)

        {

               Polynomial::Term term = *i;

               os << term.coef << "x^(" << term.exp << ")";

               if (++i != p.poly.end())

                       os << " + "; //끝이 아닐 경우 +

               else

               {

                       os << " ";

                       break;

               }

        }

        return os;

}

 

istream &operator>>(istream &is, Polynomial &p)

{

        int coef, exp;

        int num;

 

        cout << "다항식에 몇개의 식을 추가할 것인가?";

        is >> num;

 

        for (int i = 0; i < num; i++)

        {

               cout << i + 1 << "번째 계수: ";

               is >> coef;

               cout << i + 1 << "번째 지수: ";

               is >> exp;

 

               Polynomial::Term temp;

               temp.exp = exp;

               temp.coef = coef;

               p.InsertTerm(temp);

        }

 

        return is;

}

 

int main(void)

{

        Polynomial p1, p2, p3;

        Polynomial sum;

        int x;

        Polynomial::Term temp;

        for (int i = 0; i < 5; i++)

        {

               temp.Set(i+1, i+1);

               p1.InsertTerm(temp);

        }

        for (int i = 0; i < 3; i++)

        {

               temp.Set(i + 2, i + 2);

               p2.InsertTerm(temp);

        }

        cout << "p3 다항식 입력" << endl;

        cin >> p3;

        cout << "첫 번째 다항식" << endl << p1 << endl;

        cout << "두 번째 다항식" << endl << p2 << endl;

        cout << "세 번째 다항식" << endl << p3 << endl;

        sum = p1 + p2;

        cout << "첫 번째 두번째 다항식의 합" << endl << sum << endl;

        cout << "세 번째 다항식 계산" << endl;

        cout << "x의 값 입력: ";

        cin >> x;

        cout<< "계산값: "<< p3.Eval(x);

        return 0;

}

