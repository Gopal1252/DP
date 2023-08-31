//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include<bits/stdc++.h>
using namespace std;

//bottom up {tabulation} 
int MatrixChainMultiplication_Tabulation(int N, int arr[]){
    int dp[N][N];
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=1;i<=N-1;i++){
        dp[i][i] = 0;
    }
    for(int i=2;i<=N-1;i++){
        int x=1,y=i;
        while(y<=N-1){
            for(int k=x;k<y;k++){
                dp[x][y] = min(dp[x][y],dp[x][k] + dp[k+1][y] + arr[x-1]*arr[k]*arr[y]);
            }
            x++,y++;
        }
    }
    return dp[1][N-1];
}

//top-down
vector<vector<int>> dp;
int func(int i, int j, int arr[]){//returns minimum cost of multiplication of matrices from i to j
    if(i==j){//we can also put i>=j here
        return 0;
    }
        
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
        
    int ans = INT_MAX;
        
    for(int k = i; k<j; k++){
        ans = min(ans, func(i,k,arr) + func(k+1,j,arr) + arr[i-1]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}    
int MatrixChainMultiplication_Memoisation(int N, int arr[])
{
    dp.resize(N,vector<int>(N,-1));
    return func(1,N-1,arr);//
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;//n->number of matrices
    cin>>n;

    int arr[n+1];
    for(int i=0;i<n+1;i++){
        cin>>arr[i];
    }

    cout<<MatrixChainMultiplication_Tabulation(n+1,arr);
    cout<<MatrixChainMultiplication_Memoisation(n+1,arr);

    return 0;
}