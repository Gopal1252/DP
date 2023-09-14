#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 999999

int n = 4;
int dp[16][4];//dp[2^n][n] {the values the the bitmask can take}{the number of city}
//Adj Matrix which defines the graph
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

//if all cities have been visited
int VISITED_ALL = (1<<n) - 1;

//travelling salesman problem
int tsp(int mask, int pos){//mask->current mask, pos->current pos 
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;
    //try to go to all unvisited cities
    for(int city = 0; city < n; city++){
        if((mask & (1<<city)) == 0){//i.e this city is unvisited
            int newAns = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));

    cout<<tsp(1,0)<<endl;//1 is equivalent to the mask-> 0001

    return 0;
}