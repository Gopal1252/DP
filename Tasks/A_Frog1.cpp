// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+10;

// int h[N];
// int dp[N];

// //brute force recursion
// // int func(int i){
// //     if(i==0){
// //         return 0;
// //     }
    
// //     int cost = INT_MAX;

// //     // way 1
// //     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
// //     // way 2
// //     cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));

// //     return cost;
// // }

// //dp TC: O(n)
// int func(int i){
//     if(i==0){
//         return 0;
//     }

//     if(dp[i] != -1) return dp[i];
    
//     int cost = INT_MAX;

//     // way 1
//     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
//     // way 2
//     if(i>1)//can't jamp back two positions if at index = 1
//     cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));

//     return dp[i] = cost;
// }


// int main(){
//     memset(dp,-1,sizeof(dp));
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>h[i];
//     }

//     cout<<func(n-1); //since taking h[i] to be a 0 indexed array, so last stone is stored at index n-1


//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int h[N];
int dp[N];

//brute force recursion
int frog(int i, int n){
    if(i==n){
        return 0;
    }

    if(dp[i] != -1) return dp[i];

    int cost = 0;
    if(i+1<=n){
        cost = abs(h[i]-h[i+1]) + frog(i+1,n);
    }
    if(i+2<=n){
        cost = min(cost, abs(h[i]-h[i+2]) + frog(i+2,n));
    }

    return dp[i] = cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    cout<<frog(1,n);

    return 0;
}