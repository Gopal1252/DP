#include<bits/stdc++.h>
using namespace std;

int profit(int wines[],int i, int j, int y, int dp[][100]){
    //Base Case
    if(i>j){
        return 0;
    }

    //Return if dp[i][j]
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    //Recuusive case
    int opt1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
    int opt2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);
    return max(opt1,opt2);

}

int main(){
    int wines[] = {2,3,5,1,4};
    int dp[100][100] = {0};
    int n = sizeof(wines)/sizeof(int);

    return 0;
}