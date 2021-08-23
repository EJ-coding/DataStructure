#include <iostream>

using namespace std;

int cnt;//mid=(first+last)/2코드가 몇번 실행되는지 알기위한 변수
//재귀를 통해 이분탐색 진행
int binary_search(int first, int last, int *arr, int target){

    if(first > last) return -1;//탐색할 수 없을경우 
    int mid =(first+ last)/2;
    cnt++;//mid 계산 반복 수 count
    

    if(target == arr[mid]){

        return mid;

    }else if(target < arr[mid]){

        return binary_search(first, mid-1,arr,target);

    }else {

        return binary_search(mid+1,last,arr,target);

    }
}
int main(){

    int n;//배열 길이
    int m;//찾을 정수
    
    cin >> n;
    int arr[n];
    for(int i = 0 ; i< n; i++){
        cin >> arr[i];
    }

    cin >> m;
    
    cout << binary_search(0,n-1,arr,m) << endl;
   
    cout << cnt;
    
    



}
