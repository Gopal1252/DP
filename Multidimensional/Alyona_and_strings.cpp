//https://codeforces.com/problemset/problem/682/D
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

string s, t;
ll n, m, k;
ll dp[1010][1010][11][2];
//solve function returns the maximum length of the possible k disjoint substrings

//when decreasing rem at the start of a substring
ll solve1(ll is, ll it, ll rem, int cont) { //is->index in string s, it->index in string t, rem-> remaining substrings to be processes, cont-> continuity {tells whether to continue the current substring or not}
    //base case {when one of the strings gets inifshed}
    if (is == n || it == m) {
        return ((rem == 0) ? 0 : INT_MIN);
    }
 
    if (rem == 0 && cont == 0) return 0;
 
    if (dp[is][it][rem][cont] != -1) {
        return dp[is][it][rem][cont];
    }
 
    ll ans = INT_MIN;
 
    if (cont == 1) {
        ans = max(ans, solve1(is + 1, it, rem, 0));
        ans = max(ans, solve1(is, it + 1, rem, 0));
        if (s[is] == t[it]) {
            ans = max(ans, solve1(is + 1, it + 1, rem, 1) + 1) ;
            ans = max(ans, solve1(is + 1, it + 1, rem, 0) + 1);
        }
    }
    else { //if cont == 0
        ans = max(ans, solve1(is + 1, it, rem, 0));
        ans = max(ans, solve1(is, it + 1, rem, 0));
        if (s[is] == t[it]) {
            ans = max(ans, solve1(is + 1, it + 1, rem - 1, 1) + 1);
            ans = max(ans, solve1(is + 1, it + 1, rem - 1, 0) + 1);
        }
    }
    return dp[is][it][rem][cont] = ans;
}

//when decreasing rem at the end of a substring
ll solve2(ll is, ll it, ll rem, int cont) { //is->index in string s, it->index in string t, rem-> remaining substrings to be processes, cont-> continuity {tells whether to continue the current substring or not}
    //base case {when one of the strings gets inifshed}
    if (is == n || it == m) {
        return ((rem == 0) ? 0 : INT_MIN);
    }
 
    if (rem == 0 && cont == 0) return 0;
 
    if (dp[is][it][rem][cont] != -1) {
        return dp[is][it][rem][cont];
    }
 
    ll ans = INT_MIN;
 
    if (cont == 1) {
        ans = max(ans, solve2(is + 1, it, rem - 1, 0));
        ans = max(ans, solve2(is, it + 1, rem - 1, 0));
        if (s[is] == t[it]) {
            ans = max(ans, solve2(is + 1, it + 1, rem, 1) + 1) ;
            ans = max(ans, solve2(is + 1, it + 1, rem - 1, 0) + 1);
        }
    }
    else { //if cont == 0
        ans = max(ans, solve2(is + 1, it, rem, 0));
        ans = max(ans, solve2(is, it + 1, rem, 0));
        if (s[is] == t[it]) {
            ans = max(ans, solve2(is + 1, it + 1, rem, 1) + 1);
            ans = max(ans, solve2(is + 1, it + 1, rem - 1, 0) + 1);
        }
    }
    return dp[is][it][rem][cont] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    cin >> s >> t;
    cout << solve1(0, 0, k, 0);
    cout << solve2(0, 0, k, 0);

    return 0;
}