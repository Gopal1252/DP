#include<bits/stdc++.h>
using namespace std;

/*
Problem Name: Palindromic Queries 
Problem Difficulty: None
Problem Constraints: n <= 1000


m <= 100000
Problem Description:
Given a string s and m queries .
Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.  

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

Input Format: First line contains n 
Second lines contains a string of length n.
Next line contains m where m is the number of queries .
Next m lines contains two integers l,r as described in the question.
Sample Input: 5
abbac
2
1 4
2 4
Output Format: for every query from l to r print "YES" if s[l.....r] is palindrome else print "NO" without quotes in a new line.
Sample Output: YES
NO
*/

//My solution(not sure if works)
// int dp[1010][1010];

// bool func(int l,int r,string s){
//     if(l==r) return true;
//     if((l-r)==1) return s[l] == s[r];

//     if(dp[l][r] != -1) return dp[l][r];

//     return dp[l][r] = func(l+1,r-1,s) && s[l]==s[r];
// }

// int main(){
//     memset(dp,-1,sizeof(dp));
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     int m;
//     cin>>m;
//     while(m--){
//         int l,r;
//         cin>>l>>r;

//         if(func(l+1,r-1,s)) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }

//     return 0;
// }

//solution
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N=1005;
bool dp[N][N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        string s;
        cin>>s;
        for(i=0;i<n;i++){
            dp[i][i] = true;                   
        }
        for(int sz=2;sz<=n;sz++){
            for(i=0;i+sz-1<n;i++){
                int start=i,end=i+sz-1;                       
                if(sz==2){
                    dp[start][end]=(s[start]==s[end]);
                }   
                else{
                    dp[start][end]=(s[start]==s[end])&&(dp[start+1][end-1]);
                }    
            } 
        }
        // queries whether l to r plaindrome ?
        cin>>m;
        while(m--){
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<(dp[l][r]?"YES":"NO")<<'\n';
        }
    }
}