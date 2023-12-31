//https://codeforces.com/problemset/problem/429/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            grid[i][j] = x;
        }
    }

    vector<vector<int>> dp1(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j] = max(dp1[i][j-1],dp1[i-1][j]) + grid[i][j];
        }
    }

    vector<vector<int>> dp2(n+2,vector<int>(m+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            dp2[i][j] = max(dp2[i][j-1],dp2[i+1][j]) + grid[i][j];
        }
    }

    vector<vector<int>> dp3(n+2,vector<int>(m+2,0));
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp3[i][j] = max(dp3[i][j+1],dp3[i+1][j]) + grid[i][j];
        }
    }

    vector<vector<int>> dp4(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp4[i][j] = max(dp4[i][j+1],dp4[i-1][j]) + grid[i][j];
        }
    }

    int ans = INT_MIN;
    for(int i=2;i<=n-1;i++){
        for(int j=2;j<=m-1;j++){
            int opt1 = dp1[i-1][j] + dp2[i][j-1] + dp3[i+1][j] + dp4[i][j+1];
            int opt2 = dp1[i][j-1] + dp2[i+1][j] + dp3[i][j+1] + dp4[i-1][j];
            ans = max(ans,max(opt1,opt2));
        }
    }
    cout<<ans;

    return 0;
}