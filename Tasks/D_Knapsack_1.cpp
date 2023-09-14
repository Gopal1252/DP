#include<bits/stdc++.h>
using namespace std;

int wt[105];
long long val[105];

long long dp[101][100005];

long long Knapsack(int index, int cap){//returns the maximum sum of values when the bag's remaining capacity is cap
    if(cap==0) return 0;
    if(index == 0) return 0;

    if(dp[index][cap] != -1) return dp[index][cap];

    long long value = 0;

    value = Knapsack(index-1, cap);
    if(cap-wt[index]>=0){
        value = max(value, Knapsack(index-1, cap-wt[index]) + 0LL + val[index]);
    }

    return dp[index][cap] = value;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin>>n>>w;

    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }

    cout<<Knapsack(n,w);


    return 0;
}