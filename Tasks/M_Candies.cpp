#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

//TC = O(n*k) * O(k) {in worst case where each a[i] = k} {here n*k is the number of states and k is the time taken at each state}
//TLE
int ways(int ind, int candies, vector<int>& a, vector<vector<int>>& dp){
    if(ind == a.size()){
        if(candies == 0) return 1;
        else return 0;
    }

    if(dp[ind][candies] != -1) return dp[ind][candies];

    int ans = 0;
    for(int i=0;i<=min(a[ind],candies);i++){
        ans = (ans + 0LL + ways(ind+1,candies-i,a,dp))%M;
    }

    return dp[ind][candies] = ans;
}
//dp[i][j] --> no. of ways to distribute j exact candies among first i indexes (i+1 kids) 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<int>> dp(n,vector<int>(k+1,0));

    //base case
    for(int j=0;j<=a[0];j++) dp[0][j] = 1;

    //TC:O(n*k*k)
    //TLE
    // for(int i=1; i<n; i++){
    //     for(int j=0; j<=k; j++){
    //         for(int x=0; x<=min(a[i],j);x++){
    //             dp[i][j] = (dp[i][j] + 0LL + dp[i-1][j - x])%M;
    //         }
    //     }
    // }

    //To prevent TLE, we will use prefix sums to reduce the TC from nk^2 to n*k
    //The use of prefix sums will help us avoid the innermost loop
    //the innermost loop basically fills dp[i][j] which is basically the ways to give exactly j candies to forst i indexes
    //in the inner most loop, we add to dp[i][j]
    //what do we add to dp[i][j] --> we add to it dp[i-1][j-min(a[i],j)] to dp[i-1][j]
    //basically we try to give some x candites to the ith kid and see of j-i candies can be given to kids till (i-1)th index
    //this value of x ranges fro 0 to min(a[i],j)
    
    //TC: O(n*k)
    for(int i=1; i<n; i++){
        vector<int> presum(k+1,0);//presum[j] stores the ways to distribute upto j candies to the first i indexes or the first (i+1) kids
        presum[0] = dp[i-1][0];
        for(int j=1; j<=k; j++){
            presum[j] = (presum[j-1] + 0LL + dp[i-1][j])%M;
        }

        for(int j=0;j<=k;j++){
            dp[i][j] = (dp[i][j] + 0LL + presum[j])%M;
            if(j - a[i] - 1 >= 0){
                dp[i][j] = (dp[i][j] + 0LL + M - presum[j - a[i] - 1])%M;
            }
        }
    }
    cout<<dp[n-1][k];

    return 0;
}

