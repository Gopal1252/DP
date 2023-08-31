//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

#include<bits/stdc++.h>
using namespace std;

int M = 1e9+7;
int dp[10010] = {0};
int countFriendsPairings(int n) 
{   if(n==1) return 1;
    if(n==2) return 2;
        
    if(dp[n] != 0) return dp[n];
        
    int ans = 0;
    ans += (countFriendsPairings(n-1) + 0LL + ((n-1)*1LL*countFriendsPairings(n-2))%M)%M;
        
    return dp[n] = ans;
}

int main(){

    return 0;
}