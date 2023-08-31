//https://www.spoj.com/problems/TOURIST/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll m,n;
ll dx1[4] = {1,1,0,0};
ll dy1[4] = {0,0,1,1};
ll dx2[4] = {1,0,1,0};
ll dy2[4] = {0,1,0,1};

ll dp[105][105][105];
char grid[105][105];

ll solve(ll x1, ll y1, ll x2, ll y2){
    //out of bounds or blocked {for any of tourist1 or tourist2}
    if(x1>m || y1>n || x2>m || y2>n || grid[x1][y1] == '#' || grid[x2][y2] == '#'){
        return INT_MIN;
    }

    //termination condition
    if(x1 == m && y1 == n){
        return (grid[x1][y1] == '*');
    }

    if(dp[x1][y1][x2] != -1){
        return dp[x1][y1][x2];
    }

    ll ans = INT_MIN;

    for(ll i=0;i<4;i++){
        ans = max(ans,solve(x1+dx1[i],y1+dy1[i],x2+dx2[i],y2+dy2[i]));
    }

    ans += (grid[x1][y1]=='*');
    ans += (grid[x2][y2]=='*');

    //case where both are at the same position and it is a special location, then we have to decrease teh answer by one since we added 1 two times for the same special location
    if(x1 == x2 && y1 == y2 && grid[x1][y1]=='*'){
        ans--;
    }

    return dp[x1][y1][x2] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n>>m;//in question, first columns are given
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(1,1,1,1)<<endl;//since given input is for a 1-indexed grid
    }


    return 0;
}