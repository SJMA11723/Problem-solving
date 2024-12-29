// Source: https://usaco.guide/general/io
 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <map>
#define DEBUG if (deb)
#define INF 2000000000
#define LINF 2000000000000000000
bool deb = true;
using namespace std;
#define pb push_back
typedef long long ll;



bool checker(vector<int>& v, vector<int>& ans){
    bool flag1 = true, flag2 = true;;
    for(int x = 0; x < v.size(); x++){
        if(v[x] != ans[x]) flag1 = false; 
    }
    reverse(v.begin(), v.end());
    for(int x = 0; x < v.size(); x++){
        if(v[x] != ans[x]) flag2 = false; 
    }
    return (flag1 || flag2);
}
 
bool rec(vector<int> v, vector<int>& ans){
    if(v.size() < ans.size()) return false;
    if(v.size() == ans.size()){
        return checker(v, ans);
    }

    int m = (v.size()-1)/2;

        //normal
        for(int x =v.size()-1; x > m; x--){
            
            vector<int> newarr;
            for(int i = 0; i < x; i++) newarr.pb(v[i]);
            int j = x - 1;
            for(int i = x; i < v.size(); i ++){
                newarr[j]+=v[i];
                j--;
            }
            bool f1 = rec(newarr, ans);
            if(f1)return true;
        }
        //reverse
        reverse(v.begin(), v.end());
        for(int x =v.size()-1; x > m; x--){
            vector<int> newarr;
            for(int i = 0; i <x; i++) newarr.pb(v[i]);
            int j = x - 1;
            for(int i = x; i < v.size(); i ++){
                newarr[j]+=v[i];
                j--;
            }
            bool f1 = rec(newarr, ans);
            if(f1)return true;
        }

        return false;
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v1(n);
    for(int x = 0; x < n; x++)cin>>v1[x];
    int m;
    cin>>m;
    vector<int> v2(m);
    for(int x = 0; x < m; x++)cin>>v2[x];

    if(rec(v1, v2)) cout<<"S\n";
    else cout<<"N\n";



}   