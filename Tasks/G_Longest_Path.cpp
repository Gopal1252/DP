#include<bits/stdc++.h>
using namespace std;
//Topological Sort + DP
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g1(n,vector<int>()), g2(n,vector<int>());
    vector<int> indeg(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        g1[x].push_back(y);
        indeg[y]++;
        g2[y].push_back(x);
    }

    //topo sort to get the sorted order of nodes
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> sorted;
    while(!q.empty()){
        auto node = q.front();
        q.pop();

        sorted.push_back(node);

        for(auto & it : g1[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }

    vector<int> maxDis(n,0);
    //maxDis[i] stores the maximum path length to reach a node i

    int ans = 0;
    for(int i=0;i<sorted.size();i++){
        int node = sorted[i];
        for(auto & it : g2[node]){
            maxDis[node] = max(maxDis[node],maxDis[it] + 1);
            ans = max(ans,maxDis[node]);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}