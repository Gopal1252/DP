#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

//TC:O(n*(2^n)*n) --> O(n^2 * (2^n))
//should have given TLE for the n given in question, but still passed
int solve(int i, int mask, vector<vector<int>>& v, vector<vector<int>>& dp){
    int n = v.size();

    if(i == n){
        if(mask == ((1<<n)-1)){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;

    for(int j=0;j<n;j++){
        if(v[i][j] == 1 && ((mask&(1<<j)) == 0)){
            ans = (ans + 0LL + solve(i+1,(mask|(1<<j)),v,dp))%M;
        }
    }

    return dp[i][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int>((1<<n),-1));

    cout<<solve(0,0,v,dp)<<"\n";

    return 0;
}