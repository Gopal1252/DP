//Not using dp, but similar to palindrome substring question
//https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/palindrome-queries-eefd5c23/
#include <bits/stdc++.h>
using namespace std;

int arr[26][100010];

bool check(string s, int l, int r){
	if(l==r)return true;
	int flag = 0;
	for(int i=0;i<26;i++){
		int ct = arr[i][r]-((l==0)? 0 : arr[i][l-1]);
		if(ct%2==0){
			continue;
		} 
		else if(ct%2!=0 &&flag == 0){
			flag = 1;
		}
		else if(ct%2!=0 &&flag == 1){
			return false;
		}
	}
	return true;
	
}

int main() {
	int q;
	cin>>q;
	string s;
	cin>>s;

	for(int i=0;i<26;i++){
		int count=0;
		for(int j=0;j<s.length();j++){
			if(s[j] == char(97+i)){
				count++;
			}
			arr[i][j] = count;
		}
	}

	while(q--){
		int l,r;
		cin>>l>>r;
		l-=1;
		r-=1;
		if(check(s,l,r)) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
}