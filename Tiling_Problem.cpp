//https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1
//https://practice.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1
#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9+7;
long long dp[100010] = {0};
    
long long numberOfWays(long long N) {
    if(N==0) return 1;
        
    if(dp[N] != 0) return dp[N];
        
    long long ans = 0;
    ans = (ans + numberOfWays(N-1))%M;
    if(N>=2){
        ans = (ans + numberOfWays(N-2))%M;
    }
    
    return dp[N] = ans;
}

int main(){

    return 0;
}