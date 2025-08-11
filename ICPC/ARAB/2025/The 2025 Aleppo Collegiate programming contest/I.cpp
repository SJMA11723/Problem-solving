// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int k,n;
    cin>>n>>k;

    int arr[n];
    for(int x = 0; x < n; x++) cin>>arr[x];


    int l, r;
    bool rev = false;
    if(k % 2 == 0){
        l = r = k/2;
    }
    else{
        l = k/2+1;
        r = k/2;
        rev = true;
    }

    vector<int> ans; 

    for(int x = l; x < n-r; x++){
        ans.push_back(arr[x]);
    }
    if(rev)reverse(ans.begin(), ans.end());

    for(auto x : ans) cout<<x<<" ";
    cout<<"\n";
}
