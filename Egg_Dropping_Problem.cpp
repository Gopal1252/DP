//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
#include<bits/stdc++.h>
using namespace std;

//bottom-up {tabulation} {makes more sense}
int func1(int k, int n){
    vector<vector<int>> dp(k+1, vector<int>(n+1,0));
       
    for(int i=1;i<=n;i++){
        dp[1][i] = i;
    }
       
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            int ans = INT_MAX;
            for(int x=1;x<=j;x++){
                ans = min(ans,1+max(dp[i-1][x-1],dp[i][j-x]));
            }
            dp[i][j] = ans;
        }
      }
    return dp[k][n];
}

//top-down {memoisation} {less intuitive}
vector<vector<int>> dp;

int func2(int k, int n){
    if(dp[k][n] != -1) return dp[k][n];
        
    if(n==0 || n==1) return n;
        
    if(k==1) return n;
        
    int ans = INT_MAX;
        
    for(int x=1;x<=n;x++){
        ans = min(ans,1+max(func2(k-1,x-1),func2(k,n-x)));
    }
        
    return dp[k][n] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;//n -> number of floors, k->number of eggs
    cin>>n>>k;
    dp.resize(k+1, vector<int>(n+1,-1));
    cout<<func1(k,n);//bottom-up
    cout<<func2(k,n);//top-down

    return 0;
}