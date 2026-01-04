//https://codeforces.com/problemset/problem/1036/C
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[19][4][2];
//dp[pos][cnt][tight] tells the number of ways to fill up indicies from pos to n-1 such that 
//number of non-zero digits {from pos to 19} + cnt <=3
//Tight tells us whether the prefix before this is the same as in the higher limit or not 
ll countCrazy(int pos, int cnt, int tight, string n){
    if(cnt>3) return 0;
    if(pos == n.length()) return 1;

    if(dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];

    int count = 0;
    for(char i='0';i<='9';i++){
        if(tight && i>n[pos]) continue;
        count += countCrazy(pos+1,cnt + (i>'0'), tight & (i == n[pos]),n);
    }

    return dp[pos][cnt][tight] = count;
}

void solve(){
    ll l,r;
    cin>>l>>r;
    string lft = to_string(l-1);
    string rgt = to_string(r);
    memset(dp,-1,sizeof(dp));
    ll a = countCrazy(0,0,1,lft);
    memset(dp,-1,sizeof(dp));
    ll b = countCrazy(0,0,1, rgt);
    cout<<b-a<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}