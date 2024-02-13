//https://codeforces.com/problemset/problem/628/D
#include<bits/stdc++.h>
using namespace std;
//giving tle, (sir's answer is also giving tle on 35th test case {sir's answer is at bottom})
#define ll long long
const ll M = 1e9+7;
ll dp[2005][2005][2][2][2];
ll m,d;
string s;
ll countMagic(ll pos, ll mod, bool tight, bool even, bool st){
    if(pos == s.size()){
        return (mod == 0);
    }

    if(dp[pos][mod][tight][even][st] != -1) return dp[pos][mod][tight][even][st];

    ll ub = tight?(s[pos]-'0'):9;//upper bound

    ll count = 0;

    if(st == 0){//number has not started yet
        //assuming at current position also a 0
        count = (count + 0LL + countMagic(pos+1,mod,tight&(s[pos]=='0'),0,st))%M;
        for(ll i=1;i<=ub;i++){//after leading zeroes, first non zero element
            if(i != d){//since first position is odd, so can't have d here
                count = (count + 0LL + countMagic(pos+1,(mod*10 + i)%m,tight&(i==ub),1,1))%M;
            }
        }
    }
    else{//st == 1
        for(ll i=0;i<=ub;i++){
            if(even && (i==d)){
                count = (count + 0LL + countMagic(pos+1,(mod*10 + i)%m,tight&(i==ub),!even,1))%M;
            }
            else if((!even) && (i!=d)){
                count = (count + 0LL + countMagic(pos+1,(mod*10 + i)%m,tight&(i==ub),!even,1))%M;
            }
        }
    }
    return dp[pos][mod][tight][even][st] = count;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>d;
    string a,b;
    cin>>a;
    cin>>b;
    memset(dp,-1,sizeof(dp));
    s=a;
    ll l = countMagic(0,0,1,0,0);
    memset(dp,-1,sizeof(dp));
    s=b;
    ll r = countMagic(0,0,1,0,0);
    ll ans = (r - l +M)%M;

    ll mo = 0;
    ll i = 0;
    ll flag = 1;
    while(i<a.size()){
        if(i%2!=0 && (a[i]-'0') != d){
            flag = 0;
            break;
        }
        if(i%2==0 && (a[i]-'0') == d){
            flag = 0;
            break;
        }
        mo = (mo*10+(a[i]-'0'))%m;
        i++;
    }
    if(mo == 0 && flag){
        ans = (ans+1)%M;
    }
    cout<<ans;

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int mod = 1e9+7;
// ll dp[ 2005 ][ 2005 ][ 2 ][ 2 ][ 2 ];
// string s;
// string a,b;
// ll d,m;
// ll solve ( ll pos, ll mo, bool tight, bool st, bool even){
//     if ( pos == s.size() )
//         return (mo==0);
//     if ( dp[pos][mo][tight][st][even] != -1 )
//         return dp[pos][mo][tight][st][even];
//     ll ret = 0;
//     ll en = (tight?(s[pos]-'0'):9);
//     if ( st == 0 ){
//         ret = ( ret + solve(pos+1,mo,tight&(s[pos]=='0'),st,0))%mod;
//         for ( ll i = 1; i <= en; i ++)
//             if ( i != d )
//                 ret = ( ret + solve(pos+1,(mo*10 + i)%m,tight&(i==en),1,1))%mod;
//     }
//     else{
//         for ( ll i = 0; i <= en; i ++)
//         {
//             if ( even and (i==d) )
//                 ret = ( ret + solve(pos+1,(mo*10 + i)%m,tight&(i==en),1,!even))%mod;
//             else if ( (!even) and (i!=d) )
//                 ret = ( ret + solve(pos+1,(mo*10 + i)%m,tight&(i==en),1,!even))%mod;
//         }
//     }
//     return dp[pos][mo][tight][st][even] = ret;
// }

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     cin >> m >> d;
//     cin >> a >> b;
//     s = b;
//     memset(dp,-1,sizeof dp);
//     ll ans = solve(0,0,1,0,0);
//     s = a;
//     memset(dp,-1,sizeof dp);
//     ans = (ans - solve(0,0,1,0,0) + mod)%mod;
//     ll mo = 0;
//     bool flg = 1;
//     for ( ll i = 0; i < a.size(); i ++){
//         if ( i%2 and ((a[i]-'0')!=d))
//             flg = 0;
//         if ( i%2==0 and ((a[i]-'0')==d))
//             flg = 0;
//         mo = (mo*10 + (a[i]-'0'))%m;
//     }
//     if ( mo == 0 and flg ){
//         ans = ( ans + 1 )%mod;
//     }
//     cout << ans;

//     return 0;
// }