#include<iostream>
 
//메모이제이션 선언->중복되는 계산을 줄일 수 있다.
//0으로 초기화
int dp[100][100]={0,};
 
int combination(const int r, const int n) {
    if(r== n||n ==0){
        //r==n이거나 n==0인 경우 1
        return 1;
    }
    if(dp[r][n]!=0){
        return dp[r][n];
    }
    //재귀호출을 하여 r ==n || n==0까지 반복
    return dp[r][n] = combination(r - 1, n) + combination(r - 1, n - 1) ;
    
}
 
int main() {
    int n, r;
    std::cin >> n >> r;
 
    std::cout << combination(n, r);
}

