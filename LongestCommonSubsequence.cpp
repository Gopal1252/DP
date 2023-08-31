#include<bits/stdc++.h>
using namespace std;

//using DP (TC: O(N^2), TLE in GFG, passes in Leetcode)
int dp[30010];
    
    int LISubsequence(int n, int a[]){
        if(n==0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int LIS = 0;
        
        for(int i=n-1;i>=0;i--){
            if(a[i]<a[n]){
                LIS = max(LIS,LISubsequence(i,a));
            }
        }
        
        return dp[n] = 1+LIS;
    }
    
    int longestSubsequence(int n, int a[])
    {
        memset(dp,-1,sizeof(dp));
        int LIS = 0;
        for(int i=n-1;i>=0;i--){
            LIS = max(LIS,LISubsequence(i,a));
        }
        
        return LIS;
    }

//using Binar Search (TC: O(nlog(n)))
//GFG Link: https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
int longestSubsequence(int n, int a[])
    {
       vector<int> nums;
       nums.push_back(a[0]);
       
       for(int i=1;i<n;i++){
           if(a[i]>nums.back()){
               nums.push_back(a[i]);
           }
           else{
               int low = lower_bound(nums.begin(),nums.end(),a[i]) - nums.begin();
               nums[low] = a[i];
           }
       }
       return nums.size();
    }