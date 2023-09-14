// #include<bits/stdc++.h>
// using namespace std;

// string s1, s2;
// vector<string> subsequences;
// int dp[3005][3005];

// int LCS(int i, int j, string ans){
//     //base case
//     if(i<0 || j<0){
//         subsequences.push_back(ans);
//         return 0;
//     }

//     if(dp[i][j] != -1) return dp[i][j];

//     int longestSubsequence = max(LCS(i-1,j,ans),LCS(i,j-1,ans));

//     if(s1[i] == s2[j]){
//         longestSubsequence = max(longestSubsequence, 1 + LCS(i-1,j-1,s1[i] + ans));
//     }
    
//     return dp[i][j] = longestSubsequence;
// }

// int main(){
//     memset(dp,-1, sizeof(dp));
//     cin>>s1>>s2;
//     int len = LCS(s1.length()-1,s2.length()-1,"");
//     for(int i=0;i<subsequences.size();i++){
//         if(subsequences[i].size() == len){
//             cout<<subsequences[i];
//             break;
//         }
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

string s1,s2;

map<pair<string, string>, string> m;


string printLCS(string s1, string s2){
    if(s1.size()==0 ||s2.size()==0) return "";

    if(m[{s1,s2}].length() != 0) return m[{s1,s2}];

    string ans = "";

    if(s1[s1.length()-1] == s2[s2.length()-1]){
        ans += s1[s1.length()-1];
        ans += printLCS(s1.substr(0,s1.length()-1),s2.substr(0,s2.length()-1));
    }
    else{
        string str1 = printLCS(s1.substr(0,s1.length()-1),s2);
        string str2 = printLCS(s1,s2.substr(0,s2.length()-1));
        if(str1.length()>=str2.length()){
            ans += str1;
        }
        else{
            ans += str2;
        }
    }

    return m[{s1,s2}] = ans;
}

int main(){
    cin>>s1>>s2;
    string ans = printLCS(s1,s2);
    reverse(ans.begin(), ans.end());
    cout<<ans;
}