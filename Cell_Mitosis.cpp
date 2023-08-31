//https://hack.codingblocks.com/app/contests/1310/546/problem
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];

//bottom-Up
int cost(int n, int x, int y, int z){
    dp[1] = 0;
    
    for(int i=2;i<=n;i++){
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else{
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
        }
    }

    return dp[n];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int x, y, z;
    cin>>x>>y>>z;
    cout<<cost(n,x,y,z);
    return 0;
}