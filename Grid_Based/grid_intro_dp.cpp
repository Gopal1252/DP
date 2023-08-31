//https://leetcode.com/problems/minimum-path-sum/  {very easy since allowed to move only right and down}
//this problem becomes difficult when we can move both up and down  and then we will have to use dijikstra and solve the problem greedily
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

//this code works only when we are given that we are alowed to move only right and down
int minCost(int R, int C, vector<vector<int>>& cost){
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){

            //base case
            if(i==0 && j==0){
                dp[i][j] = cost[0][0];
            }
            else if(i == 0){
                dp[i][j] = dp[0][j-1] + cost[0][j];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][0] + cost[i][0];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + cost[i][j];
            }
        }
    }
    return dp[R-1][C-1];
}

int main(){



    return 0;
}