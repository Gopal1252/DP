#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int h[N];
int dp[N];

//dp TC: O(n*k)
int func(int i, int k){
    if(i==0){
        return 0;
    }

    if(dp[i] != -1) return dp[i];
    
    int cost = INT_MAX;

    for(int j=1;j<=k;j++){
        if(i>=j)//or i-j>=0
        cost = min(cost, func(i-j,k) + abs(h[i] - h[i-j]));
    }

    return dp[i] = cost;
}


int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    cout<<func(n-1,k); 


    return 0;
}



//myself
// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5+10;

// int h[N];
// int dp[N];

// //brute force recursion
// int frog(int i, int n, int k){
//     if(i==n){
//         return 0;
//     }

//     if(dp[i] != -1) return dp[i];

//     int cost = INT_MAX;

//     for(int j=1;j<=k;j++){
//         if(i+j<=n){
//             cost = min(cost,abs(h[i]-h[i+j]) + frog(i+j,n,k));
//         }
//     }

//     return dp[i] = cost;
// }

// int main(){
//     memset(dp,-1,sizeof(dp));
//     int n,k;
//     cin>>n>>k;
//     for(int i=1;i<=n;i++){
//         cin>>h[i];
//     }

//     cout<<frog(1,n,k);

//     return 0;
// }