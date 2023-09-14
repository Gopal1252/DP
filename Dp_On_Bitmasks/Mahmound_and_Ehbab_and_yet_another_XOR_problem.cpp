//https://codeforces.com/problemset/problem/959/F
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5+10;
const int M = 1e9+7;
ll n,q;
ll arr[N];

vector<vector<pair<ll,ll>>> queries(N);//q[i] will stroe all those queries which are accounting the elements till the ith index
ll fans[N];//to strore the final answer
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>q;
    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(ll i=1; i<=q; i++){
        ll l,x;
        cin>>l>>x;
        queries[l].push_back({x,i});//i the query number
    }

    set<ll> s;//stores all the possible XOR so far
    s.insert(0);
    ll ans = 1;
    //at any moment, the no. of subsequences that can lead to all the possible XOR values is same, so we just need to keeep one variable ans which stores that very value 
    for(ll i = 1; i<=n; i++){

         if(s.find(arr[i]) != s.end()){//if the current element is already present as the XOR of some elements so far, then the ans just gets double{reason: since a[i] is a possible XOR value, so , we can still get as many subsequences by taking this a[i] value in those subsequences}
            ans = (ans*2)%M;
         }
         else{
            //arr[i] is not present as the XOR of some subsequences using the i-1 elements
            //for every x in the set s, (x^arr[i]) can not be there in the set s {since x is there but arr[i] is not, so x^arr[i] is not present in the set s}
            vector<ll> temp;
            for(auto x : s){
                temp.push_back(x^arr[i]);
            }
            for(auto it : temp){
                s.insert(it);//we can not insert more than 2^20 elements in totallity.
            }
         }

         for(auto it : queries[i]){
            if(s.find(it.first) != s.end()){
                fans[it.second] = ans;
            }
            else{
                fans[it.second] = 0;
            }
         }
    }
    for(ll i=1;i<=q;i++){
        cout<<fans[i]<<endl;
    }

    return 0;
}