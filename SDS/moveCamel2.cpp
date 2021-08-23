#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int T;
   
    vector<int> from_list;
    vector<int> to_list;
     
    scanf("%d",&T);
    int ans[T];

    for(int t = 0; t < T; ++t){  
        int N;
        
        int sum = 0;// 초기화
        scanf("%d",&N); 
        vector<int> time(N);
   
        for(int i = 0 ; i<N; i++){
            cin >> time[i];
            from_list.push_back(time.back());
        }
        if(N==1){
            sum = from_list.back();
        }else{
            while(from_list.empty() != true){
                sort(from_list.begin(),from_list.end());
                to_list.push_back(from_list[0]);
                to_list.push_back(from_list[1]);
                sum += from_list[1];
                sum += from_list[0];
                from_list.erase(from_list.begin()+1);
                sum += from_list.back();
                from_list.pop_back();
                from_list.pop_back();
                sum += to_list.front();
                from_list.erase(from_list.begin());
            }
        }
        ans[t]=sum;
    }
    for(int i = 0 ; i<T; ++i){
        printf("#%d %d\n",i+1,ans[i]);
    }
    return 0;
}