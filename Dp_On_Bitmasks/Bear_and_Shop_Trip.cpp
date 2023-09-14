//https://www.codechef.com/problems/SHOPTRIP
//this solution seems correct, but not gettig accepted {even prateek narang's code giving the same error} {although correct solution i think}
//This problem is somewhat similar to travelling salesman problem
#include<bits/stdc++.h>
using namespace std;
// #define INT_MAX 100000000ll
#define N 50

//function to calculate the euclidean distance between two points
long double distance(pair<int,int> p1, pair<int,int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

//make a distance array
long double dist[N][N] = {0};
long double dp[1<<13][N];

int n,k;//n->no. of shops , k->no. of ingredients
vector<pair<int,int>> coord;
vector<int> ingred;//corresponding to each shop in coord, we keep the corresponding ingredients in the inngred array

long double shopTrip(int mask, int idx){//mask represents the ingredients we have take/not-taken and idx is the index of the city we are currently at
    //base case
    if(mask == ((1<<k)-1) && idx == 0){//i.e if you have taken all the ingredients and have returned to the kitchen, then just return 0
        return 0;
    }

    if(dp[mask][idx] != -1) return dp[mask][idx];

    dp[mask][idx] = INT_MAX;
    for(int i=0;i<=n;i++){
        if((mask|ingred[i]) != mask|| (i==0)){//at every stage, bear can go to a shop that has the ingred that he doesn't have or he can go to kitche, and in the next stage, using the base case, it can also be checked if all the ingredients have already been taken then we just return 0 
            dp[mask][idx] = min(dp[mask][idx], dist[idx][i] + shopTrip(mask|ingred[i],i)); 
        }
    }
    return dp[mask][idx];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,x,y;
    string temp;//to store the string represeting the ingredients available/not available in a shop
    cin>>t;
    while(t--){
        cin>>n>>k;

        coord.clear();
        ingred.clear();

        coord.push_back(make_pair(0,0));

        for(int i=0;i<n;i++){
            cin>>x>>y;
            coord.push_back(make_pair(x,y));
        }

        //read n strings, one for each shop
        ingred.push_back(0);//there are 0 ingredients in the kitchen

        int possible = 0;//we take OR of ingredients for each shop, if at the end, if an ingredient is not available at any of the shops, we return -1
        for(int i=0;i<n;i++){
            cin>>temp;
            reverse(temp.begin(),temp.end());//after reversing, the rightmost bit represents the 0th bit

            int temp_mask = 0;
            for(int j=0; j<temp.length();j++){
                temp_mask |= ((1<<j)*(temp[j]-'0'));
            }
            possible |= temp_mask;
            ingred.push_back(temp_mask);
        }
        int ALL = (1<<k)-1;
        if(possible != ALL){
            cout<<"-1"<<endl;
            continue;
        } 

        //Let's work on the problem
        //1. Distance array-> initialize it with euclidian distances
        memset(dist,0,sizeof(dist));
        for(int i=0;i<=n;i++){
            for(int j=0; j<=n;j++){
                dist[i][j] = distance(coord[i],coord[j]);
            }
        }
        //2.Dp array for top-down dp ->dp[2^k][n+1]
        //dp[i][j] indicates that the currently, i is bitmask(representng the ingredients) and we are at the jth shop
        for(int i=0; i<(1<<k); i++){
            for(int j=0; j<=n;j++){
                dp[i][j] = -1;
            }
        }
        long double ans = shopTrip(0,0);//shop(bitmask of ingred, current shop we are at) //we are starting with 0 ingredients intially, and from the kitchenn {at 0th index in coord array}
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }   

    return 0;
}