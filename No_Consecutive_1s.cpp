//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

ll dp[100010][2];

ll func(int n, int i){
	if(n==0) return 1;
	    
	if(dp[n][i] != -1) return dp[n][i];
	    
	ll ans = 0;
	if(i==0){
	    ans = (ans + func(n-1,0))%M;
	    ans = (ans + func(n-1,1))%M;
	}
	else if(i==1){
	   ans = (ans + func(n-1,0))%M;
    }
	    
    return dp[n][i] = ans;
}

ll countStrings(int n) {
    memset(dp,-1,sizeof(dp));
    return func(n-1,0) + 0ll + func(n-1,1);
}

int main(){
    int n;
    cin>>n;
    cout<<countStrings(n)<<endl;
    return 0;
}