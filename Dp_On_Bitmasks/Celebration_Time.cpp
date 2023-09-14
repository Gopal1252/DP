//this problem exists with the name DiwaliPuzzle in the pirated course
//https://hack.codingblocks.com/app/contests/2095/1262/problem
#include<bits/stdc++.h>
using namespace std;

//we don't need to make any combinations
//each of the n bulbs can take value 1 or 0, let's go through positions 0 to n-1 and check can the final product be k
//at each index, we have an option that bulb can be 0 or 1 and accordingly we will add to the cnt variable

int n,k;
const int M = 1e6+3;
int dp[105][3][105];//dp[ind][prev][cnt] ->ind->current index, prev->prev bulb(0/1), cnt->basically the product sum so far

int func(int ind, int prev, int cnt){
    if(ind == n){
        if(cnt == k) return 1;
        else return 0;
    }

    if(dp[ind][prev][cnt] != -1) return dp[ind][prev][cnt];

    int ans = 0;
    if(prev == 1){
        ans = (ans + 0LL + func(ind+1,1,cnt+1))%M;//only when prev bulb was 1 and we keep current bulb 1(on), then only cnt increases
        ans = (ans + 0LL + func(ind+1,0,cnt))%M;
    }
    else{//previous bulb was off
        ans = (ans + 0LL + func(ind+1,1,cnt))%M;
        ans = (ans + 0LL + func(ind+1,0,cnt))%M;
    }
    return dp[ind][prev][cnt] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<< (func(1,0,0) + func(1,1,0))%M<<endl;
    }


    return 0;
}