/*
Problem Name: Valentine Magic
Problem Difficulty: None

Problem Description:
It's Valentine's Day in Russia today. 
as we all know number of girls in Russia is more than number of boys :P 
hence boys have an extra advantage while choosing girl for the valentine evening. 
Each boy has certain number of chocolates and each girl has certain number of candies. 
Now you being the anchor of evening wants to pair all the boys with girls such that the 
sum of absolute difference between boy's chocolate and girl's candy in a pair is minimized. 
Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia :P


Input Format: The first line consists of two integers N and M.
then follow N integers in second line.
Then follow M integers in third line.
M >= N

Problem Constraints: 
1 <= N <= 5000 
1 <= M <= 5000 
M >= N 
1 <= chocolates <= 1000000 
1 <= candies <= 1000000

Sample Input: 2 5
4 5
1 2 3 4 5

Output Format: The only line which consists of required sum of absolute differences.
Sample Output: 0

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
//TC: O(m*n) {since making a dp array of size m*n}
long long func(int i, int j, int a[], int b[], int n, int m){//we can also start from behind so that we won't have to take n, m
    if(i == n){
        return 0;
    }
    if(j==m){//all girls finished but not boys, so this can't be counted as our solution 
        return INT_MAX;
    }

    if(dp[i][j] != -1) return dp[i][j];

    long long ans = 0;
    ans = abs(a[i]-b[j]) + func(i+1,j+1,a,b,n,m);//pairing the ith boy with jth girl
    ans = min(ans, func(i,j+1,a,b,n,m));//rejecting the jth girl and waiting for answer from the remaining array
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    dp.resize(n+1, vector<int>(m+1,-1));
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    //sorting the two arrays is important:
    sort(a,a+n);
    sort(b,b+m);

    cout<<func(0,0,a,b,n,m);

    return 0;
}