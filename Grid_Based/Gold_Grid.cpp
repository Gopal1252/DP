//https://hack.codingblocks.com/app/contests/1338/793/problem
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    grid.resize(n+1,vector<int>(n+1,0));
    dp.resize(n+1,vector<int>(n+1,0));
    while(m--){
        int i,j;
        cin>>i>>j;
        grid[i][j] = 1;
    }

    //2D prefix sum
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + grid[i][j];
        }
    }

    int ans = INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int part1 = dp[i][j];
            int part2 = dp[i][n] - part1;
            int part3 = dp[n][j] - part1;
            int part4 = dp[n][n] - part1 - part2 - part3;
            ans = max(ans, min(min(part1,part2),min(part3,part4)));
        }
    }
    cout<<ans<<"\n";


    return 0;
}