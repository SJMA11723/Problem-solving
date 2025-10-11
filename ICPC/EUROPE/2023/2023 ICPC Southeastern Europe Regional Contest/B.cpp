#include<bits/stdc++.h>
#define DEBUG if(deb)

bool deb = true;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;

    pair<int,int> arr[n];

    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        arr[i] = {t, i};
    }
    sort(arr, arr+n);
    int l = 0, r = n-1;
    int ans[n];
    int k = arr[l].first + arr[r].first;
    bool flag = true;
    while(l <= r){
        if(arr[l].first + arr[r].first != k){
            flag = false;
            break;
        }
        ans[arr[l].second] = arr[r].second;
        ans[arr[r].second] = arr[l].second;
        l++;
        r--;
    }
    if(flag)for(auto x: ans) cout<<x+1<<" ";
    else cout<<"-1\n";
}