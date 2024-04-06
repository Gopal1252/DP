#include<bits/stdc++.h>
using namespace std;

//dp[ind][heads] stores the probability of getting heads no. of heads from the first ind indexes (I {may be wrong})
double prob(int ind, int heads, vector<double>& p, vector<vector<double>>& dp){
    if(ind == p.size()){
        if(heads>(p.size()-heads)) return 1;
        else return 0;
    }

    if(dp[ind][heads] != -1) return dp[ind][heads];

    double ans = p[ind]*prob(ind+1,heads+1,p,dp);
    ans += (1-p[ind])*prob(ind+1,heads,p,dp);

    return dp[ind][heads] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    // vector<double> p(n);
    // for(int i=0; i<n; i++) cin>>p[i];

    // vector<vector<double>> dp(n, vector<double>(n+1,-1));
    // double ans = prob(0,0,p,dp);

    // cout<<setprecision(9)<<fixed<<ans<<"\n";

    //iterative solution
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0] = 1;//dp[i][j] stores prob of getting j no. of heads from the indexes till i

    for(int i=1; i<=n; i++){

        dp[i][0] = dp[i-1][0] * (1-p[i]);//if not taking any 0

        for(int j=1; j<=n; j++){
            dp[i][j] = ((p[i] * dp[i-1][j-1]) + ((1-p[i]) * dp[i-1][j]));
        }
    }

    double ans = 0;
    for(int j=((n+1)/2);j<=n; j++){
        ans += dp[n][j];
    }

    cout<<setprecision(9)<<ans<<"\n";


    return 0;
}