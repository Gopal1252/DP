//this questiong is basically an extension of Kadane's algorithm
//https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/  {refer this to understand}
//https://hack.codingblocks.com/app/contests/1338/337/problem
//https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ {same for some part, but can't use kadane}

#include<bits/stdc++.h>
using namespace std;

int Kadane(vector<int>& arr) {
	int max_Sum = INT_MIN;
	int presum = 0;
	for (int i = 0; i < arr.size(); i++) {
		presum += arr[i];
		if (presum > max_Sum) {
			max_Sum = presum;
		}
		if (presum < 0) {
			presum = 0;
		}
	}
	return max_Sum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>>& M) {
	vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (j == 0) {
				dp[i][j] = M[i][j];
			}
			else {
				dp[i][j] = dp[i][j - 1] + M[i][j];
			}
		}
	}

	vector<int> temp(R, 0);
	int ans = INT_MIN;

	for (int left = 0; left < C; left++) {
		for (int right = left; right < C; right++) {
			for (int i = 0; i < R; i++) {
				if (left == 0) {
					temp[i] = dp[i][right];
				}
				else {
					temp[i] = dp[i][right] - dp[i][left - 1];
				}
			}
			ans = max(ans, Kadane(temp));
		}
	}
	return ans;
}

int main() {
	int R, C;
	cin >> R >> C;
	vector<vector<int>> M(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int x;
			cin >> x;
			M[i][j] = x;
		}
	}
	cout << maximumSumRectangle(R, C, M);


	return 0;
}