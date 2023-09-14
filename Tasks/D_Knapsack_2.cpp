#include<bits/stdc++.h>
using namespace std;

long long wt[105];
int val[105];

long long dp[105][100005];

long long Knapsack(int index, int val_left){
    if(val_left == 0) return 0;
    if(index == 0) return 1e15;

    if(dp[index][val_left] != -1) return dp[index][val_left]; 

    long long weight = Knapsack(index-1, val_left);

    if(val_left - val[index] >= 0){
        weight = min(weight, Knapsack(index-1, val_left-val[index]) + 0LL + wt[index]);
    }

    return dp[index][val_left] = weight;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin>>n>>w;

    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }

    int max_val = 1e5;

    for(int i=max_val;i>=0;i--){
        if(Knapsack(n,i) <= w){
            cout<<i<<endl;
            break;
        }
    }


    return 0;
}