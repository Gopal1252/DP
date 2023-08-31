//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2010][2010][6];
ll a[2010],b[2010];

ll func(ll i, ll j, ll k){
    //base case
    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    ll ans = INT_MIN;

    if(a[i] == b[j]){
        ans = max(ans,1 + func(i-1,j-1,k));
    }
    else{//i.e if a[i] != b[j]
        if(k != 0){
            ans = max(ans,1 + func(i-1,j-1,k-1));
        }
        ans = max(ans,func(i-1,j,k));
        ans = max(ans,func(i,j-1,k));
    }
    return dp[i][j][k] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp,-1,sizeof(dp));
    ll n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    cout<<func(n-1,m-1,k);

    return 0;
}