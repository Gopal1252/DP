#include<bits/stdc++.h>
using namespace std;

#define ll long long

//my solution from CSES for this problem: https://cses.fi/problemset/task/1097 {also see the analytics section there}
//also see the iterative version there

ll solve(int i, int j, vector<ll>& v, vector<vector<ll>>& dp) {
    if (j < i) return 0;
    if (dp[i][j] != LLONG_MIN) return dp[i][j];

    ll ans = v[i] + min(solve(i+2,j,v,dp), solve(i+1,j-1,v,dp));
    ans = max(ans, v[j] + min(solve(i+1,j-1,v,dp), solve(i,j-2,v,dp)));

    return dp[i][j] = ans;
}


// ll solve(ll i, ll j, ll p, vector<ll>& v, vector<vector<vector<ll>>>& dp){
//     if(j<i) return 0;
 
//     if(dp[i][j][p] != LLONG_MIN) return dp[i][j][p];
 
//     //player one choosing the first element
//     ll ans = 0;
//     if(p == 0){
//         ans = max(v[i] + solve(i+1,j,1,v,dp), v[j] + solve(i,j-1,1,v,dp));
//     }
//     else{
//         ans = min(0-v[i] + solve(i+1,j,0,v,dp), 0-v[j] + solve(i,j-1,0,v,dp));
//     }
    
//     return dp[i][j][p] = ans;
// }


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;

    ll tot = 0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        tot = tot + v[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MIN));

    ll player1 = solve(0,n-1,v,dp);

    ll player2 = tot - player1;

    cout<<player1 - player2<<"\n";

    

    return 0;
}
