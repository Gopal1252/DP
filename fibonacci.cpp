#include<bits/stdc++.h>
using namespace std;

//normal recursive solution
int fib(int n){
    //base case
    if(n==0 || n==1){
        return n;
    }
    int ans;
    ans = fib(n-1) + fib(n-2);
    return ans;
}

//top-down approach
int fib1(int n, int dp[]){
    //base case
    if(n==0 || n==1){
        return n;
    }

    //look up
    if(dp[n] != 0){
        return dp[n];
    }

    int ans;
    ans = fib(n-1) + fib(n-2);
    return dp[n] = ans;
}

//bottom-up
int fibBU(int n){
    int dp[100] {0};
    dp[1] = 1;

    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-1];
    }
    return dp[n];
}

//bottom-up approach with space optimization
int fibSpaceOpt(int n){
    if(n==0 or n==1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;

    for(int i=2;i<n;i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};

    return 0;
}