//https://leetcode.com/problems/predict-the-winner/description/ {not exactly the same as prateek did, but yes, did using optimal game stratery}
#include<bits/stdc++.h>
using namespace std;

/*
Given an array of even size N.
2 Players pick numbers alternatively from either end.
Give the margin by which player 1 wins.

*/

//insert dp if you want to since there will be overlapping subproblems in it.

//top-down
int func(int i, int j, int a[], int n){//returns the maximum total that player 1 can get if the remainder array is from i to j
    //base case
    if(i>j){
        return 0;
    }

    int ans = 0;

    ans = max(
        a[i] + min(func(i+2,j,a,n),func(i+1,j-1,a,n)),
        a[j] + min(func(i+1,j-1,a,n),func(i,j-2,a,n))
    );

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    int total = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }

    int pl1 = func(0, n-1, a, n);
    int pl2 = total-pl1;
    cout<<pl1-pl2;
    

    return 0;
}

/*
Problem Name: Optimal Game Strategy-I
Problem Difficulty: None
Problem Constraints: 1 < N <= 30 , N is always even<br>
0 <= A<sub>i</sub> <= 1000000
Problem Description:
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 .... xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format: First line contains the number of coins 'n'. <br>Second line contains n space separated integers where ith index denotes the value of ith coin.
Sample Input: 4
1 2 3 4
Output Format: Print a single line with the maximum possible value that Piyush can win with.
Sample Output: 6



=====Solution=====
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll coins[40];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }

    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    ll ans = max(pickFirst,pickLast);

    return ans;
}


int main() {
    int n;
    cin >> n;   
    
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    cout << optimalGame(0,n-1);

    return 0;
}
*/