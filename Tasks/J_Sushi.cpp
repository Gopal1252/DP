//https://atcoder.jp/contests/dp/tasks/dp_j
#include<bits/stdc++.h>
using namespace std;

typedef double lld;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    int a1 = 0, a2 = 0, a3 = 0;//count of plates with 1/2/3 sushies

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        if(x == 1){
            a1++;
        }
        else if(x == 2){
            a2++;
        }
        else{
            a3++;
        }
    }

    //let pa be probability of choosing a plate with 1 sushie
    //let pb be probability of choosing a plate with 2 sushies
    //let pc be probability of choosing a plate with 3 sushies
    //let pd be probability of choosing a plate with 0 sushies


    // dp[a][b][c] = p_a * (1 + dp[a-1][b][c]) + p_b * (1 + dp[a+1][b-1][c]) + p_c * (1 + dp[a][b+1][c-1]) + p_d * (1 + dp[a][b][c]);
    // 1 * p_a + 1 * p_b + 1 * p_c + 1 * p_d = 1
    // dp[a][b][c] - p_d * (dp[a][b][c]) = 1 + p_a * (dp[a-1][b][c]) + p_b * (dp[a+1][b-1][c]) +p_c * (dp[a][b+1][c-1]);
    // dp[a][b][c] = (1/(1 - p_d) )* [1 + p_a (dp[a-1][b][c]) + p_b * (dp[a+1][b-1][c]) + p_c * (dp[a][b+1][c-1])]

    vector<vector<vector<lld>>> dp(301,vector<vector<lld>>(301, vector<lld>(301,0)));
    //dp[i][j][k] gives the expected number of steps for all plates to become empty if currently we have i plates with 1 sushie, j plates with 2 sushies and k plates with 3 sushies

    //base case
    dp[0][0][0] = 0;

    for(int threes = 0; threes<=n; threes++){
        for(int twos = 0; twos<=n; twos++){
            for(int ones = 0; ones<=n; ones++){
                if((threes + twos + ones > n) || (threes + twos + ones == 0)) continue;

                lld p_a = ((lld)ones) / n;
				lld p_b = ((lld)twos) / n;
				lld p_c = ((lld)threes) / n;
				lld p_d = ((lld)(n - ones - twos - threes)) / n;
				lld value = 1;
                if (ones - 1 >= 0)
					value += p_a * dp[ones-1][twos][threes];
				if (twos - 1 >= 0)
					value += p_b * dp[ones + 1][twos - 1][threes];
				if (threes - 1 >= 0)
					value += p_c * dp[ones][twos + 1][threes - 1];
				value = value / (1 - p_d);
				dp[ones][twos][threes] = value;
            }
        }
    }
    cout << setprecision(15);
	cout << fixed;
	cout << dp[a1][a2][a3] << "\n";

    return 0;
}