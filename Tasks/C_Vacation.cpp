#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int h[N][4];
int dp[N][4];

int vacation(int day, int act){
    if(day == 0){
        return 0;
    }

    if(dp[day][act] != -1) return dp[day][act];

    int happiness = 0;
    for(int i=1;i<=3;i++){
        if(i != act){
            happiness = max(happiness, h[day][i] + vacation(day-1,i));
        }
    }

    return dp[day][act] = happiness;
}



int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>h[i][j];
        }
    }

    int happiness = 0;

    for(int i=1;i<=3;i++){
        happiness = max(happiness, h[n][i] + vacation(n-1,i));
    }

    cout<<happiness;

    return 0;
}