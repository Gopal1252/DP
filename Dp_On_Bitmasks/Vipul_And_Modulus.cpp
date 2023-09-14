//https://hack.codingblocks.com/app/contests/1338/512/problem {On Hackerblocks}
//https://codeforces.com/problemset/problem/401/D {also on codeforces}
#include<bits/stdc++.h>
using namespace std;

//Question
/*
Vipul wants to buy his favourite bike Royal Enfield.
The bike is priced at N dollars. He already has the amount with him and wants to take his girlfriend for a ride but she poses a condition and asks him a question.
She always gives him challenging tasks and this time she gives him a number M and asks him to find out how many numbers can be formed by rearranging digits of number N whose modulo M is 0?
NOTE :- You have to permute digits of N and only consider the numbers which do not have leading zeroes.

Constraints:
1<=N<=10^18
1<=M<=100
*/
#define ll long long 
ll dp[(1<<19) + 1][101];
string s;
ll MOD; 
ll solve(ll mask, ll m){
    if(mask == (1<<s.size())-1){
        return (m==0);
    }

    if(dp[mask][m] != -1) return dp[mask][m];

    ll ans = 0;
    bool ch[10];
    memset(ch,0,sizeof(ch));//used to prevent taking the same number from different positions in the same turn {to avoid dupicates}
    for(ll i = 0; i < s.size(); i++){
        //avoiding eading zeroes
        if(s[i] == '0'){
            if(mask == 0){
                continue;
            }
        }
        if((!(mask&(1<<i)) )&& (!ch[s[i] - '0'])){
            ans = (ans + solve(mask|(1<<i),(m*10+(s[i] - '0'))%MOD));
            ch[s[i] - '0'] = 1;
        }
    }
    return dp[mask][m] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        memset(dp,-1,sizeof(dp));
        cin>>s;
        cin>>MOD;
        cout<<solve(0,0)<<"\n";

    return 0;
}