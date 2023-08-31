//https://www.spoj.com/problems/MIXTURES/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[1000];
ll dp[1000][1000];

ll csum(int i, int j) {
    ll ans = 0;
    for (int k = i; k <= j; k++) {
        ans = (ans + a[k]) % 100;
    }
    return ans;
}

ll func1(int i, int j) {
    //base case
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], func1(i, k) + func1(k + 1, j) + csum(i, k) * csum(k + 1, j));
    }

    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {//can also use (scanf("%d", &n) != EOF)
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        cout << func1(0, n - 1) << '\n';
    }


    return 0;
}