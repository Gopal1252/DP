//https://hack.codingblocks.com/app/contests/1338/1253/problem
#include<bits/stdc++.h>
using namespace std;

double dp[105][105][105];

void set_dp(){
    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            for(int k=0;k<102;k++){
                dp[i][j][k] = -1.0;
            }
        }
    }
}

double f1(int r, int s, int p){
    //base case
    if(r==0 || s==0){
        return 0.0;
    }
    if(p==0){
        return 1.0;
    }

    if(dp[r][s][p] != -1.0){
        return dp[r][s][p];
    }

    double tot = r*s + r*p + s*p;

    double ans = 0.0;

    ans += f1(r-1,s,p) * ((r*p)/tot); //paper kills rock
    ans += f1(r,s-1,p) * ((r*s)/tot); //rock kills scissor
    ans += f1(r,s,p-1) * ((s*p)/tot); //scissor kills paper

    return dp[r][s][p] = ans;
}

double f2(int r, int s, int p){
    //base case
    if(s==0 || p==0){
        return 0.0;
    }
    if(r==0){
        return 1.0;
    }

    if(dp[r][s][p] != -1.0){
        return dp[r][s][p];
    }

    double tot = r*s + r*p + s*p;

    double ans = 0.0;

    ans += f2(r-1,s,p) * ((r*p)/tot); //paper kills rock
    ans += f2(r,s-1,p) * ((r*s)/tot); //rock kills scissor
    ans += f2(r,s,p-1) * ((s*p)/tot); //scissor kills paper

    return dp[r][s][p] = ans;
}

double f3(int r, int s, int p){
    //base case
    if(p==0 || r==0){
        return 0.0;
    }
    if(s==0){
        return 1.0;
    }

    if(dp[r][s][p] != -1.0){
        return dp[r][s][p];
    }

    double tot = r*s + r*p + s*p;

    double ans = 0.0;

    ans += f3(r-1,s,p) * ((r*p)/tot); //paper kills rock
    ans += f3(r,s-1,p) * ((r*s)/tot); //rock kills scissor
    ans += f3(r,s,p-1) * ((s*p)/tot); //scissor kills paper

    return dp[r][s][p] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int r,s,p;
        cin>>r>>s>>p;
        set_dp();
        double ans1 = f1(r,s,p);
        set_dp();
        double ans2 = f2(r,s,p);
        set_dp();
        double ans3 = f3(r,s,p);

        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }

    return 0;
}