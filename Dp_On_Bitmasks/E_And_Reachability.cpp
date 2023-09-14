// https://codeforces.com/problemset/problem/1169/E
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3e5 + 10;
ll n,q;
ll arr[N];
ll dist1to1[25][25];//finds out the minimum distance to reach from a particular set-bit{any index} to some other set-bit{any other index}
ll mindist[N][25];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(ll i=1; i<=n;i++){
        cin>>arr[i];
    }

    for(ll i=0;i<20;i++){
        for(ll j=0;j<20;j++){
            if( i != j){
                dist1to1[i][j] = INT_MAX;
            }
        }
    }
    for(ll i = n; i >= 1; i--){
        vector<int> zeroes, ones;//to store the positions which store zeroes and ones
        for(ll j = 0; j <= 20; j++){
            if((1<<j)&arr[i]){
                mindist[i][j] = 0;
                ones.push_back(j);

                for(ll k=0; k<=20; k++){
                    if((1<<k)&arr[i]){
                        dist1to1[j][k] = 0;
                    }
                }
            }
            else{
                zeroes.push_back(j);
            }
        } 
        for(auto it0 : zeroes){
            ll mi = INT_MAX;
            for(auto it1 : ones){
                mi = min(mi, dist1to1[it1][it0]);
            }
            for(auto it1 : ones){
                dist1to1[it1][it0] = mi;
            }
            //becoz we can jump from any set bit in the number to any other set bit in the same number in 0 steps
            mindist[i][it0] = mi;
        }
        for(ll j=0; j<=20; j++){
            for(ll k=0; k<=20; k++){
                if(j != k){
                    dist1to1[j][k]++;
                }
            }
        }
    }

    while(q--){
        ll x, y;
        cin>>x>>y;
        ll mi = INT_MAX;
        for(ll j=0; j<=20; j++){
            if(arr[y] & (1<<j)){
                mi = min(mi, mindist[x][j]);
            }
        }
        if(mi <= y-x){
            cout<<"Shi\n";
        }
        else{
            cout<<"Fou\n";
        }
    }
    return 0;
}