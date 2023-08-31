//https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
//Editorial -->https://www.geeksforgeeks.org/program-nth-catalan-number/
//wikipedia -->https://en.wikipedia.org/wiki/Catalan_number
//boost library -->https://www.geeksforgeeks.org/advanced-c-boost-library/

#include<bits/stdc++.h>
using namespace std;

//Top-down (mine)
unsigned long long dp[101] = {0};
unsigned long long findCatalan(int n) 
{
    if(n==0) return 1;
    if(n==1) return 1;
        
    if(dp[n] != 0) return dp[n];
        
    unsigned long long ans = 0;
    for(int i = 1;i<=n;i++){
        ans += findCatalan(i-1) * 1LL * findCatalan(n-i);
    }
        
    return dp[n] = ans;
}

//bottom-up (theirs)
unsigned long int catalanDP(unsigned int n) 
{ 
    unsigned long int catalan[n+1]; 

    catalan[0] = catalan[1] = 1; 

    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 

    return catalan[n]; 
} 

int main(){
    int n;
    cin>>n;
    cout<<findCatalan(n);

    return 0;
}

