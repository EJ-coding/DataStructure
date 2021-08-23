#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // string filename;
    // getline(cin, filename);
	ifstream readFile;//파일을 읽어오기위해 열기
	string str;//한줄씩 읽어올 문장열 변수

    int test_case;
    int N ;//낙타수
    
    
	readFile.open("sample_input.txt");
	if(readFile.is_open()){
		getline(readFile, str);//한줄읽어오기
        //test case
		test_case = stoi(str, nullptr);//string to int    
    }    
    while(test_case > 0){
        getline(readFile, str);//한줄 씩 읽어오기
        //한줄씩 stream으로 전달
	    stringstream stream(str); 
        stream >> N;
    }	
 
    return 0;
}