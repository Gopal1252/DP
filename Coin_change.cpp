#include<bits/stdc++.h>
using namespace std;

//top-down
int minCoins(int n, int coins[], int T, int dp[]){
    //Base case
    if(n==0){
        return 0;
    }

    //Lookup
    if(dp[n] != 0){
        return dp[n];
    }

    //Recursive Case;
    int ans = INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i]>=0){
            int subprob = minCoins(n-coins[i],coins,T,dp);
            ans = min(ans,subprob+1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

//bottom -up
int minCoinsBU(int N, int coins[], int T){
    int dp[100] = {0};

    //Iterate over a;; the state 1...N
    for(int n=1;n<=N;n++){
        dp[n] = INT_MAX;
        for(int i=0;i<T;i++){
            if(n-coins[i]>=0){
                int subprob = dp[n-coins[i]];
                dp[i] = min(dp[i],subprob+1);
            }
        }
    }
    return dp[N];
}

int main(){
    int N= 15;
    int coins[] = {1,7,10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);

    cout<<minCoins(N,coins,T,dp)<<endl;

    return 0;
}