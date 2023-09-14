//Hackerearth tutorial and problems:
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/


#include<bits/stdc++.h>
using namespace std;


//Problem in the tutorial:
/*
There are N persons and N tasks.
Each task is to be alloted to a single person.
We are also givena matrix cost of size N x N, where cost[i][j] denotes, how much person i is going to charge for task j.
Now we need to assign each task to a person in such a way that the total cost is minimum. 
Note that each task is to be alloted to a single person, and each person will be alloted only one task.
*/

//Brute Force-> make all the permuations of jobs and calc the total cost and take the minimum

//Using dynamic programming
//we can space optimize further since ind is always equal to the number of set bits in the mask, so we can remove the ind variable entirely
//can also easliy write the tabulation code also
//TC:O(2^n * n), SC:O(2^n)
int func(int mask, int ind, int n, vector<vector<int>>& minCost, vector<vector<int>>& dp){//returns the minimum total cost of assigning n jobs to n workers
    if(ind == n) return 0;

    if(dp[mask][ind] != -1) return dp[mask][ind];

    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if((1<<i)&mask == 0){//i.e if the ith job has yet not been assigned
            ans = min(ans, minCost[ind][i] + func(mask|(1<<i),ind+1,n,minCost,dp));
        }
    }
    return dp[mask][ind] = ans;
}

int findMinCost(int n, vector<vector<int>>& minCost){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<vector<int>> dp((1<<n), vector<int>(n,-1));
    return func(0,0,n,minCost,dp);

    return 0;
}