#include <string>
#include <vector>
#include <iostream>    
#include <algorithm>

using namespace std;

int n;//문자열 길이
char arr[2]={'a','b'};//문자 a,b배열에 넣고 호출할 것이다.
void permutation(vector<int> v, int depth, int num) {
    //벡터 v에 인덱스번호를 넣는과정이다
	v.push_back(num);
    //depth == n이면 벡터에도 n개의 인덱스번호가 쌓여있으므로 출력한다.
	if (depth == n) {
		for (int i : v) {
			cout << arr[i] ;
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < 2; i++) {
            //기존 permutation사용방법처럼 재귀호출하여 사전순대로 나오도록 함
        	permutation(v, depth + 1, i);
		}
	}
}

int main() {
	cin >> n;
	vector<int> v;
	for (int i = 0; i < 2; i++) {
		permutation(v,1,i);
	}
}