//https://codeforces.com/problemset/gymProblem/100886/G
#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
pair<ll,string> dp[19][2][2][2]; 
pair<ll,string> findMax(int pos, int t1, int t2, int lead){//{lead to know if the current position is leading zero}if lead == 0, it means that either it is the first pos from the left or we have only encountered 0's so far
    if(pos == a.length()) return {1,""};

    if(dp[pos][t1][t2][lead].first != -1) return dp[pos][t1][t2][lead];

    int lb = t1?(a[pos]-'0'):0;
    int ub = t2?(b[pos]-'0'):9;


    ll maxProd = -1;
    string ans = "";
    for(int i=lb;i<=ub;i++){
        ll val;
        if(lead == 0 && i == 0){
            val = 1;
        }
        else{
            val = i;
        }
        pair<ll,string> ret = findMax(pos+1,t1 & (lb == i), t2 & (ub == i),lead|(i>0));
        ll prod = ret.first;
        string str = ret.second;
        if(val*prod > maxProd){
            maxProd = val*prod;
            if(lead == 0 && i == 0){
                ans = str;
            }
            else{
                reverse(str.begin(),str.end());
                str.push_back('0'+i);
                reverse(str.begin(),str.end());
                ans = str;
            }
        }
    } 
    return dp[pos][t1][t2][lead] = {maxProd,ans};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>a>>b;
    reverse(a.begin(),a.end());
    while(a.size()<b.size()){
        a.push_back('0');
    }
    reverse(a.begin(),a.end());
    for(int i=0;i<19;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                    dp[i][j][k][l] = {-1,""};
                }
            }
        }
    }
    cout<<findMax(0,1,1,0).second;

    return 0;
}