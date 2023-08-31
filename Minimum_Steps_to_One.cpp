//https://www.codingninjas.com/codestudio/problems/min-steps-to-one-using-dp_920548?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int dp[N] = {0};
//top-down approach
int countStepsToOne(int n) {
	if(n==1) return 0;

	if(dp[n] != 0) return dp[n]; 

	int ans = countStepsToOne(n-1)+1;
	if(n%2==0)
		ans = min(ans, countStepsToOne(n/2)+1);
	if(n%3==0)
		ans = min(ans, countStepsToOne(n/3)+1);

	return dp[n] = ans;
}

//bottom-up approach
int countStepsToOne(int n){
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+1;
        if(i%2==0)
            dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3==0)
            dp[i] = min(dp[i],dp[i/3]+1);
    }
    return dp[n];
}

int main(){

    return 0;
}